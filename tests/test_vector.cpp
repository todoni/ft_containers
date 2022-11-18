#include <iostream>
#include <vector>
#include "ft_vector.hpp"
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define MAX_RAM 4294967296
#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main ()
{
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;
  std::vector<int>::iterator i;

  std::cout << "initial" << std::endl;
  for (i=myvector.begin(); i<myvector.end(); i++)
    std::cout << ' ' << *i;
  std::cout << '\n';
  
  it = myvector.begin();
  
  std::cout << "it: " << *it << std::endl;

  it = myvector.insert ( it + 2 , 200 );
  std::cout << "after insert 200 at begin" << std::endl;
	std::cout << "it: " << *it << std::endl;
  for (i=myvector.begin(); i<myvector.end(); i++)
    std::cout << ' ' << *i;
  std::cout << '\n';
  std::vector<int>::iterator it2 = myvector.insert (it + 2,2,300);
  std::cout << "after insert 2 300 at previous position" << std::endl;
	std::cout << "it: "<< *it << std::endl;
	std::cout << "it2: "<< *it2 << std::endl;
for (i=myvector.begin(); i<myvector.end(); i++)
    std::cout << ' ' << *i;
  std::cout << '\n';

  std::vector<int>::iterator itt;
  itt = it;
  while (itt != myvector.end())
  {	 
	  std::cout << ' ' << *itt;
	  ++itt;
  }
  std::cout << "\n";
  itt = it2;
  while (itt != myvector.end())
  {	 
	  std::cout << ' ' << *itt;
	  ++itt;
  }
  std::cout << "\n";

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());
  std::cout << "after insert 2 400 at begin + 2" << std::endl;
for (i=myvector.begin(); i<myvector.end(); i++)
    std::cout << ' ' << *i;
  std::cout << '\n';
  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (i=myvector.begin(); i<myvector.end(); i++)
    std::cout << ' ' << *i;
  std::cout << '\n';


  std::cout << "\n";

  std::vector<int> test(5, 1);
  std::cout << "cap: " << test.capacity() << " size: " << test.size() << std::endl;
  for (i=test.begin(); i<test.end(); i++)
    std::cout << ' ' << *i;
  std::cout << '\n';
  test.reserve(10);
  std::cout << "cap: " << test.capacity() << " size: " << test.size() << std::endl;

  std::vector<int>::iterator testit;
  testit = test.begin();
  test.insert(testit + 4, 6, 7);
  for (i=test.begin(); i<test.end(); i++)
    std::cout << ' ' << *i;
  std::cout << '\n';
  std::cout << "cap: " << test.capacity() << " size: " << test.size() << std::endl;
  std::cout << std::endl;
  test.insert(test.begin(), test.begin(), test.end());
  for (i=test.begin(); i<test.end(); i++)
    std::cout << ' ' << *i;
  std::cout << '\n';
  std::cout << "cap: " << test.capacity() << " size: " << test.size() << std::endl;
  std::cout << std::endl;

	ft::vector<int>::iterator ftit;
	ft::vector<int>::iterator iter;
	ft::vector<int> ftvector(5, 1);
	for (iter=ftvector.begin(); iter<ftvector.end(); iter++)
    	std::cout << ' ' << *iter;
  	std::cout << '\n';
	ftvector.reserve(10);
	ftit = ftvector.begin();
	ftvector.insert(ftit + 4, 6, 7);
	for (iter=ftvector.begin(); iter<ftvector.end(); iter++)
    	std::cout << ' ' << *iter;
  	std::cout << '\n';
  	std::cout << "cap: " << ftvector.capacity() << " size: " << ftvector.size() << std::endl;
	ftvector.insert(ftvector.begin(), ftvector.begin(), ftvector.end());
  	for (iter=ftvector.begin(); iter<ftvector.end(); iter++)
    	std::cout << ' ' << *iter;
	std::cout << '\n';
	std::cout << "cap: " << ftvector.capacity() << " size: " << ftvector.size() << std::endl;
	
	ft::vector<int> testerase;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) testerase.push_back(i);
  for (unsigned i=0; i<testerase.size(); ++i)
    std::cout << ' ' << testerase[i];
  std::cout << '\n';
  // erase the 6th element
  testerase.erase(testerase.begin()+5);
  for (unsigned i=0; i<testerase.size(); ++i)
    std::cout << ' ' << testerase[i];
  std::cout << '\n';

	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
	
  std::vector<int> testclear;
  testclear.push_back (100);
  testclear.push_back (200);
  testclear.push_back (300);

  std::cout << "testclear contains:";
  for (unsigned i=0; i<testclear.size(); i++)
    std::cout << ' ' << testclear[i];
  std::cout << '\n';

  testclear.clear();
  std::cout << "size: " << testclear.size() << std::endl;
  testclear.push_back (1101);
  testclear.push_back (2202);

  std::cout << "testclear contains:";
  for (unsigned i=0; i<testclear.size(); i++)
    std::cout << ' ' << testclear[i];
  std::cout << '\n';
	
  ft::vector<Buffer> vector_buffer;
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
  ft::vector<Buffer>().swap(vector_buffer);
	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//std::cerr << "??" << std::endl;
		//NORMAL ! :P
	}
	ft::vector<int> testalloc;
  	int * p;
  	unsigned int ii;

  // allocate an array with space for 5 elements using vector's allocator:
  	p = testalloc.get_allocator().allocate(5);

  // construct values in-place on the array:
  	for (ii=0; ii<5; ii++) testalloc.get_allocator().construct(&p[ii],ii);

  	std::cout << "The allocated array contains:";
  	for (ii=0; ii<5; ii++) std::cout << ' ' << p[ii];
  	std::cout << '\n';

  // destroy and deallocate:
  	for (ii=0; ii<5; ii++) testalloc.get_allocator().destroy(&p[ii]);
  	testalloc.get_allocator().deallocate(p,5);

	ft::vector<int> foo2 (3,100);   // three ints with a value of 100
  	ft::vector<int> bar2 (2,200);
	if (foo2==bar2) std::cout << "foo and bar are equal\n";
	if (foo2!=bar2) std::cout << "foo and bar are not equal\n";
	if (foo2< bar2) std::cout << "foo is less than bar\n";
	if (foo2> bar2) std::cout << "foo is greater than bar\n";
	if (foo2<=bar2) std::cout << "foo is less than or equal to bar\n";
	if (foo2>=bar2) std::cout << "foo is greater than or equal to bar\n";
	system("leaks a.out");
  return 0;
}
