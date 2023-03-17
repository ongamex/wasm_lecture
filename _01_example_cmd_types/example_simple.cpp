#include <iostream>
#include <cstddef>

using namespace std;

int main() {
	
	printf("This is a simple example!\n\n");

	printf("sizeof(void*) = %lu\n", sizeof(void*));
	printf("sizeof(size_t) = %lu\n", sizeof(std::size_t));
	printf("sizeof(uint64_t) = %lu\n", sizeof(std::uint64_t));
	printf("sizeof(long long) = %lu\n", sizeof(long long));
	printf("sizeof(unsigned long long) = %lu\n", sizeof(unsigned long long));
	printf("\n");
	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(char) = %lu\n", sizeof(char));
	printf("sizeof(float) = %lu\n", sizeof(float));
	printf("sizeof(double) = %lu\n", sizeof(double));
	printf("sizeof(uint64_t) = %lu\n", sizeof(std::uint64_t));

	return 0;
}