#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void tela_boas_vindas() {
    system("cls");
    printf("\t\t\t\t=========================================\n");
    printf("\t\t\t\t\t   Trabalho do Przysiada       \n");
    printf("\t\t\t\t=========================================\n");
    printf("\nEste programa executa instruções de tipo R, I, J de MIPS!\n");
    printf("Digite instruções como ADD, SUB, MUL, REM, DIV ou outras.\n");
    printf("\nPressione ENTER para continuar...\n");
    getchar();
    system("cls");
}

void writeback(int r1, const char *nomer1, int *s, int *t) {
    if (nomer1[1] == 's') {
        s[nomer1[2] - '0'] = r1;
    } else if (nomer1[1] == 't') {
        t[nomer1[2] - '0'] = r1;
    }
}

void execute(int func, int r2, int r3, const char *nomer1, int *s, int *t, int *sp) {
    int r1 = 0;

    switch (func) {
        case 0: r1 = r2 + r3; break;
        case 1: r1 = r2 - r3; break;
        case 2: r1 = r2 * r3; break;
        case 3:
            if (r3 != 0) {
                r1 = r2 / r3;
            } else {
                printf("Erro: divisão por zero!\n");
                return;
            }
            break;
        case 4: r1 = r2 % r3; break;
        case 5: r1 = abs(r2 + r3); break;
        case 6: r1 = r2; break;
        case 7:
            if (nomer1[1] == 's') {
                *sp = s[nomer1[2] - '0']; 
            } else if (nomer1[1] == 't') {
                *sp = t[nomer1[2] - '0']; 
            } else {
                printf("Erro: registrador inválido para JR!\n");
                return;
            }
            printf("SP ajustado para %d\n", *sp);
            return; 
        default:
            printf("Erro: função inválida!\n");
            return;
    }

        writeback(r1, nomer1, s, t);
}

void decode(const char *func, const char *r1, const char *r2, const char *r3, int *s, int *t, int *sp) {
    const char *funcoesR[] = {"ADD", "SUB", "MUL", "DIV", "REM", "ADDU"};
    int cont = -1, reg2 = 0, reg3 = 0, i;

    for (i = 0; i < 6; i++) {
        if (strcmp(func, funcoesR[i]) == 0) {
            cont = i;
            break;
        }
    }

    if (cont == -1) {
        if (strcmp(func, "ADDI") == 0) {
            reg2 = (r2[1] == 's') ? s[r2[2] - '0'] : t[r2[2] - '0'];
            reg3 = atoi(r3);
            cont = 0;
        } else if (strcmp(func, "JR") == 0) {
            cont = 7;
        } else {
            printf("Erro: função não reconhecida!\n");
            return;
        }
    } else {
        reg2 = (r2[1] == 's') ? s[r2[2] - '0'] : t[r2[2] - '0'];
        reg3 = (r3[1] == 's') ? s[r3[2] - '0'] : t[r3[2] - '0'];
    }

    execute(cont, reg2, reg3, r1, s, t, sp);
}

void fetch(char *func, char *r1, char *r2, char *r3, int *s, int *t, int *sp) {
    printf("\nDigite a instrução (ex: ADD $s1, $s2, $s3):\n");
    scanf("%s", func); 
    
    if (strcmp(func, "0") == 0) {
            printf("Encerrando o programa...\n");
            exit(0); 
    }

    if (strcmp(func, "JR") != 0) {
        scanf("%s %s %s", r1, r2, r3);
    } else {
        scanf("%s", r1); 
    }

    int i;
    for (i = 0; func[i]; i++) func[i] = toupper(func[i]); 
    decode(func, r1, r2, r3, s, t, sp);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int s[] = {0, 1, 2, 3, 4, 5, 6, 7}, t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, sp = 0;
    char func[20], r1[20], r2[20], r3[20];
    tela_boas_vindas();

    while (1) {
        int i;
        printf("\nRegistradores:\n");
        for (i = 0; i < 8; i++) printf("S%d:%d   ", i, s[i]);
        printf("\n");
        for (i = 0; i < 10; i++) printf("T%d:%d   ", i, t[i]);
        printf("\nSP: %d\n", sp);

        fetch(func, r1, r2, r3, s, t, &sp);
    }
    return 0;
}
