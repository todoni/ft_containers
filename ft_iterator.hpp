#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

# include <iterator>

namespace ft
{

template <class Iterator>
struct iterator_traits
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <class T>
struct iterator_traits<T*>
{
	typedef ptrdiff_t	difference_type;
	typedef T			value_type;
	typedef T*			pointer;
	typedef T&			reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

template <class T>
struct iterator_traits<const T*>
{
	typedef ptrdiff_t	difference_type;
	typedef T			value_type;
	typedef const T*	pointer;
	typedef const T&	reference;
	typedef std::random_access_iterator_tag	iterator_category;

};

template <class Iterator>
class reverse_iterator
{
public:
	typedef Iterator													iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
	typedef typename ft::iterator_traits<Iterator>::reference			reference;

protected:
	Iterator	it;

public:
	reverse_iterator() {}
	explicit reverse_iterator(iterator_type it)
		:it(it) {}
	template <class Iter>
	reverse_iterator(const reverse_iterator<Iter>& rev_it)
		:it(rev_it.base()) {}
	//reverse_iterator &operator=(const reverse_iterator &u) {
 //   it = u.base();
 //   return *this;
  //}
	iterator_type		base() const { return (it); }
	reference 			operator*() const
	{
		Iterator	temp = it;
		return (*--temp);
	}
	reverse_iterator	operator+(difference_type n) const { return reverse_iterator(it - n); }
	reverse_iterator&	operator++() //pre-increment
	{
		--it;
		return (*this);
	}
	reverse_iterator	operator++(int) //post-increment
	{
		reverse_iterator	temp = *this;
		--it;
		return (temp);
	}
	reverse_iterator&	operator+=(difference_type n)
	{
		it -= n;
		return (*this);
	}
	reverse_iterator	operator-(difference_type n) const { return reverse_iterator(it + n); }
	reverse_iterator&	operator--() //pre-decrement
	{
		++it;
		return (*this);
	}
	reverse_iterator	operator--(int) //post-decrement
	{
		reverse_iterator	temp = *this;
		++it;
		return (temp);
	}
	reverse_iterator&	operator-=(difference_type n)
	{
		it += n;
		return (*this);
	}
	pointer 			operator->() const { return &(operator*()); }
	reference 			operator[] (difference_type n) const { return *(*this + n); }

};

template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs, 
				const reverse_iterator<Iterator2>& rhs) { return (lhs.base() == rhs.base()); }
template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs, 
				const reverse_iterator<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }
template <class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs) { return (lhs.base() > rhs.base()); }
template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs, 
				const reverse_iterator<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); }
template <class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs) { return (lhs.base() < rhs.base()); }
template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs, 
				const reverse_iterator<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); }

template <class Iterator>
reverse_iterator<Iterator> operator+(
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it)
{
	return reverse_iterator<Iterator>(rev_it.base() - n);
}

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
    const reverse_iterator<Iterator1>& lhs,
    const reverse_iterator<Iterator2>& rhs)
{
	return (rhs.base() - lhs.base());
}

}
#endif
