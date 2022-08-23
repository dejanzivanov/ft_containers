#pragma once

#include <memory>
#include <iterator>
#include <exception>
#include<limits>

#include <bits/stl_iterator_base_types.h>

// Simple container for singly-linked lists.
template<typename T, typename Alloc = std::allocator<T> >
class slist
{
	// Private type for a link (node) in the list.
	template<typename U>
	struct link
	{
		link* next;
		U value;
	};
	typedef link<T> link_type;
public:
	typedef typename Alloc::reference reference;
	typedef typename Alloc::const_reference const_reference;
	typedef typename Alloc::pointer pointer;
	typedef typename Alloc::const_pointer const_pointer;
	typedef Alloc allocator_type;
	typedef T value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	class iterator; // See the section "Iterators" later in this chapter for
	class const_iterator; // the iterators.
	slist(const slist& that);
	slist(const Alloc& alloc = Alloc( ));
	slist(size_type n, const T& x, const Alloc& alloc=Alloc( ));
	template<typename InputIter>
	slist(InputIter first, InputIter last,
	const Alloc& alloc = Alloc( ));
	~slist( ) { clear( ); }
	slist& operator=(const slist& that);
	allocator_type get_allocator( ) const
	{
		return alloc_;
	}
	iterator begin( )
	{
		return iterator(0, head_);
	}
	const_iterator begin( ) const
	{
		return const_iterator(0, head_);
	}
	iterator end( )
	{
		return iterator(0, 0); 
	}
	const_iterator end( ) const
	{
		return const_iterator(0, 0); 
	}
	void pop_front( )
	{
		erase(begin( )); 
	}
	void push_front(const T& x)
	{
		insert(begin( ), x); 
	}
	T front( ) const
	{
		return head_->value; 
	}
	T& front( )
	{
		return head_->value; 
	}
	iterator insert(iterator p, const T& x);
	void insert(iterator p, size_type n, const T& x);
	template<typename InputIter>
	void insert(iterator p, InputIter first, InputIter last);
	iterator erase(iterator p);
	iterator erase(iterator first, iterator last);
	void clear( )
	{
		erase(begin( ), end( ));
	}
	bool empty( ) const
	{
		return size( ) == 0;
	}
	size_type max_size( ) const
	{
		return std::numeric_limits<difference_type>::max( );
	}
	void resize(size_type sz, const T& x = T( ));
	size_type size( ) const
	{
		return count_;
	}
	void swap(slist& that);
private:
	typedef typename allocator_type::template rebind<link_type>::other link_allocator_type;
	link_type* newitem(const T& x, link_type* next = 0);
	void delitem(link_type* item);
	template<typename InputIter>
	void construct(InputIter first, InputIter last, is_integer_tag);
	template<typename InputIter>
	void construct(InputIter first, InputIter last, is_not_integer_tag);
	link_type* head_;
	link_type* tail_;
	size_t count_;
	allocator_type alloc_;
	link_allocator_type linkalloc_;
};


// Constructor. If InputIter is an integral type, the standard requires the
// constructor to interpret first and last as a count and value, and perform the
// slist(size_type, T) constructor. Use the is_integer trait to dispatch to the
// appropriate construct function, which does the real work.
template<typename T, typename A>
template<typename InputIter>
slist<T,A>::slist(InputIter first, InputIter last,
const A& alloc)
: alloc_(alloc), linkalloc_(link_allocator_type( )),
head_(0), tail_(0), count_(0)
{
construct(first, last, is_integer<InputIter>::tag( ));
}
template<typename T, typename A>
template<typename InputIter>
void slist<T,A>::construct(InputIter first, InputIter last, is_integer_tag)
{
insert(begin( ), static_cast<size_type>(first),
static_cast<T>(last));
}
template<typename T, typename A>
template<typename InputIter>
void slist<T,A>::construct(InputIter first, InputIter last, is_not_integer_tag)
{
insert(begin( ), first, last);
}
// Private function to allocate a new link node.
template<typename T, typename A>
typename slist<T,A>::link_type*
slist<T,A>::newitem(const T& x, link_type* next)
{
link_type* item = linkalloc_.allocate(1);
item->next = next;
alloc_.construct(&item->value, x);
return item;
}
// Private function to release a link node.
template<typename T, typename A>
void slist<T,A>::delitem(link_type* item)
{
alloc_.destroy(&item->value);
linkalloc_.deallocate(item, 1);
}
// Basic insertion function. All insertions eventually find their way here.
// Inserting at the head of the list (p == begin( )) must set the head_ member.
// Inserting at the end of the list (p == end( )) means appending to the list,
// which updates the tail_'s next member, and then sets tail_. Anywhere else in
// the list requires updating p.prev_->next. Note that inserting into an empty
// list looks like inserting at end( ). Return an iterator that points to the
// newly inserted node.
template<typename T, typename A>
typename slist<T,A>::iterator
slist<T,A>::insert(iterator p, const T& x)
{
// Allocate the new link before changing any pointers. If newitem throws an
// exception, the list is not affected.
link_type* item = newitem(x, p.node_);
if (p.node_ == 0) {
p.prev_ = tail_;
// At end
if (tail_ == 0)
head_ = tail_ = item; // Empty list
else {
tail_->next = item;
tail_ = item;
}
}
else if (p.prev_ == 0)
head_ = item; // New head of list
else
p.prev_->next = item;
p.node_ = item;
++count_;
return p;
}
// Erase the item at p. All erasures come here eventually. If erasing begin( ),
// update head_. If erasing the last item in the list, update tail_. Update the
// iterator to point to the node after the one being deleted.
template<typename T, typename A>
typename slist<T,A>::iterator slist<T,A>::erase(iterator p)
{
link_type* item = p.node_;
p.node_ = item->next;
if (p.prev_ == 0)
head_ = item->next;
else
p.prev_->next = item->next;
if (item->next == 0)
tail_ = p.prev_;
--count_;
delitem(item);
return p;
}
// Comparison functions are straightforward.
template<typename T>
bool operator==(const slist<T>& a, const slist<T>& b)
{
return a.size( ) == b.size( ) &&
std::equal(a.begin(), a.end( ), b.begin( ));
}