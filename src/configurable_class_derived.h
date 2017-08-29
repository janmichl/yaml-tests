/**
    @file
    @author Jan Michalczyk

    @brief
*/

#pragma once

#include <string>
#include <vector>

#include <Eigen/Core>

#include "configurable_class_base.h"
#include "config_reader.h"

namespace yaml_config
{
    class ConfigurableClassDerived : public ConfigurableClassBase
    {
        public:
            ConfigurableClassDerived(const char* config_file) : ConfigurableClassBase(config_file), config_reader(config_file)
            {
                readParameters("ConfigurableClassDerived");
            }
        

        private:
            void readParameters(const std::string& node_name)
            {      
                config_reader.findNode(node_name);
                config_reader.readScalar("string1", string1);
                std::cout << string1 << std::endl;
                config_reader.readScalar("string2", string2);
                std::cout << string2 << std::endl;
                config_reader.readVector("vector1", vector1);
                std::cout << vector1 << std::endl;
                config_reader.readVector("vector2", vector2);
                std::cout << vector2 << std::endl;

                config_reader.readVector("vector3", vector3);
                for(std::size_t i = 0; i < vector3.size(); ++i)
                {
                    std::cout << vector3[i] << std::endl;
                }
            }


        private:
            yaml_config::ConfigReader config_reader;
            
            std::string string1;
            std::string string2;

            Eigen::Vector2d vector1;
            Eigen::Vector2d vector2;

            std::vector<std::string> vector3;
    };
}//yaml_config
