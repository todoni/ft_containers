template <class Key, class Value, class KeyOfValue, class Compare >
class	BinarySearchTree
{
public:
	typedef Key		key_type;
	typedef Value	value_type;
	typedef std::allocator<BinarySearchTree>			allocator_type;

protected:
	struct	bst_node
	{
		int			height;
		bst_node	*parent;
		bst_node	*left;
		bst_node	*right;
		value_type	value_field;	
	};
	//typedef typename std::allocator<value_type>::pointer	pointer;
	//typedef typename std::allocator<value_type>::reference	reference;
public:
    typedef typename allocator_type::template rebind<value_type>::other	value_allocator_type;
	typedef typename allocator_type::template rebind<bst_node>::other	node_allocator_type;
};