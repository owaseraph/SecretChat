#ifndef CYPHER_HPP
#define CYPHER_HPP

#include <string>
#include <sstream>
#include <vector>
#include "encypt.hpp"


class Cypher{
    private:
        std::string key;
        std::string Process(const std::string &input){
            if(key.empty()) return input;
            std::string output = input;
            for(size_t i=0; i<input.length(); i++){
                //complex XOR operation with key rotation
                char k = key[i % key.length()];
                char rotation = (i*13) % 255;
                output[i] = input[i] ^ k ^ rotation;
            }
            return output;
        }

    public:
        Cypher(std::string k) : key(k) {};

        std::string Encrypt(const std::string &plainText){
            std::string processed = Process(plainText);
            return Base64::Encode(processed);
        }

        std::string Decrypt(std::string cyphertext){

            std::string decoded = Base64::Decode(cyphertext);
            return Process(decoded);
        }

};

#endif // CYPHER_HPP