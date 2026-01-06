#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>
#include <Adafruit_HMC5883_U.h>
#include <TinyGPS++.h>

// ================= DISPLAY =================
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ================= SENSORES =================
Adafruit_BME280 bme;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
TinyGPSPlus gps;

// ================= GPS =================
HardwareSerial GPSSerial(1);

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  GPSSerial.begin(9600, SERIAL_8N1, 16, 17); // RX, TX (ajuste se necessário)

  Wire.begin();

  // Display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Display OLED não encontrado");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // BME280
  if (!bme.begin(0x76)) {
    Serial.println("BME280 não encontrado");
  }

  // Bússola
  if (!mag.begin()) {
    Serial.println("HMC5883L não encontrado");
  }

  display.setCursor(0, 0);
  display.println("Shack Monitor");
  display.println("----------------");
  display.println("Init OK");
  display.display();
}

// ================= LOOP =================
void loop() {
  while (GPSSerial.available()) {
    gps.encode(GPSSerial.read());
  }

  display.clearDisplay();
  display.setCursor(0, 0);

  display.println("Status Geral:");

  display.print("Temp: ");
  display.print(bme.readTemperature());
  display.println(" C");

  display.print("Hum: ");
  display.print(bme.readHumidity());
  display.println(" %");

  if (gps.time.isValid()) {
    display.print("Hora GPS: ");
    display.print(gps.time.hour());
    display.print(":");
    display.println(gps.time.minute());
  } else {
    display.println("GPS: aguardando");
  }

  display.display();
  delay(1000);
}
