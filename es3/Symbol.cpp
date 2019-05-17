//
// Created by pieromack on 16/05/19.
//

#include "Symbol.h"

std::vector<int> Symbol::getPos() {
    return this->pos;
}

int Symbol::getIdSymbol() {
    return idSymbol;
}

const char Symbol::getChar() {
    return c;
}

int Symbol::getIdEditor() {
    return idEditor;
}

int Symbol::getId() {
    return std::stoi(std::to_string(idEditor) + std::to_string(idSymbol));

}
