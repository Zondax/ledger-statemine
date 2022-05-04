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
#include "substrate_types_V6.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V6 0
#define PD_CALL_TIMESTAMP_V6 3
#define PD_CALL_BALANCES_V6 10
#define PD_CALL_COLLATORSELECTION_V6 21
#define PD_CALL_SESSION_V6 22
#define PD_CALL_XCMPQUEUE_V6 30
#define PD_CALL_UTILITY_V6 40
#define PD_CALL_MULTISIG_V6 41
#define PD_CALL_PROXY_V6 42
#define PD_CALL_ASSETS_V6 50
#define PD_CALL_UNIQUES_V6 51

#define PD_CALL_BALANCES_TRANSFER_ALL_V6 4
typedef struct {
    pd_LookupasStaticLookupSource_V6_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V6_t;

#define PD_CALL_SESSION_SET_KEYS_V6 0
typedef struct {
    pd_Keys_V6_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V6_t;

#define PD_CALL_SESSION_PURGE_KEYS_V6 1
typedef struct {
} pd_session_purge_keys_V6_t;

#define PD_CALL_UTILITY_BATCH_V6 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V6_t;

#define PD_CALL_UTILITY_BATCH_ALL_V6 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V6_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V6 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V6_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V6 5
typedef struct {
    pd_LookupasStaticLookupSource_V6_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V6_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V6 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V6_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V6 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V6_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V6 3
typedef struct {
} pd_collatorselection_register_as_candidate_V6_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V6 4
typedef struct {
} pd_collatorselection_leave_intent_V6_t;

#define PD_CALL_XCMPQUEUE_SUSPEND_XCM_EXECUTION_V6 1
typedef struct {
} pd_xcmpqueue_suspend_xcm_execution_V6_t;

#define PD_CALL_XCMPQUEUE_RESUME_XCM_EXECUTION_V6 2
typedef struct {
} pd_xcmpqueue_resume_xcm_execution_V6_t;

#define PD_CALL_XCMPQUEUE_UPDATE_SUSPEND_THRESHOLD_V6 3
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_suspend_threshold_V6_t;

#define PD_CALL_XCMPQUEUE_UPDATE_DROP_THRESHOLD_V6 4
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_drop_threshold_V6_t;

#define PD_CALL_XCMPQUEUE_UPDATE_RESUME_THRESHOLD_V6 5
typedef struct {
    pd_u32_t new_;
} pd_xcmpqueue_update_resume_threshold_V6_t;

#define PD_CALL_XCMPQUEUE_UPDATE_THRESHOLD_WEIGHT_V6 6
typedef struct {
    pd_Weight_V6_t new_;
} pd_xcmpqueue_update_threshold_weight_V6_t;

#define PD_CALL_XCMPQUEUE_UPDATE_WEIGHT_RESTRICT_DECAY_V6 7
typedef struct {
    pd_Weight_V6_t new_;
} pd_xcmpqueue_update_weight_restrict_decay_V6_t;

#define PD_CALL_XCMPQUEUE_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT_V6 8
typedef struct {
    pd_Weight_V6_t new_;
} pd_xcmpqueue_update_xcmp_max_individual_weight_V6_t;

#define PD_CALL_PROXY_ADD_PROXY_V6 1
typedef struct {
    pd_AccountId_V6_t delegate;
    pd_ProxyType_V6_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V6_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V6 2
typedef struct {
    pd_AccountId_V6_t delegate;
    pd_ProxyType_V6_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V6_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V6 3
typedef struct {
} pd_proxy_remove_proxies_V6_t;

#define PD_CALL_PROXY_ANONYMOUS_V6 4
typedef struct {
    pd_ProxyType_V6_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V6_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V6 5
typedef struct {
    pd_AccountId_V6_t spawner;
    pd_ProxyType_V6_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V6_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V6 9
typedef struct {
    pd_AccountId_V6_t delegate;
    pd_AccountId_V6_t real;
    pd_OptionProxyType_V6_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V6_t;

#define PD_CALL_ASSETS_TOUCH_V6 23
typedef struct {
    pd_Compactu32_t id;
} pd_assets_touch_V6_t;

#define PD_CALL_ASSETS_REFUND_V6 24
typedef struct {
    pd_Compactu32_t id;
    pd_bool_t allow_burn;
} pd_assets_refund_V6_t;

#define PD_CALL_UNIQUES_CREATE_V6 0
typedef struct {
    pd_ClassId_V6_t class_;
    pd_LookupasStaticLookupSource_V6_t admin;
} pd_uniques_create_V6_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V6 1
typedef struct {
    pd_ClassId_V6_t class_;
    pd_LookupasStaticLookupSource_V6_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V6_t;

#define PD_CALL_UNIQUES_DESTROY_V6 2
typedef struct {
    pd_ClassId_V6_t class_;
    pd_DestroyWitness_V6_t witness;
} pd_uniques_destroy_V6_t;

#define PD_CALL_UNIQUES_MINT_V6 3
typedef struct {
    pd_ClassId_V6_t class_;
    pd_InstanceId_V6_t instance;
    pd_LookupasStaticLookupSource_V6_t owner;
} pd_uniques_mint_V6_t;

#define PD_CALL_UNIQUES_BURN_V6 4
typedef struct {
    pd_ClassId_V6_t class_;
    pd_InstanceId_V6_t instance;
    pd_OptionLookupasStaticLookupSource_V6_t check_owner;
} pd_uniques_burn_V6_t;

#define PD_CALL_UNIQUES_TRANSFER_V6 5
typedef struct {
    pd_ClassId_V6_t class_;
    pd_InstanceId_V6_t instance;
    pd_LookupasStaticLookupSource_V6_t dest;
} pd_uniques_transfer_V6_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V6 6
typedef struct {
    pd_ClassId_V6_t class_;
    pd_VecInstanceId_V6_t instances;
} pd_uniques_redeposit_V6_t;

#define PD_CALL_UNIQUES_FREEZE_V6 7
typedef struct {
    pd_ClassId_V6_t class_;
    pd_InstanceId_V6_t instance;
} pd_uniques_freeze_V6_t;

#define PD_CALL_UNIQUES_THAW_V6 8
typedef struct {
    pd_ClassId_V6_t class_;
    pd_InstanceId_V6_t instance;
} pd_uniques_thaw_V6_t;

#define PD_CALL_UNIQUES_FREEZE_CLASS_V6 9
typedef struct {
    pd_ClassId_V6_t class_;
} pd_uniques_freeze_class_V6_t;

#define PD_CALL_UNIQUES_THAW_CLASS_V6 10
typedef struct {
    pd_ClassId_V6_t class_;
} pd_uniques_thaw_class_V6_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V6 11
typedef struct {
    pd_ClassId_V6_t class_;
    pd_LookupasStaticLookupSource_V6_t owner;
} pd_uniques_transfer_ownership_V6_t;

#define PD_CALL_UNIQUES_SET_TEAM_V6 12
typedef struct {
    pd_ClassId_V6_t class_;
    pd_LookupasStaticLookupSource_V6_t issuer;
    pd_LookupasStaticLookupSource_V6_t admin;
    pd_LookupasStaticLookupSource_V6_t freezer;
} pd_uniques_set_team_V6_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V6 13
typedef struct {
    pd_ClassId_V6_t class_;
    pd_InstanceId_V6_t instance;
    pd_LookupasStaticLookupSource_V6_t delegate;
} pd_uniques_approve_transfer_V6_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V6 14
typedef struct {
    pd_ClassId_V6_t class_;
    pd_InstanceId_V6_t instance;
    pd_OptionLookupasStaticLookupSource_V6_t maybe_check_delegate;
} pd_uniques_cancel_approval_V6_t;

#define PD_CALL_UNIQUES_FORCE_ASSET_STATUS_V6 15
typedef struct {
    pd_ClassId_V6_t class_;
    pd_LookupasStaticLookupSource_V6_t owner;
    pd_LookupasStaticLookupSource_V6_t issuer;
    pd_LookupasStaticLookupSource_V6_t admin;
    pd_LookupasStaticLookupSource_V6_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_asset_status_V6_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V6 16
typedef struct {
    pd_ClassId_V6_t class_;
    pd_OptionInstanceId_V6_t maybe_instance;
    pd_BoundedVecu8_V6_t key;
    pd_BoundedVecu8_V6_t value;
} pd_uniques_set_attribute_V6_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V6 17
typedef struct {
    pd_ClassId_V6_t class_;
    pd_OptionInstanceId_V6_t maybe_instance;
    pd_BoundedVecu8_V6_t key;
} pd_uniques_clear_attribute_V6_t;

#define PD_CALL_UNIQUES_SET_METADATA_V6 18
typedef struct {
    pd_ClassId_V6_t class_;
    pd_InstanceId_V6_t instance;
    pd_BoundedVecu8_V6_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V6_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V6 19
typedef struct {
    pd_ClassId_V6_t class_;
    pd_InstanceId_V6_t instance;
} pd_uniques_clear_metadata_V6_t;

#define PD_CALL_UNIQUES_SET_CLASS_METADATA_V6 20
typedef struct {
    pd_ClassId_V6_t class_;
    pd_BoundedVecu8_V6_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_class_metadata_V6_t;

#define PD_CALL_UNIQUES_CLEAR_CLASS_METADATA_V6 21
typedef struct {
    pd_ClassId_V6_t class_;
} pd_uniques_clear_class_metadata_V6_t;

#define PD_CALL_UNIQUES_SET_ACCEPT_OWNERSHIP_V6 22
typedef struct {
    pd_OptionClassId_V6_t maybe_class;
} pd_uniques_set_accept_ownership_V6_t;

#endif

typedef union {
    pd_balances_transfer_all_V6_t balances_transfer_all_V6;
    pd_session_set_keys_V6_t session_set_keys_V6;
    pd_session_purge_keys_V6_t session_purge_keys_V6;
    pd_utility_batch_V6_t utility_batch_V6;
    pd_utility_batch_all_V6_t utility_batch_all_V6;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V6_t timestamp_set_V6;
    pd_balances_force_unreserve_V6_t balances_force_unreserve_V6;
    pd_collatorselection_set_desired_candidates_V6_t collatorselection_set_desired_candidates_V6;
    pd_collatorselection_set_candidacy_bond_V6_t collatorselection_set_candidacy_bond_V6;
    pd_collatorselection_register_as_candidate_V6_t collatorselection_register_as_candidate_V6;
    pd_collatorselection_leave_intent_V6_t collatorselection_leave_intent_V6;
    pd_xcmpqueue_suspend_xcm_execution_V6_t xcmpqueue_suspend_xcm_execution_V6;
    pd_xcmpqueue_resume_xcm_execution_V6_t xcmpqueue_resume_xcm_execution_V6;
    pd_xcmpqueue_update_suspend_threshold_V6_t xcmpqueue_update_suspend_threshold_V6;
    pd_xcmpqueue_update_drop_threshold_V6_t xcmpqueue_update_drop_threshold_V6;
    pd_xcmpqueue_update_resume_threshold_V6_t xcmpqueue_update_resume_threshold_V6;
    pd_xcmpqueue_update_threshold_weight_V6_t xcmpqueue_update_threshold_weight_V6;
    pd_xcmpqueue_update_weight_restrict_decay_V6_t xcmpqueue_update_weight_restrict_decay_V6;
    pd_xcmpqueue_update_xcmp_max_individual_weight_V6_t xcmpqueue_update_xcmp_max_individual_weight_V6;
    pd_proxy_add_proxy_V6_t proxy_add_proxy_V6;
    pd_proxy_remove_proxy_V6_t proxy_remove_proxy_V6;
    pd_proxy_remove_proxies_V6_t proxy_remove_proxies_V6;
    pd_proxy_anonymous_V6_t proxy_anonymous_V6;
    pd_proxy_kill_anonymous_V6_t proxy_kill_anonymous_V6;
    pd_proxy_proxy_announced_V6_t proxy_proxy_announced_V6;
    pd_assets_touch_V6_t assets_touch_V6;
    pd_assets_refund_V6_t assets_refund_V6;
    pd_uniques_create_V6_t uniques_create_V6;
    pd_uniques_force_create_V6_t uniques_force_create_V6;
    pd_uniques_destroy_V6_t uniques_destroy_V6;
    pd_uniques_mint_V6_t uniques_mint_V6;
    pd_uniques_burn_V6_t uniques_burn_V6;
    pd_uniques_transfer_V6_t uniques_transfer_V6;
    pd_uniques_redeposit_V6_t uniques_redeposit_V6;
    pd_uniques_freeze_V6_t uniques_freeze_V6;
    pd_uniques_thaw_V6_t uniques_thaw_V6;
    pd_uniques_freeze_class_V6_t uniques_freeze_class_V6;
    pd_uniques_thaw_class_V6_t uniques_thaw_class_V6;
    pd_uniques_transfer_ownership_V6_t uniques_transfer_ownership_V6;
    pd_uniques_set_team_V6_t uniques_set_team_V6;
    pd_uniques_approve_transfer_V6_t uniques_approve_transfer_V6;
    pd_uniques_cancel_approval_V6_t uniques_cancel_approval_V6;
    pd_uniques_force_asset_status_V6_t uniques_force_asset_status_V6;
    pd_uniques_set_attribute_V6_t uniques_set_attribute_V6;
    pd_uniques_clear_attribute_V6_t uniques_clear_attribute_V6;
    pd_uniques_set_metadata_V6_t uniques_set_metadata_V6;
    pd_uniques_clear_metadata_V6_t uniques_clear_metadata_V6;
    pd_uniques_set_class_metadata_V6_t uniques_set_class_metadata_V6;
    pd_uniques_clear_class_metadata_V6_t uniques_clear_class_metadata_V6;
    pd_uniques_set_accept_ownership_V6_t uniques_set_accept_ownership_V6;
#endif
} pd_MethodBasic_V6_t;

#define PD_CALL_BALANCES_TRANSFER_V6 0
typedef struct {
    pd_LookupasStaticLookupSource_V6_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V6_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V6 2
typedef struct {
    pd_LookupasStaticLookupSource_V6_t source;
    pd_LookupasStaticLookupSource_V6_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V6_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V6 3
typedef struct {
    pd_LookupasStaticLookupSource_V6_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V6_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V6 0
typedef struct {
    pd_Perbill_V6_t ratio;
} pd_system_fill_block_V6_t;

#define PD_CALL_SYSTEM_REMARK_V6 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V6_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V6 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V6_t;

#define PD_CALL_SYSTEM_SET_CODE_V6 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V6_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V6 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V6_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V6 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V6_t;

#define PD_CALL_BALANCES_SET_BALANCE_V6 1
typedef struct {
    pd_LookupasStaticLookupSource_V6_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V6_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V6 0
typedef struct {
    pd_VecAccountId_V6_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V6_t;

#define PD_CALL_MULTISIG_AS_MULTI_V6 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V6_t other_signatories;
    pd_OptionTimepoint_V6_t maybe_timepoint;
    pd_OpaqueCall_V6_t call;
    pd_bool_t store_call;
    pd_Weight_V6_t max_weight;
} pd_multisig_as_multi_V6_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V6 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V6_t other_signatories;
    pd_OptionTimepoint_V6_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V6_t max_weight;
} pd_multisig_approve_as_multi_V6_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V6 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V6_t other_signatories;
    pd_Timepoint_V6_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V6_t;

#define PD_CALL_PROXY_PROXY_V6 0
typedef struct {
    pd_AccountId_V6_t real;
    pd_OptionProxyType_V6_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V6_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V6 1
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t owner;
    pd_bool_t is_sufficient;
    pd_CompactBalance_t min_balance;
} pd_assets_force_create_V6_t;

#define PD_CALL_ASSETS_MINT_V6 3
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t beneficiary;
    pd_CompactBalance_t amount;
} pd_assets_mint_V6_t;

#define PD_CALL_ASSETS_BURN_V6 4
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t who;
    pd_CompactBalance_t amount;
} pd_assets_burn_V6_t;

#define PD_CALL_ASSETS_TRANSFER_V6 5
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_V6_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V6 6
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_keep_alive_V6_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V6 7
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t source;
    pd_LookupasStaticLookupSource_V6_t dest;
    pd_CompactBalance_t amount;
} pd_assets_force_transfer_V6_t;

#define PD_CALL_ASSETS_FREEZE_V6 8
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t who;
} pd_assets_freeze_V6_t;

#define PD_CALL_ASSETS_THAW_V6 9
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t who;
} pd_assets_thaw_V6_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V6 10
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V6_t;

#define PD_CALL_ASSETS_THAW_ASSET_V6 11
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V6_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V6 12
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t owner;
} pd_assets_transfer_ownership_V6_t;

#define PD_CALL_ASSETS_SET_TEAM_V6 13
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t issuer;
    pd_LookupasStaticLookupSource_V6_t admin;
    pd_LookupasStaticLookupSource_V6_t freezer;
} pd_assets_set_team_V6_t;

#define PD_CALL_ASSETS_SET_METADATA_V6 14
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V6_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V6 15
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V6_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V6 16
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V6_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V6 17
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V6_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V6 18
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t owner;
    pd_LookupasStaticLookupSource_V6_t issuer;
    pd_LookupasStaticLookupSource_V6_t admin;
    pd_LookupasStaticLookupSource_V6_t freezer;
    pd_CompactBalance_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V6_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V6 19
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t delegate;
    pd_CompactBalance_t amount;
} pd_assets_approve_transfer_V6_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V6 20
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t delegate;
} pd_assets_cancel_approval_V6_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V6 21
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t owner;
    pd_LookupasStaticLookupSource_V6_t delegate;
} pd_assets_force_cancel_approval_V6_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V6 22
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V6_t owner;
    pd_LookupasStaticLookupSource_V6_t destination;
    pd_CompactBalance_t amount;
} pd_assets_transfer_approved_V6_t;

#endif

typedef union {
    pd_balances_transfer_V6_t balances_transfer_V6;
    pd_balances_force_transfer_V6_t balances_force_transfer_V6;
    pd_balances_transfer_keep_alive_V6_t balances_transfer_keep_alive_V6;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V6_t system_fill_block_V6;
    pd_system_remark_V6_t system_remark_V6;
    pd_system_set_heap_pages_V6_t system_set_heap_pages_V6;
    pd_system_set_code_V6_t system_set_code_V6;
    pd_system_set_code_without_checks_V6_t system_set_code_without_checks_V6;
    pd_system_remark_with_event_V6_t system_remark_with_event_V6;
    pd_balances_set_balance_V6_t balances_set_balance_V6;
    pd_multisig_as_multi_threshold_1_V6_t multisig_as_multi_threshold_1_V6;
    pd_multisig_as_multi_V6_t multisig_as_multi_V6;
    pd_multisig_approve_as_multi_V6_t multisig_approve_as_multi_V6;
    pd_multisig_cancel_as_multi_V6_t multisig_cancel_as_multi_V6;
    pd_proxy_proxy_V6_t proxy_proxy_V6;
    pd_assets_force_create_V6_t assets_force_create_V6;
    pd_assets_mint_V6_t assets_mint_V6;
    pd_assets_burn_V6_t assets_burn_V6;
    pd_assets_transfer_V6_t assets_transfer_V6;
    pd_assets_transfer_keep_alive_V6_t assets_transfer_keep_alive_V6;
    pd_assets_force_transfer_V6_t assets_force_transfer_V6;
    pd_assets_freeze_V6_t assets_freeze_V6;
    pd_assets_thaw_V6_t assets_thaw_V6;
    pd_assets_freeze_asset_V6_t assets_freeze_asset_V6;
    pd_assets_thaw_asset_V6_t assets_thaw_asset_V6;
    pd_assets_transfer_ownership_V6_t assets_transfer_ownership_V6;
    pd_assets_set_team_V6_t assets_set_team_V6;
    pd_assets_set_metadata_V6_t assets_set_metadata_V6;
    pd_assets_clear_metadata_V6_t assets_clear_metadata_V6;
    pd_assets_force_set_metadata_V6_t assets_force_set_metadata_V6;
    pd_assets_force_clear_metadata_V6_t assets_force_clear_metadata_V6;
    pd_assets_force_asset_status_V6_t assets_force_asset_status_V6;
    pd_assets_approve_transfer_V6_t assets_approve_transfer_V6;
    pd_assets_cancel_approval_V6_t assets_cancel_approval_V6;
    pd_assets_force_cancel_approval_V6_t assets_force_cancel_approval_V6;
    pd_assets_transfer_approved_V6_t assets_transfer_approved_V6;
#endif
} pd_MethodNested_V6_t;

typedef union {
    pd_MethodBasic_V6_t basic;
    pd_MethodNested_V6_t nested;
} pd_Method_V6_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
