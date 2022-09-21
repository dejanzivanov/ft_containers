// time comparison ft::vector vs std::vector

// time comparison ft::stack vs std::stack

// time comparison ft::map vs std::map

// time comparison ft::42 vs std::42

// leeway for each binary timer test

// 1 to rule them all

// valgrind map

// valgrind stack

// valgrind vector

// valgrind 42

// valgrind list

// valgrind 1 to rull them all

#include "../map.hpp"
#include "../stack.hpp"
#include "../vector.hpp"
#include <list>
#include "foo.hpp"
# include <iostream>
# include <string>
#include <iomanip>

#  define TESTED_NAMESPACE ft

//bounds 

#define T1 int
#define T2 foo<int>
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_iterator;
typedef TESTED_NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;
static int iter = 0;

#define T10 char
#define T12 foo<float>
typedef TESTED_NAMESPACE::map<T10, T12> _map;
typedef _map::const_iterator const_it;
static unsigned int i = 0;

//copy constructor 

#define T14 int
#define T15 int
typedef TESTED_NAMESPACE::pair<const T14, T15> T16;

// empty test

#define T17 char
#define T18 int
typedef TESTED_NAMESPACE::pair<const T17, T18> T19;

// erase test

#define T20 int
#define T21 std::string
typedef TESTED_NAMESPACE::pair<const T20, T21> T22;

// erase test2

#define T23 int
#define T24 std::string
typedef TESTED_NAMESPACE::pair<const T23, T24> T25;

// find test

#define T26 int
#define T27 std::string

TESTED_NAMESPACE::map<T26, T27> mp;
TESTED_NAMESPACE::map<T26, T27>::iterator it = mp.end();

// insert test

#define T28 int
#define T29 std::string
typedef TESTED_NAMESPACE::map<T28, T29>::value_type T30;
typedef TESTED_NAMESPACE::map<T28, T29>::iterator iterator;

// insert test2

#define T31 int
#define T32 std::string
typedef TESTED_NAMESPACE::map<T31, T32>::value_type T33;

// itterator arrow

#define T34 float
#define T35 foo<int>
typedef TESTED_NAMESPACE::pair<const T34, T35> T36;

// more test

#define T37 int
#define T38 std::string

// op sqbr

#define T39 char
#define T40 foo<std::string>

// relational operations

#define T41 char
#define T42 int
typedef TESTED_NAMESPACE::pair<const T41, T42> T43;

// reverse iterator construct 

#define T44 int
#define T45 int

// reverse iterator op

#define T46 float
#define T47 foo<int>
typedef TESTED_NAMESPACE::pair<const T46, T47> T48;

// reverse iterator

#define T49 char
#define T50 int
typedef TESTED_NAMESPACE::pair<const T49, T50> T51;

// swap test 

#define T52 char
#define T53 int
typedef TESTED_NAMESPACE::pair<const T52, T53> T54;

// constructor test

#define T55 int
#define T56 std::string
typedef TESTED_NAMESPACE::map<T55, T56>::value_type T57;

// tricky erase2

#define T58 int
#define T59 std::string
typedef TESTED_NAMESPACE::map<T58, T59>::value_type T60;

// STACK CONTAINER

// default copy

#define TESTED_TYPE1 foo<int>
#define t_stack_ TESTED_NAMESPACE::stack<TESTED_TYPE1>
typedef t_stack_::container_type container_type;

// relational operator

#define TESTED_TYPE2 int
typedef std::list<TESTED_TYPE2> container_type2;
#define t_stack_2 TESTED_NAMESPACE::stack<TESTED_TYPE2, container_type2>

// relational operator 2


#define TESTED_TYPE3 int
#define t_stack_3 TESTED_NAMESPACE::stack<TESTED_TYPE3>
typedef t_stack_3::container_type container_type3;

// VECTOR TEST CASES
#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

// assign

#define TESTED_TYPE_int int
#define TESTED_TYPE_string std::string
#define TESTED_TYPE_foo_int foo<int>

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE_int> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

template <class T, class Alloc>
void	cmp7(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	prepost_incdec(TESTED_NAMESPACE::vector<TESTED_TYPE_int> &vct)
{
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE_int>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	std::cout << "###############################################" << std::endl;
}

void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE_string> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE_string>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

template <class T_STACK>
void	cmp3(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}


template <class T_STACK>
void	cmp1(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}


template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template <typename T_STACK>
void	printSize1(T_STACK &stck, bool print_content = 1)
{
	std::cout << "size: " << stck.size() << std::endl;
	if (print_content)
	{
		std::cout << std::endl << "Content was:" << std::endl;
		while (stck.size() != 0) {
			std::cout << "- " << stck.top() << std::endl;
			stck.pop();
		}
	}
	std::cout << "###############################################" << std::endl;
}

struct ft_more {
	bool	operator()(const T37 &first, const T37 &second) const {
		return (first > second);
	}
};

typedef TESTED_NAMESPACE::map<T37, T38, ft_more> ft_mp;
typedef TESTED_NAMESPACE::map<T37, T38, ft_more>::iterator ft_mp_it;

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

void	ft_find(T26 const &k)
{
	TESTED_NAMESPACE::map<T26, T27>::iterator ret = mp.find(k);

	if (ret != it)
		printPair(ret);
	else
		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}
void	ft_count(T26 const &k)
{
	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename MAP>
void	ft_erase5(MAP &mp, const T58 param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	TESTED_NAMESPACE::pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	iterator tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}

template <typename MAP, typename U>
void	ft_insert3(MAP &mp, U param, U param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.insert(param, param2);
	printSize(mp);
}


template <typename MAP, typename U>
void	ft_erase2(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "ret: " << mp.erase(param) << std::endl;
	printSize(mp);
}

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

template <class T>
void	is_empty(T const &mp)
{
	std::cout << "is_empty: " << mp.empty() << std::endl;
}

void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

void	outputTitle(std::string title)
{
	std::string	toPrint;
	int	size = 60;
	int	n;

	toPrint = " " + title + " ";
	n = toPrint.size();
	if (n > size)
	{
		toPrint = toPrint.substr(0, size - 2);
		toPrint[size - 4] = '.';
		toPrint[size - 3] = ' ';
		n = toPrint.size();
	}
	std::cout << std::endl << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
	std::cout << toPrint.substr(n / 2, n);
	std::cout << std::setfill('=') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
}



template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param)
{
	ft_iterator ite = mp.end(), it[2];
	TESTED_NAMESPACE::pair<ft_iterator, ft_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &mp, const T1 &param)
{
	ft_const_iterator ite = mp.end(), it[2];
	TESTED_NAMESPACE::pair<ft_const_iterator, ft_const_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}





int main(void)
{
	{
		outputTitle("BOUNDS TEST");
		std::list<T3> lst;
		unsigned int lst_size = 10;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T3(i + 1, (i + 1) * 3));
		TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
		printSize(mp);

		ft_const_bound(mp, -10);
		ft_const_bound(mp, 1);
		ft_const_bound(mp, 5);
		ft_const_bound(mp, 10);
		ft_const_bound(mp, 50);

		printSize(mp);

		mp.lower_bound(3)->second = 404;
		mp.upper_bound(7)->second = 842;
		ft_bound(mp, 5);
		ft_bound(mp, 7);
		printSize(mp);
	}


	/*********************** BOUND TEST END ***********************************/

	
	{
		outputTitle("COMPARE TEST");
		_map	mp;

		mp['a'] = 2.3;
		mp['b'] = 1.4;
		mp['c'] = 0.3;
		mp['d'] = 4.2;
		printSize(mp);

		for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
			for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
				ft_comp(mp, it1, it2);

		printSize(mp);
	}

	/************************ COMP TEST END ***********************************/

	{
		outputTitle("COPY CONSTRUCTOR TEST");

		std::list<T16> lst;
		unsigned int lst_size = 7;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T16(lst_size - i, i));

		TESTED_NAMESPACE::map<T14, T15> mp(lst.begin(), lst.end());
		TESTED_NAMESPACE::map<T14, T15>::iterator it = mp.begin(), ite = mp.end();

		TESTED_NAMESPACE::map<T14, T15> mp_range(it, --(--ite));
		for (int i = 0; it != ite; ++it)
			it->second = ++i * 5;

		it = mp.begin(); ite = --(--mp.end());
		TESTED_NAMESPACE::map<T14, T15> mp_copy(mp);
		for (int i = 0; it != ite; ++it)
			it->second = ++i * 7;

		std::cout << "\t-- PART ONE --" << std::endl;
		
		printSize(mp);
		printSize(mp_range);
		printSize(mp_copy);

		mp = mp_copy;
		mp_copy = mp_range;
		mp_range.clear();

		std::cout << "\t-- PART TWO --" << std::endl;
		printSize(mp);
		printSize(mp_range);
		printSize(mp_copy);
	}
	/*********************** COPY CONSTRUCTOR TEST END ************************/

	{
		std::list<T19> lst;
		unsigned int lst_size = 7;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T19('a' + i, lst_size - i));

		TESTED_NAMESPACE::map<T17, T18> mp(lst.begin(), lst.end()), mp2;
		TESTED_NAMESPACE::map<T17, T18>::iterator it;

		lst.clear();
		is_empty(mp);
		printSize(mp);

		// ✅✅

		is_empty(mp2);
		mp2 = mp;
		is_empty(mp2);

		// ✅✅

		it = mp.begin();
		for (unsigned long int i = 3; i < mp.size(); ++i)
			it++->second = i * 7;

		printSize(mp);
		printSize(mp2);

		// ✅✅

		mp2.clear();
		is_empty(mp2);
		printSize(mp2);
	}

	{
		outputTitle("ERASE TEST");
		std::list<T22> lst;
		unsigned int lst_size = 10;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T22(i, std::string((lst_size - i), i + 65)));
		TESTED_NAMESPACE::map<T20, T21> mp(lst.begin(), lst.end());
		printSize(mp);

		ft_erase(mp, ++mp.begin());
		ft_erase(mp, mp.begin());
		ft_erase(mp, --mp.end());

		ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
		ft_erase(mp, --(--(--mp.end())), --mp.end());

		mp[10] = "Hello";
		mp[11] = "Hi there";
		printSize(mp);
		ft_erase(mp, --(--(--mp.end())), mp.end());

		mp[12] = "ONE";
		mp[13] = "TWO";
		mp[14] = "THREE";
		mp[15] = "FOUR";
		printSize(mp);
		
		ft_erase(mp, mp.begin(), mp.end());
	}

	{
		outputTitle("ERASE TEST2");

		std::list<T25> lst;
		unsigned int lst_size = 6;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T25(i, std::string((lst_size - i), i + 65)));
		TESTED_NAMESPACE::map<T23, T24> mp(lst.begin(), lst.end());
		printSize(mp);

		for (int i = 2; i < 4; ++i)
			ft_erase2(mp, i);

		ft_erase2(mp, mp.begin()->first);
		ft_erase2(mp, (--mp.end())->first);

		mp[-1] = "Hello";
		mp[10] = "Hi there";
		mp[10] = "Hi there";
		printSize(mp);

		ft_erase2(mp, 0);
		ft_erase2(mp, 1);
	}

	{
		outputTitle("FIND_COUNT TEST");
		mp[42] = "fgzgxfn";
		mp[25] = "funny";
		mp[80] = "hey";
		mp[12] = "no";
		mp[27] = "bee";
		mp[90] = "8";
		printSize(mp);

		std::cout << "\t-- FIND --" << std::endl;
		ft_find(12);
		ft_find(3);
		ft_find(35);
		ft_find(90);
		ft_find(100);

		std::cout << "\t-- COUNT --" << std::endl;
		ft_count(-3);
		ft_count(12);
		ft_count(3);
		ft_count(35);
		ft_count(90);
		ft_count(100);

		mp.find(27)->second = "newly inserted mapped_value";

		printSize(mp);

		TESTED_NAMESPACE::map<T26, T27> const c_map(mp.begin(), mp.end());
		std::cout << "const map.find(" << 42 << ")->second: [" << c_map.find(42)->second << "]" << std::endl;
		std::cout << "const map.count(" << 80 << "): [" << c_map.count(80) << "]" << std::endl;
	}

	{
		outputTitle("INSERT TEST");
		TESTED_NAMESPACE::map<T28, T29> mp, mp2;

		ft_insert(mp, T30(42, "lol"));
		ft_insert(mp, T30(42, "mdr"));

		ft_insert(mp, T30(50, "mdr"));
		ft_insert(mp, T30(35, "funny"));

		ft_insert(mp, T30(45, "bunny"));
		ft_insert(mp, T30(21, "fizz"));
		ft_insert(mp, T30(38, "buzz"));

		ft_insert(mp, mp.begin(), T30(55, "fuzzy"));

		ft_insert(mp2, mp2.begin(), T30(1337, "beauty"));
		ft_insert(mp2, mp2.end(), T30(1000, "Hello"));
		ft_insert(mp2, mp2.end(), T30(1500, "World"));
	}

	{
		outputTitle("INSERT TEST2");
		std::list<T33> lst;
		std::list<T33>::iterator itlst;

		lst.push_back(T33(42, "lol"));

		lst.push_back(T33(50, "mdr"));
		lst.push_back(T33(35, "funny"));

		lst.push_back(T33(45, "bunny"));
		lst.push_back(T33(21, "fizz"));
		lst.push_back(T33(38, "buzz"));
		lst.push_back(T33(55, "fuzzy"));

		std::cout << "List contains:" << std::endl;
		for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
			printPair(itlst);

		TESTED_NAMESPACE::map<T31, T32> mp;
		ft_insert3(mp, lst.begin(), lst.end());

		lst.clear();

		lst.push_back(T33(87, "hey"));
		lst.push_back(T33(47, "eqweqweq"));
		lst.push_back(T33(35, "this key is already inside"));
		lst.push_back(T33(23, "but not that one"));
		lst.push_back(T33(1, "surprising isnt it?"));
		lst.push_back(T33(100, "is it enough??"));
		lst.push_back(T33(55, "inside map too"));

		std::cout << "List contains:" << std::endl;
		for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
			printPair(itlst);

		ft_insert3(mp, lst.begin(), lst.begin());
		ft_insert3(mp, lst.begin(), lst.end());
	}

	{
		outputTitle("ITERATOR TEST");

		std::list<T36> lst;
		unsigned int lst_size = 5;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T36(2.5 + i, i + 1));

		TESTED_NAMESPACE::map<T34, T35> mp(lst.begin(), lst.end());
		TESTED_NAMESPACE::map<T34, T35>::iterator it(mp.begin());
		TESTED_NAMESPACE::map<T34, T35>::const_iterator ite(mp.begin());
		printSize(mp);

		printPair(++ite);
		printPair(ite++);
		printPair(ite++);
		printPair(++ite);

		it->second.m();
		ite->second.m();

		printPair(++it);
		printPair(it++);
		printPair(it++);
		printPair(++it);

		printPair(--ite);
		printPair(ite--);
		printPair(--ite);
		printPair(ite--);

		(*it).second.m();
		(*ite).second.m();

		printPair(--it);
		printPair(it--);
		printPair(it--);
		printPair(--it);
	}

	{
		outputTitle("MORE TEST");

		ft_mp mp;

		mp[42] = "fgzgxfn";
		mp[25] = "funny";
		mp[80] = "hey";
		mp[12] = "no";
		mp[27] = "bee";
		mp[90] = "8";
		printSize(mp);

	}

	{
		outputTitle("op sqbr");
		
		TESTED_NAMESPACE::map<T39, T40> mp;

		mp['a'] = "an element";
		mp['b'] = "another element";
		mp['c'] = mp['b'];
		mp['b'] = "old element";
		printSize(mp);
		std::cout << "insert a new element via operator[]: " << mp['d'] << std::endl;

		printSize(mp);

	}

	{
		outputTitle("RELATIONAL OPERATION TEST");

		TESTED_NAMESPACE::map<T41, T42> mp1;
		TESTED_NAMESPACE::map<T41, T42> mp2;

		mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
		mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

		cmp(mp1, mp1); // 0
		cmp(mp1, mp2); // 1

		mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

		cmp(mp1, mp2); // 2
		cmp(mp2, mp1); // 3

		(++(++mp1.begin()))->second = 42;

		cmp(mp1, mp2); // 4
		cmp(mp2, mp1); // 5

		swap(mp1, mp2);

		cmp(mp1, mp2); // 6
		cmp(mp2, mp1); // 7

	}

	{
		outputTitle("reverse iterator constructor test");

		TESTED_NAMESPACE::map<T44, T45> mp;
		TESTED_NAMESPACE::map<T44, T45>::iterator it = mp.begin();
		TESTED_NAMESPACE::map<T44, T45>::const_iterator cit = mp.begin();

		TESTED_NAMESPACE::map<T44, T45>::reverse_iterator rit(it);

		TESTED_NAMESPACE::map<T44, T45>::const_reverse_iterator crit(rit);
		TESTED_NAMESPACE::map<T44, T45>::const_reverse_iterator crit_(it);
		TESTED_NAMESPACE::map<T44, T45>::const_reverse_iterator crit_2(cit);
	}

	{
		outputTitle("reverse iterator pointer test");

		std::list<T48> lst;
		unsigned int lst_size = 5;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T48(2.5 - i, (i + 1) * 7));

		TESTED_NAMESPACE::map<T46, T47> mp(lst.begin(), lst.end());
		TESTED_NAMESPACE::map<T46, T47>::reverse_iterator it(mp.rbegin());
		TESTED_NAMESPACE::map<T46, T47>::const_reverse_iterator ite(mp.rbegin());
		printSize(mp);

		printPair(++ite);
		printPair(ite++);
		printPair(ite++);
		printPair(++ite);

		it->second.m();
		ite->second.m();

		printPair(++it);
		printPair(it++);
		printPair(it++);
		printPair(++it);

		printPair(--ite);
		printPair(ite--);
		printPair(--ite);
		printPair(ite--);

		(*it).second.m();
		(*ite).second.m();

		printPair(--it);
		printPair(it--);
		printPair(it--);
		printPair(--it);

	}

	{
		outputTitle("reverse iterator relational operation test");

		std::list<T51> lst;
		unsigned int lst_size = 5;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T51('a' + i, (i + 1) * 7));

		TESTED_NAMESPACE::map<T49, T50> mp(lst.begin(), lst.end());
		TESTED_NAMESPACE::map<T49, T50>::iterator it_ = mp.begin();
		TESTED_NAMESPACE::map<T49, T50>::reverse_iterator it(it_), ite;
		printSize(mp);

		std::cout << (it_ == it.base()) << std::endl;
		std::cout << (it_ == dec(it, 3).base()) << std::endl;

		printPair(it.base());
		printPair(inc(it.base(), 1));

		std::cout << "TEST OFFSET" << std::endl;

		--it;
		printPair(it);
		printPair(it.base());

		it = mp.rbegin(); ite = mp.rend();
		while (it != ite)
			std::cout << "[rev] " << printPair(it++, false) << std::endl;
		
	}

	{
		outputTitle("swap test");

		std::list<T54> lst;

		unsigned int lst_size = 7;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T54('a' + i, lst_size - i));
		TESTED_NAMESPACE::map<T52, T53> foo(lst.begin(), lst.end());

		lst.clear(); lst_size = 4;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T54('z' - i, i * 5));
		TESTED_NAMESPACE::map<T52, T53> bar(lst.begin(), lst.end());

		TESTED_NAMESPACE::map<T52, T53>::const_iterator it_foo = foo.begin();
		TESTED_NAMESPACE::map<T52, T53>::const_iterator it_bar = bar.begin();

		std::cout << "BEFORE SWAP" << std::endl;

		std::cout << "foo contains:" << std::endl;
		printSize(foo);
		std::cout << "bar contains:" << std::endl;
		printSize(bar);

		foo.swap(bar);

		std::cout << "AFTER SWAP" << std::endl;

		std::cout << "foo contains:" << std::endl;
		printSize(foo);
		std::cout << "bar contains:" << std::endl;
		printSize(bar);

		std::cout << "Iterator validity:" << std::endl;
		std::cout << (it_foo == bar.begin()) << std::endl;
		std::cout << (it_bar == foo.begin()) << std::endl;
	}

	{
		outputTitle("tricky constructor test");

		std::list<T57> lst;
		std::list<T57>::iterator itlst;

		lst.push_back(T57(42, "lol"));
		lst.push_back(T57(50, "mdr"));
		lst.push_back(T57(35, "funny"));
		lst.push_back(T57(45, "bunny"));
		lst.push_back(T57(21, "fizz"));
		lst.push_back(T57(35, "this key is already inside"));
		lst.push_back(T57(55, "fuzzy"));
		lst.push_back(T57(38, "buzz"));
		lst.push_back(T57(55, "inside too"));

		std::cout << "List contains: " << lst.size() << " elements." << std::endl;
		for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
			printPair(itlst);
		std::cout << "---------------------------------------------" << std::endl;

		TESTED_NAMESPACE::map<T55, T56> mp(lst.begin(), lst.end());
		lst.clear();

		printSize(mp);
	}

	{
		outputTitle("tricky erase test");

		TESTED_NAMESPACE::map<T58, T59> mp;

		mp[42] = "lol";

		mp[50] = "mdr";
		mp[25] = "funny";

		mp[46] = "bunny";
		mp[21] = "fizz";
		mp[30] = "buzz";
		mp[55] = "fuzzy";

		mp[18] = "bee";
		mp[23] = "coconut";
		mp[28] = "diary";
		mp[35] = "fiesta";
		mp[44] = "hello";
		mp[48] = "world";
		mp[53] = "this is a test";
		mp[80] = "hey";

		mp[12] = "no";
		mp[20] = "idea";
		mp[22] = "123";
		mp[24] = "345";
		mp[27] = "27";
		mp[29] = "29";
		mp[33] = "33";
		mp[38] = "38";

		mp[43] = "1";
		mp[45] = "2";
		mp[47] = "3";
		mp[49] = "4";
		mp[51] = "5";
		mp[54] = "6";
		mp[60] = "7";
		mp[90] = "8";

		printSize(mp);

		ft_erase5(mp, 25);
		ft_erase5(mp, 55); 
		ft_erase5(mp, 24);
		ft_erase5(mp, 54);
		ft_erase5(mp, 22);
		ft_erase5(mp, 51);
		ft_erase5(mp, 21);
		ft_erase5(mp, 53); 
		ft_erase5(mp, 20);
		ft_erase5(mp, 23);
		ft_erase5(mp, 42); 
		ft_erase5(mp, 38);
		ft_erase5(mp, 35);
		ft_erase5(mp, 33);

	}

	outputTitle("TEST CASES FOR STACK CONTAINER");
	{
		outputTitle("Testing defualt copy");

		container_type	ctnr;

		ctnr.push_back(21);
		ctnr.push_back(42);
		ctnr.push_back(1337);
		ctnr.push_back(19);
		ctnr.push_back(0);
		ctnr.push_back(183792);

		t_stack_		stck(ctnr);

		std::cout << "empty: " << stck.empty() << std::endl;
		std::cout << "size: " << stck.size() << std::endl;

		stck.push(1);
		stck.push(2);
		stck.push(3);
		stck.push(4);
		stck.push(5);
		stck.push(6);

		std::cout << "Added some elements" << std::endl;

		std::cout << "empty: " << stck.empty() << std::endl;
		printSize1(stck);
	}

	{
		outputTitle("default test");

		TESTED_NAMESPACE::stack<TESTED_TYPE1> stck;

		std::cout << "empty: " << stck.empty() << std::endl;
		std::cout << "size: " << stck.size() << std::endl;

		stck.push(41);
		stck.push(29);
		stck.push(10);
		stck.push(42);
		std::cout << "Added some elements" << std::endl;

		std::cout << "empty: " << stck.empty() << std::endl;
		printSize1(stck);

	}

	{
		outputTitle("list copy");

		container_type	ctnr;

		ctnr.push_back(21);
		ctnr.push_back(42);
		ctnr.push_back(1337);
		ctnr.push_back(19);
		ctnr.push_back(0);
		ctnr.push_back(183792);

		t_stack_		stck(ctnr);

		std::cout << "empty: " << stck.empty() << std::endl;
		std::cout << "size: " << stck.size() << std::endl;

		stck.push(1);
		stck.push(2);
		stck.push(3);
		stck.push(4);
		stck.push(5);
		stck.push(6);

		std::cout << "Added some elements" << std::endl;

		std::cout << "empty: " << stck.empty() << std::endl;
		printSize1(stck);
	}

	{
		outputTitle("relational operators");

		container_type2	ctnr;

		ctnr.push_back(21);
		ctnr.push_back(42);
		ctnr.push_back(1337);
		ctnr.push_back(19);
		ctnr.push_back(0);
		ctnr.push_back(183792);

		t_stack_2	stck(ctnr);
		t_stack_2	stck2(ctnr);

		cmp1(stck, stck);  // 0
		cmp1(stck, stck2); // 1

		stck2.push(60);
		stck2.push(61);
		stck2.push(62);

		cmp1(stck, stck2); // 2
		cmp1(stck2, stck); // 3

		stck.push(42);

		cmp1(stck, stck2); // 4
		cmp1(stck2, stck); // 5

		stck.push(100);

		cmp1(stck, stck2); // 6
		cmp1(stck2, stck); // 7
	}

	{
		outputTitle("Relational operator");

		container_type3	ctnr;

		ctnr.push_back(21);
		ctnr.push_back(42);
		ctnr.push_back(1337);
		ctnr.push_back(19);
		ctnr.push_back(0);
		ctnr.push_back(183792);

		t_stack_3	stck(ctnr);
		t_stack_3	stck2(ctnr);

		cmp3(stck, stck); 
		cmp3(stck, stck2);

		stck2.push(60);
		stck2.push(61);
		stck2.push(62);

		cmp3(stck, stck2);
		cmp3(stck2, stck);

		stck.push(42);

		cmp3(stck, stck2);
		cmp3(stck2, stck);

		stck.push(100);

		cmp3(stck, stck2);
		cmp3(stck2, stck);
	}

	outputTitle("VECTOR CONTAINER TEST CASES");

	{
		outputTitle("Assign test");

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(7);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct_two(4);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct_three;
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct_four;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		for (unsigned long int i = 0; i < vct_two.size(); ++i)
			vct_two[i] = (vct_two.size() - i) * 5;

		printSize(vct);
		

		printSize(vct_two);

		vct_three.assign(vct.begin(), vct.end());
		
		vct.assign(vct_two.begin(), vct_two.end());
		vct_two.assign(2, 42);
		vct_four.assign(4, 21);

		std::cout << "\t### After assign(): ###" << std::endl;


		printSize(vct);
		printSize(vct_two);
		printSize(vct_three);
		printSize(vct_four);

		vct_four.assign(6, 84);
		printSize(vct_four);

		std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

		vct.assign(5, 53);
		vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

		printSize(vct);
		printSize(vct_two);

	}

	{
		outputTitle("At Const Test");

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(7);

		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct[]: " << vct[i] << std::endl;
		}
		printSize(vct);

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> const vct_c(vct);

		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

		for (unsigned long int i = 0; i < vct_c.size(); ++i)
			std::cout << "vct_c.at(): " << vct_c.at(i) << std::endl;
		try {
			std::cout << vct_c.at(10) << std::endl;
		}
		catch (std::out_of_range &e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Catch exception: " << e.what() << std::endl;
		}
		printSize(vct_c);

	}

	{
		outputTitle("At Test");

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(7);

		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct[]: " << vct[i] << std::endl;
		}
		printSize(vct);

		std::cout << "front(): " << vct.front() << std::endl;
		std::cout << "back(): " << vct.back() << std::endl;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			std::cout << "vct.at(): " << vct.at(i) << std::endl;
		try {
			std::cout << vct.at(10) << std::endl;
		}
		catch (std::out_of_range &e) {
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Catch exception: " << e.what() << std::endl;
		}
		printSize(vct);

	}

	{
		outputTitle("Back Const Test");

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(7);

		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct[i] = (vct.size() - i) * 3;
			std::cout << "vct[]: " << vct[i] << std::endl;
		}
		printSize(vct);

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> const vct_c(vct);

		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

		printSize(vct_c);

	}

	{
		outputTitle("Bidirectional iterator Test");

		std::list<TESTED_TYPE_int> lst;
		std::list<TESTED_TYPE_int>::iterator lst_it;
		for (int i = 1; i < 5; ++i)
			lst.push_back(i * 3);

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(lst.begin(), lst.end());
		printSize(vct);

		lst_it = lst.begin();
		for (int i = 1; lst_it != lst.end(); ++i)
			*lst_it++ = i * 5;
		vct.assign(lst.begin(), lst.end());
		printSize(vct);

		vct.insert(vct.end(), lst.rbegin(), lst.rend());
		printSize(vct);

	}

	{
		outputTitle("Copy constructor Test");

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(5);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::iterator it = vct.begin(), ite = vct.end();

		std::cout << "len: " << (ite - it) << std::endl;
		for (; it != ite; ++it)
			*it = (ite - it);

		it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct_range(it, --(--ite));
		for (int i = 0; it != ite; ++it)
			*it = ++i * 5;

		it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct_copy(vct);
		for (int i = 0; it != ite; ++it)
			*it = ++i * 7;
		vct_copy.push_back(42);
		vct_copy.push_back(21);

		std::cout << "\t-- PART ONE --" << std::endl;
		printSize(vct);
		printSize(vct_range);
		printSize(vct_copy);

		vct = vct_copy;
		vct_copy = vct_range;
		vct_range.clear();

		std::cout << "\t-- PART TWO --" << std::endl;
		printSize(vct);
		printSize(vct_range);
		printSize(vct_copy);

	}

	{
		outputTitle("Erase Test");

		TESTED_NAMESPACE::vector<TESTED_TYPE_string> vct(10);

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = std::string((vct.size() - i), i + 65);
		printSize(vct);

		checkErase(vct, vct.erase(vct.begin() + 2));

		checkErase(vct, vct.erase(vct.begin()));
		checkErase(vct, vct.erase(vct.end() - 1));

		checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
		checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

		vct.push_back("Hello");
		vct.push_back("Hi there");
		printSize(vct);
		checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

		vct.push_back("ONE");
		vct.push_back("TWO");
		vct.push_back("THREE");
		vct.push_back("FOUR");
		printSize(vct);
		checkErase(vct, vct.erase(vct.begin(), vct.end()));

	}

	
	{
		outputTitle("Insert Test");

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(10);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct2;
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		printSize(vct);
		vct2.insert(vct2.end(), 42);
		vct2.insert(vct2.begin(), 2, 21);
		printSize(vct2);

		vct2.insert(vct2.end() - 2, 42);
		printSize(vct2);

		vct2.insert(vct2.end(), 2, 84);
		printSize(vct2);

		vct2.resize(4);
		printSize(vct2);

		vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		vct.clear();
		printSize(vct2);

		printSize(vct);

		for (int i = 0; i < 5; ++i)
			vct3.insert(vct3.end(), i);
		vct3.insert(vct3.begin() + 1, 2, 111);
		printSize(vct3);
	}

	{
		outputTitle("Insert2 Test"); /**/

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(5);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct2;
		const int cut = 3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 7;
		printSize(vct);

		vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		printSize(vct2);
		vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		printSize(vct2);
		vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
		printSize(vct2);

		std::cout << "insert return:" << std::endl;

		std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
		std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
		std::cout << "----------------------------------------" << std::endl;

		printSize(vct2);
	}

	{
		outputTitle("ite test");

		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::iterator it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::const_iterator ite = vct.begin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;
		prepost_incdec(vct);

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
		std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		printSize(vct, true);

	}

	{
		outputTitle("ITE arrow test");

		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::iterator it(vct.begin());
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::const_iterator ite(vct.end());

		for (int i = 1; it != ite; ++i)
			*it++ = i;
		printSize(vct, 1);

		it = vct.begin();
		ite = vct.begin();

		std::cout << *(++ite) << std::endl;
		std::cout << *(ite++) << std::endl;
		std::cout << *ite++ << std::endl;
		std::cout << *++ite << std::endl;

		it->m();
		ite->m();

		std::cout << *(++it) << std::endl;
		std::cout << *(it++) << std::endl;
		std::cout << *it++ << std::endl;
		std::cout << *++it << std::endl;

		std::cout << *(--ite) << std::endl;
		std::cout << *(ite--) << std::endl;
		std::cout << *--ite << std::endl;
		std::cout << *ite-- << std::endl;

		(*it).m();
		(*ite).m();

		std::cout << *(--it) << std::endl;
		std::cout << *(it--) << std::endl;
		std::cout << *it-- << std::endl;
		std::cout << *--it << std::endl;
	}


	{
		outputTitle("iterator equal operator");
		
		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::iterator it_0(vct.begin());
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::iterator it_1(vct.end());
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::iterator it_mid;

		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::const_iterator cit_0 = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::const_iterator cit_1;
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::const_iterator cit_mid;

		for (int i = size; it_0 != it_1; --i)
			*it_0++ = i;
		printSize(vct, 1);
		it_0 = vct.begin();
		cit_1 = vct.end();
		it_mid = it_0 + 3;
		cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

		std::cout << std::boolalpha;
		std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

		std::cout << "\t\tft_eq_ope:" << std::endl;
		// regular it
		ft_eq_ope(it_0 + 3, it_mid);
		ft_eq_ope(it_0, it_1);
		ft_eq_ope(it_1 - 3, it_mid);
		// const it
		ft_eq_ope(cit_0 + 3, cit_mid);
		ft_eq_ope(cit_0, cit_1);
		ft_eq_ope(cit_1 - 3, cit_mid);
		// both it
		ft_eq_ope(it_0 + 3, cit_mid);
		ft_eq_ope(it_mid, cit_0 + 3);
		ft_eq_ope(it_0, cit_1);
		ft_eq_ope(it_1, cit_0);
		ft_eq_ope(it_1 - 3, cit_mid);
		ft_eq_ope(it_mid, cit_1 - 3);
	}

	{
		outputTitle("push pop test");

		TESTED_NAMESPACE::vector<TESTED_TYPE_string> vct(8);
		TESTED_NAMESPACE::vector<TESTED_TYPE_string> vct2;
		TESTED_NAMESPACE::vector<TESTED_TYPE_string>::iterator it = vct.begin();

		for (unsigned long int i = 0; i < vct.size(); ++i)
			it[i] = std::string((vct.size() - i), i + 65);
		printSize(vct, true);

		std::cout << "push_back():\n" << std::endl;

		vct.push_back("One long string");
		vct2.push_back("Another long string");

		printSize(vct);
		printSize(vct2);

		vct.pop_back();
		vct2.pop_back();

		printSize(vct);
		printSize(vct2);
	}

	{
		outputTitle("Relational operator");

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(4);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct2(4);

		cmp7(vct, vct);  // 0
		cmp7(vct, vct2); // 1

		vct2.resize(10);

		cmp7(vct, vct2); // 2
		cmp7(vct2, vct); // 3

		vct[2] = 42;

		cmp7(vct, vct2); // 4
		cmp7(vct2, vct); // 5

		swap(vct, vct2);

		cmp7(vct, vct2); // 6
		cmp7(vct2, vct); // 7
	}

	{
		outputTitle("reverse iterator constructor");

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct;
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::iterator it = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::const_iterator cit = vct.begin();

		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::reverse_iterator rit(it);

		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::const_reverse_iterator crit(rit);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::const_reverse_iterator crit_(it);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::const_reverse_iterator crit_2(cit);
	
	}

	{
		outputTitle("reverse iterator ");

		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::iterator it_ = vct.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::reverse_iterator it(it_);

		for (int i = 0; i < size; ++i)
			vct[i] = (i + 1) * 5;
		printSize(vct);

		std::cout << (it_ == it.base()) << std::endl;
		std::cout << (it_ == (it + 3).base()) << std::endl;

		std::cout << *(it.base() + 1) << std::endl;
		std::cout << *(it - 3) << std::endl;
		std::cout << *(it - 3).base() << std::endl;
		it -= 3;
		std::cout << *it.base() << std::endl;

		std::cout << "TEST OFFSET" << std::endl;
		std::cout << *(it) << std::endl;
		std::cout << *(it).base() << std::endl;
		std::cout << *(it - 0) << std::endl;
		std::cout << *(it - 0).base() << std::endl;
		std::cout << *(it - 1).base() << std::endl;

	}

	{
		outputTitle("reverse iterator2");

		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::reverse_iterator it = vct.rbegin();
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::const_reverse_iterator ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		printSize(vct, true);

	}

	{
		outputTitle("reverse iterator arrow");

		const int size = 5;
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int> vct(size);
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::reverse_iterator it(vct.rbegin());
		TESTED_NAMESPACE::vector<TESTED_TYPE_foo_int>::const_reverse_iterator ite(vct.rend());

		for (int i = 1; it != ite; ++i)
			*it++ = (i * 7);
		printSize(vct, 1);

		it = vct.rbegin();
		ite = vct.rbegin();

		std::cout << *(++ite) << std::endl;
		std::cout << *(ite++) << std::endl;
		std::cout << *ite++ << std::endl;
		std::cout << *++ite << std::endl;

		it->m();
		ite->m();

		std::cout << *(++it) << std::endl;
		std::cout << *(it++) << std::endl;
		std::cout << *it++ << std::endl;
		std::cout << *++it << std::endl;

		std::cout << *(--ite) << std::endl;
		std::cout << *(ite--) << std::endl;
		std::cout << *--ite << std::endl;
		std::cout << *ite-- << std::endl;

		(*it).m();
		(*ite).m();

		std::cout << *(--it) << std::endl;
		std::cout << *(it--) << std::endl;
		std::cout << *it-- << std::endl;
		std::cout << *--it << std::endl;

	}

	{
		outputTitle("size test");

		const int start_size = 7;
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct(start_size, 20);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> vct2;
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::iterator it = vct.begin();

		for (int i = 2; i < start_size; ++i)
			it[i] = (start_size - i) * 3;
		printSize(vct, true);

		vct.resize(10, 42);
		printSize(vct, true);

		vct.resize(18, 43);
		printSize(vct, true);
		vct.resize(10);
		printSize(vct, true);
		vct.resize(23, 44);
		printSize(vct, true);
		vct.resize(5);
		printSize(vct, true);
		vct.reserve(5);
		vct.reserve(3);
		printSize(vct, true);
		vct.resize(87);
		vct.resize(5);
		printSize(vct, true);

		is_empty(vct2);
		vct2 = vct;
		is_empty(vct2);
		vct.reserve(vct.capacity() + 1);
		printSize(vct, true);
		printSize(vct2, true);

		vct2.resize(0);
		is_empty(vct2);
		printSize(vct2, true);
	}

	{
		outputTitle("swap test");

		TESTED_NAMESPACE::vector<TESTED_TYPE_int> foo(3, 15);
		TESTED_NAMESPACE::vector<TESTED_TYPE_int> bar(5, 42);
		
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::const_iterator it_foo = foo.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE_int>::const_iterator it_bar = bar.begin();

		std::cout << "BEFORE SWAP" << std::endl;

		std::cout << "foo contains:" << std::endl;
		printSize(foo);
		std::cout << "bar contains:" << std::endl;
		printSize(bar);

		foo.swap(bar);

		std::cout << "AFTER SWAP" << std::endl;

		std::cout << "foo contains:" << std::endl;
		printSize(foo);
		std::cout << "bar contains:" << std::endl;
		printSize(bar);

		std::cout << "Iterator validity:" << std::endl;
		std::cout << (it_foo == bar.begin()) << std::endl;
		std::cout << (it_bar == foo.begin()) << std::endl;
	}
	


	return 0;
}