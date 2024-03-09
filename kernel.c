#include <stdint.h>

volatile unsigned int * const FAKE_UART = (unsigned int *)0x101f1000;

void print_console(const char *f) {
    while (*f != '\0') {
        *FAKE_UART = (unsigned int)(*f);
        f++;
    }
}

void _init(void);

// Handler for the interrupt
void fake_uart_interrupt_handler(void) {
    // Add your interrupt handling code here
    // For simplicity, let's print a message
    print_console("Interrupt occurred!\n");
}

// Define the interrupt vector table
// The vector for the fake UART interrupt is placed at index 1 (assuming interrupt number 1)
void (*const interrupt_vector_table[])(void) __attribute__((section(".isr_vector"))) = {
    _init,                                  // Reset vector
    fake_uart_interrupt_handler            // Fake UART interrupt vector
};

void _init(void) {
    // Set up the NVIC to enable the fake UART interrupt
    // This step is platform-specific and might involve configuring the interrupt controller
    // For demonstration purposes, let's assume NVIC enables the interrupt at position 1
    // Note: This step depends on your specific microcontroller and toolchain

    // Enable the interrupt for fake UART (assuming interrupt number 1)
    // NVIC->ISER[0] |= (1 << 1);

    // Enable interrupts globally (if not already done)
    // __enable_irq();

    // Now you can print a message to trigger the interrupt
    print_console("Hello baby ARM by Fariz!\n");

    // Uncomment the next line to trigger the interrupt
    // *FAKE_UART = (unsigned int)('I');  // This will trigger the interrupt handler
}

int main(void) {
    // This is a simplified main function
    // In a real application, you might have a more complex setup
    _init();

    // Do other initialization or application-specific tasks here

    while (1) {
        // Main application loop
        // Handle other tasks as needed
    }
}
