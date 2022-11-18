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

	std::vector<int> first2;                                // empty vector of ints
	std::vector<int> second2 (4,100);                       // four ints with value 100
	std::vector<int> third2 (second2.begin(),second2.end());  // iterating through second
  	std::vector<int> fourth2 (third2);

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

	std::cout << "std first2" << std::endl;
	for (int i = 0; i < 10; i++)
		first2.push_back(i);
	std::cout << "The contents of first2 are: ";
	for (size_t i = 0; i < first2.size(); i++)
		std::cout << first2[i] << " ";
	std::cout << std::endl;
	
	while (first2.size() != 0)
	{
		first2.pop_back();
		std::cout << "The contents of first2 are:";
  		for (std::vector<int>::iterator it = first2.begin(); it != first2.end(); ++it)
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

	ft::vector<int> firstt;
    ft::vector<int> secondd;
    ft::vector<int> thirdd;

	std::vector<int> firstt2;
    std::vector<int> secondd2;
    std::vector<int> thirdd2;

    first.assign (7,100);             // 7 ints with a value of 100
	std::cout << first.capacity() << std::endl;

    ft::vector<int>::iterator ittt;
    ittt=first.begin()+1;

    second.assign (ittt,first.end()-1); // the 5 central values of first
	std::cout << second.capacity() << std::endl;

    int myintss[] = {1776,7,4};
    third.assign (myintss,myintss+3);   // assigning from array.
	std::cout << third.capacity() << std::endl;

    std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "first contains:";
	for (unsigned i=0; i<first.size(); i++)
		std::cout << ' ' << first.at(i);
	std::cout << std::endl;
    std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "second contains:";
	for (unsigned i=0; i<second.size(); i++)
		std::cout << ' ' << second.at(i);
	std::cout << std::endl;
    std::cout << "Size of third: " << int (third.size()) << '\n';
	std::cout << "third contains:";
	for (unsigned i=0; i<third.size(); i++)
		std::cout << ' ' << third.at(i);
	std::cout << std::endl;

	std::cout << "\nstl assign" << std::endl;
	first2.assign (7,100);             // 7 ints with a value of 100
	std::cout << first2.capacity() << std::endl;

    std::vector<int>::iterator ittt2;
    ittt2=first2.begin()+1;

    second2.assign (ittt2,first2.end()-1); // the 5 central values of first
	std::cout << second2.capacity() << std::endl;

    //int myintss[] = {1776,7,4};
    third2.assign (myintss,myintss+3);   // assigning from array.
	std::cout << third2.capacity() << std::endl;

    std::cout << "Size of first: " << int (first2.size()) << '\n';
	std::cout << "first contains:";
	for (unsigned i=0; i<first2.size(); i++)
		std::cout << ' ' << first2.at(i);
	std::cout << std::endl;
    std::cout << "Size of second: " << int (second2.size()) << '\n';
    std::cout << "first contains:";
	for (unsigned i=0; i<second2.size(); i++)
		std::cout << ' ' << second2.at(i);
	std::cout << std::endl;
	std::cout << "Size of third: " << int (third2.size()) << '\n';
	std::cout << "first contains:";
	for (unsigned i=0; i<third2.size(); i++)
		std::cout << ' ' << third2.at(i);
	std::cout << std::endl;
	
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
