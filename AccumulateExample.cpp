// Various methos to use accumulate
// Cadesh modified from http://www.cplusplus.com/reference/numeric/accumulate/
// 12 AGO 2018

#include <iostream>     // std::cout
#include <functional>   // std::minus
#include <numeric>      // std::accumulate
#include <vector>

int myFunction(int x, int y) { return x + 2*y; } //the sequence in the accumulate is 0 + 2*10 -> 20 + 2*20 -> 60 + 2*30 -> 120

auto myLambda = [](int x, int y) { return x + y; };

struct myClass {                                 //only works with structs (not class)
	int operator()(int x, int y) { return x + y; }
};

int main() {
	int init = 0;
	myClass myObject;
	std::vector <int> numbers = { 10,20,30 };

	std::cout << "using default accumulate: ";
	std::cout << std::accumulate(numbers.begin(), numbers.end(), init); 
	std::cout << '\n';

	std::cout << "using functional's minus: ";
	std::cout << std::accumulate(numbers.begin(), numbers.end(), init, std::minus<int>());
	std::cout << '\n';

	std::cout << "using custom function: ";
	std::cout << std::accumulate(numbers.begin(), numbers.end(), init, myFunction);
	std::cout << '\n';

	std::cout << "using custom object: ";
	std::cout << std::accumulate(numbers.begin(), numbers.end(), init, myObject);
	std::cout << '\n';

	std::cout << "using lambda function: ";
	std::cout << std::accumulate(numbers.begin(), numbers.end(), init, myLambda);
	std::cout << '\n';

	return 0;
}

/* OUTPUT
using default accumulate: 60
using functional's minus: -60
using custom function: 120
using custom object: 60
using lambda function: 60
*/