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
#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch_V3.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readAccountId_V3(parser_context_t* c, pd_AccountId_V3_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readBoundedVecu8KeyLimit_V3(parser_context_t* c, pd_BoundedVecu8KeyLimit_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoundedVecu8StringLimit_V3(parser_context_t* c, pd_BoundedVecu8StringLimit_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoundedVecu8ValueLimit_V3(parser_context_t* c, pd_BoundedVecu8ValueLimit_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxMultiLocation_V3(parser_context_t* c, pd_BoxMultiLocation_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiAssets_V3(parser_context_t* c, pd_BoxVersionedMultiAssets_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedMultiLocation_V3(parser_context_t* c, pd_BoxVersionedMultiLocation_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTasSysConfigCall_V3(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBoxVersionedXcmTuple_V3(parser_context_t* c, pd_BoxVersionedXcmTuple_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCallHashOfT_V3(parser_context_t* c, pd_CallHashOfT_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readChangesTrieConfiguration_V3(parser_context_t* c, pd_ChangesTrieConfiguration_V3_t* v)
{
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCompactAccountIndex_V3(parser_context_t* c, pd_CompactAccountIndex_V3_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readDestroyWitness_V3(parser_context_t* c, pd_DestroyWitness_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readInstanceId_V3(parser_context_t* c, pd_InstanceId_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V3(parser_context_t* c, pd_KeyValue_V3_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V3(parser_context_t* c, pd_Key_V3_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V3(parser_context_t* c, pd_Keys_V3_t* v) {
    GEN_DEF_READARRAY(6 * 32)
}

parser_error_t _readLookupasStaticLookupSource_V3(parser_context_t* c, pd_LookupasStaticLookupSource_V3_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId_V3(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex_V3(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
    case 4: // Address20
        GEN_DEF_READARRAY(20)
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readOpaqueCall_V3(parser_context_t* c, pd_OpaqueCall_V3_t* v)
{
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readOverweightIndex_V3(parser_context_t* c, pd_OverweightIndex_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readParachainInherentData_V3(parser_context_t* c, pd_ParachainInherentData_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readPerbill_V3(parser_context_t* c, pd_Perbill_V3_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readProxyType_V3(parser_context_t* c, pd_ProxyType_V3_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 7) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readRelayChainBlockNumber_V3(parser_context_t* c, pd_RelayChainBlockNumber_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readTimepoint_V3(parser_context_t* c, pd_Timepoint_V3_t* v)
{
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readUpwardMessage_V3(parser_context_t* c, pd_UpwardMessage_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readWeightLimit_V3(parser_context_t* c, pd_WeightLimit_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readWeight_V3(parser_context_t* c, pd_Weight_V3_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readXcmVersion_V3(parser_context_t* c, pd_XcmVersion_V3_t* v)
{
    return parser_not_supported;
}

parser_error_t _readVecAccountId_V3(parser_context_t* c, pd_VecAccountId_V3_t* v) {
    GEN_DEF_READVECTOR(AccountId_V3)
}

parser_error_t _readVecInstanceId_V3(parser_context_t* c, pd_VecInstanceId_V3_t* v) {
    GEN_DEF_READVECTOR(InstanceId_V3)
}

parser_error_t _readVecKeyValue_V3(parser_context_t* c, pd_VecKeyValue_V3_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V3)
}

parser_error_t _readVecKey_V3(parser_context_t* c, pd_VecKey_V3_t* v) {
    GEN_DEF_READVECTOR(Key_V3)
}

parser_error_t _readOptionChangesTrieConfiguration_V3(parser_context_t* c, pd_OptionChangesTrieConfiguration_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration_V3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionInstanceId_V3(parser_context_t* c, pd_OptionInstanceId_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readInstanceId_V3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionLookupasStaticLookupSource_V3(parser_context_t* c, pd_OptionLookupasStaticLookupSource_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readLookupasStaticLookupSource_V3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionProxyType_V3(parser_context_t* c, pd_OptionProxyType_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readProxyType_V3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V3(parser_context_t* c, pd_OptionTimepoint_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V3(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionXcmVersion_V3(parser_context_t* c, pd_OptionXcmVersion_V3_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readXcmVersion_V3(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringAccountId_V3(
    const pd_AccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBoundedVecu8KeyLimit_V3(
    const pd_BoundedVecu8KeyLimit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoundedVecu8StringLimit_V3(
    const pd_BoundedVecu8StringLimit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoundedVecu8ValueLimit_V3(
    const pd_BoundedVecu8ValueLimit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxMultiLocation_V3(
    const pd_BoxMultiLocation_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiAssets_V3(
    const pd_BoxVersionedMultiAssets_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedMultiLocation_V3(
    const pd_BoxVersionedMultiLocation_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V3(
    const pd_BoxVersionedXcmTasSysConfigCall_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBoxVersionedXcmTuple_V3(
    const pd_BoxVersionedXcmTuple_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCallHashOfT_V3(
    const pd_CallHashOfT_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringChangesTrieConfiguration_V3(
    const pd_ChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCompactAccountIndex_V3(
    const pd_CompactAccountIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDestroyWitness_V3(
    const pd_DestroyWitness_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringInstanceId_V3(
    const pd_InstanceId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V3(
    const pd_KeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V3(
    const pd_Key_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V3(
    const pd_Keys_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
}

parser_error_t _toStringLookupasStaticLookupSource_V3(
    const pd_LookupasStaticLookupSource_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId_V3(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex_V3(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringOpaqueCall_V3(
    const pd_OpaqueCall_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOverweightIndex_V3(
    const pd_OverweightIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringParachainInherentData_V3(
    const pd_ParachainInherentData_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill_V3(
    const pd_Perbill_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    memset(outValue, 0, outValueLen);
    memset(ratioBuffer, 0, sizeof(ratioBuffer));
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringProxyType_V3(
    const pd_ProxyType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Any");
        break;
    case 1:
        snprintf(outValue, outValueLen, "NonTransfer");
        break;
    case 2:
        snprintf(outValue, outValueLen, "CancelProxy");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Assets");
        break;
    case 4:
        snprintf(outValue, outValueLen, "AssetOwner");
        break;
    case 5:
        snprintf(outValue, outValueLen, "AssetManager");
        break;
    case 6:
        snprintf(outValue, outValueLen, "Collator");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringRelayChainBlockNumber_V3(
    const pd_RelayChainBlockNumber_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringTimepoint_V3(
    const pd_Timepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringUpwardMessage_V3(
    const pd_UpwardMessage_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringWeightLimit_V3(
    const pd_WeightLimit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringWeight_V3(
    const pd_Weight_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringXcmVersion_V3(
    const pd_XcmVersion_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringVecAccountId_V3(
    const pd_VecAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V3);
}

parser_error_t _toStringVecInstanceId_V3(
    const pd_VecInstanceId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(InstanceId_V3);
}

parser_error_t _toStringVecKeyValue_V3(
    const pd_VecKeyValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V3);
}

parser_error_t _toStringVecKey_V3(
    const pd_VecKey_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V3);
}

parser_error_t _toStringOptionChangesTrieConfiguration_V3(
    const pd_OptionChangesTrieConfiguration_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionInstanceId_V3(
    const pd_OptionInstanceId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringInstanceId_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionLookupasStaticLookupSource_V3(
    const pd_OptionLookupasStaticLookupSource_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringLookupasStaticLookupSource_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionProxyType_V3(
    const pd_OptionProxyType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringProxyType_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V3(
    const pd_OptionTimepoint_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionXcmVersion_V3(
    const pd_OptionXcmVersion_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringXcmVersion_V3(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
