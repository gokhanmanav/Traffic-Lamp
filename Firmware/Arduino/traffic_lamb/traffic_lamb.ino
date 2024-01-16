/*
  * Board Arduino Nano
*/
// Pin defination
#define OUT_RED_LIGHT 2
#define OUT_YELLOW_LIGHT  3
#define OUT_GREEN_LIGHT 4

#define OUT_RED_FOR_PEOPLE  5
#define OUT_GREEN_FOR_PEOPLE 6

// Time table ms
const unsigned long time_light_red_people_red = 2000L;
const unsigned long time_light_red_yellow_people_red = 5000L;
const unsigned long time_light_green_people_red = 20000L;
const unsigned long time_light_yellow_people_red = 2000L;
const unsigned long time_light_red_people_red_2 = 5000L;
const unsigned long time_light_red_people_green = 10000L;

unsigned long current_waitting_time;

#define LIGHT_RED_PEOPLE_RED 0
#define LIGHT_RED_YELLOW_PEOPLE_RED 1
#define LIGHT_GREEN_PEOPLE_RED 2
#define LIGHT_YELLOW_PEOPLE_RED 3
#define LIGHT_RED_PEOPLE_RED_2 4
#define LIGHT_RED_PEOPLE_GREEN 5
int state_of_light;

void setup() {
  Serial.begin(9600);
  Serial.println("Trafik Lambası Uygulamas");

  digitalWrite(OUT_RED_LIGHT,HIGH);
  digitalWrite(OUT_YELLOW_LIGHT,LOW);
  digitalWrite(OUT_GREEN_LIGHT,LOW);

  digitalWrite(OUT_RED_FOR_PEOPLE,HIGH);
  digitalWrite(OUT_GREEN_FOR_PEOPLE,LOW);

  pinMode(OUT_RED_LIGHT,OUTPUT);
  pinMode(OUT_YELLOW_LIGHT,OUTPUT);
  pinMode(OUT_GREEN_LIGHT,OUTPUT);

  pinMode(OUT_RED_FOR_PEOPLE,OUTPUT);
  pinMode(OUT_GREEN_FOR_PEOPLE,OUTPUT);
  
  state_of_light=LIGHT_RED_PEOPLE_RED;
  current_waitting_time=time_light_red_people_red;
}

void loop() {
  switch(state_of_light){
    case LIGHT_RED_PEOPLE_RED:
      Serial.println("LIGHT_RED_PEOPLE_RED");
      digitalWrite(OUT_RED_LIGHT,HIGH);
      digitalWrite(OUT_YELLOW_LIGHT,LOW);
      digitalWrite(OUT_GREEN_LIGHT,LOW);

      digitalWrite(OUT_RED_FOR_PEOPLE,HIGH);
      digitalWrite(OUT_GREEN_FOR_PEOPLE,LOW);
      break;
    case LIGHT_RED_YELLOW_PEOPLE_RED:
      Serial.println("LIGHT_RED_YELLOW_PEOPLE_RED");
      digitalWrite(OUT_RED_LIGHT,HIGH);
      digitalWrite(OUT_YELLOW_LIGHT,HIGH);
      digitalWrite(OUT_GREEN_LIGHT,LOW);
      
      digitalWrite(OUT_RED_FOR_PEOPLE,HIGH);
      digitalWrite(OUT_GREEN_FOR_PEOPLE,LOW);
      break;
    case LIGHT_GREEN_PEOPLE_RED:
      Serial.println("LIGHT_GREEN_PEOPLE_RED");
      digitalWrite(OUT_RED_LIGHT,LOW);
      digitalWrite(OUT_YELLOW_LIGHT,LOW);
      digitalWrite(OUT_GREEN_LIGHT,HIGH);
      
      digitalWrite(OUT_RED_FOR_PEOPLE,HIGH);
      digitalWrite(OUT_GREEN_FOR_PEOPLE,LOW);
      break;
    case LIGHT_YELLOW_PEOPLE_RED:
      Serial.println("LIGHT_YELLOW_PEOPLE_RED");
      digitalWrite(OUT_RED_LIGHT,LOW);
      digitalWrite(OUT_YELLOW_LIGHT,HIGH);
      digitalWrite(OUT_GREEN_LIGHT,LOW);
      
      digitalWrite(OUT_RED_FOR_PEOPLE,HIGH);
      digitalWrite(OUT_GREEN_FOR_PEOPLE,LOW);
      break;
    case LIGHT_RED_PEOPLE_RED_2:
      Serial.println("LIGHT_RED_PEOPLE_RED_2");
      digitalWrite(OUT_RED_LIGHT,HIGH);
      digitalWrite(OUT_YELLOW_LIGHT,LOW);
      digitalWrite(OUT_GREEN_LIGHT,LOW);
      
      digitalWrite(OUT_RED_FOR_PEOPLE,HIGH);
      digitalWrite(OUT_GREEN_FOR_PEOPLE,LOW);
      break;
    case LIGHT_RED_PEOPLE_GREEN:
      Serial.println("LIGHT_RED_PEOPLE_GREEN");
      digitalWrite(OUT_RED_LIGHT,HIGH);
      digitalWrite(OUT_YELLOW_LIGHT,LOW);
      digitalWrite(OUT_GREEN_LIGHT,LOW);
      
      digitalWrite(OUT_RED_FOR_PEOPLE,LOW);
      digitalWrite(OUT_GREEN_FOR_PEOPLE,HIGH);
      break;
  }
  next_state();
  delay(current_waitting_time);
}

void next_state(){
  switch(state_of_light){
    case LIGHT_RED_PEOPLE_RED:
      state_of_light = LIGHT_RED_YELLOW_PEOPLE_RED;
      current_waitting_time = time_light_red_people_red;
      break;
    case LIGHT_RED_YELLOW_PEOPLE_RED:
      state_of_light = LIGHT_GREEN_PEOPLE_RED;
      current_waitting_time = time_light_red_yellow_people_red;
      break;
    case LIGHT_GREEN_PEOPLE_RED:
      state_of_light = LIGHT_YELLOW_PEOPLE_RED;
      current_waitting_time = time_light_green_people_red;
      break;
    case LIGHT_YELLOW_PEOPLE_RED:
      state_of_light = LIGHT_RED_PEOPLE_RED_2;
      current_waitting_time = time_light_yellow_people_red;
      break;
    case LIGHT_RED_PEOPLE_RED_2:
      state_of_light = LIGHT_RED_PEOPLE_GREEN;
      current_waitting_time = time_light_red_people_red_2;
      break;
    case LIGHT_RED_PEOPLE_GREEN:
      state_of_light = LIGHT_RED_PEOPLE_RED;
      current_waitting_time = time_light_red_people_green;
      break;
  }
}
