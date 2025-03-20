#include "libsample.h"
#include <stdlib.h>
#include <string.h>


// Implementação da função soma
int soma(int a, int b) {
    return a + b;
}

// Implementação da função divide
float divide(int a, int b) {
    if (b == 0) {
        return -1; // Retorna -1 em caso de divisão por zero
    }
    return (float)a / b;
}

// Implementação da função concatena
char* concatena(const char* str1, const char* str2) {
    char* resultado = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    if (resultado == NULL) {
        return NULL; // Falha na alocação de memória
    }
    strcpy(resultado, str1);
    strcat(resultado, str2);
    return resultado;
}

// Implementação da função deve_falhar
int deve_falhar() {
    int* ptr = NULL;
    *ptr = 42; // Força um segmentation fault
    return 1;
}
