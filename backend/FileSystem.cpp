#include "FileSystem.h"
#include <sstream>
#include <iostream>

FileSystem::FileSystem() {
    root = new Node("root");
    current = root;
}

FileSystem::~FileSystem() {
    deleteTree(root);
}

void FileSystem::deleteTree(Node* node) {
    for (auto& child : node->children) {
        deleteTree(child.second);
    }
    delete node;
}

void FileSystem::mkdir(const std::string& name) {
    if (current->children.find(name) == current->children.end()) {
        current->children[name] = new Node(name, current);
        std::cout << "Directory created: " << name << std::endl;
    } else {
        std::cout << "Directory already exists: " << name << std::endl;
    }
}

void FileSystem::cd(const std::string& name) {
    if (name == "..") {
        if (current->parent) {
            current = current->parent;
            std::cout << "Moved to parent directory.\n";
        } else {
            std::cout << "Already at root directory.\n";
        }
    } else if (current->children.find(name) != current->children.end()) {
        current = current->children[name];
        std::cout << "Changed directory to: " << name << std::endl;
    } else {
        std::cout << "Directory not found: " << name << std::endl;
    }
}

void FileSystem::ls() const {
    for (const auto& child : current->children) {
        std::cout << child.first << std::endl;
    }
}

void FileSystem::pwd() const {
    Node* temp = current;
    std::string path = "";

    while (temp != nullptr) {
        path = "/" + temp->name + path;
        temp = temp->parent;
    }

    std::cout << path << std::endl;
}

void FileSystem::rm(const std::string& name) {
    auto it = current->children.find(name);
    if (it == current->children.end()) {
        std::cout << "Error: '" << name << "' not found.\n";
        return;
    }

    Node* target = it->second;

    if (!target->children.empty()) {
        std::cout << "Error: Directory '" << name << "' is not empty.\n";
        return;
    }

    delete target;
    current->children.erase(it);
    std::cout << "Deleted: " << name << std::endl;
}

void FileSystem::printTree(Node* node, int level) const {
    if (!node) node = root;

    for (int i = 0; i < level; i++) std::cout << "  ";
    std::cout << "|-- " << node->name << std::endl;

    for (auto& child : node->children) {
        printTree(child.second, level + 1);
    }
}

void FileSystem::processCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    std::string arg;
    std::getline(iss, arg);

    // Trim leading/trailing whitespace
    arg.erase(0, arg.find_first_not_of(" \t\r\n"));
    arg.erase(arg.find_last_not_of(" \t\r\n") + 1);

    if (cmd == "mkdir") {
        mkdir(arg);
    } else if (cmd == "cd") {
        cd(arg);
    } else if (cmd == "touch") {
        mkdir(arg); // Simulate files as directories or adjust as needed
    } else if (cmd == "rm") {
        rm(arg);
    } else if (cmd == "ls") {
        ls();
    } else if (cmd == "pwd") {
        pwd();
    } else {
        std::cout << "Unknown command: " << cmd << std::endl;
    }
}
