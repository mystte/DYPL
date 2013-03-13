#ifndef		_DICTIONARY_HH_
#define		_DICTIONARY_HH_

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <list>

class		Dictionary
{
private:
  std::string const &			_path;
  std::ifstream				_dict;
  std::map<char, std::string>		_rules;
  std::map<char, char>			_rulesByletter;
  std::string				_sentence;

  Dictionary();
  
private:
  void		initRules();
  void		findOccurences(std::string const & number, std::string const & rawnum);
  bool		isCharInRule(char const & num, char const & sample);
  bool		isWordMatches(std::string & num, std::string const & sample);

public:
  Dictionary(std::string const & path);
  ~Dictionary();
  
  void		init();
  void		getSentence(std::string const &);
};

#endif
