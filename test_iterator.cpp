#include "ft_vector.hpp"
#include "ft_iterator.hpp"
#include <iostream>

int	main()
{
	ft::vector<int> myvector (5);  // 5 default-constructed ints
	
	int i=0;
	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;
	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	ft::vector<int> myvector2;
  	for (int i=0; i<10; i++) myvector2.push_back(i);

  	typedef ft::vector<int>::iterator iter_type;
                                                         // ? 9 8 7 6 5 4 3 2 1 0 ?
  	iter_type from (myvector2.begin());                     //   ^
                                                         //         ------>
  	iter_type until (myvector2.end());                      //                       ^
                                                         //
  	ft::reverse_iterator<iter_type> rev_until (from);     // ^
                                                         //         <------
  	ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

  	std::cout << "myvector2:";
  	while (rev_from != rev_until)
    	std::cout << ' ' << *rev_from++;
  	std::cout << '\n';

	return 0;
}
