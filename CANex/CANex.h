#ifndef CANEX_H
#define CANEX_H

#include "mbed.h"
#include "CAN.h"

#define constrain(n, min, max) ( (n<min)? (min) : (n>max)? (max) : (n) )
#define deg_to_rad(n) ( (n) / 180.0 * M_PI )
#define rad_to_deg(n) ( (n) / M_PI * 180.0 )

class CANex : public CAN{
    public:
        CANex(PinName rd, PinName td, int hz);

        int attach_multi(void (*func_for_attach)(CAN_Message));

        void call_attached();
        
        int can_filter(can_t *obj, uint32_t id, uint32_t mask, CANFormat format, int32_t handle);

        int filter(unsigned int id, unsigned int mask, CANFormat format = CANAny, int handle = 0);

        int send(int16_t id, char data[], int len);

        int send(int16_t id, char data1);

        int send(int16_t id, char data1, char data2);

        int send(int16_t id, char data1, char data2, char data3);

        int send(int16_t id, char data1, char data2, char data3, char data4);

        int send(int16_t id, char data1, char data2, char data3, char data4, char data5);

        int send(int16_t id, char data1, char data2, char data3, char data4, char data5, char data6);

        int send(int16_t id, char data1, char data2, char data3, char data4, char data5, char data6, char data7);

        int send(int16_t id, char data1, char data2, char data3, char data4, char data5, char data6, char data7, char data8);

    private:
        
        void (*func[8])(CAN_Message);
        uint8_t index_for_attach;
        CANMessage rxMsg;

};

#endif
