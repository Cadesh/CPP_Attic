// SMART POINTERS
// @author Cadesh 
// @detail Example to show how smart pointers can release memory when out of scope
// 15 AGO 2018

#include <vector>
#include <iostream>
#include <memory>
#include <string>

using namespace std;
//---------------------------------------------------------------------------
class A {
private:
	std::string desc;
public:
	A(std::string s) : desc(s) { cout << "constructor of object " << desc << endl; };
	~A() { cout << "destructor of object " << desc << endl; };
};
//---------------------------------------------------------------------------
int main()
{
	//first we create a single ptr
	shared_ptr <A> aa(new A("zero"));

	//now we add new objects to a vector
	vector<shared_ptr<A> > vec;
	vec.push_back(shared_ptr<A>(new A("one")));
	vec.push_back(shared_ptr<A>(new A("two")));
	vec.push_back(shared_ptr<A>(new A("three")));
	
	//then we clear the vector and reset the pointer (now try erasing these two lines)
	vec.clear();
	aa.reset();
	//we can delete the clear and reset lines because as smart pointers
	//they will call the destructor and release the memory when going out of scope

	return 0;
}
//---------------------------------------------------------------------------
/* OUTPUT
constructor of object zero
constructor of object one
constructor of object two
constructor of object three
destructor of object one
destructor of object two
destructor of object three
destructor of object zero
*/