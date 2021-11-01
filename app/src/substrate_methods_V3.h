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
#include "substrate_types_V3.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V3 0
#define PD_CALL_PARACHAINSYSTEM_V3 1
#define PD_CALL_TIMESTAMP_V3 3
#define PD_CALL_BALANCES_V3 10
#define PD_CALL_AUTHORSHIP_V3 20
#define PD_CALL_COLLATORSELECTION_V3 21
#define PD_CALL_SESSION_V3 22
#define PD_CALL_XCMPQUEUE_V3 30
#define PD_CALL_POLKADOTXCM_V3 31
#define PD_CALL_DMPQUEUE_V3 33
#define PD_CALL_UTILITY_V3 40
#define PD_CALL_MULTISIG_V3 41
#define PD_CALL_PROXY_V3 42
#define PD_CALL_ASSETS_V3 50
#define PD_CALL_UNIQUES_V3 51

#define PD_CALL_UTILITY_BATCH_V3 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V3_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V3 9
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V3_t;

#define PD_CALL_PARACHAINSYSTEM_SET_UPGRADE_BLOCK_V3 0
typedef struct {
    pd_RelayChainBlockNumber_V3_t relay_chain_block;
} pd_parachainsystem_set_upgrade_block_V3_t;

#define PD_CALL_PARACHAINSYSTEM_SET_VALIDATION_DATA_V3 1
typedef struct {
    pd_ParachainInherentData_V3_t data;
} pd_parachainsystem_set_validation_data_V3_t;

#define PD_CALL_PARACHAINSYSTEM_SUDO_SEND_UPWARD_MESSAGE_V3 2
typedef struct {
    pd_UpwardMessage_V3_t message;
} pd_parachainsystem_sudo_send_upward_message_V3_t;

#define PD_CALL_PARACHAINSYSTEM_AUTHORIZE_UPGRADE_V3 3
typedef struct {
    pd_Hash_t code_hash;
} pd_parachainsystem_authorize_upgrade_V3_t;

#define PD_CALL_PARACHAINSYSTEM_ENACT_AUTHORIZED_UPGRADE_V3 4
typedef struct {
    pd_Vecu8_t code;
} pd_parachainsystem_enact_authorized_upgrade_V3_t;

#define PD_CALL_TIMESTAMP_SET_V3 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V3_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V3 4
typedef struct {
    pd_LookupasStaticLookupSource_V3_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V3_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V3 5
typedef struct {
    pd_LookupasStaticLookupSource_V3_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V3_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V3 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V3_t;

#define PD_CALL_COLLATORSELECTION_SET_INVULNERABLES_V3 0
typedef struct {
    pd_VecAccountId_V3_t new_;
} pd_collatorselection_set_invulnerables_V3_t;

#define PD_CALL_COLLATORSELECTION_SET_DESIRED_CANDIDATES_V3 1
typedef struct {
    pd_u32_t max;
} pd_collatorselection_set_desired_candidates_V3_t;

#define PD_CALL_COLLATORSELECTION_SET_CANDIDACY_BOND_V3 2
typedef struct {
    pd_Balance_t bond;
} pd_collatorselection_set_candidacy_bond_V3_t;

#define PD_CALL_COLLATORSELECTION_REGISTER_AS_CANDIDATE_V3 3
typedef struct {
} pd_collatorselection_register_as_candidate_V3_t;

#define PD_CALL_COLLATORSELECTION_LEAVE_INTENT_V3 4
typedef struct {
} pd_collatorselection_leave_intent_V3_t;

#define PD_CALL_SESSION_SET_KEYS_V3 0
typedef struct {
    pd_Keys_V3_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V3_t;

#define PD_CALL_SESSION_PURGE_KEYS_V3 1
typedef struct {
} pd_session_purge_keys_V3_t;

#define PD_CALL_POLKADOTXCM_SEND_V3 0
typedef struct {
    pd_BoxVersionedMultiLocation_V3_t dest;
    pd_BoxVersionedXcmTuple_V3_t message;
} pd_polkadotxcm_send_V3_t;

#define PD_CALL_POLKADOTXCM_TELEPORT_ASSETS_V3 1
typedef struct {
    pd_BoxVersionedMultiLocation_V3_t dest;
    pd_BoxVersionedMultiLocation_V3_t beneficiary;
    pd_BoxVersionedMultiAssets_V3_t assets;
    pd_u32_t fee_asset_item;
} pd_polkadotxcm_teleport_assets_V3_t;

#define PD_CALL_POLKADOTXCM_RESERVE_TRANSFER_ASSETS_V3 2
typedef struct {
    pd_BoxVersionedMultiLocation_V3_t dest;
    pd_BoxVersionedMultiLocation_V3_t beneficiary;
    pd_BoxVersionedMultiAssets_V3_t assets;
    pd_u32_t fee_asset_item;
} pd_polkadotxcm_reserve_transfer_assets_V3_t;

#define PD_CALL_POLKADOTXCM_EXECUTE_V3 3
typedef struct {
    pd_BoxVersionedXcmTasSysConfigCall_V3_t message;
    pd_Weight_V3_t max_weight;
} pd_polkadotxcm_execute_V3_t;

#define PD_CALL_POLKADOTXCM_FORCE_XCM_VERSION_V3 4
typedef struct {
    pd_BoxMultiLocation_V3_t location;
    pd_XcmVersion_V3_t xcm_version;
} pd_polkadotxcm_force_xcm_version_V3_t;

#define PD_CALL_POLKADOTXCM_FORCE_DEFAULT_XCM_VERSION_V3 5
typedef struct {
    pd_OptionXcmVersion_V3_t maybe_xcm_version;
} pd_polkadotxcm_force_default_xcm_version_V3_t;

#define PD_CALL_POLKADOTXCM_FORCE_SUBSCRIBE_VERSION_NOTIFY_V3 6
typedef struct {
    pd_BoxVersionedMultiLocation_V3_t location;
} pd_polkadotxcm_force_subscribe_version_notify_V3_t;

#define PD_CALL_POLKADOTXCM_FORCE_UNSUBSCRIBE_VERSION_NOTIFY_V3 7
typedef struct {
    pd_BoxVersionedMultiLocation_V3_t location;
} pd_polkadotxcm_force_unsubscribe_version_notify_V3_t;

#define PD_CALL_POLKADOTXCM_LIMITED_RESERVE_TRANSFER_ASSETS_V3 8
typedef struct {
    pd_BoxVersionedMultiLocation_V3_t dest;
    pd_BoxVersionedMultiLocation_V3_t beneficiary;
    pd_BoxVersionedMultiAssets_V3_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_V3_t weight_limit;
} pd_polkadotxcm_limited_reserve_transfer_assets_V3_t;

#define PD_CALL_POLKADOTXCM_LIMITED_TELEPORT_ASSETS_V3 9
typedef struct {
    pd_BoxVersionedMultiLocation_V3_t dest;
    pd_BoxVersionedMultiLocation_V3_t beneficiary;
    pd_BoxVersionedMultiAssets_V3_t assets;
    pd_u32_t fee_asset_item;
    pd_WeightLimit_V3_t weight_limit;
} pd_polkadotxcm_limited_teleport_assets_V3_t;

#define PD_CALL_DMPQUEUE_SERVICE_OVERWEIGHT_V3 0
typedef struct {
    pd_OverweightIndex_V3_t index;
    pd_Weight_V3_t weight_limit;
} pd_dmpqueue_service_overweight_V3_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V3 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V3_t;

#define PD_CALL_UTILITY_BATCH_ALL_V3 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V3_t;

#define PD_CALL_PROXY_ADD_PROXY_V3 1
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_ProxyType_V3_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V3_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V3 2
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_ProxyType_V3_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V3_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V3 3
typedef struct {
} pd_proxy_remove_proxies_V3_t;

#define PD_CALL_PROXY_ANONYMOUS_V3 4
typedef struct {
    pd_ProxyType_V3_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V3_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V3 5
typedef struct {
    pd_AccountId_V3_t spawner;
    pd_ProxyType_V3_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V3_t;

#define PD_CALL_PROXY_ANNOUNCE_V3 6
typedef struct {
    pd_AccountId_V3_t real;
    pd_CallHashOfT_V3_t call_hash;
} pd_proxy_announce_V3_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V3 7
typedef struct {
    pd_AccountId_V3_t real;
    pd_CallHashOfT_V3_t call_hash;
} pd_proxy_remove_announcement_V3_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V3 8
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_CallHashOfT_V3_t call_hash;
} pd_proxy_reject_announcement_V3_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V3 9
typedef struct {
    pd_AccountId_V3_t delegate;
    pd_AccountId_V3_t real;
    pd_OptionProxyType_V3_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V3_t;

#define PD_CALL_UNIQUES_CREATE_V3 0
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V3_t admin;
} pd_uniques_create_V3_t;

#define PD_CALL_UNIQUES_FORCE_CREATE_V3 1
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V3_t owner;
    pd_bool_t free_holding;
} pd_uniques_force_create_V3_t;

#define PD_CALL_UNIQUES_DESTROY_V3 2
typedef struct {
    pd_Compactu32_t class_;
    pd_DestroyWitness_V3_t witness;
} pd_uniques_destroy_V3_t;

#define PD_CALL_UNIQUES_MINT_V3 3
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
    pd_LookupasStaticLookupSource_V3_t owner;
} pd_uniques_mint_V3_t;

#define PD_CALL_UNIQUES_BURN_V3 4
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
    pd_OptionLookupasStaticLookupSource_V3_t check_owner;
} pd_uniques_burn_V3_t;

#define PD_CALL_UNIQUES_TRANSFER_V3 5
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
    pd_LookupasStaticLookupSource_V3_t dest;
} pd_uniques_transfer_V3_t;

#define PD_CALL_UNIQUES_REDEPOSIT_V3 6
typedef struct {
    pd_Compactu32_t class_;
    pd_VecInstanceId_V3_t instances;
} pd_uniques_redeposit_V3_t;

#define PD_CALL_UNIQUES_FREEZE_V3 7
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
} pd_uniques_freeze_V3_t;

#define PD_CALL_UNIQUES_THAW_V3 8
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
} pd_uniques_thaw_V3_t;

#define PD_CALL_UNIQUES_FREEZE_CLASS_V3 9
typedef struct {
    pd_Compactu32_t class_;
} pd_uniques_freeze_class_V3_t;

#define PD_CALL_UNIQUES_THAW_CLASS_V3 10
typedef struct {
    pd_Compactu32_t class_;
} pd_uniques_thaw_class_V3_t;

#define PD_CALL_UNIQUES_TRANSFER_OWNERSHIP_V3 11
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V3_t owner;
} pd_uniques_transfer_ownership_V3_t;

#define PD_CALL_UNIQUES_SET_TEAM_V3 12
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V3_t issuer;
    pd_LookupasStaticLookupSource_V3_t admin;
    pd_LookupasStaticLookupSource_V3_t freezer;
} pd_uniques_set_team_V3_t;

#define PD_CALL_UNIQUES_APPROVE_TRANSFER_V3 13
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
    pd_LookupasStaticLookupSource_V3_t delegate;
} pd_uniques_approve_transfer_V3_t;

#define PD_CALL_UNIQUES_CANCEL_APPROVAL_V3 14
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
    pd_OptionLookupasStaticLookupSource_V3_t maybe_check_delegate;
} pd_uniques_cancel_approval_V3_t;

#define PD_CALL_UNIQUES_FORCE_ASSET_STATUS_V3 15
typedef struct {
    pd_Compactu32_t class_;
    pd_LookupasStaticLookupSource_V3_t owner;
    pd_LookupasStaticLookupSource_V3_t issuer;
    pd_LookupasStaticLookupSource_V3_t admin;
    pd_LookupasStaticLookupSource_V3_t freezer;
    pd_bool_t free_holding;
    pd_bool_t is_frozen;
} pd_uniques_force_asset_status_V3_t;

#define PD_CALL_UNIQUES_SET_ATTRIBUTE_V3 16
typedef struct {
    pd_Compactu32_t class_;
    pd_OptionInstanceId_V3_t maybe_instance;
    pd_BoundedVecu8KeyLimit_V3_t key;
    pd_BoundedVecu8ValueLimit_V3_t value;
} pd_uniques_set_attribute_V3_t;

#define PD_CALL_UNIQUES_CLEAR_ATTRIBUTE_V3 17
typedef struct {
    pd_Compactu32_t class_;
    pd_OptionInstanceId_V3_t maybe_instance;
    pd_BoundedVecu8KeyLimit_V3_t key;
} pd_uniques_clear_attribute_V3_t;

#define PD_CALL_UNIQUES_SET_METADATA_V3 18
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
    pd_BoundedVecu8StringLimit_V3_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_metadata_V3_t;

#define PD_CALL_UNIQUES_CLEAR_METADATA_V3 19
typedef struct {
    pd_Compactu32_t class_;
    pd_Compactu32_t instance;
} pd_uniques_clear_metadata_V3_t;

#define PD_CALL_UNIQUES_SET_CLASS_METADATA_V3 20
typedef struct {
    pd_Compactu32_t class_;
    pd_BoundedVecu8StringLimit_V3_t data;
    pd_bool_t is_frozen;
} pd_uniques_set_class_metadata_V3_t;

#define PD_CALL_UNIQUES_CLEAR_CLASS_METADATA_V3 21
typedef struct {
    pd_Compactu32_t class_;
} pd_uniques_clear_class_metadata_V3_t;

#endif

typedef union {
    pd_utility_batch_V3_t utility_batch_V3;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_remark_with_event_V3_t system_remark_with_event_V3;
    pd_parachainsystem_set_upgrade_block_V3_t parachainsystem_set_upgrade_block_V3;
    pd_parachainsystem_set_validation_data_V3_t parachainsystem_set_validation_data_V3;
    pd_parachainsystem_sudo_send_upward_message_V3_t parachainsystem_sudo_send_upward_message_V3;
    pd_parachainsystem_authorize_upgrade_V3_t parachainsystem_authorize_upgrade_V3;
    pd_parachainsystem_enact_authorized_upgrade_V3_t parachainsystem_enact_authorized_upgrade_V3;
    pd_timestamp_set_V3_t timestamp_set_V3;
    pd_balances_transfer_all_V3_t balances_transfer_all_V3;
    pd_balances_force_unreserve_V3_t balances_force_unreserve_V3;
    pd_authorship_set_uncles_V3_t authorship_set_uncles_V3;
    pd_collatorselection_set_invulnerables_V3_t collatorselection_set_invulnerables_V3;
    pd_collatorselection_set_desired_candidates_V3_t collatorselection_set_desired_candidates_V3;
    pd_collatorselection_set_candidacy_bond_V3_t collatorselection_set_candidacy_bond_V3;
    pd_collatorselection_register_as_candidate_V3_t collatorselection_register_as_candidate_V3;
    pd_collatorselection_leave_intent_V3_t collatorselection_leave_intent_V3;
    pd_session_set_keys_V3_t session_set_keys_V3;
    pd_session_purge_keys_V3_t session_purge_keys_V3;
    pd_polkadotxcm_send_V3_t polkadotxcm_send_V3;
    pd_polkadotxcm_teleport_assets_V3_t polkadotxcm_teleport_assets_V3;
    pd_polkadotxcm_reserve_transfer_assets_V3_t polkadotxcm_reserve_transfer_assets_V3;
    pd_polkadotxcm_execute_V3_t polkadotxcm_execute_V3;
    pd_polkadotxcm_force_xcm_version_V3_t polkadotxcm_force_xcm_version_V3;
    pd_polkadotxcm_force_default_xcm_version_V3_t polkadotxcm_force_default_xcm_version_V3;
    pd_polkadotxcm_force_subscribe_version_notify_V3_t polkadotxcm_force_subscribe_version_notify_V3;
    pd_polkadotxcm_force_unsubscribe_version_notify_V3_t polkadotxcm_force_unsubscribe_version_notify_V3;
    pd_polkadotxcm_limited_reserve_transfer_assets_V3_t polkadotxcm_limited_reserve_transfer_assets_V3;
    pd_polkadotxcm_limited_teleport_assets_V3_t polkadotxcm_limited_teleport_assets_V3;
    pd_dmpqueue_service_overweight_V3_t dmpqueue_service_overweight_V3;
    pd_utility_as_derivative_V3_t utility_as_derivative_V3;
    pd_utility_batch_all_V3_t utility_batch_all_V3;
    pd_proxy_add_proxy_V3_t proxy_add_proxy_V3;
    pd_proxy_remove_proxy_V3_t proxy_remove_proxy_V3;
    pd_proxy_remove_proxies_V3_t proxy_remove_proxies_V3;
    pd_proxy_anonymous_V3_t proxy_anonymous_V3;
    pd_proxy_kill_anonymous_V3_t proxy_kill_anonymous_V3;
    pd_proxy_announce_V3_t proxy_announce_V3;
    pd_proxy_remove_announcement_V3_t proxy_remove_announcement_V3;
    pd_proxy_reject_announcement_V3_t proxy_reject_announcement_V3;
    pd_proxy_proxy_announced_V3_t proxy_proxy_announced_V3;
    pd_uniques_create_V3_t uniques_create_V3;
    pd_uniques_force_create_V3_t uniques_force_create_V3;
    pd_uniques_destroy_V3_t uniques_destroy_V3;
    pd_uniques_mint_V3_t uniques_mint_V3;
    pd_uniques_burn_V3_t uniques_burn_V3;
    pd_uniques_transfer_V3_t uniques_transfer_V3;
    pd_uniques_redeposit_V3_t uniques_redeposit_V3;
    pd_uniques_freeze_V3_t uniques_freeze_V3;
    pd_uniques_thaw_V3_t uniques_thaw_V3;
    pd_uniques_freeze_class_V3_t uniques_freeze_class_V3;
    pd_uniques_thaw_class_V3_t uniques_thaw_class_V3;
    pd_uniques_transfer_ownership_V3_t uniques_transfer_ownership_V3;
    pd_uniques_set_team_V3_t uniques_set_team_V3;
    pd_uniques_approve_transfer_V3_t uniques_approve_transfer_V3;
    pd_uniques_cancel_approval_V3_t uniques_cancel_approval_V3;
    pd_uniques_force_asset_status_V3_t uniques_force_asset_status_V3;
    pd_uniques_set_attribute_V3_t uniques_set_attribute_V3;
    pd_uniques_clear_attribute_V3_t uniques_clear_attribute_V3;
    pd_uniques_set_metadata_V3_t uniques_set_metadata_V3;
    pd_uniques_clear_metadata_V3_t uniques_clear_metadata_V3;
    pd_uniques_set_class_metadata_V3_t uniques_set_class_metadata_V3;
    pd_uniques_clear_class_metadata_V3_t uniques_clear_class_metadata_V3;
#endif
} pd_MethodBasic_V3_t;

#define PD_CALL_BALANCES_TRANSFER_V3 0
typedef struct {
    pd_LookupasStaticLookupSource_V3_t dest;
    pd_CompactBalance_t Amount;
} pd_balances_transfer_V3_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V3 0
typedef struct {
    pd_Perbill_V3_t ratio;
} pd_system_fill_block_V3_t;

#define PD_CALL_SYSTEM_REMARK_V3 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V3_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V3 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V3_t;

#define PD_CALL_SYSTEM_SET_CODE_V3 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V3_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V3 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V3_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V3 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V3_t changes_trie_config;
} pd_system_set_changes_trie_config_V3_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V3 6
typedef struct {
    pd_VecKeyValue_V3_t items;
} pd_system_set_storage_V3_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V3 7
typedef struct {
    pd_VecKey_V3_t keys;
} pd_system_kill_storage_V3_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V3 8
typedef struct {
    pd_Key_V3_t prefix;
    pd_u32_t subkeys;
} pd_system_kill_prefix_V3_t;

#define PD_CALL_BALANCES_SET_BALANCE_V3 1
typedef struct {
    pd_LookupasStaticLookupSource_V3_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V3_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V3 2
typedef struct {
    pd_LookupasStaticLookupSource_V3_t source;
    pd_LookupasStaticLookupSource_V3_t dest;
    pd_CompactBalance_t Amount;
} pd_balances_force_transfer_V3_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V3 3
typedef struct {
    pd_LookupasStaticLookupSource_V3_t dest;
    pd_CompactBalance_t Amount;
} pd_balances_transfer_keep_alive_V3_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V3 0
typedef struct {
    pd_VecAccountId_V3_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V3_t;

#define PD_CALL_MULTISIG_AS_MULTI_V3 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V3_t other_signatories;
    pd_OptionTimepoint_V3_t maybe_timepoint;
    pd_OpaqueCall_V3_t call;
    pd_bool_t store_call;
    pd_Weight_V3_t max_weight;
} pd_multisig_as_multi_V3_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V3 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V3_t other_signatories;
    pd_OptionTimepoint_V3_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V3_t max_weight;
} pd_multisig_approve_as_multi_V3_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V3 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V3_t other_signatories;
    pd_Timepoint_V3_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V3_t;

#define PD_CALL_PROXY_PROXY_V3 0
typedef struct {
    pd_AccountId_V3_t real;
    pd_OptionProxyType_V3_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V3_t;

#define PD_CALL_ASSETS_CREATE_V3 0
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t admin;
    pd_Balance_t min_balance;
} pd_assets_create_V3_t;

#define PD_CALL_ASSETS_FORCE_CREATE_V3 1
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t owner;
    pd_bool_t is_sufficient;
    pd_CompactBalance_t min_balance;
} pd_assets_force_create_V3_t;

#define PD_CALL_ASSETS_DESTROY_V3 2
typedef struct {
    pd_Compactu32_t id;
    pd_DestroyWitness_V3_t witness;
} pd_assets_destroy_V3_t;

#define PD_CALL_ASSETS_MINT_V3 3
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t beneficiary;
    pd_CompactBalance_t amount;
} pd_assets_mint_V3_t;

#define PD_CALL_ASSETS_BURN_V3 4
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t who;
    pd_CompactBalance_t amount;
} pd_assets_burn_V3_t;

#define PD_CALL_ASSETS_TRANSFER_V3 5
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_V3_t;

#define PD_CALL_ASSETS_TRANSFER_KEEP_ALIVE_V3 6
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t target;
    pd_CompactBalance_t amount;
} pd_assets_transfer_keep_alive_V3_t;

#define PD_CALL_ASSETS_FORCE_TRANSFER_V3 7
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t source;
    pd_LookupasStaticLookupSource_V3_t dest;
    pd_CompactBalance_t amount;
} pd_assets_force_transfer_V3_t;

#define PD_CALL_ASSETS_FREEZE_V3 8
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t who;
} pd_assets_freeze_V3_t;

#define PD_CALL_ASSETS_THAW_V3 9
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t who;
} pd_assets_thaw_V3_t;

#define PD_CALL_ASSETS_FREEZE_ASSET_V3 10
typedef struct {
    pd_Compactu32_t id;
} pd_assets_freeze_asset_V3_t;

#define PD_CALL_ASSETS_THAW_ASSET_V3 11
typedef struct {
    pd_Compactu32_t id;
} pd_assets_thaw_asset_V3_t;

#define PD_CALL_ASSETS_TRANSFER_OWNERSHIP_V3 12
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t owner;
} pd_assets_transfer_ownership_V3_t;

#define PD_CALL_ASSETS_SET_TEAM_V3 13
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t issuer;
    pd_LookupasStaticLookupSource_V3_t admin;
    pd_LookupasStaticLookupSource_V3_t freezer;
} pd_assets_set_team_V3_t;

#define PD_CALL_ASSETS_SET_METADATA_V3 14
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
} pd_assets_set_metadata_V3_t;

#define PD_CALL_ASSETS_CLEAR_METADATA_V3 15
typedef struct {
    pd_Compactu32_t id;
} pd_assets_clear_metadata_V3_t;

#define PD_CALL_ASSETS_FORCE_SET_METADATA_V3 16
typedef struct {
    pd_Compactu32_t id;
    pd_Vecu8_t name;
    pd_Vecu8_t symbol;
    pd_u8_t decimals;
    pd_bool_t is_frozen;
} pd_assets_force_set_metadata_V3_t;

#define PD_CALL_ASSETS_FORCE_CLEAR_METADATA_V3 17
typedef struct {
    pd_Compactu32_t id;
} pd_assets_force_clear_metadata_V3_t;

#define PD_CALL_ASSETS_FORCE_ASSET_STATUS_V3 18
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t owner;
    pd_LookupasStaticLookupSource_V3_t issuer;
    pd_LookupasStaticLookupSource_V3_t admin;
    pd_LookupasStaticLookupSource_V3_t freezer;
    pd_CompactBalance_t min_balance;
    pd_bool_t is_sufficient;
    pd_bool_t is_frozen;
} pd_assets_force_asset_status_V3_t;

#define PD_CALL_ASSETS_APPROVE_TRANSFER_V3 19
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t delegate;
    pd_CompactBalance_t amount;
} pd_assets_approve_transfer_V3_t;

#define PD_CALL_ASSETS_CANCEL_APPROVAL_V3 20
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t delegate;
} pd_assets_cancel_approval_V3_t;

#define PD_CALL_ASSETS_FORCE_CANCEL_APPROVAL_V3 21
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t owner;
    pd_LookupasStaticLookupSource_V3_t delegate;
} pd_assets_force_cancel_approval_V3_t;

#define PD_CALL_ASSETS_TRANSFER_APPROVED_V3 22
typedef struct {
    pd_Compactu32_t id;
    pd_LookupasStaticLookupSource_V3_t owner;
    pd_LookupasStaticLookupSource_V3_t destination;
    pd_CompactBalance_t amount;
} pd_assets_transfer_approved_V3_t;

#endif

typedef union {
    pd_balances_transfer_V3_t balances_transfer_V3;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V3_t system_fill_block_V3;
    pd_system_remark_V3_t system_remark_V3;
    pd_system_set_heap_pages_V3_t system_set_heap_pages_V3;
    pd_system_set_code_V3_t system_set_code_V3;
    pd_system_set_code_without_checks_V3_t system_set_code_without_checks_V3;
    pd_system_set_changes_trie_config_V3_t system_set_changes_trie_config_V3;
    pd_system_set_storage_V3_t system_set_storage_V3;
    pd_system_kill_storage_V3_t system_kill_storage_V3;
    pd_system_kill_prefix_V3_t system_kill_prefix_V3;
    pd_balances_set_balance_V3_t balances_set_balance_V3;
    pd_balances_force_transfer_V3_t balances_force_transfer_V3;
    pd_balances_transfer_keep_alive_V3_t balances_transfer_keep_alive_V3;
    pd_multisig_as_multi_threshold_1_V3_t multisig_as_multi_threshold_1_V3;
    pd_multisig_as_multi_V3_t multisig_as_multi_V3;
    pd_multisig_approve_as_multi_V3_t multisig_approve_as_multi_V3;
    pd_multisig_cancel_as_multi_V3_t multisig_cancel_as_multi_V3;
    pd_proxy_proxy_V3_t proxy_proxy_V3;
    pd_assets_create_V3_t assets_create_V3;
    pd_assets_force_create_V3_t assets_force_create_V3;
    pd_assets_destroy_V3_t assets_destroy_V3;
    pd_assets_mint_V3_t assets_mint_V3;
    pd_assets_burn_V3_t assets_burn_V3;
    pd_assets_transfer_V3_t assets_transfer_V3;
    pd_assets_transfer_keep_alive_V3_t assets_transfer_keep_alive_V3;
    pd_assets_force_transfer_V3_t assets_force_transfer_V3;
    pd_assets_freeze_V3_t assets_freeze_V3;
    pd_assets_thaw_V3_t assets_thaw_V3;
    pd_assets_freeze_asset_V3_t assets_freeze_asset_V3;
    pd_assets_thaw_asset_V3_t assets_thaw_asset_V3;
    pd_assets_transfer_ownership_V3_t assets_transfer_ownership_V3;
    pd_assets_set_team_V3_t assets_set_team_V3;
    pd_assets_set_metadata_V3_t assets_set_metadata_V3;
    pd_assets_clear_metadata_V3_t assets_clear_metadata_V3;
    pd_assets_force_set_metadata_V3_t assets_force_set_metadata_V3;
    pd_assets_force_clear_metadata_V3_t assets_force_clear_metadata_V3;
    pd_assets_force_asset_status_V3_t assets_force_asset_status_V3;
    pd_assets_approve_transfer_V3_t assets_approve_transfer_V3;
    pd_assets_cancel_approval_V3_t assets_cancel_approval_V3;
    pd_assets_force_cancel_approval_V3_t assets_force_cancel_approval_V3;
    pd_assets_transfer_approved_V3_t assets_transfer_approved_V3;
#endif
} pd_MethodNested_V3_t;

typedef union {
    pd_MethodBasic_V3_t basic;
    pd_MethodNested_V3_t nested;
} pd_Method_V3_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
