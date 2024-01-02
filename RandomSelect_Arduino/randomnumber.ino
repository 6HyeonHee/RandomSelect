#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
    Serial.begin(115200); // 시리얼 통신 초기화
    SerialBT.begin("sixhyeon"); // Bluetooth 이름 설정
    randomSeed(analogRead(0)); // 랜덤 시드 설정
}

void loop() {
    if (SerialBT.available()) {
        int number = SerialBT.parseInt(); // 안드로이드 앱으로부터 수신된 숫자를 읽어옴
        if (number > 0) {
            int randomNumber = generateRandomNumber(number);
            SerialBT.println(randomNumber); // 랜덤한 숫자를 안드로이드 앱으로 전송
        }
    }
}

int generateRandomNumber(int maxNumber) {
    return random(1, maxNumber + 1); // 1부터 maxNumber까지의 랜덤한 숫자 생성
}
