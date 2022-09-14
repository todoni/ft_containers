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

	ft::vector<int> myvector;
	std::cout << "capacity: " << myvector.capacity();
	std::cout << "   size: " << myvector.size() << std::endl;

  	// set some initial content:
	std::cout << "capacity: " << myvector.capacity() << std::endl;
  	for (int i=1;i<10;i++)
	{

		myvector.push_back(i);
		std::cout << myvector.capacity() << std::endl;
	}
	std::cout << "capacity: " << myvector.capacity();
	std::cout << "   size: " << myvector.size() << std::endl;
	for (size_t i=0; i <myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

  	myvector.resize(5);
	std::cout << "capacity: " << myvector.capacity();
	std::cout << "   size: " << myvector.size() << std::endl;
	for (size_t i=0; i <myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

  	myvector.resize(8,100);
  	std::cout << "capacity: " << myvector.capacity();
	std::cout << "   size: " << myvector.size() << std::endl;
	for (size_t i=0; i <myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.resize(12);
	std::cout << "capacity: " << myvector.capacity();
	std::cout << "   size: " << myvector.size() << std::endl;
	for (size_t i=0; i <myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << "myvector contains:";
	for (size_t i=0; i <myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << "stl vector" << std::endl;
	std::vector<int> myvector2;

	std::cout << "capacity: " << myvector2.capacity();
	std::cout << "   size: " << myvector2.size() << std::endl;
  	
	// set some initial content:
	std::cout << "capacity: " << myvector2.capacity() << std::endl;
  	for (int i=1;i<10;i++)
	{
		myvector2.push_back(i);
		std::cout << myvector2.capacity() << std::endl;
	}
	std::cout << "capacity: " << myvector2.capacity();
	std::cout << "   size: " << myvector2.size() << std::endl;
	for (size_t i=0; i <myvector2.size();i++)
		std::cout << ' ' << myvector2[i];
	std::cout << '\n';
  	
	myvector2.resize(5);
	std::cout << "capacity: " << myvector2.capacity();
	std::cout << "   size: " << myvector2.size() << std::endl;
	for (size_t i=0; i <myvector2.size();i++)
		std::cout << ' ' << myvector2[i];
	std::cout << '\n';

  	myvector2.resize(8,100);
	std::cout << "capacity: " << myvector2.capacity();
	std::cout << "   size: " << myvector2.size() << std::endl;
	for (size_t i=0; i <myvector2.size();i++)
		std::cout << ' ' << myvector2[i];
	std::cout << '\n';

  	myvector2.resize(12);
	std::cout << "capacity: " << myvector2.capacity();
	std::cout << "   size: " << myvector2.size() << std::endl;
	for (size_t i=0; i <myvector2.size();i++)
		std::cout << ' ' << myvector2[i];
	std::cout << '\n';
	
	std::cout << "myvector2 contains:";
	for (size_t i=0; i <myvector2.size();i++)
		std::cout << ' ' << myvector2[i];
	std::cout << '\n';


	ft::vector<int> test_at(10);   // 10 zero-initialized ints
  // assign some values:
  	for (unsigned i=0; i < test_at.size(); i++)
		test_at.at(i)=i;
	std::cout << "myvector contains:";
	for (unsigned i=0; i<test_at.size(); i++)
		std::cout << ' ' << test_at.at(i);
	std::cout << '\n';
	std::cout << "exception test" << std::endl;
	test_at.at(test_at.size());

	std::vector<int> test_std(10);   // 10 zero-initialized ints
  // assign some values:
  	for (unsigned i=0; i < test_std.size(); i++)
		test_std.at(i)=i;
	std::cout << "myvector contains:";
	for (unsigned i=0; i < test_std.size(); i++)
		std::cout << ' ' << test_std.at(i);
	std::cout << '\n';
	test_std.at(test_std.size());

}
