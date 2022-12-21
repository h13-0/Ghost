${func_decl}
{
    lv_recursive_lock();
    ${func_call}
    lv_recursive_unlock();
    ${func_ret}
}