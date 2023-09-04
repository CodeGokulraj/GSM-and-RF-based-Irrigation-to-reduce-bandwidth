# GSM-and-RF-based-Irrigation-to-reduce-bandwidth
Abstract:

Agriculture serves as the primary livelihood for the majority of the Indian population and significantly 
impacts the nation's economy. However, the challenge of irrigation in arid regions or during periods of 
insufficient rainfall necessitates automation for optimal crop yield and remote management to ensure farmer safety.
The emergence of greenhouse-based modern agricultural practices has become imperative across India. This technology 
enables precise control of plant humidity and temperature, yet the variable atmospheric conditions within extensive
farmhouses pose difficulties in maintaining uniformity manually.

To address these challenges, a pioneering approach involves the use of Android
smartphones for irrigation system control, facilitating the maintenance of consistent
environmental conditions. Leveraging the Arduino Software Development Kit this application
capitalizes on the ubiquity of mobile phones in human life. General Packet Radio Service (GPRS)
capabilities in mobile phones are harnessed to create an innovative solution for irrigation control. Additionally, 
Global System for Mobile Communication (GSM) technology is employed to relay real-time field condition information to users
through SMS notifications, ensuring timely and informed decision-making in agriculture.

working:

An Arduino board is connected to a GSM modem, with the transmitter of the Arduino connected to the receiver of the GSM modem, and vice versa. 
The GSM module functions like a mobile phone; when a message is sent to its number, it responds and can be controlled based on the programmed 
code within the microcontroller.Additionally, soil moisture and temperature sensors are connected to the analog pins of the Arduino board.
The board is powered using a 5V supply from a USB cable connected to the Arduino.

The initialization process for the GSM/GPRS module begins, and it waits until it successfully connects to the mobile network.
A 12V power supply is provided to the GSM/GPRS module via an adapter, and a red indicator light signifies that the GSM/GPRS module is powered on and operational.
Data collected by the soil moisture and temperature sensors is transmitted to the microcontroller. Threshold values are pre-programmed into the Arduino board.
The Arduino board then compares the sensor readings with the threshold values. If the temperature sensor readings exceed the threshold value while the 
soil moisture readings fall below the threshold value, the system triggers a SMS alert through the GSM/GPRS module, notifying the user. The user can 
respond by sending an "ON" command via SMS, which activates the motor pump.
