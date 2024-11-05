#include <iostream>
#include <limits>
#include <functional>
#include <algorithm>
#include "Dictionary.h"
#include "Commands.h"

int main() {
    Dictionary dict;
    std::string command;

    std::map<std::string, std::function<void(std::istream&, std::ostream&)>> cmds;
    {
        cmds["add"] = std::bind(commands::insert, std::ref(dict), std::placeholders::_1, std::placeholders::_2);
        cmds["find"] = std::bind(commands::find, std::ref(dict), std::placeholders::_1, std::placeholders::_2);
        cmds["delete"] = std::bind(commands::remove, std::ref(dict), std::placeholders::_1, std::placeholders::_2);
        cmds["deletevalue"] = std::bind(commands::removeValue, std::ref(dict), std::placeholders::_1, std::placeholders::_2);
        cmds["print"] = std::bind(commands::print, std::ref(dict), std::placeholders::_2);
        cmds["help"] = std::bind(commands::printHelp, std::placeholders::_2, false);
    }

    commands::printHelp(std::cout, true);

    while (true) {
        std::string command;
        std::cin >> command;
        if (std::cin.eof()) {
            break;
        }
        try {
            std::transform(command.begin(), command.end(), command.begin(), std::tolower);
            cmds.at(command)(std::cin, std::cout);
        }
        catch (const std::out_of_range& ex) {
            std::cout << "ERROR! " << ex.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const std::invalid_argument& ex) {
            std::cout << "ERROR! " << ex.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return 0;
}
