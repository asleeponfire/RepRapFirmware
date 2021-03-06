#ifndef AZSMZ_MINI_H
#define AZSMZ_MINI_H

#include "../Pins_LPC.h"

// List of assignable pins and their mapping from names to MPU ports. This is indexed by logical pin number.
// The names must match user input that has been concerted to lowercase and had _ and - characters stripped out.
// Aliases are separate by the , character.
// If a pin name is prefixed by ! then this means the pin is hardware inverted. The same pin may have names for both the inverted and non-inverted cases,
// for example the inverted heater pins on the expansion connector are available as non-inverted servo pins on a DFueX.

constexpr PinEntry PinTable_AZSMZ[] =
{

    //Thermistors
    //TODO:: need confirmation on the term assignments and names???
    {P0_23, PinCapability::ainrw, "bedtemp,t0"},
    {P0_24, PinCapability::ainrw, "e0temp,t1"},
    {P0_25, PinCapability::ainrw, "e1temp,t2"},

    //Endstops
    {P1_24, PinCapability::rw, "x,xstop"},
    {P1_26, PinCapability::rw, "y,ystop"},
    {P1_28, PinCapability::rw, "z,zstop"},
    {P1_29, PinCapability::rw, "probe"},
    
    //Heaters and Fans
    {P2_5, PinCapability::rwpwm, "bed,d8"  },
    {P2_7,  PinCapability::rwpwm, "e0heat,d9" },
    {P2_4,  PinCapability::rwpwm, "e1heat,d10" },
    {P0_26,  PinCapability::rwpwm, "Fan0,Fan1" },
    
    //servo
    {P1_23, PinCapability::rwpwm, "P1.23,servo0"},
    
    //Aux-2
    {P1_27, PinCapability::rw, "P1.27"},
    {P1_25, PinCapability::rw, "P1.25"},
    {P4_28, PinCapability::rw, "P4.28"},
    {P1_30, PinCapability::rw, "P1.30"},
    {P0_26, PinCapability::rw, "P0.26"},
    {P2_6,  PinCapability::rw, "P2.6"},
    {P1_22, PinCapability::rw, "P1.22"},
    {P3_26, PinCapability::rw, "P3.26"},
    
    //Aux-3
    {P0_27, PinCapability::rw, "sda,P0.27"},
    {P0_28, PinCapability::rw, "scl,P0.28"},
    //"sck1"}, //used by SSP
    {P0_16, PinCapability::rw, "ssel1,P0.16"},
    //"miso1"}, //used by SSP
    //"mosi1"}, //Used by SSP
    {P1_31, PinCapability::rw, "P1.31"},
    {P3_25, PinCapability::rw, "P3.25"},
    //{P0_3, PinCapability::rw, "rx"}, // USed by AUX Serial
    //{P0_2, PinCapability::rw, "tx"}, // USed by AUX Serial
 
};

constexpr BoardDefaults azsmzDefaults = {
    {P0_4,  P0_10, P0_19, P0_21,  P4_29},   //enablePins
    {P2_0,  P2_1,  P2_2,  P2_3,   P2_8},    //stepPins
    {P0_5,  P0_11, P0_20, P0_22,  P2_13},   //dirPins
#if LPC_TMC_SOFT_UART
    {NoPin, NoPin, NoPin, NoPin, NoPin},    //uartPins
    0,                                      // Smart drivers
#endif
    0,                                      //digiPot Factor
};

#endif