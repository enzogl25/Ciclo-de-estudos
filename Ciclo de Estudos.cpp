#include <stdio.h>
#include <windows.h>
#include <math.h>

float somadif(float *dif, int mat) {
    float sum = 0;

    for (int i = 0; i < mat; i++) {
        sum += dif[i];
    }
    return sum;
}

void resultados(float mid, float *dif, char nome[][50], int mat) {
    for (int i = 0; i < mat; i++) {
        float resultado = mid * dif[i];
        int resultadocima = ceil(resultado);
        int resultadoa = round(resultado);
        if (resultado > 1 && resultado < 2) {
            printf("%s : %d horas\n", nome[i], resultadocima);
        } 
        if (resultado >= 2) {
            printf("%s : %d horas\n", nome[i], resultadoa);
        }
    }
}

int main() {
    int materias, i;
    float hdia, soma, dificuldade[100], thoras, mid;
    char nome[100][50];

    printf("Quantas materias deseja adicionar?\n");
    scanf("%d", &materias);
    system("cls");

    for (i = 0; i < materias; i++) {
        printf("Nome da %d materia\n", i + 1);
        scanf(" %[^\n]", nome[i]);
        printf("Qual a sua dificuldade de 1 a 5\n");
        scanf("%f", &dificuldade[i]);
        system("cls");
    }

    printf("Qual seria sua quantidade de horas ideal de estudo por dia?\n");
    scanf("%f", &hdia);
    soma = somadif(dificuldade, materias);
    printf("%f\n", soma);
    thoras = hdia * 7;
    mid = thoras / soma;
    system("cls");
    resultados(mid, dificuldade, nome, materias);

    return 0;
}