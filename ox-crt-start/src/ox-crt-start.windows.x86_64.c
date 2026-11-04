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

#include <ox-crt-defines.h>
#include <ox-crt-syscall.h>

extern int main(int argc, char** argv);

#define __OX_CRT_NT_TERMINATE_PROCESS_X86_64 (void*)(uintptr_t)0x002C

void __ox_crt_entry(void) {
  int result = main(0, (char**)0);

  ox_crt_syscall_2(__OX_CRT_NT_TERMINATE_PROCESS_X86_64, (void*)(uintptr_t)-1, (void*)(uintptr_t)result);
}

__asm__(
  ".global ox_crt_start\n"
  "ox_crt_start:\n\t"
  "subq $40, %rsp\n\t"
  "call __ox_crt_entry\n\t"
  "addq $40, %rsp\n\t"
  "ret\n"
);

#endif
