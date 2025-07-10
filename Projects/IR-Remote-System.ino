#include <IRremote.h>
#define IR_RECEIVE_PIN 23
//-----------------------------------------------------------
#define RELAY_1 25
#define RELAY_2 26
#define RELAY_3 32
#define RELAY_4 33

#define BUTTON_PIN_1 5
#define BUTTON_PIN_2 18
#define BUTTON_PIN_3 19
#define BUTTON_PIN_4 20

boolean state_relay1 = LOW;
boolean state_relay2 = LOW;
boolean state_relay3 = LOW;
boolean state_relay4 = LOW;

boolean state_BUTTON1 = HIGH;
boolean state_BUTTON2 = HIGH;
boolean state_BUTTON3 = HIGH;
boolean state_BUTTON4 = HIGH;

boolean state_BLUETOOTH1 = LOW;
boolean state_BLUETOOTH2 = LOW;
boolean state_BLUETOOTH3 = LOW;
boolean state_BLUETOOTH4 = LOW;


void setup() {
  //-----------------------------------------------------------
  Serial.begin(115200);
  Serial.println("Welcome to our System");
  delay(1000);
  //-----------------------------------------------------------
  IrReceiver.begin(IR_RECEIVE_PIN); // Start the IR receiver
  //-----------------------------------------------------------
  // initialize Relays
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);

  //During Starting all Relays should TURN OFF
  digitalWrite(RELAY_1, LOW);
  digitalWrite(RELAY_2, LOW);
  digitalWrite(RELAY_3, LOW);
  digitalWrite(RELAY_4, LOW);
  //-----------------------------------------------------------
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  //-----------------------------------------------------------
}

void loop() {
  remote_control();
  switches();
  Bluetooth();
  
}

void Bluetooth()
{
  if(Serial.available())
  {
    char bluetoothButton=Serial.read();
    if(bluetoothButton=='a')
    {
      state_BLUETOOTH1=!state_BLUETOOTH1;
      digitalWrite(RELAY_1, state_BLUETOOTH1);
    }
    if(bluetoothButton=='s')
    {
      state_BLUETOOTH2=!state_BLUETOOTH2;
      digitalWrite(RELAY_2, state_BLUETOOTH2);
    }
    if(bluetoothButton=='d')
    {
      state_BLUETOOTH3=!state_BLUETOOTH3;
      digitalWrite(RELAY_3, state_BLUETOOTH3);
    }
    if(bluetoothButton=='f')
    {
      state_BLUETOOTH4=!state_BLUETOOTH4;
      digitalWrite(RELAY_4, state_BLUETOOTH4);
    }
  }
}

void switches()
{
  boolean current_state_BUTTON1 = digitalRead(BUTTON_PIN_1);
  boolean current_state_BUTTON2 = digitalRead(BUTTON_PIN_2);
  boolean current_state_BUTTON3 = digitalRead(BUTTON_PIN_3);
  boolean current_state_BUTTON4 = digitalRead(BUTTON_PIN_4);
  if(current_state_BUTTON1!=state_BUTTON1)
  {
    digitalWrite(RELAY_1, !current_state_BUTTON1);
    state_BUTTON1=current_state_BUTTON1;
  }
  if(current_state_BUTTON2!=state_BUTTON2)
  {
    digitalWrite(RELAY_2, !current_state_BUTTON2);
    state_BUTTON2=current_state_BUTTON2;
  }
  if(current_state_BUTTON3!=state_BUTTON3)
  {
    digitalWrite(RELAY_3, !current_state_BUTTON3);
    state_BUTTON3=current_state_BUTTON3;
  }
  if(current_state_BUTTON4!=state_BUTTON4)
  {
    digitalWrite(RELAY_4, !current_state_BUTTON4);
    state_BUTTON4=current_state_BUTTON4;
  }
}

void remote_control()
{
  static uint32_t last_ir_code_time = 0;
  
  if(IrReceiver.decode()) 
  {
    uint32_t ir_code = IrReceiver.decodedIRData.command;
    //----------------------------------------------------------------------
    if(ir_code == 0) {IrReceiver.resume(); return; }
    // ignore duplicate IR codes received within 1000 ms
    if (millis() - last_ir_code_time < 1000) { IrReceiver.resume(); return;}
    last_ir_code_time = millis();

    //----------------------------------------------------------------------
    //IR KEY 1
    if(ir_code == 48){ 
        state_relay1 = !state_relay1;
        digitalWrite(RELAY_1, state_relay1);
    }
    //IR KEY 2
    else if(ir_code == 24){
      state_relay2 = !state_relay2;
      digitalWrite(RELAY_2, state_relay2);
    }
    //IR KEY 3
    else if(ir_code == 122){
      state_relay3 = !state_relay3;
      digitalWrite(RELAY_3, state_relay3);
    }
    //IR KEY 4
    else if(ir_code == 16){
      state_relay4 = !state_relay4;
      digitalWrite(RELAY_4, state_relay4);
    }
    //IR KEY 5
    else if(ir_code == 56){
      allON();
    }
    //IR KEY 6
    else if(ir_code == 90){
      allOFF();
    }
    IrReceiver.resume();
  }
}

void allON(){
  state_relay1 = HIGH; digitalWrite(RELAY_1, state_relay1);
  state_relay2 = HIGH; digitalWrite(RELAY_2, state_relay2);
  state_relay3 = HIGH; digitalWrite(RELAY_3, state_relay3);
  state_relay4 = HIGH; digitalWrite(RELAY_4, state_relay4);
}
void allOFF(){
  state_relay1 = LOW; digitalWrite(RELAY_1, state_relay1);
  state_relay2 = LOW; digitalWrite(RELAY_2, state_relay2);
  state_relay3 = LOW; digitalWrite(RELAY_3, state_relay3);
  state_relay4 = LOW; digitalWrite(RELAY_4, state_relay4);
}