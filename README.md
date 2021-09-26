# Ledger Statemine app
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![CircleCI](https://circleci.com/gh/Zondax/ledger-statemine.svg?style=shield)](https://circleci.com/gh/Zondax/ledger-statemine)

![zondax](docs/zondax.jpg)

_Please visit our website at [zondax.ch](zondax.ch)_

------------------
This project contains the Statemine app (https://kusama.network/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# Statemine  1.3.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|fill_block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` _ratio <br/> | 
|remark |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` _remark <br/> | 
|set_heap_pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> | 
|set_code |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_code_without_checks |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_changes_trie_config |    |   |   | `Option<ChangesTrieConfiguration>` changes_trie_config <br/> | 
|set_storage |    |   |   | `Vec<KeyValue>` items <br/> | 
|kill_storage |    |   |   | `Vec<Key>` keys <br/> | 
|kill_prefix |    |   |   | `Key` prefix <br/>`u32` _subkeys <br/> | 
|remark_with_event |    | :heavy_check_mark: |   | `Bytes` remark <br/> | 

## ParachainSystem

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_upgrade_block |    |   |   | `RelayChainBlockNumber` relay_chain_block <br/> | 
|set_validation_data |    |   |   | `ParachainInherentData` data <br/> | 
|sudo_send_upward_message |    |   |   | `UpwardMessage` message <br/> | 
|authorize_upgrade |    |   |   | `Hash` code_hash <br/> | 
|enact_authorized_upgrade |    |   |   | `Bytes` code <br/> | 

## RandomnessCollectiveFlip

Empty

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    | :heavy_check_mark: |   | `Compact<Moment>` now <br/> | 

## ParachainInfo

Empty

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|set_balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` who <br/>`Compact<Balance>` new_free <br/>`Compact<Balance>` new_reserved <br/> | 
|force_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` source <br/>`LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_keep_alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_all |    | :heavy_check_mark: |   | `LookupSource` dest <br/>`bool` keep_alive <br/> | 

## TransactionPayment

Empty

## Authorship

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_uncles |    |   |   | `Vec<Header>` new_uncles <br/> | 

## CollatorSelection

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_invulnerables |    |   |   | `Vec<AccountId>` new <br/> | 
|set_desired_candidates |    | :heavy_check_mark: |   | `u32` max <br/> | 
|set_candidacy_bond |    | :heavy_check_mark: |   | `BalanceOf` bond <br/> | 
|register_as_candidate |    | :heavy_check_mark: |   |  | 
|leave_intent |    | :heavy_check_mark: |   |  | 

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_keys | :heavy_check_mark:  |   |   | `Keys` keys <br/>`Bytes` proof <br/> | 
|purge_keys | :heavy_check_mark:  | :heavy_check_mark: |   |  | 

## Aura

Empty

## AuraExt

Empty

## XcmpQueue

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## PolkadotXcm

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|send |    |   |   | `MultiLocation` dest <br/>`Xcm` message <br/> | 
|teleport_assets |    |   |   | `MultiLocation` dest <br/>`MultiLocation` beneficiary <br/>`Vec<MultiAsset>` assets <br/>`Weight` dest_weight <br/> | 
|reserve_transfer_assets |    |   |   | `MultiLocation` dest <br/>`MultiLocation` beneficiary <br/>`Vec<MultiAsset>` assets <br/>`Weight` dest_weight <br/> | 
|execute |    |   |   | `Xcm` message <br/>`Weight` max_weight <br/> | 

## CumulusXcm

Empty

## DmpQueue

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|service_overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|batch | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<Call>` calls <br/> | 
|as_derivative |    |   |   | `u16` index <br/>`Call` call <br/> | 
|batch_all | :heavy_check_mark:  | :heavy_check_mark: |   | `Vec<Call>` calls <br/> | 

## Multisig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|as_multi_threshold_1 |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` other_signatories <br/>`Call` call <br/> | 
|as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> | 
|approve_as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Option<Timepoint>` maybe_timepoint <br/>`[u8;32]` call_hash <br/>`Weight` max_weight <br/> | 
|cancel_as_multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`Vec<AccountId>` other_signatories <br/>`Timepoint` timepoint <br/>`[u8;32]` call_hash <br/> | 

## Proxy

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 
|add_proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> | 
|remove_proxies |    | :heavy_check_mark: |   |  | 
|anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> | 
|kill_anonymous |    | :heavy_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compact<BlockNumber>` height <br/>`Compact<u32>` ext_index <br/> | 
|announce |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|remove_announcement |    | :heavy_check_mark: |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> | 
|reject_announcement |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> | 
|proxy_announced |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`Option<ProxyType>` force_proxy_type <br/>`Call` call <br/> | 

## Assets

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create |    |   |   | `Compact<AssetId>` id <br/>`LookupSource` admin <br/>`TAssetBalance` min_balance <br/> | 
|force_create |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` owner <br/>`bool` is_sufficient <br/>`Compact<TAssetBalance>` min_balance <br/> | 
|destroy |    |   |   | `Compact<AssetId>` id <br/>`AssetDestroyWitness` witness <br/> | 
|mint |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` beneficiary <br/>`Compact<TAssetBalance>` amount <br/> | 
|burn |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` who <br/>`Compact<TAssetBalance>` amount <br/> | 
|transfer |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` target <br/>`Compact<TAssetBalance>` amount <br/> | 
|transfer_keep_alive |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` target <br/>`Compact<TAssetBalance>` amount <br/> | 
|force_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` source <br/>`LookupSource` dest <br/>`Compact<TAssetBalance>` amount <br/> | 
|freeze |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` who <br/> | 
|thaw |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` who <br/> | 
|freeze_asset |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/> | 
|thaw_asset |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/> | 
|transfer_ownership |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` owner <br/> | 
|set_team |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` issuer <br/>`LookupSource` admin <br/>`LookupSource` freezer <br/> | 
|set_metadata |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`Bytes` name <br/>`Bytes` symbol <br/>`u8` decimals <br/> | 
|clear_metadata |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/> | 
|force_set_metadata |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`Bytes` name <br/>`Bytes` symbol <br/>`u8` decimals <br/>`bool` is_frozen <br/> | 
|force_clear_metadata |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/> | 
|force_asset_status |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` owner <br/>`LookupSource` issuer <br/>`LookupSource` admin <br/>`LookupSource` freezer <br/>`Compact<TAssetBalance>` min_balance <br/>`bool` is_sufficient <br/>`bool` is_frozen <br/> | 
|approve_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` delegate <br/>`Compact<TAssetBalance>` amount <br/> | 
|cancel_approval |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` delegate <br/> | 
|force_cancel_approval |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` owner <br/>`LookupSource` delegate <br/> | 
|transfer_approved |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<AssetId>` id <br/>`LookupSource` owner <br/>`LookupSource` destination <br/>`Compact<TAssetBalance>` amount <br/> | 

## Uniques

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create |    |   |   | `Compact<ClassId>` class <br/>`LookupSource` admin <br/> | 
|force_create |    |   |   | `Compact<ClassId>` class <br/>`LookupSource` owner <br/>`bool` free_holding <br/> | 
|destroy |    |   |   | `Compact<ClassId>` class <br/>`DestroyWitness` witness <br/> | 
|mint |    |   |   | `Compact<ClassId>` class <br/>`Compact<InstanceId>` instance <br/>`LookupSource` owner <br/> | 
|burn |    |   |   | `Compact<ClassId>` class <br/>`Compact<InstanceId>` instance <br/>`Option<LookupSource>` check_owner <br/> | 
|transfer |    |   |   | `Compact<ClassId>` class <br/>`Compact<InstanceId>` instance <br/>`LookupSource` dest <br/> | 
|redeposit |    |   |   | `Compact<ClassId>` class <br/>`Vec<InstanceId>` instances <br/> | 
|freeze |    |   |   | `Compact<ClassId>` class <br/>`Compact<InstanceId>` instance <br/> | 
|thaw |    |   |   | `Compact<ClassId>` class <br/>`Compact<InstanceId>` instance <br/> | 
|freeze_class |    |   |   | `Compact<ClassId>` class <br/> | 
|thaw_class |    |   |   | `Compact<ClassId>` class <br/> | 
|transfer_ownership |    |   |   | `Compact<ClassId>` class <br/>`LookupSource` owner <br/> | 
|set_team |    |   |   | `Compact<ClassId>` class <br/>`LookupSource` issuer <br/>`LookupSource` admin <br/>`LookupSource` freezer <br/> | 
|approve_transfer |    |   |   | `Compact<ClassId>` class <br/>`Compact<InstanceId>` instance <br/>`LookupSource` delegate <br/> | 
|cancel_approval |    |   |   | `Compact<ClassId>` class <br/>`Compact<InstanceId>` instance <br/>`Option<LookupSource>` maybe_check_delegate <br/> | 
|force_asset_status |    |   |   | `Compact<ClassId>` class <br/>`LookupSource` owner <br/>`LookupSource` issuer <br/>`LookupSource` admin <br/>`LookupSource` freezer <br/>`bool` free_holding <br/>`bool` is_frozen <br/> | 
|set_attribute |    |   |   | `Compact<ClassId>` class <br/>`Option<InstanceId>` maybe_instance <br/>`Bytes` key <br/>`Bytes` value <br/> | 
|clear_attribute |    |   |   | `Compact<ClassId>` class <br/>`Option<InstanceId>` maybe_instance <br/>`Bytes` key <br/> | 
|set_metadata |    |   |   | `Compact<ClassId>` class <br/>`Compact<InstanceId>` instance <br/>`Bytes` data <br/>`bool` is_frozen <br/> | 
|clear_metadata |    |   |   | `Compact<ClassId>` class <br/>`Compact<InstanceId>` instance <br/> | 
|set_class_metadata |    |   |   | `Compact<ClassId>` class <br/>`Bytes` data <br/>`bool` is_frozen <br/> | 
|clear_class_metadata |    |   |   | `Compact<ClassId>` class <br/> | 

