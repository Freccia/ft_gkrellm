
#include "templates.cpp"
#include <iostream>

template <typename T>
void	test_func(T x) {
	std::cout << "f(" << x << ")" << std::endl;
}

int		main( void )
{
//char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	char arr[] = "abcdefghijklmnopqrstuvwxyz0123456789";

	iter(arr, 20, &test_func);
	std::cout << "arr: " << arr << std::endl;
	return 0;
}
