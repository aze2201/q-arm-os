#include <stdint.h>
// from documentation 
volatile unsigned int * const FAKE_UART = (unsigned int *)0x101f1000;

void print_console(const char *f) {
    while (*f != '\0') {
        *FAKE_UART = (unsigned int)(*f);
        f++;
    }
}



void _init(void);

// Handler for the fake UART interrupt
void fake_uart_interrupt_handler(void) {
    // Add your interrupts handling here
    print_console("Fake UART Interrupt occurred!\n");
}

// Handler for  additional interrupt
void additional_interrupt_handler(void) {
    // Add your additional interrupt handling code
    print_console("Additional Interrupt occurred!\n");
}

// Define interrupt vector table
// vectors is placed at index 1 and 2nd
void (*const interrupt_vector_table[])(void) __attribute__((section(".isr_vector"))) = {
    _init,                              // Reset vector
    fake_uart_interrupt_handler,        // Fake UART interrupt vector
    additional_interrupt_handler       // another interrupt vector
};


void _init(void) {
    // enable_irq()

    // Now you can print message for trigger  interrupts
    print_console("Hello baby ARM by Fariz!\n");
}

int main(void) {
    // This is a simplified main function
    _init();

// some init task here ?

    while (1) {
        // Main app loop here
        // dumy tasks can be
    }
}
