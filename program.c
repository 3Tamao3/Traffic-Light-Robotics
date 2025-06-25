
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << PB5) | (1 << PB4) | (1 << PB3);
    DDRD |= (1 <<PD7);

    PORTB &= ~((1 << PB5) | (1 << PB4) | (1 << PB3));

    while (1)
    {
        PORTB |= (1 << PB5);

        if (PIND & (1 << PD7))
        {
        _delay_ms(3000);
        PORTB &= ~(1 << PB5);

        PORTB |= (1 << PB4);
        _delay_ms(1000);
        PORTB &= ~(1 << PB4);

        PORTB |= (1 << PB3);
        _delay_ms(5000);
        PORTB &= ~(1 << PB3);

        PORTB |= (1 << PB4);
        _delay_ms(1000);
        PORTB &= ~(1 << PB4);
        }
    }

    return 0;
}
