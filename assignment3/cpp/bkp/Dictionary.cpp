#include "Dictionary.hh"

Dictionary::Dictionary(std::string path):
  _path(path),
  _wordFound(false)
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
  std::string   sample;
  std::ifstream dict(this->_path.c_str());

  // std::cout << "\tNumber is : " << number << std::endl;
  if (number.empty())
    {
      if (!this->_sentence.empty())
        {
	  if (this->_wordFound == true)
	    {
	      std::cout << rawNum << ":" << this->_sentence << std::endl;
	      this->_sentence.clear();
	      this->_wordFound = false;
	    }
        }
    }
  else
    {
      while (std::getline(dict, sample))
        {
          if (sample.length() <= number.length() && isCharInRule(number[0], sample[0]) == true)
            {
              std::string       numberTmp = number;
              this->completeWord(numberTmp, rawNum, sample);
            }
        }
    }
}

void            Dictionary::completeWord(std::string &numberTmp, std::string const & rawNum, std::string const & sample)
{
  if (isWordMatches(numberTmp, sample) == true)
    {
      this->_sentence += " ";
      this->_sentence += sample;
      // std::cout << "num = \"" << numberTmp << "\"" << std::endl;
      // std::cout << "sentence = " << this->_sentence << std::endl;
      this->_sentence.clear();
      // this->findOccurences(numberTmp, rawNum);
    }
}

void            Dictionary::resetDict()
{
  this->_dict.clear();
  this->_dict.seekg(0, std::ios::beg);    
}

bool            Dictionary::isCharInRule(char const & num, char const & sample)
{
  unsigned found = this->_rules[num].find(sample);
  if (found != std::string::npos)
    return true;
  return false;
}

bool            Dictionary::isWordMatches(std::string & num, std::string const & sample)
{
  unsigned int          j = 0;

  //  std::cout << "num == " << num  << " et  sample == " << sample << std::endl;
  for (unsigned int i = 0; i != sample.length(); ++i)
    {
      //      std::cout << sample[i] << " correspond à " 
      //                << this->_rulesByletter[sample[i]] << " et num[j] == " << num[j] << std::endl;
      if (this->_rulesByletter[sample[i]] == num[j])
        {
          // std::cout << "MATCH !" << std::endl;
          j++;
          if (j == num.length() || (i + 1 == sample.length()))
            {
	      if (j == num.length() && (i + 1 == sample.length()))
		this->_wordFound = true;
              //std::cout << "RETURN TRUE" << std::endl;
              num.erase(0, j);
              return true;
            }
        }
      else
	return false;
    }
  return false;
}
