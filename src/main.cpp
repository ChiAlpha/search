/***A program to create a useful tool called chch, from French "Chercher", to search for***
****Used as follows:
****chch [pattern] [<string]
***i.e, search for "pattern" in "string"
***/


#include <iostream>
#include <cstring>
#include <iterator>

const inline short MAXL {500};

namespace MyScope                           //Self defined strstr() method
{
  char *strstr(const char*, const char*);
}


int main(int argc, char *argv[])
{
  //To display help:
  if (argc == 2)
  {
    auto isHelp {strcmp(argv[1], "help")};

    if(isHelp == 0)                         //If 2nd argument == "help"...
    {
      std::cout<<"\nchch [pattern] [<file]\nSearch file for pattern and output lines containing patten\n";
      return 0;
    }                                       //...print help and exit.

    else
    {
      std::cerr<<"\nInvalid option.\n";
      return 1; 
    }
  }

  if (argc < 2 )                            //If no search string is specified...
  {
    std::cerr<<"\nNo search string specified.\n";
    return 1;
  }                                         //...print an error message and exit.


  char line[MAXL],                          //A line of text
      *pattern { argv[1] };                 //The pattern to be searched for

  auto lengthOfLine = std::strlen(argv[2]);
  int lineNr = 0;

  while (lengthOfLine > 0)
  {
    ++lineNr;
    if (MyScope::strstr(line, pattern) != nullptr)
    {
      std::cout<<lineNr<<": "<<line<<std::endl;
    }

    --lengthOfLine;
  }

  return 0;
}
