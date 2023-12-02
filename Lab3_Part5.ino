
//Author: Sofia Gratny
//Purpose: PART 1 Lab 3 GPIO
//Class: CPE 301

// Define Port K Register Pointers
volatile unsigned char* port_k = (unsigned char*) 0x108; 
volatile unsigned char* ddr_k  = (unsigned char*) 0x107; 
volatile unsigned char* pin_k  = (unsigned char*) 0x106; 

// Define Port D Register Pointers
volatile unsigned char* port_d = (unsigned char*) 0x2B; 
volatile unsigned char* ddr_d  = (unsigned char*) 0x2A; 
volatile unsigned char* pin_d  = (unsigned char*) 0x29;

// Define Port E Register Pointers
volatile unsigned char* port_e = (unsigned char*) 0x2E; 
volatile unsigned char* ddr_e  = (unsigned char*) 0x2D; 
volatile unsigned char* pin_e  = (unsigned char*) 0x2C;

int button;

void setup() 
{
  //set PK2 to input
  *ddr_k &= 0b11111011;
  //set PD0 to output
  *ddr_d |= 0b00000001; //blue led Pin PD0
  //PE3 to complement
  *ddr_e |= 0b00001000; //red LED Pin PE3
  
}

void loop() 
{
  button = digitalRead(A10);

  if (button==1){
    digitalWrite(21, HIGH);
    digitalWrite(5, LOW); //complement
    delay(500);
  }
  else{
      digitalWrite(21, LOW);
      digitalWrite(5, HIGH); //complement 
      delay(500);
   }
}
