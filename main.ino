#include <M5Stack.h>
#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {

  // 初期化
  dacWrite(25, 0); // スピーカーのノイズ対策
  M5.begin();
  dht.begin();

  // 画面初期化
  M5.Lcd.setTextSize(7);
}


void loop() {

  delay(3000);

  // 値の取得
  float temperature = dht.readTemperature(); // 温度を取得
  float humidity = dht.readHumidity(); // 湿度を取得

  // 画面描画
  //M5.Lcd.clear();
  M5.Lcd.setCursor(0,0);

  M5.Lcd.printf("Temp:\n %2.0f C\n",temperature);
  M5.Lcd.printf("Humid:\n %2.0f",humidity);
  M5.Lcd.println(" %");

  //M5.Lcd.drawString("o",100,0,1);
}