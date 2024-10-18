# Ledger Statemine App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-statemine/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-statemine/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

## Notice :warning::warning:
The new Polkadot Ledger application aims to handle all substrate-based chains without being affected by runtime upgrades,
providing a single application for the complete ecosystem without compromising security.

As the new app is now available, this repository has been archived.

For more references, you can visit:
- [Polkadot Generic App Repo](https://github.com/Zondax/ledger-polkadot)
- [Zondax Portal](https://substrate.beryx.io/new_polkadot_ledger_app)
- [Polkadot Wiki](https://wiki.polkadot.network/docs/ledger)

---

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
# Statemine 14.1001000.x

## System

| Name                    | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                         |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Remark                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Set heap pages          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set code without checks |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage             |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage            |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix             |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |

## ParachainSystem

| Name                     | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                    |
| ------------------------ | ------ | --------- | ---------------- | ------- | -------------------------------------------- |
| Set validation data      |        |           |                  |         | `ParachainInherentData`data<br/>             |
| Sudo send upward message |        |           |                  |         | `UpwardMessage`message<br/>                  |
| Authorize upgrade        |        |           |                  |         | `Hash`code_hash<br/>`bool`check_version<br/> |
| Enact authorized upgrade |        |           |                  |         | `Vecu8`code<br/>                             |

## Timestamp

| Name | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments            |
| ---- | ------ | ------------------ | ------------------ | ------- | -------------------- |
| Set  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu64`now<br/> |

## Balances

| Name                 | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                               |
| -------------------- | ------------------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------- |
| Transfer allow death |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Force transfer       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/> |
| Transfer keep alive  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                |
| Transfer all         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                      |
| Force unreserve      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                        |
| Upgrade accounts     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`who<br/>                                                                  |
| Force set balance    |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>                               |

## CollatorSelection

| Name                   | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                |
| ---------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------ |
| Set invulnerables      |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`new\_<br/> |
| Set desired candidates |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`max<br/>            |
| Set candidacy bond     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`bond<br/>       |
| Register as candidate  |        | :heavy_check_mark: | :heavy_check_mark: |         |                          |
| Leave intent           |        | :heavy_check_mark: | :heavy_check_mark: |         |                          |
| Add invulnerable       |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`who<br/>      |
| Remove invulnerable    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountId`who<br/>      |

## Session

| Name       | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                        |
| ---------- | ------------------ | ------------------ | ------------------ | ------------------ | -------------------------------- |
| Set keys   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                  |

## XcmpQueue

| Name                              | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                            |
| --------------------------------- | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------- |
| Service overweight                |        | :heavy_check_mark: | :heavy_check_mark: |         | `OverweightIndex`index<br/>`Weight`weight_limit<br/> |
| Suspend xcm execution             |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                      |
| Resume xcm execution              |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                      |
| Update suspend threshold          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                                      |
| Update drop threshold             |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                                      |
| Update resume threshold           |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                                      |
| Update threshold weight           |        | :heavy_check_mark: | :heavy_check_mark: |         | `Weight`new\_<br/>                                   |
| Update weight restrict decay      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Weight`new\_<br/>                                   |
| Update xcmp max individual weight |        | :heavy_check_mark: | :heavy_check_mark: |         | `Weight`new\_<br/>                                   |

## PolkadotXcm

| Name                             | Nano S | Nano S XL | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                 |
| -------------------------------- | ------ | --------- | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Send                             |        |           |                    |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedXcmTuple`message<br/>                                                                                                    |
| Teleport assets                  |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Reserve transfer assets          |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Execute                          |        |           |                    |         | `BoxVersionedXcmTasConfigRuntimeCall`message<br/>`Weight`max_weight<br/>                                                                                                  |
| Force xcm version                |        |           |                    |         | `BoxMultiLocation`location<br/>`XcmVersion`version<br/>                                                                                                                   |
| Force default xcm version        |        |           |                    |         | `OptionXcmVersion`maybe_xcm_version<br/>                                                                                                                                  |
| Force subscribe version notify   |        |           |                    |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Force unsubscribe version notify |        |           |                    |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Limited reserve transfer assets  |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Limited teleport assets          |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Force suspension                 |        |           |                    |         | `bool`suspended<br/>                                                                                                                                                      |

## DmpQueue

| Name               | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                            |
| ------------------ | ------ | ------------------ | ------------------ | ------- | ---------------------------------------------------- |
| Service overweight |        | :heavy_check_mark: | :heavy_check_mark: |         | `OverweightIndex`index<br/>`Weight`weight_limit<br/> |

## ToPolkadotXcmRouter

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                   |
| -------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------- |
| Report bridge status |        |           |                  |         | `H256`bridge_id<br/>`bool`is_congested<br/> |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------- | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| Dispatch as   |                    |                    |                    |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| With weight   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>`Weight`weight<br/>              |

## Multisig

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                               |
| -------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## Proxy

| Name                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                  |
| ------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------- |
| Proxy               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>                                         |
| Add proxy           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxy        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxies      |        | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                            |
| Create pure         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ProxyType`proxy_type<br/>`BlockNumber`delay<br/>`u16`index<br/>                                                           |
| Kill pure           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`spawner<br/>`ProxyType`proxy_type<br/>`u16`index<br/>`Compactu32`height<br/>`Compactu32`ext_index<br/> |
| Announce            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Remove announcement |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Reject announcement |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`CallHashOf`call_hash<br/>                                                                |
| Proxy announced     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>        |

## Assets

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                                  |
| --------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`admin<br/>`Balance`min_balance<br/>                                                                                                                                                 |
| Force create          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`owner<br/>`bool`is_sufficient<br/>`CompactBalance`min_balance<br/>                                                                                                                  |
| Start destroy         |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>                                                                                                                                                                                                        |
| Destroy accounts      |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>                                                                                                                                                                                                        |
| Destroy approvals     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>                                                                                                                                                                                                        |
| Finish destroy        |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>                                                                                                                                                                                                        |
| Mint                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`beneficiary<br/>`CompactBalance`amount<br/>                                                                                                                                         |
| Burn                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`who<br/>`CompactBalance`amount<br/>                                                                                                                                                 |
| Transfer              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Transfer keep alive   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Force transfer        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                                                                                                 |
| Freeze                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Thaw                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Freeze asset          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>                                                                                                                                                                                                        |
| Thaw asset            |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>                                                                                                                                                                                                        |
| Transfer ownership    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                                                                          |
| Set team              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>                                                                                                           |
| Set metadata          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>                                                                                                                                                     |
| Clear metadata        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>                                                                                                                                                                                                        |
| Force set metadata    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>`bool`is_frozen<br/>                                                                                                                                 |
| Force clear metadata  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>                                                                                                                                                                                                        |
| Force asset status    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>`CompactBalance`min_balance<br/>`bool`is_sufficient<br/>`bool`is_frozen<br/> |
| Approve transfer      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`delegate<br/>`CompactBalance`amount<br/>                                                                                                                                            |
| Cancel approval       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                                                       |
| Force cancel approval |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                         |
| Transfer approved     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`destination<br/>`CompactBalance`amount<br/>                                                                                                           |
| Touch                 |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>                                                                                                                                                                                                        |
| Refund                |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>`bool`allow_burn<br/>                                                                                                                                                                                   |
| Set min balance       |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>`Balance`min_balance<br/>                                                                                                                                                                               |
| Touch other           |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Refund other          |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Block                 |        | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |

## Uniques

| Name                      | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                                           |
| ------------------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`admin<br/>                                                                                                                                         |
| Force create              |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`owner<br/>`bool`free_holding<br/>                                                                                                                  |
| Destroy                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`DestroyWitness`witness<br/>                                                                                                                                           |
| Mint                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                        |
| Burn                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`OptionAccountIdLookupOfT`check_owner<br/>                                                                                                            |
| Transfer                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`dest<br/>                                                                                                                         |
| Redeposit                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`VecItemId`items<br/>                                                                                                                                                  |
| Freeze                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                      |
| Thaw                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                      |
| Freeze collection         |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>                                                                                                                                                                       |
| Thaw collection           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>                                                                                                                                                                       |
| Transfer ownership        |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                                         |
| Set team                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>                                                                          |
| Approve transfer          |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                     |
| Cancel approval           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`OptionAccountIdLookupOfT`maybe_check_delegate<br/>                                                                                                   |
| Force item status         |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>`bool`free_holding<br/>`bool`is_frozen<br/> |
| Set attribute             |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`OptionItemId`maybe_item<br/>`BoundedVecu8`key<br/>`BoundedVecu8`value<br/>                                                                                            |
| Clear attribute           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`OptionItemId`maybe_item<br/>`BoundedVecu8`key<br/>                                                                                                                    |
| Set metadata              |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`BoundedVecu8`data<br/>`bool`is_frozen<br/>                                                                                                           |
| Clear metadata            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                      |
| Set collection metadata   |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`BoundedVecu8`data<br/>`bool`is_frozen<br/>                                                                                                                            |
| Clear collection metadata |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>                                                                                                                                                                       |
| Set accept ownership      |        | :heavy_check_mark: | :heavy_check_mark: |         | `OptionCollectionId`maybe_collection<br/>                                                                                                                                                           |
| Set collection max supply |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`u32`max_supply<br/>                                                                                                                                                   |
| Set price                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`OptionItemPrice`price<br/>`OptionAccountIdLookupOfT`whitelisted_buyer<br/>                                                                           |
| Buy item                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`ItemPrice`bid_price<br/>                                                                                                                             |

## Nfts

| Name                            | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                                                             |
| ------------------------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create                          |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`admin<br/>`CollectionConfigFor`config<br/>                                                                                                                                                        |
| Force create                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`owner<br/>`CollectionConfigFor`config<br/>                                                                                                                                                        |
| Destroy                         |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`DestroyWitness`witness<br/>                                                                                                                                                             |
| Mint                            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`mint_to<br/>`OptionMintWitnessItemIdDepositBalanceOf`witness_data<br/>                                                                              |
| Force mint                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`mint_to<br/>`ItemConfig`item_config<br/>                                                                                                            |
| Burn                            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                                        |
| Transfer                        |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`dest<br/>                                                                                                                                           |
| Redeposit                       |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`VecItemId`items<br/>                                                                                                                                                                    |
| Lock item transfer              |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                                        |
| Unlock item transfer            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                                        |
| Lock collection                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`CollectionSettings`lock_settings<br/>                                                                                                                                                   |
| Transfer ownership              |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                                                           |
| Set team                        |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`OptionAccountIdLookupOfT`issuer<br/>`OptionAccountIdLookupOfT`admin<br/>`OptionAccountIdLookupOfT`freezer<br/>                                                                          |
| Force collection owner          |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                                                           |
| Force collection config         |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`CollectionConfigFor`config<br/>                                                                                                                                                         |
| Approve transfer                |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`delegate<br/>`OptionBlockNumber`maybe_deadline<br/>                                                                                                 |
| Cancel approval                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                       |
| Clear all transfer approvals    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                                        |
| Lock item properties            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`bool`lock_metadata<br/>`bool`lock_attributes<br/>                                                                                                                      |
| Set attribute                   |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`OptionItemId`maybe*item<br/>`AttributeNamespaceAccountId`namespace*<br/>`BoundedVecu8`key<br/>`BoundedVecu8`value<br/>                                                                  |
| Force set attribute             |        | :heavy_check_mark: | :heavy_check_mark: |         | `OptionAccountId`set*as<br/>`CollectionId`collection<br/>`OptionItemId`maybe_item<br/>`AttributeNamespaceAccountId`namespace*<br/>`BoundedVecu8`key<br/>`BoundedVecu8`value<br/>                                      |
| Clear attribute                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`OptionItemId`maybe*item<br/>`AttributeNamespaceAccountId`namespace*<br/>`BoundedVecu8`key<br/>                                                                                          |
| Approve item attributes         |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                       |
| Cancel item attributes approval |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`AccountIdLookupOfT`delegate<br/>`CancelAttributesApprovalWitness`witness<br/>                                                                                          |
| Set metadata                    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`BoundedVecu8`data<br/>                                                                                                                                                 |
| Clear metadata                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>                                                                                                                                                                        |
| Set collection metadata         |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`BoundedVecu8`data<br/>                                                                                                                                                                  |
| Clear collection metadata       |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>                                                                                                                                                                                         |
| Set accept ownership            |        | :heavy_check_mark: | :heavy_check_mark: |         | `OptionCollectionId`maybe_collection<br/>                                                                                                                                                                             |
| Set collection max supply       |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`u32`max_supply<br/>                                                                                                                                                                     |
| Update mint settings            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`MintSettings`mint_settings<br/>                                                                                                                                                         |
| Set price                       |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`OptionItemPrice`price<br/>`OptionAccountIdLookupOfT`whitelisted_buyer<br/>                                                                                             |
| Buy item                        |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`collection<br/>`ItemId`item<br/>`ItemPrice`bid_price<br/>                                                                                                                                               |
| Pay tips                        |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecItemTipOfMaxTips`tips<br/>                                                                                                                                                                                        |
| Create swap                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`offered_collection<br/>`ItemId`offered_item<br/>`CollectionId`desired_collection<br/>`OptionItemId`maybe_desired_item<br/>`OptionPriceWithDirectionItemPrice`maybe_price<br/>`BlockNumber`duration<br/> |
| Cancel swap                     |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`offered_collection<br/>`ItemId`offered_item<br/>                                                                                                                                                        |
| Claim swap                      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CollectionId`send_collection<br/>`ItemId`send_item<br/>`CollectionId`receive_collection<br/>`ItemId`receive_item<br/>`OptionPriceWithDirectionItemPrice`witness_price<br/>                                           |
| Mint pre signed                 |        |                    |                    |         | `BoxPreSignedMintOf`mint_data<br/>`OffchainSignature`signature<br/>`AccountId`signer<br/>                                                                                                                             |
| Set attributes pre signed       |        |                    |                    |         | `PreSignedAttributesOf`data<br/>`OffchainSignature`signature<br/>`AccountId`signer<br/>                                                                                                                               |

## ForeignAssets

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                                                                        |
| --------------------- | ------ | --------- | ------------------ | ------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create                |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`admin<br/>`Balance`min_balance<br/>                                                                                                                                                 |
| Force create          |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>`bool`is_sufficient<br/>`CompactBalance`min_balance<br/>                                                                                                                  |
| Start destroy         |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Destroy accounts      |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Destroy approvals     |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Finish destroy        |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Mint                  |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`beneficiary<br/>`CompactBalance`amount<br/>                                                                                                                                         |
| Burn                  |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>`CompactBalance`amount<br/>                                                                                                                                                 |
| Transfer              |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Transfer keep alive   |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Force transfer        |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                                                                                                 |
| Freeze                |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Thaw                  |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Freeze asset          |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Thaw asset            |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Transfer ownership    |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                                                                          |
| Set team              |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>                                                                                                           |
| Set metadata          |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>                                                                                                                                                     |
| Clear metadata        |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Force set metadata    |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>`bool`is_frozen<br/>                                                                                                                                 |
| Force clear metadata  |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Force asset status    |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>`CompactBalance`min_balance<br/>`bool`is_sufficient<br/>`bool`is_frozen<br/> |
| Approve transfer      |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`delegate<br/>`CompactBalance`amount<br/>                                                                                                                                            |
| Cancel approval       |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                                                       |
| Force cancel approval |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                         |
| Transfer approved     |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`destination<br/>`CompactBalance`amount<br/>                                                                                                           |
| Touch                 |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>                                                                                                                                                                                                        |
| Refund                |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`bool`allow_burn<br/>                                                                                                                                                                                   |
| Set min balance       |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`Balance`min_balance<br/>                                                                                                                                                                               |
| Touch other           |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Refund other          |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Block                 |        |           | :heavy_check_mark: |         | `AssetIdParameter`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |

## NftFractionalization

| Name          | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                             |
| ------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------------- |
| Fractionalize |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`nft_collection_id<br/>`u32`nft_id<br/>`u32`asset_id<br/>`AccountIdLookupOfT`beneficiary<br/>`u128`fractions<br/> |
| Unify         |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`nft_collection_id<br/>`u32`nft_id<br/>`u32`asset_id<br/>`AccountIdLookupOfT`beneficiary<br/>                     |

## PoolAssets

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                                                           |
| --------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create                |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`admin<br/>`Balance`min_balance<br/>                                                                                                                                                 |
| Force create          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`owner<br/>`bool`is_sufficient<br/>`CompactBalance`min_balance<br/>                                                                                                                  |
| Start destroy         |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>                                                                                                                                                                                                        |
| Destroy accounts      |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>                                                                                                                                                                                                        |
| Destroy approvals     |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>                                                                                                                                                                                                        |
| Finish destroy        |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>                                                                                                                                                                                                        |
| Mint                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`beneficiary<br/>`CompactBalance`amount<br/>                                                                                                                                         |
| Burn                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`who<br/>`CompactBalance`amount<br/>                                                                                                                                                 |
| Transfer              |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Transfer keep alive   |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Force transfer        |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                                                                                                 |
| Freeze                |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Thaw                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Freeze asset          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>                                                                                                                                                                                                        |
| Thaw asset            |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>                                                                                                                                                                                                        |
| Transfer ownership    |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                                                                          |
| Set team              |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>                                                                                                           |
| Set metadata          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>                                                                                                                                                     |
| Clear metadata        |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>                                                                                                                                                                                                        |
| Force set metadata    |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>`bool`is_frozen<br/>                                                                                                                                 |
| Force clear metadata  |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>                                                                                                                                                                                                        |
| Force asset status    |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>`CompactBalance`min_balance<br/>`bool`is_sufficient<br/>`bool`is_frozen<br/> |
| Approve transfer      |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`delegate<br/>`CompactBalance`amount<br/>                                                                                                                                            |
| Cancel approval       |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                                                       |
| Force cancel approval |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                         |
| Transfer approved     |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`destination<br/>`CompactBalance`amount<br/>                                                                                                           |
| Touch                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>                                                                                                                                                                                                        |
| Refund                |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`bool`allow_burn<br/>                                                                                                                                                                                   |
| Set min balance       |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`Balance`min_balance<br/>                                                                                                                                                                               |
| Touch other           |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Refund other          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Block                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |

## AssetConversion

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                 |
| ---------------------------- | ------ | --------- | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create pool                  |        |           | :heavy_check_mark: |         | `MultiAssetId`asset1<br/>`MultiAssetId`asset2<br/>                                                                                                                        |
| Add liquidity                |        |           | :heavy_check_mark: |         | `MultiAssetId`asset1<br/>`MultiAssetId`asset2<br/>`u128`amount1_desired<br/>`u128`amount2_desired<br/>`u128`amount1_min<br/>`u128`amount2_min<br/>`AccountId`mint_to<br/> |
| Remove liquidity             |        |           | :heavy_check_mark: |         | `MultiAssetId`asset1<br/>`MultiAssetId`asset2<br/>`u128`lp_token_burn<br/>`u128`amount1_min_receive<br/>`u128`amount2_min_receive<br/>`AccountId`withdraw_to<br/>         |
| Swap exact tokens for tokens |        |           | :heavy_check_mark: |         | `VecMultiAssetId`path<br/>`u128`amount_in<br/>`u128`amount_out_min<br/>`AccountId`send_to<br/>`bool`keep_alive<br/>                                                       |
| Swap tokens for exact tokens |        |           | :heavy_check_mark: |         | `VecMultiAssetId`path<br/>`u128`amount_out<br/>`u128`amount_in_max<br/>`AccountId`send_to<br/>`bool`keep_alive<br/>                                                       |
