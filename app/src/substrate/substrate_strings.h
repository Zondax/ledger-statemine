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

// Modules names
static const char* STR_MO_SYSTEM = "System";
static const char* STR_MO_TIMESTAMP = "Timestamp";
static const char* STR_MO_BALANCES = "Balances";
static const char* STR_MO_COLLATORSELECTION = "Collatorselection";
static const char* STR_MO_SESSION = "Session";
static const char* STR_MO_XCMPQUEUE = "Xcmpqueue";
static const char* STR_MO_DMPQUEUE = "Dmpqueue";
static const char* STR_MO_UTILITY = "Utility";
static const char* STR_MO_MULTISIG = "Multisig";
static const char* STR_MO_PROXY = "Proxy";
static const char* STR_MO_ASSETS = "Assets";
static const char* STR_MO_UNIQUES = "Uniques";

// Methods names
static const char* STR_ME_FILL_BLOCK = "Fill block";
static const char* STR_ME_REMARK = "Remark";
static const char* STR_ME_SET_HEAP_PAGES = "Set heap pages";
static const char* STR_ME_SET_CODE = "Set code";
static const char* STR_ME_SET_CODE_WITHOUT_CHECKS = "Set code without checks";
static const char* STR_ME_REMARK_WITH_EVENT = "Remark with event";
static const char* STR_ME_SET = "Set";
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_SET_BALANCE = "Set balance";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_FORCE_UNRESERVE = "Force unreserve";
static const char* STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char* STR_ME_SET_DESIRED_CANDIDATES = "Set desired candidates";
static const char* STR_ME_SET_CANDIDACY_BOND = "Set candidacy bond";
static const char* STR_ME_REGISTER_AS_CANDIDATE = "Register as candidate";
static const char* STR_ME_LEAVE_INTENT = "Leave intent";
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
static const char* STR_ME_BATCH = "Batch";
static const char* STR_ME_BATCH_ALL = "Batch all";
static const char* STR_ME_FORCE_BATCH = "Force batch";
static const char* STR_ME_AS_MULTI_THRESHOLD_1 = "As multi threshold 1";
static const char* STR_ME_AS_MULTI = "As multi";
static const char* STR_ME_APPROVE_AS_MULTI = "Approve as multi";
static const char* STR_ME_CANCEL_AS_MULTI = "Cancel as multi";
static const char* STR_ME_PROXY = "Proxy";
static const char* STR_ME_ADD_PROXY = "Add proxy";
static const char* STR_ME_REMOVE_PROXY = "Remove proxy";
static const char* STR_ME_REMOVE_PROXIES = "Remove proxies";
static const char* STR_ME_ANONYMOUS = "Anonymous";
static const char* STR_ME_KILL_ANONYMOUS = "Kill anonymous";
static const char* STR_ME_ANNOUNCE = "Announce";
static const char* STR_ME_REMOVE_ANNOUNCEMENT = "Remove announcement";
static const char* STR_ME_REJECT_ANNOUNCEMENT = "Reject announcement";
static const char* STR_ME_PROXY_ANNOUNCED = "Proxy announced";
static const char* STR_ME_CREATE = "Create";
static const char* STR_ME_FORCE_CREATE = "Force create";
static const char* STR_ME_DESTROY = "Destroy";
static const char* STR_ME_MINT = "Mint";
static const char* STR_ME_BURN = "Burn";
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

// Items names
static const char* STR_IT_ratio = "Ratio";
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
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_new_reserved = "New reserved";
static const char* STR_IT_source = "Source";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_new_ = "New";
static const char* STR_IT_max = "Max";
static const char* STR_IT_bond = "Bond";
static const char* STR_IT_proof = "Proof";
static const char* STR_IT_index = "Index";
static const char* STR_IT_weight_limit = "Weight limit";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_call = "Call";
static const char* STR_IT_as_origin = "As origin";
static const char* STR_IT_other_signatories = "Other signatories";
static const char* STR_IT_threshold = "Threshold";
static const char* STR_IT_maybe_timepoint = "Maybe timepoint";
static const char* STR_IT_store_call = "Store call";
static const char* STR_IT_max_weight = "Max weight";
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
static const char* STR_IT_witness = "Witness";
static const char* STR_IT_beneficiary = "Beneficiary";
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

#ifdef __cplusplus
}
#endif
