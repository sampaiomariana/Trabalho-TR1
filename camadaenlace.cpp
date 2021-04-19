
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "camadaenlace.h"
#include "camadafisica.h"


using namespace std;



void CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres( int quadro){

}

void CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(int quadro){

}

void CamadaEnlaceDadosTransmissoraEnquadramento(int quadro){
	int tipoDeEnquadramento = 0;
	int quadroEnquadrado [3];

	switch (tipoDeEnquadramento){
		case 0: // contagem de caracteres
		quadroEnquadrado = CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro);
		break;
		case 1:	// contagem de bytes
		quadroEnquadrado=  CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro);
		break;
	}
}
 

int CamadaEnlaceDadosTransmissora (int quadro){
	
	CamadaEnlaceDadosTransmissoraEnquadramento(quadro);

}

    
