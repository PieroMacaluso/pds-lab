//
// Created by pieromack on 16/05/19.
//

#include <algorithm>
#include "NetworkServer.h"
#include "SharedEditor.h"


int NetworkServer::connect(SharedEditor *sharedEditor) {
    this->sharedEditors.push_back(sharedEditor);
    return this->id++;
}

void NetworkServer::disconnect(SharedEditor *sharedEditor) {
    auto it = std::find(this->sharedEditors.begin(), this->sharedEditors.end(), sharedEditor);
    if (it != this->sharedEditors.end()) {
        this->sharedEditors.erase(it);
    }
}

void NetworkServer::send(const Message &m) {
    this->messageQueue.push_back(m);
}

void NetworkServer::dispatchMessages() {
    while (!this->messageQueue.empty()) {
        Message m = this->messageQueue.front();
        for (auto &editor:sharedEditors) {
            if (m.getSiteId() != editor->getSiteId())
                editor->process(m);
        }
        this->messageQueue.pop_front();


    }
}

NetworkServer::NetworkServer() : id(0) {}



