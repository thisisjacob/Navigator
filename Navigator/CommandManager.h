#pragma once
#include <string>
#include <stack>
#include "FileObject.h"

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
	std::string EnterCommand(std::string);
	// Returns the name of the current directory as a std::String
	std::string EnterCommand_CurrentDirectory();
	// Returns the items in the current directory as a std::string
	std::string EnterCommand_ItemsInDirectory();
	// NOT IMPLEMENTED YET
	std::string EnterCommand_ChangeDirectory(std::string);
};