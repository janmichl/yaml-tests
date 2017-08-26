/**
    @file
    @author Jan Michalczyk

    @brief
*/

#pragma once

#include <string>

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
                config_reader.readVectorDouble("vector1", vector1);
                std::cout << vector1 << std::endl;
                config_reader.readVectorDouble("vector2", vector2);
                std::cout << vector2 << std::endl;
            }


        private:
            yaml_config::ConfigReader config_reader;
            
            std::string string1;
            std::string string2;

            Eigen::Vector2d vector1;
            Eigen::Vector2d vector2;
    };
}//yaml_config
