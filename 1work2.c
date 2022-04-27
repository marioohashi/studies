#include <stdio.h>
#include <stdlib.h>

void comandoBreak()
{
    printf("Exemplo de utilização do comando break.\nInterrompendo o comando while\n");
    int NUM = 0;
    while (NUM < 5)
    {
        printf("Número %d\n", NUM);
        NUM++;
        if (NUM == 4)
        {
            break; // Com a utilização do comando break sairemos do laço e será impresso apenas os número 1, 2 e 3;
        };
    }
}

int SOMAR(int n1, int n2)
{
    int soma;
    soma = n1 + n2;
    return (soma); //Exemplo do uso do comando return
}

void comandoReturn()
{
    printf("Exemplo comando return\n");
    int num1, num2, resultado;
    printf("Somatório de dois número: \nDigite o primeiro número\n");
    scanf("%d", &num1);
    printf("Digite o segundo número\n");
    scanf("%d", &num2);
    resultado = SOMAR(num1, num2);
    printf("A soma foi %d\n", resultado);
}

void comandoContinue()
{
    printf("Exemplo de utlização do comando continue\n");
    printf("Imprimir os números ímpares de 1 a 10\n\n");
    int i;
    for (i = 1; i < 6; i++)
    {
        if (i % 2 == 0)
        {
            continue; //pula o laço caso os números sejam pares
        }
        else
        {
            printf("Número: %d é impar\n", i);
        }
    }
}

void comandoGoTo()
{
    printf("Exemplo de utlização do comando goto\n");
    int numero1 = 0;
    int numero2 = 5;
    while (numero2 > numero1)
    {
        printf("%d é maior que %d\n", numero2, numero1);
        if (numero1 == 3)
        {
            goto AVISO;
        }
        numero1++;
    }
AVISO:
    printf("\nE 3 é o número mágico...\n\n");
}

void comandoExit()
{
    printf("Exemplo de utlização do comando exit\n\nVocê retornará para o sistema operaacional\n\n");
    exit(0);
}

int main()
{
    int FUNCAO = 1;
    while (FUNCAO != 6)
    {
        printf("Selecione uma opção abaixo:\n");
        printf("\t1 - exemplo de comando break\n");
        printf("\t2 - exemplo de comando continue\n");
        printf("\t3 - exemplo de comando return\n");
        printf("\t4 - exemplo de comando goto\n");
        printf("\t5 – exemplo de função exit\n");
        printf("\t6 – sair\n");
        scanf("%d", &FUNCAO);
        switch (FUNCAO)
        {
        case 1:
            comandoBreak();
            break;
        case 2:
            comandoContinue();
            break;
        case 3:
            comandoReturn();
            break;
        case 4:
            comandoGoTo();
            break;
        case 5:
            comandoExit();
            break;
        case 6:
            printf("Encerrando programa\n");
            break;
        default:
            printf("Voce selecionou uma opcao invalida\n");
        }
    }
    return 0;
}