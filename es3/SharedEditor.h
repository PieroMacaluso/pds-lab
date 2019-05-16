//
// Created by pieromack on 16/05/19.
//

#ifndef ES3_SHAREDEDITOR_H
#define ES3_SHAREDEDITOR_H

#include <string>
#include "NetworkServer.h"

class SharedEditor {
private:
    NetworkServer& _server;

    int _siteId;
    std::vector<Symbol> _symbols;
    int _counter;
public:

    explicit SharedEditor(NetworkServer& server);
    void localInsert(int index, char value);
    void localErase(int index);
    void process(const Message &m);
    std::string to_string();

};


#endif //ES3_SHAREDEDITOR_H
