#include "spi.h"

void init_master_SPI(t_spi_mode mode, t_spi_data_order data_order,
    t_spi_prescaler prescaler)
{
    // Set PB2, PB3 and PB5 as outputs
    init_output_GPIO(D10);
    init_output_GPIO(D11);
    init_output_GPIO(D13);
    // DDRB |= _BV(DDB2) | _BV(DDB3) | _BV(DDB5);
    // Enables SPI and sets as master
    SPCR |= _BV(SPE) | _BV(MSTR);
    // Configures SPI mode
    if (mode == SPI_MODE_2 || mode == SPI_MODE_3) {
        SPCR |= _BV(CPOL);
    }
    if (mode == SPI_MODE_1 || mode == SPI_MODE_3) {
        SPCR |= _BV(CPHA);
    }
    // Configures data order
    SPCR |= _BV(DORD) & (data_order << DORD);
    // Sets up prescaler
    if (prescaler == SPI_PRESCALER_2 || prescaler == SPI_PRESCALER_8 || prescaler == SPI_PRESCALER_32) {
        SPSR |= _BV(SPI2X);
    }
    if (prescaler == SPI_PRESCALER_8 || prescaler == SPI_PRESCALER_16 || prescaler == SPI_PRESCALER_128) {
        SPCR |= _BV(SPR0);
    }
    if (prescaler == SPI_PRESCALER_32 || prescaler == SPI_PRESCALER_64 || prescaler == SPI_PRESCALER_128) {
        SPCR |= _BV(SPR1);
    }
    write_output_GPIO(D10, HIGH);
}

void transfer_n_SPI(uint8_t send_bytes[], uint8_t receive_bytes[], uint8_t n)
{
    // Sets SS low to start transmission
    write_output_GPIO(D10, LOW);
    for (uint8_t i = 0; i < n; i++) {
        // For each byte, transmit them and wait for transmit to finish
        SPDR = send_bytes[i];
        loop_until_bit_is_set(SPSR, SPIF);
        if (receive_bytes) {
            // Read the received byte and store it
            receive_bytes[i] = SPDR;
        }
    }
    // Sets SS high to end transmission
    write_output_GPIO(D10, HIGH);
}