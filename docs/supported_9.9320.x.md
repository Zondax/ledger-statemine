# Statemine 9.9320.x

## System

| Name                    | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments                         |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Fill block              |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Perbill`ratio<br/>               |
| Remark                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`remark<br/>                |
| Set heap pages          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set code without checks |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage             |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage            |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix             |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`remark<br/>                |

## ParachainSystem

| Name                     | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                        |
| ------------------------ | ------ | --------- | --------- | ------- | -------------------------------- |
| Set validation data      |        |           |           |         | `ParachainInherentData`data<br/> |
| Sudo send upward message |        |           |           |         | `UpwardMessage`message<br/>      |
| Authorize upgrade        |        |           |           |         | `Hash`code_hash<br/>             |
| Enact authorized upgrade |        |           |           |         | `Vecu8`code<br/>                 |

## Timestamp

| Name | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments            |
| ---- | ------ | ------------------ | ------------------ | ------- | -------------------- |
| Set  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu64`now<br/> |

## Balances

| Name                | Nano S             | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                  |
| ------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------ |
| Transfer            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Set balance         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>`CompactBalance`new_reserved<br/> |
| Force transfer      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Force unreserve     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |

## Authorship

| Name       | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                  |
| ---------- | ------ | --------- | --------- | ------- | -------------------------- |
| Set uncles |        |           |           |         | `VecHeader`new_uncles<br/> |

## CollatorSelection

| Name                   | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                |
| ---------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------ |
| Set invulnerables      |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`new\_<br/> |
| Set desired candidates |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`max<br/>            |
| Set candidacy bond     |        | :heavy_check_mark: | :heavy_check_mark: |         | `Balance`bond<br/>       |
| Register as candidate  |        | :heavy_check_mark: | :heavy_check_mark: |         |                          |
| Leave intent           |        | :heavy_check_mark: | :heavy_check_mark: |         |                          |

## Session

| Name       | Nano S             | Nano S XL          | Nano SP/X          | Nesting | Arguments                        |
| ---------- | ------------------ | ------------------ | ------------------ | ------- | -------------------------------- |
| Set keys   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                  |

## XcmpQueue

| Name                              | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                               |
| --------------------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------- |
| Service overweight                |        | :heavy_check_mark: | :heavy_check_mark: |         | `OverweightIndex`index<br/>`XcmWeight`weight_limit<br/> |
| Suspend xcm execution             |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                         |
| Resume xcm execution              |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                         |
| Update suspend threshold          |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                                         |
| Update drop threshold             |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                                         |
| Update resume threshold           |        | :heavy_check_mark: | :heavy_check_mark: |         | `u32`new\_<br/>                                         |
| Update threshold weight           |        | :heavy_check_mark: | :heavy_check_mark: |         | `XcmWeight`new\_<br/>                                   |
| Update weight restrict decay      |        | :heavy_check_mark: | :heavy_check_mark: |         | `XcmWeight`new\_<br/>                                   |
| Update xcmp max individual weight |        | :heavy_check_mark: | :heavy_check_mark: |         | `XcmWeight`new\_<br/>                                   |

## PolkadotXcm

| Name                             | Nano S | Nano S XL | Nano SP/X          | Nesting | Arguments                                                                                                                                                                 |
| -------------------------------- | ------ | --------- | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Send                             |        |           |                    |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedXcmTuple`message<br/>                                                                                                    |
| Teleport assets                  |        |           |                    |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Reserve transfer assets          |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Execute                          |        |           |                    |         | `BoxVersionedXcmTasSysConfigRuntimeCall`message<br/>`XcmWeight`max_weight<br/>                                                                                            |
| Force xcm version                |        |           |                    |         | `BoxMultiLocation`location<br/>`XcmVersion`xcm_version<br/>                                                                                                               |
| Force default xcm version        |        |           |                    |         | `OptionXcmVersion`maybe_xcm_version<br/>                                                                                                                                  |
| Force subscribe version notify   |        |           |                    |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Force unsubscribe version notify |        |           |                    |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Limited reserve transfer assets  |        |           | :heavy_check_mark: |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Limited teleport assets          |        |           |                    |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |

## DmpQueue

| Name               | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                               |
| ------------------ | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------- |
| Service overweight |        | :heavy_check_mark: | :heavy_check_mark: |         | `OverweightIndex`index<br/>`XcmWeight`weight_limit<br/> |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X          | Nesting | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------- | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| Dispatch as   |                    |                    |                    |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |

## Multisig

| Name                 | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                                                               |
| -------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## Proxy

| Name                | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                                                  |
| ------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------- |
| Proxy               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>                                         |
| Add proxy           |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxy        |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxies      |        | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                            |
| Create pure         |        | :heavy_check_mark: | :heavy_check_mark: |                    | `ProxyType`proxy_type<br/>`BlockNumber`delay<br/>`u16`index<br/>                                                           |
| Kill pure           |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`spawner<br/>`ProxyType`proxy_type<br/>`u16`index<br/>`Compactu32`height<br/>`Compactu32`ext_index<br/> |
| Announce            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Remove announcement |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Reject announcement |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`CallHashOf`call_hash<br/>                                                                |
| Proxy announced     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>        |

## Assets

| Name                  | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                                                                                                                                                  |
| --------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Create                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`admin<br/>`Balance`min_balance<br/>                                                                                                                                                 |
| Force create          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`AccountIdLookupOfT`owner<br/>`bool`is_sufficient<br/>`CompactBalance`min_balance<br/>                                                                                                                  |
| Destroy               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`id<br/>`DestroyWitness`witness<br/>                                                                                                                                                                            |
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

## Uniques

| Name                      | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                                                                                                                                                           |
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
