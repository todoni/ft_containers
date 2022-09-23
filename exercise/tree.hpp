#ifndef TREE_H
# define TREE_H

# include <memory>
# include <iostream>
# include <iterator>
# include <utility>

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<T> >
class	BinarySearchTree
{
	typedef Key									key_type;
	typedef T									mapped_type;
	typedef typename std::pair<key_type, mapped_type>	value_type;
	typedef Compare								key_compare;
	typedef Allocator							allocator_type;
	typedef typename allocator_type::size_type	size_type;
	typedef typename allocator_type::pointer	pointer;
	typedef typename std::allocator<value_type>::reference	reference;

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
	typedef typename std::allocator<bst_node>		node_allocator_type;
	typedef typename node_allocator_type::pointer	link_type;
	class	iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		friend class BinarySearchTree;
	protected:
		link_type	node;
		iterator(link_type x) : node(x) {}
	public:
		iterator() {}
		/*iterator &operator=(const iterator &x)
		{
    		node = x.node;
    		return (*this);
  		}*/
		reference operator*() const { return (value(node)); };
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
	link_type				root;
	size_type				node_count;
	key_compare				comp;
	static	std::allocator<bst_node>	node_allocator;
	static reference value(link_type x) { return (*x).value_field; }
	link_type	get_node()
	{
		link_type	tmp = node_allocator.allocate(1);
		tmp->left = 0;
		tmp->right = 0;
		return (tmp);
	}
	

private:
	void	init()//tree node init
	{
		root = node_allocator.allocate(1);
		root->height = 0;
		root->parent = 0;
		root->left = 0;
		root->right = 0;
	}
	iterator	__insert(link_type x, link_type y, const value_type& v);

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
		x = root;
		y = root;
		int		right = 0;
		bool		_comp = true;
		++node_count;
		if (root->parent == 0 && size() == 1)
		{
			root->value_field = val;
			return (std::make_pair(iterator(root), _comp));
		}
		while (x != 0)
		{
			y = x;
			_comp = comp(val.first, x->value_field.first);
			std::cout << "insert key: " << val.first << " compare key: " << x->value_field.first << std::endl;
			if (_comp == true)
			{	
				x = x->left;
				right = 0;
				std::cout << "leftchild" << std::endl;
			}
			else
			{	
				x = x->right;
				right = 1;
			}
		}
		x = get_node();
		x->value_field = val;
		x->parent = y;
		if (right)
			y->right = x;
		else
			y->left = x;
		return (std::make_pair(iterator(x), _comp));
	}
	void		erase();
	void		swap (BinarySearchTree& x);
	void		clear();

	iterator 	find (const key_type& k);
	size_type	count (const key_type& k) const;
	iterator	lower_bound (const key_type& k);
	iterator	upper_bound (const key_type& k);
	std::pair<iterator,iterator>             equal_range (const key_type& k);

	void	inorder(link_type x)
	{
		if (x)
		{
			inorder(x->left);
			//std::cout << "[Key: " << x->value_field.first << " Value: " << x->value_field.second << "] ";
			std::cout << x->value_field.first << ' ';
			inorder(x->right);
		}
	}
	void	print()
	{
		link_type x = root;
		inorder(x);
		std::cout << std::endl;
	}

	//const_iterator find (const key_type& k) const;

};

template <class Key, class T, class Compare, class Allocator>
typename BinarySearchTree<Key, T, Compare, Allocator>::node_allocator_type BinarySearchTree<Key, T, Compare, Allocator>::node_allocator;

#endif
