#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>


class Dictionary {
private:
    std::map < std::string, std::vector<std::string>> dict;
    std::string tolower(std::string str) const;
    void sort(std::vector<std::string>& vec);
    bool findInNode(const std::string key, const std::string& value) const;
public:
    Dictionary();
    Dictionary(const Dictionary& other);
    Dictionary(Dictionary&& other) noexcept;
    Dictionary& operator=(const Dictionary& other);
    Dictionary& operator=(Dictionary&& other) noexcept;
    ~Dictionary();

    void clear();
    void insert(const std::string& key, const std::string& value);
    void search(const std::string& key, std::ostream& out) const;
    bool find(const std::string& key) const;
    void remove(const std::string& key);
    void removeValue(const std::string& key, const std::string& value);

    friend std::ostream& operator<<(std::ostream& out, const Dictionary& dict);
};

#endif
