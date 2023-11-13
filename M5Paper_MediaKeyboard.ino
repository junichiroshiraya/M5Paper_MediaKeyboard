#include <M5EPD.h>
#include <BleKeyboard.h>

M5EPD_Canvas canvas(&M5.EPD);
BleKeyboard bleKeyboard;

int point[2][2];

int btnSize = 150;
int btnPitch = 160;
int xOffset = 30;
int yOffset = 10;
int PrtOffsetx = 14;
int PrtOffsety = -7;
int btn0 = yOffset + 0 * btnPitch;
int btn1 = yOffset + 1 * btnPitch;
int btn2 = yOffset + 2 * btnPitch;
int btn3 = yOffset + 3 * btnPitch;
int btn4 = yOffset + 4 * btnPitch;
int btn5 = yOffset + 5 * btnPitch;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  adc_power_acquire();
  bleKeyboard.begin();
  M5.EPD.SetRotation(270);
  M5.TP.SetRotation(270);
  M5.EPD.Clear(true);
  canvas.createCanvas(540, 960);
  canvas.setTextSize(2);

  for (int i = 0; i < 3; i++) {
    canvas.drawRoundRect(xOffset + i * btnPitch, btn0, btnSize, btnSize, 10, WHITE); //
  }
  canvas.drawString("Back", xOffset + 0 * btnPitch + PrtOffsetx, btn0 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Forward", xOffset + 1 * btnPitch + PrtOffsetx, btn0 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Refresh", xOffset + 2 * btnPitch + PrtOffsetx, btn0 + 0.5 * btnSize + PrtOffsety);
  //canvas.drawString("Browser", xOffset + 2 * btnPitch + PrtOffsetx, btn0 + 0.5 * btnSize + PrtOffsety * 1.8);
  //canvas.drawString("", xOffset + 2 * btnPitch + PrtOffsetx, btn0 + 0.5 * btnSize + PrtOffsety * (-.6));

  for (int i = 0; i < 3; i++) {
    canvas.drawRoundRect(xOffset + i * btnPitch, btn1, btnSize, btnSize, 10, WHITE); //
  }
  canvas.drawString("Browser Stop", xOffset + 0 * btnPitch + PrtOffsetx, btn1 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Search", xOffset + 1 * btnPitch + PrtOffsetx, btn1 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Favorite", xOffset + 2 * btnPitch + PrtOffsetx, btn1 + 0.5 * btnSize + PrtOffsety);

  for (int i = 0; i < 3; i++) {
    canvas.drawRoundRect(xOffset + i * btnPitch, btn2, btnSize, btnSize, 10, WHITE); //
  }
  canvas.drawString("Home", xOffset + 0 * btnPitch + PrtOffsetx, btn2 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Molume Mute", xOffset + 1 * btnPitch + PrtOffsetx, btn2 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Volume Up", xOffset + 2 * btnPitch + PrtOffsetx, btn2 + 0.5 * btnSize + PrtOffsety);

  for (int i = 0; i < 3; i++) {
    canvas.drawRoundRect(xOffset + i * btnPitch, btn3, btnSize, btnSize, 10, WHITE); //
  }
  canvas.drawString("Volume Down", xOffset + 0 * btnPitch + PrtOffsetx, btn3 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Next Track", xOffset + 1 * btnPitch + PrtOffsetx, btn3 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Prev Track", xOffset + 2 * btnPitch + PrtOffsetx, btn3 + 0.5 * btnSize + PrtOffsety);

  for (int i = 0; i < 3; i++) {
    canvas.drawRoundRect(xOffset + i * btnPitch, btn4, btnSize, btnSize, 10, WHITE); //
  }
  canvas.drawString("Stop", xOffset + 0 * btnPitch + PrtOffsetx, btn4 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Play/Pause", xOffset + 1 * btnPitch + PrtOffsetx, btn4 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Mail", xOffset + 2 * btnPitch + PrtOffsetx, btn4 + 0.5 * btnSize + PrtOffsety);

  for (int i = 0; i < 3; i++) {
    canvas.drawRoundRect(xOffset + i * btnPitch, btn5, btnSize, btnSize, 10, WHITE); //
  }
  canvas.drawString("Media Select", xOffset + 0 * btnPitch + PrtOffsetx, btn5 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Launcher", xOffset + 1 * btnPitch + PrtOffsetx, btn5 + 0.5 * btnSize + PrtOffsety);
  canvas.drawString("Calculator", xOffset + 2 * btnPitch + PrtOffsetx, btn5 + 0.5 * btnSize + PrtOffsety);

  canvas.pushCanvas(0, 0, UPDATE_MODE_DU4);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (M5.TP.avaliable()) {
    if (!M5.TP.isFingerUp()) {
      M5.TP.update();
      for (int i = 0; i < 2; i++) {
        tp_finger_t FingerItem = M5.TP.readFinger(i);
        if ((point[i][0] != FingerItem.x) || (point[i][1] != FingerItem.y)) {
          point[i][0] = FingerItem.x;
          point[i][1] = FingerItem.y;
          Serial.printf("Finger ID:%d-->X: %d*C  Y: %d  Size: %d\r\n", FingerItem.id, FingerItem.x, FingerItem.y , FingerItem.size);

          if ((point[i][0] >= xOffset + 0 * btnPitch && point[i][0] <= xOffset + 0 * btnPitch + btnSize) && ( point[i][1] >= btn0 && point[i][1] <= btn0 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_WWW_BACK");
            bleKeyboard.write(KEY_F1);
          }
          if ((point[i][0] >= xOffset + 1 * btnPitch && point[i][0] <= xOffset + 1 * btnPitch + btnSize) && ( point[i][1] >= btn0 && point[i][1] <= btn0 + btnSize)) {
            //Serial.println("Sending KEY_MEDIA_WWW_FORWARD");
            //bleKeyboard.write(KEY_MEDIA_WWW_FORWARD);
          }
          if ((point[i][0] >= xOffset + 2 * btnPitch && point[i][0] <= xOffset + 2 * btnPitch + btnSize) && ( point[i][1] >= btn0 && point[i][1] <= btn0 + btnSize)) {
            //Serial.println("Sending KEY_MEDIA_WWW_REFRESH");
            //bleKeyboard.write(KEY_MEDIA_WWW_REFRESH);
          }
          
          if ((point[i][0] >= xOffset + 0 * btnPitch && point[i][0] <= xOffset + 0 * btnPitch + btnSize) && ( point[i][1] >= btn1 && point[i][1] <= btn1 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_WWW_STOP");
            bleKeyboard.write(KEY_MEDIA_WWW_STOP);
          }
          if ((point[i][0] >= xOffset + 1 * btnPitch && point[i][0] <= xOffset + 1 * btnPitch + btnSize) && ( point[i][1] >= btn1 && point[i][1] <= btn1 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_WWW_SEARCH");
            bleKeyboard.write(KEY_MEDIA_WWW_SEARCH);
          }
          if ((point[i][0] >= xOffset + 2 * btnPitch && point[i][0] <= xOffset + 2 * btnPitch + btnSize) && ( point[i][1] >= btn1 && point[i][1] <= btn1 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_WWW_BOOKMARKS");
            bleKeyboard.write(KEY_MEDIA_WWW_BOOKMARKS);
          }
          
          if ((point[i][0] >= xOffset + 0 * btnPitch && point[i][0] <= xOffset + 0 * btnPitch + btnSize) && ( point[i][1] >= btn2 && point[i][1] <= btn2 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_WWW_HOME");
            bleKeyboard.write(KEY_MEDIA_WWW_HOME);
          }
          if ((point[i][0] >= xOffset + 1 * btnPitch && point[i][0] <= xOffset + 1 * btnPitch + btnSize) && ( point[i][1] >= btn2 && point[i][1] <= btn2 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_MUTE");
            bleKeyboard.write(KEY_MEDIA_MUTE);
          }
          if ((point[i][0] >= xOffset + 2 * btnPitch && point[i][0] <= xOffset + 2 * btnPitch + btnSize) && ( point[i][1] >= btn2 && point[i][1] <= btn2 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_VOLUME_UP");
            bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
          }

          if ((point[i][0] >= xOffset + 0 * btnPitch && point[i][0] <= xOffset + 0 * btnPitch + btnSize) && ( point[i][1] >= btn3 && point[i][1] <= btn3 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_VOLUME_DOWN");
            bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
          }
          if ((point[i][0] >= xOffset + 1 * btnPitch && point[i][0] <= xOffset + 1 * btnPitch + btnSize) && ( point[i][1] >= btn3 && point[i][1] <= btn3 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_NEXT_TRACK");
            bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
          }
          if ((point[i][0] >= xOffset + 2 * btnPitch && point[i][0] <= xOffset + 2 * btnPitch + btnSize) && ( point[i][1] >= btn3 && point[i][1] <= btn3 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_PREVIOUS_TRACK");
            bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
          }

          if ((point[i][0] >= xOffset + 0 * btnPitch && point[i][0] <= xOffset + 0 * btnPitch + btnSize) && ( point[i][1] >= btn4 && point[i][1] <= btn4 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_STOP");
            bleKeyboard.write(KEY_MEDIA_STOP);
          }
          if ((point[i][0] >= xOffset + 1 * btnPitch && point[i][0] <= xOffset + 1 * btnPitch + btnSize) && ( point[i][1] >= btn4 && point[i][1] <= btn4 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_PLAY_PAUSE");
            bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
          }
          if ((point[i][0] >= xOffset + 2 * btnPitch && point[i][0] <= xOffset + 2 * btnPitch + btnSize) && ( point[i][1] >= btn4 && point[i][1] <= btn4 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_EMAIL_READER");
            bleKeyboard.write(KEY_MEDIA_EMAIL_READER);
          }

          if ((point[i][0] >= xOffset + 0 * btnPitch && point[i][0] <= xOffset + 0 * btnPitch + btnSize) && ( point[i][1] >= btn5 && point[i][1] <= btn5 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION");
            bleKeyboard.write(KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION);
          }
          if ((point[i][0] >= xOffset + 1 * btnPitch && point[i][0] <= xOffset + 1 * btnPitch + btnSize) && ( point[i][1] >= btn5 && point[i][1] <= btn5 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_LOCAL_MACHINE_BROWSER");
            bleKeyboard.write(KEY_MEDIA_LOCAL_MACHINE_BROWSER);
          }
          if ((point[i][0] >= xOffset + 2 * btnPitch && point[i][0] <= xOffset + 2 * btnPitch + btnSize) && ( point[i][1] >= btn5 && point[i][1] <= btn5 + btnSize)) {
            Serial.println("Sending KEY_MEDIA_CALCULATOR");
            bleKeyboard.write(KEY_MEDIA_CALCULATOR);
          }
        }
      }
    }
  }
}
