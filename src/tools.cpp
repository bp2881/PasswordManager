#include "tools.hpp"

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <openssl/sha.h>

// To be replaced by other Encryption algo which supports retreival of password
std::string hash_text(std::string upass) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, upass.c_str(), upass.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}