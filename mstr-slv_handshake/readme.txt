Test setup and initial voltage test:

- Place a jumper on J5-J6 pin header at position TP6 on DP Development Board.
- Place a jumper on J5-J6 pin header at position TP12 on DP Development Board.
- Turn both potentiometers into middle position.

- Place scope probe at TP39 at the row of Digital Testpoints.
- Place scope probe at TP45 at the row of Digital Testpoints.
- Place scope probe at TP47 at the row of Digital Testpoints.

- Insert PIM in Socket J1.
- Connect USB cable to a PC.
- Connect micro-USB cable to USB-jack on the DP Development Board.
	o LD1 on DP PIM must be ON with normal green light.
	
When connected to the PC/power source via USB, the green LED LD1 on the DP Development Board and the green LED LD1 on the DP PIM should be turned on statically.

- LD2 (red) on DP PIM: always flashing at 3 Hz.
- LD2 (red) on DP Development Board is on if P2 is in middle position.
- LD3 (green) on DP Development Board is on if P1 is in middle position.

- Square signal output at TP39 with
	o frequency near to 5 kHz,
	o 50% duty ratio,
	o Pulses must reach 0V and 3.3V.
	
- Square signal output at TP45 and TP47 with
	o frequency near to 500 kHz,
	o 50% duty ratio if P1 and P2 are in middle position,
	o Both pulses must reach 0V and 3.3V.	
	
3) MCLR/CPU Reset Test
- Press on-board switch SW2/RESET.
- Expected response:
		o LEDs LD2 and LD3 on DP Development Board and LD2 on DP PIM are turning off,
	o All output signals are turned off.
- Release on-board switch SW2/RESET.
- Expected response:
	o Everything gets back into the power-on conditions like described in “Power-on State”.	
	
4) External Interrupt Test
- Press on-board switch SW1/TP27 on DP Development Board.
- Expected Response:
	o LD2 (red) on DP PIM: speeds up to 10 Hz,
	o All other signal outputs remain unchanged.
- Release on-board switch SW1/TP27 on DP Development Board.
- Expected Response:
	o LD2 (red) on DP PIM: slows back to 3 Hz,
	o All other signal outputs remain unchanged.	
	
5) ADC Input Test from P1
- Turn Potentiometer P1 to the very left and then slowly to very right, observe LED LD3 (green) on the DP Development Board
- Expected response:
	o In middle position LD3 is continuously ON,
	o When turning the potentiometer, LD3 starts blinking with a frequency depending on the potentiometer position.	
	o Duty cycle of the output signal at TP45 changes by the potentiometer from <1% to cca. 95%.

6) ADC Input Test from P2
- Turn Potentiometer P2 to the very left and then slowly to very right, observe LED LD2 (red) on the DP Development Board
- Expected response:
	o In middle position LD2 is continuously ON,
	o When turning the potentiometer, LD2 starts blinking with a frequency depending on the potentiometer position.
	o Duty cycle of the output signal at TP47 changes by the potentiometer from <1% to cca. 95%.
	