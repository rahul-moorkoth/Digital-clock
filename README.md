# Arduino-DS3231-OLED
Arduino nano, DS3231 and SH1106 OLED

Note: There is one line to set system date and time. So you should upload code twice on arduino nano.
Once after uncommenting and then after commenting the below line.

`clock.setDateTime(__DATE__, __TIME__);`
