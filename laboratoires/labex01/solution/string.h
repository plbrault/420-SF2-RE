#ifndef __STRING_H
#define __STRING_H

#include <cstddef>
#include <sstream>

namespace sim {

class String {
private:
    char *_str;
    size_t _length;

    void _delete();
    void _copy(const char *);
    void _count(const char *);

public:
    String() : String("") { };
    String(const char *);
    String(const String &);
    String(size_t, char);
    ~String();

    String &operator=(const String &);
    String &operator=(const char *);
    char &operator[](size_t);
    const char &operator[](size_t) const;
    
    String &operator+=(const String &);
    const String &operator+(const String &);
    String &operator+=(const char *);
    const String &operator+(const char *);
    
    size_t getLength() const;

    friend std::ostream &operator<<(std::ostream &, const String &);
};

}

#endif
