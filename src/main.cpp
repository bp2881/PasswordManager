#include <iostream>
#include "tools.hpp"
#include "password_manager.hpp"


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
            verification_data verify;
            std::cin >> verify.website_name >> verify.credentials.uname >> verify.credentials.upass;
            if (helper.verify_password(verify)) std::cout << "\nPassword is correct.";
            else std::cout << "\nPassword Failed";
        }
        
        else break;
    }

    return 0;
}