//
// Created by mariana on 03/04/2021.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cmath>
#include <algorithm>
#include "camadafisica.h"

using namespace std;

void CamadaFisicaReceptoraDecodificacaoBinaria() {
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
    // A decodificação binária deve receber o código binário e conseguir decodificar o binário em string

    cout << "Decodificação: " << endl;
    int codigo_binario;
    string mensagem;
    // Deve ser feita a decodificação de binário para decimal

    int numero, digito;
    int posicao = 0;
    int resultado = 0;

    int vetor[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    int tamanho_string;
    cout << "Tamanho da string: \n";
    cin >> tamanho_string;

    int i, j;


    for (j = 0; j < tamanho_string; j++){
        cout << "Digite o código binário que foi obtido" << endl;
        scanf("%d", &numero);
        //cin >> codigo_binario;

 }
        while (numero > 0) {
            digito = numero % 10;
            if (digito == 1)
                resultado = resultado + vetor[posicao];
            posicao++;
            numero = numero / 10;
        }

        // Agora, passando do decimal para string e mostrando para o usuário
        // A leitura é permitida apenas por caracter

        printf("O resultado em decimal eh : %d \n", resultado);
        printf("O resultado em ANSII eh : %c\n", resultado);
    }


void CamadaDeAplicacaoReceptoraDecodificacaoManchester(){

}

void CamadaDeAplicacaoReceptoraDecodificacaoBipolar(){

}

void CamadaFisicaReceptora( int fluxoBrutoDeBitsPontoB){
    int tipoDeCodificacao;

    switch (tipoDeCodificacao) {
        case 0: // codificação binária
            CamadaFisicaReceptoraDecodificacaoBinaria();
            break;
        case 1: // codificação Manchester
            CamadaDeAplicacaoReceptoraDecodificacaoManchester();
            break;
        case 2: // codificação bipolar
            CamadaDeAplicacaoReceptoraDecodificacaoBipolar();
            break;

    }
}



void MeioDeComunicacao (){
    // Nessa camada deve ocorrer a transmissão do fluxo de bits do ponto A para o ponto B
    int fluxoBrutoDeBits;
    int fluxoBrutoDeBitsPontoA;
    int fluxoBrutoDeBitsPontoB;

    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBitsPontoB;

    while (fluxoBrutoDeBitsPontoB != fluxoBrutoDeBitsPontoA){
        fluxoBrutoDeBitsPontoB += fluxoBrutoDeBitsPontoA;
    }

    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

void  CamadaFisicaTrasnmissoraCodificacaoBinaria(){
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;
    cout << "A mensagem digitada em binário eh :\n";
    int i;
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
        cout << " ";
    }
    cout << "\n";

    MeioDeComunicacao();
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


void CamadaDeAplicacaoTransmissora(string mensagem){
    // int quadro [] = mensagem -> usado apenas na camada de enlace

    //chama a próxima camada
    CamadaFisicaTrasnmissora();
}


void AplicacaoTransmissora(void){
    string mensagem;
    // chama a próxima camada
    CamadaDeAplicacaoTransmissora(mensagem);

}

void AplicacaoReceptora(string mensagem){
    cout << "A mensagem recebida foi:" << mensagem << endl;
}

void CamadaDeAplicacaoReceptora(){
    string mensagem;
    AplicacaoReceptora(mensagem);
}
