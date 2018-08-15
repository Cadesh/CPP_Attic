// @brief Basic use of threads with functors
// @author Cadesh 
// @date 15 AGO 2018

// Thread Class - Function Object
// thread_id_fo.cpp

#include <iostream>
#include <thread>  
#include <vector>
#include <mutex>

using namespace std;

//check the number of available processors
const int NP = std::thread::hardware_concurrency();
std::mutex global_mutex;

//--------------------------------------------------
// Functor - function object
//--------------------------------------------------
/*
This functor just prints the thread info
if you comment the global_mutex lines the program will have a weird output
the lock and unlock are used to make the output run smoothly
*/
class task {
private:
	static int count; // a global counter for the class
public:
	task() {};
	
	static int getCounter() { return count; }

	void operator()(int i) {
		count++;
		
		global_mutex.lock(); //try to run without this line and the unlock line
		//note the this_thread::get_id to get the id of the current thread
		cout << " thread id = " << std::this_thread::get_id() << endl;
		global_mutex.unlock();
	}
};

//--------------------------------------------------
int task::count = 0; //initializes the static counter to 0

int main() {

	cout << "This machine has: " << NP << " processors" << endl;

	//------------------------------------------------
	// create a vector of not-joinable threads
	std::vector<std::thread> threads;
	//------------------------------------------------
	// launch execution of each thread and add to the vector
	for (int i = 0; i < NP; i++)
		threads.push_back(std::thread(task(), i));
	//------------------------------------------------
	// synchronize their execution here
	for (auto& th : threads)
		th.join();
	//-------------------------------------------------
	cout << "The counter is " << task::getCounter() << endl;  //will be equal to the number of processors NP

	return 0;
}
//---------------------------------------------------

// the result will be a sequence of broken messages as the threads are run in different moments