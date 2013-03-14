#ifndef		_DICTIONARY_HH_
#define		_DICTIONARY_HH_

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

class		Dictionary
{
private:
  std::string						_path;
  std::ifstream						_dict;
  std::map<char, std::string>				_rules;
  std::map<char, char>					_rulesByletter;
  std::map<char, std::vector<std::string> >		_dictMap;
  std::string						_sentence;

  Dictionary();
  
private:

  enum		WordStatus
    {
      VALID_WORD,
      INVALID_WORD,
      COMPLETE
    };

  void		showSentence(std::string const &);
  void 		initRules();
  void 		findOccurences(std::string const & number, std::string const & rawnum);
  bool 		isCharInRule(char const & num, char const & sample);
  WordStatus   	isWordMatches(std::string const & num, std::string const & sample);

public:
  Dictionary(std::string path);
  ~Dictionary();
  
  void		init();
  void		getSentence(std::string const &);
};

#endif
