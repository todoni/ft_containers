#include <map>
#include <iostream>

int	main()
{
	std::map<int, int> myMap;

	myMap.insert(std::pair<int, int>(1, 2));
	myMap.insert(std::pair<int, int>(3, 2));
	myMap.insert(std::pair<int, int>(5, 2));
	myMap.insert(std::pair<int, int>(5, 42));

	for (std::map<int, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
		std::cout << "[key:"<< it->first << " value:" << it->second << "] ";
	std::cout << std::endl;
}
