/*****< iasapi.h >*************************************************************/
/*      Copyright 2012 - 2014 Stonestreet One.                                */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  IASAPI - Stonestreet One Bluetooth Immediate Alert Service (GATT          */
/*           based) API Type Definitions, Constants, and Prototypes.          */
/*                                                                            */
/*  Author:  Ajay Parashar                                                    */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   08/24/12  A. Parashar    Initial creation.                               */
/******************************************************************************/
#ifndef __IASAPIH__
#define __IASAPIH__

#include "SS1BTPS.h"         /* Bluetooth Stack API Prototypes/Constants.     */
#include "SS1BTGAT.h"        /* Bluetooth Stack GATT API Prototypes/Constants.*/
#include "IASTypes.h"        /* Immediate Alert Service Types/Constants.      */

   /* Error Return Codes.                                               */

   /* Error Codes that are smaller than these (less than -1000) are     */
   /* related to the Bluetooth Protocol Stack itself (see BTERRORS.H).  */
#define IAS_ERROR_INVALID_PARAMETER                      (-1000)
#define IAS_ERROR_INVALID_BLUETOOTH_STACK_ID             (-1001)
#define IAS_ERROR_INSUFFICIENT_RESOURCES                 (-1002)
#define IAS_ERROR_SERVICE_ALREADY_REGISTERED             (-1003)
#define IAS_ERROR_INVALID_INSTANCE_ID                    (-1004)
#define IAS_ERROR_MALFORMATTED_DATA                      (-1005)
#define IAS_ERROR_UNKNOWN_ERROR                          (-1006)

   /* The following structure contains the Handles that will need to be */
   /* cached by a IAS client in order to only do service discovery once.*/
typedef struct _tagIAS_Client_Information_t
{
   Word_t Control_Point;
} IAS_Client_Information_t;

#define IAS_CLIENT_INFORMATION_DATA_SIZE                (sizeof(IAS_Client_Information_t))

   /* The following enumerated type represents all of the valid commands*/
   /* that may be received in an                                        */
   /* etIAS_Server_Alert_Level_Control_Point_Command Server event OR    */
   /* that may be written to a remote IAS Server.                       */
typedef enum
{
   cpNoAlert      = IAS_ALERT_LEVEL_NO_ALERT,
   cpMildAlert    = IAS_ALERT_LEVEL_MILD_ALERT,
   cpHighAlert    = IAS_ALERT_LEVEL_HIGH_ALERT
} IAS_Control_Point_Command_t;

   /* The following enumeration covers all the events generated by the  */
   /* IAS Service.These are used to determine the type of each event    */
   /* generated, and to ensure the proper union element is accessed for */
   /* the IAS_Event_Data_t structure.                                   */
typedef enum   _tagIAS_Event_Type_t
{
   etIAS_Server_Alert_Level_Control_Point_Command
} IAS_Event_Type_t;

   /* The following IAS Service Event is dispatched to a IAS Server     */
   /* when a IAS Client has sent an Alert Level Control Point Command.  */
   /* The ConnectionID, ConnectionType, and RemoteDevice specify the    */
   /* Client that is making the request.  The final parameter specifies */
   /* the Alert Level Control Point command that the client sent.       */
typedef struct _tagIAS_Alert_Level_Control_Point_Command_Data_t
{
   unsigned int                InstanceID;
   unsigned int                ConnectionID;
   GATT_Connection_Type_t      ConnectionType;
   BD_ADDR_t                   RemoteDevice;
   IAS_Control_Point_Command_t Command;
} IAS_Alert_Level_Control_Point_Command_Data_t;

#define IAS_ALERT_LEVEL_CONTROL_POINT_COMMAND_DATA_SIZE       (sizeof(IAS_Alert_Level_Control_Point_Command_Data_t))

   /* The following structure represents the container structure for    */
   /* holding all IAS Service Event Data.  This structure is received   */
   /* for each event generated.  The Event_Data_Type member is used to  */
   /* determine the appropriate union member element to access the      */
   /* contained data.  The Event_Data_Size member contains the total    */
   /* size of the data contained in this event.                         */
typedef struct _tagIAS_Event_Data_t
{
   IAS_Event_Type_t Event_Data_Type;
   Byte_t           Event_Data_Size;
   union
   {
     IAS_Alert_Level_Control_Point_Command_Data_t  *IAS_Alert_Level_Control_Point_Command_Data;
   } Event_Data;
} IAS_Event_Data_t;

#define IAS_EVENT_DATA_SIZE                             (sizeof(IAS_Event_Data_t))

   /* The following declared type represents the Prototype Function for */
   /* a IAS Service Event Receive Data Callback.  This function will be */
   /* called whenever an IAS Service Event occurs that is associated    */
   /* with the specified Bluetooth Stack ID.  This function passes to   */
   /* the caller the Bluetooth Stack ID, the IAS Event Data that        */
   /* occurred and the IAS Service Event Callback Parameter that was    */
   /* specified when this Callback was installed.  The caller is free to*/
   /* use the contents of the IAS Service Event Data ONLY in  context   */
   /* of this callback.  If the caller requires the Data for a longer   */
   /* period of time, then the callback function MUST copy the data into*/
   /* another Data Buffer This function is guaranteed NOT to be invoked */
   /* more than once simultaneously for the specified installed callback*/
   /* (i.e.  this function DOES NOT have be re-entrant).  It needs to be*/
   /* noted however, that if the same Callback is installed more than   */
   /* once, then the callbacks will be called serially.  Because of     */
   /* this, the processing in this function should be as efficient as   */
   /* possible.  It should also be noted that this function is called in*/
   /* the Thread Context of a Thread that the User does NOT own.        */
   /* Therefore, processing in this function should be as efficient as  */
   /* possible (this argument holds anyway because another IAS Service  */
   /* Event will not be processed while this function call is           */
   /* outstanding).                                                     */
   /* ** NOTE ** This function MUST NOT Block and wait for events that  */
   /*            can only be satisfied by Receiving IAS Service Event   */
   /*            Packets.  A Deadlock WILL occur because NO IAS Event   */
   /*            Callbacks will be issued while this function is        */
   /*            currently outstanding.                                 */
typedef void (BTPSAPI *IAS_Event_Callback_t)(unsigned int BluetoothStackID, IAS_Event_Data_t *IAS_Event_Data, unsigned long CallbackParameter);

   /* IAS Server API.                                                   */

   /* The following function is responsible for opening a IAS Server.   */
   /* The first parameter is the Bluetooth Stack ID on which to open the*/
   /* server.  The second parameter is the Callback function to call    */
   /* when an event occurs on this Server Port.  The third parameter is */
   /* a user-defined callback parameter that will be passed to the      */
   /* callback function with each event.  The final parameter is a      */
   /* pointer to store the GATT Service ID of the registered IAS        */
   /* service.  This can be used to include the service registered by   */
   /* this call.  This function returns the positive, non-zero, Instance*/
   /* ID or a negative error code.                                      */
   /* * NOTE * Only 1 IAS may be open at a time, per Bluetooth          */
   /*          Stack ID.                                                */
   /* * NOTE * All Client Requests will be dispatch to the EventCallback*/
   /*          function that is specified by the second parameter to    */
   /*          this function.                                           */
BTPSAPI_DECLARATION int BTPSAPI IAS_Initialize_Service(unsigned int BluetoothStackID, IAS_Event_Callback_t EventCallback, unsigned long CallbackParameter, unsigned int *ServiceID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IAS_Initialize_Service_t)(unsigned int BluetoothStackID, IAS_Event_Callback_t EventCallback, unsigned long CallbackParameter, unsigned int *ServiceID);
#endif

   /* The following function is responsible for opening a IAS Server.   */
   /* The first parameter is the Bluetooth Stack ID on which to open the*/
   /* server.  The second parameter is the Callback function to call    */
   /* when an event occurs on this Server Port.  The third parameter is */
   /* a user-defined callback parameter that will be passed to the      */
   /* callback function with each event.  The fourth parameter is a     */
   /* pointer to store the GATT Service ID of the registered IAS        */
   /* service.  This can be used to include the service registered by   */
   /* this call.  The final parameter is a pointer, that on input can be*/
   /* used to control the location of the service in the GATT database, */
   /* and on ouput to store the service handle range.  This function    */
   /* returns the positive, non-zero, Instance ID or a negative error   */
   /* code.                                                             */
   /* * NOTE * Only 1 IAS Server may be open at a time, per Bluetooth   */
   /*          Stack ID.                                                */
   /* * NOTE * All Client Requests will be dispatch to the EventCallback*/
   /*          function that is specified by the second parameter to    */
   /*          this function.                                           */
BTPSAPI_DECLARATION int BTPSAPI IAS_Initialize_Service_Handle_Range(unsigned int BluetoothStackID, IAS_Event_Callback_t EventCallback, unsigned long CallbackParameter, unsigned int *ServiceID, GATT_Attribute_Handle_Group_t *ServiceHandleRange);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IAS_Initialize_Service_Handle_Range_t)(unsigned int BluetoothStackID, IAS_Event_Callback_t EventCallback, unsigned long CallbackParameter, unsigned int *ServiceID, GATT_Attribute_Handle_Group_t *ServiceHandleRange);
#endif

   /* The following function is responsible for closing a previously    */
   /* opened IAS Server.  The first parameter is the Bluetooth Stack ID */
   /* on which to close the server.  The second parameter is the        */
   /* InstanceID that was returned from a successful call to            */
   /* IAS_Initialize_Service().  This function returns a zero if        */
   /* successful or a negative return error code if an error occurs.    */
BTPSAPI_DECLARATION int BTPSAPI IAS_Cleanup_Service(unsigned int BluetoothStackID, unsigned int InstanceID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IAS_Cleanup_Service_t)(unsigned int BluetoothStackID, unsigned int InstanceID);
#endif

   /* The following function is responsible for querying the number of  */
   /* attributes that are contained in the IAS Service that is          */
   /* registered with a call to IAS_Initialize_Service().  This function*/
   /* returns the non-zero number of attributes that are contained in an*/
   /* IAS Server or zero on failure.                                    */
BTPSAPI_DECLARATION unsigned int BTPSAPI IAS_Query_Number_Attributes(void);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef unsigned int (BTPSAPI *PFN_IAS_Query_Number_Attributes_t)(void);
#endif

   /* IAS Client API.                                                   */

   /* The following function is responsible for formatting an Alert     */
   /* Level Control Point Command into a user specified buffer. The     */
   /* first parameter is the command to format.  The final two          */
   /* parameters contain the length of the buffer, and the buffer, to   */
   /* format the command into. This function returns a zero if          */
   /* successful or a negative return error code if an error occurs.    */
   /* * NOTE * The BufferLength and Buffer parameter must point to a    */
   /*          buffer of at least                                       */
   /*          IAS_ALERT_LEVEL_CONTROL_POINT_VALUE_LENGTH in size.      */
BTPSAPI_DECLARATION int BTPSAPI IAS_Format_Control_Point_Command(IAS_Control_Point_Command_t Command, unsigned int BufferLength, Byte_t *Buffer);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_IAS_Format_Control_Point_Command_t)(IAS_Control_Point_Command_t Command, unsigned int BufferLength, Byte_t *Buffer);
#endif

#endif
