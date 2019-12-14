# ECEN2440_CNCPen (Joy Pen)
CNC Joystick Pen for ECEN2440 Final

Efram Aredo, Nathan Elsen, Max Pettit

See the hackster.io post for more details [here](https://www.hackster.io/maxpettit/joy-pen-74b8a4).
Brief Explanation of files below

## adc 
* Initializes analog to digital conversion: sets ADC14 sample-and-hold times, starts ADC sample conversions, turns on ADC14
* Captures values and outputs them

## gpio 
* Initializes pins on MSP inorder to configure motor driver boards
* Initializes things like step size, enable, stepper mode

## led_test
* Used in testing ADC and joystick.
* On board LED will change color depending on position of joystick

## main 
* Calls config and init functions
* Endless loop which reads joystick values and moves motors accordingly

## motor
* Starts and stops motor pwm based on joystick position
* Determines direction of motors based on joystick position

## pwm 
* Configures timers to create pulse width modulations
* PWM outputs used to move motors and servo
* Can be paused

## read_js
* Configures xout and yout pins on the joystick to MSP pins for ADC reading
* Takes in ADC reading and output the joystick position

## uart_driver
* Configures and initializes eUSCI for UART communication to LCD
* Writes desired messages to LCD

## up_start
* Calls config functions and starts timers
* Displays start up message

## z_driver
* Configures pin to trigger interrupt on falling edge which corresponds to a joystick click
* Enables necessary interrupt
* On interrupt, toggles the pen position (up/down)
* Sets pen position by changing duty cycle of pwm wave to servo
