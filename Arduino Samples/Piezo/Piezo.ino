// P01.12V-2021.11 by InstaNFC
// Sample Code
// Feature: Piezo 

#define AUDIO_BUS (25)

void setup() {
  // put your setup code here, to run once:
  setupAudio();
}

void loop() {
  // put your main code here, to run repeatedly:
  playAudio();
  delay(5000);
  playAudioError();
  delay(2000);
}

void setupAudio() {
  ledcSetup(0, 2500, 8);
  ledcAttachPin(AUDIO_BUS, 0); 
}

void loopAudio() {
}

void playAudio() {    
  int initialValue = 4000;
  int steps = 30;
  int finalValue = initialValue + steps;
  
  for (int i = initialValue; i < finalValue; i += 1) {
    ledcWriteTone(0, i);
    delay(1);
  }
  ledcWrite(0, 0);
}

void playAudioError() {
  int initialValue = 3000;
  int steps = -100;
  int finalValue = initialValue + steps;
  
  for (int i = initialValue; i > finalValue; i -= 1) {
    ledcWriteTone(0, i);
    delay(1);
  }
  ledcWrite(0, 0);
}
