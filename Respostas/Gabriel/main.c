#include <stdio.h>
#include "tSistema.h"

int main(int argc, char **argv)
{
    const char* caminhoConfig = argv[1];
    Sistema(caminhoConfig);
    return 0;
}