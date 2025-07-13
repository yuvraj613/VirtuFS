#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <map>

struct Node {
    std::string name;
    std::map<std::string, Node*> children;
    Node* parent;

    Node(std::string name, Node* parent = nullptr)
        : name(name), parent(parent) {}
};

class FileSystem {
private:
    Node* root;
    Node* current;

    void deleteTree(Node* node);

public:
    FileSystem();
    ~FileSystem();

    void mkdir(const std::string& name);
    void cd(const std::string& name);
    void ls() const;
    void pwd() const;
    void printTree(Node* node = nullptr, int level = 0) const;
    void processCommand(const std::string& command);
};

#endif
