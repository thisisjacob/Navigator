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
	// TODO: currently creates list of items from current directory, even after changing directories via cd abspath
	for (filesystem::path item : files) {
		items.push_back(item.string());
	}
	
	return items;
}

void FileObject::ChangeLocation(std::string newPath) {
	filesystem::path testPath = filesystem::path(newPath);
	if (filesystem::exists(testPath) && testPath.is_absolute()) {
		currentPath = testPath;
		files = filesystem::directory_iterator(currentPath);
	}
	// else if for relative path
}

void FileObject::MoveUpDirectory() {
	if (!currentPath.parent_path().empty()) {
		currentPath = currentPath.parent_path();
		files = filesystem::directory_iterator(currentPath);
	}
}