#include "Dictionary.h"
#include <iostream>
#include <iterator>

std::string Dictionary::tolower(std::string str) const {
    std::transform(str.begin(), str.end(), str.begin(), std::tolower);
    return str;
}


void Dictionary::sort(std::vector<std::string>& vec) {
    std::sort(vec.begin(), vec.end());
}

bool Dictionary::findInNode(const std::string key, const std::string& value) const {
    std::string key_ = tolower(key);

    if (dict.find(key_) != dict.end()) {
        return std::find(dict.at(key_).cbegin(), dict.at(key_).cend(), tolower(value)) != dict.at(key_).cend();
    }
    throw std::invalid_argument("Word not found!");
}

Dictionary::Dictionary() {}

Dictionary::Dictionary(const Dictionary& other) {
    dict = other.dict;
}

Dictionary::Dictionary(Dictionary&& other) noexcept {
    dict = std::move(other.dict);
    other.dict.clear();
}

Dictionary& Dictionary::operator=(const Dictionary& other) {
    dict = other.dict;
    return *this;
}

Dictionary& Dictionary::operator=(Dictionary&& other) noexcept {
    dict = std::move(other.dict);
    other.dict.clear();
    return *this;
}

Dictionary::~Dictionary() {
    clear();
}

void Dictionary::clear() {
    dict.clear();
}

void Dictionary::insert(const std::string& key, const std::string& value) {
    std::string key_ = tolower(key);
    std::string value_ = tolower(value);

    if (find(key_)) {
        if (findInNode(key_, value_)) {
            return;
        }
    }
    dict[key_].push_back(value_);
    sort(dict[key_]);
}

void Dictionary::search(const std::string& key, std::ostream& out) const {
    std::string key_ = tolower(key);

    if (find(key_)) {
        out << key_ << ": ";
        std::copy(dict.at(key_).cbegin(), dict.at(key_).cend() - 1, std::ostream_iterator<std::string>(out, ", "));
        out << dict.at(key_).back() << "\n";
    }
    else {
        throw std::invalid_argument("Word not found!");
    }
}

bool Dictionary::find(const std::string& key) const {
    return dict.find(tolower(key)) != dict.end();
}

void Dictionary::remove(const std::string& key) {
    if (find(key)) {
        dict.erase(tolower(key));
    }
    else {
        throw std::invalid_argument("Word not found!");
    }
}

void Dictionary::removeValue(const std::string& key, const std::string& value) {
    std::string key_ = tolower(key);
    std::string value_ = tolower(value);

    if (findInNode(key_, value_)) {
        dict.at(key_).erase(std::remove(dict.at(key_).begin(), dict.at(key_).end(), value_), dict.at(key_).end());

        if (dict.at(key_).empty()) {
            dict.erase(key_);
        }
    }
    else {
        throw std::invalid_argument("Word not found!");
    }
}

std::ostream& operator<<(std::ostream& out, const Dictionary& dict) {
    for (const auto& node : dict.dict) {
        out << node.first << "\n";

        std::string indent(node.first.size(), ' ');
        std::string prefix = indent + "L___";

        for (const auto& value : node.second) {
            out << prefix << value << "\n";
        }
    }
    return out;
}
