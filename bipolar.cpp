#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cmath>
#include <string>
#include <algorithm>
#include "camadafisica.h"

#define TAMANHO_VETOR 7
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
	//CamadaFisicaTrasnmissoraCodificacaoBinaria();
	 // A mensagem é codificada por desnível entre 0 e 1
    // 0 -> 0 = 0
    // 0 -> 1 = 1
    // 1 -> 1 = -1
	
	string mensagem;

	cout << "Digite uma mensagem em binário:" << endl;
    cin >> mensagem;
   

    cout << "A mensagem digitada em bipolar eh :\n";
    int i;
    int nivelnegativo = -1;
    int aux;
    int nivelneutro = 0;
    int nivelpositivo = 1;

    for (i = 0; i < TAMANHO_VETOR; i++)

    		if (mensagem[i] > mensagem[nivelneutro]){
    			nivelneutro = nivelpositivo;
    			cout << " ";	
    			cout << "1";

    			
    		} else if (mensagem[i] = mensagem[i]){

    			nivelneutro = nivelnegativo;
    			mensagem[i] >= (1 << i);
    			mensagem[i] = mensagem[i] - (1 << i);
    			cout << " ";	
    			cout << "0";

    			} if (mensagem[i] = mensagem[nivelpositivo]){

    				nivelnegativo = nivelneutro;
    				cout << " ";
    				cout << "-1";
    			}


    		cout << "\n";   



		/*for (i = 0; i < mensagem[i]!= '\0'; i++){
        int aux;
        aux = mensagem[i];
        int j;
        for (j = 7; j + 1 > 0; j--){
            if (aux >= (1 << j)){
                aux = aux - ( 1 << j);
                cout << "0";
            } else {
                cout << "1";
            }

        }
        cout << " ";
    }
    cout << "\n";*/


}






int main (){
	//CamadaFisicaTrasnmissoraCodificacaoBinaria();
	CamadaDeAplicacaoTransmissoraBipolar();

}