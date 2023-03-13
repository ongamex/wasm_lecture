#include <emscripten/emscripten.h>

int sum_impl(int a, int b) {
	return a + b;
}

extern "C" {
	EMSCRIPTEN_KEEPALIVE int sum(int a, int b) {
		return sum_impl(a, b);
	}
} // extern "C"