//This file is automatically generated.
//The original file is lv_port_indev_template.h
#include "GhostSafeLVGL.h"
#include "safe_lv_port_indev_template.h"

//The original function is: lv_port_indev_init.
void safe_lv_port_indev_init(void)
{
    GhostLV_Lock();
    lv_port_indev_init();
    GhostLV_Unlock();
}

