//#include <emscripten/emscripten.h>
//#include <emscripten/bind.h>
#include <emscripten.h>
#include <emscripten/bind.h>

#include <thread>
#include <atomic>
#include <mutex>

int g_counter;
std::mutex g_counterLock;

void threadFn() {
	g_counterLock.lock();
	g_counter += 1;
	g_counterLock.unlock();
}

int cppLauchThreads() {
	std::thread thread1(threadFn);
	std::thread thread2(threadFn);
	std::thread thread3(threadFn);
	std::thread thread4(threadFn);

	std::thread thread5(threadFn);
	std::thread thread6(threadFn);
	std::thread thread7(threadFn);
	std::thread thread8(threadFn);


	return g_counter;
}

/// The is the way with embind to expose function to JavaScript.
EMSCRIPTEN_BINDINGS(a_random_name_here_that_doesnt_really_matter_at_all) {
	emscripten::function("cppLauchThreads", &cppLauchThreads);
}