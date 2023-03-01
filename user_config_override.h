#define EEP_SCRIPT_SIZE 8192                    // for more space für scripting
#define USE_EEPROM                              // for more space für scripting
#define USE_24C256                              // for more space für scripting
#define USE_SCRIPT                              // required for SML
#define USE_SML_M                               // required for SML
#define USE_DISPLAY                             // required for Display Support
#define USE_DISPLAY_SSD1306                     // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
#undef USE_DISPLAY_MODES1TO5                    // disable display mode 1 to 5
#define USER_TEMPLATE "{\"NAME\":\"Lesekopf\",\"GPIO\":[1,0,1,0,640,608,0,0,1,32,1,1,1,1],\"FLAG\":0,\"BASE\":18}"  // [Template] for IR-Head
#undef FALLBACK_MODULE                          // to disabel "Sonof-Basic" after reset
#define FALLBACK_MODULE USER_MODULE             // to enabel "Leskopf" after first boot
#undef  WIFI_HOSTNAME                           // Change the WIFi-Hostname
#define WIFI_HOSTNAME     "Lesekopf-ROT"        // Change the WIFi-Hostname
#undef PROJECT                                  // Change the Projektname
#define PROJECT                "Lesekopf"       // Change the Projektname, PROJECT is used as the default topic delimiter
#undef FRIENDLY_NAME                            // Change the Friendlyname
#define FRIENDLY_NAME          "Lesekopf"       // Change the Friendlyname
#define USE_SCRIPT_WEB_DISPLAY                  // to Change GUI by Script
#define SCRIPT_FULL_WEBPAGE                     // to Change GUI by Script 

#define START_SCRIPT_FROM_BOOT                  // turn Script on, wenn ESP ist booting
#define USER_BACKLOG "script 1;wificonfig 2;displaywidth 64;displayheight 48;module 0;webbutton1 Display am Lesekopf ein/aus" // Commands for starting after boot
#define PRECONFIGURED_SCRIPT ">D\nssid=\"\"\nrssi=0\nZeile1=0\nZeile2=0\nt:timer1=600  (t:means countdown timer)\n\n>W\n<style>#but5 button{display:none}</style>\n<style>#but3 button{display:none}</style>\n<style>#but6 button{display:none}</style>\n@<form><a href=\"https://github.com/Elektrofix-OL/IR-Lesekopf-fuer-SmartMeter\" target=\"_blank\"><button>hier geht es zur Anleitung</button></a><form>\n\n>B\n=>sensor53 r\ndt [zdO]\n\n; stop timer after expired\nif timer1==0\nthen timer1=-1\nendif\n\n>T\n; Wifi- / Batterieanzeige und Zeile 1&2\nssid=Wifi#SSID\nrssi=Wifi#RSSI\nZeile1=Strom#Power_curr\nZeile2=Strom#Total_in\ndt [x10y2f3]%ssid%\ndt [x0y12f3]%lip%\nif rssi>0\nthen dt [x0y8R1:1]\nendif\nif rssi>20\nthen dt [x2y6R1:3]\nendif\nif rssi>40\nthen dt [x4y4R1:5]\nendif\nif rssi>60\nthen dt [x6y2R1:7]\nendif\nif rssi>80\nthen dt [x8y0R1:9]\nendif\n\n; Text ín Zeile 3-5\ndt [x0y20f3]%topic%\ndt [x0y30f0]%Zeile1% kWh\ndt [x0y41f0]%Zeile2% W\n\n; Display ausschalten\nif timer1<2\nand timer1>1\nthen dt [zdo]\nendif\nif timer1<1\nand pwr[1]>0\nthen timer1=60\nendif\n\n>M 1\n+1,3,s,0,9600,Strom\n1,77070100010800ff@1000,Gesamtverbrauch,KWh,Total_in,1\n1,77070100020800ff@1000,Gesamteinspeisung,KWh,Total_out,1\n1,77070100100700ff@1,Verbrauch,W,Power_curr,0\n1,77070100200700ff@1,Voltage L1,V,Volt_p1,1\n1,77070100340700ff@1,Voltage L2,V,Volt_p2,1\n1,77070100480700ff@1,Voltage L3,V,Volt_p3,1\n1,770701001f0700ff@1,Amperage L1,A,Amperage_p1,1\n1,77070100330700ff@1,Amperage L2,A,Amperage_p2,1\n1,77070100470700ff@1,Amperage L3,A,Amperage_p3,1\n1,77070100240700ff@1,Current consumption L1,W,Power_curr_p1,0\n1,77070100380700ff@1,Current consumption L2,W,Power_curr_p2,0\n1,770701004c0700ff@1,Current consumption L3,W,Power_curr_p3,0\n1,770701000e0700ff@1,Frequency,Hz,frequency,0\n1,77070100600100ff@#,Server ID,,meter_number,0\n#"
