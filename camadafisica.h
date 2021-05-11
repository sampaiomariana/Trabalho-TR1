//
// Created by mariana on 03/04/2021.
//
/* Todos as funções que têm no modelo a declaração de int quadro [] foram colocadas como comentário visto que
 * nesse trabalho será implementado apenas a camada física e esta trabalha com a conversão bit a bit.
 * */
#ifndef UNTITLED5_CAMADAFISICA_H
#define UNTITLED5_CAMADAFISICA_H

int CamadaFisicaReceptoraDecodificacaoBinaria();

int CamadaDeAplicacaoReceptoraDecodificacaoManchester();

int CamadaDeAplicacaoReceptoraDecodificacaoBipolar();

void CamadaFisicaReceptora();

void MeioDeComunicacao();

void  CamadaFisicaTrasnmissoraCodificacaoBinaria();

void CamadaDeAplicacaoTransmissoraCodificacaoManchester();

void CamadaDeAplicacaoTransmissoraCodificacaoBipolar();

void CamadaFisicaTransmissora(int quadro[]);

void CamadaDeAplicacaoTransmissora();

void AplicacaoTransmissora(void);

void AplicacaoReceptora();

void CamadaDeAplicacaoReceptora();


#endif //UNTITLED5_CAMADAFISICA_H
