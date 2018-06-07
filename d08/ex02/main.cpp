
#include "mutantstack.cpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "Stack size is : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);
	mstack.push(0);
	mstack.push(-12);
	mstack.push(89);
	mstack.push(100);

	std::cout << "---------------------------------------" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "Begin: " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "End: " << *std::prev(ite) << std::endl;
	std::cout << "Iterate:" << std::endl;
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Copy constructor" << std::endl;
	MutantStack<int> Cc(mstack);
	std::cout << "Top: " << Cc.top() << std::endl;

	std::cout << "---------------------------------------" << std::endl;
	MutantStack<int> sq;
	std::cout << "Operator = " << std::endl;
	sq.push(11);
	sq = mstack;
	std::cout << "Top: " << sq.top() << std::endl;

	std::cout << "---------------------------------------" << std::endl;
	std::stack<int> s(mstack);

	std::cout << "Stack size is : " << mstack.size() << std::endl;
	return 0;
}
