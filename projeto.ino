#include <LiquidCrystal.h> // Incluindo a biblioteca LiquidCrystal para controlar o display LCD

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2); // Configurando o display LCD com os pinos correspondentes

    

void setup(){
    lcd.begin(16,2); // Inicializando o display LCD com 16 colunas e 2 linhas
}

void loop(){
    move_logo();
    move_pac(); // Chamando a função para mover o "Pac-Man"
}

void move_logo(){
    for (int i = 0; i < 2; i++){
        lcd.clear(); // Limpando o display LCD
        lcd.setCursor(3, i-1); // Posicionando o cursor na segunda linha e na quarta coluna
        lcd.print("NEXT FUTURE "); // Escrevendo no display LCD
        delay(1000); // Aguardando 1 segundo
    }
    lcd.clear(); // Limpando o display LCD
}

void move_pac() {
    showbot();
    for (int pos = 0; pos < 15; pos++) { // Loop para mover o "Pac-Man" pela linha
        move(pos); // Chamando a função para desenhar o "Pac-Man" com a boca aberta
    }
}

void showbot(){
    bot1();
    delay(1000);
    bot2();
    delay(1000);
}

void bot1() {
    lcd.clear();
    byte image07[8] = {B00000, B11100, B11010, B00011, B00111, B01111, B11101, B11000};
    byte image08[8] = {B00000, B00111, B01011, B10000, B11100, B00010, B10101, B01001};
    byte image24[8] = {B00001, B00010, B11010, B00100, B11000, B00000, B00000, B00000};
    byte image23[8] = {B11111, B01111, B01100, B00111, B00011, B00000, B00000, B00000};


    lcd.createChar(0, image07);
    lcd.createChar(1, image08);
    lcd.createChar(2, image24);
    lcd.createChar(3, image23);


    move_image(6,0,0);
    move_image(7,0,1);
    move_image(7,1,2);
    move_image(6,1,3);

}

void bot2() {
    lcd.clear();
    byte image07[8] = {B11100, B10010, B01111, B11111, B11011, B10001, B11011, B11111};
    byte image08[8] = {B00110, B01110, B10100, B11100, B00010, B01010, B10010, B01010};
    byte image24[8] = {B00010, B10010, B00100, B01000, B10000, B00000, B00000, B00000};
    byte image23[8] = {B11111, B01000, B01111, B00111, B00011, B00000, B00000, B00000};

    lcd.createChar(0, image07);
    lcd.createChar(1, image08);
    lcd.createChar(2, image24);
    lcd.createChar(3, image23);

    move_image(6,0,0);
    move_image(7,0,1);
    move_image(7,1,2);
    move_image(6,1,3);
}

void bot3() {
    byte i1[8] = {B11100, B11010, B00111, B00111, B01110, B01100, B01110, B01111};
    byte i2[8] = {B01111, B01100, B01100, B00100, B00111, B00011, B00001, B00000};
    byte i3[8] = {B00111, B01011, B11110, B10001, B10101, B10011, B10101, B10001};
    byte i4[8] = {B00001, B11101, B11101, B11101, B00001, B00010, B11100, B00000};
    

    lcd.createChar(0, i1);
    lcd.createChar(1, i2);
    lcd.createChar(2, i3);
    lcd.createChar(3, i4); 
}

void fechado(){
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

void aberto(){
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

void move(int pos) {  
    if (pos%2 == 0) {
        fechado();
    } else {
        aberto();
    }

    move_image(pos+0,0,4);
    move_image(pos+1,0,5);
    move_image(pos+2,0,6);
    move_image(pos+0,1,7);
    move_image(pos+1,1,8);
    move_image(pos+2,1,9);
  
    bot3();
    move_image(pos+6,0,0);
    move_image(pos+6,1,1);
    move_image(pos+7,0,2);
  	move_image(pos+7,1,3);
    delay(300); // Aguardando 300 milissegundos
    lcd.clear();
}

void move_image(int x, int y, int byt){
   lcd.setCursor(x, y); // Posicionando o cursor nas coordenadas especificadas
   lcd.write(byte(byt)); // Escrevendo o caractere personalizado no display LCD
}