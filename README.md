# Hardware Keylogger (AK2 Project)
Man in the middle device to capture input from a keyboard and save it to a file that later can be retrieved while maintaining output from the keyboard to victim's device.
## Steps to reproduce
### Hardware needed:
* Arduino Leonardo compatible board,
* Raspberry Pi (tested on Zero),
* some cables,
* some means of connecting a keyboard to the RPi (e.g. USB A female port or micro to female A cable),
* SD card.
### Steps:
1. Download the Arduino code and `$ pio run -t upload` with PlatformIO installed,
2. Setup RPi with Raspbian, establish connection to your Wi-Fi, enable SSH,
3. SSH into the Pi and `$ mkdir /home/pi/ak2_projekt && mkdir /home/pi/ak2_projekt/logs`,
4. While in the Pi `$ pip install getch pyserial`
5. Copy main.py from this repo's RPi directory into `/home/pi/ak2_projekt`,
6. Append `python /home/pi/ak2_projekt/main.py` to `/etc/profile`,
7. Connect devices according to instructions below

| RPi      	  | Arduino 	|
| ----------- | ----------- |
|5V		  	  |VCC			|
|GPIO14/TXD	  |RX			|
|GPIO15/RXD   |TX 			|
|GND          |GND  		|

`Keyboard <-(USB)-> RPi`
`RPi <-(TABLE)-> Arduino`
`Arduino <-(USB)-> Computer` 

8. Make sure nothing is flashing to Arduino, plug it off the computer and put it back in.
9. Everything should be working, the logs are in the folder you created earlier, Have fun!
## Notes
To leave the program, try CTRL + ? or CTRL + -. Have in mind that the only way to resume it is to restart the devices and the output from the keyboard will be halted. CTRL + S is bugged and when pressed halts any output to victim's PC until CTRL + Z is pressed. There are probably many bugs and unhandled cases which you are welcome to tinker with.
