#include <LiquidCrystal.h> // Incluindo a biblioteca LiquidCrystal para controlar o display LCD
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); // Configurando o display LCD com os pinos correspondentes

const int x_coords[14][6] = { // Definindo as coordenadas dos caracteres do "Pac-Man"
    {1,0,0,1,2,2},
    {2,1,1,2,3,3},
    {3,2,2,3,4,4},
    {4,3,3,4,5,5},
    {5,4,4,5,6,6},
    {6,5,5,6,7,7},
    {7,6,6,7,8,8},
    {8,7,7,8,9,9},
    {9,8,8,9,10,10},
    {10,9,9,10,11,11},
    {11,10,10,11,12,12},
    {12,11,11,12,13,13},
    {13,12,12,13,14,14},
    {14,13,13,14,15,15},
  };

void setup(){
  lcd.begin(16,2); // Inicializando o display LCD com 16 colunas e 2 linhas
}

void loop(){
    lcd.clear(); // Limpando o display LCD
    lcd.setCursor(3, 1); // Posicionando o cursor na segunda linha e na quarta coluna
    lcd.print("NEXT FUTURE "); // Escrevendo no display LCD
    delay(1000); // Aguardando 1 segundo
    move_pac(); // Chamando a função para mover o "Pac-Man"
}

void move_pac() {
  String line = "NEXT FUTURE"; // Definindo uma string com o texto "NEXT FUTURE"
  for (int i = 3; i < 17; i++) { // Loop para mover o "Pac-Man" pela linha
    boca(i, i - 3, line); // Chamando a função para desenhar o "Pac-Man" com a boca aberta
    line.remove(0, 1); // Removendo o primeiro caractere da string
  }
  fecha(13); // Chamando a função para desenhar o "Pac-Man" com a boca fechada
}

void boca(int x_cursor, int pos, String texto){
  fecha(pos); // Chamando a função para desenhar o "Pac-Man" com a boca fechada
  if (texto != ""){ // Verificando se a string não está vazia
    print_cursor(x_cursor, texto); // Chamando a função para imprimir texto no display LCD
  } 

  abre(pos); // Chamando a função para desenhar o "Pac-Man" com a boca aberta
  if (texto != ""){ // Verificando se a string não está vazia
    print_cursor(x_cursor, texto); // Chamando a função para imprimir texto no display LCD
  } 
}

void fecha(int pos){
  delay(300); // Aguardando 300 milissegundos
  lcd.clear(); // Limpando o display LCD
  image_fechada(x_coords[pos][0], x_coords[pos][1], x_coords[pos][2], x_coords[pos][3], x_coords[pos][4], x_coords[pos][5]); // Chamando a função para desenhar o "Pac-Man" com a boca fechada
}

void abre(int pos){
  delay(300); // Aguardando 300 milissegundos
  image_aberta(x_coords[pos][0], x_coords[pos][1], x_coords[pos][2], x_coords[pos][3], x_coords[pos][4], x_coords[pos][5]); // Chamando a função para desenhar o "Pac-Man" com a boca aberta
}

void print_cursor(int x_cursor, String texto){
  lcd.setCursor(x_cursor, 1); // Posicionando o cursor na segunda linha e na coluna especificada
  lcd.print(texto); // Imprimindo texto no display LCD
}

void image_aberta(int x1,int x2,int x3,int x4,int x5,int x6) {
  // Definindo os padrões dos caracteres para desenhar o "Pac-Man" com a boca aberta
  byte bot_back[8] = {B00100, B00100, B00010, B00010, B00001, B00000, B00000, B00000};
  byte bot_mid[8] = {B00000, B00000, B00000, B00000, B00000, B11111, B00000, B00000};
  byte bot_front[8] = {B10000, B01000, B00100, B01000, B10000, B00000, B00000, B00000};
  byte top_back[8] = {B00000, B00000, B00000, B00001, B00010, B00010, B00100, B00100};
  byte top_mid[8] = {B00000, B00000, B11111, B00000, B00000, B00110, B00110, B00000};
  byte top_front[8] = {B00000, B00000, B00000, B10000, B01000, B00100, B01000, B10000};

  // Criando caracteres personalizados no display LCD
  lcd.createChar(0, bot_mid);
  lcd.createChar(1, bot_back);
  lcd.createChar(2, top_back);
  lcd.createChar(3, top_mid);
  lcd.createChar(4, top_front);
  lcd.createChar(5, bot_front);

  // Movendo os caracteres para desenhar o "Pac-Man" com a boca aberta
  move_image(x1, 1, 0);
  move_image(x2, 1, 1);
  move_image(x3, 0, 2);
  move_image(x4, 0, 3);
  move_image(x5, 0, 4);
  move_image(x6, 1, 5);
}

void image_fechada(int x1,int x2,int x3,int x4,int x5,int x6){
  // Definindo os padrões dos caracteres para desenhar o "Pac-Man" com a boca fechada
  byte top_back[8] = {B00000, B00000, B00000, B00001, B00010, B00010, B00100, B00100};
  byte top_mid[8] = {B00000, B00000, B11111, B00000, B00000, B00110, B00110, B00000};
  byte top_front[8] = {B00000, B00000, B00000, B00000, B00000, B11111, B00000, B00000};  
  byte bot_back[8] = {B00100, B00100, B00010, B00010, B00001, B00000, B00000, B00000};
  byte bot_mid[8] = {B00000, B00000, B00000, B10000, B01000, B01000, B00100, B00100};
  byte bot_front[8] = {B00100, B00100, B01000, B01000, B10000, B00000, B00000, B00000};

  // Criando caracteres personalizados no display LCD
  lcd.createChar(0, top_mid);
  lcd.createChar(1, top_back);
  lcd.createChar(2, bot_back);
  lcd.createChar(3, top_front); 
  lcd.createChar(4, bot_mid);
  lcd.createChar(5, bot_front);

  // Movendo os caracteres para desenhar o "Pac-Man" com a boca fechada
  move_image(x1, 0, 0);
  move_image(x2, 0, 1);
  move_image(x3, 1, 2);
  move_image(x4, 1, 3);
  move_image(x5, 0, 4);
  move_image(x6, 1, 5);

}

void move_image(int x, int y, int byt){
  lcd.setCursor(x, y); // Posicionando o cursor nas coordenadas especificadas
  lcd.write(byte(byt)); // Escrevendo o caractere personalizado no display LCD
}
