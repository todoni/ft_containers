#ifndef FT_TYPE_TRAITS_HPP
# define FT_TYPE_TRAITS_HPP

namespace ft
{
template <class T, T v> struct integral_constant;
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;
template <class T> struct is_integral;
template <bool Cond, class T = void> struct enable_if;
template<class T> struct enable_if<true, T> { typedef T type; };

template <class T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T,v> type;
  operator value_type() { return v; }
};

template<class T>
struct	is_integral : public false_type {};
template <>	struct is_integral<bool>                   : public true_type {};
template <>	struct is_integral<char>                   : public true_type {};
template <>	struct is_integral<wchar_t>                : public true_type {};
template <>	struct is_integral<signed char>            : public true_type {};
template <>	struct is_integral<short int>              : public true_type {};
template <>	struct is_integral<int>                    : public true_type {};
template <>	struct is_integral<long int>               : public true_type {};
template <>	struct is_integral<long long int>          : public true_type {};
template <>	struct is_integral<unsigned char>          : public true_type {};
template <>	struct is_integral<unsigned short int>     : public true_type {};
template <>	struct is_integral<unsigned int>           : public true_type {};
template <>	struct is_integral<unsigned long int>      : public true_type {};
template <>	struct is_integral<unsigned long long int> : public true_type {};

}//namespace ft

#endif
