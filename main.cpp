#include "ft_vector.hpp"
#include <iostream>
#include <vector>

int	main()
{
	//ft::vector<int> ft_vector(10);
	//std::vector<int> test(4, 100);
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	ft::vector<int> third (second.begin(),second.end());  // iterating through second
  	ft::vector<int> fourth (third);                       // a copy of third


  // the iterator constructor can also be used to construct from arrays:
  	int myints[] = {16,2,77,29};
  	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  	std::cout << "The contents of fifth are:";
  	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	
	std::cout << "The contents of fourth are:";
  	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	
	std::cout << "The contents of third are:";
  	for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	std::cout << "The contents of second are:";
  	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';

	/*first = fifth;
	std::cout << "The contents of first are:";
	for (size_t i = 0; i < first.size(); i++)
		std::cout << first[i] << " ";
	std::cout << std::endl;*/

	for (int i = 0; i < 10; i++)
		first.push_back(i);
	std::cout << "The contents of first are: ";
	for (size_t i = 0; i < first.size(); i++)
		std::cout << first[i] << " ";
	std::cout << std::endl;
	
	while (first.size() != 0)
	{
		first.pop_back();
		std::cout << "The contents of first are:";
  		for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    		std::cout << ' ' << *it;
  		std::cout << '\n';
	}
}
