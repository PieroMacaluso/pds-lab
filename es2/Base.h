//
// Created by pieromack on 07/05/19.
//

#ifndef ES2_BASE_H
#define ES2_BASE_H


#include <string>

class Base {
protected:
    std::string name;

    explicit Base(std::string name);

    ~Base() = default;

    enum type{DIRECTORY, FILE};

public:
    std::string getName() const;

    virtual int mType() const = 0;

    virtual void ls(int indent=0) const = 0;

};


#endif //ES2_BASE_H
