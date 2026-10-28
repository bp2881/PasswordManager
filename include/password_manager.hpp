#pragma once

#include "data_type.hpp"

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


class PasswordManager {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> database;

public:
    PasswordManager() = default;
    void create(std::string website_name, std::string uname, std::string upass);
    website_data access(std::string website_name);
    hash_data access_all();
};