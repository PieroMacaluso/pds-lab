#include <memory>

#include <utility>
#include <algorithm>
#include <iostream>
#include <stdexcept>

//
// Created by pieromack on 16/05/19.
//

#include "Directory.h"

/* Null, because instance will be initialized on demand. */
std::shared_ptr<Directory> Directory::root = nullptr;


std::shared_ptr<Directory> Directory::getRoot() {
    if (root == nullptr) {
        root = std::shared_ptr<Directory>(new Directory("/"));
        root->thisDirectory = root;
    }

    return root;
}

Directory::Directory(std::string name, const std::weak_ptr<Directory> &parent) : Base(std::move(name)) {
    this->parentDirectory = parent;
}

int Directory::mType() const {
    return DIRECTORY;
}

void Directory::ls(int indent) const {
    std::cout << std::string(indent, '\t') << "[+] " << this->name << std::endl;

    for (const auto &element : this->elements)
        element.second->ls(indent + 1);
}

std::shared_ptr<Directory> Directory::addDirectory(const std::string &name) {

    try {
        if (this->elements.find(name) != this->elements.end()) {
            throw std::runtime_error(name + std::string(" directory already exists."));
        }
    } catch (std::runtime_error &ex) {
        std::cerr << "[ERROR] " << ex.what() << std::endl;
        exit(-1);
    }

    std::shared_ptr<Directory> newDirectory = std::shared_ptr<Directory>(new Directory(name, this->thisDirectory));
    newDirectory->thisDirectory = newDirectory;
    this->elements.insert(std::pair{name, newDirectory});
    return newDirectory;
}

std::shared_ptr<File> Directory::addFile(const std::string &name, uintmax_t size) {

    try {
        if (this->elements.find(name) != this->elements.end()) {
            throw std::runtime_error(name + std::string(" file already exists."));
        }
    } catch (std::runtime_error &ex) {
        std::cerr << "[ERROR] " << ex.what() << std::endl;
        exit(-1);
    }

    std::shared_ptr<File> newFile = std::shared_ptr<File>(new File(name, size));
    this->elements.insert(std::pair{name, newFile});
    return newFile;
}

std::shared_ptr<Base> Directory::get(std::string name) {

    if (name == ".." && !this->parentDirectory.expired()) {
        return this->parentDirectory.lock();
    } else if (name == "..") {
        return std::shared_ptr<Base>();
    }

    if (name == "." && !this->thisDirectory.expired()) {
        return this->thisDirectory.lock();
    } else if (name == ".") {
        return std::shared_ptr<Base>();
    }

    auto search = this->elements.find(name);
    if (search == this->elements.end()) {
        return std::shared_ptr<Base>();
    }
    return search->second;


}

std::shared_ptr<Directory> Directory::getDir(std::string name) {
    auto castedPtr = std::dynamic_pointer_cast<Directory>(this->get(name));
    if (castedPtr) {
        return castedPtr;
    } else {
        return std::shared_ptr<Directory>();
    }
}

std::shared_ptr<File> Directory::getFile(std::string name) {
    auto castedPtr = std::dynamic_pointer_cast<File>(this->get(name));
    if (castedPtr) {
        return castedPtr;
    } else {
        return std::shared_ptr<File>();
    }
}

void Directory::remove(std::string name) {
    try {
        if (name == ".." || name == ".") {
            throw std::runtime_error(std::string("Remove of " + name + " forbidden."));
        }
    } catch (std::runtime_error &ex) {
        std::cerr << "[ERROR] " << ex.what() << std::endl;
        exit(-1);
    }


    auto search = this->elements.find(name);
    if (search != this->elements.end()) {
        this->elements.erase(search);
    }
}


