#ifndef DERIVEDOPTIONS_H
#define DERIVEDOPTIONS_H

#include <Eigen/Core>

#include "BaseOptions.h"

class DerivedOptions : public BaseOptions
{
    public:
        DerivedOptions() : BaseOptions()
        {
        }
    
        void readParameters(const YAMLUser& yaml_user, std::string node_name = "derivedoptions")
        {       
            BaseOptions::readParameters(yaml_user);

            const YAML::Node& node = yaml_user.config_file_[node_name]; 
            string1 = node["string1"].as<std::string>(); 
            std::cout << string1 << std::endl;
            string2 = node["string2"].as<std::string>();
            std::cout << string2 << std::endl;
            vector1[0] = node["vector1"].as<std::vector<double>>().at(0);
            vector1[1] = node["vector1"].as<std::vector<double>>().at(1);
            std::cout << vector1 << std::endl;
            vector2[0] = node["vector2"].as<std::vector<double>>().at(0);
            vector2[1] = node["vector2"].as<std::vector<double>>().at(1);
            std::cout << vector2 << std::endl;
        }

    private:
        std::string string1;
        std::string string2;

        Eigen::Vector2d vector1;
        Eigen::Vector2d vector2;
};

#endif //DERIVEDOPTIONS_H
