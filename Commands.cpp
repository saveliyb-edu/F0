#include "Commands.h"

void commands::insert(Dictionary& dict, std::istream& in, std::ostream& out) {
    std::string key, value;
    in >> key >> value;
    dict.insert(key, value);
}

void commands::find(Dictionary& dict, std::istream& in, std::ostream& out) {
    std::string key;
    in >> key;
    dict.search(key, out);
}

void commands::remove(Dictionary& dict, std::istream& in, std::ostream& out) {
    std::string key;
    in >> key;
    dict.remove(key);
}

void commands::removeValue(Dictionary& dict, std::istream& in, std::ostream& out) {
    std::string key, value;
    in >> key >> value;
    dict.removeValue(key, value);
}

void commands::print(Dictionary& dict, std::ostream& out) {
    out << dict;
}

void commands::printHelp(std::ostream& out, bool flag) {
    if (!flag){
        out << "\n\n";
    }
    out << "\t---------------------------------------------------------------------------------\n";
    out << "\t|Commands:\t\t\t\t\t\t\t\t\t|\n";
    out << "\t|add <key> <word> - inserts a word into the dictionary\t\t\t\t|\n";
    out << "\t|find <key> - finds a word in the dictionary\t\t\t\t\t|\n";
    out << "\t|delete <key> - removes a word from the dictionary\t\t\t\t|\n";
    out << "\t|deleteValue <key> <word> - removes a value from a word in the dictionary\t|\n";
    out << "\t|print - prints the dictionary\t\t\t\t\t\t\t|\n";
    out << "\t|help - prints this help message\t\t\t\t\t\t|\n";
    out << "\t---------------------------------------------------------------------------------\n";
    out << "\n\n";
}