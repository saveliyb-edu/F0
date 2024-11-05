#ifndef COMMANDS_H
#define COMMANDS_H

#include "Dictionary.h"
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <cctype>


namespace commands {
    void insert(Dictionary& dict, std::istream& in, std::ostream& out);
    void find(Dictionary& dict, std::istream& in, std::ostream& out);
    void remove(Dictionary& dict, std::istream& in, std::ostream& out);
    void removeValue(Dictionary& dict, std::istream& in, std::ostream& out);
    void print(Dictionary& dict, std::ostream& out);
    void printHelp(std::ostream& out, bool flag);
};


#endif
