#ifndef __PERSISTANCE_H
#define __PERSISTANCE_H

#include <string>
#include <fstream>

class Persistance {
private:
    std::ofstream *_file;
    std::string _path;

public:
    Persistance(const std::string &);
    ~Persistance();
    
    virtual void save() = 0;

};

#endif
