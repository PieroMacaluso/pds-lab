//
// Created by pieromack on 16/05/19.
//

#ifndef ES3_NETWORKSERVER_H
#define ES3_NETWORKSERVER_H

#include <vector>

#include <deque>
#include <memory>

#include "Message.h"
#include "Message.h"

class SharedEditor;

class NetworkServer {
private:
    int id;
    std::vector<SharedEditor*> sharedEditors;
    std::deque<Message> messageQueue;
public:
    NetworkServer();
    int connect(SharedEditor * sharedEditor);
    void disconnect(SharedEditor *sharedEditor);
    void send(const Message& m);
    void dispatchMessages();


};


#endif //ES3_NETWORKSERVER_H
