/*******************************************************************************
*  (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V4_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V4_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_InstanceId_V4_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V4_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V4_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V4_t id;
        pd_CompactAccountIndex_V4_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V4_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V4_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_XcmVersion_V4_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V4_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V4_t contained;
} pd_OptionChangesTrieConfiguration_V4_t;

typedef struct {
    uint8_t some;
    pd_LookupasStaticLookupSource_V4_t contained;
} pd_OptionLookupasStaticLookupSource_V4_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V4_t contained;
} pd_OptionTimepoint_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoundedVecu8KeyLimit_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoundedVecu8StringLimit_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoundedVecu8ValueLimit_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxMultiLocation_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiAssets_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedMultiLocation_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTasSysConfigCall_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BoxVersionedXcmTuple_V4_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DestroyWitness_V4_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V4_t;

typedef struct {
    uint8_t some;
    pd_InstanceId_V4_t contained;
} pd_OptionInstanceId_V4_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V4_t contained;
} pd_OptionProxyType_V4_t;

typedef struct {
    uint8_t some;
    pd_XcmVersion_V4_t contained;
} pd_OptionXcmVersion_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainInherentData_V4_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V4_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_UpwardMessage_V4_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V4_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecInstanceId_V4_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V4_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V4_t;

typedef struct {
    uint64_t value;
} pd_WeightLimit_V4_t;

typedef struct {
    uint64_t value;
} pd_Weight_V4_t;

#ifdef __cplusplus
}
#endif
