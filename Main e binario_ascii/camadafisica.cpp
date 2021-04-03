//
// Created by mariana on 03/04/2021.
//
#include <iostream>

using namespace std;

void binario_ascii(){
    char mensagem;
    cout << "Digite uma mensagem\n" << mensagem << endl;
    cin >> mensagem;

    cout << "\nValor na tabela ASCII:\n " << dec << int(mensagem);
    cout << "\nValor na tabela ASCII:\n " << hex << int(mensagem);
    

}
void  CamadaFisicaTrasnmissoraCodificacaoBinaria(int quadro[]){

}

void CamadaDeAplicacaoTransmissoraCodificacaoManchester(int quadro[]){

}

void CamadaDeAplicacaoTransmissoraBipolar(int quadro[]){

}
void CamadaFisicaTrasnmissora( int quadro[] ) {
    int tipoDeCodificacao;  // alterar de acordo com o teste
    int fluxoBrutoDeBits; // fluxoBrutodeBits[]
    int size;
    // Definindo um tamanho para o quadro

    cout << "\nDefinindo o tamanho do quadro que será recebido: \n" << size <<endl;

    cout << "\nDigite qual a codificação você escolhe:\n 0 - Binária \n 1 - Manchester\n 2 - Bipolar\n";
    cin >> tipoDeCodificacao;

    while (tipoDeCodificacao != 0 && tipoDeCodificacao != 1 && tipoDeCodificacao != 2) {
        cout << "Selecione uma opção válida." << endl;
        cout << "\nDigite qual a codificação você escolhe:\n 0 - Binária \n 1 - Manchester\n 2 - Bipolar\n";
        cin >> tipoDeCodificacao;
    }

    switch (tipoDeCodificacao) {
        case 0: // codificação binária
            CamadaFisicaTrasnmissoraCodificacaoBinaria(quadro);
            break;
        case 1: // codificação Manchester
            CamadaDeAplicacaoTransmissoraCodificacaoManchester(quadro);
            break;
        case 2: // codificação bipolar
            CamadaDeAplicacaoTransmissoraBipolar(quadro);
            break;

    }

}