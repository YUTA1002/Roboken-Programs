#ifndef Brain_Board_ver0_H
#define Brain_Board_ver0_H

//remove R34, R36, SB17, SB21
//connect SB48, SB49

#include "mbed.h"

extern "C" {
    typedef enum{
        LD0 = PA_5,
        LD1 = PA_6,
        LD2 = PA_7,
        ENC0_A = PC_12,
        ENC0_B = PC_10,
        ENC1_A = PC_13,
        ENC1_B = PA_15,
        ENC2_A = PC_14, //こののピンを使用するには、SB48とSB49をジャンパして，R34とR36を外す必要がある
        ENC2_B = PB_7,
        ENC3_A = PC_15, //こののピンを使用するには、SB48とSB49をジャンパして，R34とR36を外す必要がある
        ENC3_B = PH_1,
        IN0 = PC_11,
        IN1 = PA_4,
        IN2 = PC_1,
        IN3 = PC_0,
        IN4 = PC_3,
        IN5 = PC_2,
        IN6 = PB_6,
        IN7 = PC_7,
        IN8 = PA_9,
        IN9 = PA_8,
        IN10 = PB_10,
        IN11 = PB_5,
        OUT0_DIR = PC_9,
        OUT0_PWM = PC_8,
        OUT1_DIR = PC_5,
        OUT1_PWM = PC_6,
        OUT2_DIR = PB_1,
        OUT2_PWM = PB_2,
        OUT3_DIR = PA_12,
        OUT3_PWM = PA_11,
        CAN_TX = PB_9,
        CAN_RX = PB_8,
        SPI2_MOSI = PB_15,
        SPI2_MISO = PB_14,
        SPI2_SCLK = PB_13,
        SPI2_CS = PC_4
    }ConnecterPin;
}

class Brain_Board_ver0 {
    public:
    Brain_Board_ver0();

    private:

};
#endif
