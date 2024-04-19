#include <LiquidCrystal.h> // Incluindo a biblioteca LiquidCrystal para controlar o display LCD
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); // Configurando o display LCD com os pinos correspondentes

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
  ghost();
  move_image(14,1,10);
  for (int pos = 0; pos < 15; pos++) { // Loop para mover o "Pac-Man" pela linha
    move(pos, line); // Chamando a função para desenhar o "Pac-Man" com a boca aberta
    line.remove(0,1);
  }
}

// Define a imagem de "Pac-Man" com a boca fechada
void fechado() {
    byte i4[8] = {B00000, B00000, B00000, B00001, B00010, B00010, B00100, B00100};
    byte i5[8] = {B00000, B00000, B11111, B00000, B00000, B00110, B00110, B00000};
    byte i6[8] = {B00000, B00000, B00000, B10000, B01000, B01000, B00100, B00100};
    byte i7[8] = {B00100, B00100, B00010, B00010, B00001, B00000, B00000, B00000};
    byte i8[8] = {B00000, B00000, B00000, B00000, B00000, B11111, B00000, B00000};
    byte i9[8] = {B00100, B00100, B01000, B01000, B10000, B00000, B00000, B00000};

    lcd.createChar(4, i4);
    lcd.createChar(5, i5);
    lcd.createChar(6, i6);
    lcd.createChar(7, i7);
    lcd.createChar(10, i8);
    lcd.createChar(9, i9);
}

// Define a imagem de "Pac-Man" com a boca aberta
void aberto() {
    byte i4[8] = {B00000, B00000, B00000, B00001, B00010, B00010, B00100, B00100};
    byte i5[8] = {B00000, B00000, B11111, B00000, B00000, B00110, B00110, B00000};
    byte i6[8] = {B00000, B00000, B00000, B10000, B01000, B00100, B01000, B10000};
    byte i7[8] = {B00100, B00100, B00010, B00010, B00001, B00000, B00000, B00000};
    byte i8[8] = {B00000, B00000, B00000, B00000, B00000, B11111, B00000, B00000};
    byte i9[8] = {B10000, B01000, B00100, B01000, B10000, B00000, B00000, B00000};

    lcd.createChar(4, i4);
    lcd.createChar(5, i5);
    lcd.createChar(6, i6);
    lcd.createChar(7, i7);
    lcd.createChar(8, i8);
    lcd.createChar(9, i9);
}

// Move o "Pac-Man" e alterna entre boca aberta e fechada
void move(int pos, String texto) {
    if (pos % 2 == 0) {
        fechado(); // Se a posição for par, a boca estará fechada
    } else {
        aberto();  // Se a posição for ímpar, a boca estará aberta
    }
    if (texto != ""){ // Verificando se a string não está vazia
      print_cursor(pos, texto); // Chamando a função para imprimir texto no display LCD
    }

    ghost_move(pos);

    move_image(pos + 0, 0, 4);
    move_image(pos + 1, 0, 5);
    move_image(pos + 2, 0, 6);
    move_image(pos + 0, 1, 7);
    move_image(pos + 1, 1, 8);
    move_image(pos + 2, 1, 9);

    delay(300); // Aguarda 300 milissegundos antes de continuar a animação
    lcd.clear(); // Limpa o display LCD
}

// Move uma imagem personalizada para uma determinada posição no display
void move_image(int x, int y, int byt) {
    lcd.setCursor(x, y); // Define a posição do cursor nas coordenadas especificadas
    lcd.write(byte(byt)); // Exibe o caractere personalizado no display LCD
}

void print_cursor(int pos, String texto){
  lcd.setCursor(pos+3, 1); // Posicionando o cursor na segunda linha e na coluna especificada
  lcd.print(texto); // Imprimindo texto no display LCD
}

void ghost(){
    byte ghost[8] = {B01110, B11111, B10101, B11011, B11111, B11111, B10101, B00000};
    lcd.createChar(10, ghost);
    move_image(14,1,10);
}
void ghost_move(int pos){
    byte ghost[8] = {B01110, B11111, B10101, B11011, B11111, B11111, B10101, B00000};
    lcd.createChar(10, ghost);
    if (pos%2!=0){
        move_image(15,1,10);
    } else{
        move_image(14,1,10);
    }
    
}