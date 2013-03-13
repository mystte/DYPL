/*
**
**
** Assignment 3 - DYPL
**
**
*/

#include	<iostream>
#include	<string>
#include	<stdlib.h>
#include	"Parser.hh"

int		main(int ac, char **av)
{
  if (ac != 3)
    std::cout << "Usage : ./assignment3 + sample_dictionary + sample phone number" << std::endl;
  else
    {
      Parser parser(av[1], av[2]);

      parser.init();
      parser.launch();
    }
  return EXIT_SUCCESS;
}
