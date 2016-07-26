#ifndef DERIVEDOPTIONS_H
#define DERIVEDOPTIONS_H

#include <Eigen/Core>

#include "BaseOptions.h"

class DerivedOptions : public BaseOptions
{
    public:
        DerivedOptions(const YAMLUser& yaml_user) : BaseOptions(yaml_user)
        {
            readParameters("derivedoptions", yaml_user);
        }
    
    private: 
        void readParameters(std::string node_name, const YAMLUser& yaml_user)
        {       
            const YAML::Node& node = yaml_user.config_file_[node_name]; 
            string1 = node["string1"].as<std::string>(); 
            std::cout << string1 << std::endl;
            string2 = node["string2"].as<std::string>();
            std::cout << string2 << std::endl;
        }

        std::string string1;
        std::string string2;

        //Eigen::Vector2d vector1;
        //Eigen::Vector2d vector2;
        //Eigen::Vector2d vector3;
};

#endif //DERIVEDOPTIONS_H
