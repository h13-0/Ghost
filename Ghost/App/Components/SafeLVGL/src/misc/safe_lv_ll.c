//This file is automatically generated.
//The original file is lv_ll.h
#include "GhostSafeLVGL.h"
#include "safe_lv_ll.h"

//The original function is: lv_ll_swap.
void safe_lv_ll_swap(lv_ll_t * ll_p, void * n1_p, void * n2_p)
{
    GhostLV_Lock();
    lv_ll_swap(ll_p, n1_p, n2_p);
    GhostLV_Unlock();
}

