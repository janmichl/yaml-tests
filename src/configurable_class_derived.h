#pragma once

#include <string>

#include <Eigen/Core>

#include "configurable_class_base.h"
#include "config_reader.h"

namespace yaml_config
{
    class ConfigurableClassDerived : public ConfigurableClassBase, public virtual ConfigReader
    {
        public:
            ConfigurableClassDerived(const char* config_file) : ConfigurableClassBase(config_file), ConfigReader(config_file)
            {
                readParameters("ConfigurableClassDerived");
            }
        

        private:
            void readParameters(const std::string& node_name)
            {       
                readScalar("string1", string1);
                std::cout << string1 << std::endl;
                readScalar("string2", string2);
                std::cout << string2 << std::endl;
                readVector("vector1", vector1);
                std::cout << vector1 << std::endl;
                readVector("vector2", vector2);
                std::cout << vector2 << std::endl;
            }


        private:
            std::string string1;
            std::string string2;

            Eigen::Vector2d vector1;
            Eigen::Vector2d vector2;
    };
}//yaml_config
