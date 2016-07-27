#include <iostream>
#include "DerivedOptions.h"

int main()
{
    YAMLUser& yaml_user = YAMLUser::getInstance("config.yaml");
    DerivedOptions derived_options = DerivedOptions(yaml_user); 

    return 0;	
}
