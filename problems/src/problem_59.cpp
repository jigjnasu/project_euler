/*
  This is solution for problem 59 (XOR Decryption) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : Oct 26th, 2016
 */

#include "Problem_59.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>

namespace pp = project_euler::problems;

const std::string paragraph_frequent_characters = "(abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 )";

pp::Problem_59::Problem_59() {}

pp::Problem_59::~Problem_59() {}

void pp::Problem_59::sum_of_encrypted_message(const std::string& file) const {
    const std::vector<std::string> keys = m_generate_keys();
    const std::vector<short> message = m_get_encrypted_message(file);

    std::string key;
    int max = 0;
    for (std::size_t i = 0; i < keys.size(); ++i) {
        const int count = m_guess_key(keys[i], message);
        if (count > max) {
            max = count;
            key = keys[i];
        }
    }

    printf("-----------------------------------------------------------------------------\n");
    printf("Sum of the decrypted message == [%d] with key == [%s]\n", m_encrypt_decrypt(key, message), key.c_str());
    printf("-----------------------------------------------------------------------------\n");    
}

std::vector<std::string> pp::Problem_59::m_generate_keys() const {
    std::vector<std::string> keys;
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            for (char c = 'a'; c <= 'z'; ++c) {
                std::string key;
                key.push_back(a);
                key.push_back(b);
                key.push_back(c);                
                keys.push_back(key);
            }
        }
    }

    return keys;
}

std::vector<short> pp::Problem_59::m_get_encrypted_message(const std::string& file) const {
    std::vector<short> message;
    std::ifstream ifs(file.c_str(), std::ofstream::in);
    if (ifs.is_open()) {
        std::string line;
        std::getline(ifs, line);

        std::size_t pos = 0;
        std::size_t delim_pos = line.find(",");

        while (delim_pos != std::string::npos) {
            message.push_back(std::atoi(line.substr(pos, delim_pos - pos).c_str()));
            pos = delim_pos + 1;
            delim_pos = line.find(",", pos);
        }

        message.push_back(std::atoi(line.substr(pos, line.size() - pos).c_str()));
    } else {
        printf("There is an error while opening [%s] file\n", file.c_str());
    }

    ifs.close();
    return message;
}

int pp::Problem_59::m_guess_key(const std::string& key, const std::vector<short>& message) const {
    // Let's try to find out how many characters are found in message
    // from the paragraph_frequent_characters

    int chars_count = 0;
    for (std::size_t i = 0; i < message.size(); ++i) {
        if (paragraph_frequent_characters.find(message[i] ^ key[i % key.size()]) != std::string::npos)
            ++chars_count;
    }

    return chars_count;
}

int pp::Problem_59::m_encrypt_decrypt(const std::string& key, const std::vector<short>& message) const {
    int sum = 0;
    for (std::size_t i = 0; i < message.size(); ++i) {
        printf("%c", message[i] ^ key[i % key.size()]);
        sum += message[i] ^ key[i % key.size()];
    }
    printf("\n");
    return sum;
}
