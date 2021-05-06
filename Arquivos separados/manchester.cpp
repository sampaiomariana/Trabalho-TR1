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

int BitXnor (int a, int b) {
   // a string a corresponde a entrada de bits 
   // a string b corresponde a entrada do clock
    int resultante;
  /* string resultante = "";
   int i;
   for (i = 0; i < a.size(); i++){
    if (a[i] == b[i])
        resultante += '0';
    else 
        resultante += '1';
   }
    
   return resultante;*/
    // XNOR 
    resultante = !(a^b);
    return resultante;
}

void CamadaDeAplicacaoTransmissoraCodificacaoManchester(){
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
    // Codificação Manchester 
   
    
    int i;
    int* quadro;
    int size;
    //int clock[2*tamanho_quadro];    
    
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
    cout << "A mensagem com a Codificação Manchester eh :\n" << manchester[i] << endl;
   for (i = 0; i < 2*size; i++){
        //cout << manchester[i];
    cout << endl;

    
    }
}

    // Chama para realizar a operação XOR que deve ocorrer entre o fluxo de bits e o clock
    // Configurando o quadro, considerando que ele inicie em zero.
    
   /* for (i = 0; i < tamanho_quadro; i++){
        manchester[2*i] = BitXor (0,quadro[i]);
        manchester[2* i +1] = BitXor(1,quadro[i]);
    }
    string a,b;
    BitXor(a,b);
    cout << "Digite uma mensagem: \n";  
    cin >> a;
    cout << "Digite o clock: \n";
    cin >> b;
    cout << "Resultado da operação XOR eh: \n";
    cout << BitXor(a,b) << endl;
    */
    
   
void CamadaFisicaReceptoraDecodificacaoManchester(){
    int* manchester;
    int size_manchester;

    int quadro[size_manchester/2];

    int i;

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
int main (){
    
    CamadaDeAplicacaoTransmissoraCodificacaoManchester();
    CamadaFisicaReceptoraDecodificacaoManchester();

    return 0;

}