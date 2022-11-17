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
#include "substrate_methods_V9.h"
#include "substrate_types_V9.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAbstractFungible_V9(parser_context_t* c, pd_AbstractFungible_V9_t* v);
parser_error_t _readAbstractNonFungible_V9(parser_context_t* c, pd_AbstractNonFungible_V9_t* v);
parser_error_t _readAccountId32_V9(parser_context_t* c, pd_AccountId32_V9_t* v);
parser_error_t _readAccountIdLookupOfT_V9(parser_context_t* c, pd_AccountIdLookupOfT_V9_t* v);
parser_error_t _readAccountId_V9(parser_context_t* c, pd_AccountId_V9_t* v);
parser_error_t _readAccountIndex64_V9(parser_context_t* c, pd_AccountIndex64_V9_t* v);
parser_error_t _readAccountKey20_V9(parser_context_t* c, pd_AccountKey20_V9_t* v);
parser_error_t _readAssetInstance_V9(parser_context_t* c, pd_AssetInstance_V9_t* v);
parser_error_t _readBodyId_V9(parser_context_t* c, pd_BodyId_V9_t* v);
parser_error_t _readBodyPart_V9(parser_context_t* c, pd_BodyPart_V9_t* v);
parser_error_t _readBoundedVecu8_V9(parser_context_t* c, pd_BoundedVecu8_V9_t* v);
parser_error_t _readBoxVersionedMultiAssets_V9(parser_context_t* c, pd_BoxVersionedMultiAssets_V9_t* v);
parser_error_t _readBoxVersionedMultiLocation_V9(parser_context_t* c, pd_BoxVersionedMultiLocation_V9_t* v);
parser_error_t _readCallHashOf_V9(parser_context_t* c, pd_CallHashOf_V9_t* v);
parser_error_t _readChargeAssetIdOf_V9(parser_context_t* c, pd_ChargeAssetIdOf_V9_t* v);
parser_error_t _readCollectionId_V9(parser_context_t* c, pd_CollectionId_V9_t* v);
parser_error_t _readCompactAccountIndex_V9(parser_context_t* c, pd_CompactAccountIndex_V9_t* v);
parser_error_t _readConcreteFungible_V9(parser_context_t* c, pd_ConcreteFungible_V9_t* v);
parser_error_t _readConcreteNonFungible_V9(parser_context_t* c, pd_ConcreteNonFungible_V9_t* v);
parser_error_t _readDestroyWitness_V9(parser_context_t* c, pd_DestroyWitness_V9_t* v);
parser_error_t _readFraction_V9(parser_context_t* c, pd_Fraction_V9_t* v);
parser_error_t _readFungibility_V9(parser_context_t* c, pd_Fungibility_V9_t* v);
parser_error_t _readItemId_V9(parser_context_t* c, pd_ItemId_V9_t* v);
parser_error_t _readItemPrice_V9(parser_context_t* c, pd_ItemPrice_V9_t* v);
parser_error_t _readJunctionV0X1_V9(parser_context_t* c, pd_JunctionV0X1_V9_t* v);
parser_error_t _readJunctionV0X2_V9(parser_context_t* c, pd_JunctionV0X2_V9_t* v);
parser_error_t _readJunctionV0X3_V9(parser_context_t* c, pd_JunctionV0X3_V9_t* v);
parser_error_t _readJunctionV0X4_V9(parser_context_t* c, pd_JunctionV0X4_V9_t* v);
parser_error_t _readJunctionV0X5_V9(parser_context_t* c, pd_JunctionV0X5_V9_t* v);
parser_error_t _readJunctionV0X6_V9(parser_context_t* c, pd_JunctionV0X6_V9_t* v);
parser_error_t _readJunctionV0X7_V9(parser_context_t* c, pd_JunctionV0X7_V9_t* v);
parser_error_t _readJunctionV0X8_V9(parser_context_t* c, pd_JunctionV0X8_V9_t* v);
parser_error_t _readJunctionV0_V9(parser_context_t* c, pd_JunctionV0_V9_t* v);
parser_error_t _readJunctionV1X1_V9(parser_context_t* c, pd_JunctionV1X1_V9_t* v);
parser_error_t _readJunctionV1X2_V9(parser_context_t* c, pd_JunctionV1X2_V9_t* v);
parser_error_t _readJunctionV1X3_V9(parser_context_t* c, pd_JunctionV1X3_V9_t* v);
parser_error_t _readJunctionV1X4_V9(parser_context_t* c, pd_JunctionV1X4_V9_t* v);
parser_error_t _readJunctionV1X5_V9(parser_context_t* c, pd_JunctionV1X5_V9_t* v);
parser_error_t _readJunctionV1X6_V9(parser_context_t* c, pd_JunctionV1X6_V9_t* v);
parser_error_t _readJunctionV1X7_V9(parser_context_t* c, pd_JunctionV1X7_V9_t* v);
parser_error_t _readJunctionV1X8_V9(parser_context_t* c, pd_JunctionV1X8_V9_t* v);
parser_error_t _readJunctionV1_V9(parser_context_t* c, pd_JunctionV1_V9_t* v);
parser_error_t _readJunctionsV0_V9(parser_context_t* c, pd_JunctionsV0_V9_t* v);
parser_error_t _readJunctionsV1_V9(parser_context_t* c, pd_JunctionsV1_V9_t* v);
parser_error_t _readKeys_V9(parser_context_t* c, pd_Keys_V9_t* v);
parser_error_t _readMultiAssetId_V9(parser_context_t* c, pd_MultiAssetId_V9_t* v);
parser_error_t _readMultiAssetV0_V9(parser_context_t* c, pd_MultiAssetV0_V9_t* v);
parser_error_t _readMultiAssetV1_V9(parser_context_t* c, pd_MultiAssetV1_V9_t* v);
parser_error_t _readMultiLocationV0_V9(parser_context_t* c, pd_MultiLocationV0_V9_t* v);
parser_error_t _readMultiLocationV1_V9(parser_context_t* c, pd_MultiLocationV1_V9_t* v);
parser_error_t _readNetworkId_V9(parser_context_t* c, pd_NetworkId_V9_t* v);
parser_error_t _readOptionAccountIdLookupOfT_V9(parser_context_t* c, pd_OptionAccountIdLookupOfT_V9_t* v);
parser_error_t _readOptionCollectionId_V9(parser_context_t* c, pd_OptionCollectionId_V9_t* v);
parser_error_t _readOptionItemId_V9(parser_context_t* c, pd_OptionItemId_V9_t* v);
parser_error_t _readOptionItemPrice_V9(parser_context_t* c, pd_OptionItemPrice_V9_t* v);
parser_error_t _readOptionProxyType_V9(parser_context_t* c, pd_OptionProxyType_V9_t* v);
parser_error_t _readOptionTimepoint_V9(parser_context_t* c, pd_OptionTimepoint_V9_t* v);
parser_error_t _readOverweightIndex_V9(parser_context_t* c, pd_OverweightIndex_V9_t* v);
parser_error_t _readPerbill_V9(parser_context_t* c, pd_Perbill_V9_t* v);
parser_error_t _readPlurality_V9(parser_context_t* c, pd_Plurality_V9_t* v);
parser_error_t _readProxyType_V9(parser_context_t* c, pd_ProxyType_V9_t* v);
parser_error_t _readTimepoint_V9(parser_context_t* c, pd_Timepoint_V9_t* v);
parser_error_t _readVecAccountId_V9(parser_context_t* c, pd_VecAccountId_V9_t* v);
parser_error_t _readVecItemId_V9(parser_context_t* c, pd_VecItemId_V9_t* v);
parser_error_t _readVecMultiAssetV0_V9(parser_context_t* c, pd_VecMultiAssetV0_V9_t* v);
parser_error_t _readVecMultiAssetV1_V9(parser_context_t* c, pd_VecMultiAssetV1_V9_t* v);
parser_error_t _readWeightLimit_V9(parser_context_t* c, pd_WeightLimit_V9_t* v);
parser_error_t _readWeight_V9(parser_context_t* c, pd_Weight_V9_t* v);
parser_error_t _readXcmWeight_V9(parser_context_t* c, pd_XcmWeight_V9_t* v);
parser_error_t _readu8_array_32_V9(parser_context_t* c, pd_u8_array_32_V9_t* v);

// toString functions
parser_error_t _toStringAbstractFungible_V9(
    const pd_AbstractFungible_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAbstractNonFungible_V9(
    const pd_AbstractNonFungible_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId32_V9(
    const pd_AccountId32_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT_V9(
    const pd_AccountIdLookupOfT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V9(
    const pd_AccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex64_V9(
    const pd_AccountIndex64_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountKey20_V9(
    const pd_AccountKey20_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetInstance_V9(
    const pd_AssetInstance_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyId_V9(
    const pd_BodyId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBodyPart_V9(
    const pd_BodyPart_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoundedVecu8_V9(
    const pd_BoundedVecu8_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V9(
    const pd_BoxVersionedMultiAssets_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V9(
    const pd_BoxVersionedMultiLocation_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V9(
    const pd_CallHashOf_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChargeAssetIdOf_V9(
    const pd_ChargeAssetIdOf_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCollectionId_V9(
    const pd_CollectionId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V9(
    const pd_CompactAccountIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteFungible_V9(
    const pd_ConcreteFungible_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConcreteNonFungible_V9(
    const pd_ConcreteNonFungible_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDestroyWitness_V9(
    const pd_DestroyWitness_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFraction_V9(
    const pd_Fraction_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFungibility_V9(
    const pd_Fungibility_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemId_V9(
    const pd_ItemId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItemPrice_V9(
    const pd_ItemPrice_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X1_V9(
    const pd_JunctionV0X1_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X2_V9(
    const pd_JunctionV0X2_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X3_V9(
    const pd_JunctionV0X3_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X4_V9(
    const pd_JunctionV0X4_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X5_V9(
    const pd_JunctionV0X5_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X6_V9(
    const pd_JunctionV0X6_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X7_V9(
    const pd_JunctionV0X7_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0X8_V9(
    const pd_JunctionV0X8_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV0_V9(
    const pd_JunctionV0_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X1_V9(
    const pd_JunctionV1X1_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X2_V9(
    const pd_JunctionV1X2_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X3_V9(
    const pd_JunctionV1X3_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X4_V9(
    const pd_JunctionV1X4_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X5_V9(
    const pd_JunctionV1X5_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X6_V9(
    const pd_JunctionV1X6_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X7_V9(
    const pd_JunctionV1X7_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1X8_V9(
    const pd_JunctionV1X8_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionV1_V9(
    const pd_JunctionV1_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV0_V9(
    const pd_JunctionsV0_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJunctionsV1_V9(
    const pd_JunctionsV1_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V9(
    const pd_Keys_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetId_V9(
    const pd_MultiAssetId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV0_V9(
    const pd_MultiAssetV0_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiAssetV1_V9(
    const pd_MultiAssetV1_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV0_V9(
    const pd_MultiLocationV0_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiLocationV1_V9(
    const pd_MultiLocationV1_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNetworkId_V9(
    const pd_NetworkId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountIdLookupOfT_V9(
    const pd_OptionAccountIdLookupOfT_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionCollectionId_V9(
    const pd_OptionCollectionId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemId_V9(
    const pd_OptionItemId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionItemPrice_V9(
    const pd_OptionItemPrice_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V9(
    const pd_OptionProxyType_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V9(
    const pd_OptionTimepoint_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V9(
    const pd_OverweightIndex_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V9(
    const pd_Perbill_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPlurality_V9(
    const pd_Plurality_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V9(
    const pd_ProxyType_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V9(
    const pd_Timepoint_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V9(
    const pd_VecAccountId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecItemId_V9(
    const pd_VecItemId_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV0_V9(
    const pd_VecMultiAssetV0_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMultiAssetV1_V9(
    const pd_VecMultiAssetV1_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V9(
    const pd_WeightLimit_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V9(
    const pd_Weight_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmWeight_V9(
    const pd_XcmWeight_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu8_array_32_V9(
    const pd_u8_array_32_V9_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
