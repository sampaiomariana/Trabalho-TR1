
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "camadaenlace.h"
#include "camadafisica.h"


using namespace std;


void CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(int quadro[]){

	int i;
	int quantidade;
	int size;
	int new_size;
	quantidade = size/8;

	//cout << "Quantidade de caracteres" << endl;
	int quadro_invertido[8];

	new_size = size + 8;
	//Novo quadro recebe o tamanho no new_size;
	int novo_quadro[new_size];

	for (i = new_size-1; i > 0; i--){
		novo_quadro[i] = quadro[i - 8];
	}

	//Simulando os valores de i

	i = 0;

	while (quantidade > 0){
		quadro_invertido[i] = quantidade%2;
		quantidade = quantidade/2;
		i++;
	}

	if (i == 7){
		quadro_invertido[i] = 0;
		i++;
	}


	if (i == 6){
		for (i = 6; i < 8; i++)
		quadro_invertido[i] = 0;
	}


	if (i == 5){
		for (i = 5; i < 8; i++)
		quadro_invertido[i] = 0;
	}


	if (i == 4){
		for (i = 4; i < 8; i++)
		quadro_invertido[i] = 0;
	}


	if (i == 3){
		for (i = 3; i < 8; i++)
		quadro_invertido[i] = 0;
	}

	if (i == 2){
		for (i = 2; i < 8; i++)
			quadro_invertido[i] = 0;
	}

	if (i == 1){
		for (i = 1; i < 8; i++)
			quadro_invertido[i] = 0;
	}

	cout << endl;

	int j = 0;
	i = 7;

	while (j < 8){
		novo_quadro[j] = quadro_invertido[i];
		j++;
		i--;
		
	}	
	
	cout << "\nEnquadramento por contagem de caracter:" << endl;
	cout << "\n" << endl;

	for (i = 0; i < new_size; i++){
		cout << novo_quadro[i];
	}
	
	cout << "\n"<< endl;
}

void CamadaEnlaceDadosTransmissora (int quadro[]){
	
	CamadaEnlaceDadosTransmissoraEnquadramento(quadro);
}

void CamadaEnlaceDadosTransmissoraEnquadramento(int quadro[]){
	int tipoDeEnquadramento;
	
		cout << "\n";
		cout << "\nTipo de Enquadramento: \n 0 - Contagem De Caracteres \n 1 - Inserção de Bytes\n ";
		cin >> tipoDeEnquadramento;
	
	switch (tipoDeEnquadramento){
		case 0: // contagem de caracteres
		CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro);
		break;
		
	}
}
