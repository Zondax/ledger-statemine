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
  '0a000084b8dd3b10d41f13c321746e253d6527b68bb75dc6c38b43d08df7ad82648b9133158139ae28a3dfaac5fe1560a5e9e05cd503910133158139ae28a3dfaac5fe1560a5e9e05cf801000003000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'
