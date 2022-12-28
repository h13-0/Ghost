/**
 * @file: ${filename}
 * @note: This document is generated using [safe_lvgl_converter](https://github.com/h13-0/safe_lvgl_converter),
 *            based on lvgl version ${lvgl_version}.
 * @date: ${date}
 * @time: ${time}
 */
#include "safe_lvgl.h"
#include "GhostThread.h"

static GhostRecursiveMutex_t recursiveMutex;

void safe_lvgl_init(void)
{
    // recursive mutex init.
    GhostRecursiveMutexInit(&recursiveMutex);
}

void lv_recursive_unlock(void)
{
    // Unlock recursive mutex.
    GhostRecursiveMutexUnlock(&recursiveMutex);
}

void lv_recursive_lock(void)
{
    // Lock recursive mutex.
    GhostRecursiveMutexLock(&recursiveMutex);
}

${contents_here}
