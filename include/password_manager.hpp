#pragma once

#include "tools.hpp"

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


class PasswordManager {
private:
    hash_data database;
    void save_to_json();
    void load_from_json(std::string file_name="data.json");
    hash_data access_all();
public:
    PasswordManager();
    void create(std::string website_name, std::string uname, std::string upass);
    website_data access(std::string website_name);
    bool verify_password(verification_data v_data);
};