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
} pd_AccountId_V1_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V1_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_InstanceId_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V1_t id;
        pd_CompactAccountIndex_V1_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupSource_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MultiAsset_V1_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V1_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V1_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V1_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V1_t contained;
} pd_OptionChangesTrieConfiguration_V1_t;

typedef struct {
    uint8_t some;
    pd_LookupSource_V1_t contained;
} pd_OptionLookupSource_V1_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V1_t contained;
} pd_OptionTimepoint_V1_t;

typedef struct {
    // FIXME

} pd_AssetDestroyWitness_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V1_t;

typedef compactInt_t pd_CompactAssetId_V1_t;

typedef compactInt_t pd_CompactClassId_V1_t;

typedef compactInt_t pd_CompactInstanceId_V1_t;

typedef compactInt_t pd_CompactMoment_V1_t;

typedef compactInt_t pd_CompactTAssetBalance_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DestroyWitness_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_MultiLocation_V1_t;

typedef struct {
    uint8_t some;
    pd_InstanceId_V1_t contained;
} pd_OptionInstanceId_V1_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V1_t contained;
} pd_OptionProxyType_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OverweightIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ParachainInherentData_V1_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_RelayChainBlockNumber_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TAssetBalance_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_UpwardMessage_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecInstanceId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAsset_V1_t;

typedef struct {
    uint64_t value;
} pd_Weight_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Xcm_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_V1_t;

#ifdef __cplusplus
}
#endif
