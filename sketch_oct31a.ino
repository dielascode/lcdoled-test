#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Lebar layar (piksel)
#define SCREEN_HEIGHT 64 // Tinggi layar (piksel) - ubah ke 32 kalau layarnya setengah lebih tipis

// Inisialisasi layar OLED tanpa pin RESET (-1)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  // Pin I2C khusus ESP32-C3 Super Mini (SDA = GPIO 8, SCL = GPIO 9)
  Wire.begin(8, 9);

  // Inisialisasi OLED dengan alamat 0x3C hasil scanner
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED gagal diinisialisasi!"));
    for(;;); 
  }

  // Bersihkan layar dari logo bawaan Adafruit
  display.clearDisplay();

  // --- Baris Pertama ---
  display.setTextSize(1);              // Ukuran teks kecil
  display.setTextColor(SSD1306_WHITE); // Warna teks putih
  display.setCursor(0, 10);            // Posisi (X=0, Y=10)
  display.println("Hello, World!");

  // --- Baris Kedua ---
  display.setTextSize(2);              // Ukuran teks sedang/besar
  display.setCursor(0, 30);            // Posisi (X=0, Y=30)
  display.println("ESP32-C3");

  // Kirim data ke layar OLED untuk ditampilkan
  display.display();
}

void loop() {
  // Tidak ada proses berulang
}