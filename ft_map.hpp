#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <memory>
# include <functional>
# include <utility> //TODO: ft::pair 구현 후 바꿔야함

namespace ft
{

template < class Key,                                     		// map::key_type
           class T,                                       		// map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
           >
class map
{
public:
	typedef Key												key_type;
	typedef T												mapped_type;
	typedef typename std::pair<const key_type, mapped_type>	value_type;
	typedef Compare											key_compare;
	typedef Alloc											allocator_type;

	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;

	class	iterator
	{

	};

	class	value_compare : public std::binary_function<value_type, value_type, bool> {
		friend class map<Key, T, Compare>;
	protected:
		Compare comp;
      	value_compare(Compare c) : comp(c) {}
    public:
      	bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
	};

};

}

#endif
