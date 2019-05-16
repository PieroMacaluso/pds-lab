#include <utility>

//
// Created by pieromack on 07/05/19.
//

#include "Base.h"

std::string Base::getName() const {
    return this->name;
}

Base::Base(std::string name) {
    this->name = std::move(name);
}
