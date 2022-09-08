#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>


# ifndef Allocator
# define Allocator allocator
# endif
using namespace std;

namespace ft
{

template<typename T, typename Allocator = allocator<T> >
class vector
{

public:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename allocator_type::pointer iterator;
	typedef typename allocator_type::const_pointer const_iterator;
	typedef typename allocator_type::size_type size_type;
	typedef typename iterator_traits<iterator>::difference_type difference_type;
	//typedef reverse_iterator<iterator, value_type, const_reference, difference_type> reverse_iterator; //TODO: reverse_iterator 따로 구현
	//typedef reverse_iterator<const_iterator> const_reverse_iterator;
	
};

}

#endif
