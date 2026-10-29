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
typedef struct verification_data {
    std::string website_name;
    CRED credentials; 
} verification_data;


// Helper Functions

// Hashing Password
std::string hash_text(std::string upass);