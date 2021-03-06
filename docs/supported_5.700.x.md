# Statemine  5.700.x

## System

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Fill block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` ratio <br/> |
|Remark |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |
|Set heap pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> |
|Set code |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set code without checks |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` code <br/> |
|Set storage |    |   |   | `VecKeyValue` items <br/> |
|Kill storage |    |   |   | `VecKey` keys <br/> |
|Kill prefix |    |   |   | `Key` prefix <br/>`u32` subkeys <br/> |
|Remark with event |    | :heavy_check_mark: | :heavy_check_mark: | `Vecu8` remark <br/> |

## ParachainSystem

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set validation data |    |   |   | `ParachainInherentData` data <br/> |
|Sudo send upward message |    |   |   | `UpwardMessage` message <br/> |
|Authorize upgrade |    |   |   | `Hash` code_hash <br/> |
|Enact authorized upgrade |    |   |   | `Vecu8` code <br/> |

## Timestamp

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set |    | :heavy_check_mark: |   | `Compactu64` now <br/> |

## Balances

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Set balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` who <br/>`CompactBalance` new_free <br/>`CompactBalance` new_reserved <br/> |
|Force transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer keep alive | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Transfer all | :heavy_check_mark:  | :heavy_check_mark: |   | `LookupasStaticLookupSource` dest <br/>`bool` keep_alive <br/> |
|Force unreserve |    | :heavy_check_mark: |   | `LookupasStaticLookupSource` who <br/>`Balance` amount <br/> |

## Authorship

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set uncles |    |   |   | `VecHeader` new_uncles <br/> |

## CollatorSelection

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set invulnerables |    |   |   | `VecAccountId` new_ <br/> |
|Set desired candidates |    | :heavy_check_mark: |   | `u32` max <br/> |
|Set candidacy bond |    | :heavy_check_mark: |   | `Balance` bond <br/> |
|Register as candidate |    | :heavy_check_mark: |   |  |
|Leave intent |    | :heavy_check_mark: |   |  |

## Session

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Set keys | :heavy_check_mark:  | :heavy_check_mark: |   | `Keys` keys <br/>`Bytes` proof <br/> |
|Purge keys | :heavy_check_mark:  | :heavy_check_mark: |   |  |

## XcmpQueue

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> |
|Suspend xcm execution |    | :heavy_check_mark: |   |  |
|Resume xcm execution |    | :heavy_check_mark: |   |  |

## PolkadotXcm

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Send |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedXcmTuple` message <br/> |
|Teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> |
|Reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/> |
|Execute |    |   |   | `BoxVersionedXcmTasSysConfigCall` message <br/>`Weight` max_weight <br/> |
|Force xcm version |    |   |   | `BoxMultiLocation` location <br/>`XcmVersion` xcm_version <br/> |
|Force default xcm version |    |   |   | `OptionXcmVersion` maybe_xcm_version <br/> |
|Force subscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> |
|Force unsubscribe version notify |    |   |   | `BoxVersionedMultiLocation` location <br/> |
|Limited reserve transfer assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> |
|Limited teleport assets |    |   |   | `BoxVersionedMultiLocation` dest <br/>`BoxVersionedMultiLocation` beneficiary <br/>`BoxVersionedMultiAssets` assets <br/>`u32` fee_asset_item <br/>`WeightLimit` weight_limit <br/> |

## DmpQueue

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Service overweight |    |   |   | `OverweightIndex` index <br/>`Weight` weight_limit <br/> |

## Utility

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Batch | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|As derivative |    |   |   | `u16` index <br/>`Call` call <br/> |
|Batch all | :heavy_check_mark:  | :heavy_check_mark: |   | `VecCall` calls <br/> |
|Dispatch as |    |   |   | `BoxPalletsOrigin` as_origin <br/>`Call` call <br/> |

## Multisig

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|As multi threshold 1 |    | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId` other_signatories <br/>`Call` call <br/> |
|As multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`OpaqueCall` call <br/>`bool` store_call <br/>`Weight` max_weight <br/> |
|Approve as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`OptionTimepoint` maybe_timepoint <br/>`H256` call_hash <br/>`Weight` max_weight <br/> |
|Cancel as multi |    | :heavy_check_mark: | :heavy_check_mark: | `u16` threshold <br/>`VecAccountId` other_signatories <br/>`Timepoint` timepoint <br/>`H256` call_hash <br/> |

## Proxy

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Proxy |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |
|Add proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxy |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`ProxyType` proxy_type <br/>`BlockNumber` delay <br/> |
|Remove proxies |    | :heavy_check_mark: |   |  |
|Anonymous |    | :heavy_check_mark: |   | `ProxyType` proxy_type <br/>`BlockNumber` delay <br/>`u16` index <br/> |
|Kill anonymous |    | :heavy_check_mark: |   | `AccountId` spawner <br/>`ProxyType` proxy_type <br/>`u16` index <br/>`Compactu32` height <br/>`Compactu32` ext_index <br/> |
|Announce |    |   |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Remove announcement |    |   |   | `AccountId` real <br/>`CallHashOf` call_hash <br/> |
|Reject announcement |    |   |   | `AccountId` delegate <br/>`CallHashOf` call_hash <br/> |
|Proxy announced |    | :heavy_check_mark: |   | `AccountId` delegate <br/>`AccountId` real <br/>`OptionProxyType` force_proxy_type <br/>`Call` call <br/> |

## Assets

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    |   |   | `Compactu32` id <br/>`LookupasStaticLookupSource` admin <br/>`Balance` min_balance <br/> |
|Force create |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`bool` is_sufficient <br/>`CompactBalance` min_balance <br/> |
|Destroy |    |   |   | `Compactu32` id <br/>`DestroyWitness` witness <br/> |
|Mint |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` beneficiary <br/>`CompactBalance` amount <br/> |
|Burn |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` who <br/>`CompactBalance` amount <br/> |
|Transfer |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` target <br/>`CompactBalance` amount <br/> |
|Transfer keep alive |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` target <br/>`CompactBalance` amount <br/> |
|Force transfer |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` source <br/>`LookupasStaticLookupSource` dest <br/>`CompactBalance` amount <br/> |
|Freeze |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` who <br/> |
|Thaw |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` who <br/> |
|Freeze asset |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/> |
|Thaw asset |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/> |
|Transfer ownership |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/> |
|Set team |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/> |
|Set metadata |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`Vecu8` name <br/>`Vecu8` symbol <br/>`u8` decimals <br/> |
|Clear metadata |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/> |
|Force set metadata |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`Vecu8` name <br/>`Vecu8` symbol <br/>`u8` decimals <br/>`bool` is_frozen <br/> |
|Force clear metadata |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/> |
|Force asset status |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/>`CompactBalance` min_balance <br/>`bool` is_sufficient <br/>`bool` is_frozen <br/> |
|Approve transfer |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` delegate <br/>`CompactBalance` amount <br/> |
|Cancel approval |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` delegate <br/> |
|Force cancel approval |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` delegate <br/> |
|Transfer approved |    | :heavy_check_mark: | :heavy_check_mark: | `Compactu32` id <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` destination <br/>`CompactBalance` amount <br/> |
|Touch |    | :heavy_check_mark: |   | `Compactu32` id <br/> |
|Refund |    | :heavy_check_mark: |   | `Compactu32` id <br/>`bool` allow_burn <br/> |

## Uniques

| Name        | Light | XL | Nesting | Arguments |
| :---------- |:------------:|:--------:|:--------:|:--------|
|Create |    |   |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` admin <br/> |
|Force create |    |   |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` owner <br/>`bool` free_holding <br/> |
|Destroy |    |   |   | `Compactu32` class_ <br/>`DestroyWitness` witness <br/> |
|Mint |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`LookupasStaticLookupSource` owner <br/> |
|Burn |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`OptionLookupasStaticLookupSource` check_owner <br/> |
|Transfer |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`LookupasStaticLookupSource` dest <br/> |
|Redeposit |    |   |   | `Compactu32` class_ <br/>`VecInstanceId` instances <br/> |
|Freeze |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/> |
|Thaw |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/> |
|Freeze class |    |   |   | `Compactu32` class_ <br/> |
|Thaw class |    |   |   | `Compactu32` class_ <br/> |
|Transfer ownership |    |   |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` owner <br/> |
|Set team |    |   |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/> |
|Approve transfer |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`LookupasStaticLookupSource` delegate <br/> |
|Cancel approval |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`OptionLookupasStaticLookupSource` maybe_check_delegate <br/> |
|Force asset status |    |   |   | `Compactu32` class_ <br/>`LookupasStaticLookupSource` owner <br/>`LookupasStaticLookupSource` issuer <br/>`LookupasStaticLookupSource` admin <br/>`LookupasStaticLookupSource` freezer <br/>`bool` free_holding <br/>`bool` is_frozen <br/> |
|Set attribute |    |   |   | `Compactu32` class_ <br/>`OptionInstanceId` maybe_instance <br/>`BoundedVecu8KeyLimit` key <br/>`BoundedVecu8ValueLimit` value <br/> |
|Clear attribute |    |   |   | `Compactu32` class_ <br/>`OptionInstanceId` maybe_instance <br/>`BoundedVecu8KeyLimit` key <br/> |
|Set metadata |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/>`BoundedVecu8StringLimit` data <br/>`bool` is_frozen <br/> |
|Clear metadata |    |   |   | `Compactu32` class_ <br/>`Compactu32` instance <br/> |
|Set class metadata |    |   |   | `Compactu32` class_ <br/>`BoundedVecu8StringLimit` data <br/>`bool` is_frozen <br/> |
|Clear class metadata |    |   |   | `Compactu32` class_ <br/> |

