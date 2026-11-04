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

#ifdef OX_CRT_POSIX_X86 

#include <ox-crt-defines.h>
#include <ox-crt-syscall.h>

extern int main(int argc, char** argv, char** envp);

#define __OX_CRT_SYS_EXIT_X86 (void*)(uintptr_t)1

void __ox_crt_entry(int argc, char** argv) {
  char** envp = argv + argc + 1;
  int result = main(argc, argv, envp);

  ox_crt_syscall_1(__OX_CRT_SYS_EXIT_X86, (void*)(uintptr_t)result);
} 

__asm__(
  ".global ox_crt_start\n"
  "ox_crt_start:\n\t"
  "xorl %ebp, %ebp\n\t"
  "popl %eax\n\t"
  "movl %esp, %ebx\n\t"
  "andl $-16, %esp\n\t"
  "subl $8, %esp\n\t"
  "pushl %ebx\n\t"
  "pushl %eax\n\t"
  "call __ox_crt_entry\n"
);

#endif
