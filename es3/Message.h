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
    std::string message;
public:
    explicit Message(std::string name): message(std::move(name)){};
    std::string getMessage();

};


#endif //ES3_MESSAGE_H
