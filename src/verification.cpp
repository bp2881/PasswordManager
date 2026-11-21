#include "tools.hpp"
#include "password_manager.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <nlohmann/json.hpp>
#include <sodium.h>


using json = nlohmann::json;

void to_json(json& j, const UserPasswordRecord& record) {
    j = {
        {"salt", record.salt},
        {"hash", record.hash},
        {"opslimit", record.opslimit},
        {"memlimit", record.memlimit},
        {"parallelism", record.parallelism}
    };
}

void from_json(const json& j, UserPasswordRecord& record) {
    j.at("salt").get_to(record.salt);
    j.at("hash").get_to(record.hash);
    j.at("opslimit").get_to(record.opslimit);
    j.at("memlimit").get_to(record.memlimit);
    j.at("parallelism").get_to(record.parallelism);
}

namespace {
    void initialize_sodium() {
        if (sodium_init() < 0) {
            throw std::runtime_error("libsodium initialization failed.");
        }
    }
}

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

void PasswordManager::load_master_pass_from_json(std::string file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }

    json j;
    file >> j;

    master_pass = j.get<UserPasswordRecord>();
}

void PasswordManager::save_master_pass_to_json() {
    std::ofstream file("master_pass.json");
    json j = master_pass;

    if (file.is_open()) {
        file << j.dump(4) << std::endl;
        std::cout << "Master password successfully saved!" << std::endl;
    }
}


// Argon2id Encryption
UserPasswordRecord PasswordManager::master_hash_password(const std::string& m_password, unsigned long long ops, size_t mem, unsigned int lanes) {
    initialize_sodium();

    UserPasswordRecord record;
    record.opslimit = ops;
    record.memlimit = mem;
    record.parallelism = lanes;

    record.salt.resize(crypto_pwhash_SALTBYTES);
    record.hash.resize(32); // 256-bit o/p

    randombytes_buf(record.salt.data(), record.salt.size());

    int result = crypto_pwhash(
        record.hash.data(),
        record.hash.size(),
        m_password.c_str(),
        m_password.length(),
        record.salt.data(),
        record.opslimit,
        record.memlimit,
        crypto_pwhash_ALG_ARGON2ID13
    );

    if (result != 0) {
        throw std::runtime_error("Hashing failed.");
    }
    return record;
}

bool PasswordManager::master_verify_password(const std::string& password, const UserPasswordRecord& record) {
    initialize_sodium();

    std::vector<unsigned char> computed_hash(record.hash.size());

    int result = crypto_pwhash(
        computed_hash.data(),
        computed_hash.size(),
        password.c_str(),
        password.length(),
        record.salt.data(),
        record.opslimit,
        record.memlimit,
        crypto_pwhash_ALG_ARGON2ID13
    );

    if (result != 0) {
        return false;
    }

    return sodium_memcmp(computed_hash.data(), record.hash.data(), record.hash.size()) == 0;
}