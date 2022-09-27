#ifndef TREE_H
# define TREE_H

# include <memory>
# include <iostream>
# include <iterator>
# include <utility>
# include "ft_function.hpp"

template <class Key, class T, class KeyOfValue, class Compare = std::less<Key>, class Allocator = std::allocator<T> >
class	BinarySearchTree
{
	typedef Key									key_type;
	typedef T									mapped_type;
	typedef typename std::pair<key_type, mapped_type>	value_type;
	typedef Compare								key_compare;
	typedef Allocator							allocator_type;
	typedef typename allocator_type::size_type	size_type;
	//typedef typename std::allocator<value_type>::pointer	pointer;
	//typedef typename std::allocator<value_type>::reference	reference;
	typedef typename allocator_type::template rebind<value_type>::other	value_allocator_type;
	typedef typename value_allocator_type::pointer		pointer;
	typedef typename value_allocator_type::reference	reference;
	//typedef typename allocator_type::template rebind<value_type>::other::pointer pointer;
	//typedef typename allocator_type::template rebind<value_type>::other::reference reference;

protected:
	struct	bst_node
	{
		int			height;
		bst_node	*parent;
		bst_node	*left;
		bst_node	*right;
		value_type	value_field;	
	};
	
public:
	//typedef typename std::allocator<bst_node>		node_allocator_type;
	typedef typename allocator_type::template rebind<bst_node>::other	node_allocator_type;
	typedef typename node_allocator_type::pointer	link_type;

	class	iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		friend class BinarySearchTree;
	protected:
		link_type	node;
		iterator(link_type x) : node(x) {}
	public:
		//typedef typename std::allocator<value_type>::reference	reference;
		//typedef typename std::allocator<value_type>::pointer	pointer;
		iterator() {}
		/*iterator &operator=(const iterator &x)
		{
    		node = x.node;
    		return (*this);
  		}*/
		bool operator==(const iterator& y) const { return node == y.node; }
		bool operator!=(const iterator& y) const { return !operator==(y); }
		reference operator*() const { return (value(node)); };
		//reference operator->() const { return (value(node)); };
		pointer	operator->() const { return &(operator*()); }
		iterator& operator++()
		{
			if (node->right != 0) {
                node = node->right;
                while (node->left != 0)
                    node = node->left;
            } else {
                link_type y = node->parent;
                while (node == y->right) {
                    node = y;
                    y = y->parent;
                }
                if (node->right != y) // necessary because of rightmost 
                    node = y;
            }
			return (*this);
		}
		iterator operator++(int)
		{
            iterator tmp = *this;
            ++*this;
            return tmp;
        }
		iterator& operator--()
		{
			if (node->left != 0) {
                node = node->left;
                while (node->right != 0)
                    node = node->right;
            } else {
                link_type y = node->parent;
                while (node == y->left) {
                    node = y;
                    y = y->parent;
                }
                if (node->left != y) // necessary because of rightmost 
                    node = y;
            }
			return (*this);
		}
		iterator operator--(int)
		{
            iterator tmp = *this;
            --*this;
            return tmp;
        }

	};

protected:
	//link_type				root;
	link_type				header;
	size_type				node_count;
	key_compare				comp;
	//static	std::allocator<bst_node>	node_allocator;
	static node_allocator_type	node_allocator;
	static reference value(link_type x) { return (*x).value_field; }
	static key_type& key(const link_type x) { return  KeyOfValue()(value(x)); }
	link_type	get_node()
	{
		link_type	tmp = node_allocator.allocate(1);
		tmp->height = 0;
		tmp->parent = 0;
		tmp->left = 0;
		tmp->right = 0;
		return (tmp);
	}
	link_type	minimum(link_type x)
	{
		while (x->left != 0)
			x = x->left;
		return (x);
	}
	link_type&	root() { return (header->parent); }
	link_type&	leftmost() { return (header->left); }
	link_type&	rightmost() { return (header->right); }

private:
	void	init()//tree node init
	{
		header = get_node();
		root() = get_node();
		leftmost() = root();
		rightmost() = root();
		root()->parent = header;
	}
	iterator	__insert(link_type x, link_type y, const value_type& v)
	{
		++node_count;
    	link_type z = get_node();
    	//construct(value_allocator.address(value(z)), v);
		z->value_field = v;
    	if (y == header || x != 0 || comp(KeyOfValue()(v), key(y)))
		{
        	y->left = z;  // also makes leftmost() = z when y == header
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
		link_type	x, y;
		bool		_comp = true;
		x = root();
		y = header;
		while (x != 0 && size() != 0)
		{
			y = x;
			_comp = comp(KeyOfValue()(val), key(x));
			if (_comp == true)
				x = x->left;
			else
				x = x->right;
		}
		iterator j = iterator(y);   
    	if (_comp)
       	{
			if (j == begin())     
            	return std::pair<iterator, bool>(__insert(x, y, val), true);
        	else
            	--j;
		}
    	if (comp(key(j.node), KeyOfValue()(val)))
        	return std::pair<iterator, bool>(__insert(x, y, val), true);
		return (std::pair<iterator, bool>(j, false));
	}

	iterator insert (iterator position, const value_type& val)
	{
		
		if (position == iterator(begin()))
		{
			if (size() > 0 && comp(KeyOfValue()(val), key(position.node)))
            	return __insert(position.node, position.node, val);
            // first argument just needs to be non-NIL 
        	else
            	return insert(val).first;
		}
    	else if (position == iterator(end()))
		{
			if (comp(key(rightmost()), KeyOfValue()(val)))
            	return __insert(0, rightmost(), val);
        	else
            	return insert(val).first;
		}
    	else
		{
        	iterator before = --position;
        	if (comp(key(before.node), KeyOfValue()(val))
            	&& comp(KeyOfValue()(val), key(position.node)))
			{
				if (before.node->right == 0)
                	return __insert(0, before.node, val); 
            	else
                	return __insert(position.node, position.node, val);
			}
                // first argument just needs to be non-NIL 
        	else
            	return insert(val).first;
    	}
	}

	template <class InputIterator>
	void	insert(InputIterator first, InputIterator last)
	{
		while (first != last)
			insert(*first++);
	}

	void		erase();
	void		swap (BinarySearchTree& x);
	void		clear();

	iterator 	find (const key_type& k)
	{
		link_type y = header; /* Last node which is not less than k. */
   		link_type x = root(); /* Current node. */

   		while (x != 0) 
		{	
			if (!comp(key(x), k))
       			y = x, x = x->left;
   			else
       			x = x->right;
		}
   		iterator j = iterator(y);   
   		return (j == end() || comp(k, key(j.node))) ? end() : j;
	}
	size_type	count (const key_type& k) const;
	iterator	lower_bound (const key_type& k);
	iterator	upper_bound (const key_type& k);
	std::pair<iterator,iterator>             equal_range (const key_type& k);
	key_compare key_comp() const;
	iterator	end() { return (header); }
	//iterator	begin() { return (minimum(root())); }
	iterator	begin() { return (leftmost()); }

	void	inorder(link_type x)
	{
		if (x)
		{
			inorder(x->left);
			std::cout << "[Key: " << key(x) << " Value: " << x->value_field.second << "] ";
			//std::cout << key(x) << ' ';
			inorder(x->right);
		}
	}
	void	print()
	{
		link_type x = root();
		inorder(x);
		std::cout << std::endl;
	}

	//const_iterator find (const key_type& k) const;

};

template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
typename BinarySearchTree<Key, T, KeyOfValue, Compare, Allocator>::node_allocator_type BinarySearchTree<Key, T, KeyOfValue, Compare, Allocator>::node_allocator;

#endif
