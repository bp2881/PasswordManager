#pragma once

#include "tools.hpp"

#include <string>
#include <sodium.h>


class PasswordManager {
private:
    hash_data database;
    UserPasswordRecord master_pass;

    void save_to_json();
    void load_from_json(std::string file_name="data.json");
    void load_master_pass_from_json(std::string file_name="master_pass.json");
    void save_master_pass_to_json();
    hash_data access_all();
public:
    PasswordManager();
    void create(std::string website_name, std::string uname, std::string upass);
    website_data access(std::string website_name);
    UserPasswordRecord master_hash_password(const std::string& m_password, unsigned long long ops = crypto_pwhash_OPSLIMIT_SENSITIVE, size_t mem = 1024ULL * 1024ULL * 1024ULL, unsigned int lanes = 1);
    bool master_verify_password(const std::string& password, const UserPasswordRecord& record);
    bool verify_password(verification_data v_data);


    void push_master_pass(UserPasswordRecord& m_pass);
    UserPasswordRecord access_master_pass();
};