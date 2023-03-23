#ifndef TREE_HPP
# define TREE_HPP

# include "ft_iterator.hpp"

template <class Value, class Compare, class Allocator>
class tree
{

public:
    typedef Value       value_type;
    typedef Compare     value_compare;
    typedef Allocator   allocator_type;

private:
    typedef void* void_pointer;
    struct tree_node
    {
		void_pointer	parent;
        void_pointer    left;
        void_pointer    right;
        value_type      value_field;
        int             height;
    };
 
public:
    typedef typename allocator_type::template rebind<value_type>::other	value_allocator_type;
	typedef typename allocator_type::template rebind<tree_node>::other	tree_node_allocator_type;
	typedef typename value_allocator_type::pointer pointer;
    typedef typename value_allocator_type::reference reference;
    typedef typename value_allocator_type::const_reference const_reference;
    typedef typename tree_node_allocator_type::pointer node_pointer;
    typedef typename tree_node_allocator_type::size_type size_type;
    typedef typename tree_node_allocator_type::difference_type difference_type;
	typedef ft::tree_iterator<value_type, node_pointer, difference_type> iterator;

private:
    tree_node_allocator_type    tree_node_allocator;
    value_allocator_type        value_allocator;

	size_type					node_count;
	node_pointer				header;
	Compare						comp;

	node_pointer	get_node()
	{
		node_pointer	tmp = tree_node_allocator.allocate(1);
		tmp->height = 0;
		tmp->parent = 0;
		tmp->left = 0;
		tmp->right = 0;
		return (tmp);
	}
	node_pointer	minimum(node_pointer x)
	{
		while (x->left != 0)
			x = x->left;
		return (x);
	}
	node_pointer&	root() { return (header->parent); }
	node_pointer&	leftmost() { return (header->left); }
	node_pointer&	rightmost() { return (header->right); }

	

	iterator	__insert(node_pointer x, node_pointer y, const value_type& v)
	{
		++node_count;
    	node_pointer z = get_node();
    	//construct(value_allocator.address(value(z)), v);
		z->value_field = v;
    	if (y == header || x != 0 || comp(v.first, y.first))
		{
        	y->left = z;  // also makes leftmost() = z when y == root
        	if (y == header)
			{
            	root() = z;
            	rightmost() = z;
        	}
			else if (y == leftmost())
            	leftmost() = z;   // maintain leftmost() pointing to minimum node
    	}
		else
		{
        	y->right = z;
        	if (y == rightmost())
            	rightmost() = z;   // maintain rightmost() pointing to maximum node
    	}
    	z->parent = y;
    	z->left = 0;
    	z->right = 0;
		return (iterator(z));
	}

public:
	void	init()//tree node init
	{
		header = get_node();
		root() = get_node();
		leftmost() = root();
		rightmost() = root();
		root()->parent = header;
	}

	tree(const Compare& comp = Compare())
		:node_count(0), comp(comp)
	{
		init();
	}

	template <class InputIterator>
	tree(InputIterator first, InputIterator last)
	{
		init();
		insert(first, last);
	}

	iterator begin() { return leftmost(); }
	iterator end() { return rightmost(); }

	void insert(iterator first, iterator last) {
    	while (first != last) insert(*first++);
	}

	ft::pair<iterator, bool>		insert(const value_type& val)
	{
		node_pointer	x, y;
		bool		_comp = true;
		x = root();
		y = header;
		while (x != 0 && node_count != 0)
		{
			y = x;
			_comp = comp(val.second, x->first);
			if (_comp == true)
				x = x->left;
			else
				x = x->right;
		}
		iterator j = iterator(y);   
    	if (_comp)
       	{
			if (j == begin())     
            	return ft::pair<iterator, bool>(__insert(x, y, val), true);
        	else
            	--j;
		}
    	if (comp(j.node->first, val.first))
        	return ft::pair<iterator, bool>(__insert(x, y, val), true);
		return (ft::pair<iterator, bool>(j, false));
	}

    

};

#endif