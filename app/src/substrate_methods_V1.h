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
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_PARACHAINSYSTEM_V1 1
#define PD_CALL_TIMESTAMP_V1 3
#define PD_CALL_BALANCES_V1 10
#define PD_CALL_AUTHORSHIP_V1 20
#define PD_CALL_COLLATORSELECTION_V1 21
#define PD_CALL_SESSION_V1 22
#define PD_CALL_XCMPQUEUE_V1 30
#define PD_CALL_POLKADOTXCM_V1 31
#define PD_CALL_DMPQUEUE_V1 33
#define PD_CALL_UTILITY_V1 40
#define PD_CALL_MULTISIG_V1 41
#define PD_CALL_PROXY_V1 42
#define PD_CALL_ASSETS_V1 50
#define PD_CALL_UNIQUES_V1 51

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#define PD_CALL_UTILITY_BATCH_ALL_V1 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V1 9
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V1_t;

#define PD_CALL_PARACHAINSYSTEM_SET_UPGRADE_BLOCK_V1 0
typedef struct {
    pd_RelayChainBlockNumber_V1_t relay_chain_block;
} pd_parachainsystem_set_upgrade_block_V1_t;

#define PD_CALL_PARACHAINSYSTEM_SET_VALIDATION_DATA_V1 1
typedef struct {
    pd_ParachainInherentData_V1_t data;
} pd_parachainsystem_set_validation_data_V1_t;

#define PD_CALL_PARACHAINSYSTEM_SUDO_SEND_UPWARD_MESSAGE_V1 2
typedef struct {
    pd_UpwardMessage_V1_t message;
} pd_parachainsystem_sudo_send_upward_message_V1_t;

#define PD_CALL_PARACHAINSYSTEM_AUTHORIZE_UPGRADE_V1 3
typedef struct {
    pd_Hash_t code_hash;
} pd_parachainsystem_authorize_upgrade_V1_t;

#define PD_CALL_PARACHAINSYSTEM_ENACT_AUTHORIZED_UPGRADE_V1 4
typedef struct {
    pd_Bytes_t code;
} pd_parachainsystem_enact_authorized_upgrade_V1_t;

#define PD_CALL_TIMESTAMP_SET_V1 0
typedef struct {
    pd_CompactMoment_V1_t now;
} pd_timestamp_set_V1_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V1 4
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V1_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V1 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V1_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V1 0
typedef struct {
    pd_VecAccountId_V1_t new_;
} pd_collatorselection_set_invulnerables_V1_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V1 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V1_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V1 2
typedef struct {
    pd_BalanceOf_t bond;
} pd_collatorselection_set_candidacy_bond_V1_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V1 3
typedef struct {
} pd_collatorselection_register_as_candidate_V1_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V1 4
typedef struct {
} pd_collatorselection_leave_intent_V1_t;

#define PD_CALL_POLKADOTXCM_SEND_V1 0
typedef struct {
    pd_MultiLocation_V1_t dest;
    pd_Xcm_V1_t message;
} pd_polkadotxcm_send_V1_t;

#define PD_CALL_POLKADOTXCM_TELEPORT_ASSETS_V1 1
typedef struct {
    pd_MultiLocation_V1_t dest;
    pd_MultiLocation_V1_t beneficiary;
    pd_VecMultiAsset_V1_t assets;
    pd_Weight_V1_t dest_weight;
} pd_polkadotxcm_teleport_assets_V1_t;

#define PD_CALL_POLKADOTXCM_RESERVE_TRANSFER_ASSETS_V1 2
typedef struct {
    pd_MultiLocation_V1_t dest;
    pd_MultiLocation_V1_t beneficiary;
    pd_VecMultiAsset_V1_t assets;
    pd_Weight_V1_t dest_weight;
} pd_polkadotxcm_reserve_transfer_assets_V1_t;

#define PD_CALL_POLKADOTXCM_EXECUTE_V1 3
typedef struct {
    pd_Xcm_V1_t message;
    pd_Weight_V1_t max_weight;
} pd_polkadotxcm_execute_V1_t;

#define PD_CALL_DMPQUEUE_SERVICE_OVERWEIGHT_V1 0
typedef struct {
    pd_OverweightIndex_V1_t index;
    pd_Weight_V1_t weight_limit;
} pd_dmpqueue_service_overweight_V1_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V1 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V1_t;

#define PD_CALL_PROXY_ADD_PROXY_V1 1
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V1 2
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V1 3
typedef struct {
} pd_proxy_remove_proxies_V1_t;

#define PD_CALL_PROXY_ANONYMOUS_V1 4
typedef struct {
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V1_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V1 5
typedef struct {
    pd_AccountId_V1_t spawner;
    pd_ProxyType_V1_t proxy_type;
    pd_u16_t index;
    pd_CompactBlockNumber_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V1_t;

#define PD_CALL_PROXY_ANNOUNCE_V1 6
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_announce_V1_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V1 7
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_remove_announcement_V1_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V1 8
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_reject_announcement_V1_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V1 9
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V1_t;

#define PD_CALL_UNIQUES_CREATE_V1 0
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_LookupSource_V1_t admin;
} pd_uniques_create_V1_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V1 1
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_LookupSource_V1_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V1_t;

#define PD_CALL_UNIQUES_DESTROY_V1 2
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_DestroyWitness_V1_t witness;
} pd_uniques_destroy_V1_t;

#define PD_CALL_UNIQUES_MINT_V1 3
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_CompactInstanceId_V1_t instance;
    pd_LookupSource_V1_t owner;
} pd_uniques_mint_V1_t;

#define PD_CALL_UNIQUES_BURN_V1 4
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_CompactInstanceId_V1_t instance;
    pd_OptionLookupSource_V1_t check_owner;
} pd_uniques_burn_V1_t;

#define PD_CALL_UNIQUES_TRANSFER_V1 5
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_CompactInstanceId_V1_t instance;
    pd_LookupSource_V1_t dest;
} pd_uniques_transfer_V1_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V1 6
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_VecInstanceId_V1_t instances;
} pd_uniques_redeposit_V1_t;

#define PD_CALL_UNIQUES_FREEZE_V1 7
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_CompactInstanceId_V1_t instance;
} pd_uniques_freeze_V1_t;

#define PD_CALL_UNIQUES_THAW_V1 8
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_CompactInstanceId_V1_t instance;
} pd_uniques_thaw_V1_t;

#define PD_CALL_UNIQUES_FREEZE_CLASS_V1 9
typedef struct {
    pd_CompactClassId_V1_t class_;
} pd_uniques_freeze_class_V1_t;

#define PD_CALL_UNIQUES_THAW_CLASS_V1 10
typedef struct {
    pd_CompactClassId_V1_t class_;
} pd_uniques_thaw_class_V1_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V1 11
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_LookupSource_V1_t owner;
} pd_uniques_transfer_ownership_V1_t;

#define PD_CALL_UNIQUES_SET_TEAM_V1 12
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_LookupSource_V1_t issuer;
    pd_LookupSource_V1_t admin;
    pd_LookupSource_V1_t freezer;
} pd_uniques_set_team_V1_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V1 13
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_CompactInstanceId_V1_t instance;
    pd_LookupSource_V1_t delegate;
} pd_uniques_approve_transfer_V1_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V1 14
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_CompactInstanceId_V1_t instance;
    pd_OptionLookupSource_V1_t maybe_check_delegate;
} pd_uniques_cancel_approval_V1_t;

#define PD_CALL_UNIQUES_FORCE_ASSET_STATUS_V1 15
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_LookupSource_V1_t owner;
    pd_LookupSource_V1_t issuer;
    pd_LookupSource_V1_t admin;
    pd_LookupSource_V1_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_asset_status_V1_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V1 16
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_OptionInstanceId_V1_t maybe_instance;
    pd_Bytes_t key;
    pd_Bytes_t value;
} pd_uniques_set_attribute_V1_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V1 17
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_OptionInstanceId_V1_t maybe_instance;
    pd_Bytes_t key;
} pd_uniques_clear_attribute_V1_t;

#define PD_CALL_UNIQUES_SET_METADATA_V1 18
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_CompactInstanceId_V1_t instance;
    pd_Bytes_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V1_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V1 19
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_CompactInstanceId_V1_t instance;
} pd_uniques_clear_metadata_V1_t;

#define PD_CALL_UNIQUES_SET_CLASS_METADATA_V1 20
typedef struct {
    pd_CompactClassId_V1_t class_;
    pd_Bytes_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_class_metadata_V1_t;

#define PD_CALL_UNIQUES_CLEAR_CLASS_METADATA_V1 21
typedef struct {
    pd_CompactClassId_V1_t class_;
} pd_uniques_clear_class_metadata_V1_t;

#endif

typedef union {
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_all_V1_t utility_batch_all_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_remark_with_event_V1_t system_remark_with_event_V1;
    pd_parachainsystem_set_upgrade_block_V1_t parachainsystem_set_upgrade_block_V1;
    pd_parachainsystem_set_validation_data_V1_t parachainsystem_set_validation_data_V1;
    pd_parachainsystem_sudo_send_upward_message_V1_t parachainsystem_sudo_send_upward_message_V1;
    pd_parachainsystem_authorize_upgrade_V1_t parachainsystem_authorize_upgrade_V1;
    pd_parachainsystem_enact_authorized_upgrade_V1_t parachainsystem_enact_authorized_upgrade_V1;
    pd_timestamp_set_V1_t timestamp_set_V1;
    pd_balances_transfer_all_V1_t balances_transfer_all_V1;
    pd_authorship_set_uncles_V1_t authorship_set_uncles_V1;
    pd_collatorselection_set_invulnerables_V1_t collatorselection_set_invulnerables_V1;
    pd_collatorselection_set_desired_candidates_V1_t collatorselection_set_desired_candidates_V1;
    pd_collatorselection_set_candidacy_bond_V1_t collatorselection_set_candidacy_bond_V1;
    pd_collatorselection_register_as_candidate_V1_t collatorselection_register_as_candidate_V1;
    pd_collatorselection_leave_intent_V1_t collatorselection_leave_intent_V1;
    pd_polkadotxcm_send_V1_t polkadotxcm_send_V1;
    pd_polkadotxcm_teleport_assets_V1_t polkadotxcm_teleport_assets_V1;
    pd_polkadotxcm_reserve_transfer_assets_V1_t polkadotxcm_reserve_transfer_assets_V1;
    pd_polkadotxcm_execute_V1_t polkadotxcm_execute_V1;
    pd_dmpqueue_service_overweight_V1_t dmpqueue_service_overweight_V1;
    pd_utility_as_derivative_V1_t utility_as_derivative_V1;
    pd_proxy_add_proxy_V1_t proxy_add_proxy_V1;
    pd_proxy_remove_proxy_V1_t proxy_remove_proxy_V1;
    pd_proxy_remove_proxies_V1_t proxy_remove_proxies_V1;
    pd_proxy_anonymous_V1_t proxy_anonymous_V1;
    pd_proxy_kill_anonymous_V1_t proxy_kill_anonymous_V1;
    pd_proxy_announce_V1_t proxy_announce_V1;
    pd_proxy_remove_announcement_V1_t proxy_remove_announcement_V1;
    pd_proxy_reject_announcement_V1_t proxy_reject_announcement_V1;
    pd_proxy_proxy_announced_V1_t proxy_proxy_announced_V1;
    pd_uniques_create_V1_t uniques_create_V1;
    pd_uniques_force_create_V1_t uniques_force_create_V1;
    pd_uniques_destroy_V1_t uniques_destroy_V1;
    pd_uniques_mint_V1_t uniques_mint_V1;
    pd_uniques_burn_V1_t uniques_burn_V1;
    pd_uniques_transfer_V1_t uniques_transfer_V1;
    pd_uniques_redeposit_V1_t uniques_redeposit_V1;
    pd_uniques_freeze_V1_t uniques_freeze_V1;
    pd_uniques_thaw_V1_t uniques_thaw_V1;
    pd_uniques_freeze_class_V1_t uniques_freeze_class_V1;
    pd_uniques_thaw_class_V1_t uniques_thaw_class_V1;
    pd_uniques_transfer_ownership_V1_t uniques_transfer_ownership_V1;
    pd_uniques_set_team_V1_t uniques_set_team_V1;
    pd_uniques_approve_transfer_V1_t uniques_approve_transfer_V1;
    pd_uniques_cancel_approval_V1_t uniques_cancel_approval_V1;
    pd_uniques_force_asset_status_V1_t uniques_force_asset_status_V1;
    pd_uniques_set_attribute_V1_t uniques_set_attribute_V1;
    pd_uniques_clear_attribute_V1_t uniques_clear_attribute_V1;
    pd_uniques_set_metadata_V1_t uniques_set_metadata_V1;
    pd_uniques_clear_metadata_V1_t uniques_clear_metadata_V1;
    pd_uniques_set_class_metadata_V1_t uniques_set_class_metadata_V1;
    pd_uniques_clear_class_metadata_V1_t uniques_clear_class_metadata_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_keep_alive_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V1 0
typedef struct {
    pd_Perbill_V1_t _ratio;
} pd_system_fill_block_V1_t;

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V1 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V1_t changes_trie_config;
} pd_system_set_changes_trie_config_V1_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V1 6
typedef struct {
    pd_VecKeyValue_V1_t items;
} pd_system_set_storage_V1_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V1 7
typedef struct {
    pd_VecKey_V1_t keys;
} pd_system_kill_storage_V1_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V1 8
typedef struct {
    pd_Key_V1_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 1
typedef struct {
    pd_LookupSource_V1_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_LookupSource_V1_t source;
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_V1_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_OpaqueCall_V1_t call;
    pd_bool_t store_call;
    pd_Weight_V1_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_u8_array_32_V1_t call_hash;
    pd_Weight_V1_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_Timepoint_V1_t timepoint;
    pd_u8_array_32_V1_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#define PD_CALL_PROXY_PROXY_V1 0
typedef struct {
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V1_t;

#define PD_CALL_ASSETS_CREATE_V1 0
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t admin;
    pd_TAssetBalance_V1_t min_balance;
} pd_assets_create_V1_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V1 1
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t owner;
    pd_bool_t is_sufficient;
    pd_CompactTAssetBalance_V1_t min_balance;
} pd_assets_force_create_V1_t;

#define PD_CALL_ASSETS_DESTROY_V1 2
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_AssetDestroyWitness_V1_t witness;
} pd_assets_destroy_V1_t;

#define PD_CALL_ASSETS_MINT_V1 3
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t beneficiary;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_mint_V1_t;

#define PD_CALL_ASSETS_BURN_V1 4
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t who;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_burn_V1_t;

#define PD_CALL_ASSETS_TRANSFER_V1 5
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t target;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_transfer_V1_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V1 6
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t target;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_transfer_keep_alive_V1_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V1 7
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t source;
    pd_LookupSource_V1_t dest;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_force_transfer_V1_t;

#define PD_CALL_ASSETS_FREEZE_V1 8
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t who;
} pd_assets_freeze_V1_t;

#define PD_CALL_ASSETS_THAW_V1 9
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t who;
} pd_assets_thaw_V1_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V1 10
typedef struct {
    pd_CompactAssetId_V1_t id;
} pd_assets_freeze_asset_V1_t;

#define PD_CALL_ASSETS_THAW_ASSET_V1 11
typedef struct {
    pd_CompactAssetId_V1_t id;
} pd_assets_thaw_asset_V1_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V1 12
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t owner;
} pd_assets_transfer_ownership_V1_t;

#define PD_CALL_ASSETS_SET_TEAM_V1 13
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t issuer;
    pd_LookupSource_V1_t admin;
    pd_LookupSource_V1_t freezer;
} pd_assets_set_team_V1_t;

#define PD_CALL_ASSETS_SET_METADATA_V1 14
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_Bytes_t name;
    pd_Bytes_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V1_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V1 15
typedef struct {
    pd_CompactAssetId_V1_t id;
} pd_assets_clear_metadata_V1_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V1 16
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_Bytes_t name;
    pd_Bytes_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V1_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V1 17
typedef struct {
    pd_CompactAssetId_V1_t id;
} pd_assets_force_clear_metadata_V1_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V1 18
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t owner;
    pd_LookupSource_V1_t issuer;
    pd_LookupSource_V1_t admin;
    pd_LookupSource_V1_t freezer;
    pd_CompactTAssetBalance_V1_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V1_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V1 19
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t delegate;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_approve_transfer_V1_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V1 20
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t delegate;
} pd_assets_cancel_approval_V1_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V1 21
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t owner;
    pd_LookupSource_V1_t delegate;
} pd_assets_force_cancel_approval_V1_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V1 22
typedef struct {
    pd_CompactAssetId_V1_t id;
    pd_LookupSource_V1_t owner;
    pd_LookupSource_V1_t destination;
    pd_CompactTAssetBalance_V1_t amount;
} pd_assets_transfer_approved_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V1_t system_fill_block_V1;
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_set_changes_trie_config_V1_t system_set_changes_trie_config_V1;
    pd_system_set_storage_V1_t system_set_storage_V1;
    pd_system_kill_storage_V1_t system_kill_storage_V1;
    pd_system_kill_prefix_V1_t system_kill_prefix_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_multisig_as_multi_threshold_1_V1_t multisig_as_multi_threshold_1_V1;
    pd_multisig_as_multi_V1_t multisig_as_multi_V1;
    pd_multisig_approve_as_multi_V1_t multisig_approve_as_multi_V1;
    pd_multisig_cancel_as_multi_V1_t multisig_cancel_as_multi_V1;
    pd_proxy_proxy_V1_t proxy_proxy_V1;
    pd_assets_create_V1_t assets_create_V1;
    pd_assets_force_create_V1_t assets_force_create_V1;
    pd_assets_destroy_V1_t assets_destroy_V1;
    pd_assets_mint_V1_t assets_mint_V1;
    pd_assets_burn_V1_t assets_burn_V1;
    pd_assets_transfer_V1_t assets_transfer_V1;
    pd_assets_transfer_keep_alive_V1_t assets_transfer_keep_alive_V1;
    pd_assets_force_transfer_V1_t assets_force_transfer_V1;
    pd_assets_freeze_V1_t assets_freeze_V1;
    pd_assets_thaw_V1_t assets_thaw_V1;
    pd_assets_freeze_asset_V1_t assets_freeze_asset_V1;
    pd_assets_thaw_asset_V1_t assets_thaw_asset_V1;
    pd_assets_transfer_ownership_V1_t assets_transfer_ownership_V1;
    pd_assets_set_team_V1_t assets_set_team_V1;
    pd_assets_set_metadata_V1_t assets_set_metadata_V1;
    pd_assets_clear_metadata_V1_t assets_clear_metadata_V1;
    pd_assets_force_set_metadata_V1_t assets_force_set_metadata_V1;
    pd_assets_force_clear_metadata_V1_t assets_force_clear_metadata_V1;
    pd_assets_force_asset_status_V1_t assets_force_asset_status_V1;
    pd_assets_approve_transfer_V1_t assets_approve_transfer_V1;
    pd_assets_cancel_approval_V1_t assets_cancel_approval_V1;
    pd_assets_force_cancel_approval_V1_t assets_force_cancel_approval_V1;
    pd_assets_transfer_approved_V1_t assets_transfer_approved_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
