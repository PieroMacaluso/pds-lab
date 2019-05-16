//
// Created by pieromack on 16/05/19.
//

#ifndef ES2_FILE_H
#define ES2_FILE_H


#include "Base.h"

class File : public Base {
public:
    explicit File(std::string name = "", uintmax_t size=0);
    int mType() const override;
    void ls(int indent=0) const override;
    uintmax_t getSize() const;
    ~File()= default;
private:
    uintmax_t size;
};


#endif //ES2_FILE_H
