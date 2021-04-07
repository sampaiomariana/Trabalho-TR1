//
// Created by mariana on 03/04/2021.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cmath>
#include <string>
#include <algorithm>
#include "camadafisica.h"

using namespace std;

int CamadaFisicaReceptoraDecodificacaoBinaria() {
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
    // A decodificação binária deve receber o código binário e conseguir decodificar o binário em string

    cout << "Decodificação: " << endl;

    // Binário para decimal 

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

    CamadaDeAplicacaoReceptora();
}



void MeioDeComunicacao (){
    // Nessa camada deve ocorrer a transmissão do fluxo de bits do ponto A para o ponto B
    // Considerando tamanho máximo do fluxo de bits de 100
    int fluxoBrutoDeBits;
    int fluxoBrutoDeBitsPontoA[100];
    int fluxoBrutoDeBitsPontoB[100];

    fluxoBrutoDeBitsPontoA[100] = fluxoBrutoDeBitsPontoB[100];

    while (fluxoBrutoDeBitsPontoB[100] != fluxoBrutoDeBitsPontoA[100]){
        fluxoBrutoDeBitsPontoB[100] += fluxoBrutoDeBitsPontoA[100];
    }

    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB[100]);
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

int BitXor (int n, int m){
    return !(n ^ m);
}

void CamadaDeAplicacaoTransmissoraCodificacaoManchester(){
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
    // Codificação Manchester 

    int i;
    int tamanho_bit;
    int* quadro;

    string mensagem;
    cout << "Digite o fluxo de bits :" << endl;
    cin >> mensagem;


    int codificacao_machester[2*tamanho_bit];

    for (i = 0; i < tamanho_bit;i++){
        codificacao_machester[2*i] = BitXor(0, quadro[i]);;
        codificacao_machester[2*i + 1] = BitXor(1, quadro[i]);
    }

    cout << "O fluxo de Bits na codificação Manchester eh: " << endl;

    for ( i = 0; i < 2*tamanho_bit; ++i)
    {
        cout << "codificação: " << codificacao_machester[i];
    }
    cout << endl;

   // MeioDeComunicacao();
}

void CamadaDeAplicacaoTransmissoraBipolar(){
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
}

void CamadaFisicaTrasnmissora( ) {
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
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

int conversor_binario_string (){
    char numero;
    int  binario = 0;

    do {
        cout << "Digite o número decimal que foi recebido";
        cin >> numero;

        if (numero == '0'){
            binario = binario *2;
        }

        else if (numero == '1'){
            binario = binario * 2 +1; 
        }

        else{
            cout << "\n";
        } 
        } while (numero == '0' || numero == '1');

         cout << "O valor recebido em decimal eh: " << binario << endl;
         cout << "O caracter recebido eh " << char(binario) << endl;

         return 0;

}


void CamadaDeAplicacaoReceptora(){
    int fluxoBrutoDeBits;
    
    //string mensagem = conversor_binario_string;
    string mensagem;
    // chama a proxima camada
    AplicacaoReceptora(mensagem);
}
