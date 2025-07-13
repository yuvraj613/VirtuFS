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
    std::string cmd, arg;
    iss >> cmd;

    if (cmd == "mkdir") {
        iss >> arg;
        mkdir(arg);
    } else if (cmd == "cd") {
        iss >> arg;
        cd(arg);
    } else if (cmd == "ls") {
        ls();
    } else if (cmd == "pwd") {
        pwd();
    } else {
        std::cout << "Unknown command: " << cmd << std::endl;
    }
}
