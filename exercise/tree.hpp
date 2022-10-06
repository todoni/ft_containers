#ifndef TREE_H
# define TREE_H

# include <memory>
# include <iostream>
# include <iterator>
# include <utility>
# include "ft_functional.hpp"

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

		/*print*/
		int	edge_length;
		int	lablen;
		int	parent_dir;
		char	label[11];
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
			if (node->right != NIL) {
                node = node->right;
                while (node->left != NIL)
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
			if (node->left != NIL) {
                node = node->left;
                while (node->right != NIL)
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
	//link_type				root();
	link_type				header;
	static link_type				NIL;
	static link_type	free_list;
	static link_type 	next_avail;
	static link_type 	last;
	size_type				node_count;
	key_compare				comp;
	//static	std::allocator<bst_node>	node_allocator;
	typedef node_allocator_type buffer_allocator_type;
	typedef pointer	buffer_pointer;
	static node_allocator_type	node_allocator;
	static value_allocator_type	value_allocator;
	buffer_allocator_type	buffer_allocator;
	static buffer_pointer buffer_list;
	static reference value(link_type x) { return (*x).value_field; }
	static key_type& key(const link_type x) { return  KeyOfValue()(value(x)); }
	size_type buffer_size() {
        return node_allocator.max_size();
    }
	void add_new_buffer() {
        buffer_pointer tmp = buffer_allocator.allocate((size_type)1);
        tmp->buffer = node_allocator.allocate(buffer_size());
        tmp->next_buffer = buffer_list;
        buffer_list = tmp;
        next_avail = buffer_list->buffer;
        last = next_avail + buffer_size();
    }
	link_type	get_node()
	{
		link_type	tmp = node_allocator.allocate(1);
		tmp->height = 0;
		tmp->parent = NIL;
		tmp->left = NIL;
		tmp->right = NIL;

        return (tmp);
	}
	link_type	minimum(link_type x)
	{
		while (x->left != NIL)
			x = x->left;
		return (x);
	}
	link_type	maximum(link_type x)
	{
		while (x->right != NIL)
			x = x->right;
		return (x);
	}
	int	height(const link_type& node)
    {
        if(node == NIL)
            return -1;
        else
            return std::max(height(node->left), height(node->right)) + 1;
    }
	int	get_balance_factor(link_type& node)
	{
		return (height(node->left) - height(node->right));
	}
	void		set_height(link_type& node)
	{
		if(node != NIL)
        {
            set_height(node->left);
            set_height(node->right);
            node->height = height(node);
        }
	}
	
	link_type balance(link_type& node)
    {
        //bf is Called Balance Factor
        int	bf = get_balance_factor(node);
        
        //If Left Subtree Violates AVL Property
        if(bf > 1)
        {    
            if(get_balance_factor(node->left) > 0)
                node = LL_Rotation(node);
            else
                node = LR_Rotation(node);
        }
        //If Right Subtree Violates AVL Property
        else if(bf < -1)
        {
            if(get_balance_factor(node->right) < 0)
                node = RR_Rotation(node);
            else
                node = RL_Rotation(node);
        } 
        return node;
    }

    link_type LL_Rotation(link_type& parent)
    {
        link_type node = parent->left;
        parent->left = node->right;
        node->right = parent;
		//rightmost() = maximum(root());
		//leftmost() = minimum(root());
        return node;
    }
 
    link_type RR_Rotation(link_type& parent)
    {
        link_type node = parent->right;
        parent->right = node->left;
        node->left = parent;
		//leftmost() = minimum(root());
		//rightmost() = maximum(root());
        return node;
    }
 
    link_type LR_Rotation(link_type& parent)
    {
        link_type leftNode = parent->left;
        parent->left = RR_Rotation(leftNode);
        return LL_Rotation(parent);
    }
 
    link_type RL_Rotation(link_type& parent)
    {
        link_type rightNode = parent->right;
        parent->right = LL_Rotation(rightNode);
        return RR_Rotation(parent);
    }

	link_type&	root() { return (header->parent); }
	link_type&	leftmost() { return (header->left); }
	link_type&	rightmost() { return (header->right); }

private:
	void	init()//tree node init
	{
		if (NIL == 0) {
            NIL = get_node();
            //color(NIL) = black;
            NIL->parent = 0;
            NIL->left = 0;
            NIL->right = 0;
        }
		header = get_node();
		root() = NIL;
		leftmost() = header;
		rightmost() = header;
		//header->left = root();
		//root() = get_node();
		/*root() = header;
		leftmost() = header;
		rightmost() = header;*/
		//root()->parent = header;
	}
	
	iterator	__insert(link_type x, link_type y, const value_type& v)
	{
		++node_count;
    	link_type z = get_node();
    	//construct(value_allocator.address(value(z)), v);
		z->value_field = v;
    	if (y == header || x != NIL || comp(KeyOfValue()(v), key(y)))
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
    	z->left = NIL;
    	z->right = NIL;
		
		//set_height(root());
		//root() = balance(root());

		//z->height = height(z);
		//std::cout << "height: " << z->height << std::endl;
		//x = z;
		//x = balance(root());
		//set_height(root());
		return (iterator(z));
	}
	void	__erase(link_type x)
	{
		while (x != NIL)
		{
			__erase(x->right);
			link_type y = x->left;
			value_allocator.destroy(value(x));
			x = y;
		}
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
		while (x != NIL)
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
            	return __insert(NIL, rightmost(), val);
        	else
            	return insert(val).first;
		}
    	else
		{
        	iterator before = --position;
        	if (comp(key(before.node), KeyOfValue()(val))
            	&& comp(KeyOfValue()(val), key(position.node)))
			{
				if (before.node->right == NIL)
                	return __insert(NIL, before.node, val); 
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

	void		erase(iterator position)
	{
		link_type z = position.node;
		link_type y = z;
		link_type x;
		
		if (y->left == NIL)
		{
			x = y->right;
		}
		else
		{   
			if (y->right == NIL) 
		        x = y->left;
		    else 
			{
		        y = y->right;
		        while (y->left != NIL)
		            y = y->left;
		        x = y->right;
		    }
		}
		if (y != z)
		{ // relink y in place of z
		    z->left->parent = y; 
		    y->left = z->left;
		    if (y != z->right)
			{
		        x->parent = y->parent; // possibly x == 0
		        y->parent->left = x;   // y must be a left child
		        y->right = z->right;
		        z->right->parent = y;
		    }
			else
				x->parent = y;  // needed in case x == 0
		    if (root() == z)
		        root() = y;
		    else if (z->parent->left == z)
		        z->parent->left = y;
		    else 
		        z->parent->right = y;
		    y->parent = z->parent;
		    //std::swap(color(y), color(z));
		    y = z;                  // y points to node to be actually deleted
		}
		else
		{  // y == z
		    x->parent = y->parent;   // possibly x == 0
		    if (root() == z)
		        root() = x;
		    else 
			{
				if (z->parent->left == z)
		            z->parent->left = x;
		        else
		            z->parent->right = x;
			}
			if (leftmost() == z) 
			{
				if (z->right == NIL)  // z->left must be 0 also
					leftmost() = z->parent;
		    	else
		        	leftmost() = minimum(x);
			}       // makes leftmost() == header if z == root()
		    if (rightmost() == z)  
			{
				if (z->left == NIL) // z->right must be 0 also
					rightmost() = z->parent;  
		    	else  // x == z->left
		        	rightmost() = maximum(x);
			}       // makes rightmost() == header if z == root()
		}
		//root() = balance(root());
		//set_height(root());
		value_allocator.destroy(value_allocator.address(value(y)));
		node_allocator.destroy(y);
		//node_allocator.deallocate(y, 1);
		--node_count;
	}
	size_type	erase(const key_type& k);
	void		erase(iterator first, iterator last);
	void		swap (BinarySearchTree& x);
	void		clear();

	iterator 	find (const key_type& k)
	{
		link_type y = header; /* Last node which is not less than k. */
   		link_type x = root(); /* Current node. */

   		while (x != NIL) 
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
		if (x != NIL)
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
	void printBT(const std::string& prefix, const link_type node, bool isLeft)
	{
    	if( node != NIL )
    	{
        	std::cout << prefix;

        	std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        	std::cout << key(node) << " " << height(node) << std::endl;
        	//std::cout << key(node) << std::endl;

        // enter the next tree level - left and right branch
        	printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        	printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    	}
	}

	void printBT(const link_type node)
	{
    	printBT("", node, false);    
	}

	void printBT(void)
	{
		printBT(root());
	}
	
};

template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
typename BinarySearchTree<Key, T, KeyOfValue, Compare, Allocator>::node_allocator_type BinarySearchTree<Key, T, KeyOfValue, Compare, Allocator>::node_allocator;

template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
typename BinarySearchTree<Key, T, KeyOfValue, Compare, Allocator>::value_allocator_type BinarySearchTree<Key, T, KeyOfValue, Compare, Allocator>::value_allocator;

template <class Key, class T, class KeyOfValue, class Compare, class Allocator>
typename BinarySearchTree<Key, T, KeyOfValue, Compare, Allocator>::link_type BinarySearchTree<Key, T, KeyOfValue, Compare, Allocator>::NIL = 0;
#endif
