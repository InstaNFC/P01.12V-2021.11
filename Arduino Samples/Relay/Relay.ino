// P01.12V-2021.11 by InstaNFC
// Sample Code
// Feature: Relay 
//
// External relay connections (works with USB power)
// Negative -> LS PIN / GND PIN
// Positive -> 5V PIN
// Signal -> IO26 / IO33
//
// Electric strike (12-24V) connections
// Stike Wire 1 -> LS PIN
// Strike Wire 2 -> HS PIN
// 12V Power Supply
// Negative -> Negative (-)
// Positive -> Positive (+)

#define HS (16)
#define LS (17)

#define IO33 (33)
#define IO26 (26)

#define HS_LOCK (0x10)
#define HS_UNLOCK (0x00)

#define LS_LOCK (0x00)
#define LS_UNLOCK (0x10)

#define TOGGLE_IO33 (1)
#define TOGGLE_IO26 (1)

void setup() {
  // put your setup code here, to run once:
  setupLock();
}

void loop() {
  // put your main code here, to run repeatedly:
  unlock(2);
  delay(4000);
}

void setupLock() {
  pinMode(HS, OUTPUT);
  pinMode(LS, OUTPUT);
  
  if (TOGGLE_IO33) pinMode(IO33, OUTPUT);
  if (TOGGLE_IO26) pinMode(IO26, OUTPUT);
  
  digitalWrite(HS, HS_LOCK);
  digitalWrite(LS, LS_LOCK);
}

void loopLock() {
  
}

void unlock(float duration) {  
  // enhancement: disable NFC whilst unlocking
  // use taskmanager for locking instead of delay to remain async
  digitalWrite(HS, HS_UNLOCK);
  digitalWrite(LS, LS_UNLOCK);
  if (TOGGLE_IO33)  digitalWrite(IO33, HIGH);
  if (TOGGLE_IO26)  digitalWrite(IO26, HIGH);
  delay(duration * 1000);
  lock();
}

void lock() {  
  digitalWrite(HS, HS_LOCK);   
  digitalWrite(LS, LS_LOCK);
  if (TOGGLE_IO33)  digitalWrite(IO33, LOW);
  if (TOGGLE_IO26)  digitalWrite(IO26, LOW);
}
