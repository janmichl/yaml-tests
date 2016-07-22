#include <iostream>
#include "yaml-cpp/yaml.h"

int main()
{

    YAML::Node config = YAML::LoadFile("config.yaml");

    for(YAML::const_iterator it=config.begin(); it != config.end(); ++it)
    {
        std::cout << it->first.as<std::string>()                     << std::endl;
        std::cout << it->second["integer-property"].as<int>()        << std::endl; 
        std::cout << it->second["boolean-property"].as<bool>()       << std::endl; 
        std::cout << it->second["string-property"].as<std::string>() << std::endl; 
    }		

    return 0;	
}
