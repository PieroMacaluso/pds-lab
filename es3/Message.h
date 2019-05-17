#include <utility>

//
// Created by pieromack on 16/05/19.
//

#ifndef ES3_MESSAGE_H
#define ES3_MESSAGE_H

#include <string>
#include "Symbol.h"


class Message {
private:
    int action;
    int siteId;
    Symbol s;
public:
    enum action {
        INSERT, ERASE
    };

    explicit Message(int action, int siteId, const Symbol &s) : action(action), siteId(siteId), s(s) {};

    int getAction() const;

    int getSiteId() const;

    Symbol getSymbol() const;
};


#endif //ES3_MESSAGE_H
