#include <Wire.h>

byte pin = 0;
int selectedPin = 0;
#define R 5
#define C 5

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void sendToSlave(int pinSelected) {
  Serial.print("Selcted Pin is: ");
  Serial.println(pinSelected);
  if (pinSelected <= 13 ) {
    pin = (byte)pinSelected;
    Wire.beginTransmission(1);
    Wire.write(pin);
    Wire.endTransmission();
  } else {
    pinSelected = pinSelected % 13;
    pin = (byte)pinSelected;
    Wire.beginTransmission(2);
    Wire.write(pin);
    Wire.endTransmission();
  }
  delay(5000);
}

void spiralPrint(int m, int n, int a[R][C])
{
  int i, k = 0, l = 0;
  while (k < m && l < n) {
    for (i = l; i < n; ++i) {
      selectedPin = a[k][i];
      sendToSlave(selectedPin);
    }
    k++;
    for (i = k; i < m; ++i) {
      selectedPin = a[i][n - 1];
      sendToSlave(selectedPin);
    }
    n--;
    if (k < m) {
      for (i = n - 1; i >= l; --i) {
        selectedPin = a[m - 1][i];
        sendToSlave(selectedPin);
      }
      m--;
    }
    if (l < n) {
      for (i = m - 1; i >= k; --i) {
        selectedPin = a[i][l];
        sendToSlave(selectedPin);
      }
      l++;
    }
  }
}


void loop() {
  int a[R][C] = {
    { 1, 2, 3, 4, 5 },
    { 6, 7, 8, 9, 10 },
    { 11, 12, 13, 14, 15 },
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
  };

  // Function Call
  spiralPrint(R, C, a);
}
