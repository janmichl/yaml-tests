#include <iostream>
#include "DerivedOptions.h"

int main()
{
    DerivedOptions derived_options = DerivedOptions(); 
    derived_options.readParameters(YAMLUser::getInstance("config.yaml"));    

    return 0;	
}
