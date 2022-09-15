#pragma once


#include <memory>
#include "utils.hpp"
#include "iterator.hpp"

namespace ft
{
	enum rb_tree_color { red = false, black = true };

	struct rb_tree_node_base
	{
		typedef rb_tree_color color_type;
		typedef rb_tree_node_base*			base_pointer;
		typedef const rb_tree_node_base*	const_base_pointer;

		color_type			color;
		base_pointer		parent;
		base_pointer		left;
		base_pointer		right;

		//minimum node in the subtree
		static base_pointer static_minimum(base_pointer x)
		{
			while (x->left != 0)
			{
				x = x->left;
			}
				
			return x;
		}
		
		static const_base_pointer static_minimum(const_base_pointer x)
		{
			while (x->left != 0)
			{
				x = x->left;
			}
			return x;
		}
		
		//maximum node in the subtree
		static base_pointer static_maximum(base_pointer x)
		{
			while (x->right != 0)
			{
				x = x->right;
			}	
			return x;
		}
		
		static const_base_pointer static_maximum(const_base_pointer x)
		{
			while (x->right != 0)
			{
				x = x->right;
			}
			return x;
		}
	};

	template<typename Value>
	struct rb_tree_node : public rb_tree_node_base
	{
		typedef rb_tree_node<Value>*	link_type;
		Value	value_field;
	};

	template<typename T>
	struct rb_tree_iterator
	{
		typedef T										value_type;
		typedef T&										reference;
		typedef T*										pointer;
		typedef rb_tree_node<T>*							link_type;
		typedef rb_tree_node_base::base_pointer				base_pointer;

		typedef ptrdiff_t									difference_type;
		typedef typename std::bidirectional_iterator_tag	iterator_category;
		typedef rb_tree_iterator<T>							self;		

		rb_tree_iterator() : node() {}

		explicit rb_tree_iterator(link_type x) : node(x) {}

		reference operator*() const
		{
			return static_cast<link_type>(node)->value_field;
		}

		pointer operator->() const
		{
			return &static_cast<link_type>(node)->value_field;
		}

		self& operator++()
		{
			increment();
			return *this;
		}

		self operator++(int)
		{
			self temp = *this;
			increment();
			return temp;
		}

		self& operator-- ()
		{
			decrement();
			return *this;
		}

		self operator--(int)
		{
			self temp = *this;
			decrement();
			return temp;
		}

		bool operator==(const self& x) const
		{
			return node == x.node;
		}

		bool operator!=(const self& x) const
		{
			return node != x.node;
		}

/*
* 1. If the node has a right child, then the node is set to the right child and the loop continues.
* 2. Otherwise, the node is set to the parent.
* 3. If the node is the parent’s left child, then the loop is exited.
* 4. Otherwise, the node is set to the parent’s parent and the loop continues.
*/
		void increment()
		{
			if (node->right != 0)
			{
				node = node->right;
				while (node->left != 0)
				{
					node = node->left;
				}
			}
			else 
			{
				rb_tree_node_base* y = node->parent;

				while (node == y->right) 
				{
					node = y;
					y = y->parent;
				}
				if (node->right != y)
				{
					node = y;
				}	
			}
		}

/*
* 1. If the node is red and its parent is the root, then the node is the root.
* 2. If the node is red and its parent is not the root, then the node is the right child of its parent.
* 3. If the node is black and its left child is not null, then the node is the left child of its left child.
* 4. If the node is black and its left child is null, then the node is the parent of its left child.
*/
		void decrement()
		{
			if (node->color == red && node->parent->parent == node)
			{
				node = node->right;
			}
			else if (node->left != 0) 
			{
				rb_tree_node_base* y = node->left;

				while (y->right != 0)
				{
					y = y->right;
				}
					
				node = y;
			}
			else 
			{
				rb_tree_node_base* y = node->parent;

				while (node == y->left) 
				{
					node = y;
					y = y->parent;
				}

				node = y;
			}
		}

		base_pointer	node;
	};

	template<typename T>
	struct rb_tree_const_iterator
	{
		typedef T												value_type;
		typedef const T&										reference;
		typedef const T*										pointer;

		typedef typename std::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t										difference_type;
		typedef rb_tree_iterator<T>								iterator;
		typedef rb_tree_const_iterator<T>						self;

		typedef rb_tree_node_base::const_base_pointer			base_pointer;
		typedef const rb_tree_node<T>*							link_type;

		rb_tree_const_iterator() : node() {}

		explicit rb_tree_const_iterator(link_type x) : node(x) {}

		rb_tree_const_iterator(const iterator& it) : node(it.node) {}

		iterator constant_cast() const
		{
			return iterator(static_cast<typename iterator::link_type>(const_cast<typename iterator::base_pointer>(node)));
		}

		reference operator*() const
		{
			return static_cast<link_type>(node)->value_field;
		}

		pointer operator->() const
		{
			return &static_cast<link_type>(node)->value_field;
		}

		self& operator++()
		{
			increment();
			return *this;
		}

		self operator++(int)
		{
			self temp = *this;
			increment();
			return temp;
		}

		self& operator--()
		{
			decrement();
			return *this;
		}

		self operator--(int)
		{
			self temp = *this;
			decrement();
			return temp;
		}

		bool operator==(const self& x) const
		{
			return node == x.node;
		}

		bool operator!=(const self& x) const
		{
			return node != x.node;
		}

/*
* 1. If the node has a right child, then the node is set to the right child and the loop continues.
* 2. Otherwise, the node is set to the parent.
* 3. If the node is the parent’s left child, then the loop is exited.
* 4. Otherwise, the node is set to the parent’s parent and the loop continues.
*/
		void increment()
		{
			if (node->right != 0)
			{
				node = node->right;

				while (node->left != 0)
				{
					node = node->left;
				}
			}
			else 
			{
				rb_tree_node_base* y = node->parent;

				while (node == y->right) 
				{
					node = y;
					y = y->parent;
				}
				if (node->right != y)
				{
					node = y;
				}	
			}
		}

/*
* 1. If the node is red and its parent is the root, then the node is the root.
* 2. If the node is red and its parent is not the root, then the node is the right child of its parent.
* 3. If the node is black and its left child is not null, then the node is the left child of its left child.
* 4. If the node is black and its left child is null, then the node is the parent of its left child.
*/
		void decrement()
		{
			if (node->color == red && node->parent->parent == node)
			{
				node = node->right;
			}
			else if (node->left != 0) 
			{
				rb_tree_node_base* y = node->left;

				while (y->right != 0)
				{
					y = y->right;
				}
					
				node = y;
			}
			else 
			{
				rb_tree_node_base* y = node->parent;

				while (node == y->left) 
				{
					node = y;
					y = y->parent;
				}

				node = y;
			}
		}

		base_pointer node;
	};

	template<typename Value>
	inline bool operator==(const rb_tree_iterator<Value>& x, const rb_tree_const_iterator<Value>& y)
	{
		return x.node == y.node;
	}

	template<typename Value>
	inline bool operator!=(const rb_tree_iterator<Value>& x, const rb_tree_const_iterator<Value>& y)
	{
		return x.node != y.node;
	}

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc = std::allocator<Value> >
	class red_black_tree
	{
		typedef typename Alloc::template rebind<rb_tree_node<Value> >::other node_allocator;

	public:
		typedef Key												key_type;
		typedef Value											value_type;
		typedef value_type*										pointer;
		typedef const value_type*								const_pointer;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef rb_tree_node<Value>*							link_type;
		typedef const rb_tree_node<Value>*						const_link_type;
		typedef size_t											size_type;
		typedef ptrdiff_t										difference_type;
		typedef Alloc											allocator_type;
		typedef rb_tree_iterator<value_type>					iterator;
		typedef rb_tree_const_iterator<value_type>				const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;	

	protected:
		typedef rb_tree_node_base* base_pointer;
		typedef const rb_tree_node_base* const_base_pointer;

		template <typename Key_compare>
		struct rbt_implementation : public node_allocator
		{
			Key_compare key_compare;
			rb_tree_node_base header;
			size_type node_count;
			
			rbt_implementation() : node_allocator(), key_compare(), header(), node_count(0) { init(); }
			rbt_implementation(const Key_compare& compare, const node_allocator& allocator) : node_allocator(allocator), key_compare(compare), header(), node_count(0) { init(); }
			
		private:

			void	init()
			{
				this->header.color = red;
				this->header.parent = 0;
				this->header.left = &this->header;
				this->header.right = &this->header;
			}
		};

		rbt_implementation<Compare>	red_black_tree_implementation;

		link_type get_node()
		{
			return red_black_tree_implementation.node_allocator::allocate(1);
		}

		void put_node(link_type p)
		{
			red_black_tree_implementation.node_allocator::deallocate(p, 1);
		}
		
		link_type create_node(const value_type& x)
		{
			link_type temp = get_node();

			try
			{
				get_allocator().construct(&(temp->value_field), x);
			}
			catch(...)
			{
				put_node(temp);
				throw;
			}
			return temp;
		}

		void destroy_node(link_type p)
		{
			get_allocator().destroy(&(p->value_field));
			put_node(p);
		}

		link_type clone_node(const_link_type x)
		{
			link_type	temp = create_node(x->value_field);
			temp->color = x->color;
			temp->left = 0;
			temp->right = 0;
			return temp;
		}

		base_pointer& root()
		{
			return this->red_black_tree_implementation.header.parent;
		}

		const_base_pointer root() const
		{
			return this->red_black_tree_implementation.header.parent;
		}

		base_pointer& leftmost()
		{
			return this->red_black_tree_implementation.header.left;
		}

		const_base_pointer leftmost() const 
		{
			return this->red_black_tree_implementation.header.left; 
		}

		base_pointer& rightmost()
		{
			return this->red_black_tree_implementation.header.right;
		}

		const_base_pointer rightmost() const
		{
			return this->red_black_tree_implementation.header.right;
		}

		link_type m_begin()
		{ 
			return static_cast<link_type>(this->red_black_tree_implementation.header.parent);
		}

		const_link_type	m_begin() const
		{
			return static_cast<const_link_type>(this->red_black_tree_implementation.header.parent);
		}

		link_type m_end()
		{
			return static_cast<link_type>(&this->red_black_tree_implementation.header);
		}

		const_link_type	m_end() const
		{
			return static_cast<const_link_type>(&this->red_black_tree_implementation.header);
		}

	private:
		iterator member_insert(const_base_pointer x, const_base_pointer p, const value_type& v)
		{
			bool		insert_left = (x || p == m_end() || red_black_tree_implementation.key_compare(KeyOfValue()(v), key(p)));
			link_type	z = create_node(v);

			rb_tree_insert_and_rebalance(insert_left, z, const_cast<base_pointer>(p), this->red_black_tree_implementation.header);
			++red_black_tree_implementation.node_count;
			return iterator(z);
		}

		iterator m_insert_lower(base_pointer x, base_pointer p, const value_type& v)
		{
			bool		insert_left = (x || p == m_end() || !red_black_tree_implementation.key_compare(key(p), KeyOfValue()(v)));
			link_type	z = create_node(v);

			rb_tree_insert_and_rebalance(insert_left, z, const_cast<base_pointer>(p), this->red_black_tree_implementation.header);
			++red_black_tree_implementation.node_count;
			return iterator(z);
		}

		iterator m_insert_lower(const value_type& v)
		{
			link_type x = m_begin();
			link_type y = m_end();

			while (x)
			{
				y = x;
				x = !red_black_tree_implementation.key_compare(key(x), KeyOfValue()(v)) ? left(x) : right(x);
			}
			return m_insert_lower(x, y, v);
		}

		link_type copy(const_link_type x, link_type p)
		{
			link_type	top = clone_node(x);

			top->parent = p;

			try
			{
				if (x->right)
				{
					top->right = copy(right(x), top);
				}

				p = top;
				x = static_cast<link_type>(x->left);

				while (x != 0)
				{
					link_type y = clone_node(x);
					p->left = y;
					y->parent = p;

					if (x->right)
					{
						y->right = copy(static_cast<link_type>(x->right), y);
					}
						
					p = y;
					x = left(x);
				}
			}
			catch(...)
			{
				m_erase(top);
				throw;
			}
			return top;
		}

		void m_erase(link_type x)
		{
			while (x)
			{
				m_erase(right(x));
				link_type y = left(x);
				destroy_node(x);
				x = y;
			}
		}

		iterator m_lower_bound(link_type x, link_type y, const Key& k)
		{
			while (x)
			{
				if (!red_black_tree_implementation.key_compare(key(x), k))
				{
					y = x;
					x = left(x);
				}
				else
				{
					x = right(x);
				}
			}

			return iterator(y);
		}

		const_iterator	m_lower_bound(const_link_type x, const_link_type y, const Key& k) const
		{
			while (x)
			{
				if (!red_black_tree_implementation.key_compare(key(x), k))
				{
					y = x;
					x = left(x);
				}
				else
				{
					x = right(x);
				}
			}
			return const_iterator(y);
		}

		iterator m_upper_bound(link_type x, link_type y, const Key& k)
		{
			while (x)
			{
				if (red_black_tree_implementation.key_compare(k, key(x)))
				{
					y = x;
					x = left(x);
				}
				else
				{
					x = right(x);
				}
			}
			return iterator(y);
		}

		const_iterator	m_upper_bound(const_link_type x, const_link_type y, const Key& k) const
		{
			while (x)
			{
				if (red_black_tree_implementation.key_compare(k, key(x)))
				{
					y = x;
					x = left(x);
				}
					
				else
				{
					x = right(x);
				}
			}					
			return const_iterator(y);
		}

		void erase_aux(const_iterator position)
		{
			link_type y = static_cast<link_type>(rb_tree_rebalance_for_erase(const_cast<base_pointer>(position.node), this->red_black_tree_implementation.header));
			destroy_node(y);
			--red_black_tree_implementation.node_count;
		}

		void erase_aux(const_iterator first, const_iterator last)
		{
			if (first == begin() && last == end())
			{
				clear();
			}
			else
			{
				while (first != last)
				{
					erase(first++);
				}
			}
		}

		node_allocator& get_node_allocator()
		{
			return *static_cast<node_allocator*>(&this->red_black_tree_implementation); 
		}

		const node_allocator& get_node_allocator() const
		{
			return *static_cast<const node_allocator*>(&this->red_black_tree_implementation);
		}

		void rotate_left(rb_tree_node_base* const x, rb_tree_node_base*& root)
		{
			rb_tree_node_base* const y = x->right;

			x->right = y->left;

			if (y->left != 0)
			{
				y->left->parent = x;
			}
				
			y->parent = x->parent;

			if (x == root)
			{
				root = y;
			}
			else if (x == x->parent->left)
			{
				x->parent->left = y;
			}
			else
			{
				x->parent->right = y;
			}
				
			y->left = x;
			x->parent = y;
		}

		void rotate_right(rb_tree_node_base* const x, rb_tree_node_base*& root)
		{
			rb_tree_node_base* const y = x->left;

			x->left = y->right;

			if ( y->right != 0)
			{
				y->right->parent = x;
			}

			y->parent = x->parent;

			if (x == root)
			{
				root = y;
			}
			else if (x == x->parent->right)
			{
				x->parent->right = y;
			}
			else
			{
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		void rb_tree_insert_and_rebalance(const bool insert_left, rb_tree_node_base* x, rb_tree_node_base* p, rb_tree_node_base& header)
		{
			rb_tree_node_base *& root = header.parent;

			x->parent = p;
			x->left = 0;
			x->right = 0;
			x->color = red;

			if (insert_left)
			{
				p->left = x;

				if (p == &header)
				{
					header.parent = x;
					header.right = x;
				}
				else if (p == header.left)
				{
					header.left = x;
				}
					
			}
			else
			{
				p->right = x;

				if (p == header.right)
				{
					header.right = x;
				}
			}

			rb_tree_rebalance(x, root);
		}

		void rb_tree_rebalance(rb_tree_node_base* x, rb_tree_node_base*& root)
		{
			while (x != root  && x->parent->color == red)
			{
				rb_tree_node_base* const xpp = x->parent->parent;

				if (x->parent == xpp->left)
				{
					rb_tree_node_base* const y = xpp->right;

					if (y && y->color == red)
					{
						x->parent->color = black;
						y->color = black;
						xpp->color = red;
						x = xpp;
					}
					else
					{
						if (x == x->parent->right)
						{
							x = x->parent;
							rotate_left(x, root);
						}

						x->parent->color = black;
						xpp->color = red;
						rotate_right(xpp, root);
					}
				}
				else
				{
					rb_tree_node_base* const y = xpp->left;

					if (y && y->color == red) 
					{
						x->parent->color = black;
						y->color = black;
						xpp->color = red;
						x = xpp;
					}
					else
					{
						if (x == x->parent->left) 
						{
							x = x->parent;
							rotate_right(x, root);
						}
						x->parent->color = black;
						xpp->color = red;
						rotate_left(xpp, root);
					}
				}
			}

			root->color = black;
		}

		rb_tree_node_base* rb_tree_rebalance_for_erase(rb_tree_node_base* const z, rb_tree_node_base& header)
		{
			rb_tree_node_base *& root 		= header.parent;
			rb_tree_node_base *& leftmost 	= header.left;
			rb_tree_node_base *& rightmost 	= header.right;
			rb_tree_node_base* y 			= z;
			rb_tree_node_base* x 			= 0;
			rb_tree_node_base* x_parent 	= 0;

			if (y->left == 0)
			{
				x = y->right;
			}
			else
			{
				if (y->right == 0)
				{
					x = y->left;
				}
				else
				{
					y = y->right;

					while (y->left != 0)
					{
						y = y->left;
					}
					x = y->right;
				}
			}
			if (y != z)
			{
				z->left->parent = y; 
				y->left = z->left;
				if (y != z->right)
				{
					x_parent = y->parent;

					if (x)
					{
						x->parent = y->parent;
					}
						
					y->parent->left = x;
					y->right = z->right;
					z->right->parent = y;
				}
				else
				{
					x_parent = y;
				}
				if (root == z)
				{
					root = y;
				}
				else if (z->parent->left == z)
				{
					z->parent->left = y;
				}
				else
				{
					z->parent->right = y;	
				}
				y->parent = z->parent;
				std::swap(y->color, z->color);
				y = z;
			}
			else
			{
				x_parent = y->parent;

				if (x)
				{
					x->parent = y->parent;
				}
				if (root == z)
				{
					root = x;
				}
				else
				{
					if (z->parent->left == z)
					{
						z->parent->left = x;
					}
					else
					{
						z->parent->right = x;
					}
				}
				if (leftmost == z)
				{
					if (z->right == 0)
					{
						leftmost = z->parent;
					}
					else
					{
						leftmost = rb_tree_node_base::static_minimum(x);
					}
				}
				if (rightmost == z)
				{
					if (z->left == 0)
					{
						rightmost = z->parent;
					}
					else
					{
						rightmost = rb_tree_node_base::static_maximum(x);
					}
				}
			}

			if (y->color != red) 
			{ 
				while (x != root && (x == 0 || x->color == black))
				if (x == x_parent->left)
				{
					rb_tree_node_base* w = x_parent->right;

					if (w->color == red)
					{
						w->color = black;
						x_parent->color = red;
						rotate_left(x_parent, root);
						w = x_parent->right;
					}
					if ((w->left == 0 || w->left->color == black) && (w->right == 0 || w->right->color == black))
					{
						w->color = red;
						x = x_parent;
						x_parent = x_parent->parent;
					}
					else 
					{
						if (w->right == 0 || w->right->color == black) 
						{
							w->left->color = black;
							w->color = red;
							rotate_right(w, root);
							w = x_parent->right;
						}

						w->color = x_parent->color;
						x_parent->color = black;

						if (w->right)
						{
							w->right->color = black;
						}
						rotate_left(x_parent, root);
						break;
					}
				} 
				else
				{
					rb_tree_node_base* w = x_parent->left;

					if (w->color == red) 
					{
						w->color = black;
						x_parent->color = red;
						rotate_right(x_parent, root);
						w = x_parent->left;
					}
					if ((w->right == 0 || w->right->color == black) && (w->left == 0 || w->left->color == black)) 
					{
						w->color = red;
						x = x_parent;
						x_parent = x_parent->parent;
					}
					else 
					{
						if (w->left == 0 || w->left->color == black) 
						{
							w->right->color = black;
							w->color = red;
							rotate_left(w, root);
							w = x_parent->left;
						}

						w->color = x_parent->color;
						x_parent->color = black;

						if (w->left) 
						{
							w->left->color = black;
						}
						rotate_right(x_parent, root);
						break;
					}
				}
				if (x)
				{
					x->color = black;
				}
			}
			return y;
		}

		unsigned int rb_tree_black_count(const rb_tree_node_base* node, const rb_tree_node_base* root)
		{
			if (node == 0)
				return 0;
			unsigned int sum = 0;
			do
			{
				if (node->color == black)
					++sum;
				if (node == root)
					break;
				node = node->parent;
			} while (1);
			return sum;
		}

	public:
	
		red_black_tree() {}

		red_black_tree(const Compare& compare, const allocator_type& allocator = allocator_type()) : red_black_tree_implementation(compare, allocator) {}

		red_black_tree(const red_black_tree& x) : red_black_tree_implementation(x.red_black_tree_implementation.key_compare, x.get_node_allocator())
		{
			if (x.root())
			{
				root() = copy(x.m_begin(), m_end());
				leftmost() = minimum(root());
				rightmost() = maximum(root());
				red_black_tree_implementation.node_count = x.red_black_tree_implementation.node_count;
			}
		}

		~red_black_tree()
		{
			m_erase(m_begin());
		}

		red_black_tree& operator=(const red_black_tree& x)
		{
			if (this != &x)
			{
				clear();
				red_black_tree_implementation.key_compare = x.red_black_tree_implementation.key_compare;
				if (x.root())
				{
					root() = copy(x.m_begin(), m_end());
					leftmost() = minimum(root());
					rightmost() = maximum(root());
					red_black_tree_implementation.node_count = x.red_black_tree_implementation.node_count;
				}
			}
			return *this;
		}
	
		allocator_type get_allocator() const
		{
			return allocator_type(get_node_allocator());
		}
	
		Compare key_comp() const
		{
			return red_black_tree_implementation.key_compare;
		}

		iterator begin()
		{
			return iterator(static_cast<link_type>(this->red_black_tree_implementation.header.left));
		}

		const_iterator begin() const
		{
			return const_iterator(static_cast<link_type>(this->red_black_tree_implementation.header.left));
		}

		iterator end()
		{
			return iterator(static_cast<link_type>(&this->red_black_tree_implementation.header));
		}

		const_iterator end() const
		{
			return const_iterator(static_cast<const_link_type>(&this->red_black_tree_implementation.header));
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		bool empty() const
		{
			return red_black_tree_implementation.node_count == 0;
		}

		size_type size() const
		{
			return red_black_tree_implementation.node_count;
		}

		size_type max_size() const
		{
			return get_node_allocator().max_size();
		}

		void swap(red_black_tree& t)
		{
			if (!root())
			{
				if (t.root())
				{
					root() = t.root();
					leftmost() = t.leftmost();
					rightmost() = t.rightmost();
					root()->parent = m_end();
					
					t.root() = 0;
					t.leftmost() = t.m_end();
					t.rightmost() = t.m_end();
				}
			}
			else if (!t.root())
			{
				t.root() = root();
				t.leftmost() = leftmost();
				t.rightmost() = rightmost();
				t.root()->parent = t.m_end();

				root() = 0;
				leftmost() = m_end();
				rightmost() = m_end();
			}
			else
			{
				std::swap(root(), t.root());
				std::swap(leftmost(), t.leftmost());
				std::swap(rightmost(), t.rightmost());
				root()->parent = m_end();
				t.root()->parent = t.m_end();
			}
			std::swap(this->red_black_tree_implementation.node_count, t.red_black_tree_implementation.node_count);
			std::swap(this->red_black_tree_implementation.key_compare, t.red_black_tree_implementation.key_compare);
		}

		ft::pair<iterator, bool> insert(const value_type& v)
		{
			link_type x = m_begin();
			link_type y = m_end();
			bool compare = true;

			while (x)
			{
				y = x;
				compare = red_black_tree_implementation.key_compare(KeyOfValue()(v), key(x));
				x = compare ? left(x) : right(x);
			}

			iterator j = iterator(y);

			if (compare)
			{
				if (j == begin())
				{
					return ft::pair<iterator, bool>(member_insert(x, y, v), true);
				}
				else
				{
					--j;
				}
			}
			if (red_black_tree_implementation.key_compare(key(j.node), KeyOfValue()(v)))
			{
				return ft::pair<iterator, bool>(member_insert(x, y, v), true);
			}
			return ft::pair<iterator, bool>(j, false);
				
		}

		iterator m_insert_equal(const value_type& v)
		{
			link_type x = m_begin();
			link_type y = m_end();

			while (x)
			{
				y = x;
				x = red_black_tree_implementation.key_compare(KeyOfValue()(v), key(x)) ? left(x) : right(x);
			}
			return member_insert(x, y, v);
		}

		iterator m_insert_unique(const_iterator position, const value_type& v)
		{
			if (position.node == m_end())
			{
				if (size() > 0 && red_black_tree_implementation.key_compare(key(rightmost()), KeyOfValue()(v)))
				{
					return member_insert(0, rightmost(), v);
				}
				else
				{
					return insert(v).first;
				}
			}
			else if (red_black_tree_implementation.key_compare(KeyOfValue()(v), key(position.node)))
			{
				const_iterator before = position;

				if (position.node == leftmost())
				{
					return (member_insert(leftmost(), leftmost(), v));
				}
				else if (red_black_tree_implementation.key_compare(key((--before).node), KeyOfValue()(v)))
				{
					if (right(before.node) == 0)
					{
						return member_insert(0, before.node, v);
					}
					else
					{
						return member_insert(position.node, position.node, v);
					}
				}
				else
				{
					return insert(v).first;
				}
			}
			else if (red_black_tree_implementation.key_compare(key(position.node), KeyOfValue()(v)))
			{
				const_iterator after = position;
				if (position.node == rightmost())
				{
					return member_insert(0, rightmost(), v);
				}
				else if (red_black_tree_implementation.key_compare(KeyOfValue()(v), key((++after).node)))
				{
					if (right(position.node) == 0)
					{
						return member_insert(0, position.node, v);
					}
					else
					{
						return member_insert(after.node, after.node, v);
					}
				}
				else
				{
					return insert(v).first;
				}
			}
			else
			{
				return position.constant_cast();
			}
				
		}

		iterator m_insert_equal_(const_iterator position, const value_type& v)
		{
			if (position.node == m_end())
			{
				if (size() > 0 && !red_black_tree_implementation.initialize(KeyOfValue()(v), key(rightmost())))
				{
					return member_insert(0, rightmost(), v);
				}
				else
				{
					return m_insert_equal(v);
				}
			}
			else if (!red_black_tree_implementation.key_compare(key(position.node), KeyOfValue()(v)))
			{
				const_iterator before = position;

				if (position.node == leftmost())
				{
					return member_insert(leftmost(). leftmost(), v);
				}
				else if (!red_black_tree_implementation.key_compare(KeyOfValue()(v), key((--before).node)))
				{
					if (right(before.node) == 0)
					{
						return member_insert(0, before.node, v);
					}
					else
					{
						return member_insert(position.node, position.node, v);
					}
				}
				else
				{
					return m_insert_equal(v);
				}
			}
			else
			{
				const_iterator after = position;
				if (position.node == rightmost())
				{
					return member_insert(0, rightmost(), v);
				}
				else if (!red_black_tree_implementation.key_compare(key((++after).node), KeyOfValue()(v)))
				{
					if (right(position.node) == 0)
					{
						return member_insert(0, position.node, v);
					}
						
					else
					{
						return member_insert(after.node, after.node, v);
					}	
				}
				else
				{
					return m_insert_lower(v);
				}
			}
		}

		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
			{
				m_insert_unique(end(), *first);
			}
		} 

		template<typename InputIterator>
		void m_insert_equal(InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
			{
				m_insert_equal_(end(), *first);
			}
		}

		// erase element at position

		void erase(iterator position)
		{
			erase_aux(position);
		}

		// erase element at position

		void erase(const_iterator position)
		{
			erase_aux(position);
		}

		// erase elements with specific key

		size_type erase(const key_type& x)
		{
			ft::pair<iterator, iterator> p = equal_range(x);
			const size_type	old_size = size();
			erase(p.first, p.second);
			return old_size - size();
		}

		// Erase a range of elements

		void erase(iterator first, iterator last)
		{
			erase_aux(first, last);
		}

		// erase from first to last, but first==last is allowed

		void erase(const_iterator first, const_iterator last)
		{
			erase_aux(first, last);
		}

		// erase data from tree and delete node

		void erase(const key_type* first, const key_type* last)
		{
			while (first != last)
			{
				erase(*first++);
			}	
		}

		// clear content of the container (all elements are destroyed)

		void clear()
		{
			m_erase(m_begin());
			leftmost() = m_end();
			root() = 0;
			rightmost() = m_end();
			red_black_tree_implementation.node_count = 0;
		}

		// find operation (public member functions)

		iterator find(const key_type& k)
		{
			iterator j = m_lower_bound(m_begin(), m_end(), k);
			return (j == end()|| red_black_tree_implementation.key_compare(k, key(j.node))) ? end() : j;
		}

		// find the node with the key k

		const_iterator find(const key_type& k) const
		{
			const_iterator j = m_lower_bound(m_begin(), m_end(), k);
			return (j == end()|| red_black_tree_implementation.key_compare(k, key(j.node))) ? end() : j;
		}

		// count 

		size_type count(const key_type& k) const
		{
			ft::pair<const_iterator, const_iterator> p = equal_range(k);
			const size_type n = ft::distance(p.first, p.second);
			return n;
		}

		// lower_bound/upper_bound equal_range return the first/last position

		iterator lower_bound(const key_type& k)
		{
			return m_lower_bound(m_begin(), m_end(), k);
		}

		// const version of lower_bound

		const_iterator lower_bound(const key_type& k) const
		{
			return m_lower_bound(m_begin(), m_end(), k);
		}

		// upper_bound() returns the first node which has a key greater than k.

		iterator upper_bound(const key_type& k)
		{
			return m_upper_bound(m_begin(), m_end(), k);
		}

		// upper_bound returns a pointer to the first element that compares greater than k.

		const_iterator upper_bound(const key_type& k) const
		{
			return m_upper_bound(m_begin(), m_end(), k);
		}

		// equal range returns a range of equal elements

		ft::pair<iterator, iterator> equal_range(const key_type& k)
		{
			return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
		}

		// const version of equal_range

		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
		{
			return pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
		}

		// verify if the tree is valid 

		bool rb_verify() const
		{
			if (red_black_tree_implementation.node_count == 0 || begin() == end())
			{
				return red_black_tree_implementation.node_count == 0 && begin() == end() && this->red_black_tree_implementation.header.left == m_end() && this->red_black_tree_implementation.header.right == m_end();
			}
			
			unsigned int len = rb_tree_black_count(leftmost(), root());
			
			for (const_iterator it = begin(); it != end(); ++it)
			{
				const_link_type x = static_cast<const_link_type>(it.node);
				const_link_type L = left(x);
				const_link_type R = right(x);
				
				if (x->color == red)
				{
					if ((L && L->color == red) || (R && R->color == red))
					{
						return false;
					}		
				}
				if (L && red_black_tree_implementation.key_compare(key(x), key(L)))
				{
					return false;
				}
				if (R && red_black_tree_implementation.key_compare(key(R), key(L)))
				{
					return false;
				}
				if (!L && !R && rb_tree_black_count(x, root()) != len)
				{
					return false;
				}
			}
			if (leftmost() != rb_tree_node_base::static_minimum(root()))
			{
				return false;
			}
			if (rightmost() != rb_tree_node_base::static_maximum(root()))
			{
				return false;
			}
			return true;
		}

	protected:

		static const_reference value(const_link_type x)
		{
			return x->value_field;
		}

		static const Key& key(const_link_type x)
		{
			return KeyOfValue()(value(x));
		}

		// left most node of x subtree

		static link_type left(base_pointer x)
		{
			return static_cast<link_type>(x->left);
		}

		// right node of x

		static link_type right(base_pointer x)
		{
			return static_cast<link_type>(x->right);
		}

		// left most node of x subtree

		static const_link_type left(const_base_pointer x)
		{
			return static_cast<const_link_type>(x->left);
		}		
		
		// right node of x

		static const_link_type right(const_base_pointer x)
		{
			return static_cast<const_link_type>(x->right);
		}

		// value from a node of a const rb_tree which is read-only.

		static const_reference value(const_base_pointer x)
		{
			return static_cast<const_link_type>(x)->value_field;
		}

		static const Key& key(const_base_pointer x)
		{
			return KeyOfValue()(value(x));
		}

		// Returns the minimum node of the tree rooted at x.

		static base_pointer minimum(base_pointer x)
		{
			return rb_tree_node_base::static_minimum(x);
		}

		// maximum node in a tree rooted at x

		static base_pointer maximum(base_pointer x)
		{
			return rb_tree_node_base::static_maximum(x);
		}

		// minimum of the subtree rooted at x

		static const_base_pointer minimum(const_base_pointer x)
		{
			return rb_tree_node_base::static_minimum(x);
		}

		// maximum node in a tree rooted at x
		
		static const_base_pointer maximum(const_base_pointer x)
		{
			return rb_tree_node_base::static_maximum(x);
		}
	};

	// operator == 
	
	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	bool operator==(const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& x, const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& y)
	{
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}

	//operator < 

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	bool operator<(const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& x, const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	// operator !=

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	inline bool	operator!=(const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& x, const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& y)
	{
		return !(x == y);
	}

	// operator > 

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	inline bool	operator>(const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& x, const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& y)
	{
		return y < x;
	}

	// operator <=

	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	inline bool	operator<=(const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& x, const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& y)
	{
		return !(y < x);
	}

	// operator >=
	template<typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	inline bool	operator>=(const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& x, const red_black_tree<Key, Value, KeyOfValue, Compare, Alloc>& y)
	{
		return !(x < y);
	}
}