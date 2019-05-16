//
// Created by pieromack on 16/05/19.
//

#ifndef ES2_DIRECTORY_H
#define ES2_DIRECTORY_H


#include "Base.h"
#include "File.h"
#include <memory>
#include <map>
#include <string>

class Directory : public Base {
public:
    int mType() const override;
    void ls(int indent=0) const override;
    static std::shared_ptr<Directory> getRoot();
    std::shared_ptr<Directory> addDirectory(const std::string& name);
    std::shared_ptr<File> addFile(const std::string &name, uintmax_t size);
    std::shared_ptr<Base> get(std::string name);
    std::shared_ptr<Directory> getDir(std::string name);
    void remove(std::string name);
    std::shared_ptr<File> getFile(std::string name);

    ~Directory()= default;
private:
    std::weak_ptr<Directory> parentDirectory;
    std::weak_ptr<Directory> thisDirectory;
    std::map<std::string, std::shared_ptr<Base>> elements;
    static std::shared_ptr<Directory> root;
protected:

    explicit Directory(std::string name = "", const std::weak_ptr<Directory> &parent = std::shared_ptr<Directory>());
};


#endif //ES2_DIRECTORY_H
