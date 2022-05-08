#include <SoftwareSerial.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>



SoftwareSerial BTserial(10, 11); // RX | TX
Adafruit_MPU6050 mpu;


int flex0 = A0;
int flex1 = A1;
int flex2 = A2;
int flex3 = A3; // flex sensor is connected with analog pin A0
int res0 = 0; 
int res1 = 0; 
int res2 = 0; 
int res3 = 0; 
int flag =1;

void setup()
{
  Serial.begin(9600); 
  pinMode(flex0, INPUT);
  pinMode(flex1, INPUT);
  pinMode(flex2, INPUT);
  pinMode(flex3, INPUT);
  BTserial.begin(9600);
  

  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu.setMotionDetectionThreshold(1);
  mpu.setMotionDetectionDuration(20);
  mpu.setInterruptPinLatch(true);  
  mpu.setInterruptPinPolarity(true);
  mpu.setMotionInterrupt(true);
 
}

void loop()
{
  

  
  
  res0 = analogRead(flex0);
  Serial.print("flex0="); 
  Serial.println(res0);
  
  
  res1 = analogRead(flex1);
  Serial.print("flex1=");  
  Serial.println(res1); 

    res2 = analogRead(flex2);
    Serial.print("flex2=");  
  Serial.println(res2); 

  res3 = analogRead(flex3);
  Serial.print("flex3=");  
  Serial.println(res3); 

 
 if((res0<=50)&&(res1<50)&&(res2<50)&&(res3<50)&&(flag==1)){
   BTserial.println("Welcome Advitya 2022");
  delay(1500); 
  flag=0;
   }
   
 else if((res0<40)&&(res1<40)&&(res2<40)&&(res3>30)){
   BTserial.println("");
  delay(1500);
  flag=1; 
  }

else if((res0<20)&&(res1<40)&&(res2>40)&&(res3<40)){
   BTserial.println("You are beautiful");
  delay(1500); 
  }

  
    else if((res0<40)&&(res1<40)&&(res2>30)&&(res3>30)){
   BTserial.println("Call police");
  delay(1500); 
  flag=1; 
  }
   else if((res0<40)&&(res1>40)&&(res2<30)&&(res3<30)){
   BTserial.println("God Bless you");
  delay(1500); 
  flag=1; 
  }

  else if((res0<30)&&(res1>30)&&(res2>30)&&(res3<50)){
   BTserial.println("This is a gesture vocalizer.");
  delay(1500); 
  flag=1; 
   }
  
  else if((res0<50)&&(res1>30)&&(res2>30)&&(res3>30)){
   BTserial.println("I have a doubt");
  delay(1500); 
  flag=1; 
  }

 
  else if((res0>30)&&(res1<50)&&(res2<50)&&(res3<50)){
   BTserial.println("Have a nice day!");
  delay(1500); 
  flag=1; 
   }

   else if((res0>30)&&(res1<50)&&(res2<50)&&(res3>50)){
   BTserial.println("I am hungry!");
  delay(1500); 
  flag=1; 
   }

   else if((res0>30)&&(res1>50)&&(res2<50)&&(res3<50)){
   BTserial.println("Good Afternoon, Madam");
  delay(1500); 
  flag=1; 
   }

    else if((res0>50)&&(res1>50)&&(res2>50)&&(res3<50)){
   BTserial.println("I need to pee");
  delay(1500); 
  flag=1; 
  }
 

   else if((res0<40)&&(res1<40)&&(res2>50)&&(res3>50)){
   BTserial.println("Very Good");
  delay(1500); 
   }

else if((res0>40)&&(res1>40)&&(res2>50)&&(res3>50)){
   BTserial.println("Help me!");
  delay(1500); 
   }
 
  delay(300); 

  if(mpu.getMotionInterruptStatus()) {
    /* Get new sensor events with the readings */
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    /* Print out the values */
    Serial.print("AccelX:");
    Serial.print(a.acceleration.x);
    Serial.print(",");
    Serial.print("AccelY:");
    Serial.print(a.acceleration.y);
    Serial.print(",");
    Serial.print("AccelZ:");
    Serial.print(a.acceleration.z);
    Serial.print(", ");
    Serial.print("GyroX:");
    Serial.print(g.gyro.x);
    Serial.print(",");
    Serial.print("GyroY:");
    Serial.print(g.gyro.y);
    Serial.print(",");
    Serial.print("GyroZ:");
    Serial.print(g.gyro.z);
    Serial.println("");
  }

  delay(10);
}
