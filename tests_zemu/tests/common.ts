import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
]

//    "name": "Balances_Transfer",
export const txBasic =
  '0a0000684b4d1c0710fd3aa9d970c8aed2ed9af95a9be66c2eeffc302e0441a52366e233158139ae28a3dfaac5fe1560a5e9e05cd50391016d0f00590200000400000048239ef607d7928874027a43a67689209727dfb3d3dc5e5b03a39bdc2eda771a48239ef607d7928874027a43a67689209727dfb3d3dc5e5b03a39bdc2eda771a'
