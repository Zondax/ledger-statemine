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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V13.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V13 0
#define PD_CALL_TIMESTAMP_V13 3
#define PD_CALL_BALANCES_V13 10
#define PD_CALL_COLLATORSELECTION_V13 21
#define PD_CALL_SESSION_V13 22
#define PD_CALL_XCMPQUEUE_V13 30
#define PD_CALL_POLKADOTXCM_V13 31
#define PD_CALL_DMPQUEUE_V13 33
#define PD_CALL_UTILITY_V13 40
#define PD_CALL_MULTISIG_V13 41
#define PD_CALL_PROXY_V13 42
#define PD_CALL_ASSETS_V13 50
#define PD_CALL_UNIQUES_V13 51
#define PD_CALL_NFTS_V13 52
#define PD_CALL_FOREIGNASSETS_V13 53

#define PD_CALL_BALANCES_TRANSFER_ALL_V13 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V13_t;

#define PD_CALL_SESSION_SET_KEYS_V13 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V13_t;

#define PD_CALL_SESSION_PURGE_KEYS_V13 1
typedef struct {
} pd_session_purge_keys_V13_t;

#define PD_CALL_UTILITY_BATCH_V13 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V13_t;

#define PD_CALL_UTILITY_BATCH_ALL_V13 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V13_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#define PD_CALL_POLKADOTXCM_TELEPORT_ASSETS_V13 1
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_polkadotxcm_teleport_assets_V13_t;
#define PD_CALL_POLKADOTXCM_RESERVE_TRANSFER_ASSETS_V13 2
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
} pd_polkadotxcm_reserve_transfer_assets_V13_t;
#define PD_CALL_POLKADOTXCM_LIMITED_RESERVE_TRANSFER_ASSETS_V13 8
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_polkadotxcm_limited_reserve_transfer_assets_V13_t;
#define PD_CALL_POLKADOTXCM_LIMITED_TELEPORT_ASSETS_V13 9
typedef struct {
    pd_BoxVersionedMultiLocation_t dest;
    pd_BoxVersionedMultiLocation_t beneficiary;
    pd_BoxVersionedMultiAssets_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_t weight_limit;
} pd_polkadotxcm_limited_teleport_assets_V13_t;
#define PD_CALL_FOREIGNASSETS_CREATE_V13 0
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t admin;
    pd_Balance_t min_balance;
} pd_foreignassets_create_V13_t;
#define PD_CALL_FOREIGNASSETS_FORCE_CREATE_V13 1
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t owner;
    pd_bool_t is_sufficient;
    pd_CompactBalance_t min_balance;
} pd_foreignassets_force_create_V13_t;
#define PD_CALL_FOREIGNASSETS_START_DESTROY_V13 2
typedef struct {
    pd_AssetIdParameter_t id;
} pd_foreignassets_start_destroy_V13_t;
#define PD_CALL_FOREIGNASSETS_DESTROY_ACCOUNTS_V13 3
typedef struct {
    pd_AssetIdParameter_t id;
} pd_foreignassets_destroy_accounts_V13_t;
#define PD_CALL_FOREIGNASSETS_DESTROY_APPROVALS_V13 4
typedef struct {
    pd_AssetIdParameter_t id;
} pd_foreignassets_destroy_approvals_V13_t;
#define PD_CALL_FOREIGNASSETS_FINISH_DESTROY_V13 5
typedef struct {
    pd_AssetIdParameter_t id;
} pd_foreignassets_finish_destroy_V13_t;
#define PD_CALL_FOREIGNASSETS_MINT_V13 6
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t beneficiary;
    pd_CompactBalance_t amount;
} pd_foreignassets_mint_V13_t;
#define PD_CALL_FOREIGNASSETS_BURN_V13 7
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t amount;
} pd_foreignassets_burn_V13_t;
#define PD_CALL_FOREIGNASSETS_TRANSFER_V13 8
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t target;
    pd_CompactBalance_t amount;
} pd_foreignassets_transfer_V13_t;
#define PD_CALL_FOREIGNASSETS_TRANSFER_KEEP_ALIVE_V13 9
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t target;
    pd_CompactBalance_t amount;
} pd_foreignassets_transfer_keep_alive_V13_t;
#define PD_CALL_FOREIGNASSETS_FORCE_TRANSFER_V13 10
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_foreignassets_force_transfer_V13_t;
#define PD_CALL_FOREIGNASSETS_FREEZE_V13 11
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t who;
} pd_foreignassets_freeze_V13_t;
#define PD_CALL_FOREIGNASSETS_THAW_V13 12
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t who;
} pd_foreignassets_thaw_V13_t;
#define PD_CALL_FOREIGNASSETS_FREEZE_ASSET_V13 13
typedef struct {
    pd_AssetIdParameter_t id;
} pd_foreignassets_freeze_asset_V13_t;
#define PD_CALL_FOREIGNASSETS_THAW_ASSET_V13 14
typedef struct {
    pd_AssetIdParameter_t id;
} pd_foreignassets_thaw_asset_V13_t;
#define PD_CALL_FOREIGNASSETS_TRANSFER_OWNERSHIP_V13 15
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t owner;
} pd_foreignassets_transfer_ownership_V13_t;
#define PD_CALL_FOREIGNASSETS_SET_TEAM_V13 16
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
} pd_foreignassets_set_team_V13_t;
#define PD_CALL_FOREIGNASSETS_SET_METADATA_V13 17
typedef struct {
    pd_AssetIdParameter_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_foreignassets_set_metadata_V13_t;
#define PD_CALL_FOREIGNASSETS_CLEAR_METADATA_V13 18
typedef struct {
    pd_AssetIdParameter_t id;
} pd_foreignassets_clear_metadata_V13_t;
#define PD_CALL_FOREIGNASSETS_FORCE_SET_METADATA_V13 19
typedef struct {
    pd_AssetIdParameter_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_foreignassets_force_set_metadata_V13_t;
#define PD_CALL_FOREIGNASSETS_FORCE_CLEAR_METADATA_V13 20
typedef struct {
    pd_AssetIdParameter_t id;
} pd_foreignassets_force_clear_metadata_V13_t;
#define PD_CALL_FOREIGNASSETS_FORCE_ASSET_STATUS_V13 21
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t owner;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
    pd_CompactBalance_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_foreignassets_force_asset_status_V13_t;
#define PD_CALL_FOREIGNASSETS_APPROVE_TRANSFER_V13 22
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t delegate;
    pd_CompactBalance_t amount;
} pd_foreignassets_approve_transfer_V13_t;
#define PD_CALL_FOREIGNASSETS_CANCEL_APPROVAL_V13 23
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t delegate;
} pd_foreignassets_cancel_approval_V13_t;
#define PD_CALL_FOREIGNASSETS_FORCE_CANCEL_APPROVAL_V13 24
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t owner;
    pd_AccountIdLookupOfT_t delegate;
} pd_foreignassets_force_cancel_approval_V13_t;
#define PD_CALL_FOREIGNASSETS_TRANSFER_APPROVED_V13 25
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t owner;
    pd_AccountIdLookupOfT_t destination;
    pd_CompactBalance_t amount;
} pd_foreignassets_transfer_approved_V13_t;
#define PD_CALL_FOREIGNASSETS_TOUCH_V13 26
typedef struct {
    pd_AssetIdParameter_t id;
} pd_foreignassets_touch_V13_t;
#define PD_CALL_FOREIGNASSETS_REFUND_V13 27
typedef struct {
    pd_AssetIdParameter_t id;
    pd_bool_t allow_burn;
} pd_foreignassets_refund_V13_t;
#define PD_CALL_FOREIGNASSETS_SET_MIN_BALANCE_V13 28
typedef struct {
    pd_AssetIdParameter_t id;
    pd_Balance_t min_balance;
} pd_foreignassets_set_min_balance_V13_t;
#define PD_CALL_FOREIGNASSETS_TOUCH_OTHER_V13 29
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t who;
} pd_foreignassets_touch_other_V13_t;
#define PD_CALL_FOREIGNASSETS_REFUND_OTHER_V13 30
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t who;
} pd_foreignassets_refund_other_V13_t;
#define PD_CALL_FOREIGNASSETS_BLOCK_V13 31
typedef struct {
    pd_AssetIdParameter_t id;
    pd_AccountIdLookupOfT_t who;
} pd_foreignassets_block_V13_t;
#endif

#define PD_CALL_TIMESTAMP_SET_V13 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V13_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V13 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V13_t;

#define PD_CALL_BALANCES_UPGRADE_ACCOUNTS_V13 6
typedef struct {
    pd_VecAccountId_t who;
} pd_balances_upgrade_accounts_V13_t;

#define PD_CALL_BALANCES_FORCE_SET_BALANCE_V13 8
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
} pd_balances_force_set_balance_V13_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V13 0
typedef struct {
    pd_VecAccountId_t new_;
} pd_collatorselection_set_invulnerables_V13_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V13 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V13_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V13 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V13_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V13 3
typedef struct {
} pd_collatorselection_register_as_candidate_V13_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V13 4
typedef struct {
} pd_collatorselection_leave_intent_V13_t;

#define PD_CALL_XCMPQUEUE_SERVICE_OVERWEIGHT_V13 0
typedef struct {
    pd_OverweightIndex_t index;
    pd_Weight_t weight_limit;
} pd_xcmpqueue_service_overweight_V13_t;

#define PD_CALL_XCMPQUEUE_SUSPEND_XCM_EXECUTION_V13 1
typedef struct {
} pd_xcmpqueue_suspend_xcm_execution_V13_t;

#define PD_CALL_XCMPQUEUE_RESUME_XCM_EXECUTION_V13 2
typedef struct {
} pd_xcmpqueue_resume_xcm_execution_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_SUSPEND_THRESHOLD_V13 3
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_suspend_threshold_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_DROP_THRESHOLD_V13 4
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_drop_threshold_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_RESUME_THRESHOLD_V13 5
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_resume_threshold_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_THRESHOLD_WEIGHT_V13 6
typedef struct {
    pd_Weight_t new_;
} pd_xcmpqueue_update_threshold_weight_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_WEIGHT_RESTRICT_DECAY_V13 7
typedef struct {
    pd_Weight_t new_;
} pd_xcmpqueue_update_weight_restrict_decay_V13_t;

#define PD_CALL_XCMPQUEUE_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT_V13 8
typedef struct {
    pd_Weight_t new_;
} pd_xcmpqueue_update_xcmp_max_individual_weight_V13_t;

#define PD_CALL_DMPQUEUE_SERVICE_OVERWEIGHT_V13 0
typedef struct {
    pd_OverweightIndex_t index;
    pd_Weight_t weight_limit;
} pd_dmpqueue_service_overweight_V13_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V13 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V13_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V13 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V13_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V13 3
typedef struct {
} pd_proxy_remove_proxies_V13_t;

#define PD_CALL_PROXY_ANNOUNCE_V13 6
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_CallHashOf_t call_hash;
} pd_proxy_announce_V13_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V13 7
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_CallHashOf_t call_hash;
} pd_proxy_remove_announcement_V13_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V13 8
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_CallHashOf_t call_hash;
} pd_proxy_reject_announcement_V13_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V13 9
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V13_t;

#define PD_CALL_ASSETS_START_DESTROY_V13 2
typedef struct {
    pd_Compactu32_t id;
} pd_assets_start_destroy_V13_t;

#define PD_CALL_ASSETS_DESTROY_ACCOUNTS_V13 3
typedef struct {
    pd_Compactu32_t id;
} pd_assets_destroy_accounts_V13_t;

#define PD_CALL_ASSETS_DESTROY_APPROVALS_V13 4
typedef struct {
    pd_Compactu32_t id;
} pd_assets_destroy_approvals_V13_t;

#define PD_CALL_ASSETS_FINISH_DESTROY_V13 5
typedef struct {
    pd_Compactu32_t id;
} pd_assets_finish_destroy_V13_t;

#define PD_CALL_ASSETS_TOUCH_V13 26
typedef struct {
    pd_Compactu32_t id;
} pd_assets_touch_V13_t;

#define PD_CALL_ASSETS_REFUND_V13 27
typedef struct {
    pd_Compactu32_t id;
    pd_bool_t allow_burn;
} pd_assets_refund_V13_t;

#define PD_CALL_ASSETS_SET_MIN_BALANCE_V13 28
typedef struct {
    pd_Compactu32_t id;
    pd_Balance_t min_balance;
} pd_assets_set_min_balance_V13_t;

#define PD_CALL_ASSETS_TOUCH_OTHER_V13 29
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t who;
} pd_assets_touch_other_V13_t;

#define PD_CALL_ASSETS_REFUND_OTHER_V13 30
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t who;
} pd_assets_refund_other_V13_t;

#define PD_CALL_ASSETS_BLOCK_V13 31
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t who;
} pd_assets_block_V13_t;

#define PD_CALL_UNIQUES_CREATE_V13 0
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t admin;
} pd_uniques_create_V13_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V13 1
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V13_t;

#define PD_CALL_UNIQUES_DESTROY_V13 2
typedef struct {
    pd_CollectionId_t collection;
    pd_DestroyWitness_t witness;
} pd_uniques_destroy_V13_t;

#define PD_CALL_UNIQUES_MINT_V13 3
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t owner;
} pd_uniques_mint_V13_t;

#define PD_CALL_UNIQUES_BURN_V13 4
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionAccountIdLookupOfT_t check_owner;
} pd_uniques_burn_V13_t;

#define PD_CALL_UNIQUES_TRANSFER_V13 5
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t dest;
} pd_uniques_transfer_V13_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V13 6
typedef struct {
    pd_CollectionId_t collection;
    pd_VecItemId_t items;
} pd_uniques_redeposit_V13_t;

#define PD_CALL_UNIQUES_FREEZE_V13 7
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_uniques_freeze_V13_t;

#define PD_CALL_UNIQUES_THAW_V13 8
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_uniques_thaw_V13_t;

#define PD_CALL_UNIQUES_FREEZE_COLLECTION_V13 9
typedef struct {
    pd_CollectionId_t collection;
} pd_uniques_freeze_collection_V13_t;

#define PD_CALL_UNIQUES_THAW_COLLECTION_V13 10
typedef struct {
    pd_CollectionId_t collection;
} pd_uniques_thaw_collection_V13_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V13 11
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
} pd_uniques_transfer_ownership_V13_t;

#define PD_CALL_UNIQUES_SET_TEAM_V13 12
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
} pd_uniques_set_team_V13_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V13 13
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t delegate;
} pd_uniques_approve_transfer_V13_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V13 14
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionAccountIdLookupOfT_t maybe_check_delegate;
} pd_uniques_cancel_approval_V13_t;

#define PD_CALL_UNIQUES_FORCE_ITEM_STATUS_V13 15
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_item_status_V13_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V13 16
typedef struct {
    pd_CollectionId_t collection;
    pd_OptionItemId_t maybe_item;
    pd_BoundedVecu8_t key;
    pd_BoundedVecu8_t value;
} pd_uniques_set_attribute_V13_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V13 17
typedef struct {
    pd_CollectionId_t collection;
    pd_OptionItemId_t maybe_item;
    pd_BoundedVecu8_t key;
} pd_uniques_clear_attribute_V13_t;

#define PD_CALL_UNIQUES_SET_METADATA_V13 18
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_BoundedVecu8_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V13_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V13 19
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_uniques_clear_metadata_V13_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_METADATA_V13 20
typedef struct {
    pd_CollectionId_t collection;
    pd_BoundedVecu8_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_collection_metadata_V13_t;

#define PD_CALL_UNIQUES_CLEAR_COLLECTION_METADATA_V13 21
typedef struct {
    pd_CollectionId_t collection;
} pd_uniques_clear_collection_metadata_V13_t;

#define PD_CALL_UNIQUES_SET_ACCEPT_OWNERSHIP_V13 22
typedef struct {
    pd_OptionCollectionId_t maybe_collection;
} pd_uniques_set_accept_ownership_V13_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_MAX_SUPPLY_V13 23
typedef struct {
    pd_CollectionId_t collection;
    pd_u32_t max_supply;
} pd_uniques_set_collection_max_supply_V13_t;

#define PD_CALL_UNIQUES_SET_PRICE_V13 24
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionItemPrice_t price;
    pd_OptionAccountIdLookupOfT_t whitelisted_buyer;
} pd_uniques_set_price_V13_t;

#define PD_CALL_UNIQUES_BUY_ITEM_V13 25
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_ItemPrice_t bid_price;
} pd_uniques_buy_item_V13_t;

#define PD_CALL_NFTS_CREATE_V13 0
typedef struct {
    pd_AccountIdLookupOfT_t admin;
    pd_CollectionConfigFor_t config;
} pd_nfts_create_V13_t;

#define PD_CALL_NFTS_FORCE_CREATE_V13 1
typedef struct {
    pd_AccountIdLookupOfT_t owner;
    pd_CollectionConfigFor_t config;
} pd_nfts_force_create_V13_t;

#define PD_CALL_NFTS_DESTROY_V13 2
typedef struct {
    pd_CollectionId_t collection;
    pd_DestroyWitness_t witness;
} pd_nfts_destroy_V13_t;

#define PD_CALL_NFTS_MINT_V13 3
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t mint_to;
    pd_OptionMintWitnessItemId_t witness_data;
} pd_nfts_mint_V13_t;

#define PD_CALL_NFTS_FORCE_MINT_V13 4
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t mint_to;
    pd_ItemConfig_t item_config;
} pd_nfts_force_mint_V13_t;

#define PD_CALL_NFTS_BURN_V13 5
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_nfts_burn_V13_t;

#define PD_CALL_NFTS_TRANSFER_V13 6
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t dest;
} pd_nfts_transfer_V13_t;

#define PD_CALL_NFTS_REDEPOSIT_V13 7
typedef struct {
    pd_CollectionId_t collection;
    pd_VecItemId_t items;
} pd_nfts_redeposit_V13_t;

#define PD_CALL_NFTS_LOCK_ITEM_TRANSFER_V13 8
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_nfts_lock_item_transfer_V13_t;

#define PD_CALL_NFTS_UNLOCK_ITEM_TRANSFER_V13 9
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_nfts_unlock_item_transfer_V13_t;

#define PD_CALL_NFTS_LOCK_COLLECTION_V13 10
typedef struct {
    pd_CollectionId_t collection;
    pd_CollectionSettings_t lock_settings;
} pd_nfts_lock_collection_V13_t;

#define PD_CALL_NFTS_TRANSFER_OWNERSHIP_V13 11
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
} pd_nfts_transfer_ownership_V13_t;

#define PD_CALL_NFTS_SET_TEAM_V13 12
typedef struct {
    pd_CollectionId_t collection;
    pd_OptionAccountIdLookupOfT_t issuer;
    pd_OptionAccountIdLookupOfT_t admin;
    pd_OptionAccountIdLookupOfT_t freezer;
} pd_nfts_set_team_V13_t;

#define PD_CALL_NFTS_FORCE_COLLECTION_OWNER_V13 13
typedef struct {
    pd_CollectionId_t collection;
    pd_AccountIdLookupOfT_t owner;
} pd_nfts_force_collection_owner_V13_t;

#define PD_CALL_NFTS_FORCE_COLLECTION_CONFIG_V13 14
typedef struct {
    pd_CollectionId_t collection;
    pd_CollectionConfigFor_t config;
} pd_nfts_force_collection_config_V13_t;

#define PD_CALL_NFTS_APPROVE_TRANSFER_V13 15
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t delegate;
    pd_Optionu32_t maybe_deadline;
} pd_nfts_approve_transfer_V13_t;

#define PD_CALL_NFTS_CANCEL_APPROVAL_V13 16
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t delegate;
} pd_nfts_cancel_approval_V13_t;

#define PD_CALL_NFTS_CLEAR_ALL_TRANSFER_APPROVALS_V13 17
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_nfts_clear_all_transfer_approvals_V13_t;

#define PD_CALL_NFTS_LOCK_ITEM_PROPERTIES_V13 18
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_bool_t lock_metadata;
    pd_bool_t lock_attributes;
} pd_nfts_lock_item_properties_V13_t;

#define PD_CALL_NFTS_SET_ATTRIBUTE_V13 19
typedef struct {
    pd_CollectionId_t collection;
    pd_OptionItemId_t maybe_item;
    pd_AttributeNamespaceAccountId_t namespace_;
    pd_BoundedVecu8_t key;
    pd_BoundedVecu8_t value;
} pd_nfts_set_attribute_V13_t;

#define PD_CALL_NFTS_FORCE_SET_ATTRIBUTE_V13 20
typedef struct {
    pd_OptionAccountId_t set_as;
    pd_CollectionId_t collection;
    pd_OptionItemId_t maybe_item;
    pd_AttributeNamespaceAccountId_t namespace_;
    pd_BoundedVecu8_t key;
    pd_BoundedVecu8_t value;
} pd_nfts_force_set_attribute_V13_t;

#define PD_CALL_NFTS_CLEAR_ATTRIBUTE_V13 21
typedef struct {
    pd_CollectionId_t collection;
    pd_OptionItemId_t maybe_item;
    pd_AttributeNamespaceAccountId_t namespace_;
    pd_BoundedVecu8_t key;
} pd_nfts_clear_attribute_V13_t;

#define PD_CALL_NFTS_APPROVE_ITEM_ATTRIBUTES_V13 22
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t delegate;
} pd_nfts_approve_item_attributes_V13_t;

#define PD_CALL_NFTS_CANCEL_ITEM_ATTRIBUTES_APPROVAL_V13 23
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_AccountIdLookupOfT_t delegate;
    pd_CancelAttributesApprovalWitness_t witness;
} pd_nfts_cancel_item_attributes_approval_V13_t;

#define PD_CALL_NFTS_SET_METADATA_V13 24
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_BoundedVecu8_t data;
} pd_nfts_set_metadata_V13_t;

#define PD_CALL_NFTS_CLEAR_METADATA_V13 25
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
} pd_nfts_clear_metadata_V13_t;

#define PD_CALL_NFTS_SET_COLLECTION_METADATA_V13 26
typedef struct {
    pd_CollectionId_t collection;
    pd_BoundedVecu8_t data;
} pd_nfts_set_collection_metadata_V13_t;

#define PD_CALL_NFTS_CLEAR_COLLECTION_METADATA_V13 27
typedef struct {
    pd_CollectionId_t collection;
} pd_nfts_clear_collection_metadata_V13_t;

#define PD_CALL_NFTS_SET_ACCEPT_OWNERSHIP_V13 28
typedef struct {
    pd_OptionCollectionId_t maybe_collection;
} pd_nfts_set_accept_ownership_V13_t;

#define PD_CALL_NFTS_SET_COLLECTION_MAX_SUPPLY_V13 29
typedef struct {
    pd_CollectionId_t collection;
    pd_u32_t max_supply;
} pd_nfts_set_collection_max_supply_V13_t;

#define PD_CALL_NFTS_UPDATE_MINT_SETTINGS_V13 30
typedef struct {
    pd_CollectionId_t collection;
    pd_MintSettings_t mint_settings;
} pd_nfts_update_mint_settings_V13_t;

#define PD_CALL_NFTS_SET_PRICE_V13 31
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_OptionItemPrice_t price;
    pd_OptionAccountIdLookupOfT_t whitelisted_buyer;
} pd_nfts_set_price_V13_t;

#define PD_CALL_NFTS_BUY_ITEM_V13 32
typedef struct {
    pd_CollectionId_t collection;
    pd_ItemId_t item;
    pd_ItemPrice_t bid_price;
} pd_nfts_buy_item_V13_t;

#define PD_CALL_NFTS_PAY_TIPS_V13 33
typedef struct {
    pd_VecItemTipOfMaxTips_t tips;
} pd_nfts_pay_tips_V13_t;

#define PD_CALL_NFTS_CREATE_SWAP_V13 34
typedef struct {
    pd_CollectionId_t offered_collection;
    pd_ItemId_t offered_item;
    pd_CollectionId_t desired_collection;
    pd_OptionItemId_t maybe_desired_item;
    pd_OptionPriceWithDirectionItemPrice_t maybe_price;
    pd_BlockNumber_t duration;
} pd_nfts_create_swap_V13_t;

#define PD_CALL_NFTS_CANCEL_SWAP_V13 35
typedef struct {
    pd_CollectionId_t offered_collection;
    pd_ItemId_t offered_item;
} pd_nfts_cancel_swap_V13_t;

#define PD_CALL_NFTS_CLAIM_SWAP_V13 36
typedef struct {
    pd_CollectionId_t send_collection;
    pd_ItemId_t send_item;
    pd_CollectionId_t receive_collection;
    pd_ItemId_t receive_item;
    pd_OptionPriceWithDirectionItemPrice_t witness_price;
} pd_nfts_claim_swap_V13_t;

#endif

typedef union {
    pd_balances_transfer_all_V13_t balances_transfer_all_V13;
    pd_session_set_keys_V13_t session_set_keys_V13;
    pd_session_purge_keys_V13_t session_purge_keys_V13;
    pd_utility_batch_V13_t utility_batch_V13;
    pd_utility_batch_all_V13_t utility_batch_all_V13;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    pd_polkadotxcm_teleport_assets_V13_t polkadotxcm_teleport_assets_V13;
    pd_polkadotxcm_reserve_transfer_assets_V13_t polkadotxcm_reserve_transfer_assets_V13;
    pd_polkadotxcm_limited_reserve_transfer_assets_V13_t polkadotxcm_limited_reserve_transfer_assets_V13;
    pd_polkadotxcm_limited_teleport_assets_V13_t polkadotxcm_limited_teleport_assets_V13;
    pd_foreignassets_create_V13_t foreignassets_create_V13;
    pd_foreignassets_force_create_V13_t foreignassets_force_create_V13;
    pd_foreignassets_start_destroy_V13_t foreignassets_start_destroy_V13;
    pd_foreignassets_destroy_accounts_V13_t foreignassets_destroy_accounts_V13;
    pd_foreignassets_destroy_approvals_V13_t foreignassets_destroy_approvals_V13;
    pd_foreignassets_finish_destroy_V13_t foreignassets_finish_destroy_V13;
    pd_foreignassets_mint_V13_t foreignassets_mint_V13;
    pd_foreignassets_burn_V13_t foreignassets_burn_V13;
    pd_foreignassets_transfer_V13_t foreignassets_transfer_V13;
    pd_foreignassets_transfer_keep_alive_V13_t foreignassets_transfer_keep_alive_V13;
    pd_foreignassets_force_transfer_V13_t foreignassets_force_transfer_V13;
    pd_foreignassets_freeze_V13_t foreignassets_freeze_V13;
    pd_foreignassets_thaw_V13_t foreignassets_thaw_V13;
    pd_foreignassets_freeze_asset_V13_t foreignassets_freeze_asset_V13;
    pd_foreignassets_thaw_asset_V13_t foreignassets_thaw_asset_V13;
    pd_foreignassets_transfer_ownership_V13_t foreignassets_transfer_ownership_V13;
    pd_foreignassets_set_team_V13_t foreignassets_set_team_V13;
    pd_foreignassets_set_metadata_V13_t foreignassets_set_metadata_V13;
    pd_foreignassets_clear_metadata_V13_t foreignassets_clear_metadata_V13;
    pd_foreignassets_force_set_metadata_V13_t foreignassets_force_set_metadata_V13;
    pd_foreignassets_force_clear_metadata_V13_t foreignassets_force_clear_metadata_V13;
    pd_foreignassets_force_asset_status_V13_t foreignassets_force_asset_status_V13;
    pd_foreignassets_approve_transfer_V13_t foreignassets_approve_transfer_V13;
    pd_foreignassets_cancel_approval_V13_t foreignassets_cancel_approval_V13;
    pd_foreignassets_force_cancel_approval_V13_t foreignassets_force_cancel_approval_V13;
    pd_foreignassets_transfer_approved_V13_t foreignassets_transfer_approved_V13;
    pd_foreignassets_touch_V13_t foreignassets_touch_V13;
    pd_foreignassets_refund_V13_t foreignassets_refund_V13;
    pd_foreignassets_set_min_balance_V13_t foreignassets_set_min_balance_V13;
    pd_foreignassets_touch_other_V13_t foreignassets_touch_other_V13;
    pd_foreignassets_refund_other_V13_t foreignassets_refund_other_V13;
    pd_foreignassets_block_V13_t foreignassets_block_V13;
#endif
    pd_timestamp_set_V13_t timestamp_set_V13;
    pd_balances_force_unreserve_V13_t balances_force_unreserve_V13;
    pd_balances_upgrade_accounts_V13_t balances_upgrade_accounts_V13;
    pd_balances_force_set_balance_V13_t balances_force_set_balance_V13;
    pd_collatorselection_set_invulnerables_V13_t collatorselection_set_invulnerables_V13;
    pd_collatorselection_set_desired_candidates_V13_t collatorselection_set_desired_candidates_V13;
    pd_collatorselection_set_candidacy_bond_V13_t collatorselection_set_candidacy_bond_V13;
    pd_collatorselection_register_as_candidate_V13_t collatorselection_register_as_candidate_V13;
    pd_collatorselection_leave_intent_V13_t collatorselection_leave_intent_V13;
    pd_xcmpqueue_service_overweight_V13_t xcmpqueue_service_overweight_V13;
    pd_xcmpqueue_suspend_xcm_execution_V13_t xcmpqueue_suspend_xcm_execution_V13;
    pd_xcmpqueue_resume_xcm_execution_V13_t xcmpqueue_resume_xcm_execution_V13;
    pd_xcmpqueue_update_suspend_threshold_V13_t xcmpqueue_update_suspend_threshold_V13;
    pd_xcmpqueue_update_drop_threshold_V13_t xcmpqueue_update_drop_threshold_V13;
    pd_xcmpqueue_update_resume_threshold_V13_t xcmpqueue_update_resume_threshold_V13;
    pd_xcmpqueue_update_threshold_weight_V13_t xcmpqueue_update_threshold_weight_V13;
    pd_xcmpqueue_update_weight_restrict_decay_V13_t xcmpqueue_update_weight_restrict_decay_V13;
    pd_xcmpqueue_update_xcmp_max_individual_weight_V13_t xcmpqueue_update_xcmp_max_individual_weight_V13;
    pd_dmpqueue_service_overweight_V13_t dmpqueue_service_overweight_V13;
    pd_utility_force_batch_V13_t utility_force_batch_V13;
    pd_utility_with_weight_V13_t utility_with_weight_V13;
    pd_proxy_remove_proxies_V13_t proxy_remove_proxies_V13;
    pd_proxy_announce_V13_t proxy_announce_V13;
    pd_proxy_remove_announcement_V13_t proxy_remove_announcement_V13;
    pd_proxy_reject_announcement_V13_t proxy_reject_announcement_V13;
    pd_proxy_proxy_announced_V13_t proxy_proxy_announced_V13;
    pd_assets_start_destroy_V13_t assets_start_destroy_V13;
    pd_assets_destroy_accounts_V13_t assets_destroy_accounts_V13;
    pd_assets_destroy_approvals_V13_t assets_destroy_approvals_V13;
    pd_assets_finish_destroy_V13_t assets_finish_destroy_V13;
    pd_assets_touch_V13_t assets_touch_V13;
    pd_assets_refund_V13_t assets_refund_V13;
    pd_assets_set_min_balance_V13_t assets_set_min_balance_V13;
    pd_assets_touch_other_V13_t assets_touch_other_V13;
    pd_assets_refund_other_V13_t assets_refund_other_V13;
    pd_assets_block_V13_t assets_block_V13;
    pd_uniques_create_V13_t uniques_create_V13;
    pd_uniques_force_create_V13_t uniques_force_create_V13;
    pd_uniques_destroy_V13_t uniques_destroy_V13;
    pd_uniques_mint_V13_t uniques_mint_V13;
    pd_uniques_burn_V13_t uniques_burn_V13;
    pd_uniques_transfer_V13_t uniques_transfer_V13;
    pd_uniques_redeposit_V13_t uniques_redeposit_V13;
    pd_uniques_freeze_V13_t uniques_freeze_V13;
    pd_uniques_thaw_V13_t uniques_thaw_V13;
    pd_uniques_freeze_collection_V13_t uniques_freeze_collection_V13;
    pd_uniques_thaw_collection_V13_t uniques_thaw_collection_V13;
    pd_uniques_transfer_ownership_V13_t uniques_transfer_ownership_V13;
    pd_uniques_set_team_V13_t uniques_set_team_V13;
    pd_uniques_approve_transfer_V13_t uniques_approve_transfer_V13;
    pd_uniques_cancel_approval_V13_t uniques_cancel_approval_V13;
    pd_uniques_force_item_status_V13_t uniques_force_item_status_V13;
    pd_uniques_set_attribute_V13_t uniques_set_attribute_V13;
    pd_uniques_clear_attribute_V13_t uniques_clear_attribute_V13;
    pd_uniques_set_metadata_V13_t uniques_set_metadata_V13;
    pd_uniques_clear_metadata_V13_t uniques_clear_metadata_V13;
    pd_uniques_set_collection_metadata_V13_t uniques_set_collection_metadata_V13;
    pd_uniques_clear_collection_metadata_V13_t uniques_clear_collection_metadata_V13;
    pd_uniques_set_accept_ownership_V13_t uniques_set_accept_ownership_V13;
    pd_uniques_set_collection_max_supply_V13_t uniques_set_collection_max_supply_V13;
    pd_uniques_set_price_V13_t uniques_set_price_V13;
    pd_uniques_buy_item_V13_t uniques_buy_item_V13;
    pd_nfts_create_V13_t nfts_create_V13;
    pd_nfts_force_create_V13_t nfts_force_create_V13;
    pd_nfts_destroy_V13_t nfts_destroy_V13;
    pd_nfts_mint_V13_t nfts_mint_V13;
    pd_nfts_force_mint_V13_t nfts_force_mint_V13;
    pd_nfts_burn_V13_t nfts_burn_V13;
    pd_nfts_transfer_V13_t nfts_transfer_V13;
    pd_nfts_redeposit_V13_t nfts_redeposit_V13;
    pd_nfts_lock_item_transfer_V13_t nfts_lock_item_transfer_V13;
    pd_nfts_unlock_item_transfer_V13_t nfts_unlock_item_transfer_V13;
    pd_nfts_lock_collection_V13_t nfts_lock_collection_V13;
    pd_nfts_transfer_ownership_V13_t nfts_transfer_ownership_V13;
    pd_nfts_set_team_V13_t nfts_set_team_V13;
    pd_nfts_force_collection_owner_V13_t nfts_force_collection_owner_V13;
    pd_nfts_force_collection_config_V13_t nfts_force_collection_config_V13;
    pd_nfts_approve_transfer_V13_t nfts_approve_transfer_V13;
    pd_nfts_cancel_approval_V13_t nfts_cancel_approval_V13;
    pd_nfts_clear_all_transfer_approvals_V13_t nfts_clear_all_transfer_approvals_V13;
    pd_nfts_lock_item_properties_V13_t nfts_lock_item_properties_V13;
    pd_nfts_set_attribute_V13_t nfts_set_attribute_V13;
    pd_nfts_force_set_attribute_V13_t nfts_force_set_attribute_V13;
    pd_nfts_clear_attribute_V13_t nfts_clear_attribute_V13;
    pd_nfts_approve_item_attributes_V13_t nfts_approve_item_attributes_V13;
    pd_nfts_cancel_item_attributes_approval_V13_t nfts_cancel_item_attributes_approval_V13;
    pd_nfts_set_metadata_V13_t nfts_set_metadata_V13;
    pd_nfts_clear_metadata_V13_t nfts_clear_metadata_V13;
    pd_nfts_set_collection_metadata_V13_t nfts_set_collection_metadata_V13;
    pd_nfts_clear_collection_metadata_V13_t nfts_clear_collection_metadata_V13;
    pd_nfts_set_accept_ownership_V13_t nfts_set_accept_ownership_V13;
    pd_nfts_set_collection_max_supply_V13_t nfts_set_collection_max_supply_V13;
    pd_nfts_update_mint_settings_V13_t nfts_update_mint_settings_V13;
    pd_nfts_set_price_V13_t nfts_set_price_V13;
    pd_nfts_buy_item_V13_t nfts_buy_item_V13;
    pd_nfts_pay_tips_V13_t nfts_pay_tips_V13;
    pd_nfts_create_swap_V13_t nfts_create_swap_V13;
    pd_nfts_cancel_swap_V13_t nfts_cancel_swap_V13;
    pd_nfts_claim_swap_V13_t nfts_claim_swap_V13;
#endif
} pd_MethodBasic_V13_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V13 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V13_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V13 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V13_t;

#define PD_CALL_BALANCES_TRANSFER_V13 7
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V13_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V13 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V13_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V13 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V13_t;

#define PD_CALL_SYSTEM_SET_CODE_V13 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V13_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V13 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V13_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V13 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V13_t;

#define PD_CALL_BALANCES_TRANSFER_ALLOW_DEATH_V13 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_allow_death_V13_t;

#define PD_CALL_BALANCES_SET_BALANCE_DEPRECATED_V13 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t old_reserved;
} pd_balances_set_balance_deprecated_V13_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V13 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V13_t;

#define PD_CALL_MULTISIG_AS_MULTI_V13 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V13_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V13 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V13_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V13 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V13_t;

#define PD_CALL_PROXY_PROXY_V13 0
typedef struct {
    pd_AccountIdLookupOfT_t real;
    pd_OptionProxyType_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V13_t;

#define PD_CALL_PROXY_ADD_PROXY_V13 1
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V13_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V13 2
typedef struct {
    pd_AccountIdLookupOfT_t delegate;
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V13_t;

#define PD_CALL_PROXY_CREATE_PURE_V13 4
typedef struct {
    pd_ProxyType_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_create_pure_V13_t;

#define PD_CALL_PROXY_KILL_PURE_V13 5
typedef struct {
    pd_AccountIdLookupOfT_t spawner;
    pd_ProxyType_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_pure_V13_t;

#define PD_CALL_ASSETS_CREATE_V13 0
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t admin;
    pd_Balance_t min_balance;
} pd_assets_create_V13_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V13 1
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t owner;
    pd_bool_t is_sufficient;
    pd_CompactBalance_t min_balance;
} pd_assets_force_create_V13_t;

#define PD_CALL_ASSETS_MINT_V13 6
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t beneficiary;
    pd_CompactBalance_t amount;
} pd_assets_mint_V13_t;

#define PD_CALL_ASSETS_BURN_V13 7
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t amount;
} pd_assets_burn_V13_t;

#define PD_CALL_ASSETS_TRANSFER_V13 8
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_V13_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V13 9
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_keep_alive_V13_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V13 10
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_assets_force_transfer_V13_t;

#define PD_CALL_ASSETS_FREEZE_V13 11
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t who;
} pd_assets_freeze_V13_t;

#define PD_CALL_ASSETS_THAW_V13 12
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t who;
} pd_assets_thaw_V13_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V13 13
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V13_t;

#define PD_CALL_ASSETS_THAW_ASSET_V13 14
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V13_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V13 15
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t owner;
} pd_assets_transfer_ownership_V13_t;

#define PD_CALL_ASSETS_SET_TEAM_V13 16
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
} pd_assets_set_team_V13_t;

#define PD_CALL_ASSETS_SET_METADATA_V13 17
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V13_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V13 18
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V13_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V13 19
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V13_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V13 20
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V13_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V13 21
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t owner;
    pd_AccountIdLookupOfT_t issuer;
    pd_AccountIdLookupOfT_t admin;
    pd_AccountIdLookupOfT_t freezer;
    pd_CompactBalance_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V13_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V13 22
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t delegate;
    pd_CompactBalance_t amount;
} pd_assets_approve_transfer_V13_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V13 23
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t delegate;
} pd_assets_cancel_approval_V13_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V13 24
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t owner;
    pd_AccountIdLookupOfT_t delegate;
} pd_assets_force_cancel_approval_V13_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V13 25
typedef struct {
    pd_Compactu32_t id;
    pd_AccountIdLookupOfT_t owner;
    pd_AccountIdLookupOfT_t destination;
    pd_CompactBalance_t amount;
} pd_assets_transfer_approved_V13_t;

#endif

typedef union {
    pd_balances_force_transfer_V13_t balances_force_transfer_V13;
    pd_balances_transfer_keep_alive_V13_t balances_transfer_keep_alive_V13;
    pd_balances_transfer_V13_t balances_transfer_V13;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V13_t system_remark_V13;
    pd_system_set_heap_pages_V13_t system_set_heap_pages_V13;
    pd_system_set_code_V13_t system_set_code_V13;
    pd_system_set_code_without_checks_V13_t system_set_code_without_checks_V13;
    pd_system_remark_with_event_V13_t system_remark_with_event_V13;
    pd_balances_transfer_allow_death_V13_t balances_transfer_allow_death_V13;
    pd_balances_set_balance_deprecated_V13_t balances_set_balance_deprecated_V13;
    pd_multisig_as_multi_threshold_1_V13_t multisig_as_multi_threshold_1_V13;
    pd_multisig_as_multi_V13_t multisig_as_multi_V13;
    pd_multisig_approve_as_multi_V13_t multisig_approve_as_multi_V13;
    pd_multisig_cancel_as_multi_V13_t multisig_cancel_as_multi_V13;
    pd_proxy_proxy_V13_t proxy_proxy_V13;
    pd_proxy_add_proxy_V13_t proxy_add_proxy_V13;
    pd_proxy_remove_proxy_V13_t proxy_remove_proxy_V13;
    pd_proxy_create_pure_V13_t proxy_create_pure_V13;
    pd_proxy_kill_pure_V13_t proxy_kill_pure_V13;
    pd_assets_create_V13_t assets_create_V13;
    pd_assets_force_create_V13_t assets_force_create_V13;
    pd_assets_mint_V13_t assets_mint_V13;
    pd_assets_burn_V13_t assets_burn_V13;
    pd_assets_transfer_V13_t assets_transfer_V13;
    pd_assets_transfer_keep_alive_V13_t assets_transfer_keep_alive_V13;
    pd_assets_force_transfer_V13_t assets_force_transfer_V13;
    pd_assets_freeze_V13_t assets_freeze_V13;
    pd_assets_thaw_V13_t assets_thaw_V13;
    pd_assets_freeze_asset_V13_t assets_freeze_asset_V13;
    pd_assets_thaw_asset_V13_t assets_thaw_asset_V13;
    pd_assets_transfer_ownership_V13_t assets_transfer_ownership_V13;
    pd_assets_set_team_V13_t assets_set_team_V13;
    pd_assets_set_metadata_V13_t assets_set_metadata_V13;
    pd_assets_clear_metadata_V13_t assets_clear_metadata_V13;
    pd_assets_force_set_metadata_V13_t assets_force_set_metadata_V13;
    pd_assets_force_clear_metadata_V13_t assets_force_clear_metadata_V13;
    pd_assets_force_asset_status_V13_t assets_force_asset_status_V13;
    pd_assets_approve_transfer_V13_t assets_approve_transfer_V13;
    pd_assets_cancel_approval_V13_t assets_cancel_approval_V13;
    pd_assets_force_cancel_approval_V13_t assets_force_cancel_approval_V13;
    pd_assets_transfer_approved_V13_t assets_transfer_approved_V13;
#endif
} pd_MethodNested_V13_t;

typedef union {
    pd_MethodBasic_V13_t basic;
    pd_MethodNested_V13_t nested;
} pd_Method_V13_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
