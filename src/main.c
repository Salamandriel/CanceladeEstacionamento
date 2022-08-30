#include "main.h"

volatile int currentState = 0;
int detector = 0;
int contador = 0;
int botao = 0;
char audio = "Entrada Liberada";
int codigo = 0;
bool cancela = false;

int InitPerifericos(){
    return 1;
}

int main(void){
    InitPerifericos();
    while(1){
        
        detector++;
        
        switch (currentState)
        {
            case PASSAGEM_BLOQUEADA:
                if(detector == 1){
                    cancela = false;
                    botao = input();
                    codigo = input();
                    if(botao == 1){
                        contador++;
                        print(audio);
                        print(contador);
                        currentState = ENTRADA_LIBERADA;
                    }
                    if(codigo == 1){
                        currentState = SAIDA_LIBERADA;
                    }
                }
                break;
            case ENTRADA_LIBERADA:
                cancela = True;
                botao = 0;
                detector = 0;
                break;
            case SAIDA_LIBERADA:
                cancela = True;
                break;
            default:
                break;
        }

        currentKey = -1;
    }
    return 1;
}