#include "FileObject.h"

FileObject::FileObject() {
	currentPath = filesystem::path(filesystem::current_path());
	files = filesystem::directory_iterator(currentPath);
}

std::string FileObject::CurrentPath() {
	return currentPath.string();
}

std::vector<std::string> FileObject::ListOfItems() {
	std::vector<std::string> items = std::vector<std::string>();
	// pushes every item in directory into items
	for (filesystem::path item : files) {
		items.push_back(item.string());
	}
	
	return items;
}

void FileObject::ChangeLocation(std::string newPath) {
	filesystem::path testPath = filesystem::path(newPath);
	if (filesystem::exists(testPath) && testPath.is_absolute()) {
		currentPath = testPath;
	}
	else if (filesystem::exists(testPath)) {
		currentPath = filesystem::path(currentPath.append(testPath));
	}
	files = filesystem::directory_iterator(currentPath);
}

void FileObject::MoveUpDirectory() {
	if (!currentPath.parent_path().empty()) {
		currentPath = currentPath.parent_path();
		files = filesystem::directory_iterator(currentPath);
	}
}

std::string FileObject::MakeDirectory(std::string newDirectory) {
	filesystem::path newDir = filesystem::path(newDirectory);
	if (filesystem::exists(newDir) && newDir.is_absolute()) {
		if (!filesystem::create_directory(newDir)) {
			return "Unable to create directory.";
		}
	}
	else if (filesystem::exists(newDir)) {
		newDir = filesystem::path(currentPath.append(newDir));
		if (!filesystem::create_directory(newDir)) {
			return "Unable to create directory.";
		}
	}
	// no problems, return empty string
	return ""; 
}