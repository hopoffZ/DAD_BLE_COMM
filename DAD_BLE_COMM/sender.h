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
#include "packager.h"
#include "GATTAPI.h"
#include "stdint.h"

typedef struct _tagDAD_Measurement_Data_t
{
   uint32_t SensorName;
   uint32_t reading;
} DAD_Measurement_Data_t;

#endif /* SENDER_H_ */
