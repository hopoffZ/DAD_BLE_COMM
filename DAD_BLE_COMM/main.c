#include "HAL.h"
#include "HCITRANS.h"
#include "main.h"
#include "msp.h"

#define SENDER   1
#define RECEIVER 0 //1: on 0: off, CANNOT be the same

/**
 * main.c
 */

   /*********************************************************************/
   /* Defines, Enumerations, & Type Definitions                         */
   /*********************************************************************/

   /* The following constant denotes the max buffer size used for user  */
   /* commands input via the User Interface.                            */
#define MAX_COMMAND_LENGTH    (64)

   /*********************************************************************/
   /* Local/Static Variables                                            */
   /*********************************************************************/

   /* Internal Variables to this Module (Remember that all variables    */
   /* declared static are initialized to 0 automatically by the         */
   /* compiler as part of standard C/C++).                              */

static unsigned int BluetoothStackID;
static unsigned int InputIndex;
static Boolean_t SleepAllowed;

   /* The following buffer is used to store console input.  An          */
   /* additional 2 bytes are added to account for 2 null characters that*/
   /* must be added to each command line before the lines are processed.*/
static char Input[MAX_COMMAND_LENGTH + 2];

   /*********************************************************************/
   /* Local/Static Functions                                            */
   /*********************************************************************/

static void ProcessInputTask(void *UserParameter);
static void IdleTask(void *UserParameter);
static void ToggleLEDTask(void *UserParameter);
static void BTPSAPI HCI_Sleep_Callback(Boolean_t _SleepAllowed, unsigned long CallbackParameter);
static void PollErrorFlags(void);
static void IdleTask_Sender(void *UserParameter);
static void IdleTask_Receiver(void *UserParameter);

   /* The following function is responsible for retrieving commands from     */
   /* the user console.  TODO update this to take data from SPE or HMI input */
static void ProcessInputTask(void *UserParameter)
{
   char      Char;
   Boolean_t systemBusy;
   unsigned int raw_data; //8 byte, 64 bit raw data holder TODO: figure out why setting this to 8 bytes breaks it

   /* Initialize the variable indicating the system is busy to false    */
   systemBusy = FALSE;

   /* Attempt to read data from the console.                            */
   while((!systemBusy) && (HAL_ConsoleRead(1, &Char))) //TODO swap HAL_ConsoleRead for SPE/HMI equivalent
   {
	   if (SENDER) {

	   }
	   else if (RECEIVER) {

	   }
	   Char = raw_data;
   }
}

   /* The following function is responsible for checking the idle state */
   /* and possibly entering LPM3 mode.                                  */
static void IdleTask(void *UserParameter)
{
   /* If the stack is idle and we are in HCILL sleep, then we may enter */
   /* a Low Power Mode (with Timer Interrupts disabled).                */
   if((BSC_QueryStackIdle(BluetoothStackID)) && (SleepAllowed))
   {
      /* The stack is idle and we are in HCILL sleep, attempt to suspend*/
      /* the UART.                                                      */
      if(!HCITR_COMSuspend()) //this needs to change, as we won't be using the COM port
      {
         /* Check to see if a wakeup is in progress (by the controller).*/
         /* If so we will disable sleep mode so that we complete the    */
         /* process.                                                    */
         if(!HCITR_COMSuspended())
            SleepAllowed = FALSE;

         /* "Go ahead and process any characters we may have received   */
         /* on the console UART." DEPRECATED                            */
         /* ProcessInputTask checks for the sender/receiver status of   */
         /* device and based on the result checks for SPE / HMI input   */
         ProcessInputTask(NULL);
      }
      else
      {
         /* Failed to suspend the UART which must mean that the         */
         /* controller is attempting to do a wakeup.  Therefore we will */
         /* flag that sleep mode is disabled.                           */
         SleepAllowed = FALSE;
      }
   }
   else
   {
      /* Poll the error flags.                                          */
      PollErrorFlags();
   }
}

   /* The following function is responsible for toggling the LED.       */
static void ToggleLEDTask(void *UserParameter)
{
   HAL_ToggleLED();
}

   /* The following is the HCI Sleep Callback.  This is registered with */
   /* the stack to note when the Host processor may enter into a sleep  */
   /* mode.                                                             */
static void BTPSAPI HCI_Sleep_Callback(Boolean_t _SleepAllowed, unsigned long CallbackParameter)
{
   /* Simply store the state internally.                                */
   SleepAllowed = _SleepAllowed;

   /* Check if sleep is allowed.                                        */
   if(SleepAllowed)
   {
      /* Sleep is allowed, set the LED color to blue to notify the user.*/
      HAL_SetLEDColor(hlcBlue);
   }
   else
   {
      /* Sleep is not allowed, set the LED color to green to notify the */
      /* user.                                                          */
      HAL_SetLEDColor(hlcGreen);
   }
}

   /* The following function polls all error flags and displays an      */
   /* appropriate message if any error flags are set.                   */
static void PollErrorFlags(void)
{
   unsigned int ErrorFlags;

   /* Query the HCI transport error flags to determine if any errors    */
   /* have occurred.                                                    */
   ErrorFlags = HCITR_COMQueryErrorFlags();

   if(ErrorFlags & HCITR_ERROR_FLAG_EUSCI_UART_RXBUF_OVERRUN)
      Display(("Error: HCITRANS eUSCI UART RXBUF register overrun.\r\n"));

   if(ErrorFlags & HCITR_ERROR_FLAG_UART_RX_BUFFER_OVERRUN)
      Display(("Error: HCITRANS UART Rx buffer overrun.\r\n"));
}


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Two options: device can be a sender, or a receiver.  This is determined by the existence of certain
	//external connections to the MSP432, I.E. HMI, removable storage, SPE, etc.


	int                           Result;
	BTPS_Initialization_t         BTPS_Initialization;
	HCI_DriverInformation_t       HCI_DriverInformation;
	HCI_HCILLConfiguration_t      HCILLConfig;
	HCI_Driver_Reconfigure_Data_t DriverReconfigureData;
	/* Configure the hardware for its intended use.                      */
	HAL_ConfigureHardware();
	/* Flag that sleep is not currently enabled.                         */
	SleepAllowed = FALSE;
	/* Configure the UART Parameters.                                    */
	HCI_DRIVER_SET_COMM_INFORMATION(&HCI_DriverInformation, 1, HAL_HCI_UART_MAX_BAUD_RATE, cpHCILL_RTS_CTS);
	/* Set up the application callbacks.                                 */
	BTPS_Initialization.GetTickCountCallback  = HAL_GetTickCount;
	BTPS_Initialization.MessageOutputCallback = HAL_ConsoleWrite;
	/* Initialize the application.                                       */
	if((Result = InitializeApplication(&HCI_DriverInformation, &BTPS_Initialization)) > 0)
	{
		/* Save the Bluetooth Stack ID.                                   */
		BluetoothStackID = (unsigned int)Result;
		/* Register a sleep mode callback if we are using HCILL Mode.     */
			if((HCI_DriverInformation.DriverInformation.COMMDriverInformation.Protocol == cpHCILL) || (HCI_DriverInformation.DriverInformation.COMMDriverInformation.Protocol == cpHCILL_RTS_CTS))
			{
				HCILLConfig.SleepCallbackFunction        = HCI_Sleep_Callback;
				HCILLConfig.SleepCallbackParameter       = 0;
				DriverReconfigureData.ReconfigureCommand = HCI_COMM_DRIVER_RECONFIGURE_DATA_COMMAND_CHANGE_HCILL_PARAMETERS;
					DriverReconfigureData.ReconfigureData    = (void *)&HCILLConfig;
					/* Register the sleep mode callback.  Note that if this        */
					/* function returns greater than 0 then sleep is currently     */
					/* enabled.                                                    */
				 Result = HCI_Reconfigure_Driver(BluetoothStackID, FALSE, &DriverReconfigureData);
				 if(Result > 0)
				 {
					//Display(("Sleep is allowed.\r\n"));
					/* Flag that it is safe to go into sleep mode.              */
					SleepAllowed = TRUE;
				 }
			  }
			  /* We need to execute Add a function to process the command line  */
			  /* to the BTPS Scheduler.                                         */
			  if(BTPS_AddFunctionToScheduler(ProcessInputTask, NULL, 100))
			  {
				  /* Add the idle task (which determines if LPM3 may be entered) */
				  /* to the scheduler.                                           */
			  }
			  if(BTPS_AddFunctionToScheduler(IdleTask, NULL, 100))
			  {
				  if(BTPS_AddFunctionToScheduler(ToggleLEDTask, NULL, 750))
				  {
					  HAL_SetLEDColor(hlcGreen);

					  /* Execute the scheduler, note that this function does   */
					  /* not return.                                           */
					  BTPS_ExecuteScheduler();
				  }
			  }
	}
	if (SENDER) {

	}
	else if (RECEIVER) {

	}
}
