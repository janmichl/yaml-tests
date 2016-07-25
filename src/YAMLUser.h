#ifndef YAMLUSER_H
#define YAMLUSER_H

#include <string>
#include <utility>
#include <vector>
#include "yaml-cpp/yaml.h"

class YAMLUser
{
    public:
        YAMLUser(std::string filename)
        {
            config_file_ = YAML::LoadFile(filename);
        }

        virtual void readParameters(std::string nodename)
        {
        }

        virtual void writeParameters(std::string filename)
        {
        }

    protected:
        YAML::Node config_file_;
};

#endif //YAMLUSER_H
