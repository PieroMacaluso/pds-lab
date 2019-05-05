//
// Created by pieromack on 03/05/19.
//

#include "StringBuffer.h"

size_t StringBuffer::size() {
    return this->ptr[1];

}

size_t StringBuffer::capacity() {
    return this->ptr[0];
}

void StringBuffer::clear() {
    this->buffer[0] = '\0';
    this->ptr[1] = 0;
}

void StringBuffer::insert(const char *str, size_t pos) {
    size_t insertLen = strlen(str);
    size_t dimSpace = pos + insertLen + 1;
    size_t dimInside = this->size() + insertLen + 1;
    size_t newDim = 0;
    size_t numSpaces = 0;

    // Calcolo nuova dimensione minima necessaria
    if (dimSpace > dimInside) {
        newDim = dimSpace;
        numSpaces = pos - this->size();
    } else newDim = dimInside;

    char *newBuffer = nullptr;
    if (newDim > this->capacity()) {
        // Riallocazione necessaria
        newBuffer = new char[newDim];
        memcpy(newBuffer, this->buffer, this->size());
    } else {
        // Riallocazione non necessaria
        newBuffer = this->buffer;
    }
    // Alloco char* temporaneo
    char *tmp = new char[this->capacity() - pos];
    // Copio prima parte della stringa originale
    memcpy(tmp, newBuffer + pos, this->capacity() - pos);
    // Aggiungo eventuali spazi
    for (int i = this->size(); i < pos; i++) {
        newBuffer[i] = ' ';
    }
    // Copio nuova stringa
    memcpy(newBuffer + pos, str, insertLen);
    // Copio seconda parte della stringa originale
    memcpy(newBuffer + pos + insertLen, tmp, this->capacity() - pos);
    // Dealloco stringa temporanea
    delete[] tmp;
    // Aggiungo terminatore di stringa alla fine
    newBuffer[newDim] = '\0';

    // Aggiorno statistiche StringBuffer
    if (newDim > this->capacity()) {
        delete[] this->buffer;
        this->ptr[0] = newDim;
        this->ptr[1] = newDim - 1;
        this->buffer = newBuffer;
    } else {
        this->ptr[1] = strlen(this->buffer);
    }

}

void StringBuffer::insert(const StringBuffer &sb, size_t pos) {
    this->insert(sb.buffer, pos);

}

void StringBuffer::append(const char *str) {
    this->insert(str, this->size());

}

void StringBuffer::append(const StringBuffer &sb) {
    this->insert(sb.buffer, this->size());
}

const char *StringBuffer::c_str() {
    return this->buffer;
}

void StringBuffer::set(const char *str) {
    size_t strLen = strlen(str);
    size_t newDim = strLen + 1;
    if (newDim > this->capacity()) {
        delete[] this->buffer;
        this->buffer = new char[newDim];
        this->ptr[0] = newDim;
    }
    memcpy(this->buffer, str, strLen);
    this->ptr[1] = strLen;
    this->buffer[strLen] = '\0';
}

void StringBuffer::set(StringBuffer &sb) {
    this->set(sb.buffer);
}
