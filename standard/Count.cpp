#include <iostream>
#include <thread>
#include <vector>

void call_from_thread(){
	std::cout << "Hello from "<< std::this_thread::get_id() << std::endl;
}

int main() {

	std::vector<std::thread> mythreads;

	for(int ui = 0; ui< 4; ui++){
		mythreads.push_back(std::thread(call_from_thread));
	}

	for(int ui = 0; ui< 4; ui++){
		mythreads[ui].join();
	}
	return 0;
}