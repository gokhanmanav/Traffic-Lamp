// Pin defination
#define OUT_RED_LIGHT 2
#define OUT_YELLOW_LIGHT  3
#define OUT_GREEN_LIGHT 4

#define IN_BTN_USER 8

// Time table ms
const unsigned long red_light_time = 10000L;
const unsigned long red_yellow_light_time = 2000L;
const unsigned long green_light_time = 10000L;
const unsigned long yellow_light_time = 2000L;

unsigned long sample_time=0L;
unsigned long current_waitting_time;

enum{
  LIGHT_RED,
  LIGHT_RED_YELLOW,
  LIGHT_GREEN,
  LIGHT_YELLOW
} state_of_light;

void setup() {
  digitalWrite(OUT_RED_LIGHT,HIGH);
  digitalWrite(OUT_YELLOW_LIGHT,LOW);
  digitalWrite(OUT_GREEN_LIGHT,LOW);

  pinMode(OUT_RED_LIGHT,OUTPUT);
  pinMode(OUT_YELLOW_LIGHT,OUTPUT);
  pinMode(OUT_GREEN_LIGHT,OUTPUT);

  sample_time = millis();
  
  state_of_light=LIGHT_RED;
  current_waitting_time=red_light_time;
}

void loop() {
  if(millis() - sample_time >= current_waitting_time){
    sample_time = millis();
    next_state();
  }
  
  switch(state_of_light){
    LIGHT_RED:
      digitalWrite(OUT_RED_LIGHT,HIGH);
      digitalWrite(OUT_YELLOW_LIGHT,LOW);
      digitalWrite(OUT_GREEN_LIGHT,LOW);
      break;
    LIGHT_RED_YELLOW:
      digitalWrite(OUT_RED_LIGHT,HIGH);
      digitalWrite(OUT_YELLOW_LIGHT,HIGH);
      digitalWrite(OUT_GREEN_LIGHT,LOW);
      break;
    LIGHT_GREEN:
      digitalWrite(OUT_RED_LIGHT,LOW);
      digitalWrite(OUT_YELLOW_LIGHT,LOW);
      digitalWrite(OUT_GREEN_LIGHT,HIGH);
      break;
    LIGHT_YELLOW:
      digitalWrite(OUT_RED_LIGHT,LOW);
      digitalWrite(OUT_YELLOW_LIGHT,HIGH);
      digitalWrite(OUT_GREEN_LIGHT,LOW);
      break;
  }
}

int get_state(){
  return state_of_light;
}

void next_state(){
  switch(state_of_light){
    LIGHT_RED:
      state_of_light = LIGHT_RED_YELLOW;
      current_waitting_time=red_yellow_light_time;
      break;
    LIGHT_RED_YELLOW:
      state_of_light = LIGHT_GREEN;
      current_waitting_time=green_light_time;
      break;
    LIGHT_GREEN:
      state_of_light = LIGHT_YELLOW;
      current_waitting_time=yellow_light_time;
      break;
    LIGHT_YELLOW:
      state_of_light = LIGHT_RED;
      current_waitting_time=red_light_time;
      break;
  }
}
