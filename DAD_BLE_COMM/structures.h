/*****< structures.h >*********************************************************/
/*                                                                            */
/*  structures.h - Definitions and descriptions of helper functions for use   */
/*                 across multiple components of DAD wireless communication   */
/*                                                                            */
/*  Author:  Alex Miller                                                      */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   11/20/22  A. Miller      Initial creation.                               */
/******************************************************************************/


#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include "SS1BTPS.h"             /* Main SS1 Bluetooth Stack Header.          */
#include "BTPSKRNL.h"            /* BTPS Kernel Prototypes/Constants.         */

typedef struct Octuplet octuplet; //8-bit unsigned binary value

struct Octuplet {
    unsigned int value:1;
};

typedef struct TimeStamp timeStamp; //32-bit unsigned binary value for timestamps

struct TimeStamp {
    unsigned int value:4;
};

enum SensorType{ //structure for identifying sensor TYPES- **INSTANTIATE AS TRIPLET!**
    UNKNOWN = 0,
    TEMP    = 1,
    HUM     = 2,
    SOUND   = 3,
    VIBE    = 4
};

typedef struct SensorData { //packaged data to be parsed by sender into Data object
    unsigned int data : 8; //64 bit data field, unsigned int for now, which *should* be okay.
    octuplet sensorType; //sensor type field, 8 bits, UNKNOWN by default
} SensorData;

typedef struct Data{ //aforementioned data object- this is what will be sent over bluetooth, ideally
    timeStamp ts; //timestamp (since power on) of sampling
    struct SensorData samples[8]; //array (8 wide) of sensorData objects for transmission.
} Data;

timeStamp getTime(); //get time since power on

const char* timestamp2String(timeStamp ts); //translates 32bit timestamp into more readable string format

#endif /* STRUCTURES_H_ */
