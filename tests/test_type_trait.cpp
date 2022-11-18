#include "ft_type_traits.hpp"
#include <iostream>

template <unsigned n>
struct factorial : ft::integral_constant<int,n * factorial<n-1>::value> {};

template <>
struct factorial<0> : ft::integral_constant<int,1> {};

template <class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
           class = typename ft::enable_if<ft::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

int main() {
  std::cout << factorial<5>::value;  // constexpr (no calculations on runtime)
									 //
  std::cout << std::boolalpha;
  std::cout << "is_integral:" << std::endl;
  std::cout << "char: " << ft::is_integral<char>::value << std::endl;
  std::cout << "int: " << ft::is_integral<int>::value << std::endl;
  std::cout << "float: " << ft::is_integral<float>::value << std::endl;

  short int i = 1;    // code does not compile if type of i is not integral

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;

  return 0;
}
