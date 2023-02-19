#ifndef FT_UTILITY_HPP
# define FT_UTILITY_HPP

namespace ft
{

template <class T1, class T2>
struct pair
{
	typedef T1	first_type;
	typedef T2	second_type;

	static first_type	first;
	static second_type	second;

public:
	pair()
		:first(T1()), second(T2()) { }
	template<class U, class V> pair(const pair<U,V>& pr) : first(T1()), second(T2())
	{
		this->first = pr.first;
		this->second = pr.second;
	}
	pair(const first_type& a, const second_type& b)
	{
		this->first = a;
		this->second = b;
	}
	pair& operator=(const pair& pr)
	{
		if (this != &pr)
		{
			this->first = pr.first;
			this->second = pr.second;
		}
		return (*this);
	}
};

template <class T1, class T2>  pair<T1,T2> make_pair (T1 x, T2 y)
{
	return ( pair<T1,T2>(x,y) );
}

template <class T1, class T2>
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first == rhs.first && lhs.second == rhs.second; }

template <class T1, class T2>
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs == rhs); }

template <class T1, class T2>
bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template <class T1, class T2>
bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs < lhs); }

template <class T1, class T2>
bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs < lhs; }

template <class T1, class T2>
bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs < rhs); }

}

#endif
