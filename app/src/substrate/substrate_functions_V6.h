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
#include "substrate_methods_V6.h"
#include "substrate_types_V6.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V6(parser_context_t* c, pd_AccountId_V6_t* v);
parser_error_t _readBoundedVecu8_V6(parser_context_t* c, pd_BoundedVecu8_V6_t* v);
parser_error_t _readBoxMultiLocation_V6(parser_context_t* c, pd_BoxMultiLocation_V6_t* v);
parser_error_t _readBoxPalletsOrigin_V6(parser_context_t* c, pd_BoxPalletsOrigin_V6_t* v);
parser_error_t _readBoxVersionedMultiAssets_V6(parser_context_t* c, pd_BoxVersionedMultiAssets_V6_t* v);
parser_error_t _readBoxVersionedMultiLocation_V6(parser_context_t* c, pd_BoxVersionedMultiLocation_V6_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V6(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V6_t* v);
parser_error_t _readBoxVersionedXcmTuple_V6(parser_context_t* c, pd_BoxVersionedXcmTuple_V6_t* v);
parser_error_t _readCallHashOf_V6(parser_context_t* c, pd_CallHashOf_V6_t* v);
parser_error_t _readChargeAssetIdOf_V6(parser_context_t* c, pd_ChargeAssetIdOf_V6_t* v);
parser_error_t _readClassId_V6(parser_context_t* c, pd_ClassId_V6_t* v);
parser_error_t _readCompactAccountIndex_V6(parser_context_t* c, pd_CompactAccountIndex_V6_t* v);
parser_error_t _readDestroyWitness_V6(parser_context_t* c, pd_DestroyWitness_V6_t* v);
parser_error_t _readInstanceId_V6(parser_context_t* c, pd_InstanceId_V6_t* v);
parser_error_t _readKeyValue_V6(parser_context_t* c, pd_KeyValue_V6_t* v);
parser_error_t _readKey_V6(parser_context_t* c, pd_Key_V6_t* v);
parser_error_t _readKeys_V6(parser_context_t* c, pd_Keys_V6_t* v);
parser_error_t _readLookupasStaticLookupSource_V6(parser_context_t* c, pd_LookupasStaticLookupSource_V6_t* v);
parser_error_t _readOpaqueCall_V6(parser_context_t* c, pd_OpaqueCall_V6_t* v);
parser_error_t _readOptionClassId_V6(parser_context_t* c, pd_OptionClassId_V6_t* v);
parser_error_t _readOptionInstanceId_V6(parser_context_t* c, pd_OptionInstanceId_V6_t* v);
parser_error_t _readOptionLookupasStaticLookupSource_V6(parser_context_t* c, pd_OptionLookupasStaticLookupSource_V6_t* v);
parser_error_t _readOptionProxyType_V6(parser_context_t* c, pd_OptionProxyType_V6_t* v);
parser_error_t _readOptionTimepoint_V6(parser_context_t* c, pd_OptionTimepoint_V6_t* v);
parser_error_t _readOptionXcmVersion_V6(parser_context_t* c, pd_OptionXcmVersion_V6_t* v);
parser_error_t _readOverweightIndex_V6(parser_context_t* c, pd_OverweightIndex_V6_t* v);
parser_error_t _readParachainInherentData_V6(parser_context_t* c, pd_ParachainInherentData_V6_t* v);
parser_error_t _readPerbill_V6(parser_context_t* c, pd_Perbill_V6_t* v);
parser_error_t _readProxyType_V6(parser_context_t* c, pd_ProxyType_V6_t* v);
parser_error_t _readTimepoint_V6(parser_context_t* c, pd_Timepoint_V6_t* v);
parser_error_t _readUpwardMessage_V6(parser_context_t* c, pd_UpwardMessage_V6_t* v);
parser_error_t _readVecAccountId_V6(parser_context_t* c, pd_VecAccountId_V6_t* v);
parser_error_t _readVecInstanceId_V6(parser_context_t* c, pd_VecInstanceId_V6_t* v);
parser_error_t _readVecKeyValue_V6(parser_context_t* c, pd_VecKeyValue_V6_t* v);
parser_error_t _readVecKey_V6(parser_context_t* c, pd_VecKey_V6_t* v);
parser_error_t _readWeightLimit_V6(parser_context_t* c, pd_WeightLimit_V6_t* v);
parser_error_t _readWeight_V6(parser_context_t* c, pd_Weight_V6_t* v);
parser_error_t _readXcmVersion_V6(parser_context_t* c, pd_XcmVersion_V6_t* v);

// toString functions
parser_error_t _toStringAccountId_V6(
    const pd_AccountId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8_V6(
    const pd_BoundedVecu8_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V6(
    const pd_BoxMultiLocation_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V6(
    const pd_BoxPalletsOrigin_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V6(
    const pd_BoxVersionedMultiAssets_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V6(
    const pd_BoxVersionedMultiLocation_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V6(
    const pd_BoxVersionedXcmTasSysConfigCall_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V6(
    const pd_BoxVersionedXcmTuple_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V6(
    const pd_CallHashOf_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChargeAssetIdOf_V6(
    const pd_ChargeAssetIdOf_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassId_V6(
    const pd_ClassId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V6(
    const pd_CompactAccountIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V6(
    const pd_DestroyWitness_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInstanceId_V6(
    const pd_InstanceId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V6(
    const pd_KeyValue_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V6(
    const pd_Key_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V6(
    const pd_Keys_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V6(
    const pd_LookupasStaticLookupSource_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V6(
    const pd_OpaqueCall_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionClassId_V6(
    const pd_OptionClassId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionInstanceId_V6(
    const pd_OptionInstanceId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionLookupasStaticLookupSource_V6(
    const pd_OptionLookupasStaticLookupSource_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V6(
    const pd_OptionProxyType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V6(
    const pd_OptionTimepoint_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V6(
    const pd_OptionXcmVersion_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V6(
    const pd_OverweightIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainInherentData_V6(
    const pd_ParachainInherentData_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V6(
    const pd_Perbill_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V6(
    const pd_ProxyType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V6(
    const pd_Timepoint_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUpwardMessage_V6(
    const pd_UpwardMessage_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V6(
    const pd_VecAccountId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecInstanceId_V6(
    const pd_VecInstanceId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V6(
    const pd_VecKeyValue_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V6(
    const pd_VecKey_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V6(
    const pd_WeightLimit_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V6(
    const pd_Weight_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V6(
    const pd_XcmVersion_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
