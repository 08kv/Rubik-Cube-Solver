//stringlflow
char string[50];
int availableBytes = 0;
int flag , act;
//Functions
//void act ( char [] );


//Pins


/* enable */

const int enable8 = 12;
const int enable9 = 7;
const int enable10 = 22;
const int enable11 = 44;
const int enable12 = A12;
const int enable13 = A4;


/*Motor 1 */

const int m1ms2 = 10;
const int m1ms1 = 11;
const int m1dir = 8;
const int m1stp = 9;



/*Motor 2 */

const int m2ms2 = 5;
const int m2ms1 = 6;
const int m2dir = 3;
const int m2stp = 4;


/*Motor 3 */

const int m3ms2 = 26;
const int m3ms1 = 24;
const int m3dir = 30;
const int m3stp = 28;


/*Motor 4 */
const int m4ms2 = 48;
const int m4ms1 = 46;
const int m4dir = 52;
const int m4stp = 50;

/*Motor 5 */

const int m5ms2 = A10;
const int m5ms1 = A11;
const int m5dir = A8;
const int m5stp = A9;

/*Motor 6 */

const int m6ms2 = A2;
const int m6ms1 = A3;
const int m6dir = A0;
const int m6stp = A1;

//Safety Button

const int button = 23;
int check = 0;

void setup()
{

  Serial.begin(9600);

  pinMode(enable8, OUTPUT);
  pinMode(enable9, OUTPUT);
  pinMode(enable10, OUTPUT);
  pinMode(enable11, OUTPUT);
  pinMode(enable12, OUTPUT);
  pinMode(enable13, OUTPUT);

  pinMode(m1ms2, OUTPUT);
  pinMode(m1ms1, OUTPUT);
  pinMode(m1dir, OUTPUT);
  pinMode(m1stp, OUTPUT);

  pinMode(m2ms2, OUTPUT);
  pinMode(m2ms1, OUTPUT);
  pinMode(m2dir, OUTPUT);
  pinMode(m2stp, OUTPUT);

  pinMode(m3ms2, OUTPUT);
  pinMode(m3ms1, OUTPUT);
  pinMode(m3dir, OUTPUT);
  pinMode(m3stp, OUTPUT);

  pinMode(m4ms2, OUTPUT);
  pinMode(m4ms1, OUTPUT);
  pinMode(m4dir, OUTPUT);
  pinMode(m4stp, OUTPUT);


  pinMode(m5ms2, OUTPUT);
  pinMode(m5ms1, OUTPUT);
  pinMode(m5dir, OUTPUT);
  pinMode(m5stp, OUTPUT);

  pinMode(m6ms2, OUTPUT);
  pinMode(m6ms1, OUTPUT);
  pinMode(m6dir, OUTPUT);
  pinMode(m6stp, OUTPUT);


  pinMode(36, OUTPUT);
  pinMode(38, OUTPUT);
  digitalWrite(36, HIGH); /*vcc*/
  digitalWrite(38, LOW); /*gnd*/

  //Safety Button

  pinMode (button,INPUT);


}

void loop()
{

  digitalWrite(enable8, HIGH);
  digitalWrite(enable9, HIGH);
  digitalWrite(enable10, HIGH);
  digitalWrite(enable11, HIGH);
  digitalWrite(enable12, HIGH);
  digitalWrite(enable13, HIGH);

  availableBytes = Serial.available();

  for (int i = 0; i < availableBytes ; i++)
  {
    string[i] = Serial.read();

  }

  //delay(1000);

  if (availableBytes != 0)
  {

    for (int i = 0; i < availableBytes ; i++)
    {
      Serial.println(string[i]);
    }

    act = 1;
    flag = 1 ;
    Serial.println("Data Stored");

  }
  //Serial.println("At this point reached");
  if ( act == 1)
  {
    Serial.println("inside act");
    if (flag == 1)
    {
      Serial.println("inside flag ");
      for (int i = 0; i < availableBytes; i++)
      {

         /* while (check == 0)
          {
            int go = digitalRead(button);
            if (go == 1)
              check ++;
          } */

        if (string[i] == 'X')
        {
          digitalWrite(enable8, HIGH);
          digitalWrite(enable9, HIGH);
          digitalWrite(enable10, HIGH);
          digitalWrite(enable11, HIGH);
          digitalWrite(enable12, HIGH);
          digitalWrite(enable13, HIGH);

          check = 0;
          
          break;
        }

        else if (string[i] == 'A')
        {
          Serial.println("INTO A");



          Serial.println("MOTOR 5 90 Clockwise");
          digitalWrite(enable12, LOW);
          digitalWrite(m5dir, HIGH);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m5ms2, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m5ms1, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m5ms1, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m5ms2, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms2, LOW);
          }




          digitalWrite(enable12, HIGH);
          delay(1000);

          check = 0;
        }


        else if (string[i] == 'B')
        {
          Serial.println("INTO B");

          Serial.println("MOTOR 5 90 Anti-Clockwise");
          digitalWrite(enable12, LOW);
          digitalWrite(m5dir, LOW);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m5ms2, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m5ms1, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m5ms1, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m5ms2, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms2, LOW);
          }



          digitalWrite(enable12, HIGH);
          delay(1000);

          check = 0;
          
        }



        else if (string[i] == 'C')
        {
          Serial.println("INTO C");


          Serial.println("MOTOR 5 180 Clockwise");
          digitalWrite(enable12, LOW);
          digitalWrite(m5dir, HIGH);



          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m5ms2, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms2, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m5ms1, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms1, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m5ms1, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms1, LOW);
          }

          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m5ms2, HIGH);
            digitalWrite(m5stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m5stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m5ms2, LOW);
          }



          digitalWrite(enable12, HIGH);
          delay(1000);

          check = 0;
          
        }

        else if (string[i] == 'D')
        {
          Serial.println("INTO D");


          Serial.println("MOTOR 2  90 Clockwise");
          digitalWrite(enable9, LOW);
          digitalWrite(m2dir, HIGH);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m2ms2, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m2ms1, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m2ms1, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m2ms2, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms2, LOW);
          }



          digitalWrite(enable9, HIGH);
          delay(1000);

          check = 0;

        }

        else if (string[i] == 'E')
        {
          Serial.println("INTO E");


          Serial.println("MOTOR 2 90 Anti-Clockwise");
          digitalWrite(enable9, LOW);
          digitalWrite(m2dir, LOW);




          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m2ms2, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m2ms1, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m2ms1, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m2ms2, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms2, LOW);
          }



          digitalWrite(enable9, HIGH);
          delay(1000);

          check = 0;
          
        }

        else if (string[i] == 'F')
        {
          Serial.println("INTO F");


          Serial.println("MOTOR 2 180 Clockwise");
          digitalWrite(enable9, LOW);
          digitalWrite(m2dir, HIGH);



          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m2ms2, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms2, LOW);
          }


          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m2ms1, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms1, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m2ms1, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms1, LOW);
          }

          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m2ms2, HIGH);
            digitalWrite(m2stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m2stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m2ms2, LOW);
          }


          digitalWrite(enable9, HIGH);
          delay(1000);

          check = 0;
          
        }

        else if (string[i] == 'G')
        {
          Serial.println("INTO G");


          Serial.println("MOTOR 1 90 Clockwise");
          digitalWrite(enable8, LOW);
          digitalWrite(m1dir, HIGH);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m1ms2, HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m1ms1, HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms1, LOW);
          }


          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
          }


          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m1ms1, HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms1, LOW);
          }


          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m1ms2, HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms2, LOW);
          }




          digitalWrite(enable8, HIGH);

          delay(1000);

          check = 0;
          
        }

        else if (string[i] == 'H')
        {
          Serial.println("INTO H");


          Serial.println("MOTOR 1 90 anti-Clockwise");
          digitalWrite(enable8, LOW);
          digitalWrite(m1dir, LOW);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m1ms2, HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {

            digitalWrite(m1ms1, HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {

            digitalWrite(m1ms1, HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m1ms2, HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms2, LOW);
          }



          digitalWrite(enable8, HIGH);

          delay(1000);

          check = 0;

        }

        else if (string[i] == 'I')
        {
          Serial.println("INTO I");


          Serial.println("MOTOR 1 180 Clockwise");
          digitalWrite(enable8, LOW);
          digitalWrite(m1dir, HIGH);



          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m1ms2,HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms2,LOW);
          }
          
          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m1ms1,HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms1,LOW);
          }


          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
          }


          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m1ms1,HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms1,LOW);
          }


          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m1ms2,HIGH);
            digitalWrite(m1stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m1stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m1ms2,LOW);
          }





          digitalWrite(enable8, HIGH);

          delay(1000);

          check = 0;
          
        }

        else if (string[i] == 'J')
        {
          Serial.println("INTO J");


          Serial.println("MOTOR 6 90 Clockwise");
          digitalWrite(enable13, LOW);
          digitalWrite(m6dir, HIGH);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m6ms2, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m6ms1, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m6ms1, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m6ms2, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms2, LOW);
          }




          digitalWrite(enable13, HIGH);
          delay(1000);

          check = 0;

        }

        else if (string[i] == 'K')
        {
          Serial.println("INTO K");


          Serial.println("MOTOR 6 90 Anti-Clockwise");
          digitalWrite(enable13, LOW);
          digitalWrite(m6dir, LOW);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m6ms2, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m6ms1, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m6ms1, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m6ms2, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms2, LOW);
          }




          digitalWrite(enable13, HIGH);
          delay(1000);

          check = 0;
          
        }

        else if (string[i] == 'L')
        {
          Serial.println("INTO L");


          Serial.println("MOTOR 6 180 Clockwise");
          digitalWrite(enable13, LOW);
          digitalWrite(m6dir, HIGH);



          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m6ms2, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms2, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m6ms1, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms1, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m6ms1, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms1, LOW);
          }

          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m6ms2, HIGH);
            digitalWrite(m6stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m6stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m6ms2, LOW);
          }




          digitalWrite(enable13, HIGH);
          delay(1000);

          check = 0;
          
        }

        else if (string[i] == 'M')
        {
          Serial.println("INTO M");


          Serial.println("MOTOR 4 90 Clockwise");
          digitalWrite(enable11, LOW);
          digitalWrite(m4dir, HIGH);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m4ms2, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m4ms1, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m4ms1, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m4ms2, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms2, LOW);
          }

          digitalWrite(enable11, HIGH);
          delay(1000);

          check = 0;

        }

        else if (string[i] == 'N')
        {
          Serial.println("INTO N");



          Serial.println("MOTOR 4 90 Anti-Clockwise");
          digitalWrite(enable11, LOW);
          digitalWrite(m4dir, LOW);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m4ms2, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m4ms1, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m4ms1, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m4ms2, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms2, LOW);
          }



          digitalWrite(enable11, HIGH);
          delay(1000);

          check = 0;

        }

        else if (string[i] == 'O')
        {
          Serial.println("INTO O");



          Serial.println("MOTOR 4 180 Clockwise");
          digitalWrite(enable11, LOW);
          digitalWrite(m4dir, HIGH);



          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m4ms2, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms2, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m4ms1, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms1, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m4ms1, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms1, LOW);
          }

          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m4ms2, HIGH);
            digitalWrite(m4stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m4stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m4ms2, LOW);
          }



          digitalWrite(enable11, HIGH);
          delay(1000);

          check = 0;

        }

        else if (string[i] == 'P')
        {
          Serial.println("INTO P");


          Serial.println("MOTOR 3 90 Clockwise");
          digitalWrite(enable10, LOW);
          digitalWrite(m3dir, HIGH);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m3ms2, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m3ms1, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m3ms1, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m3ms2, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms2, LOW);
          }



          digitalWrite(enable10, HIGH);

          delay(1000);

          check = 0;
        }

        else if (string[i] == 'Q')
        {
          Serial.println("INTO Q");



          Serial.println("MOTOR 3 90 Anti-Clockwise");
          digitalWrite(enable10, LOW);
          digitalWrite(m3dir, LOW);



          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m3ms2, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms2, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m3ms1, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms1, LOW);
          }

          for (int x = 0; x < 10; x++)
          {
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m3ms1, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms1, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m3ms2, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms2, LOW);
          }




          digitalWrite(enable10, HIGH);

          delay(1000);

          check = 0;
          
        }

        else if (string[i] == 'R')
        {
          Serial.println("INTO R");

          Serial.println("MOTOR 3 180 Clockwise");
          digitalWrite(enable10, LOW);
          digitalWrite(m3dir, HIGH);



          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m3ms2, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms2, LOW);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m3ms1, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms1, LOW);
          }

          for (int x = 0; x < 20; x++)
          {
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
          }

          for (int x = 0; x < 40; x++)
          {
            digitalWrite(m3ms1, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms1, LOW);
          }

          for (int x = 0; x < 80; x++)
          {
            digitalWrite(m3ms2, HIGH);
            digitalWrite(m3stp, HIGH);
            delayMicroseconds(500);
            digitalWrite(m3stp, LOW);
            delayMicroseconds(500);
            digitalWrite(m3ms2, LOW);
          }




          digitalWrite(enable10, HIGH);

          delay(1000);

          check = 0;

        }

      }
      flag = 2;


    }
    act = 2;
  }

}
