#pragma once

namespace ft
{

	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	//in this use-case only template to store true/false values; more valuablel when using for more functionalities and value manipulations (like recursive functions)
	template <typename T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type; //technically not necessary, but listed in C++98
		typedef integral_constant<T,v> type; //technically not necessary, but listed in C++98
	};

	typedef integral_constant<bool,true> true_type; //used to reduce run-time, as value for true is created during compile time
	typedef integral_constant<bool,false> false_type; //used to reduce run-time, as value for true is created during compile time

	//default template with value false
	template <typename T>
	struct is_integral : public false_type { };


	//specializations with true values
	template <>
	struct is_integral<bool>
		: public true_type {};

	template <>
	struct is_integral<char>
		: public true_type {};

	template <>
	struct is_integral<wchar_t>
		: public true_type {};

	template <>
	struct is_integral<signed char>
		:public true_type {};

	template <>
	struct is_integral<short int>
		:public true_type {};

	template <>
	struct is_integral<int>
		:public true_type {};

	template <>
	struct is_integral<long int>
		:public true_type {};

	template <>
	struct is_integral<long long int>
		:public true_type {};

	template <>
	struct is_integral<unsigned char>
		:public true_type {};

	template <>
	struct is_integral<unsigned short int>
	:public true_type {};

	template <>
	struct is_integral<unsigned int>
	:public true_type {};

	template <>
	struct is_integral<unsigned long int>
	:public true_type {};

	template <>
	struct is_integral<unsigned long long int>
	:public true_type {};

	//for enable_if testing
	template <class T>
	typename enable_if<is_integral<T>::value,bool>::type is_odd (T i)
	{
		return bool(i%2);
	};

	template < class T>
	bool is_even(T i)
	{
		typedef typename enable_if<is_integral<T>::value,bool>::type integral;
		integral h;
		h = 0;
		if (!h)
			return (!bool(i%2));
		return (0) ;
	};

	template <class T1, class T2>
	struct pair
	{
		public:
			typedef T1 first_type;
			typedef T2 second_type;

			first_type first;
			second_type second;

			pair() : first(), second(){};

		template <class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second){};

		pair(const first_type& a, const second_type& b) : first(a), second(b){};


		pair& operator=(const pair& pr)
		{
			first = pr.first;
			second = pr.second;

			return *this;
		};
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first < rhs.first ||
				(!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template < class T1, class T2 >
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}

	//lex-cmp
	//https://cplusplus.com/reference/algorithm/lexicographical_compare/
	//https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		while (first1!=last1)
		{
			if (first2 == last2 || *first2 < *first1) 
				return false;
			else if (*first1 < *first2) 
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) 
		{
			if (comp(*first1, *first2)) 
				return true;
			if (comp(*first2, *first1)) 
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}


}