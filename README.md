# IR reading head for SmartMeter
compact reader via WLAN with Wemos-D1-mini pro

In January '21 I wanted to read a SmartMeter, but without interfering with the distribution, so I decided to connect the IR diode and phototransisor directly to the Wemos and put everything in one housing. And it works well for me because I've researched the topic and I'm an electro nerd compared to those around me. But for laypeople it is different.

During my winter vacation in '23 I dealt with the subject again. Goal: I wanted to save an elderly lady from having to walk down the stairs every morning to read the meter. So I decided to continue my old project and tried again with Tasmota and PlatformIO, which drove me crazy in winter vacation '22 because all compilation attempts ended with an error.
Now I have developed the whole thing further, here is the update:
# the IR-haed
![](https://github.com/Elektrofix-OL/IR-reading-head-for-SmartMeter-V2/blob/main/Eagle/sch.gif)

Basically it's very simple. The phototransitor (SFH 229) is connected between RX and GND and gets a pull-up resistor of 1200 ohms to 3.3V. The IR-LED with a wavelength of 880nm is connected directly between 3.3V and TX with a 180 ohm series resistor.
The 10uF capacitor is switched between 3.3V and GND and is only used to support the supply voltage when data is being transmitted.

# Housing images
I changed the case a bit from back then, it's smaller and has the small pushrod on the side to be able to press the reset button. The reset button was modified by me, that is, if it is pressed now, the display switches on and off. I was able to achieve this by making a bridge between the reset button trace and D7 (green line). I then interrupted the reset conductor path at height D5 with a knife (red line). 
![](https://github.com/Elektrofix-OL/IR-reading-head-for-SmartMeter-V2/blob/main/pictures/IMG_0497m.JPG)
Under pictures you can see a few more photos of the assembled circuit board block. The circuit boards were soldered together with a pin conductor provided by the shild.
You can find the files for a 3D printer under https://www.thingiverse.com/thing:5884337
![](https://github.com/Elektrofix-OL/IR-reading-head-for-SmartMeter-V2/blob/main/pictures/Housing.JPG)

# Software

Only the requirements were clear:
- I can configure the reading head so that the user only has to set up his WLAN
- Preconfigure everything in a *.bin to make it easier to install.
- have the opportunity to protect everything in such a way that I don't have to put on the reading head every day
- no VPN, port forwarding, because that is too complex. The reading head should establish a connection to the MQTT server and send the data.
- The data should be readable on the web interface and, if necessary, there should be a forwarding to the Grafana server.

I have put a *.bin file here for you, which you can easily transfer to your ESP8266 with an ESP flash program.
For the pros among you, I also filed my user_config_override for PlatformIO.

# Make hidden button visible
some buttons are invisible. To make all buttons visible again, go to the script editor and now in front of the commands in the area >W a ";", then all buttons are visible again. You can access the script editor by adding the characters "/s10" to the IP address in the browser.

# License
Copyright (c) 2023 Elektrofix

Anyone can use, copy and change the project. However, the sale is prohibited and even after the change, parts of the project may not be sold. You got it for free, so you have to give the changes away for free! Making money with my ideas is not!

The above copyright notice and this permission notice must be included in all copies or substantial portions of the Software.

You do everything at your own risk, I accept no liability or guarantee.
