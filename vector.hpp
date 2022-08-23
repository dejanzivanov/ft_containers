#pragma once

#include <memory>
#include "iterator.hpp"
#include <exception>
#include <limits>
#include "utils.hpp"
#include <iostream>
#include <stdexcept>

#define VECTOR_COMMENTS 0

namespace ft
{
	template<typename T, typename Allocator = std::allocator<T> >
	// typedef typename std::allocator_traits<A>::template rebind<T> allocator;

	struct vectorBase
	{
		// A allocator;
		typedef typename Allocator::template rebind<T>::other allocator;
		typedef typename Allocator::pointer pointer;
		
		struct vector_implementation_data : public allocator
		{
			pointer start;
			pointer finish;
			pointer endOfStorage;

			vector_implementation_data() : start(), finish(), endOfStorage() {}
			vector_implementation_data(allocator const& a) throw() :  allocator(a) , start(), finish(), endOfStorage() { }
		};

		// pointer data_allocation(size_t n)
		// {
		// 	if (n != 0)
		// 		// return vector_implementation_data.allocate(n); // -- reminder of reality 
		// 		return vector_implementation_data.allocate(n); // -- reminder of reality 
		// 	else
		// 		return pointer();
		// }

		pointer data_allocation(size_t __n)
		{
		return __n != 0 ? get_allocator().allocate(__n) : pointer();
		}

		void data_deallocation(pointer p, size_t n)
		{
			if (p)
				get_allocator().deallocate(p, n);
		}

		void create_storage(size_t n)
		{
			this->data_implement.start = this->data_allocation(n);
			this->data_implement.finish = this->data_implement.start;
			this->data_implement.endOfStorage = data_implement.start + n;
		}


		vectorBase() : data_implement() { }
		vectorBase(const Allocator& a) throw() : data_implement(a) { }
		vectorBase(size_t n): data_implement() { create_storage(n); } 
		// vectorBase(const Allocator& a, typename Allocator::size_type n)
		// 	: data_implement()  {}
		vectorBase(const Allocator& a, typename Allocator::size_type n)
			: data_implement(a) { create_storage(n); }
		
		~vectorBase()
		{
			if (VECTOR_COMMENTS)
				std::cout << "Base destructor called on " << this << " with " << this->data_implement.start << " to " << this->data_implement.finish << std::endl;
			// get_allocattor().dealocate();
			data_deallocation(data_implement.start, data_implement.finish - data_implement.start);
			
			// allocator.deallocate(data_implement.start, data_implement.finish - data_implement.start);
		}

		allocator get_allocator() const throw()
		{
			return allocator(alloc_return()) ; 
		}

		allocator& alloc_return() throw()
		{
			return this->data_implement;
		}

		const Allocator& alloc_return() const 
		{
			return this->data_implement;
		}

		public:
			vector_implementation_data data_implement; // - if something doesnt work check here

	};


	// used for operations in vector
 	template<typename T>
	void swap(vectorBase<T>& a, vectorBase<T>& b)
	{
		if (VECTOR_COMMENTS)
			std::cout << "vectorBase swap() specialization called on " << &a << " and " << &b << std::endl;
		// std::swap(a.allocator, b.allocator);
		std::swap(a.data_implement.start, b.data_implement.start);
		std::swap(a.data_implement.finish, b.data_implement.finish);
		std::swap(a.data_implement.endOfStorage, b.data_implement.endOfStorage);
	};

	template<typename T, typename Allocator = std::allocator<T> >
	class vector: private vectorBase<T, Allocator>
	{
		void destroy_elements()
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector destroy_elements()" << std::endl;
			for (T* p = this->data_implement.start; p != this->data_implement.finish; ++p)
			{
				if (VECTOR_COMMENTS)
					std::cout << p << std::endl;
				p->~T();
			}
		}
	public:
		
		using typename vectorBase<T, Allocator>::vector_implementation_data;
		using vectorBase<T, Allocator>::get_allocator;


		/*normal iterator is used because is needed for vector container*/

		typedef typename Allocator::value_type											value_type; // T would also be possible
		typedef typename Allocator::reference											reference;
		typedef typename Allocator::const_reference										const_reference;
		typedef typename Allocator::pointer												pointer;
		typedef typename Allocator::const_pointer										const_pointer;
		typedef typename ft::__normal_iterator<pointer, vector>					iterator;
		// typedef typename __gnu_cxx::__normal_iterator<pointer, vector>					iterator;
		typedef typename ft::__normal_iterator<const_pointer, vector>			const_iterator;
		// typedef typename __gnu_cxx::__normal_iterator<const_pointer, vector>			const_iterator;
		typedef ft::reverse_iterator<iterator>											reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;
		typedef typename Allocator::difference_type										difference_type;
		typedef typename Allocator::size_type											size_type;
		

		// vector() : vectorBase<T, Allocator>()
		// {
		// 	if (VECTOR_COMMENTS)
		// 		std::cout << "default constructor called" << std::endl;
			
		// 	//this one can be deleted maybe
		// }


		//1)
		explicit vector (const Allocator& alloc = Allocator()) //reference pages 
			: vectorBase<T, Allocator>(alloc, 0)
		{
			if (VECTOR_COMMENTS)
				std::cout << "real default constructor per reference prototype page called" << std::endl;
		};

		//2)
		explicit vector (size_type n, const value_type& val = value_type(), const Allocator& alloc = Allocator())
			:vectorBase<T, Allocator>(alloc, n)
		{
			if (VECTOR_COMMENTS)
				std::cout << "fill constructor and n is: " << n << " and val is: " << val << std::endl;
			std::uninitialized_fill(this->data_implement.start, this->data_implement.start + n, val);
			this->data_implement.finish = this->data_implement.start + n;
		};

		//3) todo
		// vector (InputIterator first, InputIterator last, const Allocator& alloc = Allocator())

		// template <class InputIterator>
		// vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value),InputIterator>::type first, InputIterator last, const Allocator& alloc = Allocator())
		/*maybe default ^*/
		
		// vector( !(ft::is_integral<InputIterator>::value) first, InputIterator last, const Allocator& alloc = Allocator())
		
		
		// template <class InputIterator>
		// vector(typename ft::enable_if<(typename InputIterator::iterator_category == std::iterator_traits::input_iterator_tag), InputIterator> first, InputIterator last, const Allocator& alloc = Allocator())
		template <class InputIterator>
		vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value),InputIterator>::type first, InputIterator last, const Allocator& alloc = Allocator())
		: vectorBase<T, Allocator>(alloc, last - first)
		{	//range constructor
			if(VECTOR_COMMENTS == 1)
				std::cout << "Range constructor called" << std::endl;
			std::uninitialized_copy(first, last, this->data_implement.start);
			this->data_implement.finish += ft::distance(first, last); 
		}


		// template <class InputIterator>
		// // vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		// vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value),InputIterator>::type first, InputIterator last, const Allocator& alloc = Allocator())
		// : vectorBase<T, Allocator>(alloc, last - first)
		// {	//range constructor
		// 	if(VECTOR_COMMENTS == 1)
		// 		std::cout << "Range constructor called" << std::endl;
		// 	// std::uninitialized_copy(first, last, this->data_implement.start);

		// 	size_type n = std::distance(first, last);
		// 	this->data_implement.start = this->get_allocator().allocate(n);
		// 	this->data_implement.endOfStorage = this->data_implement.start + n;
		// 	this->data_implement.finish = this->data_implement.start;
			
		// 	while(n--)
		// 	{
		// 		this->get_allocator().construct(this->data_implement.finish++, *first++);
		// 	}
			
		// }

		//

		//4)
		vector (const vector& x)
			:vectorBase<T, Allocator>(x.get_allocator(), x.capacity())
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector copy constructor called from " << &x << " on " << this << std::endl;
			std::uninitialized_copy(x.data_implement.start, x.data_implement.finish, this->data_implement.start);
			this->data_implement.finish = this->data_implement.start + x.size();
		};


		~vector()
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector destructor called on " << this << std::endl;
			destroy_elements();
		};

		vector& operator=(const vector& rhs)
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector copy assignement operator called from " << &rhs << " on " << this << std::endl;
			// create temporary copy, but not with copy constructor, as this would differ in the capacity of vector compared to original container
			if (this == &rhs)
				return *this;
			//vectorBase<T, Allocator> temp(allocator, this->capacity() < rhs.size() ? rhs.size() : this->capacity()); // allocate memory
			vectorBase<T, Allocator> temp(this->capacity() < rhs.size() ? rhs.size() : this->capacity());
			temp.data_implement.finish = temp.data_implement.start;
			std::uninitialized_copy(rhs.data_implement.start, rhs.data_implement.finish, temp.data_implement.start); // copy the elements of rhs into a temporary 
			temp.data_implement.finish = temp.data_implement.start + rhs.size();
			ft::swap(*this, temp);
			return(*this);
		}

		size_type size() const throw()
		{
			return (this->data_implement.finish - this->data_implement.start);
		}

		size_type max_size() const throw()
		{
			//return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			return (get_allocator().max_size());
		}

		bool empty() const throw()
		{
			return (this->data_implement.start == this->data_implement.finish);
		}

/* 		void resize (size_type n, value_type val = value_type())
		{
			if (n < size())
			{
				for (T* p = vector_implementation_data->start + n; p != vector_implementation_data->finish; ++p)
				{
					p->~T();
				}
			}
			else if (n > size())
			{
				for (T* p = vector_implementation_data->start + n; p != vector_implementation_data->finish; ++p)
				{
					push_back(val);
				}
			}
			vector_implementation_data->finish = vector_implementation_data->start + n;
		} */

		// void resize(size_type n, value_type val = value_type())
		// {
		// 	// if (n > size())
		// 	// {
		// 	// 	_M_fill_insert(end(), __new_size - size(), __x);
		// 	// }
		// 	// else if (__new_size < size())
		// 	// {
				
		// 	// _M_erase_at_end(this->_M_impl._M_start + __new_size);
		// 	// }

		// 	if (n > this->max_size())
		// 	{
		// 		throw std::out_of_range("ft::vector");
		// 	}

		// 	size_type prev_size = this->size();

		// 	if (prev_size > n)
		// 	{
		// 		while (prev_size-- > n)
		// 		{
		// 			this->get_allocator().destroy(--this->data_implement.endOfStorage);
		// 		}
		// 		return;
		// 	}
		// 	this->insert(this->end(), n - prev_size, val);

		// }

		//single element (1)	
		iterator insert (iterator position, const value_type& val)
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector single element insert() called" << std::endl;
			if (size() == 0)
				push_back(val);
			else if (this->data_implement.finish == this->data_implement.finish)
			{
				std::cout << "Test 0" << std::endl;
				int temp = *position;
				*position = val;
				push_back(temp);
			}
			else if (capacity() - size() >= 1)
			{
				std::cout << "Test 1" << std::endl;
				*(position + 1) = *position;
				*position = val;
			}
			else
			{
				std::cout << "Test 2" << std::endl;
				//vectorBase<T, Allocator> a(allocator, this->size() ? 2 * this->size() : 1);
				vector<T, Allocator> a(this->size() ? 2 * this->size() : 1);
				a.data_implement.finish = a.data_implement.start;
				std::uninitialized_copy(this->data_implement.start, this->data_implement.finish, a.data_implement.start + 1);
				a.data_implement.finish += this->size();
				new (a.data_implement.start) T(val);
				destroy_elements();
				ft::swap(a, *this);
			}
			return (this->begin());
		};
		//fill (2)	
		// void insert (iterator position, size_type n, const value_type& val)
		// {

		// };

		//range (3)	
		
		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last)
		// {

		// };

		size_type capacity() const throw()
		{
			return (this->data_implement.endOfStorage - this->data_implement.start);
		}

		iterator begin()
		{
			return (iterator(this->data_implement.start));
		}

		const_iterator begin() const
		{
			return (const_iterator(this->data_implement.start));
		}

		reverse_iterator rbegin() throw()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const throw()
		{
			return const_reverse_iterator(end());
		}

		iterator end()
		{
			return (iterator(this->data_implement.finish));
		}

		const_iterator end() const
		{
			return (const_iterator(this->data_implement.finish));
		}

		reverse_iterator rend() throw()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const throw()
		{ 
			return const_reverse_iterator(begin());
		}

		T& operator[] (size_type i)
		{
			if (this->data_implement.start)
				return this->data_implement.start[i];
			return this->data_implement.start[i];//adjust
		}

		const_reference operator[] (size_type i) const
		{
			if (this->data_implement.start)
				return this->data_implement.start[i];
			return this->data_implement.start[i];//adjust
		}

		//explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())

		void push_back(const T& x)
		{	
			if (VECTOR_COMMENTS == 1)
				std::cout << "Vector push_back() called" << std::endl;
			if (this->data_implement.finish == this->data_implement.endOfStorage)
			{
				vectorBase<T, Allocator> a(this->size() ? 2 * this->size() : 1);
				a.data_implement.finish = a.data_implement.start;
				std::uninitialized_copy(this->data_implement.start, this->data_implement.finish, a.data_implement.start);
				a.data_implement.finish += this->size();
				new (a.data_implement.finish) T(x);
				++a.data_implement.finish;
				ft::swap(a, *this);
				return;
			}

			new (this->data_implement.finish) T(x);
			++(this->data_implement.finish);
		}

		void reserve(size_type n)
		{
			if (n > max_size())
				throw std::runtime_error("vector::reserve");
			if (capacity() < n)
			{
				//realocation
				vectorBase<T, Allocator> temp(n);
				temp.data_implement.finish = temp.data_implement.start;
				std::uninitialized_copy(this->data_implement.start, this->data_implement.finish, temp.data_implement.start); // copy the elements of rhs into a temporary 
				temp.data_implement.finish += this->size();
				ft::swap(*this, temp);
			}
		}

		reference front() throw()
		{
			return *begin();
		}

		const_reference front() const throw() 
		{
			return *begin();
		}

		reference back() throw()
		{
			return *(end() - 1);
		}

		const_reference back() const throw() 
		{
			return *(end() - 1);
		}

		reference at(size_type n)
		{
			if(n < 0 || n >= this->size())
				throw std::out_of_range("vector::at out of range");
			return (*this)[n];
     	}

		const_reference at(size_type n) const
		{	
			if(n < 0 || n >= this->size())
				throw std::out_of_range("vector::const_reference at out of range");
			return (*this)[n];
		}

		void pop_back()
		{
			this->get_allocator().destroy(&this->back());
			--this->data_implement.finish;
		}

		void clear()
		{
			vector<T>().swap(*this);
		}

		iterator erase (iterator position)
		{
			erase_handler(1, position);
			return (this->begin());
		}

		iterator erase (iterator first, iterator last)
		{
			size_t distance = ft::distance(first, last);
			erase_handler(distance, first);
			return (iterator(first));
		}

		void erase_handler(size_t distance, iterator start)
		{
			for (size_t i = 0; i < distance; i++)
			{
				start = start + i + 1;
			}

			// for (iterator it = this->end() - distance; it < this->end(); it++)
			for (size_t i = 0; i < distance; i++)
			{
				this->pop_back();
			}
			// this->data_implement.finish -= distance + 1;

		}

		

		/** REALOC START**/



	// template<typename _Tp, typename _Alloc>
    // void vector<_Tp, _Alloc>::_M_realloc_insert(iterator position, const _Tp& __x)
    // {
    //   const size_type __len = _M_check_len(size_type(1), "vector::_M_realloc_insert");
    //   pointer __old_start = this->data_implement.start;
    //   pointer __old_finish = this->data_implement.finish;
    //   const size_type __elems_before = position - begin();
    //   pointer __new_start(this->data_allocation(__len));
    //   pointer __new_finish(__new_start);
    //   __try
	// {

	//   _Alloc_traits::construct(this->data_implement, __new_start + __elems_before, __x);
	//   __new_finish = pointer();

 
	//       __new_finish = std::__uninitialized_move_if_noexcept_a(__old_start, __position.base(),
	// 	  __new_start, get_allocator());

	//       ++__new_finish;

	//       __new_finish
	// 	= std::__uninitialized_move_if_noexcept_a
	// 	(__position.base(), __old_finish,
	// 	 __new_finish, get_allocator());
	    
	// }
    //   __catch(...)
	// {
	//   if (!__new_finish)
	//     _Alloc_traits::destroy(this->_M_impl,
	// 			   __new_start + __elems_before);
	//   else
	//     std::_Destroy(__new_start, __new_finish, _M_get_Tp_allocator());
	//   _M_deallocate(__new_start, __len);
	//   __throw_exception_again;
	// }
	// 	#if __cplusplus >= 201103L
	// 		if _GLIBCXX17_CONSTEXPR (!_S_use_relocate())
	// 	#endif
	// std::_Destroy(__old_start, __old_finish, _M_get_Tp_allocator());
    //   _GLIBCXX_ASAN_ANNOTATE_REINIT;
    //   _M_deallocate(__old_start,
	// 	    this->_M_impl._M_end_of_storage - __old_start);
    //   this->_M_impl._M_start = __new_start;
    //   this->_M_impl._M_finish = __new_finish;
    //   this->_M_impl._M_end_of_storage = __new_start + __len;
    // }

	// 	/** REALOC END**/

	// 	/* Realoc helper functions */
	//       size_type _M_check_len(size_type __n, const char* __s) const
    //   {
	// 	if (max_size() - size() < __n)
	// 	__throw_length_error(__N(__s));

	// 	const size_type __len = size() + std::max(size(), __n);
	// 	return (__len < size() || __len > max_size()) ? max_size() : __len;
    //   }





	// template<typename _Alloc>
    // void vector<bool, _Alloc>::_M_fill_insert(iterator __position, size_type __n, bool __x)
    // {
	// 	if (__n == 0)
	// 		return;
	// 	if (capacity() - size() >= __n)
	// 	{
	// 		// std::copy_backward(__position, end(), this->_M_impl._M_finish + difference_type(__n));
	// 		std::copy_backward(__position, end(), this->da._M_finish + difference_type(__n));
	// 		std::fill(__position, __position + difference_type(__n), __x);
	// 		this->_M_impl._M_finish += difference_type(__n);
	// 	}
	// 	else
	// 	{
	// 		const size_type __len = _M_check_len(__n, "vector<bool>::_M_fill_insert");
	// 		_Bit_pointer __q = this->_M_allocate(__len);
	// 		iterator __start(std::__addressof(*__q), 0);
	// 		iterator __i = _M_copy_aligned(begin(), __position, __start);
	// 		std::fill(__i, __i + difference_type(__n), __x);
	// 		iterator __finish = std::copy(__position, end(),
	// 						__i + difference_type(__n));
	// 		this->_M_deallocate();
	// 		this->_M_impl._M_end_of_storage = __q + _S_nword(__len);
	// 		this->_M_impl._M_start = __start;
	// 		this->_M_impl._M_finish = __finish;
	// 	}
    // }

	// size_type _M_check_len(size_type __n, const char* __s) const
	// {
	// 	if (max_size() - size() < __n)
	// 	__throw_length_error(__N(__s));

	// 	const size_type __len = size() + std::max(size(), __n);
	// 	return (__len < size() || __len > max_size()) ? max_size() : __len;
	// }
	
     









		void swap(vector& x)
		{
			if (VECTOR_COMMENTS)
				// std::cout << "vector swap() member function called on " << this << " and " << &x << std::endl;
				std::cout << "vector swap() member function called" << std::endl;
				// std::swap(a.allocator, b.allocator);
			std::swap(this->data_implement.start, x.data_implement.start);
			std::swap(this->data_implement.finish, x.data_implement.finish);
			std::swap(this->data_implement.endOfStorage, x.data_implement.endOfStorage);
		}
	};

	// used in main when swap(a,b) is called on vectors
	template<typename T>
	void swap(vector<T>& a, vector<T>& b)
	{
		if (VECTOR_COMMENTS)
			std::cout << "vector swap() specialization called on " << &a << " and " << &b << std::endl;
		a.swap(b);
	};

	/* OVERLOADS */

	template<typename _Tp, typename _Alloc>
	inline bool operator==(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    {
		return (__x.size() == __y.size() && std::equal(__x.begin(), __x.end(), __y.begin()));
	}

	template<typename _Tp, typename _Alloc>
    inline bool operator<(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    {
		return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end()); 		
	}

	template<typename _Tp, typename _Alloc>
    inline bool operator!=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { 
		return !(__x == __y);
	}

	template<typename _Tp, typename _Alloc>
    inline bool operator>(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    {
		return __y < __x;
	}

	template<typename _Tp, typename _Alloc>
    inline bool operator<=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    {
		return !(__y < __x);
	}

	template<typename _Tp, typename _Alloc>
    inline bool operator>=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    {
		return !(__x < __y);
	}


	/* HANDLERS */

	
	
}