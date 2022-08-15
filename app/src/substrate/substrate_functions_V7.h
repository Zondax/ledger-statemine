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
#include "substrate_methods_V7.h"
#include "substrate_types_V7.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V7(parser_context_t* c, pd_AccountId_V7_t* v);
parser_error_t _readBoundedVecu8_V7(parser_context_t* c, pd_BoundedVecu8_V7_t* v);
parser_error_t _readCallHashOf_V7(parser_context_t* c, pd_CallHashOf_V7_t* v);
parser_error_t _readChargeAssetIdOf_V7(parser_context_t* c, pd_ChargeAssetIdOf_V7_t* v);
parser_error_t _readCollectionId_V7(parser_context_t* c, pd_CollectionId_V7_t* v);
parser_error_t _readCompactAccountIndex_V7(parser_context_t* c, pd_CompactAccountIndex_V7_t* v);
parser_error_t _readDestroyWitness_V7(parser_context_t* c, pd_DestroyWitness_V7_t* v);
parser_error_t _readItemId_V7(parser_context_t* c, pd_ItemId_V7_t* v);
parser_error_t _readItemPrice_V7(parser_context_t* c, pd_ItemPrice_V7_t* v);
parser_error_t _readKeys_V7(parser_context_t* c, pd_Keys_V7_t* v);
parser_error_t _readLookupasStaticLookupSource_V7(parser_context_t* c, pd_LookupasStaticLookupSource_V7_t* v);
parser_error_t _readOpaqueCall_V7(parser_context_t* c, pd_OpaqueCall_V7_t* v);
parser_error_t _readOptionCollectionId_V7(parser_context_t* c, pd_OptionCollectionId_V7_t* v);
parser_error_t _readOptionItemId_V7(parser_context_t* c, pd_OptionItemId_V7_t* v);
parser_error_t _readOptionItemPrice_V7(parser_context_t* c, pd_OptionItemPrice_V7_t* v);
parser_error_t _readOptionLookupasStaticLookupSource_V7(parser_context_t* c, pd_OptionLookupasStaticLookupSource_V7_t* v);
parser_error_t _readOptionProxyType_V7(parser_context_t* c, pd_OptionProxyType_V7_t* v);
parser_error_t _readOptionTimepoint_V7(parser_context_t* c, pd_OptionTimepoint_V7_t* v);
parser_error_t _readOverweightIndex_V7(parser_context_t* c, pd_OverweightIndex_V7_t* v);
parser_error_t _readPerbill_V7(parser_context_t* c, pd_Perbill_V7_t* v);
parser_error_t _readProxyType_V7(parser_context_t* c, pd_ProxyType_V7_t* v);
parser_error_t _readTimepoint_V7(parser_context_t* c, pd_Timepoint_V7_t* v);
parser_error_t _readVecAccountId_V7(parser_context_t* c, pd_VecAccountId_V7_t* v);
parser_error_t _readVecItemId_V7(parser_context_t* c, pd_VecItemId_V7_t* v);
parser_error_t _readWeight_V7(parser_context_t* c, pd_Weight_V7_t* v);

// toString functions
parser_error_t _toStringAccountId_V7(
    const pd_AccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8_V7(
    const pd_BoundedVecu8_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V7(
    const pd_CallHashOf_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChargeAssetIdOf_V7(
    const pd_ChargeAssetIdOf_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCollectionId_V7(
    const pd_CollectionId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V7(
    const pd_CompactAccountIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V7(
    const pd_DestroyWitness_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemId_V7(
    const pd_ItemId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemPrice_V7(
    const pd_ItemPrice_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V7(
    const pd_Keys_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V7(
    const pd_LookupasStaticLookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V7(
    const pd_OpaqueCall_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionCollectionId_V7(
    const pd_OptionCollectionId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemId_V7(
    const pd_OptionItemId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemPrice_V7(
    const pd_OptionItemPrice_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionLookupasStaticLookupSource_V7(
    const pd_OptionLookupasStaticLookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V7(
    const pd_OptionProxyType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V7(
    const pd_OptionTimepoint_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V7(
    const pd_OverweightIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V7(
    const pd_Perbill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V7(
    const pd_ProxyType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V7(
    const pd_Timepoint_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V7(
    const pd_VecAccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecItemId_V7(
    const pd_VecItemId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V7(
    const pd_Weight_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
