#include <iostream>
#include <string>
#include <deque>

#if 0 //CREATE A REAL STL EXAMPLE
	//#include <map>
	//#include <stack>
	#include <vector>
	#include <type_traits>
	namespace ft = std;
#else
	//#include <map.hpp>
	//#include <stack.hpp>
	#include "vector.hpp"
	#include "utils.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

ft::pair<int, int> foo(int a, int b)
{
	return ft::make_pair(a + b, a - b);
}


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	//ft::vector<std::string> vector_str;
	ft::vector<int> vector_int(5);
	ft::vector<int> vector_int2(vector_int);
	ft::vector<int> vector_int3;
	std::cout << vector_int2.empty() << std::endl;
	std::cout << vector_int3.empty() << std::endl;
	std::cout << "vector_int address, size and capacity: " << &vector_int << " | " << vector_int.size() << " | " << vector_int.capacity() << std::endl;
	std::cout << "vector_int2 address, size and capacity: " << &vector_int2 << " | " << vector_int2.size() << " | " << vector_int2.capacity() << std::endl;
	std::cout << "vector_int3 address, size and capacity: " << &vector_int3 << " | " << vector_int3.size() << " | " << vector_int3.capacity() << std::endl;

/* 	ft::vector<Buffer> vector_buffer;


	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	} */


	std::cout << vector_int2[0] << std::endl;
	std::cout << vector_int2[1] << std::endl;
	std::cout << vector_int2[2] << std::endl;
	std::cout << vector_int2[3] << std::endl;
	std::cout << vector_int2[4] << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << vector_int[0] << std::endl;
	std::cout << vector_int[1] << std::endl;
	std::cout << vector_int[2] << std::endl;
	std::cout << vector_int[3] << std::endl;
	std::cout << vector_int[4] << std::endl;
	vector_int2.push_back(10);
	std::cout << "vector_int address, size and capacity: " << &vector_int << " | " << vector_int.size() << " | " << vector_int.capacity() << std::endl;
	std::cout << "vector_int2 address, size and capacity: " << &vector_int2 << " | " << vector_int2.size() << " | " << vector_int2.capacity() << std::endl;

	vector_int2.push_back(20);
	vector_int.push_back(30);
	vector_int.push_back(40);
	vector_int.push_back(50);
	vector_int.push_back(60);
	vector_int2.push_back(70);
	vector_int2.push_back(80);
	vector_int.push_back(90);
	vector_int.push_back(10);
	vector_int2[5] = 5;
	int sum = 0;
	std::cout << "vector_int address, size and capacity: " << &vector_int << " | " << vector_int.size() << " | " << vector_int.capacity() << std::endl;
	std::cout << "vector_int2 address, size and capacity: " << &vector_int2 << " | " << vector_int2.size() << " | " << vector_int2.capacity() << std::endl;
	std::cout << "***************** Copy assignment ********************" << std::endl;
	vector_int2 = vector_int;
	//vector_int2.resize(30, 5);
	std::cout << "vector_int address, size and capacity: " << &vector_int << " | " << vector_int.size() << " | " << vector_int.capacity() << std::endl;
	std::cout << "vector_int2 address, size and capacity: " << &vector_int2 << " | " << vector_int2.size() << " | " << vector_int2.capacity() << std::endl;
	std::cout << "***************** Swap ********************" << std::endl;
	swap(vector_int2, vector_int);
	std::cout << vector_int2[5] << std::endl;
	std::cout << vector_int2[6] << std::endl;
	std::cout << vector_int2[7] << std::endl;
	std::cout << vector_int2[8] << std::endl;
	std::cout << vector_int[5] << std::endl;
	std::cout << vector_int[6] << std::endl;
	std::cout << vector_int[7] << std::endl;
	std::cout << vector_int[8] << std::endl;
	std::cout << "*************************************" << std::endl;
	std::cout << "vector_int address, size and capacity: " << &vector_int << " | " << vector_int.size() << " | " << vector_int.capacity() << std::endl;
	std::cout << "vector_int2 address, size and capacity: " << &vector_int2 << " | " << vector_int2.size() << " | " << vector_int2.capacity() << std::endl;

	std::cout << vector_int2[5] << std::endl;
	std::cout << *(vector_int2.begin() + 5) << std::endl;

/* 	for (int i = 0; i < 10000; i++)
	{
		int access = rand() % 10;
		sum += vector_int[access];
	} */

	std::cout << "********************* is_integral *********************" << std::endl;
	std::cout << std::boolalpha; //to convert 0 to true and 1 to false in cout.
	std::cout << ft::is_integral<float>::value << std::endl;
	std::cout << ft::is_integral<int>::value << std::endl;
	std::cout << ft::is_integral<char>::value << std::endl;
	std::cout << ft::is_integral<bool>::value << std::endl;
	//short int i = 2; // code does not compile if type of i is not integral

	//std::cout << std::boolalpha;
	//std::cout << "i is odd: " << ft::is_odd(i) << std::endl;
	//std::cout << "i is even: " << ft::is_even(i) << std::endl;

	std::cout << " ********************* insert example *********************" << std::endl;
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	std::cout << "0 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "1 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	it = myvector.insert ( it , 201 );
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "2 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	it = myvector.insert ( it , 202 );
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "3 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	it = myvector.insert ( it , 203 );
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "4 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	it = myvector.insert ( it , 204 );

/* 	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end()); */

/* 	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3); */

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;

	std::cout << "should be constant with the same seed: " << sum << std::endl;
	std::cout << std::endl;



	std::cout << "********************* ft::pair test *********************" << std::endl;

	ft::pair<int, int> example = foo(5, 12);
	std::cout << "example.first: " << example.first << std::endl;
	std::cout << "example.second: " << example.second << std::endl;

	std::cout << "********************* ft::pair test end *********************" << std::endl;
	return (0);
}

