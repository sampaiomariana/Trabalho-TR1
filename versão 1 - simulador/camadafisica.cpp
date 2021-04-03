//
// Created by mariana on 03/04/2021.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "camadafisica.h"

using namespace std;

void conversor_ascii_binario(){
    char mensagem[55];
    int i;


    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;
    cout << "A mensagem digitada em binário eh :\n";


    // Conversor para binário
    for (i =0; i < mensagem[i]!= '\0'; i++){
        int aux;
        aux = mensagem[i];
        int j;
        for (j = 7; j + 1 > 0; j--){
            if (aux >=(1<< j)){
                aux = aux - (1 << j);
                cout << "1";
            } else {
                cout << "0";
            }

        }

    }
    cout << "\n";
}
void  CamadaFisicaTrasnmissoraCodificacaoBinaria(){
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
    conversor_ascii_binario();

}

void CamadaDeAplicacaoTransmissoraCodificacaoManchester(){
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
}

void CamadaDeAplicacaoTransmissoraBipolar(){
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
}
void CamadaFisicaTrasnmissora( ) {
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
    //int quadro[];
    int tipoDeCodificacao;  // alterar de acordo com o teste
    int fluxoBrutoDeBits; // fluxoBrutodeBits[]
    int size;

    // Definindo um tamanho para o quadro

    //cout << "\nDefinindo o tamanho do quadro que será recebido: \n" << size <<endl;

    cout << "\nDigite qual a codificação você escolhe:\n 0 - Binária \n 1 - Manchester\n 2 - Bipolar\n";
    cin >> tipoDeCodificacao;

    while (tipoDeCodificacao != 0 && tipoDeCodificacao != 1 && tipoDeCodificacao != 2) {
        cout << "Selecione uma opção válida." << endl;
        cout << "\nDigite qual a codificação você escolhe:\n 0 - Binária \n 1 - Manchester\n 2 - Bipolar\n";
        cin >> tipoDeCodificacao;
    }

    switch (tipoDeCodificacao) {
        case 0: // codificação binária
            CamadaFisicaTrasnmissoraCodificacaoBinaria();
            break;
        case 1: // codificação Manchester
            CamadaDeAplicacaoTransmissoraCodificacaoManchester();
            break;
        case 2: // codificação bipolar
            CamadaDeAplicacaoTransmissoraBipolar();
            break;

    }

}