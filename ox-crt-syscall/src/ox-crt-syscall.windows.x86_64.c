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

#ifdef OX_CRT_WINDOWS_X86_64 

#include <ox-crt-syscall.h>

void* ox_crt_syscall_1(void* number, void* arg1) {
  void* ret;

  register uintptr_t r10_val __asm__("r10") = (uintptr_t)arg1;

  __asm__ volatile (
    "movq %1, %%rax\n\t"
    "pushq %%rax\n\t"
    "subq $32, %%rsp\n\t"
    "syscall\n\t"
    "addq $40, %%rsp"
    : "=a" (ret)
    : "a" (number), "r" (r10_val)
    : "rcx", "r11", "memory"
  );

  return ret;
}
void* ox_crt_syscall_2(void* number, void* arg1, void* arg2) {
  void* ret;

  register uintptr_t r10_val __asm__("r10") = (uintptr_t)arg1;

  __asm__ volatile (
    "movq %2, %%rax\n\t"
    "pushq %%rax\n\t"
    "subq $32, %%rsp\n\t"
    "syscall\n\t"
    "addq $40, %%rsp"
    : "=a" (ret)
    : "a" (number), "r" (r10_val), "d" (arg2)
    : "rcx", "r11", "memory"
  );

  return ret;
}
void* ox_crt_syscall_3(void* number, void* arg1, void* arg2, void* arg3) {
  void* ret;

  register uintptr_t r10_val __asm__("r10") = (uintptr_t)arg1;
  register uintptr_t r8_val __asm__("r8") = (uintptr_t)arg3;

  __asm__ volatile (
    "movq %3, %%rax\n\t"
    "pushq %%rax\n\t"
    "subq $32, %%rsp\n\t"
    "syscall\n\t"
    "addq $40, %%rsp"
    : "=a" (ret)
    : "a" (number), "r" (r10_val), "d" (arg2), "r" (r8_val)
    : "rcx", "r11", "memory"
  );

  return ret;
}
void* ox_crt_syscall_4(void* number, void* arg1, void* arg2, void* arg3, void* arg4) {
  void* ret;

  register uintptr_t r10_val __asm__("r10") = (uintptr_t)arg1;
  register uintptr_t r8_val __asm__("r8") = (uintptr_t)arg3;
  register uintptr_t r9_val __asm__("r9") = (uintptr_t)arg4;

  __asm__ volatile (
    "movq %4, %%rax\n\t"
    "pushq %%rax\n\t"
    "subq $32, %%rsp\n\t"
    "syscall\n\t"
    "addq $40, %%rsp"
    : "=a" (ret)
    : "a" (number), "r" (r10_val), "d" (arg2), "r" (r8_val), "r" (r9_val)
    : "rcx", "r11", "memory"
  );

  return ret;
}
void* ox_crt_syscall_5(void* number, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
  void* ret;

  register uintptr_t r10_val __asm__("r10") = (uintptr_t)arg1;
  register uintptr_t r8_val __asm__("r8") = (uintptr_t)arg3;
  register uintptr_t r9_val __asm__("r9") = (uintptr_t)arg4;

  __asm__ volatile (
    "movq %5, %%rax\n\t"
    "pushq %%rax\n\t"
    "subq $32, %%rsp\n\t"
    "syscall\n\t"
    "addq $40, %%rsp"
    : "=a" (ret)
    : "a" (number), "r" (r10_val), "d" (arg2), "r" (r8_val), "r" (r9_val), "r" (arg5)
    : "rcx", "r11", "memory"
  );

  return ret;
}

#endif
