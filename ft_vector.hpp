#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
# include <iterator>

#include <iostream>

# ifndef Allocator
# define Allocator allocator
# endif

namespace ft
{

template<typename T, typename Allocator = std::allocator<T> >
class vector
{

public:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef pointer iterator;
	typedef const_pointer const_iterator;
	typedef typename allocator_type::size_type size_type;
	typedef typename allocator_type::difference_type difference_type;
	//typedef reverse_iterator<iterator, value_type, const_reference, difference_type> reverse_iterator; //TODO: reverse_iterator 따로 구현
	//typedef reverse_iterator<const_iterator> const_reverse_iterator;
protected:
    Allocator static_allocator;
    iterator start;
    iterator finish;
    iterator end_of_storage;

public:
	/* iterator */
	iterator begin() { return start; }
    const_iterator begin() const { return start; }
    iterator end() { return finish; }
    const_iterator end() const { return finish; }
    //reverse_iterator rbegin() { return reverse_iterator(end()); }
    //const_reverse_iterator rbegin() const { 
    //    return const_reverse_iterator(end()); 
    //}
    //reverse_iterator rend() { return reverse_iterator(begin()); }
    //const_reverse_iterator rend() const { 
    //    return const_reverse_iterator(begin()); 
    //}

	/* capacity */
    size_type size() const { return size_type(end() - begin()); }
    size_type max_size() const { return static_allocator.max_size(); }
    size_type capacity() const { return size_type(end_of_storage - begin()); }
    bool empty() const { return begin() == end(); }
 
	/* element access */
	reference operator[](size_type n) { return *(begin() + n); }
    const_reference operator[](size_type n) const { return *(begin() + n); }

	/* construct/copy/destruct */
	explicit vector(const allocator_type& alloc = allocator_type())
		:static_allocator(alloc), start(0), finish(0), end_of_storage(0)
	{
		std::cout << "Construct empty vector" << std::endl;
	}
	explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
		:static_allocator(alloc), start(0), finish(0), end_of_storage(0)
	{
		start = static_allocator.allocate(n);
		std::uninitialized_fill_n(start, n, val);
		finish = start + n;
		end_of_storage = finish;
	}
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, 
				const allocator_type& alloc = allocator_type(), 
				typename std::enable_if<!std::is_integral<InputIterator>::value,
                                InputIterator>::type * = 0)
		:static_allocator(alloc)
	{
		start = static_allocator.allocate(std::distance(first, last));
		finish = std::uninitialized_copy(first, last, start);
		end_of_storage = finish;
	}
	vector (const vector& x)
	{
		start = static_allocator.allocate(x.end() - x.begin());
		finish = std::uninitialized_copy(x.begin(), x.end(), start);
		end_of_storage = finish;
	}
	~vector()
	{ 
		//pointer	ptr;
		//ptr = static_allocator.address();
		while (finish != start)
			static_allocator.destroy(--finish);
		static_allocator.deallocate(start, capacity());
    }

	vector& operator=(const vector& x)
	{
		if (this != &x)
		{
			this->start = static_allocator.allocate(x.end() - x.begin());
			this->finish = std::uninitialized_copy(x.begin(), x.end(), start);
			this->end_of_storage = finish;
		}
		return (*this);
	}
};

}

#endif
