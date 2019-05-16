//
// Created by pieromack on 16/05/19.
//

#include "SharedEditor.h"

// TODO: Restart from here
void SharedEditor::localInsert(int index, char value) {
    int id = std::stoi(std::to_string(_siteId) + std::to_string(_counter++));
    std::vector<int> pos;
    if (index > this->_symbols.size()) {
        for (int i = _symbols.size(); i < index; i++)
            localInsert(i, ' ');
    }
    if (_symbols.empty()) {
        pos.push_back(1);
        pos.push_back(0);
    }
    this->_symbols.insert(index, sym);
    Symbol sym_index = this->_symbols[index];
    Symbol sym_prec = this->_symbols[index - 1];


}

SharedEditor::SharedEditor(NetworkServer &server) : _server(server), _counter(0) {
    this->_siteId = this->_server.connect(this);
}

