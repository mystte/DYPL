#include <algorithm>
#include "Dictionary.hh"

void		Dictionary::initRules()
{

/*
    E | J N Q | R W X | D S Y | F T | A M | C I V | B K U | L O P | G H Z
    e | j n q | r w x | d s y | f t | a m | c i v | b k u | l o p | g h z
    0 |   1   |   2   |   3   |  4  |  5  |   6   |   7   |   8   |   9
*/

  this->_rules['0'] = "Ee";
  this->_rules['1'] = "JNQjnq";
  this->_rules['2'] = "RWXrwx";
  this->_rules['3'] = "DSYdsy";
  this->_rules['4'] = "FTft";
  this->_rules['5'] = "AMam";
  this->_rules['6'] = "CIVciv";
  this->_rules['7'] = "BKUbku";
  this->_rules['8'] = "LOPlop";
  this->_rules['9'] = "GHZghz";

  // lower case

 this->_rulesByletter['a'] = '5';
 this->_rulesByletter['b'] = '7';
 this->_rulesByletter['c'] = '6';
 this->_rulesByletter['d'] = '3';
 this->_rulesByletter['e'] = '0';
 this->_rulesByletter['f'] = '4';
 this->_rulesByletter['g'] = '9';
 this->_rulesByletter['h'] = '9';
 this->_rulesByletter['i'] = '6';
 this->_rulesByletter['j'] = '1';
 this->_rulesByletter['k'] = '7';
 this->_rulesByletter['l'] = '8';
 this->_rulesByletter['m'] = '5';
 this->_rulesByletter['n'] = '1';
 this->_rulesByletter['o'] = '8';
 this->_rulesByletter['p'] = '8';
 this->_rulesByletter['q'] = '1';
 this->_rulesByletter['r'] = '2';
 this->_rulesByletter['s'] = '3';
 this->_rulesByletter['t'] = '4';
 this->_rulesByletter['u'] = '7';
 this->_rulesByletter['v'] = '6';
 this->_rulesByletter['w'] = '2';
 this->_rulesByletter['x'] = '2';
 this->_rulesByletter['y'] = '3';
 this->_rulesByletter['z'] = '9';

 // upper case

 this->_rulesByletter['A'] = '5';
 this->_rulesByletter['B'] = '7';
 this->_rulesByletter['C'] = '6';
 this->_rulesByletter['D'] = '3';
 this->_rulesByletter['E'] = '0';
 this->_rulesByletter['F'] = '4';
 this->_rulesByletter['G'] = '9';
 this->_rulesByletter['H'] = '9';
 this->_rulesByletter['I'] = '6';
 this->_rulesByletter['J'] = '1';
 this->_rulesByletter['K'] = '7';
 this->_rulesByletter['L'] = '8';
 this->_rulesByletter['M'] = '5';
 this->_rulesByletter['N'] = '1';
 this->_rulesByletter['O'] = '8';
 this->_rulesByletter['P'] = '8';
 this->_rulesByletter['Q'] = '1';
 this->_rulesByletter['R'] = '2';
 this->_rulesByletter['S'] = '3';
 this->_rulesByletter['T'] = '4';
 this->_rulesByletter['U'] = '7';
 this->_rulesByletter['V'] = '6';
 this->_rulesByletter['W'] = '2';
 this->_rulesByletter['X'] = '2';
 this->_rulesByletter['Y'] = '3';
 this->_rulesByletter['Z'] = '9';  

 std::string			sample;
 char				key;
  std::vector<std::string>	vect;

  this->_dictMap['0'] = vect;
  this->_dictMap['1'] = vect;
  this->_dictMap['2'] = vect;
  this->_dictMap['3'] = vect;
  this->_dictMap['4'] = vect;
  this->_dictMap['5'] = vect;
  this->_dictMap['6'] = vect;
  this->_dictMap['7'] = vect;
  this->_dictMap['8'] = vect;
  this->_dictMap['9'] = vect;

  while (std::getline(this->_dict, sample))
    {
      key = this->_rulesByletter[sample[0]];
      this->_dictMap[key].push_back(sample);
    }
}
