//#include <vector>
#include "ft_vector.hpp"

int	main()
{
	/*std::vector<int> foo(3,100);
	std::vector<int> bar(5,200);

	foo.swap(bar);
	std::swap(foo, bar);

	std::cout << "foo contains:";
  	for (unsigned i=0; i<foo.size(); i++)
    	std::cout << ' ' << foo[i];
  	std::cout << '\n';

  	std::cout << "bar contains:";
  	for (unsigned i=0; i<bar.size(); i++)
    	std::cout << ' ' << bar[i];
  	std::cout << '\n';*/

	ft::vector<int> ffoo(3,100);
	ft::vector<int> fbar(5,200);

	ffoo.swap(fbar);
	ft::swap(ffoo, fbar);
	swap(ffoo, fbar);

	std::cout << "ft foo contains:";
  	for (unsigned i=0; i<ffoo.size(); i++)
    	std::cout << ' ' << ffoo[i];
  	std::cout << '\n';

  	std::cout << "ft bar contains:";
  	for (unsigned i=0; i<fbar.size(); i++)
    	std::cout << ' ' << fbar[i];
  	std::cout << '\n';

	system("leaks test_swap");
}
