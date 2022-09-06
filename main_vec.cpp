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
	#include "stack.hpp"
	#include <iostream>
	#include <sstream>
	// #include <iterator>
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
	// start here of subfunctions
	// outputTitle(">First function call test");

	// ft::vector<int> vec_insert;
	// ft::vector<int>::iterator ve_it;
	// ft::vector<int>::iterator ve_it_end;

	// ve_it = vec_insert.begin();
	// ve_it_end = vec_insert.end();

	// vec_insert.push_back(1);
	// vec_insert.push_back(2);
	// vec_insert.push_back(3);
	// vec_insert.push_back(4);
	// vec_insert.push_back(5);
	// vec_insert.push_back(6);
	// vec_insert.push_back(7);

	// std::cout << "\nvec_insert contains:";
	// for (unsigned i=0; i< vec_insert.size(); ++i)
	// 	std::cout << ' ' << vec_insert[i];
	// std::cout << '\n';

	// std::cout << "Before insert size is: " << vec_insert.size() << " and capacity is: " << vec_insert.capacity() << "\n\n";
	// ve_it_end = vec_insert.end();
	// vec_insert.insert(ve_it_end, 8);
	// ve_it_end = vec_insert.end();
	// vec_insert.insert(vec_insert.end(), 8);
	// ve_it_end = vec_insert.end();
	// vec_insert.insert(vec_insert.end(), 9);
	

	// std::cout << "vec_insert contains:";
	// for (unsigned i=0; i<vec_insert.size(); ++i)
	// 	std::cout << ' ' << vec_insert[i];
	// std::cout << '\n';

	// std::cout << "After insert size is: " << vec_insert.size() << " and capacity is: " << vec_insert.capacity() << "\n\n";

	// outputTitle(">Second Function Call Test");

	// ft::vector<int> c1;
    // ft::vector<int> c2;

    // c1.push_back(1);
	// c1.push_back(2);
	// c1.push_back(3);
	// c1.push_back(4);
	// c1.push_back(5);
	// c1.push_back(6);
	// c1.push_back(7);
	
	// c2.push_back(1);
	// c2.push_back(2);
	// c2.push_back(3);
	// c2.push_back(4);
	// c2.push_back(5);
	// c2.push_back(6);
	// c2.push_back(7);
	// c2.push_back(8);
	// c2.push_back(9);
	
    // print(1, c1);

    // print(2, c2);
    
    // ft::vector<int>::iterator vec_insert_it = c1.begin() + 3;

	// std::cout << "Before insert size is: " << c1.size() << " and capacity is: " << c1.capacity() << "\n\n";
    // c1.insert(vec_insert_it, c2.begin(), c2.end());
	// print(3, c1);
	
	// end here of subfunctions

	// std::cout << "test c1[8] size is: " << c1[8] << " and capacity is: " << c1.capacity() << "\n\n";
	// std::cout << "test c1[9] is: " << c1[9] << " and capacity is: " << c1.capacity() << "\n\n";
	// std::cout << "test c1[10] is: " << c1[10] << " and capacity is: " << c1.capacity() << "\n\n";
	// std::cout << "test c1[11] is: " << c1[11] << " and capacity is: " << c1.capacity() << "\n\n";

	outputTitle(">Insert Testing");

	// ft::vector<int> vect10(10);
	// ft::vector<int> vect11;
	// ft::vector<int> vect12;

	// for (unsigned long int i = 0; i < vect10.size(); ++i)
		// vect10[i] = (vect10.size() - i) * 3;
	// print(1, vect10);

	// ft::vector<int>::iterator vect11_it = vect11.end();

	// vect11.insert(vect11_it, 42); // First function call(p) and sfc1
	/* from C11 to C20 not falied test case */ //vect11.insert(vect11.begin(), vect11.begin() + 2, 21); // Third function call(p)
	// print(2, vect11);

	
	// vect11.insert(vect11.end() - 2, 42); // First function call(p) and sfc2
	// print(3, vect11);

	//?? 2 and 84 are ints vect11.insert(vect11.end(), 2, 84); // Third function call(p)
	// print(4, vect11);

	// // vect11.resize(4);
	// // print(5, vect11);

	// ?? check for subfcntions test when everything works vect11.insert(vect11.begin() + 2, vect10.begin(), vect10.end()); // Third function call(p) and sfc2
	// vect10.clear();
	// print(6, vect11);

	// print(7, vect10);

	// for (int i = 0; i < 5; ++i)
		// vect12.insert(vect12.end(), i); // First function call(p) and sfc1
	// vect12.insert(vect12.begin() + 1, 2, 111); // Third function call(p)
	// print(8, vect12);

	// ft::vector<int> vect14;
	// vect14.push_back(1);
	// std::cout << "Size1 is: " << vect14.size() << std::endl;
	// vect14.push_back(2);
	// std::cout << "Size2 is: " << vect14.size() << std::endl;
	// vect14.push_back(3);
	// std::cout << "Size3 is: " << vect14.size() << std::endl;
	// vect14.push_back(4);
	// std::cout << "Size4 of vec14 before insert is: " << vect14.size() << " and a capacity is: " << vect14.capacity() << "\n\n";
	
	
	// ft::vector<int>::iterator vect14_it = vect14.begin() + 2;
	// std::cout << "\nvector it + 2 = " << *(vect14_it) << "\n";
	// ft::vector<int>::iterator vect_it = vect14.begin();
	// ft::vector<int>::iterator vect_it_end1 = vect14.insert(vect_it + 2, 5);
	// vect14.insert(vect_it + 2, 5);
	// std::cout << "return value is: " << *vect_it_end1 << "\n";
	// std::cout << "Size5 of vec14 after insert is: " << vect14.size() << " and a capacity is: " << vect14.capacity() << "\n\n";

	// vect14.push_back(6);
	// vect14.push_back(7);

	// vect14.insert(vect14.end(), 5);
	// vect14.insert(vect14.end(), 54);

	// print(9, vect14);
	// std::cout << "Size6 of vec14 after insert is: " << vect14.size() << " and a capacity is: " << vect14.capacity() << "\n\n";
	// std::cout << "vect14[6] is: " << vect14[6] << "\n"; 
	// std::cout << "vect14[5] is: " << vect14[5] << "\n"; 
	// std::cout << "vect14[4] is: " << vect14[4] << "\n"; 
	
	//if
	/*ft::vector<int> v1(10);

	v1.insert(v1.begin()  , 1);
	v1.insert(v1.begin()+ 1  , 1);
	v1.insert(v1.begin() + 2, 2);
	v1.insert(v1.begin() + 3, 3);
	v1.insert(v1.begin() + 4, 4);
	v1.insert(v1.begin() + 5, 5);
	print(1, v1);
	std::cout << "v1 size is: " << v1.size() << " and a capacity is: " << v1.capacity() << " before insert \n\n";
	*/
	//if segfault
	//ft::vector<int> vct101(10);
	/*
	ft::vector<int> vct2;
	vct2.insert(vct2.end(), 42);
	print(102, vct2);
*/
	/*for (unsigned long int i = 0; i < vct101.size(); ++i)
		vct101[i] = (vct101.size() - i) * 3;
	print(101, vct101);

	 vct2.insert(vct2.end(), 42);
	 print(102, vct2);
	 std::cout << "vct2 size is: " << vct2.size() << " and a capacity is: " << vct2.capacity() << " after insert \n\n";
	*/
	// v1.push_back(2);
	// v1.push_back(3);
	// v1.push_back(4);
	// v1.push_back(5);
	// v1.push_back(6);
	// v1.push_back(7);

	// v2.push_back(1);
	// v2.push_back(2);
	// v2.push_back(3);
	// v2.push_back(4);
	// v2.push_back(5);
	// v2.push_back(6);
	// v2.push_back(7);
	// v2.push_back(8);

	//else statement(size is not correct, try to check ths out)
	
	ft::vector<int> v1(5);
	ft::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	std::cout << "v1 size is: " << v1.size() << " and a capacity is: " << v1.capacity() << " before insert \n\n";
	print(10, v1);

	v1.insert(v1.begin() + 2, 20000);
	print(11, v1);

	std::cout << "v1 size is: " << v1.size() << " and a capacity is: " << v1.capacity() << " after insert \n\n";
	std::cout << "v1[0] is: " << v1[0] << "\n";
	std::cout << "v1[1] is: " << v1[1] << "\n";
	std::cout << "v1[2] is: " << v1[2] << "\n";
	std::cout << "v1[3] is: " << v1[3] << "\n";
	std::cout << "v1[4] is: " << v1[4] << "\n";
	std::cout << "v1[5] is: " << v1[5] << "\n";
	std::cout << "v1[6] is: " << v1[6] << "\n";
	
	std::cout << "v1 size is: " << v1.size() << " and a capacity is: " << v1.capacity() << " after insert \n\n";
	
	// std::copy(v1.rbegin(), v1.rend(), v2.begin());
	print(12, v1);
	// v1.insert(vct2.begin(), 2, 21);
	// v1.insert(v1.end() - 2, 42);
	// print(11, v1);
	// int arr[] = { 1, 2, 3, 4 ,5 ,7 };
    

	// ft::vector<int> vect(5);	
	// print(12, vect);
	// vect.push_back(1);
	// vect.push_back(2);
	// vect.push_back(3);
	// vect.push_back(4);
	// std::cout << "v1 size is: " << vect.size() << " and a capacity is: " << vect.capacity() << " before insert \n\n";
	// std::cout << "vect[0] is: " << vect[0] << "\n";
	// std::cout << "vect[1] is: " << vect[1] << "\n";
	// std::cout << "vect[2] is: " << vect[2] << "\n";
	// std::cout << "vect[3] is: " << vect[3] << "\n";
	// std::cout << "vect[4] is: " << vect[4] << "\n";
	// std::cout << "vect[5] is: " << vect[5] << "\n";
	// std::cout << "vect[6] is: " << vect[6] << "\n";
	// std::cout << "vect[7] is: " << vect[7] << "\n";
	
	// vect.insert(vect.begin() + 2, 20000);
	// print(13, vect);

	outputTitle("Testing the insert 3rd insert function");
	ft::vector<int> vect5;
	vect5.insert(vect5.begin(), 1);
	vect5.insert(vect5.begin() + 1, 2);
	vect5.insert(vect5.begin() + 2, 3);
	vect5.insert(vect5.begin() + 3, 4);
	vect5.insert(vect5.begin() + 4, 5);
	vect5.insert(vect5.begin() + 5, 6);
	vect5.insert(vect5.begin() + 6, 7);
	
	ft::vector<int> vect6;
	vect6.insert(vect6.begin(), 1);
	vect6.insert(vect6.begin() + 1, 2);
	vect6.insert(vect6.begin() + 2, 3);
	vect6.insert(vect6.begin() + 3, 4);
	vect6.insert(vect6.begin() + 4, 5);
	vect6.insert(vect6.begin() + 5, 6);
	vect6.insert(vect6.begin() + 6, 7);
	vect6.insert(vect6.begin() + 7, 8);

	std::cout << "vect6 is : ";
	print(14, vect5);
	std::cout << "vect7 is : ";
	print(16, vect6);

	ft::vector<int>::iterator vec_insert_it = vect5.begin() + 3;

	std::cout << "Before insert vect5 size is: " << vect5.size() << " and capacity is: " << vect5.capacity() << "\n\n";
	std::cout << "Before insert vect6 size is: " << vect6.size() << " and capacity is: " << vect6.capacity() << "\n\n";
    vect5.insert(vec_insert_it, vect6.begin(), vect6.end());
	std::cout << "After insert vec5 + vec6 = ";
	print(17, vect5);
	vect6.insert(vect6.begin(), 2);
	print(18, vect6);
	std::cout << "After insert vect5 size is: " << vect5.size() << " and capacity is: " << vect5.capacity() << "\n\n";
	std::cout << "After insert vect6 size is: " << vect6.size() << " and capacity is: " << vect6.capacity() << "\n\n";
    
	std::cout << "vect5 is : " << *(vect5.begin()) << "\n";

	
	outputTitle("Testing the insert 2nd insert function");
	vect6.insert(vect6.begin(), 2, 21);
	print(19, vect6);

	vect6.insert(vect6.end() - 2, 42);
	print(20, vect6);

	vect6.insert(vect6.end(), 2, 84);
	print(21, vect6);
	ft::vector<int>::iterator vec6_end_it = vect6.insert(vect6.end(), 42);
	// vect6.insert(vect6.end(), 2, 84);
	print(22, vect6);
	std::cout << "return value is: " << *vec6_end_it << "\n";
	
	outputTitle("Testing the bidirectional iterator");

	ft::vector<int> lst;
	ft::vector<int>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ft::vector<int> vct(lst.begin(), lst.end());
	print(23, vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	print(24, vct);

	outputTitle("Testing stack container");

	ft::stack<int> mystack;
	for (int i = 0; i < 5; ++i)
	{
		mystack.push(i);
	}

	std::cout << "Mystack size is: " << mystack.size() << "\n";
	mystack.pop();
	std::cout << "Mystack size after pop is: " << mystack.size() << "\n";

	std::cout << "Mystack top is: " << mystack.top() << "\n";

	ft::stack<int> mystack1;
	
	for (int i = 0; i < 5; ++i)
	{
		mystack1.push(i);
	}

	ft::stack<int> mystack2;

	for (int i = 6; i < 11; ++i)
	{
		mystack2.push(i);
	}

	std::cout << "Mystack1 size is: " << mystack1.size() << "and last value is: " << mystack1.top() << "\n";
	std::cout << "Mystack2 size is: " << mystack2.size() << "and last value is: " << mystack2.top() << "\n";


	std::cout << "OOA before " << mystack1.top() << "\n";

	mystack1 = mystack2;

	std::cout << "OOA after " << mystack1.top() << "\n";
	
	return (0);

}