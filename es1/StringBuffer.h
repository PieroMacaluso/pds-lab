//
// Created by pieromack on 03/05/19.
//

#ifndef ES1_STRINGBUFFER_H
#define ES1_STRINGBUFFER_H


#include <cstring>

class StringBuffer {
    int *ptr;
    char *buffer;
public:
    StringBuffer() {
        ptr = new int[2];
        this->ptr[0] = 16;
        this->ptr[1] = 0;
        this->buffer = new char[this->ptr[0]];
        this->buffer[1] = '\0';

    }

    StringBuffer(const char *str) {
        this->ptr = new int[2];
        this->ptr[1] = strlen(str);
        this->ptr[0] = this->ptr[1] + 1;
        this->buffer = new char[this->ptr[0]];
        std::memcpy(this->buffer, str, ptr[1]);
        this->buffer[ptr[1]] = '\0';
    }

    StringBuffer(const char *str, size_t size) {
        this->ptr = new int[2];
        this->ptr[1] = strlen(str);
        this->ptr[0] = size;
        this->buffer = new char[this->ptr[0]];
        std::memcpy(this->buffer, str, ptr[1]);
        this->buffer[ptr[1]] = '\0';
    }

    StringBuffer(const StringBuffer &sb) {
        this->ptr = new int[2];
        memcpy(this->ptr, sb.ptr, 1);
        this->buffer = new char[this->ptr[0]];
        std::memcpy(this->buffer, sb.buffer, ptr[1]);
    }

    ~StringBuffer() {
        delete[] ptr;
        delete[] buffer;
    }

    size_t size();

    size_t capacity();

    void clear();

    void insert(const char *str, size_t pos);

    void insert(const StringBuffer &sb, size_t pos);

    void append(const char *str);

    void append(const StringBuffer &sb);

    const char *c_str();

    void set(const char *str);

    void set(StringBuffer &sb);


    void realloc(size_t i);
};


#endif //ES1_STRINGBUFFER_H
