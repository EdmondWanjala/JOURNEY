08_JOURNEY

Purpose

JOURNEY is the chronological and developmental of hands on lab work and mini projects done on a weekly basis.

                        GENESIS.
                    WEEK 1.
        Project
    Blinking an LED
LED blinking patterns refer to repetitive or coded sequences of light used for simple visual displays, microcontroller projects, or device status indicators.

    Common Types of Blinking Patterns
• Standard Blink: A continuous uniform on-and-off interval (e.g., 1 second on, 1 second off).
• Sequential / Chaser: Multiple LEDs turn on and off one after another in a directional line.
• Random Flasher: Unpredictable intervals or randomized LED selection controlled by code.
• Status / Error Codes: Coded flashes (such as two short blinks followed by a pause) used by hardware and appliances to signal specific connection or error states.

    Basic Implementation (Arduino)
You can create a basic alternating pattern using a microcontroller like an Arduino Documentation board with standard C++ functions:
• Pin Setup: Configure digital pins as outputs (pinMode(pin, OUTPUT)).
• State Control: Switch power flow using high or low states (digitalWrite(pin, HIGH)).
• Timing: Control pattern speed using milliseconds delay (delay(400)) or non-blocking timers (millis())
