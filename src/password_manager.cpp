#include "password_manager.hpp"
#include "tools.hpp"

#include <iostream>


PasswordManager::PasswordManager() {
    load_from_json();
}

void PasswordManager::create(std::string website_name, std::string uname, std::string upass) {
    upass = hash_text(upass);
    database[website_name].push_back({uname, upass});
    save_to_json();
}

website_data PasswordManager::access(std::string website_name) {
    if (database.find(website_name) != database.end()) {
        std::cout << "Found Credentials: \n";
        return database[website_name];
    }

    std::cout << "No Credentials Found\n";
    return {};
}

bool PasswordManager::verify_password(verification_data v_data) {
    if (database.find(v_data.website_name) != database.end()) {
        // Need to change from vector to unordered_map
        for (auto &web_pass_list: database[v_data.website_name]) {
            if (web_pass_list.first == v_data.credentials.uname) {
                auto temp = hash_text(v_data.credentials.upass);
                if (temp == web_pass_list.second) return true;
                return false;
            }
        }
    }
    return false;
}

hash_data PasswordManager::access_all() {
    return database;
}
