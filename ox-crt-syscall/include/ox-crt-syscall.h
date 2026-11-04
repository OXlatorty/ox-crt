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

#ifndef OX_CRT_SYSCALL
#define OX_CRT_SYSCALL
#ifdef __cplusplus
extern "C" {
#endif

#include <ox-crt-defines.h>

void* ox_crt_syscall_1(void* number, void* arg1);
void* ox_crt_syscall_2(void* number, void* arg1, void* arg2);
void* ox_crt_syscall_3(void* number, void* arg1, void* arg2, void* arg3);
void* ox_crt_syscall_4(void* number, void* arg1, void* arg2, void* arg3, void* arg4);
void* ox_crt_syscall_5(void* number, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5);

#ifdef __cplusplus
}
#endif
#endif
