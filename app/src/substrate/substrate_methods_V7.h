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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V7.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V7 0
#define PD_CALL_TIMESTAMP_V7 3
#define PD_CALL_BALANCES_V7 10
#define PD_CALL_COLLATORSELECTION_V7 21
#define PD_CALL_SESSION_V7 22
#define PD_CALL_XCMPQUEUE_V7 30
#define PD_CALL_UTILITY_V7 40
#define PD_CALL_MULTISIG_V7 41
#define PD_CALL_PROXY_V7 42
#define PD_CALL_ASSETS_V7 50
#define PD_CALL_UNIQUES_V7 51

#define PD_CALL_BALANCES_TRANSFER_ALL_V7 4
typedef struct {
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V7_t;

#define PD_CALL_SESSION_SET_KEYS_V7 0
typedef struct {
    pd_Keys_V7_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V7_t;

#define PD_CALL_SESSION_PURGE_KEYS_V7 1
typedef struct {
} pd_session_purge_keys_V7_t;

#define PD_CALL_UTILITY_BATCH_V7 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V7_t;

#define PD_CALL_UTILITY_BATCH_ALL_V7 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V7_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V7 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V7_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V7 5
typedef struct {
    pd_LookupasStaticLookupSource_V7_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V7_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V7 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V7_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V7 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V7_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V7 3
typedef struct {
} pd_collatorselection_register_as_candidate_V7_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V7 4
typedef struct {
} pd_collatorselection_leave_intent_V7_t;

#define PD_CALL_XCMPQUEUE_SUSPEND_XCM_EXECUTION_V7 1
typedef struct {
} pd_xcmpqueue_suspend_xcm_execution_V7_t;

#define PD_CALL_XCMPQUEUE_RESUME_XCM_EXECUTION_V7 2
typedef struct {
} pd_xcmpqueue_resume_xcm_execution_V7_t;

#define PD_CALL_XCMPQUEUE_UPDATE_SUSPEND_THRESHOLD_V7 3
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_suspend_threshold_V7_t;

#define PD_CALL_XCMPQUEUE_UPDATE_DROP_THRESHOLD_V7 4
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_drop_threshold_V7_t;

#define PD_CALL_XCMPQUEUE_UPDATE_RESUME_THRESHOLD_V7 5
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_resume_threshold_V7_t;

#define PD_CALL_XCMPQUEUE_UPDATE_THRESHOLD_WEIGHT_V7 6
typedef struct {
    pd_Weight_V7_t new_;
} pd_xcmpqueue_update_threshold_weight_V7_t;

#define PD_CALL_XCMPQUEUE_UPDATE_WEIGHT_RESTRICT_DECAY_V7 7
typedef struct {
    pd_Weight_V7_t new_;
} pd_xcmpqueue_update_weight_restrict_decay_V7_t;

#define PD_CALL_XCMPQUEUE_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT_V7 8
typedef struct {
    pd_Weight_V7_t new_;
} pd_xcmpqueue_update_xcmp_max_individual_weight_V7_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V7 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V7_t;

#define PD_CALL_PROXY_ADD_PROXY_V7 1
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_ProxyType_V7_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V7_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V7 2
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_ProxyType_V7_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V7_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V7 3
typedef struct {
} pd_proxy_remove_proxies_V7_t;

#define PD_CALL_PROXY_ANONYMOUS_V7 4
typedef struct {
    pd_ProxyType_V7_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V7_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V7 5
typedef struct {
    pd_AccountId_V7_t spawner;
    pd_ProxyType_V7_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V7_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V7 9
typedef struct {
    pd_AccountId_V7_t delegate;
    pd_AccountId_V7_t real;
    pd_OptionProxyType_V7_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V7_t;

#define PD_CALL_ASSETS_TOUCH_V7 23
typedef struct {
    pd_Compactu32_t id;
} pd_assets_touch_V7_t;

#define PD_CALL_ASSETS_REFUND_V7 24
typedef struct {
    pd_Compactu32_t id;
    pd_bool_t allow_burn;
} pd_assets_refund_V7_t;

#define PD_CALL_UNIQUES_CREATE_V7 0
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_LookupasStaticLookupSource_V7_t admin;
} pd_uniques_create_V7_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V7 1
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_LookupasStaticLookupSource_V7_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V7_t;

#define PD_CALL_UNIQUES_DESTROY_V7 2
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_DestroyWitness_V7_t witness;
} pd_uniques_destroy_V7_t;

#define PD_CALL_UNIQUES_MINT_V7 3
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_ItemId_V7_t item;
    pd_LookupasStaticLookupSource_V7_t owner;
} pd_uniques_mint_V7_t;

#define PD_CALL_UNIQUES_BURN_V7 4
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_ItemId_V7_t item;
    pd_OptionLookupasStaticLookupSource_V7_t check_owner;
} pd_uniques_burn_V7_t;

#define PD_CALL_UNIQUES_TRANSFER_V7 5
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_ItemId_V7_t item;
    pd_LookupasStaticLookupSource_V7_t dest;
} pd_uniques_transfer_V7_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V7 6
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_VecItemId_V7_t items;
} pd_uniques_redeposit_V7_t;

#define PD_CALL_UNIQUES_FREEZE_V7 7
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_ItemId_V7_t item;
} pd_uniques_freeze_V7_t;

#define PD_CALL_UNIQUES_THAW_V7 8
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_ItemId_V7_t item;
} pd_uniques_thaw_V7_t;

#define PD_CALL_UNIQUES_FREEZE_COLLECTION_V7 9
typedef struct {
    pd_CollectionId_V7_t collection;
} pd_uniques_freeze_collection_V7_t;

#define PD_CALL_UNIQUES_THAW_COLLECTION_V7 10
typedef struct {
    pd_CollectionId_V7_t collection;
} pd_uniques_thaw_collection_V7_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V7 11
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_LookupasStaticLookupSource_V7_t owner;
} pd_uniques_transfer_ownership_V7_t;

#define PD_CALL_UNIQUES_SET_TEAM_V7 12
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_LookupasStaticLookupSource_V7_t issuer;
    pd_LookupasStaticLookupSource_V7_t admin;
    pd_LookupasStaticLookupSource_V7_t freezer;
} pd_uniques_set_team_V7_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V7 13
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_ItemId_V7_t item;
    pd_LookupasStaticLookupSource_V7_t delegate;
} pd_uniques_approve_transfer_V7_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V7 14
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_ItemId_V7_t item;
    pd_OptionLookupasStaticLookupSource_V7_t maybe_check_delegate;
} pd_uniques_cancel_approval_V7_t;

#define PD_CALL_UNIQUES_FORCE_ITEM_STATUS_V7 15
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_LookupasStaticLookupSource_V7_t owner;
    pd_LookupasStaticLookupSource_V7_t issuer;
    pd_LookupasStaticLookupSource_V7_t admin;
    pd_LookupasStaticLookupSource_V7_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_item_status_V7_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V7 16
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_OptionItemId_V7_t maybe_item;
    pd_BoundedVecu8_V7_t key;
    pd_BoundedVecu8_V7_t value;
} pd_uniques_set_attribute_V7_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V7 17
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_OptionItemId_V7_t maybe_item;
    pd_BoundedVecu8_V7_t key;
} pd_uniques_clear_attribute_V7_t;

#define PD_CALL_UNIQUES_SET_METADATA_V7 18
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_ItemId_V7_t item;
    pd_BoundedVecu8_V7_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V7_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V7 19
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_ItemId_V7_t item;
} pd_uniques_clear_metadata_V7_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_METADATA_V7 20
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_BoundedVecu8_V7_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_collection_metadata_V7_t;

#define PD_CALL_UNIQUES_CLEAR_COLLECTION_METADATA_V7 21
typedef struct {
    pd_CollectionId_V7_t collection;
} pd_uniques_clear_collection_metadata_V7_t;

#define PD_CALL_UNIQUES_SET_ACCEPT_OWNERSHIP_V7 22
typedef struct {
    pd_OptionCollectionId_V7_t maybe_collection;
} pd_uniques_set_accept_ownership_V7_t;

#define PD_CALL_UNIQUES_SET_COLLECTION_MAX_SUPPLY_V7 23
typedef struct {
    pd_CollectionId_V7_t collection;
    pd_u32_t max_supply;
} pd_uniques_set_collection_max_supply_V7_t;

#endif

typedef union {
    pd_balances_transfer_all_V7_t balances_transfer_all_V7;
    pd_session_set_keys_V7_t session_set_keys_V7;
    pd_session_purge_keys_V7_t session_purge_keys_V7;
    pd_utility_batch_V7_t utility_batch_V7;
    pd_utility_batch_all_V7_t utility_batch_all_V7;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V7_t timestamp_set_V7;
    pd_balances_force_unreserve_V7_t balances_force_unreserve_V7;
    pd_collatorselection_set_desired_candidates_V7_t collatorselection_set_desired_candidates_V7;
    pd_collatorselection_set_candidacy_bond_V7_t collatorselection_set_candidacy_bond_V7;
    pd_collatorselection_register_as_candidate_V7_t collatorselection_register_as_candidate_V7;
    pd_collatorselection_leave_intent_V7_t collatorselection_leave_intent_V7;
    pd_xcmpqueue_suspend_xcm_execution_V7_t xcmpqueue_suspend_xcm_execution_V7;
    pd_xcmpqueue_resume_xcm_execution_V7_t xcmpqueue_resume_xcm_execution_V7;
    pd_xcmpqueue_update_suspend_threshold_V7_t xcmpqueue_update_suspend_threshold_V7;
    pd_xcmpqueue_update_drop_threshold_V7_t xcmpqueue_update_drop_threshold_V7;
    pd_xcmpqueue_update_resume_threshold_V7_t xcmpqueue_update_resume_threshold_V7;
    pd_xcmpqueue_update_threshold_weight_V7_t xcmpqueue_update_threshold_weight_V7;
    pd_xcmpqueue_update_weight_restrict_decay_V7_t xcmpqueue_update_weight_restrict_decay_V7;
    pd_xcmpqueue_update_xcmp_max_individual_weight_V7_t xcmpqueue_update_xcmp_max_individual_weight_V7;
    pd_utility_force_batch_V7_t utility_force_batch_V7;
    pd_proxy_add_proxy_V7_t proxy_add_proxy_V7;
    pd_proxy_remove_proxy_V7_t proxy_remove_proxy_V7;
    pd_proxy_remove_proxies_V7_t proxy_remove_proxies_V7;
    pd_proxy_anonymous_V7_t proxy_anonymous_V7;
    pd_proxy_kill_anonymous_V7_t proxy_kill_anonymous_V7;
    pd_proxy_proxy_announced_V7_t proxy_proxy_announced_V7;
    pd_assets_touch_V7_t assets_touch_V7;
    pd_assets_refund_V7_t assets_refund_V7;
    pd_uniques_create_V7_t uniques_create_V7;
    pd_uniques_force_create_V7_t uniques_force_create_V7;
    pd_uniques_destroy_V7_t uniques_destroy_V7;
    pd_uniques_mint_V7_t uniques_mint_V7;
    pd_uniques_burn_V7_t uniques_burn_V7;
    pd_uniques_transfer_V7_t uniques_transfer_V7;
    pd_uniques_redeposit_V7_t uniques_redeposit_V7;
    pd_uniques_freeze_V7_t uniques_freeze_V7;
    pd_uniques_thaw_V7_t uniques_thaw_V7;
    pd_uniques_freeze_collection_V7_t uniques_freeze_collection_V7;
    pd_uniques_thaw_collection_V7_t uniques_thaw_collection_V7;
    pd_uniques_transfer_ownership_V7_t uniques_transfer_ownership_V7;
    pd_uniques_set_team_V7_t uniques_set_team_V7;
    pd_uniques_approve_transfer_V7_t uniques_approve_transfer_V7;
    pd_uniques_cancel_approval_V7_t uniques_cancel_approval_V7;
    pd_uniques_force_item_status_V7_t uniques_force_item_status_V7;
    pd_uniques_set_attribute_V7_t uniques_set_attribute_V7;
    pd_uniques_clear_attribute_V7_t uniques_clear_attribute_V7;
    pd_uniques_set_metadata_V7_t uniques_set_metadata_V7;
    pd_uniques_clear_metadata_V7_t uniques_clear_metadata_V7;
    pd_uniques_set_collection_metadata_V7_t uniques_set_collection_metadata_V7;
    pd_uniques_clear_collection_metadata_V7_t uniques_clear_collection_metadata_V7;
    pd_uniques_set_accept_ownership_V7_t uniques_set_accept_ownership_V7;
    pd_uniques_set_collection_max_supply_V7_t uniques_set_collection_max_supply_V7;
#endif
} pd_MethodBasic_V7_t;

#define PD_CALL_BALANCES_TRANSFER_V7 0
typedef struct {
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V7_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V7 2
typedef struct {
    pd_LookupasStaticLookupSource_V7_t source;
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V7_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V7 3
typedef struct {
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V7_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V7 0
typedef struct {
    pd_Perbill_V7_t ratio;
} pd_system_fill_block_V7_t;

#define PD_CALL_SYSTEM_REMARK_V7 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V7_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V7 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_V7 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V7_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V7 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V7_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V7 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V7_t;

#define PD_CALL_BALANCES_SET_BALANCE_V7 1
typedef struct {
    pd_LookupasStaticLookupSource_V7_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V7_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V7 0
typedef struct {
    pd_VecAccountId_V7_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V7_t;

#define PD_CALL_MULTISIG_AS_MULTI_V7 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_OptionTimepoint_V7_t maybe_timepoint;
    pd_OpaqueCall_V7_t call;
    pd_bool_t store_call;
    pd_Weight_V7_t max_weight;
} pd_multisig_as_multi_V7_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V7 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_OptionTimepoint_V7_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V7_t max_weight;
} pd_multisig_approve_as_multi_V7_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V7 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V7_t other_signatories;
    pd_Timepoint_V7_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V7_t;

#define PD_CALL_PROXY_PROXY_V7 0
typedef struct {
    pd_AccountId_V7_t real;
    pd_OptionProxyType_V7_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V7_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V7 1
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t owner;
    pd_bool_t is_sufficient;
    pd_CompactBalance_t min_balance;
} pd_assets_force_create_V7_t;

#define PD_CALL_ASSETS_MINT_V7 3
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t beneficiary;
    pd_CompactBalance_t amount;
} pd_assets_mint_V7_t;

#define PD_CALL_ASSETS_BURN_V7 4
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t who;
    pd_CompactBalance_t amount;
} pd_assets_burn_V7_t;

#define PD_CALL_ASSETS_TRANSFER_V7 5
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_V7_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V7 6
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_keep_alive_V7_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V7 7
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t source;
    pd_LookupasStaticLookupSource_V7_t dest;
    pd_CompactBalance_t amount;
} pd_assets_force_transfer_V7_t;

#define PD_CALL_ASSETS_FREEZE_V7 8
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t who;
} pd_assets_freeze_V7_t;

#define PD_CALL_ASSETS_THAW_V7 9
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t who;
} pd_assets_thaw_V7_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V7 10
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V7_t;

#define PD_CALL_ASSETS_THAW_ASSET_V7 11
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V7_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V7 12
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t owner;
} pd_assets_transfer_ownership_V7_t;

#define PD_CALL_ASSETS_SET_TEAM_V7 13
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t issuer;
    pd_LookupasStaticLookupSource_V7_t admin;
    pd_LookupasStaticLookupSource_V7_t freezer;
} pd_assets_set_team_V7_t;

#define PD_CALL_ASSETS_SET_METADATA_V7 14
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V7_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V7 15
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V7_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V7 16
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V7_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V7 17
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V7_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V7 18
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t owner;
    pd_LookupasStaticLookupSource_V7_t issuer;
    pd_LookupasStaticLookupSource_V7_t admin;
    pd_LookupasStaticLookupSource_V7_t freezer;
    pd_CompactBalance_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V7_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V7 19
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t delegate;
    pd_CompactBalance_t amount;
} pd_assets_approve_transfer_V7_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V7 20
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t delegate;
} pd_assets_cancel_approval_V7_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V7 21
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t owner;
    pd_LookupasStaticLookupSource_V7_t delegate;
} pd_assets_force_cancel_approval_V7_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V7 22
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V7_t owner;
    pd_LookupasStaticLookupSource_V7_t destination;
    pd_CompactBalance_t amount;
} pd_assets_transfer_approved_V7_t;

#endif

typedef union {
    pd_balances_transfer_V7_t balances_transfer_V7;
    pd_balances_force_transfer_V7_t balances_force_transfer_V7;
    pd_balances_transfer_keep_alive_V7_t balances_transfer_keep_alive_V7;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V7_t system_fill_block_V7;
    pd_system_remark_V7_t system_remark_V7;
    pd_system_set_heap_pages_V7_t system_set_heap_pages_V7;
    pd_system_set_code_V7_t system_set_code_V7;
    pd_system_set_code_without_checks_V7_t system_set_code_without_checks_V7;
    pd_system_remark_with_event_V7_t system_remark_with_event_V7;
    pd_balances_set_balance_V7_t balances_set_balance_V7;
    pd_multisig_as_multi_threshold_1_V7_t multisig_as_multi_threshold_1_V7;
    pd_multisig_as_multi_V7_t multisig_as_multi_V7;
    pd_multisig_approve_as_multi_V7_t multisig_approve_as_multi_V7;
    pd_multisig_cancel_as_multi_V7_t multisig_cancel_as_multi_V7;
    pd_proxy_proxy_V7_t proxy_proxy_V7;
    pd_assets_force_create_V7_t assets_force_create_V7;
    pd_assets_mint_V7_t assets_mint_V7;
    pd_assets_burn_V7_t assets_burn_V7;
    pd_assets_transfer_V7_t assets_transfer_V7;
    pd_assets_transfer_keep_alive_V7_t assets_transfer_keep_alive_V7;
    pd_assets_force_transfer_V7_t assets_force_transfer_V7;
    pd_assets_freeze_V7_t assets_freeze_V7;
    pd_assets_thaw_V7_t assets_thaw_V7;
    pd_assets_freeze_asset_V7_t assets_freeze_asset_V7;
    pd_assets_thaw_asset_V7_t assets_thaw_asset_V7;
    pd_assets_transfer_ownership_V7_t assets_transfer_ownership_V7;
    pd_assets_set_team_V7_t assets_set_team_V7;
    pd_assets_set_metadata_V7_t assets_set_metadata_V7;
    pd_assets_clear_metadata_V7_t assets_clear_metadata_V7;
    pd_assets_force_set_metadata_V7_t assets_force_set_metadata_V7;
    pd_assets_force_clear_metadata_V7_t assets_force_clear_metadata_V7;
    pd_assets_force_asset_status_V7_t assets_force_asset_status_V7;
    pd_assets_approve_transfer_V7_t assets_approve_transfer_V7;
    pd_assets_cancel_approval_V7_t assets_cancel_approval_V7;
    pd_assets_force_cancel_approval_V7_t assets_force_cancel_approval_V7;
    pd_assets_transfer_approved_V7_t assets_transfer_approved_V7;
#endif
} pd_MethodNested_V7_t;

typedef union {
    pd_MethodBasic_V7_t basic;
    pd_MethodNested_V7_t nested;
} pd_Method_V7_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
