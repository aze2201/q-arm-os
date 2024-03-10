#include <stdint.h>

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
    // Add your interrupt handling code here
    print_console("Fake UART Interrupt occurred!\n");
}

// Handler for  additional interrupt
void additional_interrupt_handler(void) {
    // Add your additional interrupt handling code
    print_console("Additional Interrupt occurred!\n");
}

// Define interrupt vector table
// vectors are placed at index 1 and 2 (assuming interrupt numbers 1 and 2)
void (*const interrupt_vector_table[])(void) __attribute__((section(".isr_vector"))) = {
    _init,                              // Reset vector
    fake_uart_interrupt_handler,        // Fake UART interrupt vector
    additional_interrupt_handler       // Additional interrupt vector
};

void _init(void) {
    // Set up the NVIC to enable the fake UART and additional interrupts
    // This step is platform-specific and might involve configuring interrupt controller
    // For demonstration purposes, assume NVIC enables the interrupts at positions 1 and 2
    // Note: This step depends on your specific microcontroller and toolchain

    // Enable  interrupt for fake UART (assuming interrupt number 1)
    // NVIC->ISER[0] |= (1 << 1);

    // Enable the interrupt for the additional interrupt (assuming interrupt number 2)
    // NVIC->ISER[0] |= (1 << 2);

    // Enable interrupts globally (if not already done)
    // __enable_irq();

    // Now you can print a message to trigger  interrupts
    print_console("Hello baby ARM by Fariz!\n");

    // Uncomment the next line to trigger  fake UART interrupt
    // *FAKE_UART = (unsigned int)('I');

    // Uncomment the next line to trigger  additional interrupt
    // additional_interrupt_handler();  
}

int main(void) {
    // This is a simplified main function
    _init();

    // Do other initialization or application-specific tasks 

    while (1) {
        // Main application loop
        // Handle other tasks as needed
    }
}
