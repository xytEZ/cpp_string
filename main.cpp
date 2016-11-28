#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "String.hh"

int main()
{
  String s;
  String s2 = s;
  
  s2 = "Panda";
  std::cout << s2 << std::endl;

  String s3(" is");
  String s4 = " cute!!!";

  s2 += s3 + s4;
  std::cout << s2 << std::endl;
    try
      {
	s2.at(42) = 'a';
      }
    catch (const std::out_of_range& e)
      {
	std::cerr << e.what() << std::endl;
      }
    s2.at(0) = 'H';
    std::cout << s2 << std::endl;

    const char *s5 = s2.c_str();

    std::cout << s5 << std::endl;

    char c = s2;

    std::cout << c << std::endl;

    std::cout << s2.size() << std::endl;
    
    {
      String::Iterator it_begin = s2.begin();
      String::Iterator it_end;

      it_end = s2.end();
      std::for_each(it_begin, it_end,
		    [](char c) -> void
		    {
		      std::cout << c;
		    });
      std::cout << std::endl;
    }

    {
      for (String::Iterator it(s2.begin()); it != s2.end(); ++it)
	std::cout << *it;
      std::cout << std::endl;
    }
    return 1;    
}
