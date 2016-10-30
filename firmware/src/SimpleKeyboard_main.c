//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8UB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
#include "EFM8UB1_FlashUtils.h"
// $[Generated Includes]
#include "efm8_usb.h"
// [Generated Includes]$

#define UUID_LENGTH (16)
#define SER_STRING_INDEX (3)
const uint8_t code UUID[UUID_LENGTH] _at_ 0xFFC0;
extern xdata USB_StringDescriptor_TypeDef serDesc[];


SI_SBIT(LED0, SFR_P0, 7);
SI_SBIT(SW0, SFR_P0, 3);
SI_SBIT(DISP_EN, SFR_P2, 3);


int main(void) {
	uint8_t i;
	char hexval[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	// Call hardware initialization routine
	enter_DefaultMode_from_RESET();

	// Toggle HW State
	LED0 = 0;
	DISP_EN = 0;

	// Copy Serial Number
	for(i = 0; i < UUID_LENGTH; i++) {
		serDesc[SER_STRING_INDEX + i*2] = hexval[UUID[i] >> 4];
		serDesc[SER_STRING_INDEX + (i*2) + 1] = hexval[UUID[i] & 0x0F];
	}


	while (1) {
// $[Generated Run-time code]
// [Generated Run-time code]$
	}
}
