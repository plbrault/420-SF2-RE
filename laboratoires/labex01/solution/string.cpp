#include "string.h"

#include <stdexcept>

namespace sim {

    String::String(const char *c_str) {
        size_t count = 0;

        while (c_str[count] != '\0') {
            count++;
        }
        this->_length = count;
        count++;

        this->_copy(c_str);
    }

    String::String(const String &str) {
        size_t count = 0;

        while (str[count] != '\0') {
            count++;
        }
        this->_length = count;
        count++;

        this->_copy(str._str);
    }

    String::String(size_t repetition, char chr) {
        this->_length = repetition;

        if (this->_length == 0) {
            this->_str = new char;
        } else {
            this->_str = new char[this->_length + 1];

            for (size_t i = 0; i < repetition; i++) {
                this->_str[i] = chr;
            }
            this->_str[repetition] = '\0';
        }
    }

    String::~String() {
        this->_delete();
    }

    String &String::operator=(const String &str) {
        if (this == &str) {
            return *this;
        }

        this->_delete();
        this->_copy(str._str);
        return *this;
    }

    String &String::operator=(const char *c_str) {
        this->_delete();
        this->_copy(c_str);
        return *this;
    }

    char &String::operator[](size_t index) {
        if (index <= this->_length) {
            return this->_str[index];
        } else {
            throw std::out_of_range("Index out of range.");
        }
    }

    const char &String::operator[](size_t index) const {
        if (index <= this->_length) {
            return this->_str[index];
        } else {
            throw std::out_of_range("Index out of range.");
        }
    }

    const String &String::operator+(const String &str) {
        size_t oldLength = this->_length;

        size_t newLength = this->_length + str._length + 1;
        char *temp = new char[newLength];

        for (size_t i = 0; i < oldLength; i++) {
            temp[i] = this->_str[i];
        }

        this->_length = newLength;

        for (size_t i = oldLength; i < newLength; i++) {
            temp[i] = str[i - oldLength];
        }

        this->_delete();
        this->_str = temp;
        temp = nullptr;
        return *this;
    }

    size_t String::getLength() const {
        return this->_length;
    }

    void String::_delete() {
        if (this->_str != nullptr) {
            if (this->_length == 0) {
                delete this->_str;
            } else {
                delete [] this->_str;
            }
        }
    }

    void String::_copy(const char *c_str) {
        if (this->_length == 0) {
            this->_str = new char('\0');
        } else {
            this->_str = new char[this->_length + 1];

            for (size_t i = 0; i < this->_length; i++) {
                this->_str[i] = c_str[i];
            }
            this->_str[this->_length] = '\0';
        }
    }

    std::ostream &operator<<(std::ostream &os, const String &str) {
        for (size_t i = 0; i < str._length; i++) {
            os << str._str[i];
        }

        return os;
    }

}