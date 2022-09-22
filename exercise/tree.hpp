#ifndef TREE_H
# define TREE_H

# include <memory>
# include <iostream>

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<T> >
class	BinarySearchTree
{
	typedef Key									key_type;
	typedef T									value_type;
	typedef Compare								key_compare;
	typedef Allocator							allocator_type;
	typedef typename allocator_type::size_type	size_type;
	typedef typename allocator_type::pointer	pointer;

protected:
	class	bst_node
	{
	public:
		int			height;
		bst_node	*left;
		bst_node	*right;
		value_type	data;
		
		
	};
	
public:
	typedef typename std::allocator<bst_node>		node_allocator_type;
	typedef typename node_allocator_type::pointer	link_type;
	class	iterator;

protected:
	link_type				root;
	size_type				node_count;
	key_compare				comp;
	static	std::allocator<bst_node>	node_allocator;

private:
	void	init()//tree node init
	{
		root = node_allocator.allocate(1);
		root->height = 0;
		root->left = 0;
		root->right = 0;
	}

public:
	BinarySearchTree(const Compare& comp = Compare())
		:node_count(0), comp(comp)
	{
		init();
	}
	~BinarySearchTree() {}

	bool		empty() const
	{
		return (node_count == 0);
	}
	size_type	size() const
	{
		return (node_count);
	}
	size_type	max_size() const
	{
		return (node_allocator.max_size());
	}

	std::pair<iterator, bool>		insert(const value_type& val)
	{
		
	}
	void		erase();
	void		swap (BinarySearchTree& x);
	void		clear();

	iterator 	find (const key_type& k);
	size_type	count (const key_type& k) const;
	iterator	lower_bound (const key_type& k);
	iterator	upper_bound (const key_type& k);
	std::pair<iterator,iterator>             equal_range (const key_type& k);

	//const_iterator find (const key_type& k) const;

};

template <class Key, class T, class Compare, class Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::node_allocator_type BinarySearchTree<Key, T, Compare, Allocator>::node_allocator;

#endif
