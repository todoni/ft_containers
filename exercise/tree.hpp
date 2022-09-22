#ifndef TREE_H
# define TREE_H

# include <memory>

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
		int			height;
		bst_node	*left;
		bst_node	*right;
		value_type	data;
		
		static std::allocator<bst_node>	node_allocator;
	};
	
public:
	typedef typename std::allocator<bst_node>		node_allocator_type;
	typedef typename node_allocator_type::pointer	link_type;
	class	iterator;

protected:
	link_type				root;
	size_type				node_count;
	key_compare				comp;

private:
	void	init(); //tree node init

public:
	BinarySearchTree(const Compare& comp = Compare())
		:node_count(0), comp(comp)
	{
		init();
	}
	~BinarySearchTree();

	bool		empty() const;
	size_type	size() const;
	size_type	max_size() const;

	void		insert();
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

#endif
