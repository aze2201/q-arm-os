volatile unsigned int * const FAKE_UART = (unsigned int *)0x101f1000;
 
void print_console(const char *f) {
	
	// Loop until end of string
	while(*f != '\0') { 
	
		// Transmit string character 
		*FAKE_UART = (unsigned int)(*f);
		
		// Next string character
		f++; 
	}
}
 
void _init() {
 print_console("Hello baby ARM by Fariz!\n");
}
