
#include "templates.cpp"
#include <iostream>

template <typename T>
T	test_templ(T x) {
	std::cout << "templ(" << x << ")" << std::endl;
	return x;
}

std::string		test_str(std::string str) {
	std::cout << "str(" << str << ")" << std::endl;
	return str;
}

int				test_biz(std::string str) {
	std::cout << "biz(" << str << ")" << std::endl;
	return str.length();
}

int		main( void )
{
	std::string arr[4] = {"Blue", "Red", "Orange", "Yellow"};
	size_t	size = 4;

	::iter_ter(arr, size, &test_templ);
	::iter_ter(arr, size, &test_str);
	::iter_bis(arr, size, &test_biz);
	std::cout << "arr: " << arr << std::endl;
	return 0;
}
