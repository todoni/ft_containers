#include "ft_vector.hpp"
#include <iostream>

int	main()
{
	ft::vector<int> ft_vector(10);
	
	for (int i = 0; i < 10; i++)
		ft_vector.push_back(i);
	//for (int i = 0; i < ft_vector.size(); i++)
	//	std::cout << ft_vector[i] << " ";
	//std::cout << std::endl;
}
