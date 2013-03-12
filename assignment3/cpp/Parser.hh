#ifndef __PARSER_HH__
#define __PARSER_HH__

#include <string>
#include <fstream>

class	Parser
{
  std::ifstream		_dict;
  std::ifstream		_numb;


private:
  Parser();

public:
  Parser(std::string dict, std::string numb);
  ~Parser();

};

#endif
