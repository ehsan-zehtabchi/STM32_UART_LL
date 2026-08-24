#include "stm32f4xx.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_bus.h"

void usart2_int(void);
void usart2_w(char ch);
char usart2_r(void);

int main(void)
{
    char rc;

    usart2_int();

    while (1)
    {
    	rc = usart2_r();

    if (rc >= 'A' && rc <= 'Z')
    {
    rc = rc + ('a' - 'A');
    }
    else if (rc >= 'a' && rc <= 'z')
    {
    rc = rc - ('a' - 'A');
    }

    usart2_w(rc);
    }
}


/* =========================================================
 * USART2 INITIALIZATION
 * ========================================================= */

void usart2_int(void)
{
    /* Enable GPIOA clock */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

    /* Enable USART2 clock */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2);


    /* PA2 = USART2_TX */
    LL_GPIO_SetPinMode(
        GPIOA,
        LL_GPIO_PIN_2,
        LL_GPIO_MODE_ALTERNATE
    );

    /* PA3 = USART2_RX */
    LL_GPIO_SetPinMode(
        GPIOA,
        LL_GPIO_PIN_3,
        LL_GPIO_MODE_ALTERNATE
    );


    /* USART2 = Alternate Function 7 */

    LL_GPIO_SetAFPin_0_7(
        GPIOA,
        LL_GPIO_PIN_2,
        LL_GPIO_AF_7
    );

    LL_GPIO_SetAFPin_0_7(
        GPIOA,
        LL_GPIO_PIN_3,
        LL_GPIO_AF_7
    );


    /* GPIO speed */

    LL_GPIO_SetPinSpeed(
        GPIOA,
        LL_GPIO_PIN_2 | LL_GPIO_PIN_3,
        LL_GPIO_SPEED_FREQ_VERY_HIGH
    );


    /* TX output type */

    LL_GPIO_SetPinOutputType(
        GPIOA,
        LL_GPIO_PIN_2,
        LL_GPIO_OUTPUT_PUSHPULL
    );


    /* Pull-up */

    LL_GPIO_SetPinPull(
        GPIOA,
        LL_GPIO_PIN_2 | LL_GPIO_PIN_3,
        LL_GPIO_PULL_UP
    );


    /* Disable USART2 before configuration */

    LL_USART_Disable(USART2);


    /* TX + RX */

    LL_USART_SetTransferDirection(
        USART2,
        LL_USART_DIRECTION_TX_RX
    );


    /* 8-bit, no parity, 1 stop bit */

    LL_USART_ConfigCharacter(
        USART2,
        LL_USART_DATAWIDTH_8B,
        LL_USART_PARITY_NONE,
        LL_USART_STOPBITS_1
    );


    /* Baud rate = 115200 */

    LL_USART_SetBaudRate(
        USART2,
        16000000,
        LL_USART_OVERSAMPLING_16,
        115200
    );


    /* Asynchronous mode */

    LL_USART_ConfigAsyncMode(USART2);


    /* Enable USART2 */

    LL_USART_Enable(USART2);
}


/* =========================================================
 * USART2 TRANSMIT
 * ========================================================= */

void usart2_w(char ch)
{
    while (!LL_USART_IsActiveFlag_TXE(USART2))
    {
    }

    LL_USART_TransmitData8(USART2, ch);
}


/* =========================================================
 * USART2 RECEIVE
 * ========================================================= */

char usart2_r(void)
{
    while (!LL_USART_IsActiveFlag_RXNE(USART2))
    {
    }

    return LL_USART_ReceiveData8(USART2);
}
