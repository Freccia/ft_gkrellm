
#include "templates.cpp"
#include <iostream>

class Awesome {
public:
	Awesome( int n ) : _n( n ) {}

	int		get() const { return _n; };

	bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); }

private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }


int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;


	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << std::endl;

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl;

	float x = 2.356;
	float y = 2.480;

	::swap( x, y );
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;

	std::cout << std::endl;

	Awesome j(10);
	Awesome k(42);

	::swap( x, y );
	std::cout << "j = " << j << ", k = " << k << std::endl;
	std::cout << "min( j, k ) = " << ::min( j, k ) << std::endl;
	std::cout << "max( j, k ) = " << ::max( j, k ) << std::endl;


/*
	std::cout << std::endl;

//		This does not compile:
	std::cout << "x = " << x << ", a = " << a << std::endl;
	std::cout << "min( x, a ) = " << ::min( x, a ) << std::endl;
	std::cout << "max( x, a ) = " << ::max( x, a ) << std::endl;
*/

	return 0;
}
