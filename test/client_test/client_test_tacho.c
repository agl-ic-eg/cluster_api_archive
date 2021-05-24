/*
 * Copyright (c) 2021, Nippon Seiki Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <CUnit/CUnit.h>

#include <cluster_api.h>

#include "client_test_common.h"

#define TACHO_TEST_FUNC(func, param, value) \
    static void Test ##func() { \
        IPC_DATA_IC_SERVICE_S sendData; \
        CU_ASSERT(clusterInit() == true); \
        memset(&sendData, 0x00, sizeof(sendData)); \
        sendData.param = value; \
        requestSendData(&sendData); \
        CU_ASSERT(func() == value); \
        CU_ASSERT(clusterTerm() == true); \
    }

#define TACHO_ADD_TEST(testSuite, func) \
    CU_add_test(testSuite, #func, Test ##func)

TACHO_TEST_FUNC(getTaAnalogVal, taAnalogVal, 0x00004E20)

void SetTestSuiteTacho(void)
{
    CU_pSuite testSuite;

    testSuite = CU_add_suite("Tacho", NULL, NULL);
    TACHO_ADD_TEST(testSuite, getTaAnalogVal);
}

