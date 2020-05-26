/*
ASCII Input Method with a Potentiometer for Arduino
jetervaz@gmail.com
Aug, 2014
*/

#include <LiquidCrystal.h>

// configura os pinos do LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int inserir = 2;
int apagar = 3;
int espaco = 4;
int sel_tipo = 5;
int tipo = 0;
char palavra[16];
int i = 0;

void setup() {
    lcd.begin(16,2);
    pinMode(inserir, INPUT_PULLUP);
    pinMode(apagar, INPUT_PULLUP);
    pinMode(sel_tipo, INPUT_PULLUP);
    pinMode(espaco, INPUT_PULLUP);
}

void loop() {

    lcd.setCursor(0,0); // seta a posicao do cursor para o inicio

    if(digitalRead(sel_tipo) == LOW){ // quando o botao ‘sel_tipo’ eh pressionado
        delay(500); // o delay de meio segundo eh para evitar dupla execucao da funcao
        if(tipo < 6){
            tipo++;
        } else {
            tipo = 0;
        }
    }

    int primeiro = 65; // valor que inicia o mapeamento da entrada analogica
    int ultimo = 90; // valor que termina o mapeamento da entrada analogica

    switch(tipo){ // esse switch vai definir as faixas de mapeamento pela tabela ASCII
        case 0:
            primeiro = 65;
            ultimo = 90;
            lcd.print(“ABC”);
            break;

        case 1:
            primeiro = 97;
            ultimo = 122;
            lcd.print(“abc”);
            break;

        case 2:
            primeiro = 48;
            ultimo = 57;
            lcd.print(“123”);
            break;

        case 3:
            primeiro = 33;
            ultimo = 47;
            lcd.print(“!*.”);
            break;

        case 4:
            primeiro = 58;
            ultimo = 64;
            lcd.print(“>?@”);
            break;

        case 5:
            primeiro = 91;
            ultimo = 96;
            lcd.print(“[\\]“);
            break;

        case 6:
            primeiro = 123;
            ultimo = 126;
            lcd.print(“{|}”);
            break;
    }

    /* Esse bloco eh o responsavel pela selecao do caractere.
    A funcao ‘map’ ira mapear o valor analogica lida em ‘A0′, que na transformacao
    analogico-digital interna do ATMEGA varia de 0 a 1023, para a faixa escolhida pelo
    ‘switch’ logo acima, que eh escolhida pressionando o botao ‘sel_tipo’. Por exemplo,
    se ‘tipo’ for igual a 0, o valor de ‘analogRead(A0)’ sera transportado da faixa de
    0 a 1023 para a faixa de 65 a 90, ou seja, de A a Z.
    */
    char caractere = map(analogRead(A0), 0, 1023, primeiro, ultimo);
    lcd.setCursor(14,0);
    lcd.print(caractere);

    if(digitalRead(inserir) == LOW){ // quando o botao ‘inserir’ eh pressionado
        delay(500);
            if(i == 15){ // se o cursor esta no final, nao insere caractere e avisa!
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print(” CHEGA! Delete “);
            lcd.setCursor(0,1);
            lcd.print(” alguma coisa! “);
            delay(700);
            lcd.clear();
        } else {
            palavra[i] = caractere; // insere caractere na string ‘palavra’
            i++;
        }
    }

    if(digitalRead(espaco) == LOW){ // adiciona o caractere ESPACO quando
        delay(500); // o botao ‘espaco’ eh pressionado
        if(i == 15){ // se o cursor esta no final do display, nao insere caractere e avisa!
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print(” CHEGA! Delete “);
            lcd.setCursor(0,1);
            lcd.print(” alguma coisa! “);
            delay(700);
            lcd.clear();
        } else {
            palavra[i] = 32; // insere caractere ESPACO -> ASCII 32
            i++;
        }
    }

    if(digitalRead(apagar) == LOW){ // quando o botao ‘apagar’ eh pressionado
        if(i > 0){ // testa se existe algo para apagar
            i–;
        }
        palavra[i] = false; // ‘unseta’ o caractere da posicao ‘i’ no vetor/string ‘palavra’
        delay(500);
        if(digitalRead(apagar) == LOW){ // se o botao ‘apagar’ ficar 
            for(int j=0;j<16;j++){ // pressionado mais de meio-segundo
                palavra[j] = false; // ‘unseta’ todos os caracteres do vetor/string ‘palavra’
                i = 0; // e retorna o indice ‘i’ para o inicio do vetor
            }
        }
        lcd.clear(); // eh importante para nao deixar o cursor perdido
    }

    // muda para a segunda linha do LCD, mostra a palavra (se existir) e o cursor
    lcd.setCursor(0,1);
    lcd.print(palavra);
    lcd.print(“_”);
}