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

                    WEEK 2
        Project
    Reading a button(digital inputs)
To read a push button (digital input) with a microcontroller like an Arduino, you connect the button to a digital pin and use a pull-up or pull-down resistor to keep the pin from "floating" (picking up random electrical noise).

    Key Concepts
• Floating State: If an input pin is not connected to a steady voltage or ground, it acts like an antenna and reads erratic, random HIGH or LOW values.
• Pull-Down Resistor: Keeps the pin at 0V (LOW) normally; pressing the button connects the pin to 5V (HIGH).
• Pull-Up Resistor: Keeps the pin at 5V (HIGH) normally; pressing the button connects the pin to 0V (GND / LOW). Many boards feature an internal pull-up resistor that you can enable in software using INPUT_PULLUP.
• digitalRead(): The function used to read the state of the digital pin, returning either HIGH (1) or LOW (0).

    Wiring (Pull-Down Configuration)
1. Connect one side of the push button to 5.0V (or 3.3V) on your board.
2. Connect the opposite side of the button to a digital pin (for example, Pin 2).
3. Connect a 10kΩ resistor from Digital Pin 2 to GND (Ground) to act as the pull-down.

    Core Benefits
• User Interaction: It provides a basic human-machine interface (HMI), allowing users to trigger actions, change modes, or reset a system manually.
• State Control: It allows the microcontroller to safely toggle between different states (e.g., ON vs. OFF) based on external real-world physical actions.
• Signal Stability: By correctly implementation of pull-up/pull-down resistors, the project demonstrates how to eliminate electrical noise ("floating pins") to achieve predictable, stable digital signals.
• Foundational Architecture: It introduces the core structure of embedded software loops—continuously polling (checking) an input pin and making immediate decisions based on its logical state (HIGH or LOW).
