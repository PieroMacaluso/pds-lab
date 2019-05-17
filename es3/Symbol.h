#include <utility>
#include <string>

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
    int idEditor;
    int idSymbol;
    std::vector<int> pos;
public:

    Symbol(char c, int idEditor, int idSymbol, std::vector<int> pos) :
            c(c), idEditor(idEditor), idSymbol(idSymbol), pos(std::move(pos)) {};

    std::vector<int> getPos();

    int getId();

    int getIdEditor();

    int getIdSymbol();

    const char getChar();

    ~Symbol() = default;
};


#endif //ES3_SYMBOL_H
