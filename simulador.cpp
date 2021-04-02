/*Simulador que contém implementações das seguintes codificações:
 * Binária
 * Manchester
 * Bipolar
 * */

#include <iostream>
#include "camadafisica.cpp"

using namespace std;


/* ------------CamadaDeAplicacaoTransmissora--------------*/
void CamadaDeAplicacaoTransmissora(string mensagem){
    int quadro [] = mensagem;
    // chama a próxima camada
    CamadaFisicaTrasnmissora(quadro);
}
/* ------------AplicacaoTransmissora--------------*/
void AplicacaoTransmissora(void){

    string mensagem;
    cout << "Digite uma mensagem:\n" << endl;
    cin >> mensagem;

    CamadaDeAplicacaoTransmissora(mensagem);
}


/* ------------Chamada da Main AplicacaoTransmissora()--------------*/
int main(void) {
    // chamada da main
   // AplicacaoTransmissora();
    std::cout << "Hello, World!" << std::endl;
    return 0;

}