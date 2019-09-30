void setup() {
  Serial.begin(9600);
}

  int L_flag = 0;
  int R_flag = 0;
  int L_flag_2 = 0;
  int R_flag_2 = 0;


void loop() {
  int analog_data;
  analog_data = analogRead(A0);

  if(analog_data > 700 && analog_data < 1024)
  {
    if(L_flag == 0)
     {
       Serial.println("L");
       L_flag = 1;
    }
  }
  else if (analog_data > 0 && analog_data < 400)
  {
    if(R_flag == 0)
    {
      Serial.println("R");
      R_flag = 1;
    }
  }
  else if(analog_data >400 && analog_data < 700)
  {
     R_flag = 0;
     L_flag = 0;
  }

  //---------
  
  int analog_data_2;
  analog_data_2 = analogRead(A1);

  if(analog_data_2 > 700 && analog_data_2 < 1024)
  {
    if(L_flag_2 == 0)
     {
       Serial.println("L_2");
       L_flag_2 = 1;
    }
  }
  else if (analog_data_2 > 0 && analog_data_2 < 400)
  {
    if(R_flag_2 == 0)
    {
      Serial.println("R_2");
      R_flag_2 = 1;
    }
  }
  else if(analog_data_2 >400 && analog_data_2 < 700)
  {
     R_flag_2 = 0;
     L_flag_2 = 0;
  }


  delay(10);
}
