#include <iostream>
#include "tools.hpp"
#include "password_manager.hpp"
#include <string>


int main() {
    PasswordManager helper;
    while (1) {
        int option;
        
        std::cout << "\nSelect Option: ";
        if (!(std::cin >> option)) {
            break;
        }
        std::string ms;

        switch (option) {
            case 1: {
                std::cout << "Enter Master Password: ";
                std::cin >> ms;
                auto dict = helper.master_hash_password(ms);
                helper.push_master_pass(dict);
                break;
            }
            case 2: {
                std::cout << "Enter Master Password to check: ";
                std::cin >> ms;
                std::cout << helper.master_verify_password(ms, helper.access_master_pass()) << "\n";
                break;
            }
            default:
                std::cout << "Invalid Option!\n";
                break; 
        }
    }

    return 0;
}