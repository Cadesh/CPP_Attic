/*
  @brief Examples of Bind 
  @author Cadesh
  @date 15 AGO 2018
*/

// bind example
#include <iostream>     // std::cout
#include <functional>   // std::bind

//----------------------------------------------------------------
class divClass  //a class function
{
public:
	int a, b;
	divClass() {  };
	int myFunction () { return (a / b); }
};
//----------------------------------------------------------------
//----------------------------------------------------------------
class divFunctor
{
public:
	divFunctor() {  };
	int operator () (double x, double y) { //note the parameters by value
		return x / y; 
	}
};
//----------------------------------------------------------------
//----------------------------------------------------------------
double divFunction (double x, double y) {  //a regular function
	return x / y; 
}
//----------------------------------------------------------------

int main() {

	int a = 10;
	int b = 2;

	//binding with regular functions
	auto bFunction = std::bind(divFunction, a,b);     
	std::cout << "bind regular function: "<< bFunction() << '\n';                         

	//binding with functor (function-objects)
	auto bFunctor = std::bind(divFunctor(), a, b);
	std::cout << "bind functor: " << bFunctor() << '\n';

	//binding class function with parameters by reference
	divClass f;
	f.a = a; f.b = b;
	auto bParamFunctor = std::bind( &divClass::myFunction, std::ref(f));  //note the std::ref
	std::cout << "bind class function by reference: " << bParamFunctor() << '\n';

	return 0;
}