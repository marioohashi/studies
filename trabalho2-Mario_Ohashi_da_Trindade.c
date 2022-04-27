/* 

LINGUAGEM DE PROGRAMAÇÃO ESTRUTURADA
Mario Ohashi da Trindade - 969338

O programa deverá ter um menu com as seguintes opções para o usuário:

    1- Escrever um número por extenso
    Essa opção solicitará para o usuário um número (no intervalo de 0 a
    9999,99) e o programa deverá imprimir o mesmo por extenso no
    arquivo. Um número não poderá sobrescrever o outro no arquivo.

    2- Imprimir todos os números do arquivo em tela
    Essa opção deverá ler todos os números salvos no arquivo e imprimir
    os mesmos em tela.

*/

#include <stdio.h>
#include <stdlib.h>

void escreveUnidade(int un)
{
    FILE *log;
    log = fopen("arquivo_log.txt", "a");
    switch (un)
    {
    case 1:
        printf("um");
        fprintf(log, "um");
        break;
    case 2:
        fprintf(log, "dois");
        printf("dois");
        break;
    case 3:
        fprintf(log, "três");
        printf("três");
        break;
    case 4:
        fprintf(log, "quatro");
        printf("quatro");
        break;
    case 5:
        fprintf(log, "cinco");
        printf("cinco");
        break;
    case 6:
        fprintf(log, "seis");
        printf("seis");
        break;
    case 7:
        fprintf(log, "sete");
        printf("sete");
        break;
    case 8:
        fprintf(log, "oito");
        printf("oito");
        break;
    case 9:
        fprintf(log, "nove");
        printf("nove");
        break;
    case 10:
        fprintf(log, "dez");
        printf("dez");
        break;
    case 11:
        fprintf(log, "onze");
        printf("onze");
        break;
    case 12:
        fprintf(log, "doze");
        printf("doze");
        break;
    case 13:
        fprintf(log, "treze");
        printf("treze");
        break;
    case 14:
        fprintf(log, "quatorze");
        printf("quatorze");
        break;
    case 15:
        fprintf(log, "quinze");
        printf("quinze");
        break;
    case 16:
        fprintf(log, "dezesseis");
        printf("dezesseis");
        break;
    case 17:
        fprintf(log, "dezessete");
        printf("dezessete");
        break;
    case 18:
        fprintf(log, "dezoito");
        printf("dezoito");
        break;
    case 19:
        fprintf(log, "dezenove");
        printf("dezenove");
        break;
    }
    fclose(log);
}

void escreveDezena(int dez)
{
    FILE *log;
    log = fopen("arquivo_log.txt", "a");
    switch (dez)
    {
    case 2:
        fprintf(log, "vinte");
        printf("vinte");
        break;
    case 3:
        fprintf(log, "trinta");
        printf("trinta");
        break;
    case 4:
        fprintf(log, "quarenta");
        printf("quarenta");
        break;
    case 5:
        fprintf(log, "cinquenta");
        printf("cinquenta");
        break;
    case 6:
        fprintf(log, "sessenta");
        printf("sessenta");
        break;
    case 7:
        fprintf(log, "setenta");
        printf("setenta");
        break;
    case 8:
        fprintf(log, "oitenta");
        printf("oitenta");
        break;
    case 9:
        fprintf(log, "noventa");
        printf("noventa");
        break;
    }
    fclose(log);
}

void escreveCentena(int centena)
{
    FILE *log;
    log = fopen("arquivo_log.txt", "a");
    switch (centena)
    {
    case 1:
        fprintf(log, "cento");
        printf("cento");
        break;
    case 2:
        fprintf(log, "duzentos");
        printf("duzentos");
        break;
    case 3:
        fprintf(log, "trezentos");
        printf("trezentos");
        break;
    case 4:
        fprintf(log, "quatrocentos");
        printf("quatrocentos");
        break;
    case 5:
        fprintf(log, "quinhentos");
        printf("quinhentos");
        break;
    case 6:
        fprintf(log, "seiscentos");
        printf("seiscentos");
        break;
    case 7:
        fprintf(log, "setecentos");
        printf("setecentos");
        break;
    case 8:
        fprintf(log, "oitocentos");
        printf("oitocentos");
        break;
    case 9:
        fprintf(log, "novecentos");
        printf("novecentos");
        break;
    }
    fclose(log);
}

void escreveMilhar(int milhar)
{
    FILE *log;
    log = fopen("arquivo_log.txt", "a");
    switch (milhar)
    {
    case 1:
        fprintf(log, "hum mil ");
        printf("hum mil ");
        break;
    case 2:
        fprintf(log, "dois mil ");
        printf("dois mil ");
        break;
    case 3:
        fprintf(log, "três mil ");
        printf("três mil ");
        break;
    case 4:
        fprintf(log, "quatro mil ");
        printf("quatro mil ");
        break;
    case 5:
        fprintf(log, "cinco mil ");
        printf("cinco mil ");
        break;
    case 6:
        fprintf(log, "seis mil ");
        printf("seis mil ");
        break;
    case 7:
        fprintf(log, "sete mil ");
        printf("sete mil ");
        break;
    case 8:
        fprintf(log, "oito mil ");
        printf("oito mil ");
        break;
    case 9:
        fprintf(log, "nove mil ");
        printf("nove mil ");
        break;
    }
    fclose(log);
}

void escreveE()
{
    printf(" e ");
    FILE *log;
    log = fopen("arquivo_log.txt", "a");
    fprintf(log, " e ");
    fclose(log);
}

// IMPRESSÃO DO REAL
void escreveReais()
{
    printf(" reais");
    FILE *log;
    log = fopen("arquivo_log.txt", "a");
    fprintf(log, " reais");
    fclose(log);
}

void leNumeros(float num)
{
    int centavos, real, unidadeReal, dezenaReal, centena, milhar, unidadeCent, dezenaCent;
    float temp;
    //float para int
    real = num / 1;
    //centavos = (num - real) * 100;
    temp = num * 100;
    centavos = temp;
    centavos = centavos % 100;

    // REAL
    unidadeReal = real % 10;
    dezenaReal = (real % 100 - unidadeReal) / 10;
    centena = (real % 1000 - dezenaReal - unidadeReal) / 100;
    milhar = real / 1000;

    FILE *log;
    log = fopen("arquivo_log.txt", "a");

    if (log == NULL)
    {
        printf("ERRO! O arquivo não foi aberto!\n");
        exit(1);
    }

    // VALORES DO REAL
    if (real < 20) // O número esta entre 1 e 19
    {
        escreveUnidade(real);
        if (real == 1)
        {
            fprintf(log, " real");
            printf(" real");
        }
        else
        {
            escreveReais();
        }
    }
    else if (real < 100) //O número esta entre 20 e 99
    {
        escreveDezena(dezenaReal);
        if (unidadeReal != 0)
        {
            escreveE();
            escreveUnidade(unidadeReal);
        }
        escreveReais();
    }
    else if (real == 100)
    {
        fprintf(log, "cem");
        printf("Cem");
        escreveReais();
    }
    else if (real < 1000) //O número esta entre 101 e 999
    {
        escreveCentena(centena);
        if (dezenaReal != 0 && unidadeReal == 0)
        {

            escreveE();
            escreveDezena(dezenaReal);
        }
        else if (dezenaReal != 0 && unidadeReal != 0)
        {
            escreveE();
            escreveDezena(dezenaReal);
            escreveE();
            escreveUnidade(unidadeReal);
        }
        escreveReais();
    }
    else if (real <= 9999) //O número esta entre 1000 e 9999
    {
        escreveMilhar(milhar);

        if (centena != 0 && dezenaReal == 0 && unidadeReal == 0)
        {
            escreveE();
            escreveCentena(centena);
        }
        else if (centena != 0 && dezenaReal != 0 && unidadeReal == 0)
        {
            escreveCentena(centena);
            escreveE();
            escreveDezena(dezenaReal);
        }
        else if (centena != 0 && dezenaReal != 0 && unidadeReal != 0)
        {
            escreveCentena(centena);
            escreveE();
            escreveDezena(dezenaReal);
            escreveE();
            escreveUnidade(unidadeReal);
        }
        else if (centena != 0 && dezenaReal == 0 && unidadeReal != 0)
        {
            escreveCentena(centena);
            escreveE();
            escreveUnidade(unidadeReal);
        }
        escreveReais();
    }

    // IMPRESSÃO DOS CENTAVOS
    unidadeCent = centavos % 10;
    dezenaCent = (centavos % 100) / 10;

    if (centavos > 0)
    {
        escreveE();

        if (centavos > 0 && centavos < 20)
        {
            escreveUnidade(centavos);
            fprintf(log, " centavos\n");
            printf(" centavos\n");
        }
        else if (centavos >= 20 && centavos < 100) //O número esta entre 20 e 99
        {
            escreveDezena(dezenaCent);
            if (unidadeReal != 0)
            {
                escreveE();
                escreveUnidade(unidadeCent);
                fprintf(log, " centavos\n");
                printf(" centavos\n");
            }
        }
    }
    else
    {
        fprintf(log, "\n");
        printf("\n");
    }
    fclose(log);
}

//Imprime todos os valores contidos no arquivo_log.txt
void imprimeRegistro()
{
    FILE *log;
    log = fopen("arquivo_log.txt", "r"); //abre o arquivo para leitura
    char logRegistro[100];
    if (log == NULL)
    {
        printf("ERRO! O arquivo não foi aberto!\n");
        exit(1);
    }
    while (fgets(logRegistro, 100, log) != NULL)
        printf("%s", logRegistro);
    fclose(log);
}

//FUNÇÃO PRINCIPAL
int main()
{
    int OP = 1;
    float num;

    // CRIA E/OU LIMPA O ARQUIVO DE LOG
    FILE *log;                           //criando a variável ponteiro para o arquivo
    log = fopen("arquivo_log.txt", "w"); // abrindo/criando o arquivo
    fclose(log);                         // fecha o arquivo

    while (OP != 3)
    {
        printf("\nSelecione uma opção abaixo:\n");
        printf("\t1 - Escrever um número por extenso\n");
        printf("\t2 - Imprimir todos os números do arquivo em tela\n");
        printf("\t3 – sair do programa\n");
        scanf("%d", &OP);
        switch (OP)
        {
        case 1:
            printf("Escreva o número desejado:\n (0 a 9999.99)\n");
            scanf("%f", &num);
            while (num <= 0.0 || num > 9999.99)
            {
                printf("Valor invalido. Insira um numero entre 0 e 9999.99\n");
                scanf("%f", &num);
            }
            leNumeros(num);
            break;
        case 2:
            imprimeRegistro();
            break;
        case 3:
            printf("Encerrando programa...\n");
            break;
        default:
            printf("Voce selecionou uma opcao invalida\n");
        }
    }
    return 0;
}