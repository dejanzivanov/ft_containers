#pragma once

#include <memory>
#include <iterator>
#include <exception>
#include<limits>
#include "utils.hpp"

#define VECTOR_COMMENTS 1

namespace ft
{
	template<typename T, typename Allocator = std::allocator<T> >

	// typedef typename std::allocator_traits<A>::template rebind<T> allocator;

	
	struct vectorBase
	{
		// A allocator;
		


		typedef typename Allocator::template rebind<T>::other allocator;
		typedef typename Allocator::pointer pointer;

		struct vector_implementation_data : allocator
		{
			T* start;
			T* finish;
			T* endOfStorage;

			vector_implementation_data() : start(), finish(), endOfStorage() {}
			vector_implementation_data(allocator const& a) :  allocator(a) , start(), finish(), endOfStorage() { }
		};

		pointer data_allocation(size_t n)
		{
			typedef std::__alloc_traits<allocator> _Tr;
			return __n != 0 ? _Tr::allocate(vector_implementation_data, n) : pointer();
		}

		create_storage(size_t n)
		{
			this->vector_implementation_data.start = this->data_allocation(n);
			this->vector_implementation_data.finish = this->vector_implementation_data.start;
			this->vector_implementation_data.endOfStorage = this->vector_implementation_data.start + n;
		}


		vectorBase() { }
		vectorBase(const Allocator& a) throw() : vector_implementation_data(__a) { }
		vectorBase(size_t n): vector_implementation_data() { _M_create_storage(__n); } 
		// 2
		// 3
		// 4
		// 5
		// 6
		
		// std::_Alloc_traits<Allocator, T>::propagate_on_container_move_assignment::value_type propagate_on_container_move_assignment;

		vectorBase(const Allocator& a, typename Allocator::size_type n)
			: data_implement()  {}
		
		~vectorBase()
		{
			if (VECTOR_COMMENTS)
				std::cout << "Base destructor called on " << this << " with " << this->vector_implementation_data->start << " to " << this->vector_implementation_data->finish << std::endl;
			allocator.deallocate(vector_implementation_data->start, vector_implementation_data->finish - vector_implementation_data->start);
		}

		allocator get_allocator() const throw()
		{
			return allocator(alloc_return); 
		}

		allocator& alloc_return() throw()
		{
			return this->vector_implementation_data;
		}

		const Allocator& alloc_return() const 
		{
			return this->vector_implementation_data;
		}

		vector_implementation_data& data_implement;

	};


	// used for operations in vector
/* 	template<typename T>
	void swap(vectorBase<T>& a, vectorBase<T>& b)
	{
		if (VECTOR_COMMENTS)
			std::cout << "vectorBase swap() specialization called on " << &a << " and " << &b << std::endl;
		std::swap(a.allocator, b.allocator);
		std::swap(a.vector_implementation_data->start, b.vector_implementation_data->start);
		std::swap(a.vector_implementation_data->finish, b.vector_implementation_data->finish);
		std::swap(a.vector_implementation_data->finish, b.vector_implementation_data->finish);
	}; */

	template<typename T, typename Allocator = std::allocator<T> >
	class vector: private vectorBase<T, Allocator>
	{
		void destroy_elements()
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector destroy_elements()" << std::endl;
			for (T* p = vector_implementation_data->start; p != vector_implementation_data->finish; ++p)
			{
				if (VECTOR_COMMENTS)
					std::cout << p << std::endl;
				p->~T();
			}
		}
	public:
		
		using vectorBase<T, Allocator>::vector_implementation_data;

		typedef typename Allocator::value_type											value_type; // T would also be possible
		typedef typename Allocator::reference								reference;
		typedef typename Allocator::const_reference						const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer							const_pointer;
		typedef typename __gnu_cxx::__normal_iterator<pointer, vector>			iterator;
		typedef typename __gnu_cxx::__normal_iterator<const_pointer, vector>	const_iterator;
		typedef std::reverse_iterator<iterator>									reverse_iterator;
		typedef std::reverse_iterator<const_iterator>							const_reverse_iterator;
		typedef typename Allocator::difference_type						difference_type;
		typedef typename Allocator::size_type								size_type;


		explicit vector (const Allocator& alloc = allocator_type())
			:vectorBase<T, Allocator>(alloc, 0)
		{

		};
		explicit vector (size_type n, const value_type& val = value_type(), const Allocator& alloc = Allocator())
			:vectorBase<T, Allocator>(alloc, n)
		{
			if (VECTOR_COMMENTS)
				std::cout << "val: " << val << std::endl;
			std::uninitialized_fill(vector_implementation_data->start, vector_implementation_data->start + n, val);
			vector_implementation_data->finish = vector_implementation_data->start + n;
		};
		template <class InputIterator>
		vector(ft::enable_if<!(ft::is_integral<InputIterator>::value),InputIterator> first, InputIterator last, const allocator_type& alloc = allocator_type())
		//vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			:vectorBase<T, Allocator>(alloc, last - first)
		{
			std::uninitialized_copy(first, last, this->vector_implementation_data->start);
		}

		vector (const vector& x)
			:vectorBase<T, Allocator>(x.allocator, x.capacity())
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector copy constructor called from " << &x << " on " << this << std::endl;
			std::uninitialized_copy(x.vector_implementation_data->start, x.vector_implementation_data->finish, this->vector_implementation_data->start);
			this->vector_implementation_data->finish = this->vector_implementation_data->start + x.size();
		};
		~vector()
			{
				if (VECTOR_COMMENTS)
					std::cout << "Vector destructor called on " << this << std::endl;
				destroy_elements();
			}
		


		vector& operator=(const vector& rhs)
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector copy assignement operator called from " << &rhs << " on " << this << std::endl;
			// create temporary copy, but not with copy constructor, as this would differ in the capacity of vector compared to original container
			if (this == &rhs)
				return *this;
			//vectorBase<T, Allocator> temp(allocator, this->capacity() < rhs.size() ? rhs.size() : this->capacity()); // allocate memory
			vector<T, Allocator> temp(this->capacity() < rhs.size() ? rhs.size() : this->capacity());
			temp.vector_implementation_data->finish = temp.vector_implementation_data->start;
			std::uninitialized_copy(rhs.vector_implementation_data->start, rhs.vector_implementation_data->finish, temp.vector_implementation_data->start); // copy the elements of rhs into a temporary 
			temp.vector_implementation_data->finish = temp.vector_implementation_data->start + rhs.size();
			swap(*this, temp);
			return(*this);
		}

		size_type size() const throw()
		{
			return (vector_implementation_data->finish - vector_implementation_data->start);
		}

		size_type max_size() const throw()
		{
			//return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			return (allocator.max_size());
		}

		bool empty() const throw()
		{
			return (vector_implementation_data->start == vector_implementation_data->finish);
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

		//single element (1)	
		iterator insert (iterator position, const value_type& val)
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector single element insert() called" << std::endl;
			if (size() == 0)
				push_back(val);
			else if (vector_implementation_data->finish == vector_implementation_data->finish)
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
				a.vector_implementation_data->finish = a.vector_implementation_data->start;
				std::uninitialized_copy(this->vector_implementation_data->start, this->vector_implementation_data->finish, a.vector_implementation_data->start + 1);
				a.vector_implementation_data->finish += this->size();
				new (a.vector_implementation_data->start) T(val);
				destroy_elements();
				swap(a, *this);
			}
			return (this->begin());

		};
		//fill (2)	
		void insert (iterator position, size_type n, const value_type& val)
		{

		};
		//range (3)	
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{

		};

		size_type capacity() const throw()
		{
			return (vector_implementation_data->finish - vector_implementation_data->start);
		}

		iterator begin()
		{
			return (iterator(vector_implementation_data->start));
		}

		const_iterator begin() const
		{
			return (const_iterator(vector_implementation_data->start));
		}

		iterator end()
		{
			return (iterator(vector_implementation_data->finish));
		}

		const_iterator end() const
		{
			return (const_iterator(vector_implementation_data->finish));
		}

		T& operator[] (size_type i)
		{
			if (vector_implementation_data->start)
				return vector_implementation_data->start[i];
			return vector_implementation_data->start[i];//adjust
		}

//explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())

		void push_back(const T& x)
		{
			if (VECTOR_COMMENTS)
				std::cout << "Vector push_back() called" << std::endl;
			if (vector_implementation_data->finish == vector_implementation_data->finish)
			{
				vector<T, Allocator> a(this->size() ? 2 * this->size() : 1);
				a.vector_implementation_data->finish = a.vector_implementation_data->start;
				std::uninitialized_copy(this->vector_implementation_data->start, this->vector_implementation_data->finish, a.vector_implementation_data->start);
				a.vector_implementation_data->finish += this->size();
				new (a.vector_implementation_data->finish) T(x);
				++a.vector_implementation_data->finish;
				//destroy_elements();
				swap(a, *this);
				return;
			}
			new (vector_implementation_data->finish) T(x);
			++vector_implementation_data->finish;
		}
	};

	// used in main when swap(a,b) is called on vectors
	template<typename T>
	void swap(vector<T>& a, vector<T>& b)
	{
		if (VECTOR_COMMENTS)
			std::cout << "vector swap() specialization called on " << &a << " and " << &b << std::endl;
		std::swap(a.allocator, b.allocator);
		std::swap(a.vector_implementation_data->start, b.vector_implementation_data->start);
		std::swap(a.vector_implementation_data->finish, b.vector_implementation_data->finish);
		std::swap(a.vector_implementation_data->finish, b.vector_implementation_data->finish);
	};
}