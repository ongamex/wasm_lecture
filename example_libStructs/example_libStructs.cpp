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
	return v.a + v.b;
}

EMSCRIPTEN_KEEPALIVE float sumFloats(ValuesFloat v) {
	return v.a + v.b;
}

} // extern "C"
