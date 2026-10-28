#include <iostream>
#include "data_type.hpp"
#include "password_manager.hpp"
#include "file_stream.hpp"


int main() {
    PasswordManager helper;
    while (1) {
        int option;
        
        std::cout << "\nSelect Option: ";
        std::cin >> option;

        if (option == 1) {
            std::string website_name, uname, upass;
            std::cin >> website_name >> uname >> upass;
            helper.create(website_name, uname, upass);
            std::cout << "Created Entry for " << website_name << "\n";
        }
        else if (option == 2) {
            std::string website_name;
            std::cin >> website_name;
            auto data = helper.access(website_name);
            for (auto &entry: data) {
                std::cout << entry.first << ": " << entry.second << "\n";
            }
        }
        else if (option == 3) {
            save_to_json(helper);
        }
        else if (option == 4) {
            auto data = load_from_json();
            for (const auto &[web, entry]: data) {
                std::cout << web << " has:\n";
                for (auto &d: entry) {
                    std::cout << d.first << ": " << d.second << "\n";
                }
            }
        }
        else break;
    }

    return 0;
}