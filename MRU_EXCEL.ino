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
#define botao 8
#define led 9
int sensor[5] = {2, 3, 4, 5, 6};

//===============================================================================//
// * Variáveis de Controle
//===============================================================================//
int sensPass;

//===============================================================================//
// * Declarar funções
//===============================================================================//
void keyENTER();
void keyUP ();
void EstadoSuspenso();
void InstantesTempo();
int SensoresID();

//===============================================================================//
// * Função que configura o Arduino e os Sensores
//===============================================================================//
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
  for(int i = 0 ; i < 5 ; i++){
    pinMode(sensor[i], INPUT);
  }

  //===============================================================================//
  // * Iniciar o Teclado
  //===============================================================================//
  Keyboard.begin();

}

//===============================================================================//
// * Função Principal
//===============================================================================//
void loop() {

  if(digitalRead(botao) == HIGH){
    //===============================================================================//
    // * Define o sistema em estado SUSPENSO
    //===============================================================================//
    EstadoSuspenso();
  }else{
    //===============================================================================//
    // * Define o sistema para calcular os instantes de tempo
    //===============================================================================//
    InstantesTempo();
  }

}

//===============================================================================//
// * Função que define o Estado Suspenso do Sistema
//===============================================================================//
void EstadoSuspenso(){

    //===============================================================================//
    // * Liga o Eletroímã
    //===============================================================================//
    digitalWrite(gate, HIGH);
    
    //===============================================================================//
    // * Variável definida para 0, para "resetar" os sensores
    //===============================================================================//
    sensPass = 0;

    //===============================================================================//
    // * LED Aceso indica que o sistema ainda não está funcionando
    //===============================================================================//
    digitalWrite(led, HIGH);

}

//===============================================================================//
// * Função que calculará os instantes de tempo do moviemento
//===============================================================================//
void InstantesTempo(){

  //===============================================================================//
  // * Definir variáveis que serão utilizadas para calcular o tempo
  //===============================================================================//
  unsigned long tempo[5], tempoInicial;
  float t[5];

  //===============================================================================//
  // * Desliga o LED e o Eletroímã, indicando que o sistema está funcionado
  //===============================================================================//
  digitalWrite(gate, LOW);
  digitalWrite(led, LOW);

  //===============================================================================//
  // * Obter os instantes de tempo quando o móvel passar pelos sensores
  //===============================================================================//
  if (SensoresID() == 0 && sensPass == 0) {
    tempo[0] = micros();
    sensPass++;
    //Obter o valor de tempo no Instante 1
  }

  if (SensoresID() == 1 && sensPass == 1) {
    tempo[1] = micros();
    sensPass++;
    //Obter o valor de tempo no Instante 2
  }

  if (SensoresID() == 2 && sensPass == 2) {
    tempo[2] = micros();
    sensPass++;
    //Obter o valor de tempo no Instante 3
  }

  if (SensoresID() == 3 && sensPass == 3) {
    tempo[3] = micros();
    sensPass++;
    //Obter o valor de tempo no Instante 4
  }

  if (SensoresID() == 4 && sensPass == 4) {
    tempo[4] = micros();
    sensPass++;
    //Obter o valor de tempo no Instante 5
  }

  //===============================================================================//
  // * Após coletar os tempos, tratar os dados
  //===============================================================================//
  if (sensPass == 5) {

    //===============================================================================//
    // * Variável de tempo inicial para efetuar a correção nos resultados
    //===============================================================================//
    tempoInicial = tempo[0];

    //===============================================================================//
    // * Strings usadas para escrever os dados no EXCEL
    //===============================================================================//
    String instanteTempo[5];

    //===============================================================================//
    // * Conversão dos tempos para SEGUNDOS e tratamento para exibição no EXCEL
    //===============================================================================//
    for (int i = 0 ; i < 5 ; i++){
      t[i] = float(tempo[i] - tempoInicial) * pow(10, -6);

      delay(50);

      instanteTempo[i] = String(t[i], 3);
      instanteTempo[i].replace(".", ",");

      Keyboard.print(instanteTempo[i]);
      keyENTER();
    }

    keyUP();
    
    sensPass = 0;
  }

}

//===============================================================================//
// * Função que checará se os sensores capturaram um obstáculo ou não
//===============================================================================//
int SensoresID(){

  if (digitalRead(sensor[0]) == LOW) {
    return 0;
  }

  if (digitalRead(sensor[1]) == LOW) {
    return 1;
  }

  if (digitalRead(sensor[2]) == LOW) {
    return 2;
  }

  if (digitalRead(sensor[3]) == LOW) {
    return 3;
  }

  if (digitalRead(sensor[4]) == LOW) {
    return 4;
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

  for(int i = 0; i < 5; i++){
    Keyboard.press(KEY_UP_ARROW);
    delay(50);
    Keyboard.release(KEY_UP_ARROW);
    delay(50);
  }
  
}
