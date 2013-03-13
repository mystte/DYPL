#include	"Parser.hh"

Parser::Parser(std::string dictPath, std::string numb):
  _dictPath(dictPath)
{
  this->_numb.open(numb.c_str(), std::ifstream::in);
  if (!this->_numb.is_open())
    {
      std::cerr << "ERROR : file \"" << numb << "\" was not found." << std::endl;
      exit(EXIT_FAILURE);
    }
}

Parser::~Parser()
{
  this->_numb.close();
  delete(this->_dict);
}

void		Parser::init()
{
  
  this->_dict = new Dictionary(this->_dictPath);
  this->_dict->init();
}

void		Parser::launch()
{
  std::string	sample;
  while (std::getline(this->_numb, sample))
    {
      this->_dict->getSentence(sample);
      std::cout << "next" << std::endl;
    }

}
