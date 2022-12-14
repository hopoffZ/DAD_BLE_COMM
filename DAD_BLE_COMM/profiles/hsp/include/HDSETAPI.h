/*****< hdsetapi.h >***********************************************************/
/*      Copyright 2001 - 2014 Stonestreet One.                                */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  HDSETAPI - Stonestreet One Bluetooth Stack Headset Profile API Type       */
/*           Definitions, Constants, and Prototypes.                          */
/*                                                                            */
/*  Author:  Damon Lange                                                      */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   08/18/01  D. Lange       Initial creation.                               */
/******************************************************************************/
#ifndef __HDSETAPIH__
#define __HDSETAPIH__

#include "SS1BTPS.h"            /* Bluetooth Stack API Prototypes/Constants.  */

   /* Error Return Codes.                                               */

   /* Error Codes that are smaller than these (less than -1000) are     */
   /* related to the Bluetooth Protocol Stack itself (see BTERRORS.H).  */
#define BTHDSET_ERROR_INVALID_PARAMETER                           (-1000)
#define BTHDSET_ERROR_NOT_INITIALIZED                             (-1001)
#define BTHDSET_ERROR_INVALID_BLUETOOTH_STACK_ID                  (-1002)
#define BTHDSET_ERROR_INSUFFICIENT_RESOURCES                      (-1004)
#define BTHDSET_ERROR_INVALID_OPERATION                           (-1005)

   /* SDP Service Classes for the Headset Profile.                      */

   /* The following MACRO is a utility MACRO that assigns the Headset   */
   /* Service Class Bluetooth Universally Unique Identifier             */
   /* (HEADSET_PROFILE_UUID_16) to the specified UUID_16_t variable.    */
   /* This MACRO accepts one parameter which is the UUID_16_t variable  */
   /* that is to receive the HEADSET_PROFILE_UUID_16 Constant value.    */
#define SDP_ASSIGN_HEADSET_PROFILE_UUID_16(_x)             ASSIGN_SDP_UUID_16((_x), 0x11, 0x08)

   /* The following MACRO is a utility MACRO that assigns the Headset   */
   /* Service Class Bluetooth Universally Unique Identifier             */
   /* (HEADSET_PROFILE_UUID_32) to the specified UUID_32_t variable.    */
   /* This MACRO accepts one parameter which is the UUID_32_t variable  */
   /* that is to receive the HEADSET_PROFILE_UUID_32 Constant value.    */
#define SDP_ASSIGN_HEADSET_PROFILE_UUID_32(_x)             ASSIGN_SDP_UUID_32((_x), 0x00, 0x00, 0x11, 0x08)

   /* The following MACRO is a utility MACRO that assigns the Headset   */
   /* Service Class Bluetooth Universally Unique Identifier             */
   /* (HEADSET_PROFILE_UUID_128) to the specified UUID_128_t variable.  */
   /* This MACRO accepts one parameter which is the UUID_128_t variable */
   /* that is to receive the HEADSET_PROFILE_UUID_128 Constant value.   */
#define SDP_ASSIGN_HEADSET_PROFILE_UUID_128(_x)            ASSIGN_SDP_UUID_128((_x), 0x00, 0x00, 0x11, 0x08, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5F, 0x9B, 0x34, 0xFB)

   /* The following MACRO is a utility MACRO that assigns the Headset   */
   /* Audio Gateway Service Class Bluetooth Universally Unique          */
   /* Identifier (HEADSET_AUDIO_GATEWAY_PROFILE_UUID_16) to the         */
   /* specified UUID_16_t variable.  This MACRO accepts one parameter   */
   /* which is the UUID_16_t variable that is to receive the            */
   /* HEADSET_AUDIO_GATEWAY_PROFILE_UUID_16 Constant value.             */
#define SDP_ASSIGN_HEADSET_AUDIO_GATEWAY_PROFILE_UUID_16(_x) ASSIGN_SDP_UUID_16((_x), 0x11, 0x12)

   /* The following MACRO is a utility MACRO that assigns the Headset   */
   /* Audio Gateway Service Class Bluetooth Universally Unique          */
   /* Identifier (HEADSET_AUDIO_GATEWAY_PROFILE_UUID_32) to the         */
   /* specified UUID_32_t variable.  This MACRO accepts one parameter   */
   /* which is the UUID_32_t variable that is to receive the            */
   /* HEADSET_AUDIO_GATEWAY_PROFILE_UUID_32 Constant value.             */
#define SDP_ASSIGN_HEADSET_AUDIO_GATEWAY_PROFILE_UUID_32(_x) ASSIGN_SDP_UUID_32((_x), 0x00, 0x00, 0x11, 0x12)

   /* The following MACRO is a utility MACRO that assigns the Headset   */
   /* Audio Gateway Service Class Bluetooth Universally Unique          */
   /* Identifier (HEADSET_AUDIO_GATEWAY_PROFILE_UUID_128) to the        */
   /* specified UUID_128_t variable.  This MACRO accepts one parameter  */
   /* which is the UUID_128_t variable that is to receive the           */
   /* HEADSET_AUDIO_GATEWAY_PROFILE_UUID_128 Constant value.            */
#define SDP_ASSIGN_HEADSET_AUDIO_GATEWAY_PROFILE_UUID_128(_x) ASSIGN_SDP_UUID_128((_x), 0x00, 0x00, 0x11, 0x12, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0x80, 0x5F, 0x9B, 0x34, 0xFB)

   /* Defines the Profile Version Number used within the SDP Record for */
   /* Headset Profile Servers (both Audio Gateway and Headset).         */
#define HDSET_PROFILE_VERSION                                           (0x0102)

   /* The following BIT definitions are used to denote the possible     */
   /* Headset Profile Server Modes that can be applied to a Headset     */
   /* Profile Client Connection.  These BIT definitions are used with   */
   /* the HDSET_Set_Server_Mode() and HDSET_Get_Server_Mode() mode      */
   /* functions.                                                        */
#define HDSET_SERVER_MODE_AUTOMATIC_ACCEPT_CONNECTION                   0x00000000
#define HDSET_SERVER_MODE_MANUAL_ACCEPT_CONNECTION                      0x00000001

   /* The following BIT MASK is used to mask the Server Mode Accept     */
   /* Connection settings from other (undefined) Server Mode bits.      */
#define HDSET_SERVER_MODE_CONNECTION_MASK                               0x00000001

   /* The following constants represent the Port Open Status Values     */
   /* that are possible in the Port Open Confirmation Event.            */
#define HDSET_OPEN_PORT_STATUS_SUCCESS                                  0x00
#define HDSET_OPEN_PORT_STATUS_CONNECTION_TIMEOUT                       0x01
#define HDSET_OPEN_PORT_STATUS_CONNECTION_REFUSED                       0x02
#define HDSET_OPEN_PORT_STATUS_AUDIO_CONNECTION_ERROR                   0x03
#define HDSET_OPEN_PORT_STATUS_UNKNOWN_ERROR                            0x04

   /* The following constants represent the Port Close Status Values    */
   /* that are possible in the Port Close Indication Event.             */
#define HDSET_CLOSE_PORT_STATUS_SUCCESS                                 0x00
#define HDSET_CLOSE_PORT_STATUS_AUDIO_CONNECTION_ERROR                  0x01
#define HDSET_CLOSE_PORT_STATUS_UNKNOWN_ERROR                           0x02

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the Speaker Gain.                            */
#define HDSET_SPEAKER_GAIN_MINIMUM                                      0x00
#define HDSET_SPEAKER_GAIN_MAXIMUM                                      0x0F

   /* The following constants represent the Minimum and Maximum         */
   /* allowable values for the Microphone Gain.                         */
#define HDSET_MICROPHONE_GAIN_MINIMUM                                   0x00
#define HDSET_MICROPHONE_GAIN_MAXIMUM                                   0x0F

   /* Headset Event API Types.                                          */
typedef enum
{
   etHDSET_Open_Port_Indication,
   etHDSET_Open_Port_Confirmation,
   etHDSET_Close_Port_Indication,
   etHDSET_Ring_Indication,
   etHDSET_Button_Pressed_Indication,
   etHDSET_Speaker_Gain_Indication,
   etHDSET_Microphone_Gain_Indication,
   etHDSET_Audio_Connection_Indication,
   etHDSET_Audio_Disconnection_Indication,
   etHDSET_Audio_Data_Indication,
   etHDSET_Audio_Transmit_Buffer_Empty_Indication,
   etHDSET_Open_Port_Request_Indication
} HDSET_Event_Type_t;

typedef struct _tagHDSET_Open_Port_Request_Indication_Data_t
{
   unsigned int HDSETPortID;
   BD_ADDR_t    BD_ADDR;
} HDSET_Open_Port_Request_Indication_Data_t;

#define HDSET_OPEN_PORT_REQUEST_INDICATION_DATA_SIZE              (sizeof(HDSET_Open_Port_Request_Indication_Data_t))

typedef struct _tagHDSET_Open_Port_Indication_Data_t
{
   unsigned int HDSETPortID;
   BD_ADDR_t    BD_ADDR;
} HDSET_Open_Port_Indication_Data_t;

#define HDSET_OPEN_PORT_INDICATION_DATA_SIZE                      (sizeof(HDSET_Open_Port_Indication_Data_t))

typedef struct _tagHDSET_Open_Port_Confirmation_Data_t
{
   unsigned int HDSETPortID;
   unsigned int PortOpenStatus;
} HDSET_Open_Port_Confirmation_Data_t;

#define HDSET_OPEN_PORT_CONFIRMATION_DATA_SIZE                    (sizeof(HDSET_Open_Port_Confirmation_Data_t))

typedef struct _tagHDSET_Close_Port_Indication_Data_t
{
   unsigned int HDSETPortID;
   unsigned int PortCloseStatus;
} HDSET_Close_Port_Indication_Data_t;

#define HDSET_CLOSE_PORT_INDICATION_DATA_SIZE                     (sizeof(HDSET_Close_Port_Indication_Data_t))

typedef struct _tagHDSET_Ring_Indication_Data_t
{
   unsigned int HDSETPortID;
} HDSET_Ring_Indication_Data_t;

#define HDSET_RING_INDICATION_DATA_SIZE                           (sizeof(HDSET_Ring_Indication_Data_t))

typedef struct _tagHDSET_Button_Pressed_Indication_Data_t
{
   unsigned int HDSETPortID;
   Boolean_t    ConnectionPresent;
} HDSET_Button_Pressed_Indication_Data_t;

#define HDSET_BUTTON_PRESSED_INDICATION_DATA_SIZE                 (sizeof(HDSET_Button_Pressed_Indication_Data_t))

typedef struct _tagHDSET_Speaker_Gain_Indication_Data_t
{
   unsigned int HDSETPortID;
   unsigned int SpeakerGain;
} HDSET_Speaker_Gain_Indication_Data_t;

#define HDSET_SPEAKER_GAIN_INDICATION_DATA_SIZE                   (sizeof(HDSET_Speaker_Gain_Indication_Data_t))

typedef struct _tagHDSET_Microphone_Gain_Indication_Data_t
{
   unsigned int HDSETPortID;
   unsigned int MicrophoneGain;
} HDSET_Microphone_Gain_Indication_Data_t;

#define HDSET_MICROPHONE_GAIN_INDICATION_DATA_SIZE                (sizeof(HDSET_Microphone_Gain_Indication_Data_t))

typedef struct _tagHDSET_Audio_Connection_Indication_Data_t
{
   unsigned int HDSETPortID;
   Word_t       SCO_Connection_Handle;
} HDSET_Audio_Connection_Indication_Data_t;

#define HDSET_AUDIO_CONNECTION_INDICATION_DATA_SIZE               (sizeof(HDSET_Audio_Connection_Indication_Data_t))

typedef struct _tagHDSET_Audio_Disconnection_Indication_Data_t
{
   unsigned int HDSETPortID;
} HDSET_Audio_Disconnection_Indication_Data_t;

#define HDSET_AUDIO_DISCONNECTION_INDICATION_DATA_SIZE            (sizeof(HDSET_Audio_Disconnection_Indication_Data_t))

typedef struct _tagHDSET_Audio_Data_Indication_Data_t
{
   unsigned int  HDSETPortID;
   Byte_t        AudioDataLength;
   Byte_t       *AudioData;
   Word_t        PacketStatus;
} HDSET_Audio_Data_Indication_Data_t;

#define HDSET_AUDIO_DATA_INDICATION_DATA_SIZE                     (sizeof(HDSET_Audio_Data_Indication_Data_t))

typedef struct _tagHDSET_Audio_Transmit_Buffer_Empty_Indication_Data_t
{
   unsigned int HDSETPortID;
} HDSET_Audio_Transmit_Buffer_Empty_Indication_Data_t;

#define HDSET_AUDIO_TRANSMIT_BUFFER_EMPTY_INDICATION_DATA_SIZE    (sizeof(HDSET_Audio_Transmit_Buffer_Empty_Indication_Data_t))

   /* The following structure represents the container structure for    */
   /* Holding all Headset Event Data Data.                              */
typedef struct _tagHDSET_Event_Data_t
{
   HDSET_Event_Type_t Event_Data_Type;
   Word_t             Event_Data_Size;
   union
   {
      HDSET_Open_Port_Request_Indication_Data_t           *HDSET_Open_Port_Request_Indication_Data;
      HDSET_Open_Port_Indication_Data_t                   *HDSET_Open_Port_Indication_Data;
      HDSET_Open_Port_Confirmation_Data_t                 *HDSET_Open_Port_Confirmation_Data;
      HDSET_Close_Port_Indication_Data_t                  *HDSET_Close_Port_Indication_Data;
      HDSET_Ring_Indication_Data_t                        *HDSET_Ring_Indication_Data;
      HDSET_Button_Pressed_Indication_Data_t              *HDSET_Button_Pressed_Indication_Data;
      HDSET_Speaker_Gain_Indication_Data_t                *HDSET_Speaker_Gain_Indication_Data;
      HDSET_Microphone_Gain_Indication_Data_t             *HDSET_Microphone_Gain_Indication_Data;
      HDSET_Audio_Connection_Indication_Data_t            *HDSET_Audio_Connection_Indication_Data;
      HDSET_Audio_Disconnection_Indication_Data_t         *HDSET_Audio_Disconnection_Indication_Data;
      HDSET_Audio_Data_Indication_Data_t                  *HDSET_Audio_Data_Indication_Data;
      HDSET_Audio_Transmit_Buffer_Empty_Indication_Data_t *HDSET_Audio_Transmit_Buffer_Empty_Indication_Data;
   } Event_Data;
} HDSET_Event_Data_t;

#define HDSET_EVENT_DATA_SIZE                           (sizeof(HDSET_Event_Data_t))

   /* The following declared type represents the Prototype Function for */
   /* an Headset Profile Event Receive Data Callback.  This function    */
   /* will be called whenever a Headset Event occurs that is associated */
   /* with the specified Bluetooth Stack ID.  This function passes to   */
   /* the caller the Bluetooth Stack ID, the Headset Event Data that    */
   /* occurred and the Headset Event Callback Parameter that was        */
   /* specified when this Callback was installed.  The caller is free to*/
   /* use the contents of the Headset Event Data ONLY in the context of */
   /* this callback.  If the caller requires the Data for a longer      */
   /* period of time, then the callback function MUST copy the data into*/
   /* another Data Buffer.  This function is guaranteed NOT to be       */
   /* invoked more than once simultaneously for the specified installed */
   /* callback (i.e. this function DOES NOT have be reentrant).  It     */
   /* Needs to be noted however, that if the same Callback is installed */
   /* more than once, then the callbacks will be called serially.       */
   /* Because of this, the processing in this function should be as     */
   /* efficient as possible.  It should also be noted that this function*/
   /* is called in the Thread Context of a Thread that the User does NOT*/
   /* own.  Therefore, processing in this function should be as         */
   /* efficient as possible (this argument holds anyway because another */
   /* Headset Profile Event will not be processed while this function   */
   /* call is outstanding).                                             */
   /* ** NOTE ** This function MUST NOT Block and wait for events that  */
   /*            can only be satisfied by Receiving Headset Event       */
   /*            Packets.  A Deadlock WILL occur because NO Headset     */
   /*            Event Callbacks will be issued while this function is  */
   /*            currently outstanding.                                 */
typedef void (BTPSAPI *HDSET_Event_Callback_t)(unsigned int BluetoothStackID, HDSET_Event_Data_t *HDSET_Event_Data, unsigned long CallbackParameter);

   /* The following function is responsible for Opening a Headset       */
   /* Server on the specified Bluetooth SPP Serial Port.  This function */
   /* accepts as input the Bluetooth Stack ID of the Bluetooth Stack    */
   /* Instance to use for the Headset Server, the Local Serial Port     */
   /* Server Number to use, a BOOLEAN Flag that specifies whether or    */
   /* not the Headset supports Remote Audio Volume Controls (TRUE if    */
   /* supported), and the HDSET Event Callback function (and parameter) */
   /* to associate with the specified Headset Port.  The ServerPort     */
   /* parameter *MUST* be between SPP_PORT_NUMBER_MINIMUM and           */
   /* SPP_PORT_NUMBER_MAXIMUM.  This function returns a positive,       */
   /* non-zero, value if successful or a negative return error code if  */
   /* an error occurs.  A successful return code will be a HDSET Port ID*/
   /* that can be used to reference the Opened HDSET Port in ALL other  */
   /* functions in this module except for the                           */
   /* HDSET_Register_Audio_Gateway_SDP_Record() function which is       */
   /* specific to an Audio Gateway Server NOT a Headset Server.  Once a */
   /* Server HDSET Port is opened, it can only be Un-Registered via a   */
   /* call to the HDSET_Close_Server_Port() function (passing the       */
   /* return value from this function).  The HDSET_Close_Port()         */
   /* function can be used to Disconnect a Client from the Server Port  */
   /* (if one is connected, it will NOT Un-Register the Server Port     */
   /* however).                                                         */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Open_Headset_Server_Port(unsigned int BluetoothStackID, unsigned int ServerPort, Boolean_t RemoteVolumeControlSupported, HDSET_Event_Callback_t EventCallback, unsigned long CallbackParameter);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Open_Headset_Server_Port_t)(unsigned int BluetoothStackID, unsigned int ServerPort, Boolean_t RemoteVoluemeControlSupported, HDSET_Event_Callback_t EventCallback, unsigned long CallbackParameter);
#endif

   /* The following function is responsible for Opening an Audio Gateway*/
   /* Server on the specified Bluetooth SPP Serial Port.  This function */
   /* accepts as input the Bluetooth Stack ID of the Bluetooth Stack    */
   /* Instance to use for the Audio Gateway Server, the Local Serial    */
   /* Port Server Number to use, and the HDSET Event Callback function  */
   /* (and parameter) to associate with the specified Headset Port.     */
   /* The ServerPort parameter *MUST* be between                        */
   /* SPP_PORT_NUMBER_MINIMUM and SPP_PORT_NUMBER_MAXIMUM.  This        */
   /* function returns a positive, non-zero, value if successful or a   */
   /* negative return error code if an error occurs. A successful       */
   /* return code will be a HDSET Port ID that can be used to reference */
   /* the Opened HDSET Port in ALL other functions in this module       */
   /* except for the HDSET_Register_Headset_SDP_Record() function which */
   /* is specific to a Headset Server NOT an Audio Gateway.  Once a     */
   /* Server HDSET Port is opened, it can only be Un-Registered via a   */
   /* call to the HDSET_Close_Server_Port() function (passing the       */
   /* return value from this function).  The HDSET_Close_Port() function*/
   /* can be used to Disconnect a Client from the Server Port (if one   */
   /* is connected, it will NOT Un-Register the Server Port however).   */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Open_Audio_Gateway_Server_Port(unsigned int BluetoothStackID, unsigned int ServerPort, HDSET_Event_Callback_t EventCallback, unsigned long CallbackParameter);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Open_Audio_Gateway_Server_Port_t)(unsigned int BluetoothStackID, unsigned int ServerPort, HDSET_Event_Callback_t EventCallback, unsigned long CallbackParameter);
#endif

   /* The following function is responsible for Un-Registering a HDSET  */
   /* Port Server (which was Registered by a successful call to either  */
   /* the HDSET_Open_Headset_Server_Port() or the                       */
   /* HDSET_Open_Audio_Gateway_Server_Port() function).  This function  */
   /* accepts as input the Bluetooth Stack ID of the Bluetooth Protocol */
   /* Stack that the HDSET Port specified by the Second Parameter is    */
   /* valid for.  This function returns zero if successful, or a        */
   /* negative return error code if an error occurred (see BTERRORS.H). */
   /* Note that this function does NOT delete any SDP Service Record    */
   /* Handles.                                                          */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Close_Server_Port(unsigned int BluetoothStackID, unsigned int HDSETPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Close_Server_Port_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID);
#endif

   /* The following function is responsible for responding to requests  */
   /* to connect to a Server (either Headset or an Audio Gateway).  This*/
   /* function accepts as input the Bluetooth Stack ID of the Local     */
   /* Bluetooth Protocol Stack, the Headset Port ID (which *MUST* have  */
   /* been obtained by calling either the                               */
   /* HDSET_Open_Headset_Server_Port() or the                           */
   /* HDSET_Open_Audio_Gateway_Server_Port() functions), and as the     */
   /* final parameter whether to accept the pending connection request. */
   /* This function returns zero if successful, or a negative return    */
   /* value if there was an error.                                      */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Open_Port_Request_Response(unsigned int BluetoothStackID, unsigned int HDSETPortID, Boolean_t AcceptConnection);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Open_Port_Request_Response_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, Boolean_t AcceptConnection);
#endif

   /* The following function is provided to allow a means to add a      */
   /* Generic Headset Service Record to the SDP Database.  This function*/
   /* takes as input the Bluetooth Stack ID of the Local Bluetooth      */
   /* Protocol Stack, the HDSET Port ID (which *MUST* have been         */
   /* obtained by calling the HDSET_Open_Headset_Server_Port() function.*/
   /* The third parameter specifies the Service Name to associate with  */
   /* the SDP Record.  The final parameter is a pointer to a DWord_t    */
   /* which receives the SDP Service Record Handle if this function     */
   /* successfully creates an SDP Service Record.  If this function     */
   /* returns zero, then the SDPServiceRecordHandle entry will contain  */
   /* the Service Record Handle of the added SDP Service Record.  If    */
   /* this function fails, a negative return error code will be         */
   /* returned (see BTERRORS.H) and the SDPServiceRecordHandle value    */
   /* will be undefined.                                                */
   /* * NOTE * This function should only be called with the HDSET Port  */
   /*          ID that was returned from the                            */
   /*          HDSET_Open_Headset_Server_Port() function.  This         */
   /*          function should NEVER be used with HDSET Port ID         */
   /*          returned from the HDSET_Open_Audio_Gateway_Server_Port() */
   /*          function.                                                */
   /* * NOTE * The Service Record Handle that is returned from this     */
   /*          function will remain in the SDP Record Database until    */
   /*          it is deleted by calling the SDP_Delete_Service_Record() */
   /*          function.                                                */
   /* * NOTE * A MACRO is provided to Delete the Service Record from    */
   /*          the SDP Data Base.  This MACRO maps the                  */
   /*          HDSET_Un_Register_SDP_Record() to                        */
   /*          SDP_Delete_Service_Record().                             */
   /* * NOTE * The Service Name is always added at Attribute ID 0x0100. */
   /*          A Language Base Attribute ID List is created that        */
   /*          specifies that 0x0100 is UTF-8 Encoded, English Language.*/
BTPSAPI_DECLARATION int BTPSAPI HDSET_Register_Headset_SDP_Record(unsigned int BluetoothStackID, unsigned int HDSETPortID, char *ServiceName, DWord_t *SDPServiceRecordHandle);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Register_Headset_SDP_Record_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, char *ServiceName, DWord_t *SDPServiceRecordHandle);
#endif

   /* The following function is provided to allow a means to add a      */
   /* Generic Audio Gateway Service Record to the SDP Database.  This   */
   /* function takes as input the Bluetooth Stack ID of the Local       */
   /* Bluetooth Protocol Stack, the HDSET Port ID (which *MUST* have    */
   /* been obtained by calling the                                      */
   /* HDSET_Open_Audio_Gateway_Server_Port() function.  The third       */
   /* parameter specifies the Service Name to associate with the SDP    */
   /* Record.  The final parameter is a pointer to a DWord_t which      */
   /* receives the SDP Service Record Handle if this function           */
   /* successfully creates an SDP Service Record.  If this function     */
   /* returns zero, then the SDPServiceRecordHandle entry will contain  */
   /* the Service Record Handle of the added SDP Service Record.  If    */
   /* this function fails, a negative return error code will be         */
   /* returned (see BTERRORS.H) and the SDPServiceRecordHandle value    */
   /* will be undefined.                                                */
   /* * NOTE * This function should only be called with the HDSET Port  */
   /*          ID that was returned from the                            */
   /*          HDSET_Open_Audio_Gateway_Server_Port() function.  This   */
   /*          function should NEVER be used with HDSET Port ID         */
   /*          returned from the HDSET_Open_Headset_Server_Port()       */
   /*          function.                                                */
   /* * NOTE * The Service Record Handle that is returned from this     */
   /*          function will remain in the SDP Record Database until    */
   /*          it is deleted by calling the SDP_Delete_Service_Record() */
   /*          function.                                                */
   /* * NOTE * A MACRO is provided to Delete the Service Record from    */
   /*          the SDP Data Base.  This MACRO maps the                  */
   /*          HDSET_Un_Register_SDP_Record() to the                    */
   /*          SDP_Delete_Service_Record() function.                    */
   /* * NOTE * The Service Name is always added at Attribute ID 0x0100. */
   /*          A Language Base Attribute ID List is created that        */
   /*          specifies that 0x0100 is UTF-8 Encoded, English Language.*/
BTPSAPI_DECLARATION int BTPSAPI HDSET_Register_Audio_Gateway_SDP_Record(unsigned int BluetoothStackID, unsigned int HDSETPortID, char *ServiceName, DWord_t *SDPServiceRecordHandle);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Register_Audio_Gateway_SDP_Record_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, char *ServiceName, DWord_t *SDPServiceRecordHandle);
#endif

   /* The following MACRO is a utility MACRO that simply deletes the    */
   /* HDSET SDP Service Record (specified by the third parameter) from  */
   /* the SDP Database.  This MACRO simply maps to the                  */
   /* SDP_Delete_Service_Record() function.  This MACRO is only provided*/
   /* so that the caller doesn't have to sift through the SDP API for   */
   /* very simplistic applications.  This function accepts as input the */
   /* Bluetooth Stack ID of the Bluetooth Protocol Stack that the       */
   /* Service Record exists on, the HDSET Port ID (returned from a      */
   /* successful call to the HDSET_Open_Headset_Server_Port() or the    */
   /* HDSET_Open_Audio_Gateway_Server_Port() functions), and the SDP    */
   /* Service Record Handle.  The SDP Service Record Handle was returned*/
   /* via a successful call to the HDSET_Register_Headset_SDP_Record()  */
   /* or the HDSET_Register_Audio_Gateway_SDP_Record() function.  See   */
   /* the HDSET_Register_xxxx_SDP_Record() functions for more           */
   /* information.  This MACRO returns the result of the                */
   /* SDP_Delete_Service_Record() function, which is zero for success or*/
   /* a negative return error code (see BTERRORS.H).                    */
#define HDSET_Un_Register_SDP_Record(__BluetoothStackID, __HDSETPortID, __SDPRecordHandle) \
        (SDP_Delete_Service_Record(__BluetoothStackID, __SDPRecordHandle))

   /* The following function is responsible for Opening a Remote Headset*/
   /* Port on the specified Remote Device.  This function accepts the   */
   /* Bluetooth Stack ID of the Bluetooth Stack which is to open the    */
   /* HDSET Connection as the first parameter.  The second parameter    */
   /* specifies the Board Address (NON NULL) of the Remote Bluetooth    */
   /* Device to connect with.  The next parameter specifies whether or  */
   /* not the Local Audio Gateway (the entity that is connecting to the */
   /* Remote Headset) supports In Band Ringing or not (TRUE if          */
   /* supported).  The final two parameters specify the HDSET Event     */
   /* Callback function, and callback parameter, respectively, of the   */
   /* HDSET Event Callback that is to process any further interaction   */
   /* with the specified Remote Port (Opening Status, Close Status,     */
   /* etc).  This function returns a non-zero, positive, value if       */
   /* successful, or a negative return error code if this function is   */
   /* unsuccessful.  If this function is successful, the return value   */
   /* will represent the HDSET Port ID that can be passed to all other  */
   /* functions that require it.  Once a Remote Headset opened, it can  */
   /* only be closed via a call to the HDSET_Close_Port() function      */
   /* (passing the return value from this function).                    */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Open_Remote_Headset_Port(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, unsigned int RemoteServerPort, Boolean_t SupportInBandRinging, HDSET_Event_Callback_t EventCallback, unsigned long CallbackParameter);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Open_Remote_Headset_Port_t)(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, unsigned int RemoteServerPort, Boolean_t SupportInBandRinging, HDSET_Event_Callback_t EventCallback, unsigned long CallbackParameter);
#endif

   /* The following function is responsible for Opening a Remote Audio  */
   /* Gateway Port on the specified Remote Device.  This function       */
   /* accepts the Bluetooth Stack ID of the Bluetooth Stack which is to */
   /* open the HDSET Connection as the first parameter.  The second     */
   /* parameter specifies the Board Address (NON NULL) of the Remote    */
   /* Bluetooth Device to connect with.  The next parameter is a        */
   /* BOOLEAN Flag that specifies whether or not the Headset supports   */
   /* Remote Audio Volume Controls (TRUE if supported).  The final two  */
   /* parameters specify the HDSET Event Callback function, and         */
   /* callback parameter, respectively, of the HDSET Event Callback     */
   /* that is to process any further interaction with the specified     */
   /* Remote Port (Opening Status, Close Status, etc).  This function   */
   /* returns a non-zero, positive, value if successful, or a negative  */
   /* return error code if this function is unsuccessful.  If this      */
   /* function is successful, the return value will represent the HDSET */
   /* Port ID that can be passed to all other functions that require it.*/
   /* Once a Remote Audio Gateway is opened, it can only be closed via  */
   /* a call to the HDSET_Close_Port() function (passing the return     */
   /* value from this function).                                        */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Open_Remote_Audio_Gateway_Port(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, unsigned int RemoteServerPort, Boolean_t RemoteVolumeControlSupported, HDSET_Event_Callback_t EventCallback, unsigned long CallbackParameter);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Open_Remote_Audio_Gateway_Port_t)(unsigned int BluetoothStackID, BD_ADDR_t BD_ADDR, unsigned int RemoteServerPort, Boolean_t RemoteVolumeControlSupported, HDSET_Event_Callback_t EventCallback, unsigned long CallbackParameter);
#endif

   /* The following function is responsible for Sending a Ring          */
   /* Indication to the remote side.  The function accepts the Bluetooth*/
   /* Stack ID of the Bluetooth Stack which has received the HDSET      */
   /* Connection Request and the HDSET Port ID for which the Connection */
   /* has been established.  This function returns a zero if successful,*/
   /* or a negative return error code if there was an error.            */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Ring_Indication(unsigned int BluetoothStackID, unsigned int HDSETPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Ring_Indication_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID);
#endif

   /* The following function is responsible for sending a Button Press  */
   /* to a remote Audio Gateway.  This function accepts the Bluetooth   */
   /* Stack ID of the Bluetooth Stack which has received the HDSET      */
   /* Connection Request and the HDSET Port ID of the Headset to send   */
   /* the request on.  This function returns a zero if successful, or a */
   /* negative return error code if there was an error.                 */
   /* * NOTE * This function should be used instead of the:             */
   /*                                                                   */
   /*             HDSET_Accept_Incoming_Call()                          */
   /*          or                                                       */
   /*             HDSET_End_Call()                                      */
   /*                                                                   */
   /*          functions.  The reason is that the above two functions   */
   /*          imply a call state.  Since the actual call state is      */
   /*          handled via the Audio Gateway, the Headset does not have */
   /*          any mechanism to actually determine the call state.      */
   /*          Because of this, this function will simply issue the     */
   /*          Button Press and let the Audio Gateway decide how to     */
   /*          process the request.                                     */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Send_Button_Press(unsigned int BluetoothStackID, unsigned int HDSETPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Send_Button_Press_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID);
#endif

   /* The following function is responsible for Accepting or Rejecting a*/
   /* HDSET Incoming Call Request (Connection Request).  The function   */
   /* accepts the Bluetooth Stack ID of the Bluetooth Stack which has   */
   /* received the HDSET Connection Request, the HDSET Port ID which the*/
   /* Connection Request was issued, and a BOOLEAN flag which specifies */
   /* whether or not the connection should be accepted (TRUE if         */
   /* accepted).  This function returns a zero if successful, or a      */
   /* negative return error code if there was an error.                 */
   /* * NOTE * This function should no longer be used.  This function   */
   /*          has been superceded by the:                              */
   /*                                                                   */
   /*             HDSET_Send_Button_Press()                             */
   /*                                                                   */
   /*          function.  The reason for this is because use of this    */
   /*          function implies a call state.  Since the actual call    */
   /*          state is handled via the Audio Gateway, the Headset does */
   /*          not have any mechanism to actually determine the call    */
   /*          state.                                                   */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Accept_Incoming_Call(unsigned int BluetoothStackID, unsigned int HDSETPortID, Boolean_t AcceptCall);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Accept_Incoming_Call_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, Boolean_t AcceptCall);
#endif

   /* The following function is responsible for Requesting a Remote     */
   /* Audio Gateway to end the current connection.  The function accepts*/
   /* the Bluetooth Stack ID of the Bluetooth Stack which currently has */
   /* a HDSET Connection and the HDSET Port ID which signifies the      */
   /* connection.  This function returns a zero if successful, or a     */
   /* negative return error code if there was an error.                 */
   /* * NOTE * This function should no longer be used.  This function   */
   /*          has been superceded by the:                              */
   /*                                                                   */
   /*             HDSET_Send_Button_Press()                             */
   /*                                                                   */
   /*          function.  The reason for this is because use of this    */
   /*          function implies a call state.  Since the actual call    */
   /*          state is handled via the Audio Gateway, the Headset does */
   /*          not have any mechanism to actually determine the call    */
   /*          state.                                                   */
BTPSAPI_DECLARATION int BTPSAPI HDSET_End_Call(unsigned int BluetoothStackID, unsigned int HDSETPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_End_Call_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID);
#endif

   /* The following function exists to close a HDSET Port that was      */
   /* previously opened by any of the following mechanisms:             */
   /*    - Successful call to HDSET_Open_Remote_Headset_Port() function.*/
   /*    - Successful call to HDSET_Open_Remote_Audio_Gateway_Port()    */
   /*      function.                                                    */
   /*    - Incoming call request (Headset or Audio Gateway) which the   */
   /*      server was opened with either the                            */
   /*      HDSET_Open_Headset_Server_Port() or the                      */
   /*      HDSET_Open_Audio_Gateway_Server_Port() functions.            */
   /* This function accepts as input the Bluetooth Stack ID of the      */
   /* Bluetooth Stack which the Open HDSET Port resides and the         */
   /* HDSET Port ID (return value from one of the above mentioned Open  */
   /* functions) of the Port to Close.  This function returns zero if   */
   /* successful, or a negative return value if there was an error.     */
   /* This function does NOT Un-Register a HDSET Server Port from the   */
   /* system, it ONLY disconnects any connection that is currently      */
   /* active on the Server Port.  The HDSET_Close_Server_Port()         */
   /* function can be used to Un-Register the HDSET Server Port.        */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Close_Port(unsigned int BluetoothStackID, unsigned int HDSETPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Close_Port_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID);
#endif

   /* The following function is provided to allow the local entity a    */
   /* mechanism of notifying the Remote entity (either Headset OR Audio */
   /* Gateway) that the Speaker Gain has changed.  This function accepts*/
   /* as input the Bluetooth Stack ID of the Bluetooth Stack which the  */
   /* HDSET Port ID (second parameter) is valid for, the HDSET Port ID, */
   /* and the new Speaker Gain Setting.  This function returns zero if  */
   /* successful or a negative return error code if there was an error. */
   /* The Speaker Gain Parameter *MUST* be between the values of        */
   /* HDSET_SPEAKER_GAIN_MINIMUM and HDSET_SPEAKER_GAIN_MAXIMUM.        */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Set_Speaker_Gain(unsigned int BluetoothStackID, unsigned int HDSETPortID, unsigned int SpeakerGain);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Set_Speaker_Gain_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, unsigned int SpeakerGain);
#endif

   /* The following function is provided to allow the local entity a    */
   /* mechanism of notifying the Remote entity (either Headset OR Audio */
   /* Gateway) that the Microphone Gain has changed.  This function     */
   /* accepts as input the Bluetooth Stack ID of the Bluetooth Stack    */
   /* which the HDSET Port ID (second parameter) is valid for, the      */
   /* HDSET Port ID, and the new Microphone Gain Setting.  This         */
   /* function returns zero if successful or a negative return error    */
   /* code if there was an error.  The Microphone Gain Parameter *MUST* */
   /* be between the values of HDSET_MICROPHONE_GAIN_MINIMUM and        */
   /* HDSET_MICROPHONE_GAIN_MAXIMUM.                                    */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Set_Microphone_Gain(unsigned int BluetoothStackID, unsigned int HDSETPortID, unsigned int MicrophoneGain);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Set_Microphone_Gain_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, unsigned int MicrophoneGain);
#endif

   /* This function is responsible for Setting Up an Audio Connection   */
   /* between the Local Audio Gateway and Remote Headset Device.  This  */
   /* function may ONLY be used by an Audio Gateway.  This function     */
   /* accepts as its input parameters the Bluetooth Stack ID for which  */
   /* the HDSET Port ID is valid as well as the HDSET Port ID (of the   */
   /* Audio Gateway).  The final parameter specifies whether this is    */
   /* In-Band ringing (TRUE) or not (FALSE).  If In-Band Ringing is     */
   /* specified then the remote Headset is required to accept the call. */
   /* This function returns zero if successful or a negative return     */
   /* error code if there was an error.                                 */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Setup_Audio_Connection(unsigned int BluetoothStackID, unsigned int HDSETPortID, Boolean_t InBandRinging);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Setup_Audio_Connection_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, Boolean_t InBandRinging);
#endif

   /* This function is responsible for Releasing an Audio Connection    */
   /* which was previously established by the local Audio Gateway or by */
   /* a call to the HDSET_Setup_Audio_Connection() function.  This      */
   /* function may ONLY be used by an Audio Gateway.  This function     */
   /* accepts as its input parameters the Bluetooth Stack ID for which  */
   /* the HDSET Port ID is valid as well as the HDSET Port ID.  This    */
   /* function returns zero if successful or a negative return error    */
   /* code if there was an error.                                       */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Release_Audio_Connection(unsigned int BluetoothStackID, unsigned int HDSETPortID);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Release_Audio_Connection_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID);
#endif

   /* The following function is provided to allow the local entity a    */
   /* mechanism of sending SCO Audio Data to the Remote entity (either  */
   /* Headset OR Audio Gateway).  This function can only be called once */
   /* an Audio Connection has been established.  This function accepts  */
   /* as input the Bluetooth Stack ID of the Bluetooth Stack which the  */
   /* HDSET Port ID (second parameter) is valid for, the HDSET Port ID, */
   /* the Length (in Bytes) of the Audio Data to send, and a pointer to */
   /* the Audio Data to send to the Remote Entity.  This function       */
   /* returns zero if successful or a negative return error code if     */
   /* there was an error.                                               */
   /* * NOTE * This function is only applicable for Bluetooth Devices   */
   /*          that support Packetized SCO Audio.  This function will   */
   /*          have no effect on Codec based Bluetooth Devices.         */
   /* * NOTE * If this function returns the Error Code:                 */
   /*          BTPS_ERROR_INSUFFICIENT_BUFFER_SPACE then this is a      */
   /*          signal to the caller that the requested data could NOT be*/
   /*          sent because the requested data could not be queued in   */
   /*          the Outgoing Audio Queue.  The caller then, must wait for*/
   /*          the etHDSET_Audio_Transmit_Buffer_Empty_Indication Event */
   /*          before trying to send any more data.                     */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Send_Audio_Data(unsigned int BluetoothStackID, unsigned int HDSETPortID, Byte_t AudioDataLength, Byte_t *AudioData);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Send_Audio_Data_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, Byte_t AudioDataLength, Byte_t *AudioData);
#endif

   /* The following function is responsible for retrieving the current  */
   /* Headset/Audio Gateway Server Server Mode for a specified          */
   /* Headset/Audio Gateway server.  This function accepts as its first */
   /* parameter the Bluetooth Stack ID of the Bluetooth Stack on which  */
   /* the server exists.  The second parameter is the Headset Port ID   */
   /* that specifies the individual Server (this *MUST* be a value that */
   /* was obtained by calling either the                                */
   /* HDSET_Open_Headset_Server_Port() or the                           */
   /* HDSET_Open_Audio_Gateway_Server_Port() functions).  The final     */
   /* parameter to this function is a pointer to a Server Mode variable */
   /* which will receive the current Server Mode.  This function returns*/
   /* zero if successful, or a negative return error code if an error   */
   /* occurred.                                                         */
   /* ** NOTE ** The Default Server Mode is                             */
   /*               HDSET_SERVER_MODE_AUTOMATIC_ACCEPT_CONNECTION.      */
   /* ** NOTE ** This function is used for Headset/Audio Gateway        */
   /*            Servers which use Bluetooth Security Mode 2.           */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Get_Server_Mode(unsigned int BluetoothStackID, unsigned int HDSETPortID, unsigned long *ServerModeMask);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Get_Server_Mode_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, unsigned long *ServerModeMask);
#endif

   /* The following function is responsible for setting the             */
   /* Headset/Audio Gateway Server Mode for the specified Headset/Audio */
   /* Gateway server.  This function accepts as its first parameter the */
   /* Bluetooth Stack ID of the Bluetooth Stack on which the server     */
   /* exists.  The second parameter is the Headset Port ID that         */
   /* specifies the individual Server (this *MUST* be a value that was  */
   /* obtained by calling either the HDSET_Open_Headset_Server_Port() or*/
   /* the HDSET_Open_Audio_Gateway_Server_Port() functions).  The final */
   /* parameter to this function is the new Server Mode to set the      */
   /* Server to use.  This function returns zero if successful, or a    */
   /* negative return error code if an error occurred.                  */
   /* ** NOTE ** The Default Server Mode is                             */
   /*            HDSET_SERVER_MODE_AUTOMATIC_ACCEPT_CONNECTION.         */
   /* ** NOTE ** This function is used for Headset/Audio Gateway Servers*/
   /*            which use Bluetooth Security Mode 2.                   */
BTPSAPI_DECLARATION int BTPSAPI HDSET_Set_Server_Mode(unsigned int BluetoothStackID, unsigned int HDSETPortID, unsigned long ServerModeMask);

#ifdef INCLUDE_BLUETOOTH_API_PROTOTYPES
   typedef int (BTPSAPI *PFN_HDSET_Set_Server_Mode_t)(unsigned int BluetoothStackID, unsigned int HDSETPortID, unsigned long ServerModeMask);
#endif

#endif
