#include <iostream>
#include "DerivedOptions.h"

YAMLUser& yaml_user = YAMLUser::getInstance("config.yaml");

int main()
{
    DerivedOptions derived_options = DerivedOptions(yaml_user); 

    return 0;	
}
