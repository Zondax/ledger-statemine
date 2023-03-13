/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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

#include <stddef.h>
#include <stdint.h>

// Common read functions

parser_error_t _readbool(parser_context_t* c, pd_bool_t* v);
parser_error_t _readu8(parser_context_t* c, pd_u8_t* v);
parser_error_t _readu16(parser_context_t* c, pd_u16_t* v);
parser_error_t _readu32(parser_context_t* c, pd_u32_t* v);
parser_error_t _readu64(parser_context_t* c, pd_u64_t* v);
parser_error_t _readBlockNumber(parser_context_t* c, pd_BlockNumber_t* v);
parser_error_t _readCompactu32(parser_context_t* c, pd_Compactu32_t* v);
parser_error_t _readCompactu64(parser_context_t* c, pd_Compactu64_t* v);
parser_error_t _readCallImpl(parser_context_t* c, pd_Call_t* v, pd_MethodNested_t* m);

parser_error_t _readu8_array_32(parser_context_t* c, pd_u8_array_32_t* v);
parser_error_t _readByFork(parser_context_t* c, pd_ByFork_t* v);
parser_error_t _readBytes(parser_context_t* c, pd_Bytes_t* v);
parser_error_t _readFraction(parser_context_t* c, pd_Fraction_t* v);
parser_error_t _readNetworkIdV3(parser_context_t* c, pd_NetworkIdV3_t* v);
parser_error_t _readBodyId(parser_context_t* c, pd_BodyId_t* v);
parser_error_t _readBodyIdV2(parser_context_t* c, pd_BodyIdV2_t* v);
parser_error_t _readBodyIdV3(parser_context_t* c, pd_BodyIdV3_t* v);
parser_error_t _readBodyPart(parser_context_t* c, pd_BodyPart_t* v);
parser_error_t _readNetworkId(parser_context_t* c, pd_NetworkId_t* v);
parser_error_t _readNetworkIdV2(parser_context_t* c, pd_NetworkIdV2_t* v);
parser_error_t _readOptionNetworkIdV3(parser_context_t* c, pd_OptionNetworkIdV3_t* v);
parser_error_t _readu8_array_20(parser_context_t* c, pd_u8_array_20_t* v);
parser_error_t _readAccountId32(parser_context_t* c, pd_AccountId32_t* v);
parser_error_t _readAccountId32V2(parser_context_t* c, pd_AccountId32V2_t* v);
parser_error_t _readAccountId32V3(parser_context_t* c, pd_AccountId32V3_t* v);
parser_error_t _readAccountIndex64(parser_context_t* c, pd_AccountIndex64_t* v);
parser_error_t _readAccountIndex64V2(parser_context_t* c, pd_AccountIndex64V2_t* v);
parser_error_t _readAccountIndex64V3(parser_context_t* c, pd_AccountIndex64V3_t* v);
parser_error_t _readAccountKey20(parser_context_t* c, pd_AccountKey20_t* v);
parser_error_t _readAccountKey20V2(parser_context_t* c, pd_AccountKey20V2_t* v);
parser_error_t _readAccountKey20V3(parser_context_t* c, pd_AccountKey20V3_t* v);
parser_error_t _readCompactu128(parser_context_t* c, pd_Compactu128_t* v);
parser_error_t _readGeneralKeyV3(parser_context_t* c, pd_GeneralKeyV3_t* v);
parser_error_t _readPlurality(parser_context_t* c, pd_Plurality_t* v);
parser_error_t _readPluralityV2(parser_context_t* c, pd_PluralityV2_t* v);
parser_error_t _readPluralityV3(parser_context_t* c, pd_PluralityV3_t* v);
parser_error_t _readJunctionV0(parser_context_t* c, pd_JunctionV0_t* v);
parser_error_t _readJunctionV1(parser_context_t* c, pd_JunctionV1_t* v);
parser_error_t _readJunctionV2(parser_context_t* c, pd_JunctionV2_t* v);
parser_error_t _readJunctionV3(parser_context_t* c, pd_JunctionV3_t* v);
parser_error_t _readJunctionV0X1(parser_context_t* c, pd_JunctionV0X1_t* v);
parser_error_t _readJunctionV0X2(parser_context_t* c, pd_JunctionV0X2_t* v);
parser_error_t _readJunctionV0X3(parser_context_t* c, pd_JunctionV0X3_t* v);
parser_error_t _readJunctionV0X4(parser_context_t* c, pd_JunctionV0X4_t* v);
parser_error_t _readJunctionV0X5(parser_context_t* c, pd_JunctionV0X5_t* v);
parser_error_t _readJunctionV0X6(parser_context_t* c, pd_JunctionV0X6_t* v);
parser_error_t _readJunctionV0X7(parser_context_t* c, pd_JunctionV0X7_t* v);
parser_error_t _readJunctionV0X8(parser_context_t* c, pd_JunctionV0X8_t* v);
parser_error_t _readJunctionV1X1(parser_context_t* c, pd_JunctionV1X1_t* v);
parser_error_t _readJunctionV1X2(parser_context_t* c, pd_JunctionV1X2_t* v);
parser_error_t _readJunctionV1X3(parser_context_t* c, pd_JunctionV1X3_t* v);
parser_error_t _readJunctionV1X4(parser_context_t* c, pd_JunctionV1X4_t* v);
parser_error_t _readJunctionV1X5(parser_context_t* c, pd_JunctionV1X5_t* v);
parser_error_t _readJunctionV1X6(parser_context_t* c, pd_JunctionV1X6_t* v);
parser_error_t _readJunctionV1X7(parser_context_t* c, pd_JunctionV1X7_t* v);
parser_error_t _readJunctionV1X8(parser_context_t* c, pd_JunctionV1X8_t* v);
parser_error_t _readJunctionV2X1(parser_context_t* c, pd_JunctionV2X1_t* v);
parser_error_t _readJunctionV2X2(parser_context_t* c, pd_JunctionV2X2_t* v);
parser_error_t _readJunctionV2X3(parser_context_t* c, pd_JunctionV2X3_t* v);
parser_error_t _readJunctionV2X4(parser_context_t* c, pd_JunctionV2X4_t* v);
parser_error_t _readJunctionV2X5(parser_context_t* c, pd_JunctionV2X5_t* v);
parser_error_t _readJunctionV2X6(parser_context_t* c, pd_JunctionV2X6_t* v);
parser_error_t _readJunctionV2X7(parser_context_t* c, pd_JunctionV2X7_t* v);
parser_error_t _readJunctionV2X8(parser_context_t* c, pd_JunctionV2X8_t* v);
parser_error_t _readJunctionV3X1(parser_context_t* c, pd_JunctionV3X1_t* v);
parser_error_t _readJunctionV3X2(parser_context_t* c, pd_JunctionV3X2_t* v);
parser_error_t _readJunctionV3X3(parser_context_t* c, pd_JunctionV3X3_t* v);
parser_error_t _readJunctionV3X4(parser_context_t* c, pd_JunctionV3X4_t* v);
parser_error_t _readJunctionV3X5(parser_context_t* c, pd_JunctionV3X5_t* v);
parser_error_t _readJunctionV3X6(parser_context_t* c, pd_JunctionV3X6_t* v);
parser_error_t _readJunctionV3X7(parser_context_t* c, pd_JunctionV3X7_t* v);
parser_error_t _readJunctionV3X8(parser_context_t* c, pd_JunctionV3X8_t* v);
parser_error_t _readJunctionsV0(parser_context_t* c, pd_JunctionsV0_t* v);
parser_error_t _readJunctionsV1(parser_context_t* c, pd_JunctionsV1_t* v);
parser_error_t _readJunctionsV2(parser_context_t* c, pd_JunctionsV2_t* v);
parser_error_t _readJunctionsV3(parser_context_t* c, pd_JunctionsV3_t* v);
parser_error_t _readAssetInstance(parser_context_t* c, pd_AssetInstance_t* v);
parser_error_t _readAssetInstanceV2(parser_context_t* c, pd_AssetInstanceV2_t* v);
parser_error_t _readAssetInstanceV3(parser_context_t* c, pd_AssetInstanceV3_t* v);
parser_error_t _readMultiLocationV0(parser_context_t* c, pd_MultiLocationV0_t* v);
parser_error_t _readMultiLocationV1(parser_context_t* c, pd_MultiLocationV1_t* v);
parser_error_t _readMultiLocationV2(parser_context_t* c, pd_MultiLocationV2_t* v);
parser_error_t _readMultiLocationV3(parser_context_t* c, pd_MultiLocationV3_t* v);
parser_error_t _readAbstractFungible(parser_context_t* c, pd_AbstractFungible_t* v);
parser_error_t _readAbstractNonFungible(parser_context_t* c, pd_AbstractNonFungible_t* v);
parser_error_t _readConcreteFungible(parser_context_t* c, pd_ConcreteFungible_t* v);
parser_error_t _readConcreteNonFungible(parser_context_t* c, pd_ConcreteNonFungible_t* v);
parser_error_t _readFungibility(parser_context_t* c, pd_Fungibility_t* v);
parser_error_t _readFungibilityV2(parser_context_t* c, pd_FungibilityV2_t* v);
parser_error_t _readFungibilityV3(parser_context_t* c, pd_FungibilityV3_t* v);
parser_error_t _readMultiAssetId(parser_context_t* c, pd_MultiAssetId_t* v);
parser_error_t _readMultiAssetIdV2(parser_context_t* c, pd_MultiAssetIdV2_t* v);
parser_error_t _readMultiAssetIdV3(parser_context_t* c, pd_MultiAssetIdV3_t* v);
parser_error_t _readAccountId(parser_context_t* c, pd_AccountId_t* v);
parser_error_t _readBalance(parser_context_t* c, pd_Balance_t* v);
parser_error_t _readCompactAccountIndex(parser_context_t* c, pd_CompactAccountIndex_t* v);
parser_error_t _readMultiAssetV0(parser_context_t* c, pd_MultiAssetV0_t* v);
parser_error_t _readMultiAssetV1(parser_context_t* c, pd_MultiAssetV1_t* v);
parser_error_t _readMultiAssetV2(parser_context_t* c, pd_MultiAssetV2_t* v);
parser_error_t _readMultiAssetV3(parser_context_t* c, pd_MultiAssetV3_t* v);
parser_error_t _readAccountIdLookupOfT(parser_context_t* c, pd_AccountIdLookupOfT_t* v);
parser_error_t _readCall(parser_context_t* c, pd_Call_t* v);
parser_error_t _readChargeAssetIdOf(parser_context_t* c, pd_ChargeAssetIdOf_t* v);
parser_error_t _readCollectionId(parser_context_t* c, pd_CollectionId_t* v);
parser_error_t _readItemId(parser_context_t* c, pd_ItemId_t* v);
parser_error_t _readItemPrice(parser_context_t* c, pd_ItemPrice_t* v);
parser_error_t _readProxyType(parser_context_t* c, pd_ProxyType_t* v);
parser_error_t _readTimepoint(parser_context_t* c, pd_Timepoint_t* v);
parser_error_t _readVecMultiAssetV0(parser_context_t* c, pd_VecMultiAssetV0_t* v);
parser_error_t _readVecMultiAssetV1(parser_context_t* c, pd_VecMultiAssetV1_t* v);
parser_error_t _readVecMultiAssetV2(parser_context_t* c, pd_VecMultiAssetV2_t* v);
parser_error_t _readVecMultiAssetV3(parser_context_t* c, pd_VecMultiAssetV3_t* v);
parser_error_t _readWeight(parser_context_t* c, pd_Weight_t* v);
parser_error_t _readBoxVersionedMultiAssets(parser_context_t* c, pd_BoxVersionedMultiAssets_t* v);
parser_error_t _readBoxVersionedMultiLocation(parser_context_t* c, pd_BoxVersionedMultiLocation_t* v);
parser_error_t _readDestroyWitness(parser_context_t* c, pd_DestroyWitness_t* v);
parser_error_t _readOptionAccountIdLookupOfT(parser_context_t* c, pd_OptionAccountIdLookupOfT_t* v);
parser_error_t _readOptionItemPrice(parser_context_t* c, pd_OptionItemPrice_t* v);
parser_error_t _readOptionTimepoint(parser_context_t* c, pd_OptionTimepoint_t* v);
parser_error_t _readVecCall(parser_context_t* c, pd_VecCall_t* v);
parser_error_t _readWeightLimit(parser_context_t* c, pd_WeightLimit_t* v);
parser_error_t _readBoundedVecu8(parser_context_t* c, pd_BoundedVecu8_t* v);
parser_error_t _readCallHashOf(parser_context_t* c, pd_CallHashOf_t* v);
parser_error_t _readH256(parser_context_t* c, pd_H256_t* v);
parser_error_t _readHash(parser_context_t* c, pd_Hash_t* v);
parser_error_t _readKeys(parser_context_t* c, pd_Keys_t* v);
parser_error_t _readOptionChargeAssetIdOf(parser_context_t* c, pd_OptionChargeAssetIdOf_t* v);
parser_error_t _readOptionCollectionId(parser_context_t* c, pd_OptionCollectionId_t* v);
parser_error_t _readOptionItemId(parser_context_t* c, pd_OptionItemId_t* v);
parser_error_t _readOptionProxyType(parser_context_t* c, pd_OptionProxyType_t* v);
parser_error_t _readOverweightIndex(parser_context_t* c, pd_OverweightIndex_t* v);
parser_error_t _readVecAccountId(parser_context_t* c, pd_VecAccountId_t* v);
parser_error_t _readVecItemId(parser_context_t* c, pd_VecItemId_t* v);
parser_error_t _readVecu8(parser_context_t* c, pd_Vecu8_t* v);
parser_error_t _readXcmWeight(parser_context_t* c, pd_XcmWeight_t* v);

// Common toString functions

parser_error_t _toStringu8(
    const pd_u8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu16(
    const pd_u16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu32(
    const pd_u32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu64(
    const pd_u64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringbool(
    const pd_bool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBlockNumber(
    const pd_BlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu64(
    const pd_Compactu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32(
    const pd_u8_array_32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringByFork(
    const pd_ByFork_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBytes(
    const pd_Bytes_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFraction(
    const pd_Fraction_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkIdV3(
    const pd_NetworkIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId(
    const pd_BodyId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyIdV2(
    const pd_BodyIdV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyIdV3(
    const pd_BodyIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart(
    const pd_BodyPart_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId(
    const pd_NetworkId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkIdV2(
    const pd_NetworkIdV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionNetworkIdV3(
    const pd_OptionNetworkIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_20(
    const pd_u8_array_20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32(
    const pd_AccountId32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32V2(
    const pd_AccountId32V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32V3(
    const pd_AccountId32V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64(
    const pd_AccountIndex64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64V2(
    const pd_AccountIndex64V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64V3(
    const pd_AccountIndex64V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20(
    const pd_AccountKey20_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20V2(
    const pd_AccountKey20V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20V3(
    const pd_AccountKey20V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu128(
    const pd_Compactu128_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringGeneralKeyV3(
    const pd_GeneralKeyV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality(
    const pd_Plurality_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPluralityV2(
    const pd_PluralityV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPluralityV3(
    const pd_PluralityV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0(
    const pd_JunctionV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1(
    const pd_JunctionV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2(
    const pd_JunctionV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3(
    const pd_JunctionV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X1(
    const pd_JunctionV0X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X2(
    const pd_JunctionV0X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X3(
    const pd_JunctionV0X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X4(
    const pd_JunctionV0X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X5(
    const pd_JunctionV0X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X6(
    const pd_JunctionV0X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X7(
    const pd_JunctionV0X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X8(
    const pd_JunctionV0X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X1(
    const pd_JunctionV1X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X2(
    const pd_JunctionV1X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X3(
    const pd_JunctionV1X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X4(
    const pd_JunctionV1X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X5(
    const pd_JunctionV1X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X6(
    const pd_JunctionV1X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X7(
    const pd_JunctionV1X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X8(
    const pd_JunctionV1X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X1(
    const pd_JunctionV2X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X2(
    const pd_JunctionV2X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X3(
    const pd_JunctionV2X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X4(
    const pd_JunctionV2X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X5(
    const pd_JunctionV2X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X6(
    const pd_JunctionV2X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X7(
    const pd_JunctionV2X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV2X8(
    const pd_JunctionV2X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X1(
    const pd_JunctionV3X1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X2(
    const pd_JunctionV3X2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X3(
    const pd_JunctionV3X3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X4(
    const pd_JunctionV3X4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X5(
    const pd_JunctionV3X5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X6(
    const pd_JunctionV3X6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X7(
    const pd_JunctionV3X7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV3X8(
    const pd_JunctionV3X8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV0(
    const pd_JunctionsV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV1(
    const pd_JunctionsV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV2(
    const pd_JunctionsV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV3(
    const pd_JunctionsV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstance(
    const pd_AssetInstance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstanceV2(
    const pd_AssetInstanceV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstanceV3(
    const pd_AssetInstanceV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0(
    const pd_MultiLocationV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1(
    const pd_MultiLocationV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV2(
    const pd_MultiLocationV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV3(
    const pd_MultiLocationV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractFungible(
    const pd_AbstractFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractNonFungible(
    const pd_AbstractNonFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteFungible(
    const pd_ConcreteFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteNonFungible(
    const pd_ConcreteNonFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungibility(
    const pd_Fungibility_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungibilityV2(
    const pd_FungibilityV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungibilityV3(
    const pd_FungibilityV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetId(
    const pd_MultiAssetId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetIdV2(
    const pd_MultiAssetIdV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetIdV3(
    const pd_MultiAssetIdV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId(
    const pd_AccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalance(
    const pd_Balance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex(
    const pd_CompactAccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV0(
    const pd_MultiAssetV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV1(
    const pd_MultiAssetV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV2(
    const pd_MultiAssetV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV3(
    const pd_MultiAssetV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT(
    const pd_AccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCall(
    const pd_Call_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChargeAssetIdOf(
    const pd_ChargeAssetIdOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCollectionId(
    const pd_CollectionId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemId(
    const pd_ItemId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemPrice(
    const pd_ItemPrice_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType(
    const pd_ProxyType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint(
    const pd_Timepoint_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV0(
    const pd_VecMultiAssetV0_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV1(
    const pd_VecMultiAssetV1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV2(
    const pd_VecMultiAssetV2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV3(
    const pd_VecMultiAssetV3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight(
    const pd_Weight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets(
    const pd_BoxVersionedMultiAssets_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation(
    const pd_BoxVersionedMultiLocation_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness(
    const pd_DestroyWitness_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountIdLookupOfT(
    const pd_OptionAccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemPrice(
    const pd_OptionItemPrice_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint(
    const pd_OptionTimepoint_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCall(
    const pd_VecCall_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit(
    const pd_WeightLimit_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8(
    const pd_BoundedVecu8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf(
    const pd_CallHashOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringH256(
    const pd_H256_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys(
    const pd_Keys_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChargeAssetIdOf(
    const pd_OptionChargeAssetIdOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionCollectionId(
    const pd_OptionCollectionId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemId(
    const pd_OptionItemId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType(
    const pd_OptionProxyType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex(
    const pd_OverweightIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId(
    const pd_VecAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecItemId(
    const pd_VecItemId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecu8(
    const pd_Vecu8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmWeight(
    const pd_XcmWeight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
