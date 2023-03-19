#include <emscripten/emscripten.h>
#include <math.h>

struct SumInput {
	float a;
	float b;
};

struct QuadraticEquationResult {
	int numResults = 0;
	float x1 = 0.f;
	float x2 = 0.f;
};

const char* g_helloString = "Hello from C++!";

extern "C" {

EMSCRIPTEN_KEEPALIVE const char* getHelloString() {
	return g_helloString;
}

/// Computes the sum of @a and @b.
/// This is an example of a very simple function that we could call
/// from JavaScript.
EMSCRIPTEN_KEEPALIVE float sumSimpleArgs(float a, float b) {
	float res = a + b;
	return res;
}

/// Computes the sum of the givn arguments by @v.
/// The purpouse is to show how to call a function that takes a struct as an input from JavaScript.
/// To call this from JavaScript we need to pass a pointer to the mory that stores v.
EMSCRIPTEN_KEEPALIVE float sumStructByValue(SumInput v) {
	float result = v.a + v.b;
	return result;
}

/// Computes the sum of the givn arguments by @v.
/// The purpouse is to show how to call a function that takes a struct by reference as an input from JavaScript.
/// Spoiler, it is actually the same as @sumStructByValue.
/// To call this from JavaScript we need to pass a pointer to the mory that stores v.
EMSCRIPTEN_KEEPALIVE float sumStructByRef(SumInput& v) {
	float result = v.a + v.b;
	return result;
}

/// Computes the sum of the givn arguments by @v.
/// The purpouse is to show how to call a function that takes a struct by pointer as an input from JavaScript.
/// Spoiler, it is actually the same as @sumStructByValue.
/// To call this from JavaScript we need to pass a pointer to the mory that stores v.
EMSCRIPTEN_KEEPALIVE float sumStructByPtr(SumInput* v) {
	float result = v->a + v->b;
	return result;
}

/// Find the real results of a quadratic equation.
/// The purpose is to deomstrate how to handle functions that return structs.
///
/// Note:
/// Technically in C, we cannot "export" functions that return structs, but Emscripten allows it
/// and it works normally as with MSVC.
EMSCRIPTEN_KEEPALIVE QuadraticEquationResult solveQuadraticEq(float a, float b, float c) {	
	const float d = b*b - 4*a*c;
	
	if(d < 0.f) {
		return QuadraticEquationResult();
	}
	
	if(fabsf(d) < 1e-6f) {
		QuadraticEquationResult result;
		result.numResults = 1;
		result.x1 = -b / 2 * a;
		result.x2 = result.x1;
		
		return result;
	}
	
	const float d_sqrt = sqrtf(d);
	QuadraticEquationResult result;
	result.numResults = 2;
	result.x1 = (-b + d_sqrt) / 2 * a;
	result.x2 = (-b - d_sqrt) / 2 * a;
	
	return result;
}

} // extern "C"
