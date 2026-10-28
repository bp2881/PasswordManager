#include "data_type.hpp"
#include "password_manager.hpp"

#include <iostream>


void PasswordManager::create(std::string website_name, std::string uname, std::string upass) {
    database[website_name].push_back({uname, upass});
}

website_data PasswordManager::access(std::string website_name) {
    if (database.find(website_name) != database.end()) {
        std::cout << "Found Credentials: \n";
        return database[website_name];
    }

    std::cout << "No Credentials Found\n";
    return {};
}

hash_data PasswordManager::access_all() {
    return database;
}
