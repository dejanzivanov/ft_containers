
#include "../map.hpp"
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

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
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

	return 0;
}