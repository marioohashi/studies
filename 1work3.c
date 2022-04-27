#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

int COD_CONT = 0;

struct REG_MES
{
    int DIA, QTDE_HORAS;
};

struct REG_FUNCIONARIOS
{
    char NOME[30], CARGO[30];
    int COD_FUNC, FLAG;
    float VALOR_HORA;
    struct REG_MES MESES[12];
} FUNC[TAM];

//------------------------------------

// CHAMADA DE FUNÇÕES
void cadastrarFunc();
void horasTrab();
void calcSal();
void listaFunc();
void alteraInfo();
void exlcuiFunc();
void menu();

//------------------------------------
void inicReg()
{
    int I;
    for (I = 0; I < TAM; I++)
        FUNC[I].FLAG = 0;
}

//------------------------------------

void imprimeLinha()
{
    printf("\n-----------------------------------------------------------\n");
}

void imprimeMeses()
{
    printf("\t1 - JAN\n\t2 - FEV\n\t3 - MAR\n\t4 - ABR\n\t5 - MAI\n\t6 - JUN\n\t7 - JUL\n\t8 - AGO\n\t9 - SET\n\t10 - OUT\n\t11 - NOV\n\t12 - DEZ\n");
}
void imprimeFuncionario(int I)
{
    printf("%d - %s", FUNC[I].COD_FUNC, FUNC[I].NOME);
}
//------------------------------------

int isPosLivre()
{
    int I, POS_LIVRE = -1;
    for (I = 0; I < TAM; I++)
    {
        if (FUNC[I].FLAG == 0)
        {
            POS_LIVRE = I;
            return I;
        }
    }
    if (POS_LIVRE == -1)
    {
        printf("Nao ha espaco livre");
        return POS_LIVRE;
    }
    return POS_LIVRE;
}
int isCodLivre(int COD)
{
    int I, codLivre = 0;
    for (I = 0; I < TAM; I++)
    {
        if (FUNC[I].COD_FUNC == COD)
        {
            codLivre = 1;
        }
    }
    return codLivre;
}
//------------------------------------
void cadastraFunc()
{
    int POS, I, COD_FUNC_TEMP, CADASTRO_OK = 0;
    POS = isPosLivre();
    while (CADASTRO_OK == 0)
    {
        printf("Digite o código do funcionario\n");
        fflush(stdin);
        scanf("%d", &COD_FUNC_TEMP);

        if (isCodLivre(COD_FUNC_TEMP) == 1)
        {
            printf("Este codigo ja foi cadastrado anteriomente\n");
        }
        else
        {
            FUNC[POS].COD_FUNC = COD_FUNC_TEMP;
            CADASTRO_OK = 1;
        }
    }
    printf("Informe o nome do funcionario\n");
    fflush(stdin);
    fgets(FUNC[POS].NOME, 30, stdin);
    COD_CONT++;
    FUNC[POS].COD_FUNC = COD_CONT;
    printf("Informe o cargo do funcionario\n");
    fgets(FUNC[POS].CARGO, 30, stdin);
    printf("Informe o valor/hora do funcionario\n");
    scanf("%f", &FUNC[POS].VALOR_HORA);
    FUNC[POS].FLAG = 1;
    printf("Funcionario cadastrado com sucesso\n");
}
//------------------------------------
int encontraFuncionario()
{
    int I, COD_FUNC, ACHOU_FUNC = 0;
    printf("Informe o codigo do funcionario:\n");
    scanf("%d", &COD_FUNC);
    for (I = 0; I < TAM; I++)
    {
        if ((FUNC[I].COD_FUNC == COD_FUNC) && (FUNC[I].FLAG == 1))
        {
            ACHOU_FUNC = 1;
            return I;
        }
    }
    if (ACHOU_FUNC == 0)
        printf("Funcionario nao encontrado\n");
    return 0;
}

//------------------------------------

void horasTrab()
{
    int I, MES, DIA, HORAS, FLAG;
    I = encontraFuncionario();
    do
    {
        printf("Informe o mês desejado:\n");
        imprimeMeses();
        scanf("%d", &MES);
        fflush(stdin);
        if (MES > 12 || MES <= 0)
        {
            printf("Mes invalido\n");
            FLAG = 0;
        }
        else
            FLAG = 1;
    } while (FLAG == 0);
    do
    {
        printf("Informe a quantidade de dias trabalhados\n");
        scanf("%d", &DIA);
        fflush(stdin);
        if (DIA < 0 || DIA > 31) // 0 é válido pois ele pode não trabalhar nenhum dia do mês.
        {
            printf("Quantidade de dias trabalhados invalido\n");
            FLAG = 0;
        }
        else
        {
            FUNC[I].MESES[MES].DIA = DIA;
            FLAG = 1;
        }
    } while (FLAG == 0);
    do
    {
        printf("Informe a quantidade de horas trabalhadas por dia\n");
        scanf("%d", &HORAS);
        fflush(stdin);
        if (HORAS < 0 || HORAS > 24)
        {
            printf("Quantidade de horas invalidas\n");
            FLAG = 0;
        }
        else
        {
            FUNC[I].MESES[MES].QTDE_HORAS = HORAS;
            FLAG = 1;
        }
    } while (FLAG == 0);

    fflush(stdin);
}
//------------------------------------

void calcSal()
{
    int I, MES;
    I = encontraFuncionario();
    printf("Informe o mês desejado:\n");
    imprimeMeses();
    scanf("%d", &MES);
    imprimeFuncionario(I);
    switch (MES)
    {
    case 1:
        printf("Salário de Janeiro: ");
        break;
    case 2:
        printf("Salário de Fevereiro: ");
        break;
    case 3:
        printf("Salário de Março: ");
        break;
    case 4:
        printf("Salário de Abril: ");
        break;
    case 5:
        printf("Salário de Maio: ");
        break;
    case 6:
        printf("Salário de Junho: ");
        break;
    case 7:
        printf("Salário de Julho: ");
        break;
    case 8:
        printf("Salário de Agosto: ");
        break;
    case 9:
        printf("Salário de Setembro: ");
        break;
    case 10:
        printf("Salário de Outubro: ");
        break;
    case 11:
        printf("Salário de Novembro: ");
        break;
    case 12:
        printf("Salário de Dezembro: ");
        break;
    }
    printf("R$%.f\n", FUNC[I].MESES[MES].QTDE_HORAS * FUNC[I].MESES[MES].DIA * FUNC[I].VALOR_HORA);
}

//------------------------------------

void listaFunc()
{
    int I, FLAG = 0;
    printf("\nFUNCIONARIOS: \n");
    for (I = 0; I < TAM; I++)
    {
        if ((FUNC[I].FLAG != 0) && (FUNC[I].COD_FUNC != 0))
        {
            imprimeFuncionario(I);
            FLAG = 1;
        }
    }
    if (FLAG == 0)
        printf("\nNenhum funcionário cadastrado\n");
}

//------------------------------------

void alteraInfo()
{
    int OP, I, codFunc;
    while (OP != 6)
    {
        printf("\t1 - NOME\n\t2 - CODIGO\n\t3 - CARGO\n\t4 - VALOR HORA\n\t5 - VOLTAR AO MENU PRINCIPAL\n");
        scanf("%d", &OP);
        switch (OP)
        {
        case 1:
            I = encontraFuncionario();
            printf("\n\tAlterar os dados de %s - %d - %s\n\n", FUNC[I].NOME, FUNC[I].COD_FUNC, FUNC[I].CARGO);
            printf("Informe um novo NOME:\n");
            fflush(stdin);
            fgets(FUNC[I].NOME, 30, stdin);
            printf("Nome alterado para:%s\n", FUNC[I].NOME);
            break;
        case 2:
            I = encontraFuncionario();
            printf("\n\tAlterar os dados de %s - %d - %s\n\n", FUNC[I].NOME, FUNC[I].COD_FUNC, FUNC[I].CARGO);
            printf("Informe um novo CODIGO\n");
            fflush(stdin);
            scanf("%d", &FUNC[I].COD_FUNC);
            printf("Codigo alterado para:%d\n", FUNC[I].COD_FUNC);

            break;
        case 3:
            I = encontraFuncionario();
            printf("\n\tAlterar os dados de %s - %d - %s\n\n", FUNC[I].NOME, FUNC[I].COD_FUNC, FUNC[I].CARGO);
            printf("Informe um novo CARGO:\n");
            fflush(stdin);
            fgets(FUNC[I].CARGO, 30, stdin);
            printf("Nome alterado para:%s\n", FUNC[I].CARGO);
            break;
        case 4:
            I = encontraFuncionario();
            printf("\n\tAlterar os dados de %s - %d - %s\n\n", FUNC[I].NOME, FUNC[I].COD_FUNC, FUNC[I].CARGO);
            printf("Informe um novo VALOR HORA\n");
            fflush(stdin);
            scanf("%f", &FUNC[I].VALOR_HORA);
            printf("Codigo alterado para:%f\n", FUNC[I].VALOR_HORA);
            break;
        case 5:
            menu();
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }
}

//------------------------------------

void exlcuiFunc()
{
    int I, COD_FUNC, ACHOU_FUNC = 0;
    printf("Digite o codigo do funcionario que deseja excluir\n");
    fflush(stdin);
    scanf("%d", &COD_FUNC);
    for (I = 0; I < TAM; I++)
    {
        if ((FUNC[I].FLAG == 1) && (COD_FUNC == FUNC[I].COD_FUNC))
        {
            printf("\nFuncionario excluido com sucesso!\n");
            FUNC[I].FLAG = 0;
            ACHOU_FUNC = 1;
        }
    }
    if (ACHOU_FUNC == 0)
        printf("\nFuncionario nao encontrado\n");
}

//------------------------------------
void menu()
{
    int COD;
    while (COD != 7)
    {
        imprimeLinha();
        printf("\n\t<Empresa de Construção Civil Fictícia Ltda>\n\n\tMENU\n");
        printf("\t1 - CADASTRAR NOVO FUNCIONARIO\n\t2 - INSERIR HORAS TRABLHADAS\n\t3 - CALCULAR SALARIO\n\t4 - LISTAR FUNCIONARIOS CADASTRADOS\n\t5 - ALTERAR INFORMACOES DO FUNCIONARIO\n\t6 - EXCLUIR FUNCIONARIO\n\t7 - SAIR DO PROGRAMA\n");
        imprimeLinha();
        scanf("%d", &COD);
        switch (COD)
        {
        case 1:
            cadastraFunc();
            break;
        case 2:
            horasTrab();
            break;
        case 3:
            calcSal();
            break;
        case 4:
            listaFunc();
            break;
        case 5:
            alteraInfo();
            break;
        case 6:
            exlcuiFunc();
            break;
        case 7:
            printf("Saindo do programa...");
            exit(1);
            break;
        default:
            break;
        }
    }
}
//----------------------------------------------
int main()
{
    inicReg();
    menu();
    return 0;
}