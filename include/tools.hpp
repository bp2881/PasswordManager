#pragma once

#include <unordered_map>
#include <vector>
#include <string>

// Storing datatypes
typedef std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> hash_data;
typedef std::vector<std::pair<std::string, std::string>> website_data;

typedef struct CRED {
    std::string uname;
    std::string upass;
} CRED;

typedef struct UserPasswordRecord {
    std::vector<unsigned char> salt;
    std::vector<unsigned char> hash;
    unsigned long long opslimit; // no. of iterations
    size_t memlimit; // Mem to be used
    unsigned int parallelism; // No. of Threads
} UserPasswordRecord;

typedef struct verification_data {
    std::string website_name;
    CRED credentials;
} verification_data;
