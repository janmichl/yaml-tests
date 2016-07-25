#ifndef WALKOPTIONS_H
#define WALKOPTIONS_H

#include "YAMLUser.h"

class WalkOptions : public YAMLUser
{
    public:
        WalkOptions(std::string filename) : YAMLUser(filename)
        {
        };
    
        void readParameters(std::string nodename)
        {       
            const YAML::Node& node = YAMLUser::config_file_[nodename]; 
            x = node["integer-property"].as<int>(); 
            std::cout << x << std::endl;
            y = node["boolean-property"].as<bool>();
            std::cout << y << std::endl;
            z = node["string-property"].as<std::string>();
            std::cout << z << std::endl;
        }
    
    private:
        int x;
        bool y;
        std::string z;
};

#endif //WALKOPTIONS_H
