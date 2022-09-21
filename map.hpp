// red black tree algorithm for map container in c++:

// https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/

// https://www.geeksforgeeks.org/red-black-tree-set-2-insert/

// https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/

// https://www.geeksforgeeks.org/red-black-tree-set-4-delete-3/

// https://www.geeksforgeeks.org/red-black-tree-set-5-delete-4/

// https://www.geeksforgeeks.org/red-black-tree-set-6-insert-2/

// https://www.geeksforgeeks.org/red-black-tree-set-7-delete/

// https://www.geeksforgeeks.org/red-black-tree-set-8-deletion/

// https://www.geeksforgeeks.org/red-black-tree-set-9-range-minimum-query/

// https://www.geeksforgeeks.org/red-black-tree-set-10-range-maximum-query/

// https://www.geeksforgeeks.org/red-black-tree-set-11-range-sum-query/

// https://www.geeksforgeeks.org/red-black-tree-set-12-implementation-of-delete-function/

// https://www.geeksforgeeks.org/red-black-tree-set-13-delete-1/

// https://www.geeksforgeeks.org/red-black-tree-set-14-2-3-tree-conversion/

// https://www.geeksforgeeks.org/red-black-tree-set-15-2-3-tree-to-red-black-tree/

// https://www.geeksforgeeks.org/red-black-tree-set-16-2-3-tree-insertion/

// https://www.geeksforgeeks.org/red-black-tree-set-17-2-3-tree-deletion/

// https://www.geeksforgeeks.org/red-black-tree-set-18-2-3-tree-to-red-black-tree-conversion/

// https://www.geeksforgeeks.org/red-black-tree-set-19-range-minimum-query/

// https://www.geeksforgeeks.org/red-black-tree-set-20-range-maximum-query/

// https://www.geeksforgeeks.org/red-black-tree-set-21-range-sum-query/

// https://www.geeksforgeeks.org/red-black-tree-set-22-implementation-of-delete-function/

// https://www.geeksforgeeks.org/red-black-tree-set-23-delete-1/

// https://www.geeksforgeeks.org/red-black-tree-set-24-2-3-tree-conversion/

// https://www.geeksforgeeks.org/red-black-tree-set-25-2-3-tree-to-red-black-tree/	

#include "utils.hpp"
#include "iterator.hpp"
#include "rb_tree.hpp"
#include <functional>
#include <stdexcept>

namespace ft
{

	//map container in c++98 standard

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key 												key_type;
		typedef T 													mapped_type;
		typedef typename ft::pair<const key_type, mapped_type> 		value_type;
		typedef Compare												key_compare;
		typedef Alloc												allocator_type;
		typedef typename Alloc::reference 							reference;
		typedef typename Alloc::const_reference						const_reference;
		typedef typename Alloc::pointer								pointer;
		typedef typename Alloc::const_pointer						const_pointer;
	protected:
		typedef ft::red_black_tree<key_type, value_type,	ft::_Select1st<value_type>, key_compare, allocator_type> rep_type;
		rep_type rbt_tree;
	public:
		typedef typename rep_type::iterator					iterator;
		typedef typename rep_type::const_iterator			const_iterator;
		typedef typename rep_type::reverse_iterator			reverse_iterator;
		typedef typename rep_type::const_reverse_iterator 	const_reverse_iterator;
		typedef typename rep_type::size_type 				size_type;
		typedef typename rep_type::difference_type 			difference_type;
		
		//constructors

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : rbt_tree(comp, alloc)
		{
			(void)comp;
			(void)alloc;
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : rbt_tree()
		{
			(void)comp;
			(void)alloc;
			rbt_tree.insert(first, last);
		}

		map(const map& x) : rbt_tree(x.rbt_tree) { }

		//destructor
		~map() { }

		//operator=

		map& operator=(const map& x)
		{
			rbt_tree = x.rbt_tree;
			return *this;
		}

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map<Key, T, Compare, Alloc>;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) { }

			public:
				bool operator()(const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

		//iterators

		iterator begin() 
		{
			return rbt_tree.begin();
		}

		const_iterator begin() const
		{
			return rbt_tree.begin();
		}

		iterator end()
		{
			return rbt_tree.end();
		}

		const_iterator end() const
		{
			return rbt_tree.end();
		}

		reverse_iterator rbegin()
		{
			return rbt_tree.rbegin();
		}

		const_reverse_iterator rbegin() const
		{
			return rbt_tree.rbegin();
		}

		reverse_iterator rend()
		{
			return rbt_tree.rend();
		}

		const_reverse_iterator rend() const
		{
			return rbt_tree.rend();
		}

		//capacity

		bool empty() const
		{
			return rbt_tree.empty();
		}

		size_type size() const
		{
			return rbt_tree.size();
		}

		size_type max_size() const
		{
			return rbt_tree.max_size();
		}

		//element access

		mapped_type& operator[](const key_type& k)
		{
			return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
		}

		//at

		mapped_type& at(const key_type& k)
		{
			iterator it = rbt_tree.find(k);
			if (it == rbt_tree.end())
			{
				throw std::out_of_range("map::at");
			}
				
			return (*it).second;
		}

		const mapped_type& at(const key_type& k) const
		{
			const_iterator it = rbt_tree.find(k);
			if (it == rbt_tree.end())
				throw std::out_of_range("map::at");
			return (*it).second;
		}

		//modifiers

		ft::pair<iterator, bool> insert(const value_type& val)
		{
			return rbt_tree.insert(val);
		}

		iterator insert(iterator position, const value_type& val)
		{
			return rbt_tree.m_insert_unique(position, val);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			rbt_tree.insert(first, last);
		}

		void erase(iterator position)
		{
			rbt_tree.erase(position);
		}

		size_type erase(const key_type& k)
		{
			return rbt_tree.erase(k);
		}

		void erase(iterator first, iterator second)
		{
			rbt_tree.erase(first, second);
		}

		void swap(map& x)
		{
			rbt_tree.swap(x.rbt_tree);
		}

		void clear()
		{
			rbt_tree.clear();
		}

		//observers

		key_compare key_comp() const
		{
			return rbt_tree.key_comp();
		}

		value_compare value_comp() const
		{
			return value_compare(rbt_tree.key_comp());
		}

		//operations

		iterator find(const key_type& k)
		{
			return rbt_tree.find(k);
		}

		const_iterator find(const key_type& k) const
		{
			return rbt_tree.find(k);
		}

		size_type count(const key_type& k) const
		{
			return rbt_tree.find(k) == rbt_tree.end() ? 0 : 1;
		}

		iterator lower_bound(const key_type& k)
		{
			return rbt_tree.lower_bound(k);
		}

		const_iterator lower_bound(const key_type& k) const
		{
			return rbt_tree.lower_bound(k);
		}

		iterator upper_bound(const key_type& k)
		{
			return rbt_tree.upper_bound(k);
		}

		const_iterator upper_bound(const key_type& k) const
		{
			return rbt_tree.upper_bound(k);
		}

		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
		{
			return rbt_tree.equal_range(k);
		}

		ft::pair<iterator, iterator> equal_range(const key_type& k)
		{
			return rbt_tree.equal_range(k);
		}

		//allocator

		allocator_type get_allocator() const
		{
			return rbt_tree.get_allocator();
		}

		//non-member functions

		template<typename K1, typename T1, typename Compare1, typename Alloc1>
		friend bool operator==(const map<K1, T1, Compare1, Alloc1>& lhs, const map<K1, T1, Compare1, Alloc1>&);

		template<typename K1, typename T1, typename Compare1, typename Alloc1>
		friend bool operator<(const map<K1, T1, Compare1, Alloc1>& lhs, const map<K1, T1, Compare1, Alloc1>&);

	};

	//non-member functions

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return lhs.rbt_tree == rhs.rbt_tree;
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return lhs.rbt_tree < rhs.rbt_tree;
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

}