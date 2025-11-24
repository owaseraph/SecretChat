#ifndef ENCYPT_HPP
#define ENCYPT_HPP

#include <string>
#include <sstream>
#include <vector>


class Base64{
    public:
        static std::string Encode(const std::string &in){
            std::string out;
            int val=0;
            int valb=-6;

            for(unsigned char a : in){
                val = (val<<8)+a;
                valb += 8;

                while(valb>=0){
                    out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
                    valb -= 6;
                }
            }

            if(valb>-6){
                out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
            }
            while(out.size()%4){
                out.push_back('=');
            }
            return out;
        }

        static std::string Decode(const std::string &in){
            std::string out;
            std::vector<int> T(256,-1);

            for(int i=0; i<64; i++){
                T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
            }

            int val=0;
            int valb=-8;

            for(unsigned char a : in){
                if(T[a] == -1) break;
                val = (val<<6)+T[a];
                valb += 6;

                if(valb>=0){
                    out.push_back(char((val>>valb)&0xFF));
                    valb -= 8;
                }
            }
            return out;
        }
};


#endif // ENCYPT_HPP

