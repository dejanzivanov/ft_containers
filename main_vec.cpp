#include <iostream>
#include <string>
#include <deque>
#include <iomanip>


#if 0 //CREATE A REAL STL EXAMPLE
	//#include <map>
	//#include <stack>
	#include <vector>
	#include <iterator>
	namespace ft = std;
#else
	//#include <map.hpp>
	//#include <stack.hpp>
	#include "vector.hpp"
	#include "utils.hpp"
	#include <iostream>
	#include <sstream>
	#include <iterator>
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

void print(int id, const ft::vector<int>& container)
{
    std::cout << id << ". ";	
	for (unsigned i=0; i<container.size(); ++i)
		std::cout << ' ' << container[i];
	std::cout << '\n';
}

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
	ft::vector<int> vector_int(5, 3);
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
	std::cout << "Int2 5th position: " << vector_int2[5] << std::endl;
	int sum = 0;
	std::cout << "vector_int address, size and capacity: " << &vector_int << " | " << vector_int.size() << " | " << vector_int.capacity() << std::endl;
	std::cout << "vector_int2 address, size and capacity: " << &vector_int2 << " | " << vector_int2.size() << " | " << vector_int2.capacity() << std::endl;
	std::cout << "***************** Copy assignment ********************" << std::endl;
	vector_int2 = vector_int;
	//vector_int2.resize(30, 5);
	std::cout << "vector_int address, size and capacity: " << &vector_int << " | " << vector_int.size() << " | " << vector_int.capacity() << std::endl;
	std::cout << "vector_int2 address, size and capacity: " << &vector_int2 << " | " << vector_int2.size() << " | " << vector_int2.capacity() << std::endl;
	std::cout << "***************** Swap ********************" << std::endl;
	vector_int2[5] = 5;
	std::cout << "Before swap Int2 5th position: " << vector_int2[5] << std::endl;
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

	// std::cout << "********************* is_integral *********************" << std::endl;
	// std::cout << std::boolalpha; //to convert 0 to true and 1 to false in cout.
	// std::cout << ft::is_integral<float>::value << std::endl;
	// std::cout << ft::is_integral<int>::value << std::endl;
	// std::cout << ft::is_integral<char>::value << std::endl;
	// std::cout << ft::is_integral<bool>::value << std::endl;
	//short int i = 2; // code does not compile if type of i is not integral

	//std::cout << std::boolalpha;
	//std::cout << "i is odd: " << ft::is_odd(i) << std::endl;
	//std::cout << "i is even: " << ft::is_even(i) << std::endl;

	std::cout << " ********************* insert example *********************" << std::endl;
	ft::vector<int> myvector;
	ft::vector<int>::iterator it;
	std::cout << "0 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	// it = myvector.insert ( it , 200 );
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "1 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	// it = myvector.insert ( it , 201 );
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "2 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	// it = myvector.insert ( it , 202 );
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "3 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	// it = myvector.insert ( it , 203 );
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "4 myvector address, size and capacity: " << &myvector << " | " << myvector.size() << " | " << myvector.capacity() << std::endl;
	it = myvector.begin();
	// it = myvector.insert ( it , 204 );

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

	std::cout << "********************* RANGE CONSTRUCTOR TEST *********************" << std::endl;



	ft::vector<int> vector_int4(vector_int2.begin(), vector_int2.end());
	std::cout << "Vec[4] is: " << vector_int4[5] << std::endl;

	// ft::vector<float> vector_float5(3.2, 4.5);
	// ft::vector<float> vector_float5(3, 6.2);
	// ft::vector<double> vector_float5(5, 6.2);
	// std::cout << "VecFloat[1] is: " << vector_float5[1] << std::endl;
	// std::cout << "size of VecFloat[1] is: " << vector_float5.size() << std::endl;
	// std::cout << "size of VecFloat5 is: " << vector_float5.size() << std::endl;


	// std::vector<float> myvector(4, 6);
    // for (std::vector<float>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    // {
	// 	std::cout << *it << std::endl;
	// }    




    // std::istringstream str("54 34 5754 344 5 6456 345 0 -1 42 69 55123");
    // std::istream_iterator<int> itt(str);
    // std::istream_iterator<int> ite;
// 
    // std::istream_iterator<int> it2;
    // it2 = itt;
    // std::cout << "first: " << *itt << " " << *it2 << std::endl;
    // ++it;
    // std::cout << "second: " << *itt << " " << *it2 << std::endl;
    // ++it2;
    // std::cout << "third: " << *itt << " " << *it2 << std::endl;
    // for (; it != ite; ++it)
    //     std::cout << *it << std::endl;

	std::cout << "********************* RESERVE TEST PMF *********************" << std::endl;

	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[0] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[1] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[2] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[3] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[4] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[5] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[6] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[7] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[8] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[9] << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[10] << std::endl;
	std::cout << "Size1 before reserve is: " << vector_int4.size() << std::endl;

	vector_int4.pop_back();
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[10] << std::endl;
	std::cout << "Size2 before reserve is: " << vector_int4.size() << std::endl;

	std::cout << "Capacity of: vector_int4 is " << vector_int4.capacity() << std::endl;
	std::cout << "Vec[4] = 30 before reserve change is: " << vector_int4[5] << std::endl;
	std::cout << "Size before reserve is: " << vector_int4.size() << std::endl;
	vector_int4.reserve(100);

	std::cout << "Capacity of: vector_int4 after change is: " << vector_int4.capacity() << std::endl;
	std::cout << "Vec[4] = 30 after reserve change is: " << vector_int4[5] << std::endl;
	std::cout << "Size after reserve is: " << vector_int4.size() << std::endl;

	std::cout << "** CLEAR TEST  **: " << std::endl;

	// std::cout << "** start address  = : " <<  &vector_int4.data_implement.start  << std::endl;
	// std::cout << "** end address    = : " <<  &vector_int4.data_implement.end << std::endl;
	// std::cout << "** finish address =  : " << &vector_int4.data_implement.finish << std::endl;

	vector_int4.clear();

	vector_int4.push_back(1);
	vector_int4.push_back(2);

	std::cout << "Size after clear is: " << vector_int4.size() << std::endl;

	std::cout << "** ERASE TEST  **: " << std::endl;

	ft::vector<int> vec;
	
	for (size_t i = 0; i <= 10; i++)
	{
		vec.push_back(i * 10);
	}

	
	std::cout << "vec contains:";
	for (unsigned i=0; i<vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '\n'; 

	ft::vector<int>::iterator iter = vec.begin();
	
	std::cout << "Erased Value is: " << *(vec.erase(iter + 4, iter + 7)) << std::endl;
	std::cout << "vec size is:" << vec.size() << std::endl;
	// vec.erase(it);

	
	
	
	std::cout << "vec contains:";
	for (unsigned i=0; i<vec.size(); ++i)
		std::cout << ' ' << vec[i];
	std::cout << '\n';

	
	ft::vector<int> vec1(vec.size());

	std::copy(vec.rbegin(), vec.rend(), vec1.begin());

	std::cout << "vec1 contains:";
	for (unsigned i=0; i<vec1.size(); ++i)
		std::cout << ' ' << vec1[i];
	std::cout << '\n';

	std::cout << "***ASSIGN TEST***\n";
	ft::vector<int> vct_one(7);
	ft::vector<int> vct_two(4);
	ft::vector<int> vct_three;
	ft::vector<int> vct_four;

	for (unsigned long int i = 0; i < vct_one.size(); ++i)
		vct_one[i] = (vct_one.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;

	vct_three.assign(vct_one.begin(), vct_one.end());
	vct_one.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);
	vct_four.assign(6, 84);
	vct_one.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);


	

	outputTitle("INSERT");
	outputTitle(">First function call test");

	ft::vector<int> vec_insert;
	ft::vector<int>::iterator ve_it;
	ft::vector<int>::iterator ve_it_end;

	ve_it = vec_insert.begin();
	ve_it_end = vec_insert.end();

	vec_insert.push_back(1);
	vec_insert.push_back(2);
	vec_insert.push_back(3);
	vec_insert.push_back(4);
	vec_insert.push_back(5);
	vec_insert.push_back(6);
	vec_insert.push_back(7);

	std::cout << "\nvec_insert contains:";
	for (unsigned i=0; i< vec_insert.size(); ++i)
		std::cout << ' ' << vec_insert[i];
	std::cout << '\n';

	std::cout << "Before insert size is: " << vec_insert.size() << " and capacity is: " << vec_insert.capacity() << "\n\n";

	vec_insert.insert(ve_it_end, 8);
	ve_it_end = vec_insert.end();
	// vec_insert.insert(vec_insert.end(), 8);
	// vec_insert.insert(vec_insert.end(), 9);
	vec_insert.insert(ve_it_end, 9);

	std::cout << "vec_insert contains:";
	for (unsigned i=0; i<vec_insert.size(); ++i)
		std::cout << ' ' << vec_insert[i];
	std::cout << '\n';

	std::cout << "After insert size is: " << vec_insert.size() << " and capacity is: " << vec_insert.capacity() << "\n\n";

	outputTitle(">Second Function Call Test");

	ft::vector<int> c1;
    ft::vector<int> c2;
    
    c1.push_back(1);
	c1.push_back(2);
	c1.push_back(3);
	c1.push_back(4);
	c1.push_back(5);
	c1.push_back(6);
	c1.push_back(7);
	
	c2.push_back(1);
	c2.push_back(2);
	c2.push_back(3);
	c2.push_back(4);
	c2.push_back(5);
	c2.push_back(6);
	c2.push_back(7);
	c2.push_back(8);
	
    print(1, c1);

    print(2, c2);
    
    ft::vector<int>::iterator vec_insert_it = c1.begin() + 3;

	std::cout << "Before insert size is: " << c1.size() << " and capacity is: " << c1.capacity() << "\n\n";
    c1.insert(vec_insert_it, c2.begin(), c2.end());
	print(3, c1);
	std::cout << "After insert size is: " << c1.size() << " and capacity is: " << c1.capacity() << "\n\n";



	return (0);
}



// erase1            -> erase Nth element, set the finish to Nth element

// erase2(iterators) -> erase everything between 
//Iterator range ? copy all the elements from Nth untill the end