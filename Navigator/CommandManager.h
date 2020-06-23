#pragma once
#include <string>
#include "FileObject.h"

class CommandManager {
private:
	std::string lastCommand;
	FileObject file;
public:
	CommandManager(std::string);
	std::string EnterCommand();
};