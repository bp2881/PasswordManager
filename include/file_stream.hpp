#pragma once

#include "password_manager.hpp"
#include "data_type.hpp"


void save_to_json(PasswordManager& obj);
hash_data load_from_json(std::string file_name="data.json");