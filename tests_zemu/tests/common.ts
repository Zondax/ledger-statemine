import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')
const APP_PATH_SP = Resolve('../app/output/app_s2.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
  { name: 'nanosp', prefix: 'SP', path: APP_PATH_SP },
]

//    "name": "Balances_Transfer",
export const txBasic =
  '0a000087138f48a0f9e6e7904244eed35b3e3fca029b68bce55404bcd2ec177cd41f8233158139ae28a3dfaac5fe1560a5e9e05cd503000b63ce64c10c0500bc0200000500000048239ef607d7928874027a43a67689209727dfb3d3dc5e5b03a39bdc2eda771a48239ef607d7928874027a43a67689209727dfb3d3dc5e5b03a39bdc2eda771a'
