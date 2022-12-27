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

#include "substrate_dispatch_V11.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_V11(
    parser_context_t* c, pd_balances_transfer_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V11(
    parser_context_t* c, pd_balances_force_transfer_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V11(
    parser_context_t* c, pd_balances_transfer_keep_alive_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V11(
    parser_context_t* c, pd_balances_transfer_all_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V11(
    parser_context_t* c, pd_session_set_keys_V11_t* m)
{
    CHECK_ERROR(_readKeys_V11(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V11(
    parser_context_t* c, pd_session_purge_keys_V11_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V11(
    parser_context_t* c, pd_utility_batch_V11_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V11(
    parser_context_t* c, pd_utility_batch_all_V11_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
__Z_INLINE parser_error_t _readMethod_polkadotxcm_reserve_transfer_assets_V11(
    parser_context_t* c, pd_polkadotxcm_reserve_transfer_assets_V11_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation_V11(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation_V11(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets_V11(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_polkadotxcm_limited_reserve_transfer_assets_V11(
    parser_context_t* c, pd_polkadotxcm_limited_reserve_transfer_assets_V11_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation_V11(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation_V11(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets_V11(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeightLimit_V11(c, &m->weight_limit))
    return parser_ok;
}
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V11(
    parser_context_t* c, pd_system_remark_V11_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V11(
    parser_context_t* c, pd_system_set_heap_pages_V11_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V11(
    parser_context_t* c, pd_system_set_code_V11_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V11(
    parser_context_t* c, pd_system_set_code_without_checks_V11_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V11(
    parser_context_t* c, pd_system_remark_with_event_V11_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V11(
    parser_context_t* c, pd_timestamp_set_V11_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V11(
    parser_context_t* c, pd_balances_set_balance_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V11(
    parser_context_t* c, pd_balances_force_unreserve_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_invulnerables_V11(
    parser_context_t* c, pd_collatorselection_set_invulnerables_V11_t* m)
{
    CHECK_ERROR(_readVecAccountId_V11(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_desired_candidates_V11(
    parser_context_t* c, pd_collatorselection_set_desired_candidates_V11_t* m)
{
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_candidacy_bond_V11(
    parser_context_t* c, pd_collatorselection_set_candidacy_bond_V11_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->bond))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_register_as_candidate_V11(
    parser_context_t* c, pd_collatorselection_register_as_candidate_V11_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_leave_intent_V11(
    parser_context_t* c, pd_collatorselection_leave_intent_V11_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_service_overweight_V11(
    parser_context_t* c, pd_xcmpqueue_service_overweight_V11_t* m)
{
    CHECK_ERROR(_readOverweightIndex_V11(c, &m->index))
    CHECK_ERROR(_readXcmWeight_V11(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_suspend_xcm_execution_V11(
    parser_context_t* c, pd_xcmpqueue_suspend_xcm_execution_V11_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_resume_xcm_execution_V11(
    parser_context_t* c, pd_xcmpqueue_resume_xcm_execution_V11_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_suspend_threshold_V11(
    parser_context_t* c, pd_xcmpqueue_update_suspend_threshold_V11_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_drop_threshold_V11(
    parser_context_t* c, pd_xcmpqueue_update_drop_threshold_V11_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_resume_threshold_V11(
    parser_context_t* c, pd_xcmpqueue_update_resume_threshold_V11_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_threshold_weight_V11(
    parser_context_t* c, pd_xcmpqueue_update_threshold_weight_V11_t* m)
{
    CHECK_ERROR(_readXcmWeight_V11(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_weight_restrict_decay_V11(
    parser_context_t* c, pd_xcmpqueue_update_weight_restrict_decay_V11_t* m)
{
    CHECK_ERROR(_readXcmWeight_V11(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_xcmp_max_individual_weight_V11(
    parser_context_t* c, pd_xcmpqueue_update_xcmp_max_individual_weight_V11_t* m)
{
    CHECK_ERROR(_readXcmWeight_V11(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dmpqueue_service_overweight_V11(
    parser_context_t* c, pd_dmpqueue_service_overweight_V11_t* m)
{
    CHECK_ERROR(_readOverweightIndex_V11(c, &m->index))
    CHECK_ERROR(_readXcmWeight_V11(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V11(
    parser_context_t* c, pd_utility_force_batch_V11_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V11(
    parser_context_t* c, pd_utility_with_weight_V11_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight_V11(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V11(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V11_t* m)
{
    CHECK_ERROR(_readVecAccountId_V11(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V11(
    parser_context_t* c, pd_multisig_as_multi_V11_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V11(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V11(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight_V11(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V11(
    parser_context_t* c, pd_multisig_approve_as_multi_V11_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V11(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V11(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V11(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V11(
    parser_context_t* c, pd_multisig_cancel_as_multi_V11_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V11(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V11(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V11(
    parser_context_t* c, pd_proxy_proxy_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V11(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V11(
    parser_context_t* c, pd_proxy_add_proxy_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V11(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V11(
    parser_context_t* c, pd_proxy_remove_proxy_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V11(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V11(
    parser_context_t* c, pd_proxy_remove_proxies_V11_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_create_pure_V11(
    parser_context_t* c, pd_proxy_create_pure_V11_t* m)
{
    CHECK_ERROR(_readProxyType_V11(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_pure_V11(
    parser_context_t* c, pd_proxy_kill_pure_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V11(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V11(
    parser_context_t* c, pd_proxy_announce_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V11(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V11(
    parser_context_t* c, pd_proxy_remove_announcement_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->real))
    CHECK_ERROR(_readCallHashOf_V11(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V11(
    parser_context_t* c, pd_proxy_reject_announcement_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf_V11(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V11(
    parser_context_t* c, pd_proxy_proxy_announced_V11_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->delegate))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V11(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_create_V11(
    parser_context_t* c, pd_assets_create_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->admin))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_create_V11(
    parser_context_t* c, pd_assets_force_create_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_start_destroy_V11(
    parser_context_t* c, pd_assets_start_destroy_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_destroy_accounts_V11(
    parser_context_t* c, pd_assets_destroy_accounts_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_destroy_approvals_V11(
    parser_context_t* c, pd_assets_destroy_approvals_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_finish_destroy_V11(
    parser_context_t* c, pd_assets_finish_destroy_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_mint_V11(
    parser_context_t* c, pd_assets_mint_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->beneficiary))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_burn_V11(
    parser_context_t* c, pd_assets_burn_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_V11(
    parser_context_t* c, pd_assets_transfer_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_keep_alive_V11(
    parser_context_t* c, pd_assets_transfer_keep_alive_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_transfer_V11(
    parser_context_t* c, pd_assets_force_transfer_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_V11(
    parser_context_t* c, pd_assets_freeze_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_V11(
    parser_context_t* c, pd_assets_thaw_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_asset_V11(
    parser_context_t* c, pd_assets_freeze_asset_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_asset_V11(
    parser_context_t* c, pd_assets_thaw_asset_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_ownership_V11(
    parser_context_t* c, pd_assets_transfer_ownership_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_team_V11(
    parser_context_t* c, pd_assets_set_team_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_metadata_V11(
    parser_context_t* c, pd_assets_set_metadata_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_clear_metadata_V11(
    parser_context_t* c, pd_assets_clear_metadata_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_set_metadata_V11(
    parser_context_t* c, pd_assets_force_set_metadata_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_clear_metadata_V11(
    parser_context_t* c, pd_assets_force_clear_metadata_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_asset_status_V11(
    parser_context_t* c, pd_assets_force_asset_status_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->freezer))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_approve_transfer_V11(
    parser_context_t* c, pd_assets_approve_transfer_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->delegate))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_cancel_approval_V11(
    parser_context_t* c, pd_assets_cancel_approval_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_cancel_approval_V11(
    parser_context_t* c, pd_assets_force_cancel_approval_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_approved_V11(
    parser_context_t* c, pd_assets_transfer_approved_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->destination))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_touch_V11(
    parser_context_t* c, pd_assets_touch_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_refund_V11(
    parser_context_t* c, pd_assets_refund_V11_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->allow_burn))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_create_V11(
    parser_context_t* c, pd_uniques_create_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_force_create_V11(
    parser_context_t* c, pd_uniques_force_create_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->free_holding))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_destroy_V11(
    parser_context_t* c, pd_uniques_destroy_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readDestroyWitness_V11(c, &m->witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_mint_V11(
    parser_context_t* c, pd_uniques_mint_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_burn_V11(
    parser_context_t* c, pd_uniques_burn_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    CHECK_ERROR(_readOptionAccountIdLookupOfT_V11(c, &m->check_owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_transfer_V11(
    parser_context_t* c, pd_uniques_transfer_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_redeposit_V11(
    parser_context_t* c, pd_uniques_redeposit_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readVecItemId_V11(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_freeze_V11(
    parser_context_t* c, pd_uniques_freeze_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_thaw_V11(
    parser_context_t* c, pd_uniques_thaw_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_freeze_collection_V11(
    parser_context_t* c, pd_uniques_freeze_collection_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_thaw_collection_V11(
    parser_context_t* c, pd_uniques_thaw_collection_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_transfer_ownership_V11(
    parser_context_t* c, pd_uniques_transfer_ownership_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_team_V11(
    parser_context_t* c, pd_uniques_set_team_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_approve_transfer_V11(
    parser_context_t* c, pd_uniques_approve_transfer_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_cancel_approval_V11(
    parser_context_t* c, pd_uniques_cancel_approval_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    CHECK_ERROR(_readOptionAccountIdLookupOfT_V11(c, &m->maybe_check_delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_force_item_status_V11(
    parser_context_t* c, pd_uniques_force_item_status_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT_V11(c, &m->freezer))
    CHECK_ERROR(_readbool(c, &m->free_holding))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_attribute_V11(
    parser_context_t* c, pd_uniques_set_attribute_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readOptionItemId_V11(c, &m->maybe_item))
    CHECK_ERROR(_readBoundedVecu8_V11(c, &m->key))
    CHECK_ERROR(_readBoundedVecu8_V11(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_attribute_V11(
    parser_context_t* c, pd_uniques_clear_attribute_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readOptionItemId_V11(c, &m->maybe_item))
    CHECK_ERROR(_readBoundedVecu8_V11(c, &m->key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_metadata_V11(
    parser_context_t* c, pd_uniques_set_metadata_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    CHECK_ERROR(_readBoundedVecu8_V11(c, &m->data))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_metadata_V11(
    parser_context_t* c, pd_uniques_clear_metadata_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_collection_metadata_V11(
    parser_context_t* c, pd_uniques_set_collection_metadata_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readBoundedVecu8_V11(c, &m->data))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_collection_metadata_V11(
    parser_context_t* c, pd_uniques_clear_collection_metadata_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_accept_ownership_V11(
    parser_context_t* c, pd_uniques_set_accept_ownership_V11_t* m)
{
    CHECK_ERROR(_readOptionCollectionId_V11(c, &m->maybe_collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_collection_max_supply_V11(
    parser_context_t* c, pd_uniques_set_collection_max_supply_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readu32(c, &m->max_supply))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_price_V11(
    parser_context_t* c, pd_uniques_set_price_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    CHECK_ERROR(_readOptionItemPrice_V11(c, &m->price))
    CHECK_ERROR(_readOptionAccountIdLookupOfT_V11(c, &m->whitelisted_buyer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_buy_item_V11(
    parser_context_t* c, pd_uniques_buy_item_V11_t* m)
{
    CHECK_ERROR(_readCollectionId_V11(c, &m->collection))
    CHECK_ERROR(_readItemId_V11(c, &m->item))
    CHECK_ERROR(_readItemPrice_V11(c, &m->bid_price))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V11(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V11_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V11(c, &method->nested.balances_transfer_V11))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V11(c, &method->nested.balances_force_transfer_V11))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V11(c, &method->nested.balances_transfer_keep_alive_V11))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V11(c, &method->basic.balances_transfer_all_V11))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V11(c, &method->basic.session_set_keys_V11))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V11(c, &method->basic.session_purge_keys_V11))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V11(c, &method->basic.utility_batch_V11))
        break;
    case 10242: /* module 40 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V11(c, &method->basic.utility_batch_all_V11))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_polkadotxcm_reserve_transfer_assets_V11(c, &method->basic.polkadotxcm_reserve_transfer_assets_V11))
        break;
    case 7944: /* module 31 call 8 */
        CHECK_ERROR(_readMethod_polkadotxcm_limited_reserve_transfer_assets_V11(c, &method->basic.polkadotxcm_limited_reserve_transfer_assets_V11))
        break;
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V11(c, &method->nested.system_remark_V11))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V11(c, &method->nested.system_set_heap_pages_V11))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_code_V11(c, &method->nested.system_set_code_V11))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V11(c, &method->nested.system_set_code_without_checks_V11))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V11(c, &method->nested.system_remark_with_event_V11))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V11(c, &method->basic.timestamp_set_V11))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V11(c, &method->nested.balances_set_balance_V11))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V11(c, &method->basic.balances_force_unreserve_V11))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_collatorselection_set_invulnerables_V11(c, &method->basic.collatorselection_set_invulnerables_V11))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_collatorselection_set_desired_candidates_V11(c, &method->basic.collatorselection_set_desired_candidates_V11))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_collatorselection_set_candidacy_bond_V11(c, &method->basic.collatorselection_set_candidacy_bond_V11))
        break;
    case 5379: /* module 21 call 3 */
        CHECK_ERROR(_readMethod_collatorselection_register_as_candidate_V11(c, &method->basic.collatorselection_register_as_candidate_V11))
        break;
    case 5380: /* module 21 call 4 */
        CHECK_ERROR(_readMethod_collatorselection_leave_intent_V11(c, &method->basic.collatorselection_leave_intent_V11))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_xcmpqueue_service_overweight_V11(c, &method->basic.xcmpqueue_service_overweight_V11))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_xcmpqueue_suspend_xcm_execution_V11(c, &method->basic.xcmpqueue_suspend_xcm_execution_V11))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_xcmpqueue_resume_xcm_execution_V11(c, &method->basic.xcmpqueue_resume_xcm_execution_V11))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_suspend_threshold_V11(c, &method->basic.xcmpqueue_update_suspend_threshold_V11))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_drop_threshold_V11(c, &method->basic.xcmpqueue_update_drop_threshold_V11))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_resume_threshold_V11(c, &method->basic.xcmpqueue_update_resume_threshold_V11))
        break;
    case 7686: /* module 30 call 6 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_threshold_weight_V11(c, &method->basic.xcmpqueue_update_threshold_weight_V11))
        break;
    case 7687: /* module 30 call 7 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_weight_restrict_decay_V11(c, &method->basic.xcmpqueue_update_weight_restrict_decay_V11))
        break;
    case 7688: /* module 30 call 8 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_xcmp_max_individual_weight_V11(c, &method->basic.xcmpqueue_update_xcmp_max_individual_weight_V11))
        break;
    case 8448: /* module 33 call 0 */
        CHECK_ERROR(_readMethod_dmpqueue_service_overweight_V11(c, &method->basic.dmpqueue_service_overweight_V11))
        break;
    case 10244: /* module 40 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V11(c, &method->basic.utility_force_batch_V11))
        break;
    case 10245: /* module 40 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V11(c, &method->basic.utility_with_weight_V11))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V11(c, &method->nested.multisig_as_multi_threshold_1_V11))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V11(c, &method->nested.multisig_as_multi_V11))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V11(c, &method->nested.multisig_approve_as_multi_V11))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V11(c, &method->nested.multisig_cancel_as_multi_V11))
        break;
    case 10752: /* module 42 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V11(c, &method->nested.proxy_proxy_V11))
        break;
    case 10753: /* module 42 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V11(c, &method->basic.proxy_add_proxy_V11))
        break;
    case 10754: /* module 42 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V11(c, &method->basic.proxy_remove_proxy_V11))
        break;
    case 10755: /* module 42 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V11(c, &method->basic.proxy_remove_proxies_V11))
        break;
    case 10756: /* module 42 call 4 */
        CHECK_ERROR(_readMethod_proxy_create_pure_V11(c, &method->basic.proxy_create_pure_V11))
        break;
    case 10757: /* module 42 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_pure_V11(c, &method->basic.proxy_kill_pure_V11))
        break;
    case 10758: /* module 42 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V11(c, &method->basic.proxy_announce_V11))
        break;
    case 10759: /* module 42 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V11(c, &method->basic.proxy_remove_announcement_V11))
        break;
    case 10760: /* module 42 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V11(c, &method->basic.proxy_reject_announcement_V11))
        break;
    case 10761: /* module 42 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V11(c, &method->basic.proxy_proxy_announced_V11))
        break;
    case 12800: /* module 50 call 0 */
        CHECK_ERROR(_readMethod_assets_create_V11(c, &method->nested.assets_create_V11))
        break;
    case 12801: /* module 50 call 1 */
        CHECK_ERROR(_readMethod_assets_force_create_V11(c, &method->nested.assets_force_create_V11))
        break;
    case 12802: /* module 50 call 2 */
        CHECK_ERROR(_readMethod_assets_start_destroy_V11(c, &method->basic.assets_start_destroy_V11))
        break;
    case 12803: /* module 50 call 3 */
        CHECK_ERROR(_readMethod_assets_destroy_accounts_V11(c, &method->basic.assets_destroy_accounts_V11))
        break;
    case 12804: /* module 50 call 4 */
        CHECK_ERROR(_readMethod_assets_destroy_approvals_V11(c, &method->basic.assets_destroy_approvals_V11))
        break;
    case 12805: /* module 50 call 5 */
        CHECK_ERROR(_readMethod_assets_finish_destroy_V11(c, &method->basic.assets_finish_destroy_V11))
        break;
    case 12806: /* module 50 call 6 */
        CHECK_ERROR(_readMethod_assets_mint_V11(c, &method->nested.assets_mint_V11))
        break;
    case 12807: /* module 50 call 7 */
        CHECK_ERROR(_readMethod_assets_burn_V11(c, &method->nested.assets_burn_V11))
        break;
    case 12808: /* module 50 call 8 */
        CHECK_ERROR(_readMethod_assets_transfer_V11(c, &method->nested.assets_transfer_V11))
        break;
    case 12809: /* module 50 call 9 */
        CHECK_ERROR(_readMethod_assets_transfer_keep_alive_V11(c, &method->nested.assets_transfer_keep_alive_V11))
        break;
    case 12810: /* module 50 call 10 */
        CHECK_ERROR(_readMethod_assets_force_transfer_V11(c, &method->nested.assets_force_transfer_V11))
        break;
    case 12811: /* module 50 call 11 */
        CHECK_ERROR(_readMethod_assets_freeze_V11(c, &method->nested.assets_freeze_V11))
        break;
    case 12812: /* module 50 call 12 */
        CHECK_ERROR(_readMethod_assets_thaw_V11(c, &method->nested.assets_thaw_V11))
        break;
    case 12813: /* module 50 call 13 */
        CHECK_ERROR(_readMethod_assets_freeze_asset_V11(c, &method->nested.assets_freeze_asset_V11))
        break;
    case 12814: /* module 50 call 14 */
        CHECK_ERROR(_readMethod_assets_thaw_asset_V11(c, &method->nested.assets_thaw_asset_V11))
        break;
    case 12815: /* module 50 call 15 */
        CHECK_ERROR(_readMethod_assets_transfer_ownership_V11(c, &method->nested.assets_transfer_ownership_V11))
        break;
    case 12816: /* module 50 call 16 */
        CHECK_ERROR(_readMethod_assets_set_team_V11(c, &method->nested.assets_set_team_V11))
        break;
    case 12817: /* module 50 call 17 */
        CHECK_ERROR(_readMethod_assets_set_metadata_V11(c, &method->nested.assets_set_metadata_V11))
        break;
    case 12818: /* module 50 call 18 */
        CHECK_ERROR(_readMethod_assets_clear_metadata_V11(c, &method->nested.assets_clear_metadata_V11))
        break;
    case 12819: /* module 50 call 19 */
        CHECK_ERROR(_readMethod_assets_force_set_metadata_V11(c, &method->nested.assets_force_set_metadata_V11))
        break;
    case 12820: /* module 50 call 20 */
        CHECK_ERROR(_readMethod_assets_force_clear_metadata_V11(c, &method->nested.assets_force_clear_metadata_V11))
        break;
    case 12821: /* module 50 call 21 */
        CHECK_ERROR(_readMethod_assets_force_asset_status_V11(c, &method->nested.assets_force_asset_status_V11))
        break;
    case 12822: /* module 50 call 22 */
        CHECK_ERROR(_readMethod_assets_approve_transfer_V11(c, &method->nested.assets_approve_transfer_V11))
        break;
    case 12823: /* module 50 call 23 */
        CHECK_ERROR(_readMethod_assets_cancel_approval_V11(c, &method->nested.assets_cancel_approval_V11))
        break;
    case 12824: /* module 50 call 24 */
        CHECK_ERROR(_readMethod_assets_force_cancel_approval_V11(c, &method->nested.assets_force_cancel_approval_V11))
        break;
    case 12825: /* module 50 call 25 */
        CHECK_ERROR(_readMethod_assets_transfer_approved_V11(c, &method->nested.assets_transfer_approved_V11))
        break;
    case 12826: /* module 50 call 26 */
        CHECK_ERROR(_readMethod_assets_touch_V11(c, &method->basic.assets_touch_V11))
        break;
    case 12827: /* module 50 call 27 */
        CHECK_ERROR(_readMethod_assets_refund_V11(c, &method->basic.assets_refund_V11))
        break;
    case 13056: /* module 51 call 0 */
        CHECK_ERROR(_readMethod_uniques_create_V11(c, &method->basic.uniques_create_V11))
        break;
    case 13057: /* module 51 call 1 */
        CHECK_ERROR(_readMethod_uniques_force_create_V11(c, &method->basic.uniques_force_create_V11))
        break;
    case 13058: /* module 51 call 2 */
        CHECK_ERROR(_readMethod_uniques_destroy_V11(c, &method->basic.uniques_destroy_V11))
        break;
    case 13059: /* module 51 call 3 */
        CHECK_ERROR(_readMethod_uniques_mint_V11(c, &method->basic.uniques_mint_V11))
        break;
    case 13060: /* module 51 call 4 */
        CHECK_ERROR(_readMethod_uniques_burn_V11(c, &method->basic.uniques_burn_V11))
        break;
    case 13061: /* module 51 call 5 */
        CHECK_ERROR(_readMethod_uniques_transfer_V11(c, &method->basic.uniques_transfer_V11))
        break;
    case 13062: /* module 51 call 6 */
        CHECK_ERROR(_readMethod_uniques_redeposit_V11(c, &method->basic.uniques_redeposit_V11))
        break;
    case 13063: /* module 51 call 7 */
        CHECK_ERROR(_readMethod_uniques_freeze_V11(c, &method->basic.uniques_freeze_V11))
        break;
    case 13064: /* module 51 call 8 */
        CHECK_ERROR(_readMethod_uniques_thaw_V11(c, &method->basic.uniques_thaw_V11))
        break;
    case 13065: /* module 51 call 9 */
        CHECK_ERROR(_readMethod_uniques_freeze_collection_V11(c, &method->basic.uniques_freeze_collection_V11))
        break;
    case 13066: /* module 51 call 10 */
        CHECK_ERROR(_readMethod_uniques_thaw_collection_V11(c, &method->basic.uniques_thaw_collection_V11))
        break;
    case 13067: /* module 51 call 11 */
        CHECK_ERROR(_readMethod_uniques_transfer_ownership_V11(c, &method->basic.uniques_transfer_ownership_V11))
        break;
    case 13068: /* module 51 call 12 */
        CHECK_ERROR(_readMethod_uniques_set_team_V11(c, &method->basic.uniques_set_team_V11))
        break;
    case 13069: /* module 51 call 13 */
        CHECK_ERROR(_readMethod_uniques_approve_transfer_V11(c, &method->basic.uniques_approve_transfer_V11))
        break;
    case 13070: /* module 51 call 14 */
        CHECK_ERROR(_readMethod_uniques_cancel_approval_V11(c, &method->basic.uniques_cancel_approval_V11))
        break;
    case 13071: /* module 51 call 15 */
        CHECK_ERROR(_readMethod_uniques_force_item_status_V11(c, &method->basic.uniques_force_item_status_V11))
        break;
    case 13072: /* module 51 call 16 */
        CHECK_ERROR(_readMethod_uniques_set_attribute_V11(c, &method->basic.uniques_set_attribute_V11))
        break;
    case 13073: /* module 51 call 17 */
        CHECK_ERROR(_readMethod_uniques_clear_attribute_V11(c, &method->basic.uniques_clear_attribute_V11))
        break;
    case 13074: /* module 51 call 18 */
        CHECK_ERROR(_readMethod_uniques_set_metadata_V11(c, &method->basic.uniques_set_metadata_V11))
        break;
    case 13075: /* module 51 call 19 */
        CHECK_ERROR(_readMethod_uniques_clear_metadata_V11(c, &method->basic.uniques_clear_metadata_V11))
        break;
    case 13076: /* module 51 call 20 */
        CHECK_ERROR(_readMethod_uniques_set_collection_metadata_V11(c, &method->basic.uniques_set_collection_metadata_V11))
        break;
    case 13077: /* module 51 call 21 */
        CHECK_ERROR(_readMethod_uniques_clear_collection_metadata_V11(c, &method->basic.uniques_clear_collection_metadata_V11))
        break;
    case 13078: /* module 51 call 22 */
        CHECK_ERROR(_readMethod_uniques_set_accept_ownership_V11(c, &method->basic.uniques_set_accept_ownership_V11))
        break;
    case 13079: /* module 51 call 23 */
        CHECK_ERROR(_readMethod_uniques_set_collection_max_supply_V11(c, &method->basic.uniques_set_collection_max_supply_V11))
        break;
    case 13080: /* module 51 call 24 */
        CHECK_ERROR(_readMethod_uniques_set_price_V11(c, &method->basic.uniques_set_price_V11))
        break;
    case 13081: /* module 51 call 25 */
        CHECK_ERROR(_readMethod_uniques_buy_item_V11(c, &method->basic.uniques_buy_item_V11))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V11(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 10:
        return STR_MO_BALANCES;
    case 22:
        return STR_MO_SESSION;
    case 40:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 31:
        return STR_MO_POLKADOTXCM;
#endif
    case 0:
        return STR_MO_SYSTEM;
    case 3:
        return STR_MO_TIMESTAMP;
    case 21:
        return STR_MO_COLLATORSELECTION;
    case 30:
        return STR_MO_XCMPQUEUE;
    case 33:
        return STR_MO_DMPQUEUE;
    case 41:
        return STR_MO_MULTISIG;
    case 42:
        return STR_MO_PROXY;
    case 50:
        return STR_MO_ASSETS;
    case 51:
        return STR_MO_UNIQUES;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V11(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2560: /* module 10 call 0 */
        return STR_ME_TRANSFER;
    case 2562: /* module 10 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 2563: /* module 10 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 2564: /* module 10 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 5632: /* module 22 call 0 */
        return STR_ME_SET_KEYS;
    case 5633: /* module 22 call 1 */
        return STR_ME_PURGE_KEYS;
    case 10240: /* module 40 call 0 */
        return STR_ME_BATCH;
    case 10242: /* module 40 call 2 */
        return STR_ME_BATCH_ALL;
    default:
        return _getMethod_Name_V11_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V11_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 7938: /* module 31 call 2 */
        return STR_ME_RESERVE_TRANSFER_ASSETS;
    case 7944: /* module 31 call 8 */
        return STR_ME_LIMITED_RESERVE_TRANSFER_ASSETS;
#endif
    case 0: /* module 0 call 0 */
        return STR_ME_REMARK;
    case 1: /* module 0 call 1 */
        return STR_ME_SET_HEAP_PAGES;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_CODE;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 7: /* module 0 call 7 */
        return STR_ME_REMARK_WITH_EVENT;
    case 768: /* module 3 call 0 */
        return STR_ME_SET;
    case 2561: /* module 10 call 1 */
        return STR_ME_SET_BALANCE;
    case 2565: /* module 10 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 5376: /* module 21 call 0 */
        return STR_ME_SET_INVULNERABLES;
    case 5377: /* module 21 call 1 */
        return STR_ME_SET_DESIRED_CANDIDATES;
    case 5378: /* module 21 call 2 */
        return STR_ME_SET_CANDIDACY_BOND;
    case 5379: /* module 21 call 3 */
        return STR_ME_REGISTER_AS_CANDIDATE;
    case 5380: /* module 21 call 4 */
        return STR_ME_LEAVE_INTENT;
    case 7680: /* module 30 call 0 */
        return STR_ME_SERVICE_OVERWEIGHT;
    case 7681: /* module 30 call 1 */
        return STR_ME_SUSPEND_XCM_EXECUTION;
    case 7682: /* module 30 call 2 */
        return STR_ME_RESUME_XCM_EXECUTION;
    case 7683: /* module 30 call 3 */
        return STR_ME_UPDATE_SUSPEND_THRESHOLD;
    case 7684: /* module 30 call 4 */
        return STR_ME_UPDATE_DROP_THRESHOLD;
    case 7685: /* module 30 call 5 */
        return STR_ME_UPDATE_RESUME_THRESHOLD;
    case 7686: /* module 30 call 6 */
        return STR_ME_UPDATE_THRESHOLD_WEIGHT;
    case 7687: /* module 30 call 7 */
        return STR_ME_UPDATE_WEIGHT_RESTRICT_DECAY;
    case 7688: /* module 30 call 8 */
        return STR_ME_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT;
    case 8448: /* module 33 call 0 */
        return STR_ME_SERVICE_OVERWEIGHT;
    case 10244: /* module 40 call 4 */
        return STR_ME_FORCE_BATCH;
    case 10245: /* module 40 call 5 */
        return STR_ME_WITH_WEIGHT;
    case 10496: /* module 41 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 10497: /* module 41 call 1 */
        return STR_ME_AS_MULTI;
    case 10498: /* module 41 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 10499: /* module 41 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 10752: /* module 42 call 0 */
        return STR_ME_PROXY;
    case 10753: /* module 42 call 1 */
        return STR_ME_ADD_PROXY;
    case 10754: /* module 42 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 10755: /* module 42 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 10756: /* module 42 call 4 */
        return STR_ME_CREATE_PURE;
    case 10757: /* module 42 call 5 */
        return STR_ME_KILL_PURE;
    case 10758: /* module 42 call 6 */
        return STR_ME_ANNOUNCE;
    case 10759: /* module 42 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 10760: /* module 42 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 10761: /* module 42 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 12800: /* module 50 call 0 */
        return STR_ME_CREATE;
    case 12801: /* module 50 call 1 */
        return STR_ME_FORCE_CREATE;
    case 12802: /* module 50 call 2 */
        return STR_ME_START_DESTROY;
    case 12803: /* module 50 call 3 */
        return STR_ME_DESTROY_ACCOUNTS;
    case 12804: /* module 50 call 4 */
        return STR_ME_DESTROY_APPROVALS;
    case 12805: /* module 50 call 5 */
        return STR_ME_FINISH_DESTROY;
    case 12806: /* module 50 call 6 */
        return STR_ME_MINT;
    case 12807: /* module 50 call 7 */
        return STR_ME_BURN;
    case 12808: /* module 50 call 8 */
        return STR_ME_TRANSFER;
    case 12809: /* module 50 call 9 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 12810: /* module 50 call 10 */
        return STR_ME_FORCE_TRANSFER;
    case 12811: /* module 50 call 11 */
        return STR_ME_FREEZE;
    case 12812: /* module 50 call 12 */
        return STR_ME_THAW;
    case 12813: /* module 50 call 13 */
        return STR_ME_FREEZE_ASSET;
    case 12814: /* module 50 call 14 */
        return STR_ME_THAW_ASSET;
    case 12815: /* module 50 call 15 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 12816: /* module 50 call 16 */
        return STR_ME_SET_TEAM;
    case 12817: /* module 50 call 17 */
        return STR_ME_SET_METADATA;
    case 12818: /* module 50 call 18 */
        return STR_ME_CLEAR_METADATA;
    case 12819: /* module 50 call 19 */
        return STR_ME_FORCE_SET_METADATA;
    case 12820: /* module 50 call 20 */
        return STR_ME_FORCE_CLEAR_METADATA;
    case 12821: /* module 50 call 21 */
        return STR_ME_FORCE_ASSET_STATUS;
    case 12822: /* module 50 call 22 */
        return STR_ME_APPROVE_TRANSFER;
    case 12823: /* module 50 call 23 */
        return STR_ME_CANCEL_APPROVAL;
    case 12824: /* module 50 call 24 */
        return STR_ME_FORCE_CANCEL_APPROVAL;
    case 12825: /* module 50 call 25 */
        return STR_ME_TRANSFER_APPROVED;
    case 12826: /* module 50 call 26 */
        return STR_ME_TOUCH;
    case 12827: /* module 50 call 27 */
        return STR_ME_REFUND;
    case 13056: /* module 51 call 0 */
        return STR_ME_CREATE;
    case 13057: /* module 51 call 1 */
        return STR_ME_FORCE_CREATE;
    case 13058: /* module 51 call 2 */
        return STR_ME_DESTROY;
    case 13059: /* module 51 call 3 */
        return STR_ME_MINT;
    case 13060: /* module 51 call 4 */
        return STR_ME_BURN;
    case 13061: /* module 51 call 5 */
        return STR_ME_TRANSFER;
    case 13062: /* module 51 call 6 */
        return STR_ME_REDEPOSIT;
    case 13063: /* module 51 call 7 */
        return STR_ME_FREEZE;
    case 13064: /* module 51 call 8 */
        return STR_ME_THAW;
    case 13065: /* module 51 call 9 */
        return STR_ME_FREEZE_COLLECTION;
    case 13066: /* module 51 call 10 */
        return STR_ME_THAW_COLLECTION;
    case 13067: /* module 51 call 11 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 13068: /* module 51 call 12 */
        return STR_ME_SET_TEAM;
    case 13069: /* module 51 call 13 */
        return STR_ME_APPROVE_TRANSFER;
    case 13070: /* module 51 call 14 */
        return STR_ME_CANCEL_APPROVAL;
    case 13071: /* module 51 call 15 */
        return STR_ME_FORCE_ITEM_STATUS;
    case 13072: /* module 51 call 16 */
        return STR_ME_SET_ATTRIBUTE;
    case 13073: /* module 51 call 17 */
        return STR_ME_CLEAR_ATTRIBUTE;
    case 13074: /* module 51 call 18 */
        return STR_ME_SET_METADATA;
    case 13075: /* module 51 call 19 */
        return STR_ME_CLEAR_METADATA;
    case 13076: /* module 51 call 20 */
        return STR_ME_SET_COLLECTION_METADATA;
    case 13077: /* module 51 call 21 */
        return STR_ME_CLEAR_COLLECTION_METADATA;
    case 13078: /* module 51 call 22 */
        return STR_ME_SET_ACCEPT_OWNERSHIP;
    case 13079: /* module 51 call 23 */
        return STR_ME_SET_COLLECTION_MAX_SUPPLY;
    case 13080: /* module 51 call 24 */
        return STR_ME_SET_PRICE;
    case 13081: /* module 51 call 25 */
        return STR_ME_BUY_ITEM;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V11(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2560: /* module 10 call 0 */
        return 2;
    case 2562: /* module 10 call 2 */
        return 3;
    case 2563: /* module 10 call 3 */
        return 2;
    case 2564: /* module 10 call 4 */
        return 2;
    case 5632: /* module 22 call 0 */
        return 2;
    case 5633: /* module 22 call 1 */
        return 0;
    case 10240: /* module 40 call 0 */
        return 1;
    case 10242: /* module 40 call 2 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 7938: /* module 31 call 2 */
        return 4;
    case 7944: /* module 31 call 8 */
        return 5;
#endif
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 2561: /* module 10 call 1 */
        return 3;
    case 2565: /* module 10 call 5 */
        return 2;
    case 5376: /* module 21 call 0 */
        return 1;
    case 5377: /* module 21 call 1 */
        return 1;
    case 5378: /* module 21 call 2 */
        return 1;
    case 5379: /* module 21 call 3 */
        return 0;
    case 5380: /* module 21 call 4 */
        return 0;
    case 7680: /* module 30 call 0 */
        return 2;
    case 7681: /* module 30 call 1 */
        return 0;
    case 7682: /* module 30 call 2 */
        return 0;
    case 7683: /* module 30 call 3 */
        return 1;
    case 7684: /* module 30 call 4 */
        return 1;
    case 7685: /* module 30 call 5 */
        return 1;
    case 7686: /* module 30 call 6 */
        return 1;
    case 7687: /* module 30 call 7 */
        return 1;
    case 7688: /* module 30 call 8 */
        return 1;
    case 8448: /* module 33 call 0 */
        return 2;
    case 10244: /* module 40 call 4 */
        return 1;
    case 10245: /* module 40 call 5 */
        return 2;
    case 10496: /* module 41 call 0 */
        return 2;
    case 10497: /* module 41 call 1 */
        return 5;
    case 10498: /* module 41 call 2 */
        return 5;
    case 10499: /* module 41 call 3 */
        return 4;
    case 10752: /* module 42 call 0 */
        return 3;
    case 10753: /* module 42 call 1 */
        return 3;
    case 10754: /* module 42 call 2 */
        return 3;
    case 10755: /* module 42 call 3 */
        return 0;
    case 10756: /* module 42 call 4 */
        return 3;
    case 10757: /* module 42 call 5 */
        return 5;
    case 10758: /* module 42 call 6 */
        return 2;
    case 10759: /* module 42 call 7 */
        return 2;
    case 10760: /* module 42 call 8 */
        return 2;
    case 10761: /* module 42 call 9 */
        return 4;
    case 12800: /* module 50 call 0 */
        return 3;
    case 12801: /* module 50 call 1 */
        return 4;
    case 12802: /* module 50 call 2 */
        return 1;
    case 12803: /* module 50 call 3 */
        return 1;
    case 12804: /* module 50 call 4 */
        return 1;
    case 12805: /* module 50 call 5 */
        return 1;
    case 12806: /* module 50 call 6 */
        return 3;
    case 12807: /* module 50 call 7 */
        return 3;
    case 12808: /* module 50 call 8 */
        return 3;
    case 12809: /* module 50 call 9 */
        return 3;
    case 12810: /* module 50 call 10 */
        return 4;
    case 12811: /* module 50 call 11 */
        return 2;
    case 12812: /* module 50 call 12 */
        return 2;
    case 12813: /* module 50 call 13 */
        return 1;
    case 12814: /* module 50 call 14 */
        return 1;
    case 12815: /* module 50 call 15 */
        return 2;
    case 12816: /* module 50 call 16 */
        return 4;
    case 12817: /* module 50 call 17 */
        return 4;
    case 12818: /* module 50 call 18 */
        return 1;
    case 12819: /* module 50 call 19 */
        return 5;
    case 12820: /* module 50 call 20 */
        return 1;
    case 12821: /* module 50 call 21 */
        return 8;
    case 12822: /* module 50 call 22 */
        return 3;
    case 12823: /* module 50 call 23 */
        return 2;
    case 12824: /* module 50 call 24 */
        return 3;
    case 12825: /* module 50 call 25 */
        return 4;
    case 12826: /* module 50 call 26 */
        return 1;
    case 12827: /* module 50 call 27 */
        return 2;
    case 13056: /* module 51 call 0 */
        return 2;
    case 13057: /* module 51 call 1 */
        return 3;
    case 13058: /* module 51 call 2 */
        return 2;
    case 13059: /* module 51 call 3 */
        return 3;
    case 13060: /* module 51 call 4 */
        return 3;
    case 13061: /* module 51 call 5 */
        return 3;
    case 13062: /* module 51 call 6 */
        return 2;
    case 13063: /* module 51 call 7 */
        return 2;
    case 13064: /* module 51 call 8 */
        return 2;
    case 13065: /* module 51 call 9 */
        return 1;
    case 13066: /* module 51 call 10 */
        return 1;
    case 13067: /* module 51 call 11 */
        return 2;
    case 13068: /* module 51 call 12 */
        return 4;
    case 13069: /* module 51 call 13 */
        return 3;
    case 13070: /* module 51 call 14 */
        return 3;
    case 13071: /* module 51 call 15 */
        return 7;
    case 13072: /* module 51 call 16 */
        return 4;
    case 13073: /* module 51 call 17 */
        return 3;
    case 13074: /* module 51 call 18 */
        return 4;
    case 13075: /* module 51 call 19 */
        return 2;
    case 13076: /* module 51 call 20 */
        return 3;
    case 13077: /* module 51 call 21 */
        return 1;
    case 13078: /* module 51 call 22 */
        return 1;
    case 13079: /* module 51 call 23 */
        return 2;
    case 13080: /* module 51 call 24 */
        return 4;
    case 13081: /* module 51 call 25 */
        return 3;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V11(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        default:
            return NULL;
        }
    case 7944: /* module 31 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_assets;
        case 3:
            return STR_IT_fee_asset_item;
        case 4:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bond;
        default:
            return NULL;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 10755: /* module 42 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10756: /* module 42 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 10757: /* module 42 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 10758: /* module 42 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 10759: /* module 42 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 10760: /* module 42 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 10761: /* module 42 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_admin;
        case 2:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_is_sufficient;
        case 3:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12806: /* module 50 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 12807: /* module 50 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 12808: /* module 50 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 12809: /* module 50 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 12810: /* module 50 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_source;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 12811: /* module 50 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 12812: /* module 50 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 12813: /* module 50 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12814: /* module 50 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12815: /* module 50 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 12816: /* module 50 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_issuer;
        case 2:
            return STR_IT_admin;
        case 3:
            return STR_IT_freezer;
        default:
            return NULL;
        }
    case 12817: /* module 50 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_symbol;
        case 3:
            return STR_IT_decimals;
        default:
            return NULL;
        }
    case 12818: /* module 50 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12819: /* module 50 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_symbol;
        case 3:
            return STR_IT_decimals;
        case 4:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 12820: /* module 50 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12821: /* module 50 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_issuer;
        case 3:
            return STR_IT_admin;
        case 4:
            return STR_IT_freezer;
        case 5:
            return STR_IT_min_balance;
        case 6:
            return STR_IT_is_sufficient;
        case 7:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 12822: /* module 50 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 12823: /* module 50 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 12824: /* module 50 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 12825: /* module 50 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_destination;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 12826: /* module 50 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12827: /* module 50 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_allow_burn;
        default:
            return NULL;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_admin;
        default:
            return NULL;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_free_holding;
        default:
            return NULL;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_witness;
        default:
            return NULL;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_check_owner;
        default:
            return NULL;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_dest;
        default:
            return NULL;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        default:
            return NULL;
        }
    case 13066: /* module 51 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        default:
            return NULL;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_issuer;
        case 2:
            return STR_IT_admin;
        case 3:
            return STR_IT_freezer;
        default:
            return NULL;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_maybe_check_delegate;
        default:
            return NULL;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_issuer;
        case 3:
            return STR_IT_admin;
        case 4:
            return STR_IT_freezer;
        case 5:
            return STR_IT_free_holding;
        case 6:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 13072: /* module 51 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_maybe_item;
        case 2:
            return STR_IT_key;
        case 3:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 13073: /* module 51 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_maybe_item;
        case 2:
            return STR_IT_key;
        default:
            return NULL;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_data;
        case 3:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_data;
        case 2:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        default:
            return NULL;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_maybe_collection;
        default:
            return NULL;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_max_supply;
        default:
            return NULL;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_price;
        case 3:
            return STR_IT_whitelisted_buyer;
        default:
            return NULL;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_bid_price;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V11(
    pd_Method_V11_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V11 - dest */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.balances_transfer_V11.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V11 - source */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.balances_force_transfer_V11.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V11 - dest */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.balances_force_transfer_V11.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V11 - dest */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.balances_transfer_keep_alive_V11.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V11 - dest */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.balances_transfer_all_V11.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V11 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V11.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V11 - keys */;
            return _toStringKeys_V11(
                &m->basic.session_set_keys_V11.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V11 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V11.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V11 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V11.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V11 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V11.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_reserve_transfer_assets_V11 - dest */;
            return _toStringBoxVersionedMultiLocation_V11(
                &m->basic.polkadotxcm_reserve_transfer_assets_V11.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_reserve_transfer_assets_V11 - beneficiary */;
            return _toStringBoxVersionedMultiLocation_V11(
                &m->basic.polkadotxcm_reserve_transfer_assets_V11.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_reserve_transfer_assets_V11 - assets */;
            return _toStringBoxVersionedMultiAssets_V11(
                &m->basic.polkadotxcm_reserve_transfer_assets_V11.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_reserve_transfer_assets_V11 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_reserve_transfer_assets_V11.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7944: /* module 31 call 8 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_limited_reserve_transfer_assets_V11 - dest */;
            return _toStringBoxVersionedMultiLocation_V11(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V11.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_limited_reserve_transfer_assets_V11 - beneficiary */;
            return _toStringBoxVersionedMultiLocation_V11(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V11.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_limited_reserve_transfer_assets_V11 - assets */;
            return _toStringBoxVersionedMultiAssets_V11(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V11.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_limited_reserve_transfer_assets_V11 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V11.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* polkadotxcm_limited_reserve_transfer_assets_V11 - weight_limit */;
            return _toStringWeightLimit_V11(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V11.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_remark_V11 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V11.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V11 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V11.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_code_V11 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V11.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V11 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V11.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V11 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V11.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V11 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V11.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V11 - who */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.balances_set_balance_V11.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V11 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V11.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V11 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V11.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V11 - who */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.balances_force_unreserve_V11.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V11 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_invulnerables_V11 - new_ */;
            return _toStringVecAccountId_V11(
                &m->basic.collatorselection_set_invulnerables_V11.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_desired_candidates_V11 - max */;
            return _toStringu32(
                &m->basic.collatorselection_set_desired_candidates_V11.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_candidacy_bond_V11 - bond */;
            return _toStringBalance(
                &m->basic.collatorselection_set_candidacy_bond_V11.bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5379: /* module 21 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5380: /* module 21 call 4 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_service_overweight_V11 - index */;
            return _toStringOverweightIndex_V11(
                &m->basic.xcmpqueue_service_overweight_V11.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpqueue_service_overweight_V11 - weight_limit */;
            return _toStringXcmWeight_V11(
                &m->basic.xcmpqueue_service_overweight_V11.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_suspend_threshold_V11 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_suspend_threshold_V11.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_drop_threshold_V11 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_drop_threshold_V11.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_resume_threshold_V11 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_resume_threshold_V11.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_threshold_weight_V11 - new_ */;
            return _toStringXcmWeight_V11(
                &m->basic.xcmpqueue_update_threshold_weight_V11.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_weight_restrict_decay_V11 - new_ */;
            return _toStringXcmWeight_V11(
                &m->basic.xcmpqueue_update_weight_restrict_decay_V11.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_xcmp_max_individual_weight_V11 - new_ */;
            return _toStringXcmWeight_V11(
                &m->basic.xcmpqueue_update_xcmp_max_individual_weight_V11.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0: /* dmpqueue_service_overweight_V11 - index */;
            return _toStringOverweightIndex_V11(
                &m->basic.dmpqueue_service_overweight_V11.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dmpqueue_service_overweight_V11 - weight_limit */;
            return _toStringXcmWeight_V11(
                &m->basic.dmpqueue_service_overweight_V11.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V11 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V11.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V11 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V11.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V11 - weight */;
            return _toStringWeight_V11(
                &m->basic.utility_with_weight_V11.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V11 - other_signatories */;
            return _toStringVecAccountId_V11(
                &m->nested.multisig_as_multi_threshold_1_V11.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V11 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V11.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V11 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V11.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V11 - other_signatories */;
            return _toStringVecAccountId_V11(
                &m->nested.multisig_as_multi_V11.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V11 - maybe_timepoint */;
            return _toStringOptionTimepoint_V11(
                &m->nested.multisig_as_multi_V11.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V11 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V11.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V11 - max_weight */;
            return _toStringWeight_V11(
                &m->nested.multisig_as_multi_V11.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V11 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V11.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V11 - other_signatories */;
            return _toStringVecAccountId_V11(
                &m->nested.multisig_approve_as_multi_V11.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V11 - maybe_timepoint */;
            return _toStringOptionTimepoint_V11(
                &m->nested.multisig_approve_as_multi_V11.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V11 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V11.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V11 - max_weight */;
            return _toStringWeight_V11(
                &m->nested.multisig_approve_as_multi_V11.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V11 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V11.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V11 - other_signatories */;
            return _toStringVecAccountId_V11(
                &m->nested.multisig_cancel_as_multi_V11.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V11 - timepoint */;
            return _toStringTimepoint_V11(
                &m->nested.multisig_cancel_as_multi_V11.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V11 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V11.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V11 - real */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.proxy_proxy_V11.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V11 - force_proxy_type */;
            return _toStringOptionProxyType_V11(
                &m->nested.proxy_proxy_V11.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V11 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V11.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V11 - delegate */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.proxy_add_proxy_V11.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V11 - proxy_type */;
            return _toStringProxyType_V11(
                &m->basic.proxy_add_proxy_V11.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V11 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V11.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V11 - delegate */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.proxy_remove_proxy_V11.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V11 - proxy_type */;
            return _toStringProxyType_V11(
                &m->basic.proxy_remove_proxy_V11.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V11 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V11.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10755: /* module 42 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10756: /* module 42 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_create_pure_V11 - proxy_type */;
            return _toStringProxyType_V11(
                &m->basic.proxy_create_pure_V11.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_create_pure_V11 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_create_pure_V11.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_create_pure_V11 - index */;
            return _toStringu16(
                &m->basic.proxy_create_pure_V11.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10757: /* module 42 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_pure_V11 - spawner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.proxy_kill_pure_V11.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_pure_V11 - proxy_type */;
            return _toStringProxyType_V11(
                &m->basic.proxy_kill_pure_V11.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_pure_V11 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_pure_V11.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_pure_V11 - height */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_pure_V11.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_pure_V11 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_pure_V11.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10758: /* module 42 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V11 - real */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.proxy_announce_V11.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V11 - call_hash */;
            return _toStringCallHashOf_V11(
                &m->basic.proxy_announce_V11.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10759: /* module 42 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V11 - real */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.proxy_remove_announcement_V11.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V11 - call_hash */;
            return _toStringCallHashOf_V11(
                &m->basic.proxy_remove_announcement_V11.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10760: /* module 42 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V11 - delegate */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.proxy_reject_announcement_V11.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V11 - call_hash */;
            return _toStringCallHashOf_V11(
                &m->basic.proxy_reject_announcement_V11.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10761: /* module 42 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V11 - delegate */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.proxy_proxy_announced_V11.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V11 - real */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.proxy_proxy_announced_V11.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V11 - force_proxy_type */;
            return _toStringOptionProxyType_V11(
                &m->basic.proxy_proxy_announced_V11.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V11 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V11.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0: /* assets_create_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_create_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_create_V11 - admin */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_create_V11.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_create_V11 - min_balance */;
            return _toStringBalance(
                &m->nested.assets_create_V11.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0: /* assets_force_create_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_create_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_create_V11 - owner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_force_create_V11.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_create_V11 - is_sufficient */;
            return _toStringbool(
                &m->nested.assets_force_create_V11.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_create_V11 - min_balance */;
            return _toStringCompactBalance(
                &m->nested.assets_force_create_V11.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        case 0: /* assets_start_destroy_V11 - id */;
            return _toStringCompactu32(
                &m->basic.assets_start_destroy_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0: /* assets_destroy_accounts_V11 - id */;
            return _toStringCompactu32(
                &m->basic.assets_destroy_accounts_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0: /* assets_destroy_approvals_V11 - id */;
            return _toStringCompactu32(
                &m->basic.assets_destroy_approvals_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0: /* assets_finish_destroy_V11 - id */;
            return _toStringCompactu32(
                &m->basic.assets_finish_destroy_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12806: /* module 50 call 6 */
        switch (itemIdx) {
        case 0: /* assets_mint_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_mint_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_mint_V11 - beneficiary */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_mint_V11.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_mint_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_mint_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12807: /* module 50 call 7 */
        switch (itemIdx) {
        case 0: /* assets_burn_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_burn_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_burn_V11 - who */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_burn_V11.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_burn_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_burn_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12808: /* module 50 call 8 */
        switch (itemIdx) {
        case 0: /* assets_transfer_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_transfer_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_V11 - target */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_transfer_V11.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_transfer_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12809: /* module 50 call 9 */
        switch (itemIdx) {
        case 0: /* assets_transfer_keep_alive_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_transfer_keep_alive_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_keep_alive_V11 - target */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_transfer_keep_alive_V11.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_keep_alive_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_transfer_keep_alive_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12810: /* module 50 call 10 */
        switch (itemIdx) {
        case 0: /* assets_force_transfer_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_transfer_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_transfer_V11 - source */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_force_transfer_V11.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_transfer_V11 - dest */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_force_transfer_V11.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_transfer_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_force_transfer_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12811: /* module 50 call 11 */
        switch (itemIdx) {
        case 0: /* assets_freeze_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_freeze_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_freeze_V11 - who */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_freeze_V11.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12812: /* module 50 call 12 */
        switch (itemIdx) {
        case 0: /* assets_thaw_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_thaw_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_thaw_V11 - who */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_thaw_V11.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12813: /* module 50 call 13 */
        switch (itemIdx) {
        case 0: /* assets_freeze_asset_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_freeze_asset_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12814: /* module 50 call 14 */
        switch (itemIdx) {
        case 0: /* assets_thaw_asset_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_thaw_asset_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12815: /* module 50 call 15 */
        switch (itemIdx) {
        case 0: /* assets_transfer_ownership_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_transfer_ownership_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_ownership_V11 - owner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_transfer_ownership_V11.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12816: /* module 50 call 16 */
        switch (itemIdx) {
        case 0: /* assets_set_team_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_set_team_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_team_V11 - issuer */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_set_team_V11.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_team_V11 - admin */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_set_team_V11.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_team_V11 - freezer */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_set_team_V11.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12817: /* module 50 call 17 */
        switch (itemIdx) {
        case 0: /* assets_set_metadata_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_set_metadata_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_metadata_V11 - name */;
            return _toStringVecu8(
                &m->nested.assets_set_metadata_V11.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_metadata_V11 - symbol */;
            return _toStringVecu8(
                &m->nested.assets_set_metadata_V11.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_metadata_V11 - decimals */;
            return _toStringu8(
                &m->nested.assets_set_metadata_V11.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12818: /* module 50 call 18 */
        switch (itemIdx) {
        case 0: /* assets_clear_metadata_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_clear_metadata_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12819: /* module 50 call 19 */
        switch (itemIdx) {
        case 0: /* assets_force_set_metadata_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_set_metadata_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_set_metadata_V11 - name */;
            return _toStringVecu8(
                &m->nested.assets_force_set_metadata_V11.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_set_metadata_V11 - symbol */;
            return _toStringVecu8(
                &m->nested.assets_force_set_metadata_V11.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_set_metadata_V11 - decimals */;
            return _toStringu8(
                &m->nested.assets_force_set_metadata_V11.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_set_metadata_V11 - is_frozen */;
            return _toStringbool(
                &m->nested.assets_force_set_metadata_V11.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12820: /* module 50 call 20 */
        switch (itemIdx) {
        case 0: /* assets_force_clear_metadata_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_clear_metadata_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12821: /* module 50 call 21 */
        switch (itemIdx) {
        case 0: /* assets_force_asset_status_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_asset_status_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_asset_status_V11 - owner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_force_asset_status_V11.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_asset_status_V11 - issuer */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_force_asset_status_V11.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_asset_status_V11 - admin */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_force_asset_status_V11.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_asset_status_V11 - freezer */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_force_asset_status_V11.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* assets_force_asset_status_V11 - min_balance */;
            return _toStringCompactBalance(
                &m->nested.assets_force_asset_status_V11.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* assets_force_asset_status_V11 - is_sufficient */;
            return _toStringbool(
                &m->nested.assets_force_asset_status_V11.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* assets_force_asset_status_V11 - is_frozen */;
            return _toStringbool(
                &m->nested.assets_force_asset_status_V11.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12822: /* module 50 call 22 */
        switch (itemIdx) {
        case 0: /* assets_approve_transfer_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_approve_transfer_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_approve_transfer_V11 - delegate */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_approve_transfer_V11.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_approve_transfer_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_approve_transfer_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12823: /* module 50 call 23 */
        switch (itemIdx) {
        case 0: /* assets_cancel_approval_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_cancel_approval_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_cancel_approval_V11 - delegate */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_cancel_approval_V11.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12824: /* module 50 call 24 */
        switch (itemIdx) {
        case 0: /* assets_force_cancel_approval_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_cancel_approval_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_cancel_approval_V11 - owner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_force_cancel_approval_V11.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_cancel_approval_V11 - delegate */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_force_cancel_approval_V11.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12825: /* module 50 call 25 */
        switch (itemIdx) {
        case 0: /* assets_transfer_approved_V11 - id */;
            return _toStringCompactu32(
                &m->nested.assets_transfer_approved_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_approved_V11 - owner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_transfer_approved_V11.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_approved_V11 - destination */;
            return _toStringAccountIdLookupOfT_V11(
                &m->nested.assets_transfer_approved_V11.destination,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_transfer_approved_V11 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_transfer_approved_V11.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12826: /* module 50 call 26 */
        switch (itemIdx) {
        case 0: /* assets_touch_V11 - id */;
            return _toStringCompactu32(
                &m->basic.assets_touch_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12827: /* module 50 call 27 */
        switch (itemIdx) {
        case 0: /* assets_refund_V11 - id */;
            return _toStringCompactu32(
                &m->basic.assets_refund_V11.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_refund_V11 - allow_burn */;
            return _toStringbool(
                &m->basic.assets_refund_V11.allow_burn,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0: /* uniques_create_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_create_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_create_V11 - admin */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_create_V11.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0: /* uniques_force_create_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_force_create_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_force_create_V11 - owner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_force_create_V11.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_force_create_V11 - free_holding */;
            return _toStringbool(
                &m->basic.uniques_force_create_V11.free_holding,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0: /* uniques_destroy_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_destroy_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_destroy_V11 - witness */;
            return _toStringDestroyWitness_V11(
                &m->basic.uniques_destroy_V11.witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0: /* uniques_mint_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_mint_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_mint_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_mint_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_mint_V11 - owner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_mint_V11.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0: /* uniques_burn_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_burn_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_burn_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_burn_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_burn_V11 - check_owner */;
            return _toStringOptionAccountIdLookupOfT_V11(
                &m->basic.uniques_burn_V11.check_owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0: /* uniques_transfer_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_transfer_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_transfer_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_transfer_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_transfer_V11 - dest */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_transfer_V11.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0: /* uniques_redeposit_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_redeposit_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_redeposit_V11 - items */;
            return _toStringVecItemId_V11(
                &m->basic.uniques_redeposit_V11.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0: /* uniques_freeze_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_freeze_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_freeze_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_freeze_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0: /* uniques_thaw_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_thaw_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_thaw_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_thaw_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0: /* uniques_freeze_collection_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_freeze_collection_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13066: /* module 51 call 10 */
        switch (itemIdx) {
        case 0: /* uniques_thaw_collection_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_thaw_collection_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0: /* uniques_transfer_ownership_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_transfer_ownership_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_transfer_ownership_V11 - owner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_transfer_ownership_V11.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0: /* uniques_set_team_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_set_team_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_team_V11 - issuer */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_set_team_V11.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_team_V11 - admin */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_set_team_V11.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_team_V11 - freezer */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_set_team_V11.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0: /* uniques_approve_transfer_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_approve_transfer_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_approve_transfer_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_approve_transfer_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_approve_transfer_V11 - delegate */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_approve_transfer_V11.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0: /* uniques_cancel_approval_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_cancel_approval_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_cancel_approval_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_cancel_approval_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_cancel_approval_V11 - maybe_check_delegate */;
            return _toStringOptionAccountIdLookupOfT_V11(
                &m->basic.uniques_cancel_approval_V11.maybe_check_delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0: /* uniques_force_item_status_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_force_item_status_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_force_item_status_V11 - owner */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_force_item_status_V11.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_force_item_status_V11 - issuer */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_force_item_status_V11.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_force_item_status_V11 - admin */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_force_item_status_V11.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* uniques_force_item_status_V11 - freezer */;
            return _toStringAccountIdLookupOfT_V11(
                &m->basic.uniques_force_item_status_V11.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* uniques_force_item_status_V11 - free_holding */;
            return _toStringbool(
                &m->basic.uniques_force_item_status_V11.free_holding,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* uniques_force_item_status_V11 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_force_item_status_V11.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13072: /* module 51 call 16 */
        switch (itemIdx) {
        case 0: /* uniques_set_attribute_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_set_attribute_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_attribute_V11 - maybe_item */;
            return _toStringOptionItemId_V11(
                &m->basic.uniques_set_attribute_V11.maybe_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_attribute_V11 - key */;
            return _toStringBoundedVecu8_V11(
                &m->basic.uniques_set_attribute_V11.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_attribute_V11 - value */;
            return _toStringBoundedVecu8_V11(
                &m->basic.uniques_set_attribute_V11.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13073: /* module 51 call 17 */
        switch (itemIdx) {
        case 0: /* uniques_clear_attribute_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_clear_attribute_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_clear_attribute_V11 - maybe_item */;
            return _toStringOptionItemId_V11(
                &m->basic.uniques_clear_attribute_V11.maybe_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_clear_attribute_V11 - key */;
            return _toStringBoundedVecu8_V11(
                &m->basic.uniques_clear_attribute_V11.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0: /* uniques_set_metadata_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_set_metadata_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_metadata_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_set_metadata_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_metadata_V11 - data */;
            return _toStringBoundedVecu8_V11(
                &m->basic.uniques_set_metadata_V11.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_metadata_V11 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_set_metadata_V11.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0: /* uniques_clear_metadata_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_clear_metadata_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_clear_metadata_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_clear_metadata_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0: /* uniques_set_collection_metadata_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_set_collection_metadata_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_collection_metadata_V11 - data */;
            return _toStringBoundedVecu8_V11(
                &m->basic.uniques_set_collection_metadata_V11.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_collection_metadata_V11 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_set_collection_metadata_V11.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0: /* uniques_clear_collection_metadata_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_clear_collection_metadata_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0: /* uniques_set_accept_ownership_V11 - maybe_collection */;
            return _toStringOptionCollectionId_V11(
                &m->basic.uniques_set_accept_ownership_V11.maybe_collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0: /* uniques_set_collection_max_supply_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_set_collection_max_supply_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_collection_max_supply_V11 - max_supply */;
            return _toStringu32(
                &m->basic.uniques_set_collection_max_supply_V11.max_supply,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0: /* uniques_set_price_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_set_price_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_price_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_set_price_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_price_V11 - price */;
            return _toStringOptionItemPrice_V11(
                &m->basic.uniques_set_price_V11.price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_price_V11 - whitelisted_buyer */;
            return _toStringOptionAccountIdLookupOfT_V11(
                &m->basic.uniques_set_price_V11.whitelisted_buyer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0: /* uniques_buy_item_V11 - collection */;
            return _toStringCollectionId_V11(
                &m->basic.uniques_buy_item_V11.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_buy_item_V11 - item */;
            return _toStringItemId_V11(
                &m->basic.uniques_buy_item_V11.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_buy_item_V11 - bid_price */;
            return _toStringItemPrice_V11(
                &m->basic.uniques_buy_item_V11.bid_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V11(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V11(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: // Timestamp:Set
    case 2564: // Balances:Transfer all
    case 2565: // Balances:Force unreserve
    case 5376: // CollatorSelection:Set invulnerables
    case 5377: // CollatorSelection:Set desired candidates
    case 5378: // CollatorSelection:Set candidacy bond
    case 5379: // CollatorSelection:Register as candidate
    case 5380: // CollatorSelection:Leave intent
    case 5632: // Session:Set keys
    case 5633: // Session:Purge keys
    case 7680: // XcmpQueue:Service overweight
    case 7681: // XcmpQueue:Suspend xcm execution
    case 7682: // XcmpQueue:Resume xcm execution
    case 7683: // XcmpQueue:Update suspend threshold
    case 7684: // XcmpQueue:Update drop threshold
    case 7685: // XcmpQueue:Update resume threshold
    case 7686: // XcmpQueue:Update threshold weight
    case 7687: // XcmpQueue:Update weight restrict decay
    case 7688: // XcmpQueue:Update xcmp max individual weight
    case 7938: // PolkadotXcm:Reserve transfer assets
    case 7944: // PolkadotXcm:Limited reserve transfer assets
    case 8448: // DmpQueue:Service overweight
    case 10240: // Utility:Batch
    case 10242: // Utility:Batch all
    case 10244: // Utility:Force batch
    case 10245: // Utility:With weight
    case 10753: // Proxy:Add proxy
    case 10754: // Proxy:Remove proxy
    case 10755: // Proxy:Remove proxies
    case 10756: // Proxy:Create pure
    case 10757: // Proxy:Kill pure
    case 10758: // Proxy:Announce
    case 10759: // Proxy:Remove announcement
    case 10760: // Proxy:Reject announcement
    case 10761: // Proxy:Proxy announced
    case 12802: // Assets:Start destroy
    case 12803: // Assets:Destroy accounts
    case 12804: // Assets:Destroy approvals
    case 12805: // Assets:Finish destroy
    case 12826: // Assets:Touch
    case 12827: // Assets:Refund
    case 13056: // Uniques:Create
    case 13057: // Uniques:Force create
    case 13058: // Uniques:Destroy
    case 13059: // Uniques:Mint
    case 13060: // Uniques:Burn
    case 13061: // Uniques:Transfer
    case 13062: // Uniques:Redeposit
    case 13063: // Uniques:Freeze
    case 13064: // Uniques:Thaw
    case 13065: // Uniques:Freeze collection
    case 13066: // Uniques:Thaw collection
    case 13067: // Uniques:Transfer ownership
    case 13068: // Uniques:Set team
    case 13069: // Uniques:Approve transfer
    case 13070: // Uniques:Cancel approval
    case 13071: // Uniques:Force item status
    case 13072: // Uniques:Set attribute
    case 13073: // Uniques:Clear attribute
    case 13074: // Uniques:Set metadata
    case 13075: // Uniques:Clear metadata
    case 13076: // Uniques:Set collection metadata
    case 13077: // Uniques:Clear collection metadata
    case 13078: // Uniques:Set accept ownership
    case 13079: // Uniques:Set collection max supply
    case 13080: // Uniques:Set price
    case 13081: // Uniques:Buy item
        return false;
    default:
        return true;
    }
}
