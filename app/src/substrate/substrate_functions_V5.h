/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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
#include "substrate_methods_V5.h"
#include "substrate_types_V5.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V5(parser_context_t* c, pd_AccountId_V5_t* v);
parser_error_t _readBoundedVecu8KeyLimit_V5(parser_context_t* c, pd_BoundedVecu8KeyLimit_V5_t* v);
parser_error_t _readBoundedVecu8StringLimit_V5(parser_context_t* c, pd_BoundedVecu8StringLimit_V5_t* v);
parser_error_t _readBoundedVecu8ValueLimit_V5(parser_context_t* c, pd_BoundedVecu8ValueLimit_V5_t* v);
parser_error_t _readBoxMultiLocation_V5(parser_context_t* c, pd_BoxMultiLocation_V5_t* v);
parser_error_t _readBoxPalletsOrigin_V5(parser_context_t* c, pd_BoxPalletsOrigin_V5_t* v);
parser_error_t _readBoxVersionedMultiAssets_V5(parser_context_t* c, pd_BoxVersionedMultiAssets_V5_t* v);
parser_error_t _readBoxVersionedMultiLocation_V5(parser_context_t* c, pd_BoxVersionedMultiLocation_V5_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V5(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V5_t* v);
parser_error_t _readBoxVersionedXcmTuple_V5(parser_context_t* c, pd_BoxVersionedXcmTuple_V5_t* v);
parser_error_t _readCallHashOf_V5(parser_context_t* c, pd_CallHashOf_V5_t* v);
parser_error_t _readChargeAssetIdOf_V5(parser_context_t* c, pd_ChargeAssetIdOf_V5_t* v);
parser_error_t _readCompactAccountIndex_V5(parser_context_t* c, pd_CompactAccountIndex_V5_t* v);
parser_error_t _readDestroyWitness_V5(parser_context_t* c, pd_DestroyWitness_V5_t* v);
parser_error_t _readInstanceId_V5(parser_context_t* c, pd_InstanceId_V5_t* v);
parser_error_t _readKeyValue_V5(parser_context_t* c, pd_KeyValue_V5_t* v);
parser_error_t _readKey_V5(parser_context_t* c, pd_Key_V5_t* v);
parser_error_t _readKeys_V5(parser_context_t* c, pd_Keys_V5_t* v);
parser_error_t _readLookupasStaticLookupSource_V5(parser_context_t* c, pd_LookupasStaticLookupSource_V5_t* v);
parser_error_t _readOpaqueCall_V5(parser_context_t* c, pd_OpaqueCall_V5_t* v);
parser_error_t _readOptionInstanceId_V5(parser_context_t* c, pd_OptionInstanceId_V5_t* v);
parser_error_t _readOptionLookupasStaticLookupSource_V5(parser_context_t* c, pd_OptionLookupasStaticLookupSource_V5_t* v);
parser_error_t _readOptionProxyType_V5(parser_context_t* c, pd_OptionProxyType_V5_t* v);
parser_error_t _readOptionTimepoint_V5(parser_context_t* c, pd_OptionTimepoint_V5_t* v);
parser_error_t _readOptionXcmVersion_V5(parser_context_t* c, pd_OptionXcmVersion_V5_t* v);
parser_error_t _readOverweightIndex_V5(parser_context_t* c, pd_OverweightIndex_V5_t* v);
parser_error_t _readParachainInherentData_V5(parser_context_t* c, pd_ParachainInherentData_V5_t* v);
parser_error_t _readPerbill_V5(parser_context_t* c, pd_Perbill_V5_t* v);
parser_error_t _readProxyType_V5(parser_context_t* c, pd_ProxyType_V5_t* v);
parser_error_t _readTimepoint_V5(parser_context_t* c, pd_Timepoint_V5_t* v);
parser_error_t _readUpwardMessage_V5(parser_context_t* c, pd_UpwardMessage_V5_t* v);
parser_error_t _readVecAccountId_V5(parser_context_t* c, pd_VecAccountId_V5_t* v);
parser_error_t _readVecInstanceId_V5(parser_context_t* c, pd_VecInstanceId_V5_t* v);
parser_error_t _readVecKeyValue_V5(parser_context_t* c, pd_VecKeyValue_V5_t* v);
parser_error_t _readVecKey_V5(parser_context_t* c, pd_VecKey_V5_t* v);
parser_error_t _readWeightLimit_V5(parser_context_t* c, pd_WeightLimit_V5_t* v);
parser_error_t _readWeight_V5(parser_context_t* c, pd_Weight_V5_t* v);
parser_error_t _readXcmVersion_V5(parser_context_t* c, pd_XcmVersion_V5_t* v);

// toString functions
parser_error_t _toStringAccountId_V5(
    const pd_AccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8KeyLimit_V5(
    const pd_BoundedVecu8KeyLimit_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8StringLimit_V5(
    const pd_BoundedVecu8StringLimit_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8ValueLimit_V5(
    const pd_BoundedVecu8ValueLimit_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V5(
    const pd_BoxMultiLocation_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V5(
    const pd_BoxPalletsOrigin_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V5(
    const pd_BoxVersionedMultiAssets_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V5(
    const pd_BoxVersionedMultiLocation_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V5(
    const pd_BoxVersionedXcmTasSysConfigCall_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V5(
    const pd_BoxVersionedXcmTuple_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V5(
    const pd_CallHashOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChargeAssetIdOf_V5(
    const pd_ChargeAssetIdOf_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V5(
    const pd_CompactAccountIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V5(
    const pd_DestroyWitness_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInstanceId_V5(
    const pd_InstanceId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V5(
    const pd_KeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V5(
    const pd_Key_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V5(
    const pd_Keys_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V5(
    const pd_LookupasStaticLookupSource_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V5(
    const pd_OpaqueCall_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionInstanceId_V5(
    const pd_OptionInstanceId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionLookupasStaticLookupSource_V5(
    const pd_OptionLookupasStaticLookupSource_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V5(
    const pd_OptionProxyType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V5(
    const pd_OptionTimepoint_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V5(
    const pd_OptionXcmVersion_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V5(
    const pd_OverweightIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainInherentData_V5(
    const pd_ParachainInherentData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V5(
    const pd_Perbill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V5(
    const pd_ProxyType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V5(
    const pd_Timepoint_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUpwardMessage_V5(
    const pd_UpwardMessage_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V5(
    const pd_VecAccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecInstanceId_V5(
    const pd_VecInstanceId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V5(
    const pd_VecKeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V5(
    const pd_VecKey_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V5(
    const pd_WeightLimit_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V5(
    const pd_Weight_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V5(
    const pd_XcmVersion_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
