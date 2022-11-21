#include "../ft_utility.hpp"
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

void	test_pointers()
{

  ft::pair <int*,int*> foo2;
  ft::pair <int*,int*> bar2;

  int *a = new int(10);
  int *b = new int(20);
  int *c = new int(105);
  int *d = new int('A');
  //double *cc = new double(10.5);
  //char	*dd = new char('A');

  foo2 = ft::make_pair (a,b);
  bar2 = ft::make_pair (c,d); // ok: implicit conversion from pair<double,char>

  std::cout << "foo2: " << foo2.first << ", " << foo2.second << '\n';
  std::cout << "bar2: " << bar2.first << ", " << bar2.second << '\n';

  ft::pair <std::string*,int*> planet, homeplanet;
  std::string	test = "Earth";
  int *test2 = new int(6371);
  planet = ft::make_pair(&test,test2);

  homeplanet = planet;

  std::cout << "Home planet: " << homeplanet.first << '\n';
  std::cout << "Planet size: " << homeplanet.second << '\n';
}

int main () {
  std::cout << "================constructions===============" << std::endl;
  ft::pair <std::string,double> product1;                     // default constructor
  ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  ft::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

  std::cout << "==================assignment=================" << std::endl;
  ft::pair <std::string,int> planet, homeplanet;

  planet = ft::make_pair("Earth",6371);

  homeplanet = planet;

  std::cout << "Home planet: " << homeplanet.first << '\n';
  std::cout << "Planet size: " << homeplanet.second << '\n';

  std::cout << "=============relational operators============" << std::endl;
  ft::pair<int,char> foo (10,'z');
  ft::pair<int,char> bar (90,'a');

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  std::cout << "==================make_pair=================" << std::endl;
  ft::pair <int,int> foo2;
  ft::pair <int,int> bar2;

  foo2 = ft::make_pair (10,20);
  bar2 = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  std::cout << "foo2: " << foo2.first << ", " << foo2.second << '\n';
  std::cout << "bar2: " << bar2.first << ", " << bar2.second << '\n';

  std::cout << "pointers" << std::endl;
  test_pointers();
  system("leaks a.out");

  return 0;
}
