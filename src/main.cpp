#include <iostream>
#include "WalkOptions.h"

int main()
{
    WalkOptions wo = WalkOptions("config.yaml"); 
    
    wo.readParameters("walkoptions");    

    return 0;	
}
