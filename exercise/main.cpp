#include "tree.hpp"
#include <iostream>
#include <utility>

int	main()
{
	BinarySearchTree<int, int> binary_search_tree;
	std::pair<BinarySearchTree<int, int>::iterator, bool>	ret;

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
	for (BinarySearchTree<int, int>::iterator itt = binary_search_tree.begin(); itt != binary_search_tree.end(); ++itt)
		std::cout << "[key:"<<	itt->first << " value:" << itt->second << "] " << std::endl;

	//std::pair<int, int> tmp;
	tmp = *ret.first;
	std::cout << tmp.first << " " << tmp.second << std::endl;
	binary_search_tree.print();
	ret = binary_search_tree.insert(std::make_pair(3, 42));
	binary_search_tree.print();
	std::cout << "size: " << binary_search_tree.size() << std::endl;

	BinarySearchTree<int, int>::iterator it;
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
	for (BinarySearchTree<int, int>::iterator itt = binary_search_tree.begin(); itt != binary_search_tree.end(); ++itt)
		std::cout << "[key:"<<	itt->first << " value:" << itt->second << "] " << std::endl;
		
}
