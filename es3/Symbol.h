#include <utility>

//
// Created by pieromack on 16/05/19.
//

#ifndef ES3_SYMBOL_H
#define ES3_SYMBOL_H


#include <stdint-gcc.h>
#include <vector>

class Symbol {
private:
    char c;
    int id;
    std::vector<int> pos;
public:
    Symbol(char c, int id, std::vector<int> pos) : c(c), id(id), pos(std::move(pos)) {};

    ~Symbol() = default;


};


#endif //ES3_SYMBOL_H
