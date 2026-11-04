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

#ifndef OX_CRT_DEFINES
#define OX_CRT_DEFINES
#ifdef __cplusplus
extern "C" {
#endif

// #if defined(__UINTPTR_TYPE__)
//   typedef __UINTPTR_TYPE__ uintptr_t;
#if defined(OX_CRT_POSIX_X86) || defined(OX_CRT_WINDOWS_X86)
  typedef unsigned long uintptr_t;
#elif defined(OX_CRT_POSIX_X86_64) || defined(OX_CRT_WINDOWS_X86_64)
  typedef unsigned long long uintptr_t;
#endif

#ifdef __cplusplus
}
#endif
#endif
