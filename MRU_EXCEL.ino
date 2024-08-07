
//===============================================================================//
//==================== ALGORÍTIMO PARA MRU - PLANO INCLINADO ====================//
//===============================================================================//

//===============================================================================//
// * Inserir biblioteca de teclado
//===============================================================================//
#include <Keyboard.h>

//===============================================================================//
// * Definir os Sensores e outros Componentes
//===============================================================================//
#define gate 7
#define sensor1 2 //Marrom
#define sensor2 3 //Cinza
#define sensor3 4 //Azul
#define sensor4 5 //Roxo
#define sensor5 6 //Verde
#define botao 8
#define led 9

//===============================================================================//
// * Variáveis de Controle
//===============================================================================//
bool a, b, c, d, e;
byte sens;
byte i;

//===============================================================================//
// * Declarar funções de teclas
//===============================================================================//
void keyENTER();
void keyUP ();

//===============================================================================//
// * Definir variáveis que serão utilizadas para calcular o tempo
//===============================================================================//
unsigned long tempoInicial;
unsigned long tempo1, tempo2, tempo3, tempo4, tempo5;
float t1, t2, t3, t4, t5;

void setup() {
  //===============================================================================//
  // * Definir Botão como Entrada de Dados e o LED como Saída
  //===============================================================================//
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(gate, OUTPUT);

  //===============================================================================//
  // * Definir os Sensores como Entrada de Dados
  //===============================================================================//
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);

  //===============================================================================//
  // * Iniciar o Teclado
  //===============================================================================//
  Keyboard.begin();
}

void loop() {
  //===============================================================================//
  // * Enquanto o Botão não estiver pressionado, ocorre este WHILE
  //===============================================================================//
  while (digitalRead(botao) == HIGH) {
    //Liga o eletroímã
    digitalWrite(gate, HIGH);
    
    //Variáveis definidas como FALSE quando o botão não estiver pressionado
    a = false;
    b = false;
    c = false;
    d = false;
    e = false;
    sens = 0;

    //LED Aceso indica que o sistema ainda não está funcionando
    digitalWrite(led, HIGH);

    //Tempo que será capturado assim que o botão for pressionado.
    tempoInicial = millis();

    //OBS: Este tempo será usando para realizar uma correção no tempo de cada sensor,
    //a fim de obter o valor exato dos instantes de tempo em cada posição do móvel.
  }

  //===============================================================================//
  // * Após condição do WHILE ser desfeita
  //   Desliga o LED, indicando que o sistema está funcionado
  //===============================================================================//
  digitalWrite(gate, LOW);
  digitalWrite(led, LOW);

  //===============================================================================//
  // * Define as Variáveis de controle como TRUE se o sensor tiver captado o móvel
  //===============================================================================//
  if (digitalRead(sensor1) == LOW) {
    a = true;
  }

  if (digitalRead(sensor2) == LOW) {
    b = true;
  }

  if (digitalRead(sensor3) == LOW) {
    c = true;
  }

  if (digitalRead(sensor4) == LOW) {
    d = true;
  }

  if (digitalRead(sensor5) == LOW) {
    e = true;
  }

  //===============================================================================//
  // * Obter os instantes de tempo quando o móvel passar pelos sensores
  //===============================================================================//
  if (a == true && b == false && c == false && d == false && e == false && sens == 0) {
    tempo1 = millis();
    sens++;
    //Obter o valor de tempo no Instante 1
  }

  if (a == true && b == true && c == false && d == false && e == false && sens == 1) {
    tempo2 = millis();
    sens++;
    //Obter o valor de tempo no Instante 2
  }

  if (a == true && b == true && c == true && d == false && e == false && sens == 2) {
    tempo3 = millis();
    sens++;
    //Obter o valor de tempo no Instante 3
  }

  if (a == true && b == true && c == true && d == true && e == false && sens == 3) {
    tempo4 = millis();
    sens++;
    //Obter o valor de tempo no Instante 4
  }

  if (a == true && b == true && c == true && d == true && e == true && sens == 4){
    tempo5 = millis();
    sens++;
    //Obter o valor de tempo no Instante 5
  }

  //===============================================================================//
  // * Após coletar os tempos, fazer a correção no tempo e converter para SEGUNDOS
  //===============================================================================//
  if (sens == 5) {
    t1 = (tempo1 - tempoInicial) * 0.001;
    t2 = (tempo2 - tempoInicial) * 0.001;
    t3 = (tempo3 - tempoInicial) * 0.001;
    t4 = (tempo4 - tempoInicial) * 0.001;
    t5 = (tempo5 - tempoInicial) * 0.001;

    delay(50);
    
    //===============================================================================//
    // * Strings usadas para escrever os dados no EXCEL
    //===============================================================================//
    String tempo_1;
    String tempo_2;
    String tempo_3;
    String tempo_4;
    String tempo_5;

    //Converte as variáveis para textos
    tempo_1 = String(t1, 3);
    tempo_2 = String(t2, 3);
    tempo_3 = String(t3, 3);
    tempo_4 = String(t4, 3); 
    tempo_5 = String(t5, 3);

    //Troca o PONTO FINAL por VÍRGULA como indicador de casa decimal
    tempo_1.replace(".", ","); 
    tempo_2.replace(".", ",");
    tempo_3.replace(".", ",");    
    tempo_4.replace(".", ",");
    tempo_5.replace(".", ","); 

    //Imprimir os valores obtidos no EXCEL
    Keyboard.print(tempo_1);
    keyENTER();
    Keyboard.print(tempo_2);
    keyENTER();
    Keyboard.print(tempo_3);
    keyENTER();
    Keyboard.print(tempo_4);
    keyENTER();
    Keyboard.print(tempo_5);
    keyENTER();

    keyUP();
    
    sens = 0;
  }
}

//===============================================================================//
// * Função para pressionar e soltar a tecla ENTER
//===============================================================================//
void keyENTER() {
  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.release(KEY_RETURN);
  delay(50);
}

//===============================================================================//
// * Função para pressionar e soltar a tecla CIMA 5 vezes
//===============================================================================//
void keyUP() {
  for(i = 0; i < 5; i++){
    Keyboard.press(KEY_UP_ARROW);
    delay(50);
    Keyboard.release(KEY_UP_ARROW);
    delay(50);
  }
}
