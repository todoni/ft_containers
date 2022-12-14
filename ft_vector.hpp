#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <memory>
# include "ft_algorithm.hpp"
# include <algorithm> //TODO: ft_algorithm 구현 되면 바꿔야함
# include "ft_iterator.hpp"
# include "ft_type_traits.hpp"

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
	typedef ft::reverse_iterator<iterator>	reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

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
    reverse_iterator rbegin() { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const { 
        return const_reverse_iterator(end()); 
    }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const { 
        return const_reverse_iterator(begin()); 
    }

	/* capacity */
    size_type	size() const { return size_type(end() - begin()); }
    size_type	max_size() const { return static_allocator.max_size(); }
    size_type	capacity() const { return size_type(end_of_storage - begin()); }
    bool		empty() const { return begin() == end(); }
	void		reserve(size_type n)
	{
		if (n > max_size())
			throw std::length_error("vector");
		if (n > capacity())
		{
			/*reallocate*/
			iterator tmp = static_allocator.allocate(n);
			size_type save = size();
			std::uninitialized_copy(begin(), end(), tmp);
			while (finish != start)
				static_allocator.destroy(--finish);
	    	static_allocator.deallocate(start, capacity());
	    	finish = tmp + save;
	    	start = tmp;
	    	end_of_storage = begin() + n;
		}
	}
	void		resize(size_type n, value_type val = value_type())
	{
		size_type	size_ = size();
		for (size_type i = n; i < size_; i++)
			static_allocator.destroy(--finish);
		reserve(n);
		for (size_type i = size(); i < n; i++)
		{	
			static_allocator.construct(finish, val);
			++finish;
		}
	}
 
	/* element access */
	reference		operator[](size_type n) { return *(begin() + n); }
    const_reference operator[](size_type n) const { return *(begin() + n); }
	reference		at(size_type n)
	{
		if (n >= size())
			throw std::out_of_range("vector");
		return (*(begin() + n));
	}
	const_reference	at(size_type n) const
	{
		if (n >= size())
			throw std::out_of_range("vector");
		return (*(begin() + n));
	}
	reference front()
	{
		return (*begin());
	}
	const_reference front() const
	{
		return (*begin());
	}
	reference back()
	{
		return (*(end() - 1));
	}
	const_reference back() const
	{
		return (*(end() - 1));
	}

	/* construct/copy/destruct */
	explicit vector(const allocator_type& alloc = allocator_type())
		:static_allocator(alloc), start(0), finish(0), end_of_storage(0)
	{
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
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
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
		/*if (this != &x)
		{
			this->start = static_allocator.allocate(x.end() - x.begin());
			this->finish = std::uninitialized_copy(x.begin(), x.end(), start);
			this->end_of_storage = finish;
		}
		return (*this);*/

		if (&x == this) return *this;
    	if (x.size() > capacity())
		{
			while (finish != start)
				static_allocator.destroy(--finish);
			//destroy(start, finish);
			static_allocator.deallocate(start, capacity());
			start = static_allocator.allocate(x.end() - x.begin());
			end_of_storage = std::uninitialized_copy(x.begin(), x.end(), start);
    	}
		else if (size() >= x.size())
		{
			iterator i = std::copy(x.begin(), x.end(), begin());
			while (finish != i)
				static_allocator.destroy(--finish);
			// work around for destroy(copy(x.begin(), x.end(), begin()), finish);
    	}
		else
		{
			std::copy(x.begin(), x.begin() + size(), begin());
			std::uninitialized_copy(x.begin() + size(), x.end(), begin() + size());
    	}
    	finish = begin() + x.size();
    	return (*this);
	}
protected:
	typename vector<T, Allocator>::size_type __recommend(size_type __new_size) const
	{
    	const size_type __ms = max_size();
    	if (__new_size > __ms)
        	throw std::length_error("vector");
    	const size_type __cap = capacity();
    	if (__cap >= __ms / 2)
        	return __ms;
    	return _VSTD::max<size_type>(2*__cap, __new_size);
	}

	void	insert_aux(iterator position, const value_type& x)
	{
		if (finish != end_of_storage) 
		{
			static_allocator.construct(finish, *(finish - 1));
			std::copy_backward(position, finish - 1, finish);
			*position = x;
			++finish;
    	}
		else //TODO std 처럼 바꾸기
		{
			//size_type len = size() ?  2 * size() : 1;
			size_type len = __recommend(size() + 1);
			iterator tmp = static_allocator.allocate(len);
			std::uninitialized_copy(begin(), position, tmp);
			static_allocator.construct(tmp + (position - begin()), x);
			std::uninitialized_copy(position, end(), tmp + (position - begin()) + 1); 
			static_allocator.destroy(end());
			static_allocator.deallocate(begin(), capacity());
			end_of_storage = tmp + len;
			finish = tmp + size() + 1;
			start = tmp;
   	 	}
	}

	

public:
	void		push_back(const value_type& val)
	{
		if (finish != end_of_storage)
		{
	    /* Borland bug */
	    	static_allocator.construct(finish, val);
	    	finish++;
		}
		else
	    	insert_aux(end(), val);
	}
	void		pop_back(void)
	{
		--finish;
		static_allocator.destroy(end());
	}
	iterator	insert(iterator position, const value_type& val)
	{
		size_type dist = position - begin();
		if (finish != end_of_storage && position == end())
		{
	    	/* Borland bug */
	    	construct(finish, val);
	    	finish++;
		}
		else
	    	insert_aux(position, val);
		return (begin() + dist);
	}
	void		insert(iterator position, size_type n, const value_type& val)
	{
		if (end_of_storage - finish >= n)
		{
			if (end() - position > n)
			{
				std::uninitialized_copy(end() - n, end(), end());
				std::copy_backward(position, end() - n, end());
				std::fill(position, position + n, val);
			}
			else
			{
				std::uninitialized_copy(position, end(), position + n);
				std::fill(position, end(), val);
				std::uninitialized_fill_n(end(), n - (end() - position), val);
			}
			finish += n;	
		}
		else
		{
			size_type len = __recommend(size() + n);
			size_type	save = size();
			iterator tmp = static_allocator.allocate(len);
			std::uninitialized_copy(begin(), position, tmp);
			std::uninitialized_fill_n(tmp + (position - begin()), n, val);
			std::uninitialized_copy(position, end(), tmp + (position - begin() + n));
			while (finish != start)
				static_allocator.destroy(--finish);
			static_allocator.deallocate(start, capacity());
			end_of_storage = tmp + len;
			finish = tmp + save + n;
			start = tmp;
		}
	}
	template <class InputIterator>
	void	insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                				InputIterator>::type * = 0)
	{
		size_type n = std::distance(first, last);
		if (end_of_storage - finish >= n)
		{
			if (end() - position > n)
			{
				std::uninitialized_copy(end() - n, end(), end());
				std::copy_backward(position, end() - n, end());
				std::copy(first, last, position);
			}
			else
			{
				std::uninitialized_copy(position, end(), position + n);
				std::copy(first, first + (end() - position), position);
				std::uninitialized_copy(first + (end() - position), last, end());
			}
			finish += n;	
		}
		else
		{
			//size_type len = size() + std::max(size(), n);
			size_type len = __recommend(size() + n);
			size_type	save = size();
			iterator tmp = static_allocator.allocate(len);
			std::uninitialized_copy(begin(), position, tmp);
			std::uninitialized_copy(first, last, tmp + (position - begin()));
			std::uninitialized_copy(position, end(), tmp + (position - begin() + n));
			while (finish != start)
				static_allocator.destroy(--finish);
			static_allocator.deallocate(start, capacity());
			end_of_storage = tmp + len;
			finish = tmp + save + n;
			start = tmp;
		}	
	}
	template <class InputIterator>
	void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
	{
		size_type	n = std::distance(first, last);
		size_type	len = __recommend(n);
		iterator tmp = static_allocator.allocate(len);
		std::uninitialized_copy(first, last, tmp);
		while (finish != start)
			static_allocator.destroy(--finish);
		end_of_storage = tmp + len;
		finish = tmp + n;
		start = tmp;
	}
	void assign(size_type n, const value_type& val)
	{
		size_type len = __recommend(n);
		iterator tmp = static_allocator.allocate(len);
		std::uninitialized_fill_n(tmp, n, val);
		while (finish != start)
			static_allocator.destroy(--finish);
		static_allocator.deallocate(start, capacity());
		end_of_storage = tmp + len;
		finish = tmp + n;
		start = tmp;
	}
	iterator	erase(iterator position)
	{
		if (position + 1 != end())
			std::copy(position + 1, end(), position);
		--finish;
		static_allocator.destroy(finish);
		return (position);
	}
	iterator	erase(iterator first, iterator last)
	{
		iterator i = std::copy(last, end(), first);
		while (finish != i)
			static_allocator.destroy(--finish);
		return (i);
	}
	void		swap(vector& x)
	{
		std::swap(start, x.start);
		std::swap(finish, x.finish);
		std::swap(end_of_storage, x.end_of_storage);
	}
	void		clear()
	{
		while (finish != start)
			static_allocator.destroy(--finish);
	}
	allocator_type get_allocator() const
	{
		return (static_allocator);
	}
};

template <class T, class Alloc>
inline bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
inline bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!operator==(lhs, rhs));
}

template <class T, class Alloc>
inline bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
inline bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (operator<(lhs, rhs) || operator==(lhs, rhs));
}

template <class T, class Alloc>
inline bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!operator<(lhs, rhs) && !operator==(lhs, rhs));
}

template <class T, class Alloc>
inline bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!operator<(lhs, rhs));
}

template<class T, class Alloc>
void swap(vector<T,Alloc>& lhs, vector<T,Alloc>& rhs)
{
	vector<T, Alloc>	tmp;

	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

}




#endif
