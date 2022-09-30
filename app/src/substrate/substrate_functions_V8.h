/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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
#include "substrate_methods_V8.h"
#include "substrate_types_V8.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountIdLookupOfT_V8(parser_context_t* c, pd_AccountIdLookupOfT_V8_t* v);
parser_error_t _readAccountId_V8(parser_context_t* c, pd_AccountId_V8_t* v);
parser_error_t _readBoundedVecu8_V8(parser_context_t* c, pd_BoundedVecu8_V8_t* v);
parser_error_t _readCallHashOf_V8(parser_context_t* c, pd_CallHashOf_V8_t* v);
parser_error_t _readChargeAssetIdOf_V8(parser_context_t* c, pd_ChargeAssetIdOf_V8_t* v);
parser_error_t _readCollectionId_V8(parser_context_t* c, pd_CollectionId_V8_t* v);
parser_error_t _readCompactAccountIndex_V8(parser_context_t* c, pd_CompactAccountIndex_V8_t* v);
parser_error_t _readDestroyWitness_V8(parser_context_t* c, pd_DestroyWitness_V8_t* v);
parser_error_t _readItemId_V8(parser_context_t* c, pd_ItemId_V8_t* v);
parser_error_t _readItemPrice_V8(parser_context_t* c, pd_ItemPrice_V8_t* v);
parser_error_t _readKeys_V8(parser_context_t* c, pd_Keys_V8_t* v);
parser_error_t _readOpaqueCall_V8(parser_context_t* c, pd_OpaqueCall_V8_t* v);
parser_error_t _readOptionAccountIdLookupOfT_V8(parser_context_t* c, pd_OptionAccountIdLookupOfT_V8_t* v);
parser_error_t _readOptionCollectionId_V8(parser_context_t* c, pd_OptionCollectionId_V8_t* v);
parser_error_t _readOptionItemId_V8(parser_context_t* c, pd_OptionItemId_V8_t* v);
parser_error_t _readOptionItemPrice_V8(parser_context_t* c, pd_OptionItemPrice_V8_t* v);
parser_error_t _readOptionProxyType_V8(parser_context_t* c, pd_OptionProxyType_V8_t* v);
parser_error_t _readOptionTimepoint_V8(parser_context_t* c, pd_OptionTimepoint_V8_t* v);
parser_error_t _readOverweightIndex_V8(parser_context_t* c, pd_OverweightIndex_V8_t* v);
parser_error_t _readPerbill_V8(parser_context_t* c, pd_Perbill_V8_t* v);
parser_error_t _readProxyType_V8(parser_context_t* c, pd_ProxyType_V8_t* v);
parser_error_t _readTimepoint_V8(parser_context_t* c, pd_Timepoint_V8_t* v);
parser_error_t _readVecAccountId_V8(parser_context_t* c, pd_VecAccountId_V8_t* v);
parser_error_t _readVecItemId_V8(parser_context_t* c, pd_VecItemId_V8_t* v);
parser_error_t _readWeight_V8(parser_context_t* c, pd_Weight_V8_t* v);

// toString functions
parser_error_t _toStringAccountIdLookupOfT_V8(
    const pd_AccountIdLookupOfT_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V8(
    const pd_AccountId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8_V8(
    const pd_BoundedVecu8_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V8(
    const pd_CallHashOf_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChargeAssetIdOf_V8(
    const pd_ChargeAssetIdOf_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCollectionId_V8(
    const pd_CollectionId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V8(
    const pd_CompactAccountIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V8(
    const pd_DestroyWitness_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemId_V8(
    const pd_ItemId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemPrice_V8(
    const pd_ItemPrice_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V8(
    const pd_Keys_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V8(
    const pd_OpaqueCall_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountIdLookupOfT_V8(
    const pd_OptionAccountIdLookupOfT_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionCollectionId_V8(
    const pd_OptionCollectionId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemId_V8(
    const pd_OptionItemId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemPrice_V8(
    const pd_OptionItemPrice_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V8(
    const pd_OptionProxyType_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V8(
    const pd_OptionTimepoint_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V8(
    const pd_OverweightIndex_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V8(
    const pd_Perbill_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V8(
    const pd_ProxyType_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V8(
    const pd_Timepoint_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V8(
    const pd_VecAccountId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecItemId_V8(
    const pd_VecItemId_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V8(
    const pd_Weight_V8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
