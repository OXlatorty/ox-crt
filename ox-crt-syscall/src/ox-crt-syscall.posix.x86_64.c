/*
* Copyright 2026 OXlatorty
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifdef OX_CRT_POSIX_X86_64 

#include <ox-crt-syscall.h>

void* ox_crt_syscall_1(void* number, void* arg1) {
  void* ret;

  __asm__ volatile (
    "syscall"
    : "=a" (ret)
    : "a" (number), "D" (arg1)
    : "rcx", "r11", "memory"
  );

  return ret;
}
void* ox_crt_syscall_2(void* number, void* arg1, void* arg2) {
  void* ret;

  __asm__ volatile (
    "syscall"
    : "=a" (ret)
    : "a" (number), "D" (arg1), "S" (arg2)
    : "rcx", "r11", "memory"
  );

  return ret;
}
void* ox_crt_syscall_3(void* number, void* arg1, void* arg2, void* arg3) {
  void* ret;

  __asm__ volatile (
    "syscall"
    : "=a" (ret)
    : "a" (number), "D" (arg1), "S" (arg2), "d" (arg3)
    : "rcx", "r11", "memory"
  );

  return ret;
}
void* ox_crt_syscall_4(void* number, void* arg1, void* arg2, void* arg3, void* arg4) {
  void* ret;

  register uintptr_t r10_val __asm__("r10") = (uintptr_t)arg4;

  __asm__ volatile (
    "syscall"
    : "=a" (ret)
    : "a" (number), "D" (arg1), "S" (arg2), "d" (arg3), "r" (r10_val)
    : "rcx", "r11", "memory"
  );

  return ret;
}
void* ox_crt_syscall_5(void* number, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
  void* ret;

  register uintptr_t r10_val __asm__("r10") = (uintptr_t)arg4;
  register uintptr_t r8_val __asm__("r8") = (uintptr_t)arg5;

  __asm__ volatile (
    "syscall"
    : "=a" (ret)
    : "a" (number), "D" (arg1), "S" (arg2), "d" (arg3), "r" (r10_val), "r" (r8_val)
    : "rcx", "r11", "memory"
  );

  return ret;
}

#endif
