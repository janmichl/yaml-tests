#pragma once

#include "config_reader.h"

namespace yaml_config
{
    class ConfigurableClassBase : public virtual ConfigReader
    {
        public:
            ConfigurableClassBase(const char* config_file) : ConfigReader(config_file)
            {
                readParameters("ConfigurableClassBase");
            }
        

        private:
            void readParameters(const std::string& node_name)
            {       
                readScalar("uint1", uint1);
                std::cout << uint1 << std::endl;
                readScalar("uint2", uint2);
                std::cout << uint2 << std::endl;
                readScalar("uint3", uint3);
                std::cout << uint3 << std::endl;
                readScalar("uint4", uint4);
                std::cout << uint4 << std::endl;
            }


        private:
            unsigned int uint1;
            unsigned int uint2;
            unsigned int uint3;
            unsigned int uint4;
    };
}//yaml_config
