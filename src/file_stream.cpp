#include "file_stream.hpp"
#include "data_type.hpp"

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void save_to_json(PasswordManager &obj) {
    std::ofstream file("data.json");
    json j = obj.access_all();

    if (file.is_open()) {
        file << j.dump(4) << std::endl;
        std::cout << "JSON successfully saved!" << std::endl;
    }
}

hash_data load_from_json(std::string file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return {};
    }

    json j;
    file >> j;

    auto restoredMap = j.get<hash_data>();

    return restoredMap;
}