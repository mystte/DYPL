#ifndef __PARSER_HH__
#define __PARSER_HH__

#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include "Dictionary.hh"

class	Parser
{
private:
  std::ifstream		_numb;
  std::string		_dictPath;
  Dictionary *		_dict;

private:
  Parser();

public:
  Parser(std::string const dict, std::string const numb);
  ~Parser();

  void		init();
  void		launch();
};

#endif
