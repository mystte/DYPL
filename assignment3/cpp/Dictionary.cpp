#include "Dictionary.hh"

Dictionary::Dictionary(std::string path):
  _path(path)
{
}

Dictionary::~Dictionary()
{
}

void            Dictionary::init()
{
  std::string   tmp = this->_path;
  this->_dict.open(tmp.c_str(), std::ifstream::in);
  if (!this->_dict.is_open())
    {
      std::cerr << "ERROR : file \"" << this->_path << "\" was not found." << std::endl;
      exit(EXIT_FAILURE);
    }
  this->initRules();
}

//
//  This function finds the result for the given number (main loop)
//
//

void            Dictionary::getSentence(std::string const & number)
{
  this->findOccurences(number, number);
}

//
//
// Find occurences function
//
//

void            Dictionary::findOccurences(std::string const & number, std::string const & rawNum)
{
  std::string	numberTmp = number;

  for (std::vector<std::string>::iterator it = this->_dictMap[number[0]].begin(); it != this->_dictMap[number[0]].end(); ++it)
    {
      if ((*it).length() <= numberTmp.length())
	{
	  wordStatus ws = isWordMatches(numberTmp, (*it));
	  if (ws == COMPLETE || ws == VALID_WORD)
	    {
	      this->_sentence += " ";
	      this->_sentence += (*it);
	      if (ws == COMPLETE)
		this->showSentence(rawNum);
	      this->findOccurences(number.substr((*it).length(), number.length()), rawNum);
	    }
	}
    }
  this->_sentence.clear();
}

Dictionary::wordStatus           Dictionary::isWordMatches(std::string & num, std::string const & sample)
{
  std::string		word = sample;
  std::string		numTmp = num;
  unsigned int		i = 0;

  
  for (i = 0; isCharInRule(num[i], word[i]) == true; ++i)
    ;
  if (i == word.length())
    {
      if (i != num.length())
	return VALID_WORD;
      return COMPLETE;
    }
  return INVALID_WORD;
}

void		Dictionary::showSentence(std::string const & rawNum)
{
  std::cout << rawNum << ":" << this->_sentence << std::endl;
  this->_sentence.clear();
}

bool            Dictionary::isCharInRule(char const & num, char const & sample)
{
  unsigned found = this->_rules[num].find(sample);
  if (found != std::string::npos)
    return true;
  return false;
}

