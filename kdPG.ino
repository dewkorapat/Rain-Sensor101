int analogPin = A0; 
int val = 0;
int x = 0;
#include <TridentTD_LineNotify.h>

#define SSID        "test638"      // ให้ใส่ ชื่อ Wifi ที่จะเชื่อมต่อ
#define PASSWORD    "8888888890"   // ใส่ รหัส Wifi
#define LINE_TOKEN  "NXBbbecTjSKE2nvi418p6PTb0FuGqsrCMWEXcXpZWCt"   // บรรทัดที่ 13 ใส่ รหัส TOKEN ที่ได้มาจากข้างบน
String message = "ฝนตกแล้วจ้า";     // เปลี่ยนเป็นข้อความที่เราต้องการ
String message2 = "ฝนหยุดแล้วจ้า"; 

void setup() {
  Serial.begin(9600);
  Serial.println(LINE.getVersion());

  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);
}

void loop() {
  val = analogRead(analogPin);    // อ่านค่าสัญญาณ analog
  Serial.print("val = ");         // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println(val);            // พิมพ์ค่าของตัวแปร val

  if (val < 500 && x == 0) {      // ถ้าค่าน้อยกว่า 500 และ x เป็น 0
    LINE.notify(message);         // ส่งข้อความทางไลน์
    delay(1000);
  }

  if (val > 500 && x == 1) {      // ถ้าค่ามากกว่า 500 และ x เป็น 1
    LINE.notify(message2);        // ส่งข้อความทางไลน์
    delay(1000);
  }

  if (val < 500) {                // ถ้าค่าน้อยกว่า 500
    x = 1;
  }
  else {
    x = 0;
  }
  
  delay(1000);
}
