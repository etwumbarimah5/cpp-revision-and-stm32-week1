#define TEMP_PIN A0
#define BUTTON_PIN A1
#define BUZZER_PIN A2

#define LED1_PIN D2
#define LED2_PIN D3
#define LED3_PIN D4

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  Serial.println("STM32 Temperature Monitoring System");
}

void loop() {
  int sensorValue = analogRead(TEMP_PIN);

  float temperature = 25.0 + (523 - sensorValue) * 0.1;

  bool buttonPressed = (digitalRead(BUTTON_PIN) == LOW);

  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature <= 30) {
    digitalWrite(LED1_PIN, HIGH);
    Serial.println("Status: SAFE");
  }
  else if (temperature <= 60) {
    digitalWrite(LED2_PIN, HIGH);
    Serial.println("Status: NORMAL");
  }
  else if (temperature <= 80) {
    digitalWrite(LED3_PIN, HIGH);
    Serial.println("Status: WARNING");
  }
  else {
    digitalWrite(LED3_PIN, HIGH);

    if (!buttonPressed) {
      digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("Status: CRITICAL - BUZZER ON");
    }
    else {
      Serial.println("Status: CRITICAL - BUZZER SILENCED");
    }
  }

  delay(1000);
}