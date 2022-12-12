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

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    pd_Compactu32_t nom;
    pd_Compactu32_t denom;
} pd_Fraction_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t named;
        pd_Compactu32_t index;
    };
} pd_BodyId_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t count;
        pd_Fraction_V10_t fraction;
    };
} pd_BodyPart_V10_t;

typedef struct {
    uint8_t value;
    pd_Bytes_t named;
} pd_NetworkId_V10_t;

typedef struct {
    const uint8_t* _ptr;
} pd_u8_array_32_V10_t;

typedef struct {
    pd_NetworkId_V10_t networkId;
    pd_u8_array_32_V10_t key;
} pd_AccountId32_V10_t;

typedef struct {
    pd_NetworkId_V10_t networkId;
    pd_Compactu64_t index;
} pd_AccountIndex64_V10_t;

typedef struct {
    pd_NetworkId_V10_t networkId;
    pd_u8_array_20_t key;
} pd_AccountKey20_V10_t;

typedef struct {
    pd_BodyId_V10_t id;
    pd_BodyPart_V10_t part;
} pd_Plurality_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V10_t accountId32;
        pd_AccountIndex64_V10_t accountIndex64;
        pd_AccountKey20_V10_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_V10_t plurality;
    };
} pd_JunctionV0_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu32_t parachain;
        pd_AccountId32_V10_t accountId32;
        pd_AccountIndex64_V10_t accountIndex64;
        pd_AccountKey20_V10_t accountKey20;
        uint8_t palletInstance;
        pd_Compactu128_t generalIndex;
        pd_Bytes_t generalKey;
        pd_Plurality_V10_t plurality;
    };
} pd_JunctionV1_V10_t;

typedef struct {
    pd_JunctionV0_V10_t junction;
} pd_JunctionV0X1_V10_t;

typedef struct {
    pd_JunctionV0_V10_t junction0;
    pd_JunctionV0_V10_t junction1;
} pd_JunctionV0X2_V10_t;

typedef struct {
    pd_JunctionV0_V10_t junction0;
    pd_JunctionV0_V10_t junction1;
    pd_JunctionV0_V10_t junction2;
} pd_JunctionV0X3_V10_t;

typedef struct {
    pd_JunctionV0_V10_t junction0;
    pd_JunctionV0_V10_t junction1;
    pd_JunctionV0_V10_t junction2;
    pd_JunctionV0_V10_t junction3;
} pd_JunctionV0X4_V10_t;

typedef struct {
    pd_JunctionV0_V10_t junction0;
    pd_JunctionV0_V10_t junction1;
    pd_JunctionV0_V10_t junction2;
    pd_JunctionV0_V10_t junction3;
    pd_JunctionV0_V10_t junction4;
} pd_JunctionV0X5_V10_t;

typedef struct {
    pd_JunctionV0_V10_t junction0;
    pd_JunctionV0_V10_t junction1;
    pd_JunctionV0_V10_t junction2;
    pd_JunctionV0_V10_t junction3;
    pd_JunctionV0_V10_t junction4;
    pd_JunctionV0_V10_t junction5;
} pd_JunctionV0X6_V10_t;

typedef struct {
    pd_JunctionV0_V10_t junction0;
    pd_JunctionV0_V10_t junction1;
    pd_JunctionV0_V10_t junction2;
    pd_JunctionV0_V10_t junction3;
    pd_JunctionV0_V10_t junction4;
    pd_JunctionV0_V10_t junction5;
    pd_JunctionV0_V10_t junction6;
} pd_JunctionV0X7_V10_t;

typedef struct {
    pd_JunctionV0_V10_t junction0;
    pd_JunctionV0_V10_t junction1;
    pd_JunctionV0_V10_t junction2;
    pd_JunctionV0_V10_t junction3;
    pd_JunctionV0_V10_t junction4;
    pd_JunctionV0_V10_t junction5;
    pd_JunctionV0_V10_t junction6;
    pd_JunctionV0_V10_t junction7;
} pd_JunctionV0X8_V10_t;

typedef struct {
    pd_JunctionV1_V10_t junction;
} pd_JunctionV1X1_V10_t;

typedef struct {
    pd_JunctionV1_V10_t junction0;
    pd_JunctionV1_V10_t junction1;
} pd_JunctionV1X2_V10_t;

typedef struct {
    pd_JunctionV1_V10_t junction0;
    pd_JunctionV1_V10_t junction1;
    pd_JunctionV1_V10_t junction2;
} pd_JunctionV1X3_V10_t;

typedef struct {
    pd_JunctionV1_V10_t junction0;
    pd_JunctionV1_V10_t junction1;
    pd_JunctionV1_V10_t junction2;
    pd_JunctionV1_V10_t junction3;
} pd_JunctionV1X4_V10_t;

typedef struct {
    pd_JunctionV1_V10_t junction0;
    pd_JunctionV1_V10_t junction1;
    pd_JunctionV1_V10_t junction2;
    pd_JunctionV1_V10_t junction3;
    pd_JunctionV1_V10_t junction4;
} pd_JunctionV1X5_V10_t;

typedef struct {
    pd_JunctionV1_V10_t junction0;
    pd_JunctionV1_V10_t junction1;
    pd_JunctionV1_V10_t junction2;
    pd_JunctionV1_V10_t junction3;
    pd_JunctionV1_V10_t junction4;
    pd_JunctionV1_V10_t junction5;
} pd_JunctionV1X6_V10_t;

typedef struct {
    pd_JunctionV1_V10_t junction0;
    pd_JunctionV1_V10_t junction1;
    pd_JunctionV1_V10_t junction2;
    pd_JunctionV1_V10_t junction3;
    pd_JunctionV1_V10_t junction4;
    pd_JunctionV1_V10_t junction5;
    pd_JunctionV1_V10_t junction6;
} pd_JunctionV1X7_V10_t;

typedef struct {
    pd_JunctionV1_V10_t junction0;
    pd_JunctionV1_V10_t junction1;
    pd_JunctionV1_V10_t junction2;
    pd_JunctionV1_V10_t junction3;
    pd_JunctionV1_V10_t junction4;
    pd_JunctionV1_V10_t junction5;
    pd_JunctionV1_V10_t junction6;
    pd_JunctionV1_V10_t junction7;
} pd_JunctionV1X8_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV0X1_V10_t x1;
        pd_JunctionV0X2_V10_t x2;
        pd_JunctionV0X3_V10_t x3;
        pd_JunctionV0X4_V10_t x4;
        pd_JunctionV0X5_V10_t x5;
        pd_JunctionV0X6_V10_t x6;
        pd_JunctionV0X7_V10_t x7;
        pd_JunctionV0X8_V10_t x8;
    };
} pd_JunctionsV0_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_JunctionV1X1_V10_t x1;
        pd_JunctionV1X2_V10_t x2;
        pd_JunctionV1X3_V10_t x3;
        pd_JunctionV1X4_V10_t x4;
        pd_JunctionV1X5_V10_t x5;
        pd_JunctionV1X6_V10_t x6;
        pd_JunctionV1X7_V10_t x7;
        pd_JunctionV1X8_V10_t x8;
    };
} pd_JunctionsV1_V10_t;

typedef struct {
    uint8_t value;
    union {
        const uint8_t* _ptr;
        pd_Compactu128_t index;
        pd_Bytes_t blob;
    };
} pd_AssetInstance_V10_t;

typedef struct {
    pd_JunctionsV0_V10_t junctions;
} pd_MultiLocationV0_V10_t;

typedef struct {
    uint8_t parents;
    pd_JunctionsV1_V10_t interior;
} pd_MultiLocationV1_V10_t;

typedef struct {
    pd_Bytes_t id;
    pd_Compactu128_t amount;
} pd_AbstractFungible_V10_t;

typedef struct {
    pd_Bytes_t _class;
    pd_AssetInstance_V10_t instance;
} pd_AbstractNonFungible_V10_t;

typedef struct {
    pd_MultiLocationV0_V10_t id;
    pd_CompactBalance_t amount;
} pd_ConcreteFungible_V10_t;

typedef struct {
    pd_MultiLocationV0_V10_t _class;
    pd_AssetInstance_V10_t instance;
} pd_ConcreteNonFungible_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_Compactu128_t fungible;
        pd_AssetInstance_V10_t nonFungible;
    };
} pd_Fungibility_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV1_V10_t concrete;
        pd_Bytes_t abstract;
    };
} pd_MultiAssetId_V10_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V10_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_Bytes_t abstract;
        pd_MultiLocationV0_V10_t concrete;
        pd_AbstractFungible_V10_t abstractFungible;
        pd_AbstractNonFungible_V10_t abstractNonFungible;
        pd_ConcreteFungible_V10_t concreteFungible;
        pd_ConcreteNonFungible_V10_t concreteNonFungible;
    };
} pd_MultiAssetV0_V10_t;

typedef struct {
    pd_MultiAssetId_V10_t assetId;
    pd_Fungibility_V10_t fungibility;
} pd_MultiAssetV1_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V10_t id;
        pd_CompactAccountIndex_V10_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_AccountIdLookupOfT_V10_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChargeAssetIdOf_V10_t;

typedef struct {
    uint32_t value;
} pd_CollectionId_V10_t;

typedef struct {
    uint32_t value;
} pd_ItemId_V10_t;

typedef struct {
    pd_Balance_t value;
} pd_ItemPrice_V10_t;

typedef struct {
    uint8_t value;
} pd_ProxyType_V10_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V10_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV0_V10_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMultiAssetV1_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_VecMultiAssetV0_V10_t vecMultiassetV0;
        pd_VecMultiAssetV1_V10_t vecMultiassetV1;
    };
} pd_BoxVersionedMultiAssets_V10_t;

typedef struct {
    uint8_t value;
    union {
        pd_MultiLocationV0_V10_t multilocationV0;
        pd_MultiLocationV1_V10_t multilocationV1;
    };
} pd_BoxVersionedMultiLocation_V10_t;

typedef struct {
    pd_Compactu32_t accounts;
    pd_Compactu32_t sufficients;
    pd_Compactu32_t approvals;
} pd_DestroyWitness_V10_t;

typedef struct {
    uint8_t some;
    pd_AccountIdLookupOfT_V10_t contained;
} pd_OptionAccountIdLookupOfT_V10_t;

typedef struct {
    uint8_t some;
    pd_ItemPrice_V10_t contained;
} pd_OptionItemPrice_V10_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V10_t contained;
} pd_OptionTimepoint_V10_t;

typedef struct {
    uint8_t value;
    pd_Compactu64_t limited;
} pd_WeightLimit_V10_t;

typedef struct {
    pd_Compactu64_t refTime;
    pd_Compactu64_t proofSize;
} pd_Weight_V10_t;

typedef struct {
    uint64_t _len;
    uint64_t _lenBuffer;
    const uint8_t* _ptr;
} pd_BoundedVecu8_V10_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CallHashOf_V10_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V10_t;

typedef struct {
    uint8_t some;
    pd_CollectionId_V10_t contained;
} pd_OptionCollectionId_V10_t;

typedef struct {
    uint8_t some;
    pd_ItemId_V10_t contained;
} pd_OptionItemId_V10_t;

typedef struct {
    uint8_t some;
    pd_ProxyType_V10_t contained;
} pd_OptionProxyType_V10_t;

typedef struct {
    uint64_t value;
} pd_OverweightIndex_V10_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V10_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V10_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecItemId_V10_t;

typedef struct {
    uint64_t value;
} pd_XcmWeight_V10_t;

#ifdef __cplusplus
}
#endif
