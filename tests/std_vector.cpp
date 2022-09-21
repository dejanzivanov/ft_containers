

#include <vector>
#include <iterator>
// #include "../utils.hpp"
#include <list>
#include "foo.hpp"
# include <iostream>
# include <string>
#include <iomanip>

// VECTOR TEST CASES
#  define TESTED_NAMESPACE std
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



template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
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




template <class T>
void	is_empty(T const &mp)
{
	std::cout << "is_empty: " << mp.empty() << std::endl;
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

int main(void)
{
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