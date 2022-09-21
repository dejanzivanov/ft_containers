
#include <map>
#include <stack>
#include <list>
#include <iterator>
#include "foo.hpp"
# include <iostream>
# include <string>
#include <iomanip>

#  define TESTED_NAMESPACE std

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

	return 0;
}