//This file is automatically generated.
//The original file is lv_async.h
#include "GhostSafeLVGL.h"
#include "safe_lv_async.h"

//The original function is: lv_async_call.
lv_res_t safe_lv_async_call(lv_async_cb_t async_xcb, void * user_data)
{
    GhostLV_Lock();
    lv_res_t ret = lv_async_call(async_xcb, user_data);
    GhostLV_Unlock();
    return ret;
}

//The original function is: lv_async_call_cancel.
lv_res_t safe_lv_async_call_cancel(lv_async_cb_t async_xcb, void * user_data)
{
    GhostLV_Lock();
    lv_res_t ret = lv_async_call_cancel(async_xcb, user_data);
    GhostLV_Unlock();
    return ret;
}

