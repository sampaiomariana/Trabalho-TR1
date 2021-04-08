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
    // A função esta decodificando de binário para decimal e decimal para char seguindo a tabela ASCII

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

    for (i = 0; i < tamanho_string; i++){
    cout << "Digite o código binário que foi obtido  " << endl;
    scanf("%d", &numero);
       
      while (numero > 0) {
            digito = numero % 10;
            if (digito == 1)
                resultado = resultado + vetor[posicao];
            posicao++;
            numero = numero / 10;
            }        
    
      // Agora, passando do decimal para string e mostrando para o usuário
        // A leitura é permitida apenas por caracter

        printf("O resultado em decimal eh : %d \n",resultado);
        printf("O resultado em ANSII eh : %c\n", char (resultado));
}

}

int BitXnor (int a, int b) {
      int resultante;
      resultante = !(a^b);
      return resultante;
}


int CamadaDeAplicacaoReceptoraDecodificacaoManchester(){

    int* manchester;
    int size_manchester;
    int size;

    int quadro[size_manchester/2];

    int i;

    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;

    // Passegm de clock considerando que ele comece em zero
    for (i = 0; i <size_manchester/2; i++){
        quadro[i] = BitXnor(manchester[2*i], 0);
    }

    cout << endl;

     for (i = 0; i < size_manchester/2; i++){
        cout << quadro[i];
     }
   
    cout << "A mensagem decofificada eh: \n" << quadro[i] << endl;

    cout << endl;


}

int CamadaDeAplicacaoReceptoraDecodificacaoBipolar(){

}

void CamadaFisicaReceptora(){
    //int size;
    //int quadro [size];
    int fluxoBrutoDeBits;
    //int tipoDeDeCodificacao;
    int tipoDeDeCodificacao;

    cout << "\nDigite qual a decodificação você escolhe:\n 0 - Binária \n 1 - Manchester\n 2 - Bipolar\n";
    cin >> tipoDeDeCodificacao;

   /* while (tipoDeDeCodificacao != 0 && tipoDeDeCodificacao != 1 && tipoDeDeCodificacao != 2) {
        cout << "Selecione uma opção válida." << endl;
        cout << "\nDigite qual a codificação você escolhe:\n 0 - Binária \n 1 - Manchester\n 2 - Bipolar\n";
        cin >> tipoDeDeCodificacao;
    }*/
    

    switch (tipoDeDeCodificacao) {
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

   // CamadaDeAplicacaoReceptora();
}



void MeioDeComunicacao (){
    // Nessa camada deve ocorrer a transmissão do fluxo de bits do ponto A para o ponto B
    // Considerando tamanho máximo do fluxo de bits como size
    
    
    int size;
    int tipoDeCodificacao;

    int fluxoBrutoDeBits[size];
    int fluxoBrutoDeBitsPontoA[size];
    int fluxoBrutoDeBitsPontoB[size];
    int i;

    cout << "Fluxo de bits de A eh: \n";
    for (i = 0; i < size; i++){
        fluxoBrutoDeBitsPontoA[i] = fluxoBrutoDeBitsPontoB[i];
        cout << fluxoBrutoDeBitsPontoA[i];
    }
    cout << endl;

    cout << "O fluxo de bits em B eh: \n";
    for (i = 0; i < size; i++){
        fluxoBrutoDeBitsPontoB[i] =  fluxoBrutoDeBitsPontoA[i];
        cout << fluxoBrutoDeBitsPontoB[i];
        // Os bits sendo transferidos do Ponto A para o ponto B
    }

    cout << endl;
    // realizar a chamada da próxima camada
   
    
    CamadaFisicaReceptora();

   /* int tipoDeDeCodificacao;

        switch (tipoDeDeCodificacao){
        case 0:
        CamadaFisicaReceptora();
        break;
        case 1:
        CamadaFisicaReceptora();
        break;
        case 2:
        CamadaFisicaReceptora();
        break;
    }*/
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
    // Codificação Manchester 
   

    int i;
    int* quadro;
    int size;

    int manchester[2*size];
    
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;

     // Passegm de clock considerando que ele comece em zero
    for (i = 0; i < size; i++){
        manchester[2*i] = BitXnor (0,quadro[i]);
        manchester[2* i +1] = BitXnor(1,quadro[i]);
    }

    // size foi definido como um inteiro mas sem nenhum valor especifico 
    
   for (i = 0; i < 2*size; i++){
        //cout << manchester[i];
        
    }
    cout << "A mensagem com a Codificação Manchester eh :\n" << manchester[i] << endl;   
    cout << endl;

     MeioDeComunicacao();
}

void CamadaDeAplicacaoTransmissoraBipolar(){
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
}

void CamadaFisicaTrasnmissora( int quadro) {
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

   // MeioDeComunicacao();
}


void CamadaDeAplicacaoTransmissora(int mensagem){
    // int quadro [] = mensagem -> usado apenas na camada de enlace
     int quadro =  mensagem;
    //chama a próxima camada
    CamadaFisicaTrasnmissora(quadro);
}


void AplicacaoTransmissora(void){
   int mensagem;
    // chama a próxima camada
    CamadaDeAplicacaoTransmissora(mensagem);

}

void AplicacaoReceptora(){
    int tipoDeCodificacao;

    cout << "Tipo de Decodificação" << endl;
    cin >> tipoDeCodificacao;

    while (tipoDeCodificacao != 0 && tipoDeCodificacao != 1 && tipoDeCodificacao != 2) {
        cout << "Selecione uma opção válida." << endl;
        cout << "\nDigite qual a codificação você escolhe:\n 0 - Binária \n 1 - Manchester\n 2 - Bipolar\n";
        cin >> tipoDeCodificacao;
    }
     // cout << "A mensagem recebida foi:\n";
    switch(tipoDeCodificacao){
         case 0: 
          CamadaFisicaReceptoraDecodificacaoBinaria();
         break;
         case 1:
          CamadaDeAplicacaoReceptoraDecodificacaoManchester();   
         break;  
    }
   
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
    AplicacaoReceptora();
}
