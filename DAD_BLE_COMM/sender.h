/*****< sender.h >*************************************************************/
/*                                                                            */
/*  sender.h - Definitions and descriptions of functions for use by RSA in    */
/*             DAD wireless communication                                     */
/*                                                                            */
/*  Author:  Alex Miller                                                      */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   11/20/22  A. Miller      Initial creation.                               */
/******************************************************************************/

#ifndef SENDER_H_
#define SENDER_H_

#include "structures.h" //structures header file

struct Sender{
    octuplet sensorType[8]; //array of 8 sensor types

    struct Data data; //data object
};

struct sensorType identify(); //pull sensorType of each sensor currently active

struct Data graball(); //pull data from all Packagers and synthesize

void send(Data d);

#endif /* SENDER_H_ */
