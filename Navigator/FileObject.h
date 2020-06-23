#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include <vector>
using namespace std::experimental;


class FileObject {
private:
	filesystem::path currentPath;
	filesystem::directory_iterator files;
public:
	FileObject();
	std::string CurrentPath();
	std::vector<std::string> ListOfItems();
	void ChangeLocation(filesystem::path newPath);
	void ChangeLocation(std::string command);
};
