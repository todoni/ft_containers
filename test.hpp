#ifndef TEST_HPP
# define TEST_HPP

template <class Key, class Value, class KeyOfValue, class Compare>
class Test
{
    typedef void* link_type;
public:
    void __erase(link_type x);
};

template <class Key, class Value, class KeyOfValue, class Compare>
void Test<Key, Value, KeyOfValue, Compare>::__erase(link_type x) {

}

#endif