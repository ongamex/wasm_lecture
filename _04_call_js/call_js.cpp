//#include <emscripten/emscripten.h>
//#include <emscripten/bind.h>
#include <emscripten.h>
#include <emscripten/bind.h>

//-----------------------------------------------------------------
// Our logging to javascript.
//-----------------------------------------------------------------
EM_JS(
	void, chaosLog_invokeJS, (const char* message, int messageLen), 
	{
		// Here we are writing in JavaScript, not C++!
		// This javascript has the same context as our document.
	
		/// UTF8ToString is defined by Emscripten Module.
		/// The type of @message here is number (a pointer) and emscripten
		/// know how to look it up.
		/// https://emscripten.org/docs/api_reference/preamble.js.html

		const messageJSString = UTF8ToString(message, messageLen);
		chaosPrintImpl(messageJSString);
	}
);

/// A function for a bit easier calling of @chaosLog_invokeJS
void chaosLog(const char* msg) {
	chaosLog_invokeJS(msg, strlen(msg));
}

//-----------------------------------------------------------------
// Example 1.
//-----------------------------------------------------------------
void cppHowManyTimesICalledThis() {
	static int numCallsToThisFn = 0;
	numCallsToThisFn += 1;

	char message[512] = { '\0' };
	const int messageSize = sprintf(message, "Hey, you've asked me to say something %d times!", numCallsToThisFn);
	chaosLog(message);
}

//-----------------------------------------------------------------
// Example 2.
//-----------------------------------------------------------------
int getLocalVariablePtr() {
	static int localVariable = 0;

	char message[512] = { '\0' };
	const int messageSize =
		sprintf(message, "getLocalVariablePtr called, localVariable = %d, with address = %d!"
			, localVariable
			, int(&localVariable)
		);

	chaosLog(message);

	return int(&localVariable);
}

//-----------------------------------------------------------------
//
//-----------------------------------------------------------------
int main() {
	chaosLog("C++: main() has been called!");
}

void onModuleLoaded() {
	chaosLog("C++: onModuleLoaded() has been called!");
}

//-----------------------------------------------------------------
// Emscripten bindings:
//-----------------------------------------------------------------

/// The is the way with embind to expose function to JavaScript.
EMSCRIPTEN_BINDINGS(a_random_name_here_that_doesnt_really_matter_at_all) {
	emscripten::function("onModuleLoaded", &onModuleLoaded);
	emscripten::function("cppHowManyTimesICalledThis", &cppHowManyTimesICalledThis);
	emscripten::function("getLocalVariablePtr", &getLocalVariablePtr);
}