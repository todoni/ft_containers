// lexicographical_compare example
#include <iostream>     // std::cout, std::boolalpha
#include "ft_algorithm.hpp"  // std::lexicographical_compare
#include "ft_vector.hpp"
#include <cctype>       // std::tolower

// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int main () {
  char foo[]="Apple";
  char bar[]="apartment";

  std::cout << std::boolalpha;

  std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

  std::cout << "Using default comparison (operator<): ";
  std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
  std::cout << '\n';

  std::cout << "Using mycomp as comparison object: ";
  std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  std::cout << '\n';

  ft::vector<int> foo2 (3,100);   // three ints with a value of 100
  ft::vector<int> bar2 (2,200);   // two ints with a value of 200

  if (foo2==bar2) std::cout << "foo2 and bar2 are equal\n";
  if (foo2!=bar2) std::cout << "foo2 and bar2 are not equal\n";
  if (foo2< bar2) std::cout << "foo2 is less than bar2\n";
  if (foo2> bar2) std::cout << "foo2 is greater than bar2\n";
  if (foo2<=bar2) std::cout << "foo2 is less than or equal to bar2\n";
  if (foo2>=bar2) std::cout << "foo2 is greater than or equal to bar2\n";
  return 0;
}
