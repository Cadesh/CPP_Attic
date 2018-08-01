///--------------------------------------------------------------------
/// @detail ALGORITHM LIBRARY FUNCTIONS EXAMPLE WITH TEMPLATES
/// FOR_EACH and TRANSFORM
/// @date 01 AGO 2018
/// @author Cadesh
///--------------------------------------------------------------------
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

// for more info
// for_each  http://www.cplusplus.com/reference/algorithm/for_each/
// transform http://www.cplusplus.com/reference/algorithm/transform/
//

// Note the function template that receives a method as parameter
//--------------------------------------------------------
template<typename Collection, typename UnaryOp>
Collection for_each(Collection c, UnaryOp op) {
	// Function for_each(InputIterator first, InputIterator last, Function fn)
	std::for_each(c.begin(), c.end(), op);
	return c;
}
 
//--------------------------------------------------------
template<typename Collection, typename UnaryOp>  //NOTE THAT PARAMETERS ARE PASSED BY COPY (NOT REFERENCE)
Collection map(Collection c, UnaryOp op) {
	std::transform(c.begin(), c.end(), c.begin(), op);
	return c;
}

//Note the 4th parameter that receives the result of the function
//OutputIterator transform(InputIterator1 first1, InputIterator1 last1,
//	                       InputIterator2 first2, OutputIterator result,
//                         BinaryOperation binary_op);
//--------------------------------------------------------
template<typename Collection, typename BinaryOp> //NOTE THAT PARAMETERS ARE PASSED BY COPY (NOT REFERENCE)
Collection zip(Collection c1, Collection c2, BinaryOp op) {
	std::transform(c1.begin(), c1.end(), c2.begin(), c1.begin(), op); //the result is placed again in c1
	return c1;
}

//---------------------------------------------------------
int main() {

	std::vector<int> X{ 1,2,3,7 };
	std::vector<int> Y{ 2,3,6,5 };

	auto println = [](const char * msg) {std::cout << msg << std::endl; };

	//echo function just prints an integer
	auto echo = [] (int i) { std::cout << i << std::endl; };  

	println("run for_each");
	for_each(X, echo);   

	println("run map");
	auto mapAddTen = [](int i) {return i + 10; };
	auto mapZ = map(X, mapAddTen);  //X is not changed because it is passed by copy
	for_each(mapZ, echo);

	println("run zip");
	auto zipAdd = [] (int a, int b) { return a + b; };
	auto zipZ = zip(X, Y, zipAdd);
	for_each(zipZ, echo);

	return 0;
}
//---------------------------------------------------------------
/* OUTPUT
run for_each
1
2
3
7
run map
11
12
13
17
run zip
3
5
9
12
*/