//
// Created by mariana on 28/03/2021.
//

/*Implementaão da camada física*/
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string>
#include "camadafisica.h"

using namespace std;



void main_2 () {
    AplicacaoTransmissora();
}

// Fim do metodo main
void AplicacaoTransmissora(void){

    string mensagem;
    cout << "Digite uma mensagem:\n" << endl;
    cin >> mensagem;

    camadade_aplicacao_transmissora(mensagem);
}
void camadade_aplicacao_transmissora(string mensagem){

    camada_fisica_transmissora(quadro);
}