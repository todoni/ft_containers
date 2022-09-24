#include "tree.hpp"
#include <iostream>
#include <utility>

int	main()
{
	BinarySearchTree<int, int> binary_search_tree;
	std::pair<BinarySearchTree<int, int>::iterator, bool>	ret;

	std::cout << binary_search_tree.empty() << std::endl;
	ret = binary_search_tree.insert(std::make_pair(1, 2));
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
	//std::pair<int, int> tmp;
	tmp = *ret.first;
	std::cout << tmp.first << " " << tmp.second << std::endl;
	binary_search_tree.print();

	BinarySearchTree<int, int>::iterator it;
	it = ret.first;
	--it;
	std::cout << (*it).first << ' ' << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << ' ' << (*it).second << std::endl;
	++it;
	std::cout << (*it).first << ' ' << (*it).second << std::endl;
	std::cout << (*--binary_search_tree.end()).first << std::endl;
	ret = binary_search_tree.insert(std::make_pair(5, 42));
	std::cout << ret.second << std::endl;
	binary_search_tree.print();
	std::cout << "size: " << binary_search_tree.size() << std::endl;
	std::cout << (*binary_search_tree.begin()).first << std::endl;
	ret = binary_search_tree.insert(std::make_pair(-1, 42));
	binary_search_tree.print();
	std::cout << (*binary_search_tree.begin()).first << std::endl;
	std::cout << "size: " << binary_search_tree.size() << std::endl;
}
