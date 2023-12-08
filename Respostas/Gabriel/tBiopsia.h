#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

typedef struct tBiopsia tBiopsia;

tBiopsia* criaBiopsia();

void desalocaBiopsia(tBiopsia* b);

void imprimeNaTelaBiopsia(tBiopsia* b);

void imprimeEmArquivoBiopsia(tBiopsia* b);

#endif