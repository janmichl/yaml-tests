#ifndef YAMLUSER_H
#define YAMLUSER_H

#include <string>
#include "yaml-cpp/yaml.h"

class YAMLUser
{
    public:
        static YAMLUser& getInstance(std::string filename)
        {
            static YAMLUser instance(filename);
            return instance;
        }

        YAML::Node config_file_;

    private:
        YAMLUser() {};
        YAMLUser(const YAMLUser&);
        void operator=(const YAMLUser&);
        YAMLUser(std::string filename)
        {
            config_file_ = YAML::LoadFile(filename);
        }
};

#endif //YAMLUSER_H
