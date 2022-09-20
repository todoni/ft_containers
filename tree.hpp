#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <functional>
# include <utility> //TODO: ft_utility.hpp

template<class Key, class Value, class KeyOfValue, class Compare>
class	avl_tree
{
/*protected:
	typedef std::allocator<void>::pointer void_pointer;
	struct	avl_tree_node
	{
		int				height;
		void_pointer	parent_link;
		void_pointer	left_link;
		void_pointer	right_link;
		Value			value_field;
	};
	static std::allocator<avl_tree_node>	avl_tree_node_allocator;
    static std::allocator<Value> 			value_allocator;
*/
protected:
	//typedef avl_tree_node*	node_pointer;
	typedef std::allocator<void>::pointer void_pointer;
	class	avl_tree_node
	{
		int				height;
		void_pointer	parent;
		void_pointer	left;
		void_pointer	right;
		Value			value;
	};
public:
	typedef Key		key_type;
    typedef Value	value_type;
    typedef typename std::allocator<Value>::pointer pointer;
    typedef typename std::allocator<Value>::reference reference;
    typedef typename std::allocator<Value>::const_reference const_reference;
    typedef std::allocator<avl_tree_node> avl_tree_node_allocator_type;
    typedef typename std::allocator<avl_tree_node>::pointer link_type;
    typedef typename std::allocator<avl_tree_node>::size_type size_type;
    typedef typename std::allocator<avl_tree_node>::difference_type difference_type;

protected:
	link_type		header;
	size_type		node_count;

	/*balancing*/
	/*insert*/
	/*delete*/

public:
	/*construct, destruct*/
	/*public insert, delete*/
	/*search*/
};


#endif
