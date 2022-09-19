#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

namespace ft
{

template <class Iterator> class iterator_traits;
template <class T> class iterator_traits<T*>;
template <class T> class iterator_traits<const T*>;

template <class Iterator> class reverse_iterator;

}
#endif
