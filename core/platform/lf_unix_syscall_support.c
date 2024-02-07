#if defined(PLATFORM_Linux) || defined(PLATFORM_Darwin)
/**
 * @file lf_unix_syscall_support.c
 * @author Soroush Bateni (soroush@utdallas.edu)
 * @brief Platform support for syscalls in Unix-like systems.
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022 The University of Texas at Dallas
 * 
 */

#include <unistd.h>
#include "lf_atomic.h"

int lf_available_cores() {
    return (int)sysconf(_SC_NPROCESSORS_ONLN);
}

int32_t lf_atomic_fetch_add32(int32_t *ptr, int32_t value) { 
    return __sync_fetch_and_add(ptr, value);
}
int64_t lf_atomic_fetch_add64(int64_t *ptr, int64_t value) {
    return __sync_fetch_and_add(ptr, value);
}
int lf_atomic_add_fetch32(int32_t *ptr, int32_t value) {
    return __sync_add_and_fetch(ptr, value);
}
int64_t lf_atomic_add_fetch64(int64_t *ptr, int64_t value) {
    return __sync_add_and_fetch(ptr, value);
}
bool lf_atomic_bool_compare_and_swap32(int32_t *ptr, int32_t oldval, int32_t newval) {
    return __sync_bool_compare_and_swap(ptr, oldval, newval);
}
bool lf_atomic_bool_compare_and_swap64(int64_t *ptr, int64_t oldval, int64_t newval) {
    return __sync_bool_compare_and_swap(ptr, oldval, newval);
}
int  lf_atomic_val_compare_and_swap32(int32_t *ptr, int32_t oldval, int32_t newval) {
    return __sync_val_compare_and_swap(ptr, oldval, newval);
}
int64_t  lf_atomic_val_compare_and_swap64(int64_t *ptr, int64_t oldval, int64_t newval) {
    return __sync_val_compare_and_swap(ptr, oldval, newval);
}
#endif
