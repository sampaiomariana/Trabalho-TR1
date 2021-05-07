
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "camadaenlace.h"
#include "camadafisica.cpp"


using namespace std;

/*Considerando size = 32*/

void CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(int quadro[]){

	int i;
	int quantidade;
	int size = 32;
	int new_size;
	quantidade = size/8;

	int quadro_invertido[8];

	new_size = size + 8;
	//Novo quadro recebe o tamanho no new_size;
	int novo_quadro[new_size];

	for (i = new_size-1; i > 1; i--){
		novo_quadro[i] = quadro[i - 8];
	}

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

	//chama a próxima camada
	CamadaEnlaceDadosReceptora(quadro);
}
void CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(int quadro[]){
	// implmentação da inserção de bytes 
	int flag_bytes[] = {0,0,1,0,0,0,1,1}; // Considerando a flag == # -dec == 35 -bin== 00100011
	int flag_esc[] = {0,0,0,0,0,0,0,0,0}; // referente ao byte de escape
	//É necessário percorrer pelo quadro para encontrar a flag

	int i;
	int size = 32;
	int qtd_flag = 0;

	for ( i = 0; i < size - 8; i++ ){
		if (flag_bytes){
			qtd_flag++;
			i = i + 8;
		}
	}
	int new_size = size + 8*qtd_flag + 16;
	int novo_quadro[new_size];
	

	cout << "Inserção de bytes";
	cout << "\n";
	cout << "Flag:";
	cout << "\n";
	

	for (i = 0; i < 8; i++)
		cout << flag_bytes[i];
	cout << "\n";
	cout << "Quadro:";
	cout << "\n";
	for (i = 0; i < new_size; i++)
		cout << novo_quadro[i];
	cout << "\n";


	//chama a próxima camada
	CamadaEnlaceDadosReceptora(quadro);

}

void CamadaDeEnlaceTransmissoraControleDeErro(int quadro[]){
	int tipoDeControleDeErro;


}
void CamadaEnlaceDadosTransmissora (int quadro[]){
	
	CamadaEnlaceDadosTransmissoraEnquadramento(quadro);

	//próxima camada 

	CamadaDeEnlaceTransmissoraControleDeErro(quadro);

	//próxima camada

	//CamadaFisicaTransmissora();
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
		case 1:
		CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro);
		break;
		
	}
}
/*Desenquadramento*/

void CamadaEnlaceDadosReceptoraDesenquadramentoContagemDeCaracteres(int quadro[]){
	//implemente o código

	int i;
	int size = 32;
	int aux;
	int novo_quadro[size - 8];
	aux = novo_quadro[size - 8];
	cout <<"\n Quadro Desenquadrado:";
	cout << "\n";

	for (i = 1; i < size - 8; i++){
		aux = quadro[i + 7];
		cout << aux;
	}

	cout << "\n";

	//chama a próxima camada

}

void CamadaEnlaceDadosReceptoraDesenquadramentoInsercaoDebytes(int quadro[]){

	//para desenquadrar foi implementado o inverso do enquadramento

	int flag_bytes[] = {0,0,1,0,0,0,1,1}; // Considerando a flag == # -dec == 35 -bin== 00100011
	int flag_esc[] = {0,0,0,0,0,0,0,0,0}; // referente ao byte de escape

	int i;
	int size = 32;
	int qtd_flag = 0;

	for ( i = 0; i < size - 8 ; i++ ){
		if (flag_bytes){
			qtd_flag++;
			i = i + 8;
		}
	}
	int new_size = size  + 8*qtd_flag - 16;
	int novo_quadro[new_size];


	cout << "Inserção de bytes";
	cout << "\n";
	cout << "Flag:";
	cout << "\n";
	

	for (i = 0; i < 8; i++)
		cout << flag_bytes[i];
	cout << "\n";
	cout << "Quadro Desenquadrado:";
	cout << "\n";
	for (i = 0; i < new_size; i++)
		cout << novo_quadro[i];
	cout << "\n";

	// chama a próxima camada
}

void CamadaEnlaceDadosReceptoraEnquadramento(int quadro[]){
	/*Realiza a chamada para o tipo de desenquadramento*/
	int tipoDesenquadramento;
	
		cout << "\n";
		cout << "\nTipo de Desenquadramento: \n 0 - Contagem De Caracteres \n 1 - Inserção de Bytes\n ";
		cin >> tipoDesenquadramento;
	
	switch (tipoDesenquadramento){
		case 0: // contagem de caracteres
		CamadaEnlaceDadosReceptoraDesenquadramentoContagemDeCaracteres(quadro);
		break;
		case 1:
		CamadaEnlaceDadosReceptoraDesenquadramentoInsercaoDebytes(quadro);
		break;

		}
}


void CamadaEnlaceDadosReceptora(int quadro[]){
//implemente o código
	//chama a próxima camada
	CamadaEnlaceDadosReceptoraEnquadramento(quadro);

	//chama a próxima camada
	//CamadaEnlaceReceptoraControleDeErro(quadro);

	//chama a próxima camada

	//CamadaDeAplicacaoReceptora(quadro);
}

