// Controle de velocidade de motor


#include <TimerOne.h>

// Define os pinos dos botões
const char Botao_1 = 6, Botao_2 = 5, Botao_3 = 4, Botao_4 = 3; // Botões para controle de velocidade
const char saida_pwm = 9;                                  // Pino de saída do PWM
unsigned int velocidade_ant = 0;

void setup() {
 
  // Define os botões
  pinMode(Botao_1, INPUT);
  pinMode(Botao_2, INPUT);
  pinMode(Botao_3, INPUT);
  pinMode(Botao_4, INPUT);
  pinMode(saida_pwm, OUTPUT);
 
  // Saida Serial
  Serial.begin(9600);
  Serial.println("Sistemas para controle de velocidade em motor DC");
  Serial.println("************************************************");
  Serial.println("Velocidade: 0 RPM");
 
  // Timer1, rotina:
  Timer1.initialize(100000);  // 100 ms
}


void loop() {
 
  if (!digitalRead(Botao_1))
    MudaVelocidade(0);
  else if(!digitalRead(Botao_2))
    MudaVelocidade(25);
  else if(!digitalRead(Botao_3))
    MudaVelocidade(50);
  else if(!digitalRead(Botao_4))
    MudaVelocidade(100);
  
  delay(5);

}

void MudaVelocidade(int velocidade){
  
  if (velocidade != velocidade_ant){
    int duty =  velocidade * 10.23;
    Timer1.pwm(saida_pwm, duty);
    Timer1.restart();
  
    Serial.print("Velocidade: ");
    Serial.print(velocidade);
    Serial.println("% da velocidade maxima");
    velocidade_anterior = velocidade;
  }
  
  delay(1000);
}
