//
// Created by pieromack on 16/05/19.
//

#include <algorithm>
#include "SharedEditor.h"

void SharedEditor::localInsert(int index, char value) {
    std::vector<int> pos;

    if (index == 0 && this->_symbols.empty()) {
        pos = Utility::fromFloatToPos(0.0);
    } else if (index == 0) {
        float sym_index = Utility::fromPosToFloat(_symbols[index].getPos());
        pos = Utility::fromFloatToPos(sym_index - 1);
    } else if (index >= this->_symbols.size()) {
        for (int i = _symbols.size(); i < index; i++)
            localInsert(i, ' ');
        float sym_index1 = Utility::fromPosToFloat(_symbols[index - 1].getPos());
        pos = Utility::fromFloatToPos(sym_index1 + 1);
    } else {
        float sym_index = Utility::fromPosToFloat(_symbols[index].getPos());
        float sym_index1 = Utility::fromPosToFloat(_symbols[index - 1].getPos());
        pos = Utility::fromFloatToPos((sym_index1 + sym_index) / 2);
    }
    auto it = _symbols.begin();
    for (int i = 0; i < index; ++i) it++;

    Symbol s(value, _siteId, _counter++, pos);
    this->_symbols.insert(it, s);
    Message message(Message::INSERT, this->_siteId, s);
    this->_server.send(message);
}

SharedEditor::SharedEditor(NetworkServer &server) : _server(server), _counter(0) {
    this->_siteId = this->_server.connect(this);
}

void SharedEditor::localErase(int index) {
    Message message(Message::ERASE, this->_siteId, this->_symbols[index]);
    this->_server.send(message);
    auto it = _symbols.begin();
    for (int i = 0; i < index; ++i) it++;
    this->_symbols.erase(it);


}

void SharedEditor::process(const Message &m) {
    if (m.getAction() == Message::INSERT) {
        auto it = _symbols.begin();
        for (; it != _symbols.end(); ++it) {
            if (Utility::fromPosToFloat(it->getPos()) > Utility::fromPosToFloat(m.getSymbol().getPos())) {
                this->_symbols.insert(it, m.getSymbol());
                break;
            }
        }
        if (it == this->_symbols.end()){
            this->_symbols.push_back(m.getSymbol());
        }
    } else {
        for (auto it = _symbols.begin(); it != _symbols.end(); ++it) {
            if (Utility::fromPosToFloat(it->getPos()) >= Utility::fromPosToFloat(m.getSymbol().getPos())) {
                if (it->getId() == m.getSymbol().getId()) {
                    this->_symbols.erase(it);
                    break;
                }
            }
        }
    }

}

std::string SharedEditor::to_string() {
    std::string result;
    for (auto &it : _symbols) {
        result.append(1, it.getChar());
    }
    return result;
}

int SharedEditor::getSiteId() {
    return _siteId;
}

