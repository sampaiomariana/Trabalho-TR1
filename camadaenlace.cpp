
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "camadaenlace.h"
#include "camadafisica.h"


using namespace std;

void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(int quadro[]){

	//cout << "Bit Paridade par";
	//cout << "\n";
	int size = 32;
	int bit = 0;
	// adiciona o novo bit no tamanho do quadro
	int aux[size + 1];
	int j = 0;
	
	for (int j = 0; j < size; j++){
		bit ^= quadro[j] & 1; //xor
		quadro[j] >>= 1;
		// Se o bit for 0 nada é alterado, se o bit for 1 altera entre 0 e 1
	}
	for (j = 0; j < size; j++){
		aux[j] = quadro[j];
	}
	aux[size] = bit;

	//chama a camada física
	CamadaFisicaTransmissora(quadro);
}

void CamadaEnlaceDadosTransmissoraControleDeErroCRC(int quadro[]){

	// usar polinomio CRC-32 (IEEE 802)
	int size = 4;
	int size_t = 8;
	int gerador[size];
	
	//definindo gerador para 1001
	gerador[0] = 1;
	gerador[1] = 0;
	gerador[2] = 0;
	gerador[3] = 1;
		
	int i;
	for (i = 5; i < size - 1; i++ ){
		gerador[i] = 0;
	}

	cout << "Quadro:" << endl;
	for (i = 1; i < size_t; i++){
		cout << quadro[i];
	}
	cout << "\n";
	cout << "Gerador:";
	for (i = 0; i < size; i++){
		cout << gerador[i];
	}

	cout << "\n";

	int j;
	int resto[size];
	for (j = 0; j < size; j++){
		if (resto[0] == 1){
			for (i = 0; i < size; i++){ //xor
				resto[j] ^= gerador[i];
			}
		}
	}
	
	int quadro_n = quadro[i] && gerador[size];

	cout << "Mensagem Transmitida:" << endl;
	// Dobrar o tamanho do size para que não tenha problema na divisão
	//Soma 3 considerando que o CRC seja 0000
	for (i = 0; i < 2*size + 3; i ++){
		cout <<  quadro_n;

	}

	cout << "\n";
	//chama a camada física

	CamadaFisicaTransmissora(quadro);

}

void CamadaDeEnlaceTransmissoraControleDeErro(int quadro[]){
	int tipoDeControleDeErro;


		cout << "\n";
		cout << "\nTipo de Controle de Erro: \n 0 - Bit Paridade Par \n 1 - CRC\n ";
		cin >> tipoDeControleDeErro;
	
	switch(tipoDeControleDeErro){
		case 0: CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro);
		break;
		case 1: CamadaEnlaceDadosTransmissoraControleDeErroCRC(quadro);
		break;
	}


}

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
	//próxima camada - controle de erro
	CamadaDeEnlaceTransmissoraControleDeErro(quadro);
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

	// próxima camada controle de erro
	CamadaDeEnlaceTransmissoraControleDeErro(quadro);
	//chama a próxima camada
	CamadaEnlaceDadosReceptora(quadro);

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

