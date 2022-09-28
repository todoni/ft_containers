#include "tree.hpp"
#include <iostream>
#include <utility>
#include "ft_functional.hpp"

int	main()
{
	BinarySearchTree<int, int, select1st<std::pair<int, int> > > binary_search_tree;
	std::pair<BinarySearchTree<int, int, select1st<std::pair<int, int> > >::iterator, bool>	ret;

	std::cout << binary_search_tree.empty() << std::endl;
	ret = binary_search_tree.insert(std::pair<int, int>(1, 2));
	std::pair <int, int> tmp = *ret.first;
	std::cout << tmp.first << " " << tmp.second << std::endl;
	//binary_search_tree.print();
	ret = binary_search_tree.insert(std::make_pair(5, 2));
	tmp = *ret.first;
	std::cout << tmp.first << " " << tmp.second << std::endl;
	//binary_search_tree.print();
	ret = binary_search_tree.insert(std::make_pair(3, 2));
	std::cout << binary_search_tree.empty() << std::endl;
	std::cout << "size: " << binary_search_tree.size() << std::endl;
	std::cout << "first value:" << (*binary_search_tree.begin()).first << std::endl;
	std::cout << "last  value: "<< (*--binary_search_tree.end()).first << std::endl;
	for (BinarySearchTree<int, int, select1st<std::pair<int, int> > >::iterator itt = binary_search_tree.begin(); itt != binary_search_tree.end(); ++itt)
		std::cout << "[key:"<<	itt->first << " value:" << itt->second << "] " << std::endl;

	//std::pair<int, int> tmp;
	tmp = *ret.first;
	std::cout << tmp.first << " " << tmp.second << std::endl;
	binary_search_tree.print();
	ret = binary_search_tree.insert(std::make_pair(3, 42));
	binary_search_tree.print();
	tmp = *ret.first;
	std::cout << "size: " << binary_search_tree.size() << std::endl;
	std::cout << tmp.first << " " << tmp.second << std::endl;

	BinarySearchTree<int, int, select1st<std::pair<int, int> > >::iterator it;
	std::cout << "=========================" << std::endl;
	it = ret.first;
	--it;
	std::cout << (*it).first << ' ' << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << ' ' << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << ' ' << (*it).second << std::endl;
	std::cout << "last value: "<< (*--binary_search_tree.end()).first << std::endl;
	ret = binary_search_tree.insert(std::make_pair(5, 42));
	std::cout << ret.second << std::endl;
	binary_search_tree.print();
	std::cout << "size: " << binary_search_tree.size() << std::endl;
	std::cout << (*binary_search_tree.begin()).first << std::endl;
	ret = binary_search_tree.insert(std::make_pair(-1, 42));
	binary_search_tree.print();
	std::cout << (*binary_search_tree.begin()).first << std::endl;
	std::cout << "size: " << binary_search_tree.size() << std::endl;
	for (BinarySearchTree<int, int, select1st<std::pair<int, int> > >::iterator itt = binary_search_tree.begin(); itt != binary_search_tree.end(); ++itt)
		std::cout << "[key:"<<	itt->first << " value:" << itt->second << "] " << std::endl;
	
	BinarySearchTree<char, int, select1st<std::pair<char, int> > > mymap;

  // first insert function version (single parameter):
  	mymap.insert ( std::pair<char,int>('a',100) );
  	mymap.insert ( std::pair<char,int>('z',200) );

  	std::pair<BinarySearchTree<char, int, select1st<std::pair<char, int> > >::iterator,bool> rett;
  	rett = mymap.insert ( std::pair<char,int>('z',500) );
  	if (rett.second==false) {
    	std::cout << "element 'z' already existed";
    	std::cout << " with a value of " << rett.first->second << '\n';
  	}	
	// second insert function version (with hint position):
  	BinarySearchTree<char, int, select1st<std::pair<char, int> > >::iterator itt = mymap.begin();
  	mymap.insert (itt, std::pair<char,int>('b',300));  // max efficiency inserting
  	mymap.insert (itt, std::pair<char,int>('c',400));  // no max efficiency inserting
	
	// third insert function version (range insertion):
	BinarySearchTree<char, int, select1st<std::pair<char, int> > > anothermap;
  	anothermap.insert(mymap.begin(),mymap.find('c'));

  	// showing contents:
  	std::cout << "mymap contains:\n";
  	for (itt=mymap.begin(); itt!=mymap.end(); ++itt)
    	std::cout << itt->first << " => " << itt->second << '\n';

  	std::cout << "anothermap contains:\n";
  	for (itt=anothermap.begin(); itt!=anothermap.end(); ++itt)
    	std::cout << itt->first << " => " << itt->second << '\n';

}
