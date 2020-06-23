#include <iostream>
#include "FileObject.h"


int main()
{
    std::string command;
    FileObject currentLocation = FileObject();
    for (;;) {
        std::cout << currentLocation.CurrentPath() << ">";
        std::cin >> command;
    }
}

