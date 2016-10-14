#include "ch.h"
#include "hal.h"

int main(void) {

    /* Allow debug access during WFI sleep */
    DBGMCU->CR |= DBGMCU_CR_DBG_SLEEP;

    /* Turn on the watchdog timer, stopped in debug halt */
    DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_IWDG_STOP;
    IWDG->KR = 0x5555;
    IWDG->PR = 3;
    IWDG->KR = 0xCCCC;

    /* Initialise ChibiOS */
    halInit();
    chSysInit();


    while (true) {
        /* Clear the watchdog timer */
        IWDG->KR = 0xAAAA;

        palSetPad(GPIOA,GPIOA_LED_RED);

        chThdSleepMilliseconds(1000);

        palClearPad(GPIOA,GPIOA_LED_RED);

        chThdSleepMilliseconds(1000);
    }
}
