//----------------------------------------------------------------------------
/// @author Cadesh
/// @date 15 AGO 2018
/// @brief STL accumulate 
//----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

//this example was modified from the original in https://en.cppreference.com/w/cpp/algorithm/accumulate
//----------------------------------------------------------------------------------------
int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5 };

	// adds all numbers in vector. Note the regular version and the one with Lambda 
	int sum = std::accumulate(v.begin(), v.end(), 0);
	int su2 = std::accumulate(v.begin(), v.end(), 0, [](int a, int b) { return a + b; });

	// multiplies all numbers in vector. Note the regular version and the one with Lambda
	int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
	int produc2 = std::accumulate(v.begin(), v.end(), 1, [](int a, int b) { return a * b; });

	//using accumulate to generate a string, note the initial element 
	std::string s = std::accumulate(std::next(v.begin()), v.end(),
		std::to_string(v[0]), // start with first element
		[](std::string a, int b) { return a + '-' + std::to_string(b); }
	);

	std::cout << "sum: " << sum << '\n'
		<< "sum2: " << su2 << '\n'
		<< "product: " << product << '\n'
		<< "product: " << produc2 << '\n'
		<< "dash-separated string: " << s << '\n';

	return 0;
}
//------------------------------------------------------------------------------------------
