#include <iostream>
#include "FileObject.h"
#include "CommandManager.h"


int main()
{
    std::string command;
    CommandManager manager = CommandManager();
    std::cout << manager.EnterCommand_CurrentDirectory();
    for (;;) {
        std::cin >> command;
        std::cout << manager.EnterCommand(command);
    }
    return 0;
}

