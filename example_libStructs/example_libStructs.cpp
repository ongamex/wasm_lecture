#include <emscripten/emscripten.h>
#include <cstdlib>

struct Values {
	int a;
	int b;
};

struct ValuesFloat {
	float a;
	float b;
};
extern "C" {

EMSCRIPTEN_KEEPALIVE int sum(Values v) {
	int res = v.a + v.b;
	return res;
}

EMSCRIPTEN_KEEPALIVE float sumFloats(ValuesFloat v) {
	float result = v.a + v.b;
	return result;
}

} // extern "C"
