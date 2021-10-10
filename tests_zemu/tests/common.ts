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
  '0a0000a542b7f5bc7b3767e9bbd713decde1ef01d45875981edc52dee8410bb61433340b63ce64c10c05d50391010b63ce64c10c050100000001000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'

//     "name": "Staking_Nominate",
export const txNomination =
  '0605100074dbeae458762c8257fe23d9f05ad82fa994e4f9557800169f1a9b04b3964d6800e46c28d0b59b08570d9b29d470efb5e9ab90c8adc602fd2ff809076ea28bb63b009ac4cd92a3a9f9de8f0af1b6cf6449590de0adbc48ba9c522461c18fe818a32f00522e26c7c869be5d00c45341b6c148e6e4955a60788bc829cd19c2cdec06f80cd5030003d20296493223000005000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'

//     "name": "Utility_Batch",
export const setKeys =
  '08007c62f5333fe9504d5482ce9b5001dfcbb69469599f6102f5c63d1aeb56c327e89711297a7b91c772ba9b20a733fcd8bf684f91556c280465f217c23e600da88e72ba0f3cfafc8e0c505ae3a8c133b711dc9297cc16f75d4494ee060eb5d1df338bc5bddb66da8f22ddefb352a8d57655c13d201cdb6b0b37905ec83376ac7bcfc5de9be77d870fdd5d0a42ad3668c92df99eb9eb8b7a2fe723e4ca952ab31e5229fbdac1a9dc23d377d47e9b32b62916eaf6b54a5f7ae97e9c97917b26918296010262648f0c06bbb5c4ee0e2057a20b18f2f97605e94b65eb193f8a3b6d15ed1065568b0bb471ea893cbb23dbad658b003b922c1955935a84f9dbfc84f908f57e1f35c7eddc76fe6d924e71cb41d83d7bffbc35a02c21974d8bc1bf91b3128ca960cb85a961d49dffb51982edd14de2eae3e115fa672fd60122647820e568515941d50391018ed73e0d6e23000005000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafeb0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe'
