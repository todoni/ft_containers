#ifndef FT_FUNCTIONAL_HPP
# define FT_FUNCTIONAL_HPP

#include <functional>

template <class _Pair>
struct select1st : public std::unary_function<_Pair, typename _Pair::first_type>
{
    typename _Pair::first_type& operator()(_Pair& __x) const
    { return __x.first; }
    const typename _Pair::first_type& operator()(const _Pair& __x) const
    { return __x.first; }
};

#endif
