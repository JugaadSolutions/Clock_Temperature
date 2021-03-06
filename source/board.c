
/*
*------------------------------------------------------------------------------
* device.c
*
* Board specipic drivers module(BSP)
*
*
* The copyright notice above does not evidence any
* actual or intended publication of such source code.
*
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/


#include "board.h"
#include "config.h"
#include "typedefs.h"




/*
*------------------------------------------------------------------------------
* Private Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Macros
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Variables (static)
*------------------------------------------------------------------------------
*/

static BOOL ledState;

/*
*------------------------------------------------------------------------------
* Public Constants
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Constants (static)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Function Prototypes (static)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Functions
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* void InitializeBoard(void)

* Summary	: This function configures all i/o pin directions
*
* Input		: None
*
* Output	: None
*
*------------------------------------------------------------------------------
*/
void BRD_init(void)
{
	
	// set all anolog channels as Digital I/O
	ADCON0 = 0x00;
	ADCON1 = 0x0F;
	ADCON2 = 0xB5;

//	MEMCON = 0x80;

	// Internal oscillator setup
	OSCCON |= 0X70; 		//internal oscillator 8MHz
	OSCTUNEbits.PLLEN = 1;	//PLL Enable
	

	TX_EN_DIR = PORT_OUT;
	SER_TX_DIR = PORT_OUT;
	SER_RX_DIR = 1;
	

	DISPLAY_PORT_DIRECTION = 0x00;	// Segment Data port
	DIGIT_SEL_A_DIRECTION = PORT_OUT;		// Digit Selection
	
	DIGIT_SEL_B_DIRECTION = PORT_OUT;
	
	DIGIT_SEL_C_DIRECTION = PORT_OUT;
	
	DIGIT_SEL_D_DIRECTION = PORT_OUT;

	DIGIT_SEL_E_DIRECTION = PORT_OUT;		
	
	DIGIT_SEL_F_DIRECTION = PORT_OUT;
	
	DIGIT_SEL_G_DIRECTION = PORT_OUT;
	

	


	// Control switches	
	CHANGE_ON_INTR_DIRECTION = PORT_IN;

	I2C_SCL_DIR = PORT_OUT;
	I2C_SDA_DIR = PORT_OUT;

	HEART_BEAT_DIRECTION = PORT_OUT;
	CLOCK_LED_DIRECTION = PORT_OUT;

}



/*
*------------------------------------------------------------------------------
* Private Functions
*------------------------------------------------------------------------------
*/

/*
*  End of device.c
*/
