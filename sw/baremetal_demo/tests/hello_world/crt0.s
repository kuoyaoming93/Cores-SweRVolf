# SPDX-License-Identifier: Apache-2.0
# Copyright 2020 Western Digital Corporation or its affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

.section .text.init
.global _start
_start:

        li  x1, 0
        li  x2, 0
        li  x3, 0
        li  x4, 0
        li  x5, 0
        li  x6, 0
        li  x7, 0
        li  x8, 0
        li  x9, 0
        li  x10,0
        li  x11,0
        li  x12,0
        li  x13,0
        li  x14,0
        li  x15,0
        li  x16,0
        li  x17,0
        li  x18,0
        li  x19,0
        li  x20,0
        li  x21,0
        li  x22,0
        li  x23,0
        li  x24,0
        li  x25,0
        li  x26,0
        li  x27,0
        li  x28,0
        li  x29,0
        li  x30,0
        li  x31,0

        la sp, STACK

        call main



