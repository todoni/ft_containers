#ifndef TREE_H
# define TREE_H

# include <memory>

template <class T, class Allocator = std::allocator<T> >
class	BinarySearchTree
{
	typedef T									value_type;
	typedef Allocator							allocator_type;
	typedef typename allocator_type::size_type	size_type;
	typedef typename allocator_type::pointer	pointer;

protected:
	class	bst_node
	{
		int			height;
		bst_node	*left;
		bst_node	*right;
		value_type	data;
	};
	
public:
	typedef typename std::allocator<bst_node>		node_allocator_type;
	typedef typename node_allocator_type::pointer	link_type;

protected:
	link_type				root;
	static allocator_type	node_allocator;
	size_type				node_count;

public:
	BinarySearchTree() :root(0) {}
	~BinarySearchTree();
	void	erase();
	void	insert();

};

#endif
