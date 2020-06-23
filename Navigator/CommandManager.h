#pragma once
#include <string>
#include <stack>
#include "FileObject.h"

class CommandManager {
private:
	std::stack<std::string> recentCommands;
	FileObject file;
public:
	CommandManager();
	std::string EnterCommand(std::string);
	std::string EnterCommand_CurrentDirectory();
	std::string EnterCommand_PrintWorkingDirectory();
	std::string EnterCommand_ChangeDirectory(std::string);
};