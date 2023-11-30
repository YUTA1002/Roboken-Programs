#include "CANex.h"

CANex::CANex(PinName rd, PinName td, int hz) : CAN(rd, td, hz){ 
  return;
}

int CANex::attach_multi(void (*func_for_attach)(CAN_Message)){
  int ret;
  if(index_for_attach < 7){
    if(index_for_attach == 0){
      CAN::attach(this, &CANex::call_attached);
    }
    func[index_for_attach++] = func_for_attach;
    ret = 1;
  }else {
    ret = 0;
  }
  return ret;
}

void CANex::call_attached(){
  CAN::read(rxMsg);
  for(int i=0 ; i<index_for_attach ; i++){
      if((*func[i]) != NULL)(*func[i])(rxMsg);
  }
}


int CANex::can_filter(can_t *obj, uint32_t id, uint32_t mask, CANFormat format, int32_t handle){
  int retval = 0;

  // filter for CANAny format cannot be configured for STM32
  if ((format == CANStandard) || (format == CANExtended)) {
    CAN_FilterConfTypeDef  sFilterConfig;
    sFilterConfig.FilterNumber = handle;
    sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;

    if (format == CANStandard) {
      sFilterConfig.FilterIdHigh = ((id << 5)  | (id >> (32 - 5))) & 0xFFFF;
      sFilterConfig.FilterIdLow =  (id >> (11 - 3)) & 0xFFF8;
      sFilterConfig.FilterMaskIdHigh = ((mask << 5)  | (mask >> (32 - 5))) & 0xFFFF;
      sFilterConfig.FilterMaskIdLow = (mask >> (11 - 3)) & 0xFFF8; // allows both remote and data frames
    } else { // format == CANExtended
      sFilterConfig.FilterIdHigh = id >> 13; // EXTID[28:13]
      sFilterConfig.FilterIdLow = (0xFFFF & (id << 3)) | (1 << 2); // EXTID[12:0] + IDE
      sFilterConfig.FilterMaskIdHigh = mask >> 13;
      sFilterConfig.FilterMaskIdLow = (0xFFFF & (mask << 3)) | (1 << 2);
    }

    sFilterConfig.FilterFIFOAssignment = 0;
    sFilterConfig.FilterActivation = ENABLE;
    sFilterConfig.BankNumber = 14 + handle;

    HAL_CAN_ConfigFilter(&obj->CanHandle, &sFilterConfig);
    retval = handle;
  }
  return retval;
}

int CANex::filter(unsigned int id, unsigned int mask, CANFormat format, int handle){
  lock();
  int ret = can_filter(&_can, id, mask, format, handle);
  unlock();
  return ret;
}

int CANex::send(int16_t id, char data[], int len){
  txMsg.id = id;
  txMsg.len = len;
  for(int i = 0; i < len; i++){
    txMsg.data[i] = data[i];
  }
  return write(txMsg);
}

int CANex::send(int16_t id, char data1){
  txMsg.id = id;
  txMsg.len = 1;
  txMsg.data[0] = data1;
  return write(txMsg);
}

int CANex::send(int16_t id, char data1, char data2){
  txMsg.id = id;
  txMsg.len = 2;
  txMsg.data[0] = data1;
  txMsg.data[1] = data2;
  return write(txMsg);
}

int CANex::send(int16_t id, char data1, char data2, char data3){
  txMsg.id = id;
  txMsg.len = 3;
  txMsg.data[0] = data1;
  txMsg.data[1] = data2;
  txMsg.data[2] = data3;
  return write(txMsg);
}

int CANex::send(int16_t id, char data1, char data2, char data3, char data4){
  txMsg.id = id;
  txMsg.len = 4;
  txMsg.data[0] = data1;
  txMsg.data[1] = data2;
  txMsg.data[2] = data3;
  txMsg.data[3] = data4;
  return write(txMsg);
}

int CANex::send(int16_t id, char data1, char data2, char data3, char data4, char data5){
  txMsg.id = id;
  txMsg.len = 5;
  txMsg.data[0] = data1;
  txMsg.data[1] = data2;
  txMsg.data[2] = data3;
  txMsg.data[3] = data4;
  txMsg.data[4] = data5;
  return write(txMsg);
}

int CANex::send(int16_t id, char data1, char data2, char data3, char data4, char data5, char data6){
  txMsg.id = id;
  txMsg.len = 6;
  txMsg.data[0] = data1;
  txMsg.data[1] = data2;
  txMsg.data[2] = data3;
  txMsg.data[3] = data4;
  txMsg.data[4] = data5;
  txMsg.data[5] = data6;
  return write(txMsg);
}

int CANex::send(int16_t id, char data1, char data2, char data3, char data4, char data5, char data6, char data7){
  txMsg.id = id;
  txMsg.len = 7;
  txMsg.data[0] = data1;
  txMsg.data[1] = data2;
  txMsg.data[2] = data3;
  txMsg.data[3] = data4;
  txMsg.data[4] = data5;
  txMsg.data[5] = data6;
  txMsg.data[6] = data7;
  return write(txMsg);
}

int CANex::send(int16_t id, char data1, char data2, char data3, char data4, char data5, char data6, char data7, char data8){
  txMsg.id = id;
  txMsg.len = 8;
  txMsg.data[0] = data1;
  txMsg.data[1] = data2;
  txMsg.data[2] = data3;
  txMsg.data[3] = data4;
  txMsg.data[4] = data5;
  txMsg.data[5] = data6;
  txMsg.data[6] = data7;
  txMsg.data[7] = data8;
  return write(txMsg);
}
