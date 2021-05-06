#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cmath>
#include <string>
#include <algorithm>
//#include "camadafisica.h"

#define TAMANHO_VETOR 8
using namespace std;

int CamadaDeAplicacaoTransmissoraBipolar(){

	// Deve ser feita a conversão para binário
	//CamadaFisicaTrasnmissoraCodificacaoBinaria();
	 // A mensagem é codificada por desnível entre 0 e 1
    // 0 -> 0 = 0
    // 0 -> 1 = 1
    // 1 -> 1 = -1/0
	
    string mensagem;

	cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;
   

    cout << "A mensagem digitada em bipolar eh :";
    int i;
    int nivelnegativo = -1;
    int aux0, aux1,aux2;
    int nivelneutro = 0;
    int nivelpositivo = 1;

            
            /*for (i =0; i < mensagem.length(); i++){
               // mensagem[i] = 0;
            }*/
            //for (i = 0; i < mensagem.length(); i++)
            //mensagem[i] > mensagem[nivelneutro]
            if (mensagem[i] > mensagem[nivelneutro]){
                nivelneutro = nivelpositivo;
               // cout << " ";    
                cout << "1";
                nivelneutro = 1;
                
              //else if (mensagem[i] == mensagem[i] || mensagem[i] == 0 || mensagem[i] == 1)  
            } else if ( mensagem[i] == mensagem[i]){

                 nivelneutro = nivelnegativo;
                 mensagem[i] >= (1 << i);
                 mensagem[i] = mensagem[i] - (1 << i);
                //cout << " ";    
                cout << "0";
                nivelneutro = 0;
                
                //mensagem[i] ==  mensagem[i]  && mensagem[i] == 1
                } 
            if (mensagem[i] ==  mensagem[i]  && mensagem[i] == 1 ){

                    //nivelnegativo  = nivelneutro;
                    cout << " ";
                    cout << "-1";

                }
            
                cout << " ";
                cout << "\n";
            

     cout << "\nO valor tamanho da mensagem eh: " << mensagem.size() << endl;
}

int CamadaDeAplicacaoReceptoraDecodificacaoBipolar(){

    // 0 -> 0 = 0
    // 0 -> 1 = 1
    // 1 -> 1 = -1/0
    
    string mensagem;

    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;

    int i;
    int nivelnegativo = -1;
    int aux0, aux1,aux2;
    int nivelneutro = 0;
    int nivelpositivo = 1;

    // Inicializar 
    for (i = 0; i < mensagem.length(); i++){
        mensagem[i] = 0;
        mensagem[i+1] = 1;
    }

    cout << "A mensagem decodifica eh: ";

    if (mensagem[i] < mensagem[nivelneutro]){
                nivelneutro = nivelpositivo;
               // cout << " ";    
                cout << "0";
                nivelneutro = 1;
                
              //else if (mensagem[i] == mensagem[i] || mensagem[i] == 0 || mensagem[i] == 1)  
            } else if ( mensagem[i] != mensagem[i]){

                 nivelneutro = nivelnegativo;
                 mensagem[i] >= (1 << i);
                 mensagem[i] = mensagem[i] - (1 << i);
                //cout << " ";    
                cout << "1";
                nivelneutro = 0;
                
                //mensagem[i] ==  mensagem[i]  && mensagem[i] == 1
                } 
            if (mensagem[i] ==  mensagem[i]  && mensagem[i] == 1 ){

                    //nivelnegativo  = nivelneutro;
                    cout << " ";
                    cout << "1";

                }
            
                cout << " ";
                cout << "\n";
            

     cout << "\nO valor tamanho da mensagem eh: " << mensagem.size() << endl;

    
}


int main (){
	 //CamadaFisicaTrasnmissoraCodificacaoBinaria();
	 CamadaDeAplicacaoTransmissoraBipolar();
     CamadaDeAplicacaoReceptoraDecodificacaoBipolar();

    
}

