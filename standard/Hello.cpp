#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

#define nthreads 4

std::mutex mtx;

void call_from_thread(){
	mtx.lock();
	std::cout << "Hello from " << std::this_thread::get_id() << std::endl;
	mtx.unlock();
}

int main() {

	std::vector<std::thread> mythreads;

	for(int ui=0;ui< nthreads; ui++)
		mythreads.push_back(std::thread(call_from_thread));

	for(int ui=0; ui< nthreads; ui++)
		mythreads[ui].join();

	return 0;
}