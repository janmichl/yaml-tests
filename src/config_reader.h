#pragma once

#include <string>

#include "yaml-cpp/yaml.h"

namespace yaml_config
{
    class ConfigReader
    {
        public:
            ConfigReader(const std::string& filename)
            {
                YAML::Node root_node_ = YAML::LoadFile(filename);
            }


            template<typename t>
                void readVector(const std::string& node_name, t& value_to_read)
            {
                    YAML::Node node = current_node_[node_name];
                    if(!node.IsSequence())
                    {
                        std::cerr << "Entry is not a sequence." << std::endl;
                        throw(std::runtime_error("Entry not a sequence."));
                    }
                    
                    value_to_read.resize(node.size());
                    for(std::size_t i = 0; i < value_to_read.size(); ++i)
                    {
                        value_to_read(i) = node[i].as<double>();
                    }
            }


            template<typename t>
                void readScalar(const std::string& node_name, t& value_to_read)
            {
                YAML::Node node = current_node_[node_name];
                value_to_read = node[node_name].as<t>(); 
            }

            
            virtual void readParameters(const std::string& node_name)
            {
                goDown(node_name);
                goUp();
            }


        private:
            void goDown(const std::string& node_name)
            {
                current_node_ = root_node_[node_name];
            }


            void goUp()
            {
                current_node_ = root_node_;
            }


        private:
            YAML::Node root_node_;
            YAML::Node current_node_;
    };
}//yaml_config
