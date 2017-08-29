/**
    @file
    @author Jan Michalczyk

    @brief
*/

#pragma once

#include <string>
#include <vector>

#include "yaml-cpp/yaml.h"

namespace yaml_config
{
    class ConfigReader
    {
        public:
            ConfigReader(const std::string& filename)
            {
                root_node_ = YAML::LoadFile(filename);
            }


            template <typename t_Scalar,
                      int t_rows,
                      int t_flags>
                void readVector(const std::string& node_name,
                                Eigen::Matrix<t_Scalar, t_rows, 1, t_flags>& to_read)
            {
                    YAML::Node node = current_node_[node_name];
                    if(!node.IsSequence())
                    {
                        std::cerr << "Entry is not a sequence." << std::endl;
                        throw(std::runtime_error("Entry not a sequence."));
                    }
                    
                    if(Eigen::Dynamic == t_rows)
                    {
                        to_read.resize(node.size());
                    }
                    for(std::size_t i = 0; i < to_read.size(); ++i)
                    {
                        to_read(i) = node[i].as<t_Scalar>();
                    }
            }


            template<typename t>
                void readScalar(const std::string& node_name, t& to_read)
            {
                to_read = current_node_[node_name].as<t>(); 
            }
            
            
            template<typename t>
                void readVector(const std::string& node_name, std::vector<t>& to_read)
            {
                YAML::Node node = current_node_[node_name];
                if(!node.IsSequence())
                {
                    std::cerr << "Entry is not a sequence." << std::endl;
                    throw(std::runtime_error("Entry not a sequence."));
                }
                
                to_read.resize(node.size());
                for(std::size_t i = 0; i < to_read.size(); ++i)
                {
                    to_read[i] = node[i].as<t>();
                }
            }


            void findNode(const std::string& node_name)
            {
                goDown(node_name);
            }


        private:
            void goDown(const std::string& node_name)
            {
                current_node_ = root_node_[node_name];
            }


        private:
            YAML::Node root_node_;
            YAML::Node current_node_;
    };
}//yaml_config
