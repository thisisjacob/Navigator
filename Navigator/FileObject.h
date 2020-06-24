#pragma once
// standard filesystem not functioning
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include <vector>
using namespace std::experimental;


class FileObject {
private:
	filesystem::path currentPath;
	filesystem::directory_iterator files;
public:
	// initializes the stored path with the current directory
	FileObject();
	// returns a std::string holding the path to the current directory
	std::string CurrentPath();
	// returns the list of items in the current directory
	std::vector<std::string> ListOfItems();
	// sets newPath as the current path
	void ChangeLocation(filesystem::path newPath);	
	// Moves up one item in the file path, as long as it would not create an empty path
	void MoveUpDirectory();
};
