#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

// word_map: the key is the sequence of digits that encodes
// all the words in the associated vector
typedef std::vector<std::string> words;
typedef std::map<std::string, words> word_map;

// return digit associated with given letter 'ch' (must be in a..z or A..Z)
char encode(char ch)
{
/*
    E | J N Q | R W X | D S Y | F T | A M | C I V | B K U | L O P | G H Z
    e | j n q | r w x | d s y | f t | a m | c i v | b k u | l o p | g h z
    0 |   1   |   2   |   3   |  4  |  5  |   6   |   7   |   8   |   9
*/
    return "57630499617851881234762239"[toupper(ch) - 'A'];
}

// return digit sequence corresponding to given 'word'
std::string encode(const std::string & word)
{
    std::string encoded_word;
    for (const char * p = word.c_str(); *p; ++p) {
        if (*p != '"') // ignore embedded double quotes (umlauts)
            encoded_word += encode(*p);
    }
    return encoded_word;
}

// return the word map for dict.txt
word_map read_words()
{
    word_map wp;
    std::ifstream is("dictionary.txt");
    std::string word;
    while (std::getline(is, word))
        wp[encode(word)].push_back(word);
    return wp;
}

// return the given number with all the non-digit characters removed
std::string filtered(const std::string & num)
{
    std::string result;
    for (const char * p = num.c_str(); *p; ++p) {
        if (isdigit(*p))
            result += *p;
    }
    return result;
}

// the (messy) heart: find and print the sentences
void find_sentences(const word_map & dict, const std::string & rawnum,
    const std::string & num, const std::string & sentence, bool trailing_digit)
{
    if (num.empty()) {
        if (!sentence.empty())
            std::cout << rawnum << ":" << sentence << '\n';
    }
    else {
        bool found_word = false;
        for (size_t i = 2; i <= num.size(); ++i) {
            word_map::const_iterator entry = dict.find(num.substr(0, i));
            if (entry != dict.end()) {
                found_word = true;
                for (unsigned j = 0; j < entry->second.size(); ++j)
                    find_sentences(dict, rawnum, num.substr(i), sentence + " " + entry->second[j], false);
            }
        }
        if (!found_word && !trailing_digit)
            find_sentences(dict, rawnum, num.substr(1), sentence + " " + num[0], true);
    }
}

int main()
{
    const word_map dict(read_words());

    std::ifstream is("input.txt");
    std::string raw_number;
    while (std::getline(is, raw_number))
        find_sentences(dict, raw_number, filtered(raw_number), "", false);
}

// that's 49 non-blank, non-comment, non-just-curly-brace lines
