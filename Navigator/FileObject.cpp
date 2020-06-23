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
	int i = 0;
	for (filesystem::path item : files) {
		i++;
		items.push_back(i + ": " + item.string());
	}
	
	return items;
}

void FileObject::ChangeLocation(filesystem::path newPath) {
	currentPath = newPath;
	files = filesystem::directory_iterator(currentPath);
}

void FileObject::ChangeLocation(std::string command) {
	if (command._Equal("..")) {

	}
}