#include <Adafruit_NeoPixel.h>  //调用LED彩灯的库文件
Adafruit_NeoPixel ColorLED = Adafruit_NeoPixel(1, 6, NEO_GRB + NEO_KHZ800);
//定义彩灯引脚以及数量
int ligth_state; //定义一个整数变量ligth_state
int sound_state; //定义一个整数变量sound_state
int start_time,end_time;
void setup()
{
  ColorLED.begin();
  pinMode(A0, INPUT); //设置光敏传感器引脚为输入状态
  pinMode(A2, INPUT); //设置MIC传感器引脚为输入状态
  Serial.begin(9600); //设置串口波特率为9600
}
void loop()
{
  ligth_state = analogRead(A0);
  Serial.print("ligth_state:");
  Serial.println(ligth_state);
  delay(100);
  if (ligth_state >50) { //当ligth_state的值小于50时，继续下一个条件
    sound_state = analogRead(A2);
    Serial.print("sound_state:");
    Serial.println(sound_state);
    if (sound_state < 200) { //当sound_state的值大于200时，亮灯
      ColorLED.setPixelColor(0, ColorLED.Color(255, 255, 255));  //设置彩灯颜色为红色
      ColorLED.show();  //显示彩灯效果
      start_time = millis();
    }
    else{
      end_time = millis();
      if(end_time-start_time > 5000) {
        ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0));  //设置彩灯颜色为黑色
        ColorLED.show();  //显示彩灯效果
      }
    }
  } else { //否则，关灯
    ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0));  //设置彩灯颜色为黑色
    ColorLED.show();  //显示彩灯效果
  }
}
