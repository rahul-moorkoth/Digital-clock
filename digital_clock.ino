#include <U8g2lib.h>
#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

void setup() {
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_8x13_tf); // Set font to bold

  clock.begin();

  // Uncomment below line to set system date and time
  clock.setDateTime(__DATE__, __TIME__);

  u8g2.setCursor(15, 40);
  u8g2.print("Hello Rahul");

  u8g2.sendBuffer();
  delay(5000);
}

void loop() {
  dt = clock.getDateTime();

  u8g2.firstPage();
  do {
    u8g2.setCursor(15, 15);
    u8g2.print(getMonthName(dt.month));
    u8g2.print(" ");
    u8g2.print(dt.day);
    u8g2.print(", ");
    u8g2.print(dt.year);

    u8g2.setFont(u8g2_font_10x20_tf); // Set a bigger font size for the time
    u8g2.setCursor(22, 40);
    u8g2.print(dt.hour);
    u8g2.print(":");
    if (dt.minute < 10) {
      u8g2.print("0");
    }
    u8g2.print(dt.minute);
    u8g2.print(":");
    if (dt.second < 10) {
      u8g2.print("0");
    }
    u8g2.print(dt.second);

    u8g2.setFont(u8g2_font_8x13_tf); // Reset font size to default
    u8g2.setCursor(15, 60);
    String weekday = getWeekdayName(dt.dayOfWeek);
    weekday.toUpperCase();
    u8g2.print(weekday);
    u8g2.print(" ");
    u8g2.print(clock.readTemperature());
    u8g2.print(" \xB0""C");

  } while (u8g2.nextPage());

  delay(1000);  // Delay for 1 second
}

String getWeekdayName(uint8_t weekday) {
  switch (weekday) {
    case 1:
      return "MON";
    case 2:
      return "TUE";
    case 3:
      return "WED";
    case 4:
      return "THU";
    case 5:
      return "FRI";
    case 6:
      return "SAT";
    case 7:
      return "SUN";
    default:
      return "Unknown";
  }
}

String getMonthName(uint8_t month) {
  switch (month) {
    case 1:
      return "JAN";
    case 2:
      return "FEB";
    case 3:
      return "MAR";
    case 4:
      return "APR";
    case 5:
      return "MAY";
    case 6:
      return "JUN";
    case 7:
      return "JUL";
    case 8:
      return "AUG";
    case 9:
      return "SEP";
    case 10:
      return "OCT";
    case 11:
      return "NOV";
    case 12:
      return "DEC";
    default:
      return "Unknown";
  }
}
