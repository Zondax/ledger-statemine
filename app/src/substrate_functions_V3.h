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

#include "parser_common.h"
#include "substrate_methods_V3.h"
#include "substrate_types_V3.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V3(parser_context_t* c, pd_AccountId_V3_t* v);
parser_error_t _readBoundedVecu8KeyLimit_V3(parser_context_t* c, pd_BoundedVecu8KeyLimit_V3_t* v);
parser_error_t _readBoundedVecu8StringLimit_V3(parser_context_t* c, pd_BoundedVecu8StringLimit_V3_t* v);
parser_error_t _readBoundedVecu8ValueLimit_V3(parser_context_t* c, pd_BoundedVecu8ValueLimit_V3_t* v);
parser_error_t _readBoxMultiLocation_V3(parser_context_t* c, pd_BoxMultiLocation_V3_t* v);
parser_error_t _readBoxVersionedMultiAssets_V3(parser_context_t* c, pd_BoxVersionedMultiAssets_V3_t* v);
parser_error_t _readBoxVersionedMultiLocation_V3(parser_context_t* c, pd_BoxVersionedMultiLocation_V3_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V3(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V3_t* v);
parser_error_t _readBoxVersionedXcmTuple_V3(parser_context_t* c, pd_BoxVersionedXcmTuple_V3_t* v);
parser_error_t _readCallHashOfT_V3(parser_context_t* c, pd_CallHashOfT_V3_t* v);
parser_error_t _readChangesTrieConfiguration_V3(parser_context_t* c, pd_ChangesTrieConfiguration_V3_t* v);
parser_error_t _readCompactAccountIndex_V3(parser_context_t* c, pd_CompactAccountIndex_V3_t* v);
parser_error_t _readDestroyWitness_V3(parser_context_t* c, pd_DestroyWitness_V3_t* v);
parser_error_t _readInstanceId_V3(parser_context_t* c, pd_InstanceId_V3_t* v);
parser_error_t _readKeyValue_V3(parser_context_t* c, pd_KeyValue_V3_t* v);
parser_error_t _readKey_V3(parser_context_t* c, pd_Key_V3_t* v);
parser_error_t _readKeys_V3(parser_context_t* c, pd_Keys_V3_t* v);
parser_error_t _readLookupasStaticLookupSource_V3(parser_context_t* c, pd_LookupasStaticLookupSource_V3_t* v);
parser_error_t _readOpaqueCall_V3(parser_context_t* c, pd_OpaqueCall_V3_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V3(parser_context_t* c, pd_OptionChangesTrieConfiguration_V3_t* v);
parser_error_t _readOptionInstanceId_V3(parser_context_t* c, pd_OptionInstanceId_V3_t* v);
parser_error_t _readOptionLookupasStaticLookupSource_V3(parser_context_t* c, pd_OptionLookupasStaticLookupSource_V3_t* v);
parser_error_t _readOptionProxyType_V3(parser_context_t* c, pd_OptionProxyType_V3_t* v);
parser_error_t _readOptionTimepoint_V3(parser_context_t* c, pd_OptionTimepoint_V3_t* v);
parser_error_t _readOptionXcmVersion_V3(parser_context_t* c, pd_OptionXcmVersion_V3_t* v);
parser_error_t _readOverweightIndex_V3(parser_context_t* c, pd_OverweightIndex_V3_t* v);
parser_error_t _readParachainInherentData_V3(parser_context_t* c, pd_ParachainInherentData_V3_t* v);
parser_error_t _readPerbill_V3(parser_context_t* c, pd_Perbill_V3_t* v);
parser_error_t _readProxyType_V3(parser_context_t* c, pd_ProxyType_V3_t* v);
parser_error_t _readRelayChainBlockNumber_V3(parser_context_t* c, pd_RelayChainBlockNumber_V3_t* v);
parser_error_t _readTimepoint_V3(parser_context_t* c, pd_Timepoint_V3_t* v);
parser_error_t _readUpwardMessage_V3(parser_context_t* c, pd_UpwardMessage_V3_t* v);
parser_error_t _readVecAccountId_V3(parser_context_t* c, pd_VecAccountId_V3_t* v);
parser_error_t _readVecInstanceId_V3(parser_context_t* c, pd_VecInstanceId_V3_t* v);
parser_error_t _readVecKeyValue_V3(parser_context_t* c, pd_VecKeyValue_V3_t* v);
parser_error_t _readVecKey_V3(parser_context_t* c, pd_VecKey_V3_t* v);
parser_error_t _readWeightLimit_V3(parser_context_t* c, pd_WeightLimit_V3_t* v);
parser_error_t _readWeight_V3(parser_context_t* c, pd_Weight_V3_t* v);
parser_error_t _readXcmVersion_V3(parser_context_t* c, pd_XcmVersion_V3_t* v);

// toString functions
parser_error_t _toStringAccountId_V3(
    const pd_AccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8KeyLimit_V3(
    const pd_BoundedVecu8KeyLimit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8StringLimit_V3(
    const pd_BoundedVecu8StringLimit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8ValueLimit_V3(
    const pd_BoundedVecu8ValueLimit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V3(
    const pd_BoxMultiLocation_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V3(
    const pd_BoxVersionedMultiAssets_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V3(
    const pd_BoxVersionedMultiLocation_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V3(
    const pd_BoxVersionedXcmTasSysConfigCall_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V3(
    const pd_BoxVersionedXcmTuple_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOfT_V3(
    const pd_CallHashOfT_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V3(
    const pd_ChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V3(
    const pd_CompactAccountIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V3(
    const pd_DestroyWitness_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInstanceId_V3(
    const pd_InstanceId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V3(
    const pd_KeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V3(
    const pd_Key_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V3(
    const pd_Keys_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V3(
    const pd_LookupasStaticLookupSource_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V3(
    const pd_OpaqueCall_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V3(
    const pd_OptionChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionInstanceId_V3(
    const pd_OptionInstanceId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionLookupasStaticLookupSource_V3(
    const pd_OptionLookupasStaticLookupSource_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V3(
    const pd_OptionProxyType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V3(
    const pd_OptionTimepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V3(
    const pd_OptionXcmVersion_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V3(
    const pd_OverweightIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainInherentData_V3(
    const pd_ParachainInherentData_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V3(
    const pd_Perbill_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V3(
    const pd_ProxyType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRelayChainBlockNumber_V3(
    const pd_RelayChainBlockNumber_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V3(
    const pd_Timepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUpwardMessage_V3(
    const pd_UpwardMessage_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V3(
    const pd_VecAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecInstanceId_V3(
    const pd_VecInstanceId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V3(
    const pd_VecKeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V3(
    const pd_VecKey_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V3(
    const pd_WeightLimit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V3(
    const pd_Weight_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V3(
    const pd_XcmVersion_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
