#pragma once
#include <string>
#include <stack>
#include "FileObject.h"
#include <iostream>

class CommandManager {
private:
	// TO BE IMPLEMENTED
	std::stack<std::string> recentCommands;
	FileObject file;
public:
	// Initializes file with default constructor
	CommandManager();
	// Calls a command function based on what is called, returning any relevant responses to command
	// or returns a notice that an invalid command was entered
	std::string EnterCommand(std::string command);
	// Returns the name of the current directory as a std::String
	std::string EnterCommand_CurrentDirectory();
	// Returns the items in the current directory as a std::string
	std::string EnterCommand_ItemsInDirectory();
	// Sets file to point to the directory given in dir, can either be absolute or relative
	// Returns a string of the absolute value of the new path, assuming it is valid
	// Otherwise, it returns the current path, and a notice that the command failed
	std::string EnterCommand_ChangeDirectory(std::string newPath);
	// Creates a new directory at the value of newDirectory, can either be absolute or relative
	// Does not switch selected path to the directory
	// Returns the current path, as well as an error if the new directory is invalid
	std::string EnterCommand_MakeDirectory(std::string newDirectory);
};