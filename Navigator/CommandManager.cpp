#include "CommandManager.h"

CommandManager::CommandManager() {
	file = FileObject();
}

std::string CommandManager::EnterCommand(std::string command) {
	if (command.compare("pwd") == 0) {
		return EnterCommand_PrintWorkingDirectory();
	}
	else if (command.compare("dir") == 0) {
		return EnterCommand_CurrentDirectory();
	}
	else {
		return "Unrecognized command.";
	}
}

std::string CommandManager::EnterCommand_CurrentDirectory() {
	return file.CurrentPath() + ">";
};
std::string CommandManager::EnterCommand_PrintWorkingDirectory() {
	std::vector<std::string> items = file.ListOfItems();
	std::string returned = "";
	for (int i = 0; i < items.size(); i++) {
		returned.append(items[i] + "\n");
	}
	returned.append("\n" + EnterCommand_CurrentDirectory());
	return returned;
};
std::string CommandManager::EnterCommand_ChangeDirectory(std::string) {
	return "";
};


// std::string EnterCommand(std::string);
// std::string EnterCommand_CurrentDirectory();
// std::string EnterCommand_PrintWorkingDirectory();
// std::string EnterCommand_ChangeDirectory(std::string);

