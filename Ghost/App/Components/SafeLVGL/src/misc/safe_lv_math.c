//This file is automatically generated.
//The original file is lv_math.h
#include "GhostSafeLVGL.h"
#include "safe_lv_math.h"

//The original function is: lv_trigo_sin.
LV_ATTRIBUTE_FAST_MEM int16_t safe_lv_trigo_sin(int16_t angle)
{
    GhostLV_Lock();
    LV_ATTRIBUTE_FAST_MEM int16_t ret = lv_trigo_sin(angle);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_trigo_sin.
return safe_lv_trigo_sin(angle + 90)
{
    GhostLV_Lock();
    return ret = lv_trigo_sin(90);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_bezier3.
uint32_t safe_lv_bezier3(uint32_t t, uint32_t u0, uint32_t u1, uint32_t u2, uint32_t u3)
{
    GhostLV_Lock();
    uint32_t ret = lv_bezier3(t, u0, u1, u2, u3);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_atan2.
uint16_t safe_lv_atan2(int x, int y)
{
    GhostLV_Lock();
    uint16_t ret = lv_atan2(x, y);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_sqrt.
LV_ATTRIBUTE_FAST_MEM void safe_lv_sqrt(uint32_t x, lv_sqrt_res_t * q, uint32_t mask)
{
    GhostLV_Lock();
    LV_ATTRIBUTE_FAST_MEM void ret = lv_sqrt(x, q, mask);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_pow.
int64_t safe_lv_pow(int64_t base, int8_t exp)
{
    GhostLV_Lock();
    int64_t ret = lv_pow(base, exp);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_map.
int32_t safe_lv_map(int32_t x, int32_t min_in, int32_t max_in, int32_t min_out, int32_t max_out)
{
    GhostLV_Lock();
    int32_t ret = lv_map(x, min_in, max_in, min_out, max_out);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_rand.
uint32_t safe_lv_rand(uint32_t min, uint32_t max)
{
    GhostLV_Lock();
    uint32_t ret = lv_rand(min, max);
    GhostLV_Unlock();
    return ret;
}

