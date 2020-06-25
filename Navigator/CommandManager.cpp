#include "CommandManager.h"

CommandManager::CommandManager() {
	file = FileObject();
}

std::string CommandManager::EnterCommand(std::string command) {
	if (command.compare("dir") == 0) {
		return EnterCommand_ItemsInDirectory();
	}
	else if (command.compare("pwd") == 0) {
		return EnterCommand_CurrentDirectory();
	}
	else if (command.compare("cd") == 0) {
		std::string dir;
		std::getline(std::cin, dir);
		// Clears leading space from dir so it can be turned into a path
		dir = dir.substr(1, dir.length());
		return EnterCommand_ChangeDirectory(dir);
	}
	else {
		return "Unrecognized command.";
	}
}

std::string CommandManager::EnterCommand_CurrentDirectory() {
	return file.CurrentPath() + ">";
};

std::string CommandManager::EnterCommand_ItemsInDirectory() {
	std::vector<std::string> items = file.ListOfItems();
	std::string returned = "";
	// Appends number in directory and every item in directory to returned
	for (int i = 0; i < items.size(); i++) {
		returned.append(std::to_string(i + 1) + ": " + items[i] + "\n");
	}
	returned.append("\n" + EnterCommand_CurrentDirectory());
	return returned;
};

std::string CommandManager::EnterCommand_ChangeDirectory(std::string newPath) {
	if (newPath._Equal("..")) {
		file.MoveUpDirectory();
	}
	else { 
		file.ChangeLocation(newPath);
	}
	return EnterCommand_CurrentDirectory();
};




