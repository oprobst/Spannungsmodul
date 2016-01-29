# Spannungsversorgungsmodul

Microcontroller based toggle for supply voltage for other modules.

This circuit controls a toggle for other modules. 
The start time can be configured by a timer. This will be done by a switch after system start.

Once started, it activates a bistable relay (via H-Bridge) toggling input voltage to the target system. Maximum current is 5 ampere (depending on relay).

In addition, it provides a PIN output for a 5V DCDC converted voltage. Maximum current is restricted to 1 ampere (depending on DCDC Converter).

To protect the battery, a low voltage detection for 3s (12.6V to 9.2V) and 2s (8.4V to 6V) LiPo batteries is available.

   * *JP1*: External interface exports 5V via DCDC Converter. Additional pin with source voltage
   * *JP2*: ISP for Programmer
   * *JP3*: Disables the relay. Used to prevent uncontrolled action during programming.
   * *JP4*: Switches low voltage shutdown detection between 2s and 3s LiPo batteries.
   * *X1*: 3x GND connector
   * *X2*: 1x Input voltage, 2x output voltage via relay

![Exported schematic for the module](/Schaltplan.png?raw=true "Schematic")
