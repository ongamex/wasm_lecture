//#include <emscripten/emscripten.h>
//#include <emscripten/bind.h>
#include <emscripten.h>
#include <emscripten/bind.h>
#include <filesystem>
#include <vector>
#include <string>

struct FSEntry {
	std::string name;
	bool isDir = false;

	std::string getName() const {
		return name;
	}

	bool getIsDir() const {
		return isDir;
	}
};

std::vector<FSEntry> getCurrDirContents() {
	namespace fs = std::filesystem;
	std::vector<FSEntry> result;

	result.emplace_back(FSEntry{"../", true});
	for (const fs::directory_entry& entry : fs::directory_iterator("./")) {
		result.emplace_back(FSEntry{entry.path().filename().string(), entry.is_directory()});
	}
	return result;
}

void enterDirectory(std::string newDir) {
	namespace fs = std::filesystem;
	fs::current_path(newDir);
}

/// The is the way with embind to expose function to JavaScript.
EMSCRIPTEN_BINDINGS(a_random_name_here_that_doesnt_really_matter_at_all) {
	emscripten::class_<FSEntry>("FSEntry")
		.constructor<>()
		.function("getName", &FSEntry::getName)
		.function("getIsDir", &FSEntry::getIsDir)
	;

	emscripten::register_vector<FSEntry>("vectorFSEntry");
	emscripten::function("getCurrDirContents", &getCurrDirContents);
	emscripten::function("enterDirectory", &enterDirectory);
}