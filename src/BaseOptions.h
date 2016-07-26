#ifndef BASEOPTIONS_H
#define BASEOPTIONS_H

#include "YAMLUser.h"

class BaseOptions
{
    public:
        BaseOptions(const YAMLUser& yaml_user)
        {
            readParameters("baseoptions", yaml_user);
        }
  
    private:
        void readParameters(std::string nodename, const YAMLUser& yaml_user)
        {       
            const YAML::Node& node = yaml_user.config_file_[nodename]; 
            uint1 = node["uint1"].as<unsigned int>(); 
            std::cout << uint1 << std::endl;
            uint2 = node["uint2"].as<unsigned int>(); 
            std::cout << uint2 << std::endl;
            uint3 = node["uint3"].as<unsigned int>(); 
            std::cout << uint3 << std::endl;
            uint4 = node["uint4"].as<unsigned int>(); 
            std::cout << uint4 << std::endl;
            uint5 = node["uint5"].as<unsigned int>(); 
            std::cout << uint5 << std::endl;
            uint6 = node["uint6"].as<unsigned int>(); 
            std::cout << uint6 << std::endl;
            uint7 = node["uint7"].as<unsigned int>(); 
            std::cout << uint7 << std::endl;
            uint8 = node["uint8"].as<unsigned int>(); 
            std::cout << uint8 << std::endl;
        }

        unsigned int uint1;
        unsigned int uint2;
        unsigned int uint3;
        unsigned int uint4;
        unsigned int uint5;
        unsigned int uint6;
        unsigned int uint7;
        unsigned int uint8;
};

#endif //BASEOPTIONS_H
