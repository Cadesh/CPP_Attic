
// 3 styles to create a for loop C++ 17
// Cadesh
// 12 AGO 2018

#include <vector>
#include <iostream>
//------------------------------------------------------------------------------------
int main() {

	std::vector <std::vector<int>> vec { {10, 11, 12} , {20, 21, 22} , {30, 31, 32} };

	///-------------------------------------------------
	// traditional style
	///-------------------------------------------------
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			std::cout << vec[i][j] << " ";
		}
	}
	///-------------------------------------------------
	std::cout << std::endl;

	///-------------------------------------------------
	// for range style
	///-------------------------------------------------
	for (auto row : vec) {
		for (auto col : row) {
			std::cout << col << " ";
		}
	}
	///-------------------------------------------------
	std::cout << std::endl;

	///-------------------------------------------------
	//iterator style
	///-------------------------------------------------
	std::vector< std::vector<int> >::iterator row;
	std::vector<int>::iterator col;

	for (row = vec.begin(); row != vec.end(); row++) {
		for (col = row->begin(); col != row->end(); col++) {
			
			std::cout << *col << " ";
		}
	}
	///-------------------------------------------------

	return 0;
}
//-------------------------------------------------------------------------