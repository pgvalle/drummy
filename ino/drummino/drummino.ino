#define N_PADS 1
#define MAX_PADS 16
#define HIT_INTERVAL 20

// pad states
#define HIT     true
#define NOT_HIT false

uint8_t pins[MAX_PADS] = { A0, A1, A2, A3, A4, A5 };
bool states[MAX_PADS] = { NOT_HIT };
uint32_t timesLastHit[MAX_PADS] = { 0 };
  
bool shouldSend = false;
uint16_t valuesToSend[MAX_PADS] = {0};

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (uint8_t i = 0; i < N_PADS; i++) {
    uint16_t pinValue = analogRead(pins[i]);
    uint32_t timeOnHit = millis() - timesLastHit[i];

    if (states[i] == HIT && timeOnHit < HIT_INTERVAL) {
      continue;
    }

    states[i] = NOT_HIT;

    if (pinValue >= 32) {
      states[i] = HIT;
      timesLastHit[i] = millis();
      valuesToSend[i] = pinValue;
      shouldSend = true;
    }
  }

  if (shouldSend) {
    size_t lenBytes = MAX_PADS * sizeof(uint16_t);
    Serial.write((char *)valuesToSend, lenBytes);
    Serial.flush();
    memset(valuesToSend, 0, lenBytes);
    shouldSend = false;
  }
}
