#include "common.hpp"

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	std::cout << "1111111111111111111111111111111111111111" << std::endl;
	printSize(vct);
	std::cout << "1111111111111111111111111111111111111111" << std::endl;
	std::cout << "\n\n\n\n\n\n" << std::endl;
	std::cout << "2222222222222222222222222222222222222222" << std::endl;
	printSize(vct_two);
	std::cout << "2222222222222222222222222222222222222222" << std::endl;

	vct_three.assign(vct.begin(), vct.end());
	// std::cout << "Vct begin == " << *(vct_two.begin()) << "vct end is: " << *(vct_two.end() - 1) << "\n";
	// std::cerr << "Vct begin == " << *(vct_two.begin()) << "vct end is: " << *(vct_two.end() - 1) << "\n";
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	// std::cout << "\t### After assign(): ###" << std::endl;


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

	return (0);
}
