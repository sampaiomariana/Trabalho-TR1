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

string  BitXor (string a, string b) {
   // a string a corresponde a entrada de bits 
   // a string b corresponde a entrada do clock

   string resultante = "";
   int i;

   for (i = 0; i < a.size(); i++){
    if (a[i] == b[i])
        resultante += '0';
    else 
        resultante += '1';
   }

   return resultante;

}

void CamadaDeAplicacaoTransmissoraCodificacaoManchester(){
    // int quadro[] deve ser utilizado apenas para a camada de enlace.
    // Codificação Manchester 

    string a,b;
    cout << "Digite uma mensagem: \n";  
    cin >> a;
    cout << "Digite o clock: \n";
    cin >> b;
    cout << "Resultado da operação XOR eh: \n";
    cout << BitXor(a,b) << endl;

   }

int main (){
    
    CamadaDeAplicacaoTransmissoraCodificacaoManchester();
  

    return 0;

}