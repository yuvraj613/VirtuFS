#include <iostream>
#include <string>
#include "FileSystem.h"

int main() {
    FileSystem fs;
    std::string command;

    while (std::getline(std::cin, command)) {
        if (command.empty()) continue;

        std::cout << "> " << command << std::endl;

        fs.processCommand(command);

        std::cout << "\nCurrent File System:\n";
        fs.printTree();
        std::cout << "-----------------------------\n";
    }

    return 0;
}
