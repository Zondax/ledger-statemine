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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Modules names
static const char* STR_MO_SYSTEM = "System";
static const char* STR_MO_TIMESTAMP = "Timestamp";
static const char* STR_MO_BALANCES = "Balances";
static const char* STR_MO_COLLATORSELECTION = "Collatorselection";
static const char* STR_MO_SESSION = "Session";
static const char* STR_MO_XCMPQUEUE = "Xcmpqueue";
static const char* STR_MO_POLKADOTXCM = "Polkadotxcm";
static const char* STR_MO_DMPQUEUE = "Dmpqueue";
static const char* STR_MO_UTILITY = "Utility";
static const char* STR_MO_MULTISIG = "Multisig";
static const char* STR_MO_PROXY = "Proxy";
static const char* STR_MO_ASSETS = "Assets";
static const char* STR_MO_UNIQUES = "Uniques";
static const char* STR_MO_NFTS = "Nfts";
static const char* STR_MO_FOREIGNASSETS = "Foreignassets";
static const char* STR_MO_NFTFRACTIONALIZATION = "Nftfractionalization";
static const char* STR_MO_POOLASSETS = "Poolassets";
static const char* STR_MO_ASSETCONVERSION = "Assetconversion";

// Methods names
static const char* STR_ME_REMARK = "Remark";
static const char* STR_ME_SET_HEAP_PAGES = "Set heap pages";
static const char* STR_ME_SET_CODE = "Set code";
static const char* STR_ME_SET_CODE_WITHOUT_CHECKS = "Set code without checks";
static const char* STR_ME_REMARK_WITH_EVENT = "Remark with event";
static const char* STR_ME_SET = "Set";
static const char* STR_ME_TRANSFER_ALLOW_DEATH = "Transfer allow death";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_FORCE_UNRESERVE = "Force unreserve";
static const char* STR_ME_UPGRADE_ACCOUNTS = "Upgrade accounts";
static const char* STR_ME_FORCE_SET_BALANCE = "Force set balance";
static const char* STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char* STR_ME_SET_DESIRED_CANDIDATES = "Set desired candidates";
static const char* STR_ME_SET_CANDIDACY_BOND = "Set candidacy bond";
static const char* STR_ME_REGISTER_AS_CANDIDATE = "Register as candidate";
static const char* STR_ME_LEAVE_INTENT = "Leave intent";
static const char* STR_ME_ADD_INVULNERABLE = "Add invulnerable";
static const char* STR_ME_REMOVE_INVULNERABLE = "Remove invulnerable";
static const char* STR_ME_SET_KEYS = "Set keys";
static const char* STR_ME_PURGE_KEYS = "Purge keys";
static const char* STR_ME_SERVICE_OVERWEIGHT = "Service overweight";
static const char* STR_ME_SUSPEND_XCM_EXECUTION = "Suspend xcm execution";
static const char* STR_ME_RESUME_XCM_EXECUTION = "Resume xcm execution";
static const char* STR_ME_UPDATE_SUSPEND_THRESHOLD = "Update suspend threshold";
static const char* STR_ME_UPDATE_DROP_THRESHOLD = "Update drop threshold";
static const char* STR_ME_UPDATE_RESUME_THRESHOLD = "Update resume threshold";
static const char* STR_ME_UPDATE_THRESHOLD_WEIGHT = "Update threshold weight";
static const char* STR_ME_UPDATE_WEIGHT_RESTRICT_DECAY = "Update weight restrict decay";
static const char* STR_ME_UPDATE_XCMP_MAX_INDIVIDUAL_WEIGHT = "Update xcmp max individual weight";
static const char* STR_ME_TELEPORT_ASSETS = "Teleport assets";
static const char* STR_ME_RESERVE_TRANSFER_ASSETS = "Reserve transfer assets";
static const char* STR_ME_LIMITED_RESERVE_TRANSFER_ASSETS = "Limited reserve transfer assets";
static const char* STR_ME_LIMITED_TELEPORT_ASSETS = "Limited teleport assets";
static const char* STR_ME_BATCH = "Batch";
static const char* STR_ME_BATCH_ALL = "Batch all";
static const char* STR_ME_FORCE_BATCH = "Force batch";
static const char* STR_ME_WITH_WEIGHT = "With weight";
static const char* STR_ME_AS_MULTI_THRESHOLD_1 = "As multi threshold 1";
static const char* STR_ME_AS_MULTI = "As multi";
static const char* STR_ME_APPROVE_AS_MULTI = "Approve as multi";
static const char* STR_ME_CANCEL_AS_MULTI = "Cancel as multi";
static const char* STR_ME_PROXY = "Proxy";
static const char* STR_ME_ADD_PROXY = "Add proxy";
static const char* STR_ME_REMOVE_PROXY = "Remove proxy";
static const char* STR_ME_REMOVE_PROXIES = "Remove proxies";
static const char* STR_ME_CREATE_PURE = "Create pure";
static const char* STR_ME_KILL_PURE = "Kill pure";
static const char* STR_ME_ANNOUNCE = "Announce";
static const char* STR_ME_REMOVE_ANNOUNCEMENT = "Remove announcement";
static const char* STR_ME_REJECT_ANNOUNCEMENT = "Reject announcement";
static const char* STR_ME_PROXY_ANNOUNCED = "Proxy announced";
static const char* STR_ME_CREATE = "Create";
static const char* STR_ME_FORCE_CREATE = "Force create";
static const char* STR_ME_START_DESTROY = "Start destroy";
static const char* STR_ME_DESTROY_ACCOUNTS = "Destroy accounts";
static const char* STR_ME_DESTROY_APPROVALS = "Destroy approvals";
static const char* STR_ME_FINISH_DESTROY = "Finish destroy";
static const char* STR_ME_MINT = "Mint";
static const char* STR_ME_BURN = "Burn";
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_FREEZE = "Freeze";
static const char* STR_ME_THAW = "Thaw";
static const char* STR_ME_FREEZE_ASSET = "Freeze asset";
static const char* STR_ME_THAW_ASSET = "Thaw asset";
static const char* STR_ME_TRANSFER_OWNERSHIP = "Transfer ownership";
static const char* STR_ME_SET_TEAM = "Set team";
static const char* STR_ME_SET_METADATA = "Set metadata";
static const char* STR_ME_CLEAR_METADATA = "Clear metadata";
static const char* STR_ME_FORCE_SET_METADATA = "Force set metadata";
static const char* STR_ME_FORCE_CLEAR_METADATA = "Force clear metadata";
static const char* STR_ME_FORCE_ASSET_STATUS = "Force asset status";
static const char* STR_ME_APPROVE_TRANSFER = "Approve transfer";
static const char* STR_ME_CANCEL_APPROVAL = "Cancel approval";
static const char* STR_ME_FORCE_CANCEL_APPROVAL = "Force cancel approval";
static const char* STR_ME_TRANSFER_APPROVED = "Transfer approved";
static const char* STR_ME_TOUCH = "Touch";
static const char* STR_ME_REFUND = "Refund";
static const char* STR_ME_SET_MIN_BALANCE = "Set min balance";
static const char* STR_ME_TOUCH_OTHER = "Touch other";
static const char* STR_ME_REFUND_OTHER = "Refund other";
static const char* STR_ME_BLOCK = "Block";
static const char* STR_ME_DESTROY = "Destroy";
static const char* STR_ME_REDEPOSIT = "Redeposit";
static const char* STR_ME_FREEZE_COLLECTION = "Freeze collection";
static const char* STR_ME_THAW_COLLECTION = "Thaw collection";
static const char* STR_ME_FORCE_ITEM_STATUS = "Force item status";
static const char* STR_ME_SET_ATTRIBUTE = "Set attribute";
static const char* STR_ME_CLEAR_ATTRIBUTE = "Clear attribute";
static const char* STR_ME_SET_COLLECTION_METADATA = "Set collection metadata";
static const char* STR_ME_CLEAR_COLLECTION_METADATA = "Clear collection metadata";
static const char* STR_ME_SET_ACCEPT_OWNERSHIP = "Set accept ownership";
static const char* STR_ME_SET_COLLECTION_MAX_SUPPLY = "Set collection max supply";
static const char* STR_ME_SET_PRICE = "Set price";
static const char* STR_ME_BUY_ITEM = "Buy item";
static const char* STR_ME_FORCE_MINT = "Force mint";
static const char* STR_ME_LOCK_ITEM_TRANSFER = "Lock item transfer";
static const char* STR_ME_UNLOCK_ITEM_TRANSFER = "Unlock item transfer";
static const char* STR_ME_LOCK_COLLECTION = "Lock collection";
static const char* STR_ME_FORCE_COLLECTION_OWNER = "Force collection owner";
static const char* STR_ME_FORCE_COLLECTION_CONFIG = "Force collection config";
static const char* STR_ME_CLEAR_ALL_TRANSFER_APPROVALS = "Clear all transfer approvals";
static const char* STR_ME_LOCK_ITEM_PROPERTIES = "Lock item properties";
static const char* STR_ME_FORCE_SET_ATTRIBUTE = "Force set attribute";
static const char* STR_ME_APPROVE_ITEM_ATTRIBUTES = "Approve item attributes";
static const char* STR_ME_CANCEL_ITEM_ATTRIBUTES_APPROVAL = "Cancel item attributes approval";
static const char* STR_ME_UPDATE_MINT_SETTINGS = "Update mint settings";
static const char* STR_ME_PAY_TIPS = "Pay tips";
static const char* STR_ME_CREATE_SWAP = "Create swap";
static const char* STR_ME_CANCEL_SWAP = "Cancel swap";
static const char* STR_ME_CLAIM_SWAP = "Claim swap";
static const char* STR_ME_FRACTIONALIZE = "Fractionalize";
static const char* STR_ME_UNIFY = "Unify";
static const char* STR_ME_CREATE_POOL = "Create pool";
static const char* STR_ME_ADD_LIQUIDITY = "Add liquidity";
static const char* STR_ME_REMOVE_LIQUIDITY = "Remove liquidity";
static const char* STR_ME_SWAP_EXACT_TOKENS_FOR_TOKENS = "Swap exact tokens for tokens";
static const char* STR_ME_SWAP_TOKENS_FOR_EXACT_TOKENS = "Swap tokens for exact tokens";

// Items names
static const char* STR_IT_remark = "Remark";
static const char* STR_IT_pages = "Pages";
static const char* STR_IT_code = "Code";
static const char* STR_IT_items = "Items";
static const char* STR_IT_keys = "Keys";
static const char* STR_IT_prefix = "Prefix";
static const char* STR_IT_subkeys = "Subkeys";
static const char* STR_IT_now = "Now";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_source = "Source";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_new_ = "New";
static const char* STR_IT_max = "Max";
static const char* STR_IT_bond = "Bond";
static const char* STR_IT_proof = "Proof";
static const char* STR_IT_index = "Index";
static const char* STR_IT_weight_limit = "Weight limit";
static const char* STR_IT_message = "Message";
static const char* STR_IT_beneficiary = "Beneficiary";
static const char* STR_IT_assets = "Assets";
static const char* STR_IT_fee_asset_item = "Fee asset item";
static const char* STR_IT_max_weight = "Max weight";
static const char* STR_IT_location = "Location";
static const char* STR_IT_version = "Version";
static const char* STR_IT_maybe_xcm_version = "Maybe xcm version";
static const char* STR_IT_suspended = "Suspended";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_call = "Call";
static const char* STR_IT_as_origin = "As origin";
static const char* STR_IT_weight = "Weight";
static const char* STR_IT_other_signatories = "Other signatories";
static const char* STR_IT_threshold = "Threshold";
static const char* STR_IT_maybe_timepoint = "Maybe timepoint";
static const char* STR_IT_call_hash = "Call hash";
static const char* STR_IT_timepoint = "Timepoint";
static const char* STR_IT_real = "Real";
static const char* STR_IT_force_proxy_type = "Force proxy type";
static const char* STR_IT_delegate = "Delegate";
static const char* STR_IT_proxy_type = "Proxy type";
static const char* STR_IT_delay = "Delay";
static const char* STR_IT_spawner = "Spawner";
static const char* STR_IT_height = "Height";
static const char* STR_IT_ext_index = "Ext index";
static const char* STR_IT_id = "Id";
static const char* STR_IT_admin = "Admin";
static const char* STR_IT_min_balance = "Min balance";
static const char* STR_IT_owner = "Owner";
static const char* STR_IT_is_sufficient = "Is sufficient";
static const char* STR_IT_target = "Target";
static const char* STR_IT_issuer = "Issuer";
static const char* STR_IT_freezer = "Freezer";
static const char* STR_IT_name = "Name";
static const char* STR_IT_symbol = "Symbol";
static const char* STR_IT_decimals = "Decimals";
static const char* STR_IT_is_frozen = "Is frozen";
static const char* STR_IT_destination = "Destination";
static const char* STR_IT_allow_burn = "Allow burn";
static const char* STR_IT_collection = "Collection";
static const char* STR_IT_free_holding = "Free holding";
static const char* STR_IT_witness = "Witness";
static const char* STR_IT_item = "Item";
static const char* STR_IT_check_owner = "Check owner";
static const char* STR_IT_maybe_check_delegate = "Maybe check delegate";
static const char* STR_IT_maybe_item = "Maybe item";
static const char* STR_IT_key = "Key";
static const char* STR_IT_value = "Value";
static const char* STR_IT_data = "Data";
static const char* STR_IT_maybe_collection = "Maybe collection";
static const char* STR_IT_max_supply = "Max supply";
static const char* STR_IT_price = "Price";
static const char* STR_IT_whitelisted_buyer = "Whitelisted buyer";
static const char* STR_IT_bid_price = "Bid price";
static const char* STR_IT_config = "Config";
static const char* STR_IT_mint_to = "Mint to";
static const char* STR_IT_witness_data = "Witness data";
static const char* STR_IT_item_config = "Item config";
static const char* STR_IT_lock_settings = "Lock settings";
static const char* STR_IT_maybe_deadline = "Maybe deadline";
static const char* STR_IT_lock_metadata = "Lock metadata";
static const char* STR_IT_lock_attributes = "Lock attributes";
static const char* STR_IT_namespace_ = "namespace_";
static const char* STR_IT_set_as = "Set as";
static const char* STR_IT_mint_settings = "Mint settings";
static const char* STR_IT_tips = "Tips";
static const char* STR_IT_offered_collection = "Offered collection";
static const char* STR_IT_offered_item = "Offered item";
static const char* STR_IT_desired_collection = "Desired collection";
static const char* STR_IT_maybe_desired_item = "Maybe desired item";
static const char* STR_IT_maybe_price = "Maybe price";
static const char* STR_IT_duration = "Duration";
static const char* STR_IT_send_collection = "Send collection";
static const char* STR_IT_send_item = "Send item";
static const char* STR_IT_receive_collection = "Receive collection";
static const char* STR_IT_receive_item = "Receive item";
static const char* STR_IT_witness_price = "Witness price";
static const char* STR_IT_mint_data = "Mint data";
static const char* STR_IT_signature = "Signature";
static const char* STR_IT_signer = "Signer";
static const char* STR_IT_nft_collection_id = "Nft collection id";
static const char* STR_IT_nft_id = "Nft id";
static const char* STR_IT_asset_id = "Asset id";
static const char* STR_IT_fractions = "Fractions";
static const char* STR_IT_asset1 = "Asset1";
static const char* STR_IT_asset2 = "Asset2";
static const char* STR_IT_amount1_desired = "Amount1 desired";
static const char* STR_IT_amount2_desired = "Amount2 desired";
static const char* STR_IT_amount1_min = "Amount1 min";
static const char* STR_IT_amount2_min = "Amount2 min";
static const char* STR_IT_lp_token_burn = "Lp token burn";
static const char* STR_IT_amount1_min_receive = "Amount1 min receive";
static const char* STR_IT_amount2_min_receive = "Amount2 min receive";
static const char* STR_IT_withdraw_to = "Withdraw to";
static const char* STR_IT_path = "Path";
static const char* STR_IT_amount_in = "Amount in";
static const char* STR_IT_amount_out_min = "Amount out min";
static const char* STR_IT_send_to = "Send to";
static const char* STR_IT_amount_out = "Amount out";
static const char* STR_IT_amount_in_max = "Amount in max";

#ifdef __cplusplus
}
#endif
