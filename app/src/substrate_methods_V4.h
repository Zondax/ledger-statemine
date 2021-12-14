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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V4.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V4 0
#define PD_CALL_TIMESTAMP_V4 3
#define PD_CALL_BALANCES_V4 10
#define PD_CALL_COLLATORSELECTION_V4 21
#define PD_CALL_SESSION_V4 22
#define PD_CALL_UTILITY_V4 40
#define PD_CALL_MULTISIG_V4 41
#define PD_CALL_PROXY_V4 42
#define PD_CALL_ASSETS_V4 50

#define PD_CALL_BALANCES_TRANSFER_ALL_V4 4
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V4_t;

#define PD_CALL_SESSION_SET_KEYS_V4 0
typedef struct {
    pd_Keys_V4_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V4_t;

#define PD_CALL_SESSION_PURGE_KEYS_V4 1
typedef struct {
} pd_session_purge_keys_V4_t;

#define PD_CALL_UTILITY_BATCH_V4 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V4_t;

#define PD_CALL_UTILITY_BATCH_ALL_V4 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V4_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V4 9
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V4_t;

#define PD_CALL_TIMESTAMP_SET_V4 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V4_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V4 5
typedef struct {
    pd_LookupasStaticLookupSource_V4_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V4_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V4 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V4_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V4 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V4_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V4 3
typedef struct {
} pd_collatorselection_register_as_candidate_V4_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V4 4
typedef struct {
} pd_collatorselection_leave_intent_V4_t;

#define PD_CALL_PROXY_ADD_PROXY_V4 1
typedef struct {
    pd_AccountId_V4_t delegate;
    pd_ProxyType_V4_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V4_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V4 2
typedef struct {
    pd_AccountId_V4_t delegate;
    pd_ProxyType_V4_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V4_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V4 3
typedef struct {
} pd_proxy_remove_proxies_V4_t;

#define PD_CALL_PROXY_ANONYMOUS_V4 4
typedef struct {
    pd_ProxyType_V4_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V4_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V4 5
typedef struct {
    pd_AccountId_V4_t spawner;
    pd_ProxyType_V4_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V4_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V4 9
typedef struct {
    pd_AccountId_V4_t delegate;
    pd_AccountId_V4_t real;
    pd_OptionProxyType_V4_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V4_t;

#endif

typedef union {
    pd_balances_transfer_all_V4_t balances_transfer_all_V4;
    pd_session_set_keys_V4_t session_set_keys_V4;
    pd_session_purge_keys_V4_t session_purge_keys_V4;
    pd_utility_batch_V4_t utility_batch_V4;
    pd_utility_batch_all_V4_t utility_batch_all_V4;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_remark_with_event_V4_t system_remark_with_event_V4;
    pd_timestamp_set_V4_t timestamp_set_V4;
    pd_balances_force_unreserve_V4_t balances_force_unreserve_V4;
    pd_collatorselection_set_desired_candidates_V4_t collatorselection_set_desired_candidates_V4;
    pd_collatorselection_set_candidacy_bond_V4_t collatorselection_set_candidacy_bond_V4;
    pd_collatorselection_register_as_candidate_V4_t collatorselection_register_as_candidate_V4;
    pd_collatorselection_leave_intent_V4_t collatorselection_leave_intent_V4;
    pd_proxy_add_proxy_V4_t proxy_add_proxy_V4;
    pd_proxy_remove_proxy_V4_t proxy_remove_proxy_V4;
    pd_proxy_remove_proxies_V4_t proxy_remove_proxies_V4;
    pd_proxy_anonymous_V4_t proxy_anonymous_V4;
    pd_proxy_kill_anonymous_V4_t proxy_kill_anonymous_V4;
    pd_proxy_proxy_announced_V4_t proxy_proxy_announced_V4;
#endif
} pd_MethodBasic_V4_t;

#define PD_CALL_BALANCES_TRANSFER_V4 0
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t Amount;
} pd_balances_transfer_V4_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V4 2
typedef struct {
    pd_LookupasStaticLookupSource_V4_t source;
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t Amount;
} pd_balances_force_transfer_V4_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V4 3
typedef struct {
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t Amount;
} pd_balances_transfer_keep_alive_V4_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V4 0
typedef struct {
    pd_Perbill_V4_t ratio;
} pd_system_fill_block_V4_t;

#define PD_CALL_SYSTEM_REMARK_V4 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V4_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V4 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_V4 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V4 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V4_t;

#define PD_CALL_BALANCES_SET_BALANCE_V4 1
typedef struct {
    pd_LookupasStaticLookupSource_V4_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V4_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V4 0
typedef struct {
    pd_VecAccountId_V4_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V4_t;

#define PD_CALL_MULTISIG_AS_MULTI_V4 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_OptionTimepoint_V4_t maybe_timepoint;
    pd_OpaqueCall_V4_t call;
    pd_bool_t store_call;
    pd_Weight_V4_t max_weight;
} pd_multisig_as_multi_V4_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V4 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_OptionTimepoint_V4_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V4_t max_weight;
} pd_multisig_approve_as_multi_V4_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V4 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V4_t other_signatories;
    pd_Timepoint_V4_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V4_t;

#define PD_CALL_PROXY_PROXY_V4 0
typedef struct {
    pd_AccountId_V4_t real;
    pd_OptionProxyType_V4_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V4_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V4 1
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t owner;
    pd_bool_t is_sufficient;
    pd_CompactBalance_t min_balance;
} pd_assets_force_create_V4_t;

#define PD_CALL_ASSETS_MINT_V4 3
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t beneficiary;
    pd_CompactBalance_t amount;
} pd_assets_mint_V4_t;

#define PD_CALL_ASSETS_BURN_V4 4
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t who;
    pd_CompactBalance_t amount;
} pd_assets_burn_V4_t;

#define PD_CALL_ASSETS_TRANSFER_V4 5
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_V4_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V4 6
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_keep_alive_V4_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V4 7
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t source;
    pd_LookupasStaticLookupSource_V4_t dest;
    pd_CompactBalance_t amount;
} pd_assets_force_transfer_V4_t;

#define PD_CALL_ASSETS_FREEZE_V4 8
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t who;
} pd_assets_freeze_V4_t;

#define PD_CALL_ASSETS_THAW_V4 9
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t who;
} pd_assets_thaw_V4_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V4 10
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V4_t;

#define PD_CALL_ASSETS_THAW_ASSET_V4 11
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V4_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V4 12
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t owner;
} pd_assets_transfer_ownership_V4_t;

#define PD_CALL_ASSETS_SET_TEAM_V4 13
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t issuer;
    pd_LookupasStaticLookupSource_V4_t admin;
    pd_LookupasStaticLookupSource_V4_t freezer;
} pd_assets_set_team_V4_t;

#define PD_CALL_ASSETS_SET_METADATA_V4 14
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V4_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V4 15
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V4_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V4 16
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V4_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V4 17
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V4_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V4 18
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t owner;
    pd_LookupasStaticLookupSource_V4_t issuer;
    pd_LookupasStaticLookupSource_V4_t admin;
    pd_LookupasStaticLookupSource_V4_t freezer;
    pd_CompactBalance_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V4_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V4 19
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t delegate;
    pd_CompactBalance_t amount;
} pd_assets_approve_transfer_V4_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V4 20
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t delegate;
} pd_assets_cancel_approval_V4_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V4 21
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t owner;
    pd_LookupasStaticLookupSource_V4_t delegate;
} pd_assets_force_cancel_approval_V4_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V4 22
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V4_t owner;
    pd_LookupasStaticLookupSource_V4_t destination;
    pd_CompactBalance_t amount;
} pd_assets_transfer_approved_V4_t;

#endif

typedef union {
    pd_balances_transfer_V4_t balances_transfer_V4;
    pd_balances_force_transfer_V4_t balances_force_transfer_V4;
    pd_balances_transfer_keep_alive_V4_t balances_transfer_keep_alive_V4;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V4_t system_fill_block_V4;
    pd_system_remark_V4_t system_remark_V4;
    pd_system_set_heap_pages_V4_t system_set_heap_pages_V4;
    pd_system_set_code_V4_t system_set_code_V4;
    pd_system_set_code_without_checks_V4_t system_set_code_without_checks_V4;
    pd_balances_set_balance_V4_t balances_set_balance_V4;
    pd_multisig_as_multi_threshold_1_V4_t multisig_as_multi_threshold_1_V4;
    pd_multisig_as_multi_V4_t multisig_as_multi_V4;
    pd_multisig_approve_as_multi_V4_t multisig_approve_as_multi_V4;
    pd_multisig_cancel_as_multi_V4_t multisig_cancel_as_multi_V4;
    pd_proxy_proxy_V4_t proxy_proxy_V4;
    pd_assets_force_create_V4_t assets_force_create_V4;
    pd_assets_mint_V4_t assets_mint_V4;
    pd_assets_burn_V4_t assets_burn_V4;
    pd_assets_transfer_V4_t assets_transfer_V4;
    pd_assets_transfer_keep_alive_V4_t assets_transfer_keep_alive_V4;
    pd_assets_force_transfer_V4_t assets_force_transfer_V4;
    pd_assets_freeze_V4_t assets_freeze_V4;
    pd_assets_thaw_V4_t assets_thaw_V4;
    pd_assets_freeze_asset_V4_t assets_freeze_asset_V4;
    pd_assets_thaw_asset_V4_t assets_thaw_asset_V4;
    pd_assets_transfer_ownership_V4_t assets_transfer_ownership_V4;
    pd_assets_set_team_V4_t assets_set_team_V4;
    pd_assets_set_metadata_V4_t assets_set_metadata_V4;
    pd_assets_clear_metadata_V4_t assets_clear_metadata_V4;
    pd_assets_force_set_metadata_V4_t assets_force_set_metadata_V4;
    pd_assets_force_clear_metadata_V4_t assets_force_clear_metadata_V4;
    pd_assets_force_asset_status_V4_t assets_force_asset_status_V4;
    pd_assets_approve_transfer_V4_t assets_approve_transfer_V4;
    pd_assets_cancel_approval_V4_t assets_cancel_approval_V4;
    pd_assets_force_cancel_approval_V4_t assets_force_cancel_approval_V4;
    pd_assets_transfer_approved_V4_t assets_transfer_approved_V4;
#endif
} pd_MethodNested_V4_t;

typedef union {
    pd_MethodBasic_V4_t basic;
    pd_MethodNested_V4_t nested;
} pd_Method_V4_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
