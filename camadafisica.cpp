//
// Created by Mariana de Sampaio on 28/03/2021.
//

/*Implementaão da camada física*/
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string>
#include "camadafisica.h"

using namespace std;

void CamadaFisicaTrasnmissoraCodificacaoBinaria(int quadro[]){
    // Implementação  do algoritmo
}


void CamadaDeAplicacaoTransmissoraCodificacaoManchester(int quadro[]){
    // implementação do algoritmo
}

void CamadaDeAplicacaoTransmissoraBipolar(int quadro[]){
    // implementação do algoritmo
}


void MeioDeComunicacao(int fluxoBrutoDeBits []){
    /*Descobrir como trabalhar com o fluxoBrutoDeBits*/

    // Trabalhar com bits e não com bytes
    int fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB; // []
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBitsPontoB; // []

  /*  while (fluxoBrutoDeBitsPontoB.lenght!= fluxoBrutoDeBitsPontoA){
        fluxoBrutoDeBitsPontoB += fluxoBrutoDeBitsPontoA; // bits sendo transferidos
*/
        //chama a próxima camada

        CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
    }
//}

void CamadaFisicaTrasnmissora(int quadro[]){
    int tipoDeCodificacao = 0;
    int fluxoBrutoDeBits; // fluxoBrutodeBits[]

    switch (tipoDeCodificacao) {
        case 0: // codificação Binária
            fluxoBrutoDeBits = CamadaFisicaTrasnmissoraCodificacaoBinaria(quadro);
            break;
        case 1: // codificação manchester
            fluxoBrutoDeBits = CamadaDeAplicacaoTransmissoraCodificacaoManchester(quadro);
            break;
        case 2: // codificação bipolar
            fluxoBrutoDeBits = CamadaDeAplicacaoTransmissoraBipolar(quadro);
            break;
    }
            MeioDeComunicacao(fluxoBrutoDeBits);
}


/* Este metodo simula a transmissão da informação no meio de comunicação, passando de um pontoA(transmissor) para um pontoB (receptor)
 * */


void CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[]){
    // implementação do algoritmo para decodificar
}

void CamadaDeAplicacaoReceptoraDecodificacaoManchester(int quadro []){
    // implementação do algoritmo para decodificar
}


void CamadaDeAplicacaoReceptoraDecodificacaoBipolar(int quadro []){
    // implementação do algoritmo para decodificar
}

/* ------------AplicacaoReceptora--------------*/

void AplicacaoReceptora(string mensagem){
    cout << "A mensagem recebida foi:" << mensagem << endl;
}

/* ------------CamadaDeAplicacaoReceptora--------------*/
void CamadaDeAplicacaoReceptora (int quadro []){

    // string mensagem = quadro [];

    //chama a próxima camada
    AplicacaoReceptora(mensagem);
}

void   CamadaFisicaReceptora(int quadro []){
    int tipoDeDecodificacao = 0; // altera de acordo com o teste
    int fluxoBrutoDeBits; // trabalhar com bits []

    switch (tipoDeDecodificacao) {
        case 0: // codificação Binária
            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBinaria(quadro);
            break;
        case 1: // codificação manchester
            fluxoBrutoDeBits = CamadaDeAplicacaoReceptoraDecodificacaoManchester(quadro);
            break;
        case 2: // codificação bipolar
            fluxoBrutoDeBits = CamadaDeAplicacaoReceptoraDecodificacaoBipolar(quadro);
            break;
    }
    // chama a próxima camada
    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}


