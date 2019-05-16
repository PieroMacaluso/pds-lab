//
// Created by pieromack on 16/05/19.
//

#include <iostream>
#include "File.h"

File::File(std::string name, uintmax_t size) : Base(name), size(size) {

}

int File::mType() const {
    return FILE;
}

void File::ls(int indent) const {
    std::cout << std::string(indent, '\t') << "    " << this->name << " " << this->size << std::endl;
}

uintmax_t File::getSize() const {
    return this->size;
}
