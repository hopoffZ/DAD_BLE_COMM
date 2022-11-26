/*****< sender.c >*************************************************************/
/*                                                                            */
/*  sender.c - Implementations of functions for use by RSA in DAD wireless    */
/*             communication                                                  */
/*                                                                            */
/*  Author:  Alex Miller                                                      */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   11/20/22  A. Miller      Initial creation.                               */
/******************************************************************************/

#include "sender.h" //Sender header file

//TODO: sender implementations

   /* The following function is responsible for sending a Heart Rate    */
   /* Measurement notification to a specified remote device.  The first */
   /* parameter is the Bluetooth Stack ID of the Bluetooth Device.  The */
   /* second parameter is the InstanceID returned from a successful call*/
   /* to HRS_Initialize_Server().  The third parameter is the           */
   /* ConnectionID of the remote device to send the notification to.    */
   /* The final parameter is the Heart Rate Measurement data to notify. */
   /* This function returns a zero if successful or a negative return   */
   /* error code if an error occurs.                                    */
   /* Above is DEPRECATED. This is being altered to send data from RSA  */
   /* to the handheld device.											*/
int DAD_Notify_Handheld(unsigned int BluetoothStackID, unsigned int ConnectionID, DAD_Measurement_Data_t *DAD_Measurement)
{
   int                  ret_val;
   uint64_t             *NotificationData; //64 bit container
   Word_t               MTU;
   unsigned int         NotificationDataLength;

   /* Make sure the parameters passed to us are semi-valid.             */
   if((BluetoothStackID) && (ConnectionID) && (DAD_Measurement))
   {
	 /* Call GATT to determine the Connection MTU */
	 if(!(ret_val = GATT_Query_Connection_MTU(BluetoothStackID, ConnectionID, &MTU)))
	 {
		/* Allocate a buffer that is big enough to hold the         */
		/* notification.                                            */
		NotificationDataLength = MTU / 8; //TODO: temporary, change later
		if((NotificationData = BTPS_AllocateMemory(NotificationDataLength)) != NULL)
		{
		   /* Initialize the Notification Data memory.              */
		   BTPS_MemInitialize(NotificationData, 0, NotificationDataLength);
		   uint32_t reading = DAD_Measurement->reading;
		   uint32_t name = DAD_Measurement->SensorName;
		   NotificationData = ;
		   /* Attempt to send the notification.                  */
		   ret_val = GATT_Handle_Value_Notification(ServiceInstance->BluetoothStackID, ServiceInstance->ServiceID, ConnectionID, HRS_HEART_RATE_MEASUREMENT_ATTRIBUTE_OFFSET, (Word_t)NotificationDataLength, (Byte_t *)NotificationData);
		   if(ret_val > 0) ret_val = 0;

		   /* Free the previously allocated memory.                 */
		   BTPS_FreeMemory(NotificationData);
		}
		else
		   ret_val = -1;
	 }

	 /* UnLock the previously locked Bluetooth Stack.               */
	 BSC_UnLockBluetoothStack(ServiceInstance->BluetoothStackID);
   }
   else
      ret_val = -1;

   /* Finally return the result to the caller.                          */
   return(ret_val);
}
