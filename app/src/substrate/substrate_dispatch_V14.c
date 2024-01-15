/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
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

#include "substrate_dispatch_V14.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V14(
    parser_context_t* c, pd_balances_force_transfer_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V14(
    parser_context_t* c, pd_balances_transfer_keep_alive_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V14(
    parser_context_t* c, pd_balances_transfer_all_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V14(
    parser_context_t* c, pd_session_set_keys_V14_t* m)
{
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V14(
    parser_context_t* c, pd_session_purge_keys_V14_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V14(
    parser_context_t* c, pd_utility_batch_V14_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V14(
    parser_context_t* c, pd_utility_batch_all_V14_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
__Z_INLINE parser_error_t _readMethod_polkadotxcm_teleport_assets_V14(
    parser_context_t* c, pd_polkadotxcm_teleport_assets_V14_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_polkadotxcm_reserve_transfer_assets_V14(
    parser_context_t* c, pd_polkadotxcm_reserve_transfer_assets_V14_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_polkadotxcm_limited_reserve_transfer_assets_V14(
    parser_context_t* c, pd_polkadotxcm_limited_reserve_transfer_assets_V14_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeightLimit(c, &m->weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_polkadotxcm_limited_teleport_assets_V14(
    parser_context_t* c, pd_polkadotxcm_limited_teleport_assets_V14_t* m)
{
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->dest))
    CHECK_ERROR(_readBoxVersionedMultiLocation(c, &m->beneficiary))
    CHECK_ERROR(_readBoxVersionedMultiAssets(c, &m->assets))
    CHECK_ERROR(_readu32(c, &m->fee_asset_item))
    CHECK_ERROR(_readWeightLimit(c, &m->weight_limit))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_create_V14(
    parser_context_t* c, pd_foreignassets_create_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_force_create_V14(
    parser_context_t* c, pd_foreignassets_force_create_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_start_destroy_V14(
    parser_context_t* c, pd_foreignassets_start_destroy_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_destroy_accounts_V14(
    parser_context_t* c, pd_foreignassets_destroy_accounts_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_destroy_approvals_V14(
    parser_context_t* c, pd_foreignassets_destroy_approvals_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_finish_destroy_V14(
    parser_context_t* c, pd_foreignassets_finish_destroy_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_mint_V14(
    parser_context_t* c, pd_foreignassets_mint_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_burn_V14(
    parser_context_t* c, pd_foreignassets_burn_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_transfer_V14(
    parser_context_t* c, pd_foreignassets_transfer_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_transfer_keep_alive_V14(
    parser_context_t* c, pd_foreignassets_transfer_keep_alive_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_force_transfer_V14(
    parser_context_t* c, pd_foreignassets_force_transfer_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_freeze_V14(
    parser_context_t* c, pd_foreignassets_freeze_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_thaw_V14(
    parser_context_t* c, pd_foreignassets_thaw_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_freeze_asset_V14(
    parser_context_t* c, pd_foreignassets_freeze_asset_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_thaw_asset_V14(
    parser_context_t* c, pd_foreignassets_thaw_asset_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_transfer_ownership_V14(
    parser_context_t* c, pd_foreignassets_transfer_ownership_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_set_team_V14(
    parser_context_t* c, pd_foreignassets_set_team_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_set_metadata_V14(
    parser_context_t* c, pd_foreignassets_set_metadata_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_clear_metadata_V14(
    parser_context_t* c, pd_foreignassets_clear_metadata_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_force_set_metadata_V14(
    parser_context_t* c, pd_foreignassets_force_set_metadata_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_force_clear_metadata_V14(
    parser_context_t* c, pd_foreignassets_force_clear_metadata_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_force_asset_status_V14(
    parser_context_t* c, pd_foreignassets_force_asset_status_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_approve_transfer_V14(
    parser_context_t* c, pd_foreignassets_approve_transfer_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_cancel_approval_V14(
    parser_context_t* c, pd_foreignassets_cancel_approval_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_force_cancel_approval_V14(
    parser_context_t* c, pd_foreignassets_force_cancel_approval_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_transfer_approved_V14(
    parser_context_t* c, pd_foreignassets_transfer_approved_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->destination))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_touch_V14(
    parser_context_t* c, pd_foreignassets_touch_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_refund_V14(
    parser_context_t* c, pd_foreignassets_refund_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->allow_burn))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_set_min_balance_V14(
    parser_context_t* c, pd_foreignassets_set_min_balance_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_touch_other_V14(
    parser_context_t* c, pd_foreignassets_touch_other_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_refund_other_V14(
    parser_context_t* c, pd_foreignassets_refund_other_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_foreignassets_block_V14(
    parser_context_t* c, pd_foreignassets_block_V14_t* m)
{
    CHECK_ERROR(_readAssetIdParameter(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_assetconversion_create_pool_V14(
    parser_context_t* c, pd_assetconversion_create_pool_V14_t* m)
{
    CHECK_ERROR(_readMultiAssetId(c, &m->asset1))
    CHECK_ERROR(_readMultiAssetId(c, &m->asset2))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_assetconversion_add_liquidity_V14(
    parser_context_t* c, pd_assetconversion_add_liquidity_V14_t* m)
{
    CHECK_ERROR(_readMultiAssetId(c, &m->asset1))
    CHECK_ERROR(_readMultiAssetId(c, &m->asset2))
    CHECK_ERROR(_readu128(c, &m->amount1_desired))
    CHECK_ERROR(_readu128(c, &m->amount2_desired))
    CHECK_ERROR(_readu128(c, &m->amount1_min))
    CHECK_ERROR(_readu128(c, &m->amount2_min))
    CHECK_ERROR(_readAccountId(c, &m->mint_to))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_assetconversion_remove_liquidity_V14(
    parser_context_t* c, pd_assetconversion_remove_liquidity_V14_t* m)
{
    CHECK_ERROR(_readMultiAssetId(c, &m->asset1))
    CHECK_ERROR(_readMultiAssetId(c, &m->asset2))
    CHECK_ERROR(_readu128(c, &m->lp_token_burn))
    CHECK_ERROR(_readu128(c, &m->amount1_min_receive))
    CHECK_ERROR(_readu128(c, &m->amount2_min_receive))
    CHECK_ERROR(_readAccountId(c, &m->withdraw_to))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_assetconversion_swap_exact_tokens_for_tokens_V14(
    parser_context_t* c, pd_assetconversion_swap_exact_tokens_for_tokens_V14_t* m)
{
    CHECK_ERROR(_readVecMultiAssetId(c, &m->path))
    CHECK_ERROR(_readu128(c, &m->amount_in))
    CHECK_ERROR(_readu128(c, &m->amount_out_min))
    CHECK_ERROR(_readAccountId(c, &m->send_to))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_assetconversion_swap_tokens_for_exact_tokens_V14(
    parser_context_t* c, pd_assetconversion_swap_tokens_for_exact_tokens_V14_t* m)
{
    CHECK_ERROR(_readVecMultiAssetId(c, &m->path))
    CHECK_ERROR(_readu128(c, &m->amount_out))
    CHECK_ERROR(_readu128(c, &m->amount_in_max))
    CHECK_ERROR(_readAccountId(c, &m->send_to))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V14(
    parser_context_t* c, pd_system_remark_V14_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V14(
    parser_context_t* c, pd_system_set_heap_pages_V14_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V14(
    parser_context_t* c, pd_system_set_code_V14_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V14(
    parser_context_t* c, pd_system_set_code_without_checks_V14_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V14(
    parser_context_t* c, pd_system_remark_with_event_V14_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V14(
    parser_context_t* c, pd_timestamp_set_V14_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V14(
    parser_context_t* c, pd_balances_transfer_allow_death_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V14(
    parser_context_t* c, pd_balances_force_unreserve_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V14(
    parser_context_t* c, pd_balances_upgrade_accounts_V14_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V14(
    parser_context_t* c, pd_balances_force_set_balance_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_invulnerables_V14(
    parser_context_t* c, pd_collatorselection_set_invulnerables_V14_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_desired_candidates_V14(
    parser_context_t* c, pd_collatorselection_set_desired_candidates_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_set_candidacy_bond_V14(
    parser_context_t* c, pd_collatorselection_set_candidacy_bond_V14_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->bond))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_register_as_candidate_V14(
    parser_context_t* c, pd_collatorselection_register_as_candidate_V14_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_leave_intent_V14(
    parser_context_t* c, pd_collatorselection_leave_intent_V14_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_add_invulnerable_V14(
    parser_context_t* c, pd_collatorselection_add_invulnerable_V14_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_collatorselection_remove_invulnerable_V14(
    parser_context_t* c, pd_collatorselection_remove_invulnerable_V14_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_service_overweight_V14(
    parser_context_t* c, pd_xcmpqueue_service_overweight_V14_t* m)
{
    CHECK_ERROR(_readOverweightIndex(c, &m->index))
    CHECK_ERROR(_readWeight(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_suspend_xcm_execution_V14(
    parser_context_t* c, pd_xcmpqueue_suspend_xcm_execution_V14_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_resume_xcm_execution_V14(
    parser_context_t* c, pd_xcmpqueue_resume_xcm_execution_V14_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_suspend_threshold_V14(
    parser_context_t* c, pd_xcmpqueue_update_suspend_threshold_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_drop_threshold_V14(
    parser_context_t* c, pd_xcmpqueue_update_drop_threshold_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_resume_threshold_V14(
    parser_context_t* c, pd_xcmpqueue_update_resume_threshold_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_threshold_weight_V14(
    parser_context_t* c, pd_xcmpqueue_update_threshold_weight_V14_t* m)
{
    CHECK_ERROR(_readWeight(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_weight_restrict_decay_V14(
    parser_context_t* c, pd_xcmpqueue_update_weight_restrict_decay_V14_t* m)
{
    CHECK_ERROR(_readWeight(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xcmpqueue_update_xcmp_max_individual_weight_V14(
    parser_context_t* c, pd_xcmpqueue_update_xcmp_max_individual_weight_V14_t* m)
{
    CHECK_ERROR(_readWeight(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dmpqueue_service_overweight_V14(
    parser_context_t* c, pd_dmpqueue_service_overweight_V14_t* m)
{
    CHECK_ERROR(_readOverweightIndex(c, &m->index))
    CHECK_ERROR(_readWeight(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V14(
    parser_context_t* c, pd_utility_force_batch_V14_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V14(
    parser_context_t* c, pd_utility_with_weight_V14_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V14(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V14_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V14(
    parser_context_t* c, pd_multisig_as_multi_V14_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V14(
    parser_context_t* c, pd_multisig_approve_as_multi_V14_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V14(
    parser_context_t* c, pd_multisig_cancel_as_multi_V14_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V14(
    parser_context_t* c, pd_proxy_proxy_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V14(
    parser_context_t* c, pd_proxy_add_proxy_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V14(
    parser_context_t* c, pd_proxy_remove_proxy_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V14(
    parser_context_t* c, pd_proxy_remove_proxies_V14_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_create_pure_V14(
    parser_context_t* c, pd_proxy_create_pure_V14_t* m)
{
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_pure_V14(
    parser_context_t* c, pd_proxy_kill_pure_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->spawner))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V14(
    parser_context_t* c, pd_proxy_announce_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V14(
    parser_context_t* c, pd_proxy_remove_announcement_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V14(
    parser_context_t* c, pd_proxy_reject_announcement_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V14(
    parser_context_t* c, pd_proxy_proxy_announced_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_create_V14(
    parser_context_t* c, pd_assets_create_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_create_V14(
    parser_context_t* c, pd_assets_force_create_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_start_destroy_V14(
    parser_context_t* c, pd_assets_start_destroy_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_destroy_accounts_V14(
    parser_context_t* c, pd_assets_destroy_accounts_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_destroy_approvals_V14(
    parser_context_t* c, pd_assets_destroy_approvals_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_finish_destroy_V14(
    parser_context_t* c, pd_assets_finish_destroy_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_mint_V14(
    parser_context_t* c, pd_assets_mint_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_burn_V14(
    parser_context_t* c, pd_assets_burn_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_V14(
    parser_context_t* c, pd_assets_transfer_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_keep_alive_V14(
    parser_context_t* c, pd_assets_transfer_keep_alive_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_transfer_V14(
    parser_context_t* c, pd_assets_force_transfer_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_V14(
    parser_context_t* c, pd_assets_freeze_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_V14(
    parser_context_t* c, pd_assets_thaw_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_asset_V14(
    parser_context_t* c, pd_assets_freeze_asset_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_asset_V14(
    parser_context_t* c, pd_assets_thaw_asset_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_ownership_V14(
    parser_context_t* c, pd_assets_transfer_ownership_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_team_V14(
    parser_context_t* c, pd_assets_set_team_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_metadata_V14(
    parser_context_t* c, pd_assets_set_metadata_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_clear_metadata_V14(
    parser_context_t* c, pd_assets_clear_metadata_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_set_metadata_V14(
    parser_context_t* c, pd_assets_force_set_metadata_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_clear_metadata_V14(
    parser_context_t* c, pd_assets_force_clear_metadata_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_asset_status_V14(
    parser_context_t* c, pd_assets_force_asset_status_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_approve_transfer_V14(
    parser_context_t* c, pd_assets_approve_transfer_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_cancel_approval_V14(
    parser_context_t* c, pd_assets_cancel_approval_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_cancel_approval_V14(
    parser_context_t* c, pd_assets_force_cancel_approval_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_approved_V14(
    parser_context_t* c, pd_assets_transfer_approved_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->destination))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_touch_V14(
    parser_context_t* c, pd_assets_touch_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_refund_V14(
    parser_context_t* c, pd_assets_refund_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->allow_burn))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_min_balance_V14(
    parser_context_t* c, pd_assets_set_min_balance_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_touch_other_V14(
    parser_context_t* c, pd_assets_touch_other_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_refund_other_V14(
    parser_context_t* c, pd_assets_refund_other_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_block_V14(
    parser_context_t* c, pd_assets_block_V14_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_create_V14(
    parser_context_t* c, pd_uniques_create_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_force_create_V14(
    parser_context_t* c, pd_uniques_force_create_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->free_holding))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_destroy_V14(
    parser_context_t* c, pd_uniques_destroy_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readDestroyWitness(c, &m->witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_mint_V14(
    parser_context_t* c, pd_uniques_mint_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_burn_V14(
    parser_context_t* c, pd_uniques_burn_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->check_owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_transfer_V14(
    parser_context_t* c, pd_uniques_transfer_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_redeposit_V14(
    parser_context_t* c, pd_uniques_redeposit_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readVecItemId(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_freeze_V14(
    parser_context_t* c, pd_uniques_freeze_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_thaw_V14(
    parser_context_t* c, pd_uniques_thaw_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_freeze_collection_V14(
    parser_context_t* c, pd_uniques_freeze_collection_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_thaw_collection_V14(
    parser_context_t* c, pd_uniques_thaw_collection_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_transfer_ownership_V14(
    parser_context_t* c, pd_uniques_transfer_ownership_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_team_V14(
    parser_context_t* c, pd_uniques_set_team_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_approve_transfer_V14(
    parser_context_t* c, pd_uniques_approve_transfer_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_cancel_approval_V14(
    parser_context_t* c, pd_uniques_cancel_approval_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->maybe_check_delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_force_item_status_V14(
    parser_context_t* c, pd_uniques_force_item_status_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    CHECK_ERROR(_readbool(c, &m->free_holding))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_attribute_V14(
    parser_context_t* c, pd_uniques_set_attribute_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readOptionItemId(c, &m->maybe_item))
    CHECK_ERROR(_readBoundedVecu8(c, &m->key))
    CHECK_ERROR(_readBoundedVecu8(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_attribute_V14(
    parser_context_t* c, pd_uniques_clear_attribute_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readOptionItemId(c, &m->maybe_item))
    CHECK_ERROR(_readBoundedVecu8(c, &m->key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_metadata_V14(
    parser_context_t* c, pd_uniques_set_metadata_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readBoundedVecu8(c, &m->data))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_metadata_V14(
    parser_context_t* c, pd_uniques_clear_metadata_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_collection_metadata_V14(
    parser_context_t* c, pd_uniques_set_collection_metadata_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readBoundedVecu8(c, &m->data))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_clear_collection_metadata_V14(
    parser_context_t* c, pd_uniques_clear_collection_metadata_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_accept_ownership_V14(
    parser_context_t* c, pd_uniques_set_accept_ownership_V14_t* m)
{
    CHECK_ERROR(_readOptionCollectionId(c, &m->maybe_collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_collection_max_supply_V14(
    parser_context_t* c, pd_uniques_set_collection_max_supply_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readu32(c, &m->max_supply))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_set_price_V14(
    parser_context_t* c, pd_uniques_set_price_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readOptionItemPrice(c, &m->price))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->whitelisted_buyer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_uniques_buy_item_V14(
    parser_context_t* c, pd_uniques_buy_item_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readItemPrice(c, &m->bid_price))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_create_V14(
    parser_context_t* c, pd_nfts_create_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readCollectionConfigFor(c, &m->config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_force_create_V14(
    parser_context_t* c, pd_nfts_force_create_V14_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readCollectionConfigFor(c, &m->config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_destroy_V14(
    parser_context_t* c, pd_nfts_destroy_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readDestroyWitness(c, &m->witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_mint_V14(
    parser_context_t* c, pd_nfts_mint_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->mint_to))
    CHECK_ERROR(_readOptionMintWitnessItemIdDepositBalanceOf(c, &m->witness_data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_force_mint_V14(
    parser_context_t* c, pd_nfts_force_mint_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->mint_to))
    CHECK_ERROR(_readItemConfig(c, &m->item_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_burn_V14(
    parser_context_t* c, pd_nfts_burn_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_transfer_V14(
    parser_context_t* c, pd_nfts_transfer_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_redeposit_V14(
    parser_context_t* c, pd_nfts_redeposit_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readVecItemId(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_lock_item_transfer_V14(
    parser_context_t* c, pd_nfts_lock_item_transfer_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_unlock_item_transfer_V14(
    parser_context_t* c, pd_nfts_unlock_item_transfer_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_lock_collection_V14(
    parser_context_t* c, pd_nfts_lock_collection_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readCollectionSettings(c, &m->lock_settings))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_transfer_ownership_V14(
    parser_context_t* c, pd_nfts_transfer_ownership_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_set_team_V14(
    parser_context_t* c, pd_nfts_set_team_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_force_collection_owner_V14(
    parser_context_t* c, pd_nfts_force_collection_owner_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_force_collection_config_V14(
    parser_context_t* c, pd_nfts_force_collection_config_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readCollectionConfigFor(c, &m->config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_approve_transfer_V14(
    parser_context_t* c, pd_nfts_approve_transfer_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readOptionBlockNumber(c, &m->maybe_deadline))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_cancel_approval_V14(
    parser_context_t* c, pd_nfts_cancel_approval_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_clear_all_transfer_approvals_V14(
    parser_context_t* c, pd_nfts_clear_all_transfer_approvals_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_lock_item_properties_V14(
    parser_context_t* c, pd_nfts_lock_item_properties_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readbool(c, &m->lock_metadata))
    CHECK_ERROR(_readbool(c, &m->lock_attributes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_set_attribute_V14(
    parser_context_t* c, pd_nfts_set_attribute_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readOptionItemId(c, &m->maybe_item))
    CHECK_ERROR(_readAttributeNamespaceAccountId(c, &m->namespace_))
    CHECK_ERROR(_readBoundedVecu8(c, &m->key))
    CHECK_ERROR(_readBoundedVecu8(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_force_set_attribute_V14(
    parser_context_t* c, pd_nfts_force_set_attribute_V14_t* m)
{
    CHECK_ERROR(_readOptionAccountId(c, &m->set_as))
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readOptionItemId(c, &m->maybe_item))
    CHECK_ERROR(_readAttributeNamespaceAccountId(c, &m->namespace_))
    CHECK_ERROR(_readBoundedVecu8(c, &m->key))
    CHECK_ERROR(_readBoundedVecu8(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_clear_attribute_V14(
    parser_context_t* c, pd_nfts_clear_attribute_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readOptionItemId(c, &m->maybe_item))
    CHECK_ERROR(_readAttributeNamespaceAccountId(c, &m->namespace_))
    CHECK_ERROR(_readBoundedVecu8(c, &m->key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_approve_item_attributes_V14(
    parser_context_t* c, pd_nfts_approve_item_attributes_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_cancel_item_attributes_approval_V14(
    parser_context_t* c, pd_nfts_cancel_item_attributes_approval_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readCancelAttributesApprovalWitness(c, &m->witness))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_set_metadata_V14(
    parser_context_t* c, pd_nfts_set_metadata_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readBoundedVecu8(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_clear_metadata_V14(
    parser_context_t* c, pd_nfts_clear_metadata_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_set_collection_metadata_V14(
    parser_context_t* c, pd_nfts_set_collection_metadata_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readBoundedVecu8(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_clear_collection_metadata_V14(
    parser_context_t* c, pd_nfts_clear_collection_metadata_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_set_accept_ownership_V14(
    parser_context_t* c, pd_nfts_set_accept_ownership_V14_t* m)
{
    CHECK_ERROR(_readOptionCollectionId(c, &m->maybe_collection))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_set_collection_max_supply_V14(
    parser_context_t* c, pd_nfts_set_collection_max_supply_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readu32(c, &m->max_supply))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_update_mint_settings_V14(
    parser_context_t* c, pd_nfts_update_mint_settings_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readMintSettings(c, &m->mint_settings))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_set_price_V14(
    parser_context_t* c, pd_nfts_set_price_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readOptionItemPrice(c, &m->price))
    CHECK_ERROR(_readOptionAccountIdLookupOfT(c, &m->whitelisted_buyer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_buy_item_V14(
    parser_context_t* c, pd_nfts_buy_item_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->collection))
    CHECK_ERROR(_readItemId(c, &m->item))
    CHECK_ERROR(_readItemPrice(c, &m->bid_price))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_pay_tips_V14(
    parser_context_t* c, pd_nfts_pay_tips_V14_t* m)
{
    CHECK_ERROR(_readVecItemTipOfMaxTips(c, &m->tips))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_create_swap_V14(
    parser_context_t* c, pd_nfts_create_swap_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->offered_collection))
    CHECK_ERROR(_readItemId(c, &m->offered_item))
    CHECK_ERROR(_readCollectionId(c, &m->desired_collection))
    CHECK_ERROR(_readOptionItemId(c, &m->maybe_desired_item))
    CHECK_ERROR(_readOptionPriceWithDirectionItemPrice(c, &m->maybe_price))
    CHECK_ERROR(_readBlockNumber(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_cancel_swap_V14(
    parser_context_t* c, pd_nfts_cancel_swap_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->offered_collection))
    CHECK_ERROR(_readItemId(c, &m->offered_item))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nfts_claim_swap_V14(
    parser_context_t* c, pd_nfts_claim_swap_V14_t* m)
{
    CHECK_ERROR(_readCollectionId(c, &m->send_collection))
    CHECK_ERROR(_readItemId(c, &m->send_item))
    CHECK_ERROR(_readCollectionId(c, &m->receive_collection))
    CHECK_ERROR(_readItemId(c, &m->receive_item))
    CHECK_ERROR(_readOptionPriceWithDirectionItemPrice(c, &m->witness_price))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nftfractionalization_fractionalize_V14(
    parser_context_t* c, pd_nftfractionalization_fractionalize_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->nft_collection_id))
    CHECK_ERROR(_readu32(c, &m->nft_id))
    CHECK_ERROR(_readu32(c, &m->asset_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    CHECK_ERROR(_readu128(c, &m->fractions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nftfractionalization_unify_V14(
    parser_context_t* c, pd_nftfractionalization_unify_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->nft_collection_id))
    CHECK_ERROR(_readu32(c, &m->nft_id))
    CHECK_ERROR(_readu32(c, &m->asset_id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_create_V14(
    parser_context_t* c, pd_poolassets_create_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_force_create_V14(
    parser_context_t* c, pd_poolassets_force_create_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_start_destroy_V14(
    parser_context_t* c, pd_poolassets_start_destroy_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_destroy_accounts_V14(
    parser_context_t* c, pd_poolassets_destroy_accounts_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_destroy_approvals_V14(
    parser_context_t* c, pd_poolassets_destroy_approvals_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_finish_destroy_V14(
    parser_context_t* c, pd_poolassets_finish_destroy_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_mint_V14(
    parser_context_t* c, pd_poolassets_mint_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_burn_V14(
    parser_context_t* c, pd_poolassets_burn_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_transfer_V14(
    parser_context_t* c, pd_poolassets_transfer_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_transfer_keep_alive_V14(
    parser_context_t* c, pd_poolassets_transfer_keep_alive_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_force_transfer_V14(
    parser_context_t* c, pd_poolassets_force_transfer_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_freeze_V14(
    parser_context_t* c, pd_poolassets_freeze_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_thaw_V14(
    parser_context_t* c, pd_poolassets_thaw_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_freeze_asset_V14(
    parser_context_t* c, pd_poolassets_freeze_asset_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_thaw_asset_V14(
    parser_context_t* c, pd_poolassets_thaw_asset_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_transfer_ownership_V14(
    parser_context_t* c, pd_poolassets_transfer_ownership_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_set_team_V14(
    parser_context_t* c, pd_poolassets_set_team_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_set_metadata_V14(
    parser_context_t* c, pd_poolassets_set_metadata_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_clear_metadata_V14(
    parser_context_t* c, pd_poolassets_clear_metadata_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_force_set_metadata_V14(
    parser_context_t* c, pd_poolassets_force_set_metadata_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_force_clear_metadata_V14(
    parser_context_t* c, pd_poolassets_force_clear_metadata_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_force_asset_status_V14(
    parser_context_t* c, pd_poolassets_force_asset_status_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_approve_transfer_V14(
    parser_context_t* c, pd_poolassets_approve_transfer_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_cancel_approval_V14(
    parser_context_t* c, pd_poolassets_cancel_approval_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_force_cancel_approval_V14(
    parser_context_t* c, pd_poolassets_force_cancel_approval_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_transfer_approved_V14(
    parser_context_t* c, pd_poolassets_transfer_approved_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->destination))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_touch_V14(
    parser_context_t* c, pd_poolassets_touch_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_refund_V14(
    parser_context_t* c, pd_poolassets_refund_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->allow_burn))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_set_min_balance_V14(
    parser_context_t* c, pd_poolassets_set_min_balance_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_touch_other_V14(
    parser_context_t* c, pd_poolassets_touch_other_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_refund_other_V14(
    parser_context_t* c, pd_poolassets_refund_other_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_poolassets_block_V14(
    parser_context_t* c, pd_poolassets_block_V14_t* m)
{
    CHECK_ERROR(_readu32(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V14(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V14_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V14(c, &method->nested.balances_force_transfer_V14))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V14(c, &method->nested.balances_transfer_keep_alive_V14))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V14(c, &method->nested.balances_transfer_all_V14))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V14(c, &method->nested.session_set_keys_V14))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V14(c, &method->nested.session_purge_keys_V14))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V14(c, &method->basic.utility_batch_V14))
        break;
    case 10242: /* module 40 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V14(c, &method->basic.utility_batch_all_V14))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_polkadotxcm_teleport_assets_V14(c, &method->basic.polkadotxcm_teleport_assets_V14))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_polkadotxcm_reserve_transfer_assets_V14(c, &method->basic.polkadotxcm_reserve_transfer_assets_V14))
        break;
    case 7944: /* module 31 call 8 */
        CHECK_ERROR(_readMethod_polkadotxcm_limited_reserve_transfer_assets_V14(c, &method->basic.polkadotxcm_limited_reserve_transfer_assets_V14))
        break;
    case 7945: /* module 31 call 9 */
        CHECK_ERROR(_readMethod_polkadotxcm_limited_teleport_assets_V14(c, &method->basic.polkadotxcm_limited_teleport_assets_V14))
        break;
    case 13568: /* module 53 call 0 */
        CHECK_ERROR(_readMethod_foreignassets_create_V14(c, &method->basic.foreignassets_create_V14))
        break;
    case 13569: /* module 53 call 1 */
        CHECK_ERROR(_readMethod_foreignassets_force_create_V14(c, &method->basic.foreignassets_force_create_V14))
        break;
    case 13570: /* module 53 call 2 */
        CHECK_ERROR(_readMethod_foreignassets_start_destroy_V14(c, &method->basic.foreignassets_start_destroy_V14))
        break;
    case 13571: /* module 53 call 3 */
        CHECK_ERROR(_readMethod_foreignassets_destroy_accounts_V14(c, &method->basic.foreignassets_destroy_accounts_V14))
        break;
    case 13572: /* module 53 call 4 */
        CHECK_ERROR(_readMethod_foreignassets_destroy_approvals_V14(c, &method->basic.foreignassets_destroy_approvals_V14))
        break;
    case 13573: /* module 53 call 5 */
        CHECK_ERROR(_readMethod_foreignassets_finish_destroy_V14(c, &method->basic.foreignassets_finish_destroy_V14))
        break;
    case 13574: /* module 53 call 6 */
        CHECK_ERROR(_readMethod_foreignassets_mint_V14(c, &method->basic.foreignassets_mint_V14))
        break;
    case 13575: /* module 53 call 7 */
        CHECK_ERROR(_readMethod_foreignassets_burn_V14(c, &method->basic.foreignassets_burn_V14))
        break;
    case 13576: /* module 53 call 8 */
        CHECK_ERROR(_readMethod_foreignassets_transfer_V14(c, &method->basic.foreignassets_transfer_V14))
        break;
    case 13577: /* module 53 call 9 */
        CHECK_ERROR(_readMethod_foreignassets_transfer_keep_alive_V14(c, &method->basic.foreignassets_transfer_keep_alive_V14))
        break;
    case 13578: /* module 53 call 10 */
        CHECK_ERROR(_readMethod_foreignassets_force_transfer_V14(c, &method->basic.foreignassets_force_transfer_V14))
        break;
    case 13579: /* module 53 call 11 */
        CHECK_ERROR(_readMethod_foreignassets_freeze_V14(c, &method->basic.foreignassets_freeze_V14))
        break;
    case 13580: /* module 53 call 12 */
        CHECK_ERROR(_readMethod_foreignassets_thaw_V14(c, &method->basic.foreignassets_thaw_V14))
        break;
    case 13581: /* module 53 call 13 */
        CHECK_ERROR(_readMethod_foreignassets_freeze_asset_V14(c, &method->basic.foreignassets_freeze_asset_V14))
        break;
    case 13582: /* module 53 call 14 */
        CHECK_ERROR(_readMethod_foreignassets_thaw_asset_V14(c, &method->basic.foreignassets_thaw_asset_V14))
        break;
    case 13583: /* module 53 call 15 */
        CHECK_ERROR(_readMethod_foreignassets_transfer_ownership_V14(c, &method->basic.foreignassets_transfer_ownership_V14))
        break;
    case 13584: /* module 53 call 16 */
        CHECK_ERROR(_readMethod_foreignassets_set_team_V14(c, &method->basic.foreignassets_set_team_V14))
        break;
    case 13585: /* module 53 call 17 */
        CHECK_ERROR(_readMethod_foreignassets_set_metadata_V14(c, &method->basic.foreignassets_set_metadata_V14))
        break;
    case 13586: /* module 53 call 18 */
        CHECK_ERROR(_readMethod_foreignassets_clear_metadata_V14(c, &method->basic.foreignassets_clear_metadata_V14))
        break;
    case 13587: /* module 53 call 19 */
        CHECK_ERROR(_readMethod_foreignassets_force_set_metadata_V14(c, &method->basic.foreignassets_force_set_metadata_V14))
        break;
    case 13588: /* module 53 call 20 */
        CHECK_ERROR(_readMethod_foreignassets_force_clear_metadata_V14(c, &method->basic.foreignassets_force_clear_metadata_V14))
        break;
    case 13589: /* module 53 call 21 */
        CHECK_ERROR(_readMethod_foreignassets_force_asset_status_V14(c, &method->basic.foreignassets_force_asset_status_V14))
        break;
    case 13590: /* module 53 call 22 */
        CHECK_ERROR(_readMethod_foreignassets_approve_transfer_V14(c, &method->basic.foreignassets_approve_transfer_V14))
        break;
    case 13591: /* module 53 call 23 */
        CHECK_ERROR(_readMethod_foreignassets_cancel_approval_V14(c, &method->basic.foreignassets_cancel_approval_V14))
        break;
    case 13592: /* module 53 call 24 */
        CHECK_ERROR(_readMethod_foreignassets_force_cancel_approval_V14(c, &method->basic.foreignassets_force_cancel_approval_V14))
        break;
    case 13593: /* module 53 call 25 */
        CHECK_ERROR(_readMethod_foreignassets_transfer_approved_V14(c, &method->basic.foreignassets_transfer_approved_V14))
        break;
    case 13594: /* module 53 call 26 */
        CHECK_ERROR(_readMethod_foreignassets_touch_V14(c, &method->basic.foreignassets_touch_V14))
        break;
    case 13595: /* module 53 call 27 */
        CHECK_ERROR(_readMethod_foreignassets_refund_V14(c, &method->basic.foreignassets_refund_V14))
        break;
    case 13596: /* module 53 call 28 */
        CHECK_ERROR(_readMethod_foreignassets_set_min_balance_V14(c, &method->basic.foreignassets_set_min_balance_V14))
        break;
    case 13597: /* module 53 call 29 */
        CHECK_ERROR(_readMethod_foreignassets_touch_other_V14(c, &method->basic.foreignassets_touch_other_V14))
        break;
    case 13598: /* module 53 call 30 */
        CHECK_ERROR(_readMethod_foreignassets_refund_other_V14(c, &method->basic.foreignassets_refund_other_V14))
        break;
    case 13599: /* module 53 call 31 */
        CHECK_ERROR(_readMethod_foreignassets_block_V14(c, &method->basic.foreignassets_block_V14))
        break;
    case 14336: /* module 56 call 0 */
        CHECK_ERROR(_readMethod_assetconversion_create_pool_V14(c, &method->basic.assetconversion_create_pool_V14))
        break;
    case 14337: /* module 56 call 1 */
        CHECK_ERROR(_readMethod_assetconversion_add_liquidity_V14(c, &method->basic.assetconversion_add_liquidity_V14))
        break;
    case 14338: /* module 56 call 2 */
        CHECK_ERROR(_readMethod_assetconversion_remove_liquidity_V14(c, &method->basic.assetconversion_remove_liquidity_V14))
        break;
    case 14339: /* module 56 call 3 */
        CHECK_ERROR(_readMethod_assetconversion_swap_exact_tokens_for_tokens_V14(c, &method->basic.assetconversion_swap_exact_tokens_for_tokens_V14))
        break;
    case 14340: /* module 56 call 4 */
        CHECK_ERROR(_readMethod_assetconversion_swap_tokens_for_exact_tokens_V14(c, &method->basic.assetconversion_swap_tokens_for_exact_tokens_V14))
        break;
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V14(c, &method->nested.system_remark_V14))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V14(c, &method->nested.system_set_heap_pages_V14))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_code_V14(c, &method->nested.system_set_code_V14))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V14(c, &method->nested.system_set_code_without_checks_V14))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V14(c, &method->nested.system_remark_with_event_V14))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V14(c, &method->basic.timestamp_set_V14))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_allow_death_V14(c, &method->nested.balances_transfer_allow_death_V14))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V14(c, &method->basic.balances_force_unreserve_V14))
        break;
    case 2566: /* module 10 call 6 */
        CHECK_ERROR(_readMethod_balances_upgrade_accounts_V14(c, &method->basic.balances_upgrade_accounts_V14))
        break;
    case 2568: /* module 10 call 8 */
        CHECK_ERROR(_readMethod_balances_force_set_balance_V14(c, &method->basic.balances_force_set_balance_V14))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_collatorselection_set_invulnerables_V14(c, &method->basic.collatorselection_set_invulnerables_V14))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_collatorselection_set_desired_candidates_V14(c, &method->basic.collatorselection_set_desired_candidates_V14))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_collatorselection_set_candidacy_bond_V14(c, &method->basic.collatorselection_set_candidacy_bond_V14))
        break;
    case 5379: /* module 21 call 3 */
        CHECK_ERROR(_readMethod_collatorselection_register_as_candidate_V14(c, &method->basic.collatorselection_register_as_candidate_V14))
        break;
    case 5380: /* module 21 call 4 */
        CHECK_ERROR(_readMethod_collatorselection_leave_intent_V14(c, &method->basic.collatorselection_leave_intent_V14))
        break;
    case 5381: /* module 21 call 5 */
        CHECK_ERROR(_readMethod_collatorselection_add_invulnerable_V14(c, &method->basic.collatorselection_add_invulnerable_V14))
        break;
    case 5382: /* module 21 call 6 */
        CHECK_ERROR(_readMethod_collatorselection_remove_invulnerable_V14(c, &method->basic.collatorselection_remove_invulnerable_V14))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_xcmpqueue_service_overweight_V14(c, &method->basic.xcmpqueue_service_overweight_V14))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_xcmpqueue_suspend_xcm_execution_V14(c, &method->basic.xcmpqueue_suspend_xcm_execution_V14))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_xcmpqueue_resume_xcm_execution_V14(c, &method->basic.xcmpqueue_resume_xcm_execution_V14))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_suspend_threshold_V14(c, &method->basic.xcmpqueue_update_suspend_threshold_V14))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_drop_threshold_V14(c, &method->basic.xcmpqueue_update_drop_threshold_V14))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_resume_threshold_V14(c, &method->basic.xcmpqueue_update_resume_threshold_V14))
        break;
    case 7686: /* module 30 call 6 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_threshold_weight_V14(c, &method->basic.xcmpqueue_update_threshold_weight_V14))
        break;
    case 7687: /* module 30 call 7 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_weight_restrict_decay_V14(c, &method->basic.xcmpqueue_update_weight_restrict_decay_V14))
        break;
    case 7688: /* module 30 call 8 */
        CHECK_ERROR(_readMethod_xcmpqueue_update_xcmp_max_individual_weight_V14(c, &method->basic.xcmpqueue_update_xcmp_max_individual_weight_V14))
        break;
    case 8448: /* module 33 call 0 */
        CHECK_ERROR(_readMethod_dmpqueue_service_overweight_V14(c, &method->basic.dmpqueue_service_overweight_V14))
        break;
    case 10244: /* module 40 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V14(c, &method->basic.utility_force_batch_V14))
        break;
    case 10245: /* module 40 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V14(c, &method->basic.utility_with_weight_V14))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V14(c, &method->nested.multisig_as_multi_threshold_1_V14))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V14(c, &method->nested.multisig_as_multi_V14))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V14(c, &method->nested.multisig_approve_as_multi_V14))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V14(c, &method->nested.multisig_cancel_as_multi_V14))
        break;
    case 10752: /* module 42 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V14(c, &method->nested.proxy_proxy_V14))
        break;
    case 10753: /* module 42 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V14(c, &method->nested.proxy_add_proxy_V14))
        break;
    case 10754: /* module 42 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V14(c, &method->nested.proxy_remove_proxy_V14))
        break;
    case 10755: /* module 42 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V14(c, &method->basic.proxy_remove_proxies_V14))
        break;
    case 10756: /* module 42 call 4 */
        CHECK_ERROR(_readMethod_proxy_create_pure_V14(c, &method->nested.proxy_create_pure_V14))
        break;
    case 10757: /* module 42 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_pure_V14(c, &method->nested.proxy_kill_pure_V14))
        break;
    case 10758: /* module 42 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V14(c, &method->basic.proxy_announce_V14))
        break;
    case 10759: /* module 42 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V14(c, &method->basic.proxy_remove_announcement_V14))
        break;
    case 10760: /* module 42 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V14(c, &method->basic.proxy_reject_announcement_V14))
        break;
    case 10761: /* module 42 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V14(c, &method->basic.proxy_proxy_announced_V14))
        break;
    case 12800: /* module 50 call 0 */
        CHECK_ERROR(_readMethod_assets_create_V14(c, &method->nested.assets_create_V14))
        break;
    case 12801: /* module 50 call 1 */
        CHECK_ERROR(_readMethod_assets_force_create_V14(c, &method->nested.assets_force_create_V14))
        break;
    case 12802: /* module 50 call 2 */
        CHECK_ERROR(_readMethod_assets_start_destroy_V14(c, &method->basic.assets_start_destroy_V14))
        break;
    case 12803: /* module 50 call 3 */
        CHECK_ERROR(_readMethod_assets_destroy_accounts_V14(c, &method->basic.assets_destroy_accounts_V14))
        break;
    case 12804: /* module 50 call 4 */
        CHECK_ERROR(_readMethod_assets_destroy_approvals_V14(c, &method->basic.assets_destroy_approvals_V14))
        break;
    case 12805: /* module 50 call 5 */
        CHECK_ERROR(_readMethod_assets_finish_destroy_V14(c, &method->basic.assets_finish_destroy_V14))
        break;
    case 12806: /* module 50 call 6 */
        CHECK_ERROR(_readMethod_assets_mint_V14(c, &method->nested.assets_mint_V14))
        break;
    case 12807: /* module 50 call 7 */
        CHECK_ERROR(_readMethod_assets_burn_V14(c, &method->nested.assets_burn_V14))
        break;
    case 12808: /* module 50 call 8 */
        CHECK_ERROR(_readMethod_assets_transfer_V14(c, &method->nested.assets_transfer_V14))
        break;
    case 12809: /* module 50 call 9 */
        CHECK_ERROR(_readMethod_assets_transfer_keep_alive_V14(c, &method->nested.assets_transfer_keep_alive_V14))
        break;
    case 12810: /* module 50 call 10 */
        CHECK_ERROR(_readMethod_assets_force_transfer_V14(c, &method->nested.assets_force_transfer_V14))
        break;
    case 12811: /* module 50 call 11 */
        CHECK_ERROR(_readMethod_assets_freeze_V14(c, &method->nested.assets_freeze_V14))
        break;
    case 12812: /* module 50 call 12 */
        CHECK_ERROR(_readMethod_assets_thaw_V14(c, &method->nested.assets_thaw_V14))
        break;
    case 12813: /* module 50 call 13 */
        CHECK_ERROR(_readMethod_assets_freeze_asset_V14(c, &method->nested.assets_freeze_asset_V14))
        break;
    case 12814: /* module 50 call 14 */
        CHECK_ERROR(_readMethod_assets_thaw_asset_V14(c, &method->nested.assets_thaw_asset_V14))
        break;
    case 12815: /* module 50 call 15 */
        CHECK_ERROR(_readMethod_assets_transfer_ownership_V14(c, &method->nested.assets_transfer_ownership_V14))
        break;
    case 12816: /* module 50 call 16 */
        CHECK_ERROR(_readMethod_assets_set_team_V14(c, &method->nested.assets_set_team_V14))
        break;
    case 12817: /* module 50 call 17 */
        CHECK_ERROR(_readMethod_assets_set_metadata_V14(c, &method->nested.assets_set_metadata_V14))
        break;
    case 12818: /* module 50 call 18 */
        CHECK_ERROR(_readMethod_assets_clear_metadata_V14(c, &method->nested.assets_clear_metadata_V14))
        break;
    case 12819: /* module 50 call 19 */
        CHECK_ERROR(_readMethod_assets_force_set_metadata_V14(c, &method->nested.assets_force_set_metadata_V14))
        break;
    case 12820: /* module 50 call 20 */
        CHECK_ERROR(_readMethod_assets_force_clear_metadata_V14(c, &method->nested.assets_force_clear_metadata_V14))
        break;
    case 12821: /* module 50 call 21 */
        CHECK_ERROR(_readMethod_assets_force_asset_status_V14(c, &method->nested.assets_force_asset_status_V14))
        break;
    case 12822: /* module 50 call 22 */
        CHECK_ERROR(_readMethod_assets_approve_transfer_V14(c, &method->nested.assets_approve_transfer_V14))
        break;
    case 12823: /* module 50 call 23 */
        CHECK_ERROR(_readMethod_assets_cancel_approval_V14(c, &method->nested.assets_cancel_approval_V14))
        break;
    case 12824: /* module 50 call 24 */
        CHECK_ERROR(_readMethod_assets_force_cancel_approval_V14(c, &method->nested.assets_force_cancel_approval_V14))
        break;
    case 12825: /* module 50 call 25 */
        CHECK_ERROR(_readMethod_assets_transfer_approved_V14(c, &method->nested.assets_transfer_approved_V14))
        break;
    case 12826: /* module 50 call 26 */
        CHECK_ERROR(_readMethod_assets_touch_V14(c, &method->basic.assets_touch_V14))
        break;
    case 12827: /* module 50 call 27 */
        CHECK_ERROR(_readMethod_assets_refund_V14(c, &method->basic.assets_refund_V14))
        break;
    case 12828: /* module 50 call 28 */
        CHECK_ERROR(_readMethod_assets_set_min_balance_V14(c, &method->basic.assets_set_min_balance_V14))
        break;
    case 12829: /* module 50 call 29 */
        CHECK_ERROR(_readMethod_assets_touch_other_V14(c, &method->basic.assets_touch_other_V14))
        break;
    case 12830: /* module 50 call 30 */
        CHECK_ERROR(_readMethod_assets_refund_other_V14(c, &method->basic.assets_refund_other_V14))
        break;
    case 12831: /* module 50 call 31 */
        CHECK_ERROR(_readMethod_assets_block_V14(c, &method->basic.assets_block_V14))
        break;
    case 13056: /* module 51 call 0 */
        CHECK_ERROR(_readMethod_uniques_create_V14(c, &method->basic.uniques_create_V14))
        break;
    case 13057: /* module 51 call 1 */
        CHECK_ERROR(_readMethod_uniques_force_create_V14(c, &method->basic.uniques_force_create_V14))
        break;
    case 13058: /* module 51 call 2 */
        CHECK_ERROR(_readMethod_uniques_destroy_V14(c, &method->basic.uniques_destroy_V14))
        break;
    case 13059: /* module 51 call 3 */
        CHECK_ERROR(_readMethod_uniques_mint_V14(c, &method->basic.uniques_mint_V14))
        break;
    case 13060: /* module 51 call 4 */
        CHECK_ERROR(_readMethod_uniques_burn_V14(c, &method->basic.uniques_burn_V14))
        break;
    case 13061: /* module 51 call 5 */
        CHECK_ERROR(_readMethod_uniques_transfer_V14(c, &method->basic.uniques_transfer_V14))
        break;
    case 13062: /* module 51 call 6 */
        CHECK_ERROR(_readMethod_uniques_redeposit_V14(c, &method->basic.uniques_redeposit_V14))
        break;
    case 13063: /* module 51 call 7 */
        CHECK_ERROR(_readMethod_uniques_freeze_V14(c, &method->basic.uniques_freeze_V14))
        break;
    case 13064: /* module 51 call 8 */
        CHECK_ERROR(_readMethod_uniques_thaw_V14(c, &method->basic.uniques_thaw_V14))
        break;
    case 13065: /* module 51 call 9 */
        CHECK_ERROR(_readMethod_uniques_freeze_collection_V14(c, &method->basic.uniques_freeze_collection_V14))
        break;
    case 13066: /* module 51 call 10 */
        CHECK_ERROR(_readMethod_uniques_thaw_collection_V14(c, &method->basic.uniques_thaw_collection_V14))
        break;
    case 13067: /* module 51 call 11 */
        CHECK_ERROR(_readMethod_uniques_transfer_ownership_V14(c, &method->basic.uniques_transfer_ownership_V14))
        break;
    case 13068: /* module 51 call 12 */
        CHECK_ERROR(_readMethod_uniques_set_team_V14(c, &method->basic.uniques_set_team_V14))
        break;
    case 13069: /* module 51 call 13 */
        CHECK_ERROR(_readMethod_uniques_approve_transfer_V14(c, &method->basic.uniques_approve_transfer_V14))
        break;
    case 13070: /* module 51 call 14 */
        CHECK_ERROR(_readMethod_uniques_cancel_approval_V14(c, &method->basic.uniques_cancel_approval_V14))
        break;
    case 13071: /* module 51 call 15 */
        CHECK_ERROR(_readMethod_uniques_force_item_status_V14(c, &method->basic.uniques_force_item_status_V14))
        break;
    case 13072: /* module 51 call 16 */
        CHECK_ERROR(_readMethod_uniques_set_attribute_V14(c, &method->basic.uniques_set_attribute_V14))
        break;
    case 13073: /* module 51 call 17 */
        CHECK_ERROR(_readMethod_uniques_clear_attribute_V14(c, &method->basic.uniques_clear_attribute_V14))
        break;
    case 13074: /* module 51 call 18 */
        CHECK_ERROR(_readMethod_uniques_set_metadata_V14(c, &method->basic.uniques_set_metadata_V14))
        break;
    case 13075: /* module 51 call 19 */
        CHECK_ERROR(_readMethod_uniques_clear_metadata_V14(c, &method->basic.uniques_clear_metadata_V14))
        break;
    case 13076: /* module 51 call 20 */
        CHECK_ERROR(_readMethod_uniques_set_collection_metadata_V14(c, &method->basic.uniques_set_collection_metadata_V14))
        break;
    case 13077: /* module 51 call 21 */
        CHECK_ERROR(_readMethod_uniques_clear_collection_metadata_V14(c, &method->basic.uniques_clear_collection_metadata_V14))
        break;
    case 13078: /* module 51 call 22 */
        CHECK_ERROR(_readMethod_uniques_set_accept_ownership_V14(c, &method->basic.uniques_set_accept_ownership_V14))
        break;
    case 13079: /* module 51 call 23 */
        CHECK_ERROR(_readMethod_uniques_set_collection_max_supply_V14(c, &method->basic.uniques_set_collection_max_supply_V14))
        break;
    case 13080: /* module 51 call 24 */
        CHECK_ERROR(_readMethod_uniques_set_price_V14(c, &method->basic.uniques_set_price_V14))
        break;
    case 13081: /* module 51 call 25 */
        CHECK_ERROR(_readMethod_uniques_buy_item_V14(c, &method->basic.uniques_buy_item_V14))
        break;
    case 13312: /* module 52 call 0 */
        CHECK_ERROR(_readMethod_nfts_create_V14(c, &method->basic.nfts_create_V14))
        break;
    case 13313: /* module 52 call 1 */
        CHECK_ERROR(_readMethod_nfts_force_create_V14(c, &method->basic.nfts_force_create_V14))
        break;
    case 13314: /* module 52 call 2 */
        CHECK_ERROR(_readMethod_nfts_destroy_V14(c, &method->basic.nfts_destroy_V14))
        break;
    case 13315: /* module 52 call 3 */
        CHECK_ERROR(_readMethod_nfts_mint_V14(c, &method->basic.nfts_mint_V14))
        break;
    case 13316: /* module 52 call 4 */
        CHECK_ERROR(_readMethod_nfts_force_mint_V14(c, &method->basic.nfts_force_mint_V14))
        break;
    case 13317: /* module 52 call 5 */
        CHECK_ERROR(_readMethod_nfts_burn_V14(c, &method->basic.nfts_burn_V14))
        break;
    case 13318: /* module 52 call 6 */
        CHECK_ERROR(_readMethod_nfts_transfer_V14(c, &method->basic.nfts_transfer_V14))
        break;
    case 13319: /* module 52 call 7 */
        CHECK_ERROR(_readMethod_nfts_redeposit_V14(c, &method->basic.nfts_redeposit_V14))
        break;
    case 13320: /* module 52 call 8 */
        CHECK_ERROR(_readMethod_nfts_lock_item_transfer_V14(c, &method->basic.nfts_lock_item_transfer_V14))
        break;
    case 13321: /* module 52 call 9 */
        CHECK_ERROR(_readMethod_nfts_unlock_item_transfer_V14(c, &method->basic.nfts_unlock_item_transfer_V14))
        break;
    case 13322: /* module 52 call 10 */
        CHECK_ERROR(_readMethod_nfts_lock_collection_V14(c, &method->basic.nfts_lock_collection_V14))
        break;
    case 13323: /* module 52 call 11 */
        CHECK_ERROR(_readMethod_nfts_transfer_ownership_V14(c, &method->basic.nfts_transfer_ownership_V14))
        break;
    case 13324: /* module 52 call 12 */
        CHECK_ERROR(_readMethod_nfts_set_team_V14(c, &method->basic.nfts_set_team_V14))
        break;
    case 13325: /* module 52 call 13 */
        CHECK_ERROR(_readMethod_nfts_force_collection_owner_V14(c, &method->basic.nfts_force_collection_owner_V14))
        break;
    case 13326: /* module 52 call 14 */
        CHECK_ERROR(_readMethod_nfts_force_collection_config_V14(c, &method->basic.nfts_force_collection_config_V14))
        break;
    case 13327: /* module 52 call 15 */
        CHECK_ERROR(_readMethod_nfts_approve_transfer_V14(c, &method->basic.nfts_approve_transfer_V14))
        break;
    case 13328: /* module 52 call 16 */
        CHECK_ERROR(_readMethod_nfts_cancel_approval_V14(c, &method->basic.nfts_cancel_approval_V14))
        break;
    case 13329: /* module 52 call 17 */
        CHECK_ERROR(_readMethod_nfts_clear_all_transfer_approvals_V14(c, &method->basic.nfts_clear_all_transfer_approvals_V14))
        break;
    case 13330: /* module 52 call 18 */
        CHECK_ERROR(_readMethod_nfts_lock_item_properties_V14(c, &method->basic.nfts_lock_item_properties_V14))
        break;
    case 13331: /* module 52 call 19 */
        CHECK_ERROR(_readMethod_nfts_set_attribute_V14(c, &method->basic.nfts_set_attribute_V14))
        break;
    case 13332: /* module 52 call 20 */
        CHECK_ERROR(_readMethod_nfts_force_set_attribute_V14(c, &method->basic.nfts_force_set_attribute_V14))
        break;
    case 13333: /* module 52 call 21 */
        CHECK_ERROR(_readMethod_nfts_clear_attribute_V14(c, &method->basic.nfts_clear_attribute_V14))
        break;
    case 13334: /* module 52 call 22 */
        CHECK_ERROR(_readMethod_nfts_approve_item_attributes_V14(c, &method->basic.nfts_approve_item_attributes_V14))
        break;
    case 13335: /* module 52 call 23 */
        CHECK_ERROR(_readMethod_nfts_cancel_item_attributes_approval_V14(c, &method->basic.nfts_cancel_item_attributes_approval_V14))
        break;
    case 13336: /* module 52 call 24 */
        CHECK_ERROR(_readMethod_nfts_set_metadata_V14(c, &method->basic.nfts_set_metadata_V14))
        break;
    case 13337: /* module 52 call 25 */
        CHECK_ERROR(_readMethod_nfts_clear_metadata_V14(c, &method->basic.nfts_clear_metadata_V14))
        break;
    case 13338: /* module 52 call 26 */
        CHECK_ERROR(_readMethod_nfts_set_collection_metadata_V14(c, &method->basic.nfts_set_collection_metadata_V14))
        break;
    case 13339: /* module 52 call 27 */
        CHECK_ERROR(_readMethod_nfts_clear_collection_metadata_V14(c, &method->basic.nfts_clear_collection_metadata_V14))
        break;
    case 13340: /* module 52 call 28 */
        CHECK_ERROR(_readMethod_nfts_set_accept_ownership_V14(c, &method->basic.nfts_set_accept_ownership_V14))
        break;
    case 13341: /* module 52 call 29 */
        CHECK_ERROR(_readMethod_nfts_set_collection_max_supply_V14(c, &method->basic.nfts_set_collection_max_supply_V14))
        break;
    case 13342: /* module 52 call 30 */
        CHECK_ERROR(_readMethod_nfts_update_mint_settings_V14(c, &method->basic.nfts_update_mint_settings_V14))
        break;
    case 13343: /* module 52 call 31 */
        CHECK_ERROR(_readMethod_nfts_set_price_V14(c, &method->basic.nfts_set_price_V14))
        break;
    case 13344: /* module 52 call 32 */
        CHECK_ERROR(_readMethod_nfts_buy_item_V14(c, &method->basic.nfts_buy_item_V14))
        break;
    case 13345: /* module 52 call 33 */
        CHECK_ERROR(_readMethod_nfts_pay_tips_V14(c, &method->basic.nfts_pay_tips_V14))
        break;
    case 13346: /* module 52 call 34 */
        CHECK_ERROR(_readMethod_nfts_create_swap_V14(c, &method->basic.nfts_create_swap_V14))
        break;
    case 13347: /* module 52 call 35 */
        CHECK_ERROR(_readMethod_nfts_cancel_swap_V14(c, &method->basic.nfts_cancel_swap_V14))
        break;
    case 13348: /* module 52 call 36 */
        CHECK_ERROR(_readMethod_nfts_claim_swap_V14(c, &method->basic.nfts_claim_swap_V14))
        break;
    case 13824: /* module 54 call 0 */
        CHECK_ERROR(_readMethod_nftfractionalization_fractionalize_V14(c, &method->basic.nftfractionalization_fractionalize_V14))
        break;
    case 13825: /* module 54 call 1 */
        CHECK_ERROR(_readMethod_nftfractionalization_unify_V14(c, &method->basic.nftfractionalization_unify_V14))
        break;
    case 14080: /* module 55 call 0 */
        CHECK_ERROR(_readMethod_poolassets_create_V14(c, &method->basic.poolassets_create_V14))
        break;
    case 14081: /* module 55 call 1 */
        CHECK_ERROR(_readMethod_poolassets_force_create_V14(c, &method->basic.poolassets_force_create_V14))
        break;
    case 14082: /* module 55 call 2 */
        CHECK_ERROR(_readMethod_poolassets_start_destroy_V14(c, &method->basic.poolassets_start_destroy_V14))
        break;
    case 14083: /* module 55 call 3 */
        CHECK_ERROR(_readMethod_poolassets_destroy_accounts_V14(c, &method->basic.poolassets_destroy_accounts_V14))
        break;
    case 14084: /* module 55 call 4 */
        CHECK_ERROR(_readMethod_poolassets_destroy_approvals_V14(c, &method->basic.poolassets_destroy_approvals_V14))
        break;
    case 14085: /* module 55 call 5 */
        CHECK_ERROR(_readMethod_poolassets_finish_destroy_V14(c, &method->basic.poolassets_finish_destroy_V14))
        break;
    case 14086: /* module 55 call 6 */
        CHECK_ERROR(_readMethod_poolassets_mint_V14(c, &method->basic.poolassets_mint_V14))
        break;
    case 14087: /* module 55 call 7 */
        CHECK_ERROR(_readMethod_poolassets_burn_V14(c, &method->basic.poolassets_burn_V14))
        break;
    case 14088: /* module 55 call 8 */
        CHECK_ERROR(_readMethod_poolassets_transfer_V14(c, &method->basic.poolassets_transfer_V14))
        break;
    case 14089: /* module 55 call 9 */
        CHECK_ERROR(_readMethod_poolassets_transfer_keep_alive_V14(c, &method->basic.poolassets_transfer_keep_alive_V14))
        break;
    case 14090: /* module 55 call 10 */
        CHECK_ERROR(_readMethod_poolassets_force_transfer_V14(c, &method->basic.poolassets_force_transfer_V14))
        break;
    case 14091: /* module 55 call 11 */
        CHECK_ERROR(_readMethod_poolassets_freeze_V14(c, &method->basic.poolassets_freeze_V14))
        break;
    case 14092: /* module 55 call 12 */
        CHECK_ERROR(_readMethod_poolassets_thaw_V14(c, &method->basic.poolassets_thaw_V14))
        break;
    case 14093: /* module 55 call 13 */
        CHECK_ERROR(_readMethod_poolassets_freeze_asset_V14(c, &method->basic.poolassets_freeze_asset_V14))
        break;
    case 14094: /* module 55 call 14 */
        CHECK_ERROR(_readMethod_poolassets_thaw_asset_V14(c, &method->basic.poolassets_thaw_asset_V14))
        break;
    case 14095: /* module 55 call 15 */
        CHECK_ERROR(_readMethod_poolassets_transfer_ownership_V14(c, &method->basic.poolassets_transfer_ownership_V14))
        break;
    case 14096: /* module 55 call 16 */
        CHECK_ERROR(_readMethod_poolassets_set_team_V14(c, &method->basic.poolassets_set_team_V14))
        break;
    case 14097: /* module 55 call 17 */
        CHECK_ERROR(_readMethod_poolassets_set_metadata_V14(c, &method->basic.poolassets_set_metadata_V14))
        break;
    case 14098: /* module 55 call 18 */
        CHECK_ERROR(_readMethod_poolassets_clear_metadata_V14(c, &method->basic.poolassets_clear_metadata_V14))
        break;
    case 14099: /* module 55 call 19 */
        CHECK_ERROR(_readMethod_poolassets_force_set_metadata_V14(c, &method->basic.poolassets_force_set_metadata_V14))
        break;
    case 14100: /* module 55 call 20 */
        CHECK_ERROR(_readMethod_poolassets_force_clear_metadata_V14(c, &method->basic.poolassets_force_clear_metadata_V14))
        break;
    case 14101: /* module 55 call 21 */
        CHECK_ERROR(_readMethod_poolassets_force_asset_status_V14(c, &method->basic.poolassets_force_asset_status_V14))
        break;
    case 14102: /* module 55 call 22 */
        CHECK_ERROR(_readMethod_poolassets_approve_transfer_V14(c, &method->basic.poolassets_approve_transfer_V14))
        break;
    case 14103: /* module 55 call 23 */
        CHECK_ERROR(_readMethod_poolassets_cancel_approval_V14(c, &method->basic.poolassets_cancel_approval_V14))
        break;
    case 14104: /* module 55 call 24 */
        CHECK_ERROR(_readMethod_poolassets_force_cancel_approval_V14(c, &method->basic.poolassets_force_cancel_approval_V14))
        break;
    case 14105: /* module 55 call 25 */
        CHECK_ERROR(_readMethod_poolassets_transfer_approved_V14(c, &method->basic.poolassets_transfer_approved_V14))
        break;
    case 14106: /* module 55 call 26 */
        CHECK_ERROR(_readMethod_poolassets_touch_V14(c, &method->basic.poolassets_touch_V14))
        break;
    case 14107: /* module 55 call 27 */
        CHECK_ERROR(_readMethod_poolassets_refund_V14(c, &method->basic.poolassets_refund_V14))
        break;
    case 14108: /* module 55 call 28 */
        CHECK_ERROR(_readMethod_poolassets_set_min_balance_V14(c, &method->basic.poolassets_set_min_balance_V14))
        break;
    case 14109: /* module 55 call 29 */
        CHECK_ERROR(_readMethod_poolassets_touch_other_V14(c, &method->basic.poolassets_touch_other_V14))
        break;
    case 14110: /* module 55 call 30 */
        CHECK_ERROR(_readMethod_poolassets_refund_other_V14(c, &method->basic.poolassets_refund_other_V14))
        break;
    case 14111: /* module 55 call 31 */
        CHECK_ERROR(_readMethod_poolassets_block_V14(c, &method->basic.poolassets_block_V14))
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

const char* _getMethod_ModuleName_V14(uint8_t moduleIdx)
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
    case 53:
        return STR_MO_FOREIGNASSETS;
    case 56:
        return STR_MO_ASSETCONVERSION;
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
    case 52:
        return STR_MO_NFTS;
    case 54:
        return STR_MO_NFTFRACTIONALIZATION;
    case 55:
        return STR_MO_POOLASSETS;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V14(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
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
        return _getMethod_Name_V14_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V14_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 7937: /* module 31 call 1 */
        return STR_ME_TELEPORT_ASSETS;
    case 7938: /* module 31 call 2 */
        return STR_ME_RESERVE_TRANSFER_ASSETS;
    case 7944: /* module 31 call 8 */
        return STR_ME_LIMITED_RESERVE_TRANSFER_ASSETS;
    case 7945: /* module 31 call 9 */
        return STR_ME_LIMITED_TELEPORT_ASSETS;
    case 13568: /* module 53 call 0 */
        return STR_ME_CREATE;
    case 13569: /* module 53 call 1 */
        return STR_ME_FORCE_CREATE;
    case 13570: /* module 53 call 2 */
        return STR_ME_START_DESTROY;
    case 13571: /* module 53 call 3 */
        return STR_ME_DESTROY_ACCOUNTS;
    case 13572: /* module 53 call 4 */
        return STR_ME_DESTROY_APPROVALS;
    case 13573: /* module 53 call 5 */
        return STR_ME_FINISH_DESTROY;
    case 13574: /* module 53 call 6 */
        return STR_ME_MINT;
    case 13575: /* module 53 call 7 */
        return STR_ME_BURN;
    case 13576: /* module 53 call 8 */
        return STR_ME_TRANSFER;
    case 13577: /* module 53 call 9 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 13578: /* module 53 call 10 */
        return STR_ME_FORCE_TRANSFER;
    case 13579: /* module 53 call 11 */
        return STR_ME_FREEZE;
    case 13580: /* module 53 call 12 */
        return STR_ME_THAW;
    case 13581: /* module 53 call 13 */
        return STR_ME_FREEZE_ASSET;
    case 13582: /* module 53 call 14 */
        return STR_ME_THAW_ASSET;
    case 13583: /* module 53 call 15 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 13584: /* module 53 call 16 */
        return STR_ME_SET_TEAM;
    case 13585: /* module 53 call 17 */
        return STR_ME_SET_METADATA;
    case 13586: /* module 53 call 18 */
        return STR_ME_CLEAR_METADATA;
    case 13587: /* module 53 call 19 */
        return STR_ME_FORCE_SET_METADATA;
    case 13588: /* module 53 call 20 */
        return STR_ME_FORCE_CLEAR_METADATA;
    case 13589: /* module 53 call 21 */
        return STR_ME_FORCE_ASSET_STATUS;
    case 13590: /* module 53 call 22 */
        return STR_ME_APPROVE_TRANSFER;
    case 13591: /* module 53 call 23 */
        return STR_ME_CANCEL_APPROVAL;
    case 13592: /* module 53 call 24 */
        return STR_ME_FORCE_CANCEL_APPROVAL;
    case 13593: /* module 53 call 25 */
        return STR_ME_TRANSFER_APPROVED;
    case 13594: /* module 53 call 26 */
        return STR_ME_TOUCH;
    case 13595: /* module 53 call 27 */
        return STR_ME_REFUND;
    case 13596: /* module 53 call 28 */
        return STR_ME_SET_MIN_BALANCE;
    case 13597: /* module 53 call 29 */
        return STR_ME_TOUCH_OTHER;
    case 13598: /* module 53 call 30 */
        return STR_ME_REFUND_OTHER;
    case 13599: /* module 53 call 31 */
        return STR_ME_BLOCK;
    case 14336: /* module 56 call 0 */
        return STR_ME_CREATE_POOL;
    case 14337: /* module 56 call 1 */
        return STR_ME_ADD_LIQUIDITY;
    case 14338: /* module 56 call 2 */
        return STR_ME_REMOVE_LIQUIDITY;
    case 14339: /* module 56 call 3 */
        return STR_ME_SWAP_EXACT_TOKENS_FOR_TOKENS;
    case 14340: /* module 56 call 4 */
        return STR_ME_SWAP_TOKENS_FOR_EXACT_TOKENS;
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
    case 2560: /* module 10 call 0 */
        return STR_ME_TRANSFER_ALLOW_DEATH;
    case 2565: /* module 10 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 2566: /* module 10 call 6 */
        return STR_ME_UPGRADE_ACCOUNTS;
    case 2568: /* module 10 call 8 */
        return STR_ME_FORCE_SET_BALANCE;
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
    case 5381: /* module 21 call 5 */
        return STR_ME_ADD_INVULNERABLE;
    case 5382: /* module 21 call 6 */
        return STR_ME_REMOVE_INVULNERABLE;
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
    case 12828: /* module 50 call 28 */
        return STR_ME_SET_MIN_BALANCE;
    case 12829: /* module 50 call 29 */
        return STR_ME_TOUCH_OTHER;
    case 12830: /* module 50 call 30 */
        return STR_ME_REFUND_OTHER;
    case 12831: /* module 50 call 31 */
        return STR_ME_BLOCK;
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
    case 13312: /* module 52 call 0 */
        return STR_ME_CREATE;
    case 13313: /* module 52 call 1 */
        return STR_ME_FORCE_CREATE;
    case 13314: /* module 52 call 2 */
        return STR_ME_DESTROY;
    case 13315: /* module 52 call 3 */
        return STR_ME_MINT;
    case 13316: /* module 52 call 4 */
        return STR_ME_FORCE_MINT;
    case 13317: /* module 52 call 5 */
        return STR_ME_BURN;
    case 13318: /* module 52 call 6 */
        return STR_ME_TRANSFER;
    case 13319: /* module 52 call 7 */
        return STR_ME_REDEPOSIT;
    case 13320: /* module 52 call 8 */
        return STR_ME_LOCK_ITEM_TRANSFER;
    case 13321: /* module 52 call 9 */
        return STR_ME_UNLOCK_ITEM_TRANSFER;
    case 13322: /* module 52 call 10 */
        return STR_ME_LOCK_COLLECTION;
    case 13323: /* module 52 call 11 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 13324: /* module 52 call 12 */
        return STR_ME_SET_TEAM;
    case 13325: /* module 52 call 13 */
        return STR_ME_FORCE_COLLECTION_OWNER;
    case 13326: /* module 52 call 14 */
        return STR_ME_FORCE_COLLECTION_CONFIG;
    case 13327: /* module 52 call 15 */
        return STR_ME_APPROVE_TRANSFER;
    case 13328: /* module 52 call 16 */
        return STR_ME_CANCEL_APPROVAL;
    case 13329: /* module 52 call 17 */
        return STR_ME_CLEAR_ALL_TRANSFER_APPROVALS;
    case 13330: /* module 52 call 18 */
        return STR_ME_LOCK_ITEM_PROPERTIES;
    case 13331: /* module 52 call 19 */
        return STR_ME_SET_ATTRIBUTE;
    case 13332: /* module 52 call 20 */
        return STR_ME_FORCE_SET_ATTRIBUTE;
    case 13333: /* module 52 call 21 */
        return STR_ME_CLEAR_ATTRIBUTE;
    case 13334: /* module 52 call 22 */
        return STR_ME_APPROVE_ITEM_ATTRIBUTES;
    case 13335: /* module 52 call 23 */
        return STR_ME_CANCEL_ITEM_ATTRIBUTES_APPROVAL;
    case 13336: /* module 52 call 24 */
        return STR_ME_SET_METADATA;
    case 13337: /* module 52 call 25 */
        return STR_ME_CLEAR_METADATA;
    case 13338: /* module 52 call 26 */
        return STR_ME_SET_COLLECTION_METADATA;
    case 13339: /* module 52 call 27 */
        return STR_ME_CLEAR_COLLECTION_METADATA;
    case 13340: /* module 52 call 28 */
        return STR_ME_SET_ACCEPT_OWNERSHIP;
    case 13341: /* module 52 call 29 */
        return STR_ME_SET_COLLECTION_MAX_SUPPLY;
    case 13342: /* module 52 call 30 */
        return STR_ME_UPDATE_MINT_SETTINGS;
    case 13343: /* module 52 call 31 */
        return STR_ME_SET_PRICE;
    case 13344: /* module 52 call 32 */
        return STR_ME_BUY_ITEM;
    case 13345: /* module 52 call 33 */
        return STR_ME_PAY_TIPS;
    case 13346: /* module 52 call 34 */
        return STR_ME_CREATE_SWAP;
    case 13347: /* module 52 call 35 */
        return STR_ME_CANCEL_SWAP;
    case 13348: /* module 52 call 36 */
        return STR_ME_CLAIM_SWAP;
    case 13824: /* module 54 call 0 */
        return STR_ME_FRACTIONALIZE;
    case 13825: /* module 54 call 1 */
        return STR_ME_UNIFY;
    case 14080: /* module 55 call 0 */
        return STR_ME_CREATE;
    case 14081: /* module 55 call 1 */
        return STR_ME_FORCE_CREATE;
    case 14082: /* module 55 call 2 */
        return STR_ME_START_DESTROY;
    case 14083: /* module 55 call 3 */
        return STR_ME_DESTROY_ACCOUNTS;
    case 14084: /* module 55 call 4 */
        return STR_ME_DESTROY_APPROVALS;
    case 14085: /* module 55 call 5 */
        return STR_ME_FINISH_DESTROY;
    case 14086: /* module 55 call 6 */
        return STR_ME_MINT;
    case 14087: /* module 55 call 7 */
        return STR_ME_BURN;
    case 14088: /* module 55 call 8 */
        return STR_ME_TRANSFER;
    case 14089: /* module 55 call 9 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 14090: /* module 55 call 10 */
        return STR_ME_FORCE_TRANSFER;
    case 14091: /* module 55 call 11 */
        return STR_ME_FREEZE;
    case 14092: /* module 55 call 12 */
        return STR_ME_THAW;
    case 14093: /* module 55 call 13 */
        return STR_ME_FREEZE_ASSET;
    case 14094: /* module 55 call 14 */
        return STR_ME_THAW_ASSET;
    case 14095: /* module 55 call 15 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 14096: /* module 55 call 16 */
        return STR_ME_SET_TEAM;
    case 14097: /* module 55 call 17 */
        return STR_ME_SET_METADATA;
    case 14098: /* module 55 call 18 */
        return STR_ME_CLEAR_METADATA;
    case 14099: /* module 55 call 19 */
        return STR_ME_FORCE_SET_METADATA;
    case 14100: /* module 55 call 20 */
        return STR_ME_FORCE_CLEAR_METADATA;
    case 14101: /* module 55 call 21 */
        return STR_ME_FORCE_ASSET_STATUS;
    case 14102: /* module 55 call 22 */
        return STR_ME_APPROVE_TRANSFER;
    case 14103: /* module 55 call 23 */
        return STR_ME_CANCEL_APPROVAL;
    case 14104: /* module 55 call 24 */
        return STR_ME_FORCE_CANCEL_APPROVAL;
    case 14105: /* module 55 call 25 */
        return STR_ME_TRANSFER_APPROVED;
    case 14106: /* module 55 call 26 */
        return STR_ME_TOUCH;
    case 14107: /* module 55 call 27 */
        return STR_ME_REFUND;
    case 14108: /* module 55 call 28 */
        return STR_ME_SET_MIN_BALANCE;
    case 14109: /* module 55 call 29 */
        return STR_ME_TOUCH_OTHER;
    case 14110: /* module 55 call 30 */
        return STR_ME_REFUND_OTHER;
    case 14111: /* module 55 call 31 */
        return STR_ME_BLOCK;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V14(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
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
    case 7937: /* module 31 call 1 */
        return 4;
    case 7938: /* module 31 call 2 */
        return 4;
    case 7944: /* module 31 call 8 */
        return 5;
    case 7945: /* module 31 call 9 */
        return 5;
    case 13568: /* module 53 call 0 */
        return 3;
    case 13569: /* module 53 call 1 */
        return 4;
    case 13570: /* module 53 call 2 */
        return 1;
    case 13571: /* module 53 call 3 */
        return 1;
    case 13572: /* module 53 call 4 */
        return 1;
    case 13573: /* module 53 call 5 */
        return 1;
    case 13574: /* module 53 call 6 */
        return 3;
    case 13575: /* module 53 call 7 */
        return 3;
    case 13576: /* module 53 call 8 */
        return 3;
    case 13577: /* module 53 call 9 */
        return 3;
    case 13578: /* module 53 call 10 */
        return 4;
    case 13579: /* module 53 call 11 */
        return 2;
    case 13580: /* module 53 call 12 */
        return 2;
    case 13581: /* module 53 call 13 */
        return 1;
    case 13582: /* module 53 call 14 */
        return 1;
    case 13583: /* module 53 call 15 */
        return 2;
    case 13584: /* module 53 call 16 */
        return 4;
    case 13585: /* module 53 call 17 */
        return 4;
    case 13586: /* module 53 call 18 */
        return 1;
    case 13587: /* module 53 call 19 */
        return 5;
    case 13588: /* module 53 call 20 */
        return 1;
    case 13589: /* module 53 call 21 */
        return 8;
    case 13590: /* module 53 call 22 */
        return 3;
    case 13591: /* module 53 call 23 */
        return 2;
    case 13592: /* module 53 call 24 */
        return 3;
    case 13593: /* module 53 call 25 */
        return 4;
    case 13594: /* module 53 call 26 */
        return 1;
    case 13595: /* module 53 call 27 */
        return 2;
    case 13596: /* module 53 call 28 */
        return 2;
    case 13597: /* module 53 call 29 */
        return 2;
    case 13598: /* module 53 call 30 */
        return 2;
    case 13599: /* module 53 call 31 */
        return 2;
    case 14336: /* module 56 call 0 */
        return 2;
    case 14337: /* module 56 call 1 */
        return 7;
    case 14338: /* module 56 call 2 */
        return 6;
    case 14339: /* module 56 call 3 */
        return 5;
    case 14340: /* module 56 call 4 */
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
    case 2560: /* module 10 call 0 */
        return 2;
    case 2565: /* module 10 call 5 */
        return 2;
    case 2566: /* module 10 call 6 */
        return 1;
    case 2568: /* module 10 call 8 */
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
    case 5381: /* module 21 call 5 */
        return 1;
    case 5382: /* module 21 call 6 */
        return 1;
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
    case 12828: /* module 50 call 28 */
        return 2;
    case 12829: /* module 50 call 29 */
        return 2;
    case 12830: /* module 50 call 30 */
        return 2;
    case 12831: /* module 50 call 31 */
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
    case 13312: /* module 52 call 0 */
        return 2;
    case 13313: /* module 52 call 1 */
        return 2;
    case 13314: /* module 52 call 2 */
        return 2;
    case 13315: /* module 52 call 3 */
        return 4;
    case 13316: /* module 52 call 4 */
        return 4;
    case 13317: /* module 52 call 5 */
        return 2;
    case 13318: /* module 52 call 6 */
        return 3;
    case 13319: /* module 52 call 7 */
        return 2;
    case 13320: /* module 52 call 8 */
        return 2;
    case 13321: /* module 52 call 9 */
        return 2;
    case 13322: /* module 52 call 10 */
        return 2;
    case 13323: /* module 52 call 11 */
        return 2;
    case 13324: /* module 52 call 12 */
        return 4;
    case 13325: /* module 52 call 13 */
        return 2;
    case 13326: /* module 52 call 14 */
        return 2;
    case 13327: /* module 52 call 15 */
        return 4;
    case 13328: /* module 52 call 16 */
        return 3;
    case 13329: /* module 52 call 17 */
        return 2;
    case 13330: /* module 52 call 18 */
        return 4;
    case 13331: /* module 52 call 19 */
        return 5;
    case 13332: /* module 52 call 20 */
        return 6;
    case 13333: /* module 52 call 21 */
        return 4;
    case 13334: /* module 52 call 22 */
        return 3;
    case 13335: /* module 52 call 23 */
        return 4;
    case 13336: /* module 52 call 24 */
        return 3;
    case 13337: /* module 52 call 25 */
        return 2;
    case 13338: /* module 52 call 26 */
        return 2;
    case 13339: /* module 52 call 27 */
        return 1;
    case 13340: /* module 52 call 28 */
        return 1;
    case 13341: /* module 52 call 29 */
        return 2;
    case 13342: /* module 52 call 30 */
        return 2;
    case 13343: /* module 52 call 31 */
        return 4;
    case 13344: /* module 52 call 32 */
        return 3;
    case 13345: /* module 52 call 33 */
        return 1;
    case 13346: /* module 52 call 34 */
        return 6;
    case 13347: /* module 52 call 35 */
        return 2;
    case 13348: /* module 52 call 36 */
        return 5;
    case 13824: /* module 54 call 0 */
        return 5;
    case 13825: /* module 54 call 1 */
        return 4;
    case 14080: /* module 55 call 0 */
        return 3;
    case 14081: /* module 55 call 1 */
        return 4;
    case 14082: /* module 55 call 2 */
        return 1;
    case 14083: /* module 55 call 3 */
        return 1;
    case 14084: /* module 55 call 4 */
        return 1;
    case 14085: /* module 55 call 5 */
        return 1;
    case 14086: /* module 55 call 6 */
        return 3;
    case 14087: /* module 55 call 7 */
        return 3;
    case 14088: /* module 55 call 8 */
        return 3;
    case 14089: /* module 55 call 9 */
        return 3;
    case 14090: /* module 55 call 10 */
        return 4;
    case 14091: /* module 55 call 11 */
        return 2;
    case 14092: /* module 55 call 12 */
        return 2;
    case 14093: /* module 55 call 13 */
        return 1;
    case 14094: /* module 55 call 14 */
        return 1;
    case 14095: /* module 55 call 15 */
        return 2;
    case 14096: /* module 55 call 16 */
        return 4;
    case 14097: /* module 55 call 17 */
        return 4;
    case 14098: /* module 55 call 18 */
        return 1;
    case 14099: /* module 55 call 19 */
        return 5;
    case 14100: /* module 55 call 20 */
        return 1;
    case 14101: /* module 55 call 21 */
        return 8;
    case 14102: /* module 55 call 22 */
        return 3;
    case 14103: /* module 55 call 23 */
        return 2;
    case 14104: /* module 55 call 24 */
        return 3;
    case 14105: /* module 55 call 25 */
        return 4;
    case 14106: /* module 55 call 26 */
        return 1;
    case 14107: /* module 55 call 27 */
        return 2;
    case 14108: /* module 55 call 28 */
        return 2;
    case 14109: /* module 55 call 29 */
        return 2;
    case 14110: /* module 55 call 30 */
        return 2;
    case 14111: /* module 55 call 31 */
        return 2;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V14(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
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
    case 7937: /* module 31 call 1 */
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
    case 7945: /* module 31 call 9 */
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
    case 13568: /* module 53 call 0 */
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
    case 13569: /* module 53 call 1 */
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
    case 13570: /* module 53 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 13571: /* module 53 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 13572: /* module 53 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 13573: /* module 53 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 13574: /* module 53 call 6 */
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
    case 13575: /* module 53 call 7 */
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
    case 13576: /* module 53 call 8 */
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
    case 13577: /* module 53 call 9 */
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
    case 13578: /* module 53 call 10 */
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
    case 13579: /* module 53 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 13580: /* module 53 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 13581: /* module 53 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 13582: /* module 53 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 13583: /* module 53 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 13584: /* module 53 call 16 */
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
    case 13585: /* module 53 call 17 */
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
    case 13586: /* module 53 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 13587: /* module 53 call 19 */
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
    case 13588: /* module 53 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 13589: /* module 53 call 21 */
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
    case 13590: /* module 53 call 22 */
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
    case 13591: /* module 53 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 13592: /* module 53 call 24 */
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
    case 13593: /* module 53 call 25 */
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
    case 13594: /* module 53 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 13595: /* module 53 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_allow_burn;
        default:
            return NULL;
        }
    case 13596: /* module 53 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 13597: /* module 53 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 13598: /* module 53 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 13599: /* module 53 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 14336: /* module 56 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset1;
        case 1:
            return STR_IT_asset2;
        default:
            return NULL;
        }
    case 14337: /* module 56 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset1;
        case 1:
            return STR_IT_asset2;
        case 2:
            return STR_IT_amount1_desired;
        case 3:
            return STR_IT_amount2_desired;
        case 4:
            return STR_IT_amount1_min;
        case 5:
            return STR_IT_amount2_min;
        case 6:
            return STR_IT_mint_to;
        default:
            return NULL;
        }
    case 14338: /* module 56 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_asset1;
        case 1:
            return STR_IT_asset2;
        case 2:
            return STR_IT_lp_token_burn;
        case 3:
            return STR_IT_amount1_min_receive;
        case 4:
            return STR_IT_amount2_min_receive;
        case 5:
            return STR_IT_withdraw_to;
        default:
            return NULL;
        }
    case 14339: /* module 56 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_path;
        case 1:
            return STR_IT_amount_in;
        case 2:
            return STR_IT_amount_out_min;
        case 3:
            return STR_IT_send_to;
        case 4:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 14340: /* module 56 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_path;
        case 1:
            return STR_IT_amount_out;
        case 2:
            return STR_IT_amount_in_max;
        case 3:
            return STR_IT_send_to;
        case 4:
            return STR_IT_keep_alive;
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
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
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
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2568: /* module 10 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
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
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
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
    case 12828: /* module 50 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 12829: /* module 50 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 12830: /* module 50 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 12831: /* module 50 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
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
    case 13312: /* module 52 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_admin;
        case 1:
            return STR_IT_config;
        default:
            return NULL;
        }
    case 13313: /* module 52 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_owner;
        case 1:
            return STR_IT_config;
        default:
            return NULL;
        }
    case 13314: /* module 52 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_witness;
        default:
            return NULL;
        }
    case 13315: /* module 52 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_mint_to;
        case 3:
            return STR_IT_witness_data;
        default:
            return NULL;
        }
    case 13316: /* module 52 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_mint_to;
        case 3:
            return STR_IT_item_config;
        default:
            return NULL;
        }
    case 13317: /* module 52 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 13318: /* module 52 call 6 */
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
    case 13319: /* module 52 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 13320: /* module 52 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 13321: /* module 52 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 13322: /* module 52 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_lock_settings;
        default:
            return NULL;
        }
    case 13323: /* module 52 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 13324: /* module 52 call 12 */
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
    case 13325: /* module 52 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 13326: /* module 52 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_config;
        default:
            return NULL;
        }
    case 13327: /* module 52 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_delegate;
        case 3:
            return STR_IT_maybe_deadline;
        default:
            return NULL;
        }
    case 13328: /* module 52 call 16 */
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
    case 13329: /* module 52 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 13330: /* module 52 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_lock_metadata;
        case 3:
            return STR_IT_lock_attributes;
        default:
            return NULL;
        }
    case 13331: /* module 52 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_maybe_item;
        case 2:
            return STR_IT_namespace_;
        case 3:
            return STR_IT_key;
        case 4:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 13332: /* module 52 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_set_as;
        case 1:
            return STR_IT_collection;
        case 2:
            return STR_IT_maybe_item;
        case 3:
            return STR_IT_namespace_;
        case 4:
            return STR_IT_key;
        case 5:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 13333: /* module 52 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_maybe_item;
        case 2:
            return STR_IT_namespace_;
        case 3:
            return STR_IT_key;
        default:
            return NULL;
        }
    case 13334: /* module 52 call 22 */
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
    case 13335: /* module 52 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_delegate;
        case 3:
            return STR_IT_witness;
        default:
            return NULL;
        }
    case 13336: /* module 52 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        case 2:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 13337: /* module 52 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_item;
        default:
            return NULL;
        }
    case 13338: /* module 52 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 13339: /* module 52 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        default:
            return NULL;
        }
    case 13340: /* module 52 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_maybe_collection;
        default:
            return NULL;
        }
    case 13341: /* module 52 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_max_supply;
        default:
            return NULL;
        }
    case 13342: /* module 52 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_collection;
        case 1:
            return STR_IT_mint_settings;
        default:
            return NULL;
        }
    case 13343: /* module 52 call 31 */
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
    case 13344: /* module 52 call 32 */
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
    case 13345: /* module 52 call 33 */
        switch (itemIdx) {
        case 0:
            return STR_IT_tips;
        default:
            return NULL;
        }
    case 13346: /* module 52 call 34 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offered_collection;
        case 1:
            return STR_IT_offered_item;
        case 2:
            return STR_IT_desired_collection;
        case 3:
            return STR_IT_maybe_desired_item;
        case 4:
            return STR_IT_maybe_price;
        case 5:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 13347: /* module 52 call 35 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offered_collection;
        case 1:
            return STR_IT_offered_item;
        default:
            return NULL;
        }
    case 13348: /* module 52 call 36 */
        switch (itemIdx) {
        case 0:
            return STR_IT_send_collection;
        case 1:
            return STR_IT_send_item;
        case 2:
            return STR_IT_receive_collection;
        case 3:
            return STR_IT_receive_item;
        case 4:
            return STR_IT_witness_price;
        default:
            return NULL;
        }
    case 13824: /* module 54 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_nft_collection_id;
        case 1:
            return STR_IT_nft_id;
        case 2:
            return STR_IT_asset_id;
        case 3:
            return STR_IT_beneficiary;
        case 4:
            return STR_IT_fractions;
        default:
            return NULL;
        }
    case 13825: /* module 54 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_nft_collection_id;
        case 1:
            return STR_IT_nft_id;
        case 2:
            return STR_IT_asset_id;
        case 3:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 14080: /* module 55 call 0 */
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
    case 14081: /* module 55 call 1 */
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
    case 14082: /* module 55 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 14083: /* module 55 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 14084: /* module 55 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 14085: /* module 55 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 14086: /* module 55 call 6 */
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
    case 14087: /* module 55 call 7 */
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
    case 14088: /* module 55 call 8 */
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
    case 14089: /* module 55 call 9 */
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
    case 14090: /* module 55 call 10 */
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
    case 14091: /* module 55 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 14092: /* module 55 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 14093: /* module 55 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 14094: /* module 55 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 14095: /* module 55 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 14096: /* module 55 call 16 */
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
    case 14097: /* module 55 call 17 */
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
    case 14098: /* module 55 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 14099: /* module 55 call 19 */
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
    case 14100: /* module 55 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 14101: /* module 55 call 21 */
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
    case 14102: /* module 55 call 22 */
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
    case 14103: /* module 55 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 14104: /* module 55 call 24 */
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
    case 14105: /* module 55 call 25 */
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
    case 14106: /* module 55 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 14107: /* module 55 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_allow_burn;
        default:
            return NULL;
        }
    case 14108: /* module 55 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 14109: /* module 55 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 14110: /* module 55 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 14111: /* module 55 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V14(
    pd_Method_V14_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V14 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V14.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V14 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V14 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V14 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_all_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V14 - keep_alive */;
            return _toStringbool(
                &m->nested.balances_transfer_all_V14.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V14 - keys */;
            return _toStringKeys(
                &m->nested.session_set_keys_V14.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V14 - proof */;
            return _toStringBytes(
                &m->nested.session_set_keys_V14.proof,
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
        case 0: /* utility_batch_V14 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V14.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V14 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V14.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_teleport_assets_V14 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_teleport_assets_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_teleport_assets_V14 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_teleport_assets_V14.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_teleport_assets_V14 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.polkadotxcm_teleport_assets_V14.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_teleport_assets_V14 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_teleport_assets_V14.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_reserve_transfer_assets_V14 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_reserve_transfer_assets_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_reserve_transfer_assets_V14 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_reserve_transfer_assets_V14.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_reserve_transfer_assets_V14 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.polkadotxcm_reserve_transfer_assets_V14.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_reserve_transfer_assets_V14 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_reserve_transfer_assets_V14.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7944: /* module 31 call 8 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_limited_reserve_transfer_assets_V14 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_limited_reserve_transfer_assets_V14 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V14.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_limited_reserve_transfer_assets_V14 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V14.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_limited_reserve_transfer_assets_V14 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V14.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* polkadotxcm_limited_reserve_transfer_assets_V14 - weight_limit */;
            return _toStringWeightLimit(
                &m->basic.polkadotxcm_limited_reserve_transfer_assets_V14.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7945: /* module 31 call 9 */
        switch (itemIdx) {
        case 0: /* polkadotxcm_limited_teleport_assets_V14 - dest */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_limited_teleport_assets_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polkadotxcm_limited_teleport_assets_V14 - beneficiary */;
            return _toStringBoxVersionedMultiLocation(
                &m->basic.polkadotxcm_limited_teleport_assets_V14.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polkadotxcm_limited_teleport_assets_V14 - assets */;
            return _toStringBoxVersionedMultiAssets(
                &m->basic.polkadotxcm_limited_teleport_assets_V14.assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polkadotxcm_limited_teleport_assets_V14 - fee_asset_item */;
            return _toStringu32(
                &m->basic.polkadotxcm_limited_teleport_assets_V14.fee_asset_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* polkadotxcm_limited_teleport_assets_V14 - weight_limit */;
            return _toStringWeightLimit(
                &m->basic.polkadotxcm_limited_teleport_assets_V14.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13568: /* module 53 call 0 */
        switch (itemIdx) {
        case 0: /* foreignassets_create_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_create_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_create_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_create_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_create_V14 - min_balance */;
            return _toStringBalance(
                &m->basic.foreignassets_create_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13569: /* module 53 call 1 */
        switch (itemIdx) {
        case 0: /* foreignassets_force_create_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_force_create_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_force_create_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_force_create_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_force_create_V14 - is_sufficient */;
            return _toStringbool(
                &m->basic.foreignassets_force_create_V14.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* foreignassets_force_create_V14 - min_balance */;
            return _toStringCompactBalance(
                &m->basic.foreignassets_force_create_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13570: /* module 53 call 2 */
        switch (itemIdx) {
        case 0: /* foreignassets_start_destroy_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_start_destroy_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13571: /* module 53 call 3 */
        switch (itemIdx) {
        case 0: /* foreignassets_destroy_accounts_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_destroy_accounts_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13572: /* module 53 call 4 */
        switch (itemIdx) {
        case 0: /* foreignassets_destroy_approvals_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_destroy_approvals_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13573: /* module 53 call 5 */
        switch (itemIdx) {
        case 0: /* foreignassets_finish_destroy_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_finish_destroy_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13574: /* module 53 call 6 */
        switch (itemIdx) {
        case 0: /* foreignassets_mint_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_mint_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_mint_V14 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_mint_V14.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_mint_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.foreignassets_mint_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13575: /* module 53 call 7 */
        switch (itemIdx) {
        case 0: /* foreignassets_burn_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_burn_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_burn_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_burn_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_burn_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.foreignassets_burn_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13576: /* module 53 call 8 */
        switch (itemIdx) {
        case 0: /* foreignassets_transfer_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_transfer_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_transfer_V14 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_transfer_V14.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.foreignassets_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13577: /* module 53 call 9 */
        switch (itemIdx) {
        case 0: /* foreignassets_transfer_keep_alive_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_transfer_keep_alive_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_transfer_keep_alive_V14 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_transfer_keep_alive_V14.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_transfer_keep_alive_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.foreignassets_transfer_keep_alive_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13578: /* module 53 call 10 */
        switch (itemIdx) {
        case 0: /* foreignassets_force_transfer_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_force_transfer_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_force_transfer_V14 - source */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_force_transfer_V14.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_force_transfer_V14 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_force_transfer_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* foreignassets_force_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.foreignassets_force_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13579: /* module 53 call 11 */
        switch (itemIdx) {
        case 0: /* foreignassets_freeze_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_freeze_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_freeze_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_freeze_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13580: /* module 53 call 12 */
        switch (itemIdx) {
        case 0: /* foreignassets_thaw_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_thaw_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_thaw_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_thaw_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13581: /* module 53 call 13 */
        switch (itemIdx) {
        case 0: /* foreignassets_freeze_asset_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_freeze_asset_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13582: /* module 53 call 14 */
        switch (itemIdx) {
        case 0: /* foreignassets_thaw_asset_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_thaw_asset_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13583: /* module 53 call 15 */
        switch (itemIdx) {
        case 0: /* foreignassets_transfer_ownership_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_transfer_ownership_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_transfer_ownership_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_transfer_ownership_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13584: /* module 53 call 16 */
        switch (itemIdx) {
        case 0: /* foreignassets_set_team_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_set_team_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_set_team_V14 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_set_team_V14.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_set_team_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_set_team_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* foreignassets_set_team_V14 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_set_team_V14.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13585: /* module 53 call 17 */
        switch (itemIdx) {
        case 0: /* foreignassets_set_metadata_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_set_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_set_metadata_V14 - name */;
            return _toStringVecu8(
                &m->basic.foreignassets_set_metadata_V14.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_set_metadata_V14 - symbol */;
            return _toStringVecu8(
                &m->basic.foreignassets_set_metadata_V14.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* foreignassets_set_metadata_V14 - decimals */;
            return _toStringu8(
                &m->basic.foreignassets_set_metadata_V14.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13586: /* module 53 call 18 */
        switch (itemIdx) {
        case 0: /* foreignassets_clear_metadata_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_clear_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13587: /* module 53 call 19 */
        switch (itemIdx) {
        case 0: /* foreignassets_force_set_metadata_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_force_set_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_force_set_metadata_V14 - name */;
            return _toStringVecu8(
                &m->basic.foreignassets_force_set_metadata_V14.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_force_set_metadata_V14 - symbol */;
            return _toStringVecu8(
                &m->basic.foreignassets_force_set_metadata_V14.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* foreignassets_force_set_metadata_V14 - decimals */;
            return _toStringu8(
                &m->basic.foreignassets_force_set_metadata_V14.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* foreignassets_force_set_metadata_V14 - is_frozen */;
            return _toStringbool(
                &m->basic.foreignassets_force_set_metadata_V14.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13588: /* module 53 call 20 */
        switch (itemIdx) {
        case 0: /* foreignassets_force_clear_metadata_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_force_clear_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13589: /* module 53 call 21 */
        switch (itemIdx) {
        case 0: /* foreignassets_force_asset_status_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_force_asset_status_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_force_asset_status_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_force_asset_status_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_force_asset_status_V14 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_force_asset_status_V14.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* foreignassets_force_asset_status_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_force_asset_status_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* foreignassets_force_asset_status_V14 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_force_asset_status_V14.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* foreignassets_force_asset_status_V14 - min_balance */;
            return _toStringCompactBalance(
                &m->basic.foreignassets_force_asset_status_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* foreignassets_force_asset_status_V14 - is_sufficient */;
            return _toStringbool(
                &m->basic.foreignassets_force_asset_status_V14.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* foreignassets_force_asset_status_V14 - is_frozen */;
            return _toStringbool(
                &m->basic.foreignassets_force_asset_status_V14.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13590: /* module 53 call 22 */
        switch (itemIdx) {
        case 0: /* foreignassets_approve_transfer_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_approve_transfer_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_approve_transfer_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_approve_transfer_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_approve_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.foreignassets_approve_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13591: /* module 53 call 23 */
        switch (itemIdx) {
        case 0: /* foreignassets_cancel_approval_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_cancel_approval_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_cancel_approval_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_cancel_approval_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13592: /* module 53 call 24 */
        switch (itemIdx) {
        case 0: /* foreignassets_force_cancel_approval_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_force_cancel_approval_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_force_cancel_approval_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_force_cancel_approval_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_force_cancel_approval_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_force_cancel_approval_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13593: /* module 53 call 25 */
        switch (itemIdx) {
        case 0: /* foreignassets_transfer_approved_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_transfer_approved_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_transfer_approved_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_transfer_approved_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* foreignassets_transfer_approved_V14 - destination */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_transfer_approved_V14.destination,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* foreignassets_transfer_approved_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.foreignassets_transfer_approved_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13594: /* module 53 call 26 */
        switch (itemIdx) {
        case 0: /* foreignassets_touch_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_touch_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13595: /* module 53 call 27 */
        switch (itemIdx) {
        case 0: /* foreignassets_refund_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_refund_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_refund_V14 - allow_burn */;
            return _toStringbool(
                &m->basic.foreignassets_refund_V14.allow_burn,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13596: /* module 53 call 28 */
        switch (itemIdx) {
        case 0: /* foreignassets_set_min_balance_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_set_min_balance_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_set_min_balance_V14 - min_balance */;
            return _toStringBalance(
                &m->basic.foreignassets_set_min_balance_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13597: /* module 53 call 29 */
        switch (itemIdx) {
        case 0: /* foreignassets_touch_other_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_touch_other_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_touch_other_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_touch_other_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13598: /* module 53 call 30 */
        switch (itemIdx) {
        case 0: /* foreignassets_refund_other_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_refund_other_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_refund_other_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_refund_other_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13599: /* module 53 call 31 */
        switch (itemIdx) {
        case 0: /* foreignassets_block_V14 - id */;
            return _toStringAssetIdParameter(
                &m->basic.foreignassets_block_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* foreignassets_block_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.foreignassets_block_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14336: /* module 56 call 0 */
        switch (itemIdx) {
        case 0: /* assetconversion_create_pool_V14 - asset1 */;
            return _toStringMultiAssetId(
                &m->basic.assetconversion_create_pool_V14.asset1,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assetconversion_create_pool_V14 - asset2 */;
            return _toStringMultiAssetId(
                &m->basic.assetconversion_create_pool_V14.asset2,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14337: /* module 56 call 1 */
        switch (itemIdx) {
        case 0: /* assetconversion_add_liquidity_V14 - asset1 */;
            return _toStringMultiAssetId(
                &m->basic.assetconversion_add_liquidity_V14.asset1,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assetconversion_add_liquidity_V14 - asset2 */;
            return _toStringMultiAssetId(
                &m->basic.assetconversion_add_liquidity_V14.asset2,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assetconversion_add_liquidity_V14 - amount1_desired */;
            return _toStringu128(
                &m->basic.assetconversion_add_liquidity_V14.amount1_desired,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assetconversion_add_liquidity_V14 - amount2_desired */;
            return _toStringu128(
                &m->basic.assetconversion_add_liquidity_V14.amount2_desired,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assetconversion_add_liquidity_V14 - amount1_min */;
            return _toStringu128(
                &m->basic.assetconversion_add_liquidity_V14.amount1_min,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* assetconversion_add_liquidity_V14 - amount2_min */;
            return _toStringu128(
                &m->basic.assetconversion_add_liquidity_V14.amount2_min,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* assetconversion_add_liquidity_V14 - mint_to */;
            return _toStringAccountId(
                &m->basic.assetconversion_add_liquidity_V14.mint_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14338: /* module 56 call 2 */
        switch (itemIdx) {
        case 0: /* assetconversion_remove_liquidity_V14 - asset1 */;
            return _toStringMultiAssetId(
                &m->basic.assetconversion_remove_liquidity_V14.asset1,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assetconversion_remove_liquidity_V14 - asset2 */;
            return _toStringMultiAssetId(
                &m->basic.assetconversion_remove_liquidity_V14.asset2,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assetconversion_remove_liquidity_V14 - lp_token_burn */;
            return _toStringu128(
                &m->basic.assetconversion_remove_liquidity_V14.lp_token_burn,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assetconversion_remove_liquidity_V14 - amount1_min_receive */;
            return _toStringu128(
                &m->basic.assetconversion_remove_liquidity_V14.amount1_min_receive,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assetconversion_remove_liquidity_V14 - amount2_min_receive */;
            return _toStringu128(
                &m->basic.assetconversion_remove_liquidity_V14.amount2_min_receive,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* assetconversion_remove_liquidity_V14 - withdraw_to */;
            return _toStringAccountId(
                &m->basic.assetconversion_remove_liquidity_V14.withdraw_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14339: /* module 56 call 3 */
        switch (itemIdx) {
        case 0: /* assetconversion_swap_exact_tokens_for_tokens_V14 - path */;
            return _toStringVecMultiAssetId(
                &m->basic.assetconversion_swap_exact_tokens_for_tokens_V14.path,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assetconversion_swap_exact_tokens_for_tokens_V14 - amount_in */;
            return _toStringu128(
                &m->basic.assetconversion_swap_exact_tokens_for_tokens_V14.amount_in,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assetconversion_swap_exact_tokens_for_tokens_V14 - amount_out_min */;
            return _toStringu128(
                &m->basic.assetconversion_swap_exact_tokens_for_tokens_V14.amount_out_min,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assetconversion_swap_exact_tokens_for_tokens_V14 - send_to */;
            return _toStringAccountId(
                &m->basic.assetconversion_swap_exact_tokens_for_tokens_V14.send_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assetconversion_swap_exact_tokens_for_tokens_V14 - keep_alive */;
            return _toStringbool(
                &m->basic.assetconversion_swap_exact_tokens_for_tokens_V14.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14340: /* module 56 call 4 */
        switch (itemIdx) {
        case 0: /* assetconversion_swap_tokens_for_exact_tokens_V14 - path */;
            return _toStringVecMultiAssetId(
                &m->basic.assetconversion_swap_tokens_for_exact_tokens_V14.path,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assetconversion_swap_tokens_for_exact_tokens_V14 - amount_out */;
            return _toStringu128(
                &m->basic.assetconversion_swap_tokens_for_exact_tokens_V14.amount_out,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assetconversion_swap_tokens_for_exact_tokens_V14 - amount_in_max */;
            return _toStringu128(
                &m->basic.assetconversion_swap_tokens_for_exact_tokens_V14.amount_in_max,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assetconversion_swap_tokens_for_exact_tokens_V14 - send_to */;
            return _toStringAccountId(
                &m->basic.assetconversion_swap_tokens_for_exact_tokens_V14.send_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assetconversion_swap_tokens_for_exact_tokens_V14 - keep_alive */;
            return _toStringbool(
                &m->basic.assetconversion_swap_tokens_for_exact_tokens_V14.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_remark_V14 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V14.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V14 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V14.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_code_V14 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V14.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V14 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V14.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V14 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V14.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V14 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V14.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_allow_death_V14 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_allow_death_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_allow_death_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_allow_death_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V14 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        case 0: /* balances_upgrade_accounts_V14 - who */;
            return _toStringVecAccountId(
                &m->basic.balances_upgrade_accounts_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2568: /* module 10 call 8 */
        switch (itemIdx) {
        case 0: /* balances_force_set_balance_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_set_balance_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_set_balance_V14 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_force_set_balance_V14.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_invulnerables_V14 - new_ */;
            return _toStringVecAccountId(
                &m->basic.collatorselection_set_invulnerables_V14.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_desired_candidates_V14 - max */;
            return _toStringu32(
                &m->basic.collatorselection_set_desired_candidates_V14.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* collatorselection_set_candidacy_bond_V14 - bond */;
            return _toStringBalance(
                &m->basic.collatorselection_set_candidacy_bond_V14.bond,
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
    case 5381: /* module 21 call 5 */
        switch (itemIdx) {
        case 0: /* collatorselection_add_invulnerable_V14 - who */;
            return _toStringAccountId(
                &m->basic.collatorselection_add_invulnerable_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5382: /* module 21 call 6 */
        switch (itemIdx) {
        case 0: /* collatorselection_remove_invulnerable_V14 - who */;
            return _toStringAccountId(
                &m->basic.collatorselection_remove_invulnerable_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_service_overweight_V14 - index */;
            return _toStringOverweightIndex(
                &m->basic.xcmpqueue_service_overweight_V14.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xcmpqueue_service_overweight_V14 - weight_limit */;
            return _toStringWeight(
                &m->basic.xcmpqueue_service_overweight_V14.weight_limit,
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
        case 0: /* xcmpqueue_update_suspend_threshold_V14 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_suspend_threshold_V14.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_drop_threshold_V14 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_drop_threshold_V14.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_resume_threshold_V14 - new_ */;
            return _toStringu32(
                &m->basic.xcmpqueue_update_resume_threshold_V14.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_threshold_weight_V14 - new_ */;
            return _toStringWeight(
                &m->basic.xcmpqueue_update_threshold_weight_V14.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_weight_restrict_decay_V14 - new_ */;
            return _toStringWeight(
                &m->basic.xcmpqueue_update_weight_restrict_decay_V14.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0: /* xcmpqueue_update_xcmp_max_individual_weight_V14 - new_ */;
            return _toStringWeight(
                &m->basic.xcmpqueue_update_xcmp_max_individual_weight_V14.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0: /* dmpqueue_service_overweight_V14 - index */;
            return _toStringOverweightIndex(
                &m->basic.dmpqueue_service_overweight_V14.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dmpqueue_service_overweight_V14 - weight_limit */;
            return _toStringWeight(
                &m->basic.dmpqueue_service_overweight_V14.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V14 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V14.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V14 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V14.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V14 - weight */;
            return _toStringWeight(
                &m->basic.utility_with_weight_V14.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V14 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_threshold_1_V14.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V14 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V14.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V14 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V14.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V14 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_V14.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V14 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_as_multi_V14.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V14 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V14.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V14 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V14.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V14 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V14.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V14 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_approve_as_multi_V14.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V14 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_approve_as_multi_V14.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V14 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V14.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V14 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V14.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V14 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V14.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V14 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_cancel_as_multi_V14.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V14 - timepoint */;
            return _toStringTimepoint(
                &m->nested.multisig_cancel_as_multi_V14.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V14 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V14.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V14 - real */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_proxy_V14.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V14 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->nested.proxy_proxy_V14.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V14 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V14.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_add_proxy_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V14 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_add_proxy_V14.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V14 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_add_proxy_V14.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_remove_proxy_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V14 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_remove_proxy_V14.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V14 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_remove_proxy_V14.delay,
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
        case 0: /* proxy_create_pure_V14 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_create_pure_V14.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_create_pure_V14 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_create_pure_V14.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_create_pure_V14 - index */;
            return _toStringu16(
                &m->nested.proxy_create_pure_V14.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10757: /* module 42 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_pure_V14 - spawner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_kill_pure_V14.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_pure_V14 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_kill_pure_V14.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_pure_V14 - index */;
            return _toStringu16(
                &m->nested.proxy_kill_pure_V14.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_pure_V14 - height */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V14.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_pure_V14 - ext_index */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V14.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10758: /* module 42 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V14 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_announce_V14.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V14 - call_hash */;
            return _toStringCallHashOf(
                &m->basic.proxy_announce_V14.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10759: /* module 42 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V14 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_remove_announcement_V14.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V14 - call_hash */;
            return _toStringCallHashOf(
                &m->basic.proxy_remove_announcement_V14.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10760: /* module 42 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_reject_announcement_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V14 - call_hash */;
            return _toStringCallHashOf(
                &m->basic.proxy_reject_announcement_V14.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10761: /* module 42 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V14 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V14.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V14 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->basic.proxy_proxy_announced_V14.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V14 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V14.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0: /* assets_create_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_create_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_create_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_create_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_create_V14 - min_balance */;
            return _toStringBalance(
                &m->nested.assets_create_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0: /* assets_force_create_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_create_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_create_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_force_create_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_create_V14 - is_sufficient */;
            return _toStringbool(
                &m->nested.assets_force_create_V14.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_create_V14 - min_balance */;
            return _toStringCompactBalance(
                &m->nested.assets_force_create_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        case 0: /* assets_start_destroy_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_start_destroy_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0: /* assets_destroy_accounts_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_destroy_accounts_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12804: /* module 50 call 4 */
        switch (itemIdx) {
        case 0: /* assets_destroy_approvals_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_destroy_approvals_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12805: /* module 50 call 5 */
        switch (itemIdx) {
        case 0: /* assets_finish_destroy_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_finish_destroy_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12806: /* module 50 call 6 */
        switch (itemIdx) {
        case 0: /* assets_mint_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_mint_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_mint_V14 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_mint_V14.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_mint_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_mint_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12807: /* module 50 call 7 */
        switch (itemIdx) {
        case 0: /* assets_burn_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_burn_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_burn_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_burn_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_burn_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_burn_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12808: /* module 50 call 8 */
        switch (itemIdx) {
        case 0: /* assets_transfer_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_transfer_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_V14 - target */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_transfer_V14.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12809: /* module 50 call 9 */
        switch (itemIdx) {
        case 0: /* assets_transfer_keep_alive_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_transfer_keep_alive_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_keep_alive_V14 - target */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_transfer_keep_alive_V14.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_keep_alive_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_transfer_keep_alive_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12810: /* module 50 call 10 */
        switch (itemIdx) {
        case 0: /* assets_force_transfer_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_transfer_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_transfer_V14 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_force_transfer_V14.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_transfer_V14 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_force_transfer_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_force_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12811: /* module 50 call 11 */
        switch (itemIdx) {
        case 0: /* assets_freeze_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_freeze_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_freeze_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_freeze_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12812: /* module 50 call 12 */
        switch (itemIdx) {
        case 0: /* assets_thaw_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_thaw_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_thaw_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_thaw_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12813: /* module 50 call 13 */
        switch (itemIdx) {
        case 0: /* assets_freeze_asset_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_freeze_asset_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12814: /* module 50 call 14 */
        switch (itemIdx) {
        case 0: /* assets_thaw_asset_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_thaw_asset_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12815: /* module 50 call 15 */
        switch (itemIdx) {
        case 0: /* assets_transfer_ownership_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_transfer_ownership_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_ownership_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_transfer_ownership_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12816: /* module 50 call 16 */
        switch (itemIdx) {
        case 0: /* assets_set_team_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_set_team_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_team_V14 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_set_team_V14.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_team_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_set_team_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_team_V14 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_set_team_V14.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12817: /* module 50 call 17 */
        switch (itemIdx) {
        case 0: /* assets_set_metadata_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_set_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_metadata_V14 - name */;
            return _toStringVecu8(
                &m->nested.assets_set_metadata_V14.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_metadata_V14 - symbol */;
            return _toStringVecu8(
                &m->nested.assets_set_metadata_V14.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_metadata_V14 - decimals */;
            return _toStringu8(
                &m->nested.assets_set_metadata_V14.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12818: /* module 50 call 18 */
        switch (itemIdx) {
        case 0: /* assets_clear_metadata_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_clear_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12819: /* module 50 call 19 */
        switch (itemIdx) {
        case 0: /* assets_force_set_metadata_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_set_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_set_metadata_V14 - name */;
            return _toStringVecu8(
                &m->nested.assets_force_set_metadata_V14.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_set_metadata_V14 - symbol */;
            return _toStringVecu8(
                &m->nested.assets_force_set_metadata_V14.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_set_metadata_V14 - decimals */;
            return _toStringu8(
                &m->nested.assets_force_set_metadata_V14.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_set_metadata_V14 - is_frozen */;
            return _toStringbool(
                &m->nested.assets_force_set_metadata_V14.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12820: /* module 50 call 20 */
        switch (itemIdx) {
        case 0: /* assets_force_clear_metadata_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_clear_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12821: /* module 50 call 21 */
        switch (itemIdx) {
        case 0: /* assets_force_asset_status_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_asset_status_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_asset_status_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_force_asset_status_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_asset_status_V14 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_force_asset_status_V14.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_asset_status_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_force_asset_status_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_asset_status_V14 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_force_asset_status_V14.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* assets_force_asset_status_V14 - min_balance */;
            return _toStringCompactBalance(
                &m->nested.assets_force_asset_status_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* assets_force_asset_status_V14 - is_sufficient */;
            return _toStringbool(
                &m->nested.assets_force_asset_status_V14.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* assets_force_asset_status_V14 - is_frozen */;
            return _toStringbool(
                &m->nested.assets_force_asset_status_V14.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12822: /* module 50 call 22 */
        switch (itemIdx) {
        case 0: /* assets_approve_transfer_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_approve_transfer_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_approve_transfer_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_approve_transfer_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_approve_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_approve_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12823: /* module 50 call 23 */
        switch (itemIdx) {
        case 0: /* assets_cancel_approval_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_cancel_approval_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_cancel_approval_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_cancel_approval_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12824: /* module 50 call 24 */
        switch (itemIdx) {
        case 0: /* assets_force_cancel_approval_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_force_cancel_approval_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_cancel_approval_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_force_cancel_approval_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_cancel_approval_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_force_cancel_approval_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12825: /* module 50 call 25 */
        switch (itemIdx) {
        case 0: /* assets_transfer_approved_V14 - id */;
            return _toStringCompactu32(
                &m->nested.assets_transfer_approved_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_approved_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_transfer_approved_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_approved_V14 - destination */;
            return _toStringAccountIdLookupOfT(
                &m->nested.assets_transfer_approved_V14.destination,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_transfer_approved_V14 - amount */;
            return _toStringCompactBalance(
                &m->nested.assets_transfer_approved_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12826: /* module 50 call 26 */
        switch (itemIdx) {
        case 0: /* assets_touch_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_touch_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12827: /* module 50 call 27 */
        switch (itemIdx) {
        case 0: /* assets_refund_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_refund_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_refund_V14 - allow_burn */;
            return _toStringbool(
                &m->basic.assets_refund_V14.allow_burn,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12828: /* module 50 call 28 */
        switch (itemIdx) {
        case 0: /* assets_set_min_balance_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_set_min_balance_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_min_balance_V14 - min_balance */;
            return _toStringBalance(
                &m->basic.assets_set_min_balance_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12829: /* module 50 call 29 */
        switch (itemIdx) {
        case 0: /* assets_touch_other_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_touch_other_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_touch_other_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_touch_other_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12830: /* module 50 call 30 */
        switch (itemIdx) {
        case 0: /* assets_refund_other_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_refund_other_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_refund_other_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_refund_other_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12831: /* module 50 call 31 */
        switch (itemIdx) {
        case 0: /* assets_block_V14 - id */;
            return _toStringCompactu32(
                &m->basic.assets_block_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_block_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_block_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0: /* uniques_create_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_create_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_create_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_create_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0: /* uniques_force_create_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_force_create_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_force_create_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_create_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_force_create_V14 - free_holding */;
            return _toStringbool(
                &m->basic.uniques_force_create_V14.free_holding,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0: /* uniques_destroy_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_destroy_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_destroy_V14 - witness */;
            return _toStringDestroyWitness(
                &m->basic.uniques_destroy_V14.witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0: /* uniques_mint_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_mint_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_mint_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_mint_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_mint_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_mint_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0: /* uniques_burn_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_burn_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_burn_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_burn_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_burn_V14 - check_owner */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.uniques_burn_V14.check_owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0: /* uniques_transfer_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_transfer_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_transfer_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_transfer_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_transfer_V14 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_transfer_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0: /* uniques_redeposit_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_redeposit_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_redeposit_V14 - items */;
            return _toStringVecItemId(
                &m->basic.uniques_redeposit_V14.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0: /* uniques_freeze_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_freeze_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_freeze_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_freeze_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0: /* uniques_thaw_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_thaw_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_thaw_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_thaw_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0: /* uniques_freeze_collection_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_freeze_collection_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13066: /* module 51 call 10 */
        switch (itemIdx) {
        case 0: /* uniques_thaw_collection_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_thaw_collection_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0: /* uniques_transfer_ownership_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_transfer_ownership_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_transfer_ownership_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_transfer_ownership_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0: /* uniques_set_team_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_team_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_team_V14 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_set_team_V14.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_team_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_set_team_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_team_V14 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_set_team_V14.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0: /* uniques_approve_transfer_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_approve_transfer_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_approve_transfer_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_approve_transfer_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_approve_transfer_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_approve_transfer_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0: /* uniques_cancel_approval_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_cancel_approval_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_cancel_approval_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_cancel_approval_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_cancel_approval_V14 - maybe_check_delegate */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.uniques_cancel_approval_V14.maybe_check_delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0: /* uniques_force_item_status_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_force_item_status_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_force_item_status_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_item_status_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_force_item_status_V14 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_item_status_V14.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_force_item_status_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_item_status_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* uniques_force_item_status_V14 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.uniques_force_item_status_V14.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* uniques_force_item_status_V14 - free_holding */;
            return _toStringbool(
                &m->basic.uniques_force_item_status_V14.free_holding,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* uniques_force_item_status_V14 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_force_item_status_V14.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13072: /* module 51 call 16 */
        switch (itemIdx) {
        case 0: /* uniques_set_attribute_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_attribute_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_attribute_V14 - maybe_item */;
            return _toStringOptionItemId(
                &m->basic.uniques_set_attribute_V14.maybe_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_attribute_V14 - key */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_set_attribute_V14.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_attribute_V14 - value */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_set_attribute_V14.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13073: /* module 51 call 17 */
        switch (itemIdx) {
        case 0: /* uniques_clear_attribute_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_clear_attribute_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_clear_attribute_V14 - maybe_item */;
            return _toStringOptionItemId(
                &m->basic.uniques_clear_attribute_V14.maybe_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_clear_attribute_V14 - key */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_clear_attribute_V14.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0: /* uniques_set_metadata_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_metadata_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_metadata_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_set_metadata_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_metadata_V14 - data */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_set_metadata_V14.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_metadata_V14 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_set_metadata_V14.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0: /* uniques_clear_metadata_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_clear_metadata_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_clear_metadata_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_clear_metadata_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0: /* uniques_set_collection_metadata_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_collection_metadata_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_collection_metadata_V14 - data */;
            return _toStringBoundedVecu8(
                &m->basic.uniques_set_collection_metadata_V14.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_collection_metadata_V14 - is_frozen */;
            return _toStringbool(
                &m->basic.uniques_set_collection_metadata_V14.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0: /* uniques_clear_collection_metadata_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_clear_collection_metadata_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0: /* uniques_set_accept_ownership_V14 - maybe_collection */;
            return _toStringOptionCollectionId(
                &m->basic.uniques_set_accept_ownership_V14.maybe_collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0: /* uniques_set_collection_max_supply_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_collection_max_supply_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_collection_max_supply_V14 - max_supply */;
            return _toStringu32(
                &m->basic.uniques_set_collection_max_supply_V14.max_supply,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0: /* uniques_set_price_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_set_price_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_set_price_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_set_price_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_set_price_V14 - price */;
            return _toStringOptionItemPrice(
                &m->basic.uniques_set_price_V14.price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* uniques_set_price_V14 - whitelisted_buyer */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.uniques_set_price_V14.whitelisted_buyer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0: /* uniques_buy_item_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.uniques_buy_item_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* uniques_buy_item_V14 - item */;
            return _toStringItemId(
                &m->basic.uniques_buy_item_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* uniques_buy_item_V14 - bid_price */;
            return _toStringItemPrice(
                &m->basic.uniques_buy_item_V14.bid_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13312: /* module 52 call 0 */
        switch (itemIdx) {
        case 0: /* nfts_create_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_create_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_create_V14 - config */;
            return _toStringCollectionConfigFor(
                &m->basic.nfts_create_V14.config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13313: /* module 52 call 1 */
        switch (itemIdx) {
        case 0: /* nfts_force_create_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_force_create_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_force_create_V14 - config */;
            return _toStringCollectionConfigFor(
                &m->basic.nfts_force_create_V14.config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13314: /* module 52 call 2 */
        switch (itemIdx) {
        case 0: /* nfts_destroy_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_destroy_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_destroy_V14 - witness */;
            return _toStringDestroyWitness(
                &m->basic.nfts_destroy_V14.witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13315: /* module 52 call 3 */
        switch (itemIdx) {
        case 0: /* nfts_mint_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_mint_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_mint_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_mint_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_mint_V14 - mint_to */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_mint_V14.mint_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_mint_V14 - witness_data */;
            return _toStringOptionMintWitnessItemIdDepositBalanceOf(
                &m->basic.nfts_mint_V14.witness_data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13316: /* module 52 call 4 */
        switch (itemIdx) {
        case 0: /* nfts_force_mint_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_force_mint_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_force_mint_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_force_mint_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_force_mint_V14 - mint_to */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_force_mint_V14.mint_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_force_mint_V14 - item_config */;
            return _toStringItemConfig(
                &m->basic.nfts_force_mint_V14.item_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13317: /* module 52 call 5 */
        switch (itemIdx) {
        case 0: /* nfts_burn_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_burn_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_burn_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_burn_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13318: /* module 52 call 6 */
        switch (itemIdx) {
        case 0: /* nfts_transfer_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_transfer_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_transfer_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_transfer_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_transfer_V14 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_transfer_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13319: /* module 52 call 7 */
        switch (itemIdx) {
        case 0: /* nfts_redeposit_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_redeposit_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_redeposit_V14 - items */;
            return _toStringVecItemId(
                &m->basic.nfts_redeposit_V14.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13320: /* module 52 call 8 */
        switch (itemIdx) {
        case 0: /* nfts_lock_item_transfer_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_lock_item_transfer_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_lock_item_transfer_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_lock_item_transfer_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13321: /* module 52 call 9 */
        switch (itemIdx) {
        case 0: /* nfts_unlock_item_transfer_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_unlock_item_transfer_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_unlock_item_transfer_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_unlock_item_transfer_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13322: /* module 52 call 10 */
        switch (itemIdx) {
        case 0: /* nfts_lock_collection_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_lock_collection_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_lock_collection_V14 - lock_settings */;
            return _toStringCollectionSettings(
                &m->basic.nfts_lock_collection_V14.lock_settings,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13323: /* module 52 call 11 */
        switch (itemIdx) {
        case 0: /* nfts_transfer_ownership_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_transfer_ownership_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_transfer_ownership_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_transfer_ownership_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13324: /* module 52 call 12 */
        switch (itemIdx) {
        case 0: /* nfts_set_team_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_set_team_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_set_team_V14 - issuer */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.nfts_set_team_V14.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_set_team_V14 - admin */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.nfts_set_team_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_set_team_V14 - freezer */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.nfts_set_team_V14.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13325: /* module 52 call 13 */
        switch (itemIdx) {
        case 0: /* nfts_force_collection_owner_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_force_collection_owner_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_force_collection_owner_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_force_collection_owner_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13326: /* module 52 call 14 */
        switch (itemIdx) {
        case 0: /* nfts_force_collection_config_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_force_collection_config_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_force_collection_config_V14 - config */;
            return _toStringCollectionConfigFor(
                &m->basic.nfts_force_collection_config_V14.config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13327: /* module 52 call 15 */
        switch (itemIdx) {
        case 0: /* nfts_approve_transfer_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_approve_transfer_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_approve_transfer_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_approve_transfer_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_approve_transfer_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_approve_transfer_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_approve_transfer_V14 - maybe_deadline */;
            return _toStringOptionBlockNumber(
                &m->basic.nfts_approve_transfer_V14.maybe_deadline,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13328: /* module 52 call 16 */
        switch (itemIdx) {
        case 0: /* nfts_cancel_approval_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_cancel_approval_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_cancel_approval_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_cancel_approval_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_cancel_approval_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_cancel_approval_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13329: /* module 52 call 17 */
        switch (itemIdx) {
        case 0: /* nfts_clear_all_transfer_approvals_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_clear_all_transfer_approvals_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_clear_all_transfer_approvals_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_clear_all_transfer_approvals_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13330: /* module 52 call 18 */
        switch (itemIdx) {
        case 0: /* nfts_lock_item_properties_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_lock_item_properties_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_lock_item_properties_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_lock_item_properties_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_lock_item_properties_V14 - lock_metadata */;
            return _toStringbool(
                &m->basic.nfts_lock_item_properties_V14.lock_metadata,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_lock_item_properties_V14 - lock_attributes */;
            return _toStringbool(
                &m->basic.nfts_lock_item_properties_V14.lock_attributes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13331: /* module 52 call 19 */
        switch (itemIdx) {
        case 0: /* nfts_set_attribute_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_set_attribute_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_set_attribute_V14 - maybe_item */;
            return _toStringOptionItemId(
                &m->basic.nfts_set_attribute_V14.maybe_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_set_attribute_V14 - namespace_ */;
            return _toStringAttributeNamespaceAccountId(
                &m->basic.nfts_set_attribute_V14.namespace_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_set_attribute_V14 - key */;
            return _toStringBoundedVecu8(
                &m->basic.nfts_set_attribute_V14.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nfts_set_attribute_V14 - value */;
            return _toStringBoundedVecu8(
                &m->basic.nfts_set_attribute_V14.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13332: /* module 52 call 20 */
        switch (itemIdx) {
        case 0: /* nfts_force_set_attribute_V14 - set_as */;
            return _toStringOptionAccountId(
                &m->basic.nfts_force_set_attribute_V14.set_as,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_force_set_attribute_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_force_set_attribute_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_force_set_attribute_V14 - maybe_item */;
            return _toStringOptionItemId(
                &m->basic.nfts_force_set_attribute_V14.maybe_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_force_set_attribute_V14 - namespace_ */;
            return _toStringAttributeNamespaceAccountId(
                &m->basic.nfts_force_set_attribute_V14.namespace_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nfts_force_set_attribute_V14 - key */;
            return _toStringBoundedVecu8(
                &m->basic.nfts_force_set_attribute_V14.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* nfts_force_set_attribute_V14 - value */;
            return _toStringBoundedVecu8(
                &m->basic.nfts_force_set_attribute_V14.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13333: /* module 52 call 21 */
        switch (itemIdx) {
        case 0: /* nfts_clear_attribute_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_clear_attribute_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_clear_attribute_V14 - maybe_item */;
            return _toStringOptionItemId(
                &m->basic.nfts_clear_attribute_V14.maybe_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_clear_attribute_V14 - namespace_ */;
            return _toStringAttributeNamespaceAccountId(
                &m->basic.nfts_clear_attribute_V14.namespace_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_clear_attribute_V14 - key */;
            return _toStringBoundedVecu8(
                &m->basic.nfts_clear_attribute_V14.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13334: /* module 52 call 22 */
        switch (itemIdx) {
        case 0: /* nfts_approve_item_attributes_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_approve_item_attributes_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_approve_item_attributes_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_approve_item_attributes_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_approve_item_attributes_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_approve_item_attributes_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13335: /* module 52 call 23 */
        switch (itemIdx) {
        case 0: /* nfts_cancel_item_attributes_approval_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_cancel_item_attributes_approval_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_cancel_item_attributes_approval_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_cancel_item_attributes_approval_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_cancel_item_attributes_approval_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nfts_cancel_item_attributes_approval_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_cancel_item_attributes_approval_V14 - witness */;
            return _toStringCancelAttributesApprovalWitness(
                &m->basic.nfts_cancel_item_attributes_approval_V14.witness,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13336: /* module 52 call 24 */
        switch (itemIdx) {
        case 0: /* nfts_set_metadata_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_set_metadata_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_set_metadata_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_set_metadata_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_set_metadata_V14 - data */;
            return _toStringBoundedVecu8(
                &m->basic.nfts_set_metadata_V14.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13337: /* module 52 call 25 */
        switch (itemIdx) {
        case 0: /* nfts_clear_metadata_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_clear_metadata_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_clear_metadata_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_clear_metadata_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13338: /* module 52 call 26 */
        switch (itemIdx) {
        case 0: /* nfts_set_collection_metadata_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_set_collection_metadata_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_set_collection_metadata_V14 - data */;
            return _toStringBoundedVecu8(
                &m->basic.nfts_set_collection_metadata_V14.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13339: /* module 52 call 27 */
        switch (itemIdx) {
        case 0: /* nfts_clear_collection_metadata_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_clear_collection_metadata_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13340: /* module 52 call 28 */
        switch (itemIdx) {
        case 0: /* nfts_set_accept_ownership_V14 - maybe_collection */;
            return _toStringOptionCollectionId(
                &m->basic.nfts_set_accept_ownership_V14.maybe_collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13341: /* module 52 call 29 */
        switch (itemIdx) {
        case 0: /* nfts_set_collection_max_supply_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_set_collection_max_supply_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_set_collection_max_supply_V14 - max_supply */;
            return _toStringu32(
                &m->basic.nfts_set_collection_max_supply_V14.max_supply,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13342: /* module 52 call 30 */
        switch (itemIdx) {
        case 0: /* nfts_update_mint_settings_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_update_mint_settings_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_update_mint_settings_V14 - mint_settings */;
            return _toStringMintSettings(
                &m->basic.nfts_update_mint_settings_V14.mint_settings,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13343: /* module 52 call 31 */
        switch (itemIdx) {
        case 0: /* nfts_set_price_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_set_price_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_set_price_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_set_price_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_set_price_V14 - price */;
            return _toStringOptionItemPrice(
                &m->basic.nfts_set_price_V14.price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_set_price_V14 - whitelisted_buyer */;
            return _toStringOptionAccountIdLookupOfT(
                &m->basic.nfts_set_price_V14.whitelisted_buyer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13344: /* module 52 call 32 */
        switch (itemIdx) {
        case 0: /* nfts_buy_item_V14 - collection */;
            return _toStringCollectionId(
                &m->basic.nfts_buy_item_V14.collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_buy_item_V14 - item */;
            return _toStringItemId(
                &m->basic.nfts_buy_item_V14.item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_buy_item_V14 - bid_price */;
            return _toStringItemPrice(
                &m->basic.nfts_buy_item_V14.bid_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13345: /* module 52 call 33 */
        switch (itemIdx) {
        case 0: /* nfts_pay_tips_V14 - tips */;
            return _toStringVecItemTipOfMaxTips(
                &m->basic.nfts_pay_tips_V14.tips,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13346: /* module 52 call 34 */
        switch (itemIdx) {
        case 0: /* nfts_create_swap_V14 - offered_collection */;
            return _toStringCollectionId(
                &m->basic.nfts_create_swap_V14.offered_collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_create_swap_V14 - offered_item */;
            return _toStringItemId(
                &m->basic.nfts_create_swap_V14.offered_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_create_swap_V14 - desired_collection */;
            return _toStringCollectionId(
                &m->basic.nfts_create_swap_V14.desired_collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_create_swap_V14 - maybe_desired_item */;
            return _toStringOptionItemId(
                &m->basic.nfts_create_swap_V14.maybe_desired_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nfts_create_swap_V14 - maybe_price */;
            return _toStringOptionPriceWithDirectionItemPrice(
                &m->basic.nfts_create_swap_V14.maybe_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* nfts_create_swap_V14 - duration */;
            return _toStringBlockNumber(
                &m->basic.nfts_create_swap_V14.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13347: /* module 52 call 35 */
        switch (itemIdx) {
        case 0: /* nfts_cancel_swap_V14 - offered_collection */;
            return _toStringCollectionId(
                &m->basic.nfts_cancel_swap_V14.offered_collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_cancel_swap_V14 - offered_item */;
            return _toStringItemId(
                &m->basic.nfts_cancel_swap_V14.offered_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13348: /* module 52 call 36 */
        switch (itemIdx) {
        case 0: /* nfts_claim_swap_V14 - send_collection */;
            return _toStringCollectionId(
                &m->basic.nfts_claim_swap_V14.send_collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nfts_claim_swap_V14 - send_item */;
            return _toStringItemId(
                &m->basic.nfts_claim_swap_V14.send_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nfts_claim_swap_V14 - receive_collection */;
            return _toStringCollectionId(
                &m->basic.nfts_claim_swap_V14.receive_collection,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nfts_claim_swap_V14 - receive_item */;
            return _toStringItemId(
                &m->basic.nfts_claim_swap_V14.receive_item,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nfts_claim_swap_V14 - witness_price */;
            return _toStringOptionPriceWithDirectionItemPrice(
                &m->basic.nfts_claim_swap_V14.witness_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13824: /* module 54 call 0 */
        switch (itemIdx) {
        case 0: /* nftfractionalization_fractionalize_V14 - nft_collection_id */;
            return _toStringu32(
                &m->basic.nftfractionalization_fractionalize_V14.nft_collection_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nftfractionalization_fractionalize_V14 - nft_id */;
            return _toStringu32(
                &m->basic.nftfractionalization_fractionalize_V14.nft_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nftfractionalization_fractionalize_V14 - asset_id */;
            return _toStringu32(
                &m->basic.nftfractionalization_fractionalize_V14.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nftfractionalization_fractionalize_V14 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nftfractionalization_fractionalize_V14.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nftfractionalization_fractionalize_V14 - fractions */;
            return _toStringu128(
                &m->basic.nftfractionalization_fractionalize_V14.fractions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13825: /* module 54 call 1 */
        switch (itemIdx) {
        case 0: /* nftfractionalization_unify_V14 - nft_collection_id */;
            return _toStringu32(
                &m->basic.nftfractionalization_unify_V14.nft_collection_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nftfractionalization_unify_V14 - nft_id */;
            return _toStringu32(
                &m->basic.nftfractionalization_unify_V14.nft_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nftfractionalization_unify_V14 - asset_id */;
            return _toStringu32(
                &m->basic.nftfractionalization_unify_V14.asset_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nftfractionalization_unify_V14 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.nftfractionalization_unify_V14.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14080: /* module 55 call 0 */
        switch (itemIdx) {
        case 0: /* poolassets_create_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_create_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_create_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_create_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_create_V14 - min_balance */;
            return _toStringBalance(
                &m->basic.poolassets_create_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14081: /* module 55 call 1 */
        switch (itemIdx) {
        case 0: /* poolassets_force_create_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_force_create_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_force_create_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_force_create_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_force_create_V14 - is_sufficient */;
            return _toStringbool(
                &m->basic.poolassets_force_create_V14.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* poolassets_force_create_V14 - min_balance */;
            return _toStringCompactBalance(
                &m->basic.poolassets_force_create_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14082: /* module 55 call 2 */
        switch (itemIdx) {
        case 0: /* poolassets_start_destroy_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_start_destroy_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14083: /* module 55 call 3 */
        switch (itemIdx) {
        case 0: /* poolassets_destroy_accounts_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_destroy_accounts_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14084: /* module 55 call 4 */
        switch (itemIdx) {
        case 0: /* poolassets_destroy_approvals_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_destroy_approvals_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14085: /* module 55 call 5 */
        switch (itemIdx) {
        case 0: /* poolassets_finish_destroy_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_finish_destroy_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14086: /* module 55 call 6 */
        switch (itemIdx) {
        case 0: /* poolassets_mint_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_mint_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_mint_V14 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_mint_V14.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_mint_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.poolassets_mint_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14087: /* module 55 call 7 */
        switch (itemIdx) {
        case 0: /* poolassets_burn_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_burn_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_burn_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_burn_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_burn_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.poolassets_burn_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14088: /* module 55 call 8 */
        switch (itemIdx) {
        case 0: /* poolassets_transfer_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_transfer_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_transfer_V14 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_transfer_V14.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.poolassets_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14089: /* module 55 call 9 */
        switch (itemIdx) {
        case 0: /* poolassets_transfer_keep_alive_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_transfer_keep_alive_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_transfer_keep_alive_V14 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_transfer_keep_alive_V14.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_transfer_keep_alive_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.poolassets_transfer_keep_alive_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14090: /* module 55 call 10 */
        switch (itemIdx) {
        case 0: /* poolassets_force_transfer_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_force_transfer_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_force_transfer_V14 - source */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_force_transfer_V14.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_force_transfer_V14 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_force_transfer_V14.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* poolassets_force_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.poolassets_force_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14091: /* module 55 call 11 */
        switch (itemIdx) {
        case 0: /* poolassets_freeze_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_freeze_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_freeze_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_freeze_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14092: /* module 55 call 12 */
        switch (itemIdx) {
        case 0: /* poolassets_thaw_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_thaw_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_thaw_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_thaw_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14093: /* module 55 call 13 */
        switch (itemIdx) {
        case 0: /* poolassets_freeze_asset_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_freeze_asset_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14094: /* module 55 call 14 */
        switch (itemIdx) {
        case 0: /* poolassets_thaw_asset_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_thaw_asset_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14095: /* module 55 call 15 */
        switch (itemIdx) {
        case 0: /* poolassets_transfer_ownership_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_transfer_ownership_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_transfer_ownership_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_transfer_ownership_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14096: /* module 55 call 16 */
        switch (itemIdx) {
        case 0: /* poolassets_set_team_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_set_team_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_set_team_V14 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_set_team_V14.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_set_team_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_set_team_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* poolassets_set_team_V14 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_set_team_V14.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14097: /* module 55 call 17 */
        switch (itemIdx) {
        case 0: /* poolassets_set_metadata_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_set_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_set_metadata_V14 - name */;
            return _toStringVecu8(
                &m->basic.poolassets_set_metadata_V14.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_set_metadata_V14 - symbol */;
            return _toStringVecu8(
                &m->basic.poolassets_set_metadata_V14.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* poolassets_set_metadata_V14 - decimals */;
            return _toStringu8(
                &m->basic.poolassets_set_metadata_V14.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14098: /* module 55 call 18 */
        switch (itemIdx) {
        case 0: /* poolassets_clear_metadata_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_clear_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14099: /* module 55 call 19 */
        switch (itemIdx) {
        case 0: /* poolassets_force_set_metadata_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_force_set_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_force_set_metadata_V14 - name */;
            return _toStringVecu8(
                &m->basic.poolassets_force_set_metadata_V14.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_force_set_metadata_V14 - symbol */;
            return _toStringVecu8(
                &m->basic.poolassets_force_set_metadata_V14.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* poolassets_force_set_metadata_V14 - decimals */;
            return _toStringu8(
                &m->basic.poolassets_force_set_metadata_V14.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* poolassets_force_set_metadata_V14 - is_frozen */;
            return _toStringbool(
                &m->basic.poolassets_force_set_metadata_V14.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14100: /* module 55 call 20 */
        switch (itemIdx) {
        case 0: /* poolassets_force_clear_metadata_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_force_clear_metadata_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14101: /* module 55 call 21 */
        switch (itemIdx) {
        case 0: /* poolassets_force_asset_status_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_force_asset_status_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_force_asset_status_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_force_asset_status_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_force_asset_status_V14 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_force_asset_status_V14.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* poolassets_force_asset_status_V14 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_force_asset_status_V14.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* poolassets_force_asset_status_V14 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_force_asset_status_V14.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* poolassets_force_asset_status_V14 - min_balance */;
            return _toStringCompactBalance(
                &m->basic.poolassets_force_asset_status_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* poolassets_force_asset_status_V14 - is_sufficient */;
            return _toStringbool(
                &m->basic.poolassets_force_asset_status_V14.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* poolassets_force_asset_status_V14 - is_frozen */;
            return _toStringbool(
                &m->basic.poolassets_force_asset_status_V14.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14102: /* module 55 call 22 */
        switch (itemIdx) {
        case 0: /* poolassets_approve_transfer_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_approve_transfer_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_approve_transfer_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_approve_transfer_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_approve_transfer_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.poolassets_approve_transfer_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14103: /* module 55 call 23 */
        switch (itemIdx) {
        case 0: /* poolassets_cancel_approval_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_cancel_approval_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_cancel_approval_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_cancel_approval_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14104: /* module 55 call 24 */
        switch (itemIdx) {
        case 0: /* poolassets_force_cancel_approval_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_force_cancel_approval_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_force_cancel_approval_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_force_cancel_approval_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_force_cancel_approval_V14 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_force_cancel_approval_V14.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14105: /* module 55 call 25 */
        switch (itemIdx) {
        case 0: /* poolassets_transfer_approved_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_transfer_approved_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_transfer_approved_V14 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_transfer_approved_V14.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* poolassets_transfer_approved_V14 - destination */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_transfer_approved_V14.destination,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* poolassets_transfer_approved_V14 - amount */;
            return _toStringCompactBalance(
                &m->basic.poolassets_transfer_approved_V14.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14106: /* module 55 call 26 */
        switch (itemIdx) {
        case 0: /* poolassets_touch_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_touch_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14107: /* module 55 call 27 */
        switch (itemIdx) {
        case 0: /* poolassets_refund_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_refund_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_refund_V14 - allow_burn */;
            return _toStringbool(
                &m->basic.poolassets_refund_V14.allow_burn,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14108: /* module 55 call 28 */
        switch (itemIdx) {
        case 0: /* poolassets_set_min_balance_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_set_min_balance_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_set_min_balance_V14 - min_balance */;
            return _toStringBalance(
                &m->basic.poolassets_set_min_balance_V14.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14109: /* module 55 call 29 */
        switch (itemIdx) {
        case 0: /* poolassets_touch_other_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_touch_other_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_touch_other_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_touch_other_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14110: /* module 55 call 30 */
        switch (itemIdx) {
        case 0: /* poolassets_refund_other_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_refund_other_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_refund_other_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_refund_other_V14.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14111: /* module 55 call 31 */
        switch (itemIdx) {
        case 0: /* poolassets_block_V14 - id */;
            return _toStringu32(
                &m->basic.poolassets_block_V14.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* poolassets_block_V14 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.poolassets_block_V14.who,
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

bool _getMethod_ItemIsExpert_V14(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V14(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: // Timestamp:Set
    case 2565: // Balances:Force unreserve
    case 2566: // Balances:Upgrade accounts
    case 2568: // Balances:Force set balance
    case 5376: // CollatorSelection:Set invulnerables
    case 5377: // CollatorSelection:Set desired candidates
    case 5378: // CollatorSelection:Set candidacy bond
    case 5379: // CollatorSelection:Register as candidate
    case 5380: // CollatorSelection:Leave intent
    case 5381: // CollatorSelection:Add invulnerable
    case 5382: // CollatorSelection:Remove invulnerable
    case 7680: // XcmpQueue:Service overweight
    case 7681: // XcmpQueue:Suspend xcm execution
    case 7682: // XcmpQueue:Resume xcm execution
    case 7683: // XcmpQueue:Update suspend threshold
    case 7684: // XcmpQueue:Update drop threshold
    case 7685: // XcmpQueue:Update resume threshold
    case 7686: // XcmpQueue:Update threshold weight
    case 7687: // XcmpQueue:Update weight restrict decay
    case 7688: // XcmpQueue:Update xcmp max individual weight
    case 7937: // PolkadotXcm:Teleport assets
    case 7938: // PolkadotXcm:Reserve transfer assets
    case 7944: // PolkadotXcm:Limited reserve transfer assets
    case 7945: // PolkadotXcm:Limited teleport assets
    case 8448: // DmpQueue:Service overweight
    case 10240: // Utility:Batch
    case 10242: // Utility:Batch all
    case 10244: // Utility:Force batch
    case 10245: // Utility:With weight
    case 10755: // Proxy:Remove proxies
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
    case 12828: // Assets:Set min balance
    case 12829: // Assets:Touch other
    case 12830: // Assets:Refund other
    case 12831: // Assets:Block
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
    case 13312: // Nfts:Create
    case 13313: // Nfts:Force create
    case 13314: // Nfts:Destroy
    case 13315: // Nfts:Mint
    case 13316: // Nfts:Force mint
    case 13317: // Nfts:Burn
    case 13318: // Nfts:Transfer
    case 13319: // Nfts:Redeposit
    case 13320: // Nfts:Lock item transfer
    case 13321: // Nfts:Unlock item transfer
    case 13322: // Nfts:Lock collection
    case 13323: // Nfts:Transfer ownership
    case 13324: // Nfts:Set team
    case 13325: // Nfts:Force collection owner
    case 13326: // Nfts:Force collection config
    case 13327: // Nfts:Approve transfer
    case 13328: // Nfts:Cancel approval
    case 13329: // Nfts:Clear all transfer approvals
    case 13330: // Nfts:Lock item properties
    case 13331: // Nfts:Set attribute
    case 13332: // Nfts:Force set attribute
    case 13333: // Nfts:Clear attribute
    case 13334: // Nfts:Approve item attributes
    case 13335: // Nfts:Cancel item attributes approval
    case 13336: // Nfts:Set metadata
    case 13337: // Nfts:Clear metadata
    case 13338: // Nfts:Set collection metadata
    case 13339: // Nfts:Clear collection metadata
    case 13340: // Nfts:Set accept ownership
    case 13341: // Nfts:Set collection max supply
    case 13342: // Nfts:Update mint settings
    case 13343: // Nfts:Set price
    case 13344: // Nfts:Buy item
    case 13345: // Nfts:Pay tips
    case 13346: // Nfts:Create swap
    case 13347: // Nfts:Cancel swap
    case 13348: // Nfts:Claim swap
    case 13568: // ForeignAssets:Create
    case 13569: // ForeignAssets:Force create
    case 13570: // ForeignAssets:Start destroy
    case 13571: // ForeignAssets:Destroy accounts
    case 13572: // ForeignAssets:Destroy approvals
    case 13573: // ForeignAssets:Finish destroy
    case 13574: // ForeignAssets:Mint
    case 13575: // ForeignAssets:Burn
    case 13576: // ForeignAssets:Transfer
    case 13577: // ForeignAssets:Transfer keep alive
    case 13578: // ForeignAssets:Force transfer
    case 13579: // ForeignAssets:Freeze
    case 13580: // ForeignAssets:Thaw
    case 13581: // ForeignAssets:Freeze asset
    case 13582: // ForeignAssets:Thaw asset
    case 13583: // ForeignAssets:Transfer ownership
    case 13584: // ForeignAssets:Set team
    case 13585: // ForeignAssets:Set metadata
    case 13586: // ForeignAssets:Clear metadata
    case 13587: // ForeignAssets:Force set metadata
    case 13588: // ForeignAssets:Force clear metadata
    case 13589: // ForeignAssets:Force asset status
    case 13590: // ForeignAssets:Approve transfer
    case 13591: // ForeignAssets:Cancel approval
    case 13592: // ForeignAssets:Force cancel approval
    case 13593: // ForeignAssets:Transfer approved
    case 13594: // ForeignAssets:Touch
    case 13595: // ForeignAssets:Refund
    case 13596: // ForeignAssets:Set min balance
    case 13597: // ForeignAssets:Touch other
    case 13598: // ForeignAssets:Refund other
    case 13599: // ForeignAssets:Block
    case 13824: // NftFractionalization:Fractionalize
    case 13825: // NftFractionalization:Unify
    case 14080: // PoolAssets:Create
    case 14081: // PoolAssets:Force create
    case 14082: // PoolAssets:Start destroy
    case 14083: // PoolAssets:Destroy accounts
    case 14084: // PoolAssets:Destroy approvals
    case 14085: // PoolAssets:Finish destroy
    case 14086: // PoolAssets:Mint
    case 14087: // PoolAssets:Burn
    case 14088: // PoolAssets:Transfer
    case 14089: // PoolAssets:Transfer keep alive
    case 14090: // PoolAssets:Force transfer
    case 14091: // PoolAssets:Freeze
    case 14092: // PoolAssets:Thaw
    case 14093: // PoolAssets:Freeze asset
    case 14094: // PoolAssets:Thaw asset
    case 14095: // PoolAssets:Transfer ownership
    case 14096: // PoolAssets:Set team
    case 14097: // PoolAssets:Set metadata
    case 14098: // PoolAssets:Clear metadata
    case 14099: // PoolAssets:Force set metadata
    case 14100: // PoolAssets:Force clear metadata
    case 14101: // PoolAssets:Force asset status
    case 14102: // PoolAssets:Approve transfer
    case 14103: // PoolAssets:Cancel approval
    case 14104: // PoolAssets:Force cancel approval
    case 14105: // PoolAssets:Transfer approved
    case 14106: // PoolAssets:Touch
    case 14107: // PoolAssets:Refund
    case 14108: // PoolAssets:Set min balance
    case 14109: // PoolAssets:Touch other
    case 14110: // PoolAssets:Refund other
    case 14111: // PoolAssets:Block
    case 14336: // AssetConversion:Create pool
    case 14337: // AssetConversion:Add liquidity
    case 14338: // AssetConversion:Remove liquidity
    case 14339: // AssetConversion:Swap exact tokens for tokens
    case 14340: // AssetConversion:Swap tokens for exact tokens
        return false;
    default:
        return true;
    }
}
