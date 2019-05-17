//
// Created by pieromack on 16/05/19.
//

#include "Message.h"


int Message::getAction() const {
    return action;
}

Symbol Message::getSymbol() const {
    return s;
}

int Message::getSiteId() const {
    return siteId;
}
