# Projeto de Exibição de "Pac-Man" em um Display LCD

## Visão Geral
Este projeto é um exemplo simples de como criar uma animação do personagem "Pac-Man" em um display LCD utilizando uma placa Arduino e a biblioteca LiquidCrystal.

## Recursos Utilizados
- Arduino Uno (ou similar)
- Display LCD 16x2
- Cabos jumper

## Configuração do Hardware
Conecte o display LCD ao Arduino da seguinte maneira:
- Pino VSS do LCD ao GND do Arduino
- Pino VDD do LCD ao +5V do Arduino
- Pino VO do LCD ao cursor de potência do potenciômetro
- Pino RS do LCD ao pino digital 12 do Arduino
- Pino RW do LCD ao GND do Arduino
- Pino EN do LCD ao pino digital 11 do Arduino
- Pinos D4 a D7 do LCD aos pinos digitais 5 a 2 do Arduino

## Funcionalidades
- A animação exibe o a logo da equipe "NEXT FUTURE" movendo-se horizontalmente no display LCD, enquanto um ícone "Pac-Man" acompanha o movimento com sua boca abrindo e fechando.
- O movimento do "Pac-Man" é realizado desenhando e redesenhando seus caracteres personalizados em diferentes posições no display.

## Uso do Código
- Abra o arquivo "projeto.ino" no Arduino IDE.
- Faça o upload do código para o Arduino.
- Observe a animação do "Pac-Man" no display LCD.

## Tinkercad

<a href="https://www.tinkercad.com/things/4yJdtZ7YJDf-copy-of-copy-of-display-lcd-16x2">
<img src="./tkc.png" alt="tinkercad_logo"></a>
<p>Clique na logo para abrir o projeto</p>


## Contribuidores
- Ana Laura <sobrenome> - RM <>
- Gerônimo <sobrenome> - RM <>
- Mateus Leme - RM 93480
- Vitor <sobrenome> - RM <>
