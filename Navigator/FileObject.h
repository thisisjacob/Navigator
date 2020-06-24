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
	// converts command to a path, sets path as converted command
	// works based on specific commands
	// .. moves one directory upwards
	// NOTICE:: Not fully implemented yet
	void ChangeLocation(std::string command);
};
