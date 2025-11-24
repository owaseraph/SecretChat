#include <iostream>
#include "cypher.hpp"
#include "clear.hpp"
#include "copy.hpp"



void createMenu(){
    std::string password;


    std::cout << "==========================================\n";
    std::cout << "   SECURE CHAT ENCRYPTION TOOL (C++)      \n";
    std::cout << "==========================================\n";
    std::cout << "Enter shared password: ";
    getline(std::cin, password);


    if(password.empty()){
        std::cout<<"Password cannot be empty! \n";
        return;
    }

    Cypher cypher(password);

    clearScreen();

    while(true){
        std::cout << "\n--- Secure Channel Active [" << password.length() << "-char key] ---\n";
        std::cout << "1. Encrypt Message (for sending)\n";
        std::cout << "2. Decrypt Message (received)\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin>>choice;
        std::cin.ignore();
        switch(choice){
            case 1:{
                std::cout<<"\nEnter message to encrypt: \n";
                std::string msg;
                getline(std::cin,msg);


                if(!msg.empty()){
                    std::string encrypted = cypher.Encrypt(msg);
                    copyToClipboard(encrypted);
                }
                break;
            }
            case 2:{
                std::cout<<"\nEnter message to decrypt: \n";
                std::string msg;
                getline(std::cin,msg);


                if(!msg.empty()){
                    std::string encrypted = cypher.Decrypt(msg);
                    std::cout<<"The message: "<<encrypted<<"\n";
                }
                break;
            }
            case 3:
                exit(1);
                break;
            default:
                std::cout<<"Invalid selection!\n";
                break;
        }

    }

}