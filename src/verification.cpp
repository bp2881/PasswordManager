#include "tools.hpp"
#include "password_manager.hpp"

#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>


using json = nlohmann::json;

void PasswordManager::save_to_json() {
    std::ofstream file("data.json");
    json j = access_all();

    if (file.is_open()) {
        file << j.dump(4) << std::endl;
        std::cout << "JSON successfully saved!" << std::endl;
    }
}

void PasswordManager::load_from_json(std::string file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }

    json j;
    file >> j;

    auto restoredMap = j.get<hash_data>();
    database = restoredMap;
}