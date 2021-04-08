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
}



void CamadaDeAplicacaoTransmissoraBipolar(){

	// Deve ser feita a conversão para binário
	CamadaFisicaTrasnmissoraCodificacaoBinaria();
	string mensagem;
	int i = mensagem.size();
	int flag = 0;
	cout << "A mensagem codificada eh:";
	for (int j = 0; j < mensagem[i]; j++){
		if(mensagem[i] == '0'){
			cout << '0';

		} else if (mensagem[i] == '1'){
			
			if (flag == 0){
				flag = 1;
				cout << '1';
			} else {
				flag = 0;
				cout << '1';
			}

			}
	}

	
	cout << "\n";

}



int main (){

	CamadaDeAplicacaoTransmissoraBipolar();

}