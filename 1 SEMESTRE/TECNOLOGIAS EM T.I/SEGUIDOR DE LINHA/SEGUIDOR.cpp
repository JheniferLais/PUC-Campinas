#include <Servo.h>

Servo RodaE;  //CRIA O SERVO (ESQUERDO) 
Servo RodaD;  //CRIA O SERVO (DIREITO)

int SensorE = 0;  //VARIAVEL PARA O VALOR DO SENSOR (ESQUERDO)
int SensorD = 0;  //VARIAVEL PARA O VALOR DO SENSOR (DIREITO)

const int Linha = 350;  //VARIAVEL PARA SER USADA DE COMPARAÇÃO -- VARIÁVEL CONSTANTE

void setup() {
  RodaE.attach(5);    //CONFIGURA O SERVO AO PINO (ESQUERDO)
  RodaD.attach(6);    //CONFIGURA O SERVO AO PINO (DIREITO)
  Serial.begin(9600); //INICIA COMUNICAÇÃO SERIAL
}

void loop() {
  int SensorE = analogRead(A5);  //ARMAZENA NA VARIAVEL O VALOR LIDO NO SENSOR (ESQUERDO)
  int SensorD = analogRead(A4);  //ARMAZENA NA VARIAVEL O VALOR LIDO NO SENSOR (DIREITO)


  Serial.print("Sensor ESQUERDO= ");
  Serial.print(SensorE);
  Serial.println();                 //PRINT DA VARIAVEL NO MONITOR SERIAL
  Serial.print("Sensor DIREITO= ");  
  Serial.print(SensorD);
  Serial.println();                 //PRINT DA VARIAVEL NO MONITOR SERIAL

  if (SensorE < Linha && SensorD < Linha) { //EM FRENTE
    RodaE.write(0);                         //RODA ESQUERDA VAI PARA FRENTE
    RodaD.write(180);                       //RODA DIREITA VAI PARA FRENTE
  }
  if (SensorE > Linha && SensorD < Linha) { //CURVA DIREITA
    RodaE.write(0);                         //RODA ESQUERDA VAI PARA FRENTE
    RodaD.write(90);                        //RODA DIREITA PARA
  }
  if (SensorE < Linha && SensorD > Linha) {  //CURVA ESQUERDA
    RodaE.write(90);                         //RODA ESQUERDA PARA
    RodaD.write(180);                        //RODA DIREITA VAI PARA FRENTE
  }
  else if (SensorE > Linha && SensorD > Linha) { //PARADA
    RodaE.write(90);                             //RODA ESQUERDA PARA
    RodaD.write(90);                             //RODA DIREITA PARA
  }
}