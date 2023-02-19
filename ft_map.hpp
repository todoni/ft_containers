#ifndef FT_MAP_HPP
# define FT_MAP_HPP

# include <memory>
# include "./exercise/ft_functional.hpp"
# include "ft_utility.hpp" //TODO: ft::pair 구현 후 바꿔야함
# include "ft_iterator.hpp"
# include "rb_tree.hpp"

namespace ft
{

template < class Key,                                     		// map::key_type
           class T,                                       		// map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           >
class map
{
public:
	typedef Key												key_type;
	typedef T												mapped_type;
	typedef typename ft::pair<const key_type, mapped_type>	value_type;
	typedef Compare											key_compare;
	typedef Alloc											allocator_type;

	//typedef typename allocator_type::reference				reference;
	//typedef typename allocator_type::const_reference		const_reference;
	//typedef typename allocator_type::pointer				pointer;
	//typedef typename allocator_type::const_pointer			const_pointer;

	//class	iterator
	//{

	//};
	//typedef	ft::reverse_iterator<iterator>							reverse_iterator;
	//typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	//typedef typename allocator_type::size_type				size_type;

	class	value_compare : public std::binary_function<value_type, value_type, bool> {
		friend class map<Key, T, Compare>;
	protected:
		Compare comp;
      	value_compare(Compare c) : comp(c) {}
    public:
      	bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
	};

private:
	typedef rb_tree<key_type, mapped_type, select1st<value_type>, key_compare> rep_type;

	rep_type t;

public:
	typedef typename rep_type::pointer pointer;
    typedef typename rep_type::reference reference;
    typedef typename rep_type::const_reference const_reference;
    typedef typename rep_type::iterator iterator;
    typedef typename rep_type::const_iterator const_iterator;
    typedef typename rep_type::reverse_iterator reverse_iterator;
    typedef typename rep_type::const_reverse_iterator const_reverse_iterator;
    typedef typename rep_type::size_type size_type;
    typedef typename rep_type::difference_type difference_type;

	explicit map(const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : t(comp, false) {}
	template <class InputIterator>
	map(InputIterator first, InputIterator last,
       			const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type()) : t(first, last, comp, false) {}
	map(const map& x) : t(x.t, false) {}
	~map() {}

	iterator begin() { return t.begin(); }
	//const_iterator begin() const;
	iterator end() { return t.end(); }
	//const_iterator end() const;
	reverse_iterator rbegin() { return t.rbegin(); }
	//const_reverse_iterator rbegin() const;
	reverse_iterator rend() { return t.rend(); }
	//const_reverse_iterator rend() const;
	bool empty() const { return t.empty(); }
	size_type size() const { return t.size(); }
	size_type max_size() const { return t.max_size(); }

	mapped_type& operator[] (const key_type& k) { return (*((insert(value_type(k, T()))).first)).second; }
	
	typedef ft::pair<iterator, bool> pair_iterator_bool;
	pair_iterator_bool insert(const value_type& val) { return t.insert(val); }
	/*iterator insert(iterator position, const value_type& val);
	template <class InputIterator>
  	void insert (InputIterator first, InputIterator last);
	void erase(iterator position);
	size_type erase(const key_type& k);
	void erase(iterator first, iterator last);
	void swap(map& x);
	void clear();
	key_compare key_comp() const;
	value_compare value_comp() const;

	iterator find(const key_type& k);
	//const_iterator find(const key_type& k) const;
	size_type count(const key_type& k) const;
	iterator lower_bound(const key_type& k);
	//const_iterator lower_bound (const key_type& k) const;
	iterator upper_bound(const key_type& k);
	//const_iterator upper_bound (const key_type& k) const;
	//ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
	pair_iterator_bool	equal_range(const key_type& k);
	allocator_type	get_allocator() const;*/
};

}

#endif
