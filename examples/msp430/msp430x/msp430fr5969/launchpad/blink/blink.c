#include "tpl_os.h"
#include "msp430.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	P4DIR |= 1<<6; //P4.6 as output (red led)
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	P4OUT ^= 1<<6; //toggle led.
	TerminateTask();
}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"
