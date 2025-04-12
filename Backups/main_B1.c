
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
//#include <unistd.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#define MAX_ALUNOS 100

typedef struct {
    char nome[50];
    char senha[99];
    char telefone[50];
    char endereco[99];
    char DataNascimento[99];
    char curso_do_aluno[99];
    char matricula[99];
    char materias[3][99];
    float notas[4];
    int turma[99]; 
    float media[99];
    char status[15];
} Aluno;
Aluno alunos[MAX_ALUNOS] = {0};

int dia, mes, ano;
char materia[99];
int totalAlunos = 0;
bool opcaoin2 = true;
int cursos = 0;
int opcao, matricula;
char nome[50];
char solicitar_e[99];

void exibirAlunos() {
    int opea = 0;
    printf("\nNome: %s",alunos->nome);
    printf("\nData De Nascimento: %s",alunos->DataNascimento);   
    printf("\nEndereço: %s",alunos->endereco);   
    printf("\nTelefone: %s",alunos->telefone);   
    printf("\nCurso: %s",alunos->curso_do_aluno);   
    printf("\nRA: %s",alunos->matricula);
    printf("\nTurma: %d",alunos[9].turma[1]);
    printf("\n>>Para Voltar[1]<<\n");
    scanf("%d",&opea);
    if(opea == 1){
        opcaoin2 = false;
        system("cls");
    }
             
}

void adicionarmaterias(){
    if(strcmp(alunos->curso_do_aluno, "[TC.TI]Desenvolvimento de Sistemas") == 0){
        strcpy(alunos->materias[1],"TC.TI = Logica de Programação");
        strcpy(alunos->materias[2],"TC.TI = Eletro Eletronica");
        strcpy(alunos->materias[3],"TC.TI = Idealização De Projetos");
    }
    else if(strcmp(alunos->curso_do_aluno, "[SOLD]Soldagem") == 0){
        strcpy(alunos->materias[1],"SOLD = Introdução a Soldagem");
        strcpy(alunos->materias[2],"SOLD = Segurança na Soldagem");
        strcpy(alunos->materias[3],"SOLD = Leitura e Interpretação de Desenho Técnico");
    }
    else if(strcmp(alunos->curso_do_aluno, "[ELET.T]Eletrotecnico") == 0){
        strcpy(alunos->materias[1],"ELET.T = Fundamentos de Eletricidade");
        strcpy(alunos->materias[2],"ELET.T = Segurança em Instalações Elétricas");
        strcpy(alunos->materias[3],"ELET.T = Eletrônica Básica");
    }
    else if(strcmp(alunos->curso_do_aluno, "[MECA]Mecatrônica") == 0){
        strcpy(alunos->materias[1],"MECA = Segurança do Trabalho");
        strcpy(alunos->materias[2],"MECA = Fundamentos de Automação Industrial");
        strcpy(alunos->materias[3],"MECA = Uso de EPIs e EPCs");
    }
    else{
        printf("Curso Selecionado nao corresponde");
    }
}
float calcularnotas(){
    srand(time(NULL));
    if(alunos[8].notas[1] == 0){
        alunos[8].notas[1] = rand() % 11;
        alunos[8].notas[2] = rand() % 11;
        alunos[8].notas[3] = rand() % 11;
    }
    float nota1 = alunos[8].notas[1];
    float nota2 = alunos[8].notas[2];
    float nota3 = alunos[8].notas[3];
    float clc = (nota1 + nota2 + nota3) /3;
    return clc;
}

void vernotas(){
    system("cls");
    float clc2 = calcularnotas();
    int option_extra = 0;
    do{
        printf("------NOTAS------\n");
        printf("%s\n\n",alunos->curso_do_aluno);
        printf("Em: %s no Módulo 1 sua nota foi: %.2f\n",alunos->materias[1], alunos[8].notas[1]);
        printf("Em: %s no Módulo 2 sua nota foi: %.2f\n",alunos->materias[2], alunos[8].notas[2]);
        printf("Em: %s no Módulo 3 sua nota foi: %.2f\n",alunos->materias[3], alunos[8].notas[3]);
        if(clc2 >= 7.0){
            printf("\nSua Média foi: %.2f Parabens! Voce Foi Aprovado\n",clc2);
        }
        else if(clc2 >= 5.0){
            printf("\nSua Média foi: %.2f Voce esta em Recuperação, a data para a reavaliação será 03/10/2025\n",clc2);
        }
        else{
            printf("\nSua Média foi: %.2f Voce Reprovou, Contate A Secretaria\n",clc2);
        }
        printf(">>Pessione [1] Para Voltar<<\n");
        scanf("%d",&option_extra);
        if(option_extra == 1){
            option_extra = 1;
            system("cls");
        }
    }while (option_extra == 0);
}

void LOGIN()
{
	printf("\n<< Está à ser implementado! >>");
}

void cadastro(){
    int opf = 0;
    char dtn[99];
    getchar();
    printf("Digite Seu Nome Completo: ");
    fgets(alunos->nome, sizeof(alunos->nome), stdin);
    alunos->nome[strcspn(alunos->nome, "\n")] = 0;

    printf("\nDigite Sua Senha: " );
    fgets(alunos->senha, sizeof(alunos->senha), stdin);
    alunos->senha[strcspn(alunos->senha, "\n")] = 0;

    printf("\nDigite Seu Endereço: ");
    fgets(alunos->endereco, sizeof(alunos->endereco), stdin);
    alunos->endereco[strcspn(alunos->endereco, "\n")] = 0;

    printf("\nDigite Seu Telefone: ");
    fgets(alunos->telefone, sizeof(alunos->telefone), stdin);
    alunos->telefone[strcspn(alunos->telefone, "\n")] = 0;

    printf("\nDigite Sua Data de Nascimento\n");
    printf("Dia: ");
    scanf("%d",&dia);
    printf("\nMes: ");
    scanf("%d",&mes);
    printf("\nAno: ");
    scanf("%d",&ano);
    snprintf(dtn, sizeof(dtn), "%d.%d.%d", dia, mes,ano);
    strncpy(alunos->DataNascimento, dtn, sizeof(alunos->DataNascimento));
    system("cls");
    printf("Escolha um Curso\n");
    printf("-----------------------");
    printf("\nCURSOS DISPONIVEIS\n");
    printf("-----------------------\n");
    do{
        printf("\n1 = Desenvolvimento de sistmeas\n2 = Soldagem\n3 = Eletrotecnico\n4 = Mecatrônica\n");
        scanf("%d",&cursos);
        switch (cursos)
        {
        case 1:
            strcpy(alunos->curso_do_aluno, "[TC.TI]Desenvolvimento de Sistemas");
            opf = 1;
            system("cls");
            break;
        case 2:
            strcpy(alunos->curso_do_aluno, "[SOLD]Soldagem");
            opf = 1;
            system("cls");
            break;
        case 3:
            strcpy(alunos->curso_do_aluno, "[ELET.T]Eletrotecnico");
            opf = 1;
            system("cls");
            break;
        case 4:
            strcpy(alunos->curso_do_aluno, "[MECA]Mecatrônica");
            opf = 1;
            system("cls");
        default:
            printf("\n>>Opção Invalida<<\n");
            Sleep(4);
            opf = 0;
            break;
        }
    }while(opf == 0);
    adicionarmaterias();
    int num1,num2;
    char uni[10];
    srand(time(NULL));
    num1 = rand() % 1000;
    num2 = (rand() % 9000) + 1000;
    snprintf(uni, sizeof(uni), "%d.%d", num1, num2);
    strncpy(alunos->matricula, uni, sizeof(alunos->matricula));
    alunos[9].turma[1] = rand() % 999;
}

void editarcadastro(){
    system("cls");
    int op_e = 0,op_e2 = 0,op_e3 = 0,op_e4 = 0;
    do{
        do{
            printf("|||Para editar o cadastro escolha a opção que deseja editar|||\n");
            printf("[1]Nome || [2]Senha || [3]Endereço || [4]Telefone || [5]Data de Nascimento || [6]Voltar\n");
            scanf("%d",&op_e2);
            switch (op_e2)
            {
            case 1:
                system("cls");
                printf("Seu nome atual é: %s\n",alunos->nome);
                printf("Digite o novo Nome: ");
                scanf("%s",alunos->nome);
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Digite a nova Senha: ");
                scanf("%s",alunos->senha);
                system("cls");
                break;
            case 3:
                system("cls");
                printf("Seu Endereço atual é: %s\n",alunos->endereco);
                printf("Digite o novo Endereço: ");
                scanf("%s",alunos->endereco);
                system("cls");
                break;
            case 4:
                system("cls");
                printf("Seu Telefone atual é: %s\n",alunos->telefone);
                printf("Digite o novo Telefone: ");
                scanf("%s",alunos->telefone);
                system("cls"); 
                break;
            case 5:
                system("cls");
                printf("Sua Data De Nascimento atual é: %s\n",alunos->telefone);
                printf("Digite uma nova Data de Nascimento: ");
                scanf("%s",alunos->DataNascimento);
                system("cls");
                break;
            case 6:
                system("cls");
                op_e3 = 1;
                op_e = 1;
                break;
            default:
                printf("\n\nOpção Escolhida é Invalida");
                break;
            }
        }while (op_e3 == 0);
    }while (op_e == 0);
}

void suporte(){
    system("cls");
    int op = 0,ops1 = 0,i = 0,turmaescolhida,mudar;
    int turmas[5];
    char tempsenha[99];
    int tmptmp = 0;
    do{
        printf("||||||| Bem vindo ao >SUPORTE< |||||||\n\n");
        printf("[1]Solicitar Mudança de Turma\n[2] Solicitar Cancelamento de Matricula\n[3]Solicitar Mundança de Curso\n[4]Outros\n[5]Voltar\n");       
        scanf("%d",&ops1);
        switch (ops1)
        {
        case 1:
            system("cls");
            printf("Sua Turma Atual é: %d\n",alunos[9].turma[1]);
            printf("[Escolha uma das Turmas Disponiveis]\n");
            srand(time(NULL));
            for(i; i < 4; i++){              
                turmas[i] = rand() % 999;
                printf("Turma %d: %d\n",i,turmas[i]);
            }
            scanf("%d",&turmaescolhida);
            alunos[9].turma[1] = turmaescolhida;
            system("cls");
            break;
        
        case 2:
            system("cls");
            printf("Para Solicitar o Cancelamento de Matricula Digite Sua Senha: ");
            scanf("%s",&tempsenha);
            if(strcmp(alunos->senha, tempsenha) == 0){
                strcpy(alunos->senha, tempsenha);
                tmptmp = 1;
                system("cls");
            }
            else{
                system("cls");
                printf("Senha Digitada é Incorreta Tente Novamente em 4 Segundos");
                Sleep(4000);
                system("cls");
            }
            break;
        case 3:
            system("cls");
            printf("Tem Certeza que Deseja Mudar de Curso? [1]Sim [2]Não\n");
            scanf("%d",&mudar);
            if(mudar == 1){
                system("cls");
                printf("\nA Mudança de Curso Só Pode Ser Feita Pela Administração\nSua Solicitação Foi Guardada com um Prazo de 3 dias Uteis Para ser Validada");
                Sleep(4000);
                system("cls");
            }
            else{
                printf("\nMudança Cancelada");
            }
        break;
        case 4:
            system("cls");
            printf("Caso Tenha outra Duvida ou Solicitação Digite aqui (Seja Breve)\n");
            scanf("%s",&solicitar_e);
            system("cls");
            break;
        case 5:
            system("cls");
            op = 1;
        default:
            break;
        }
    }while(op == 0);
}

int main(){
    //SetConsoleOutputCP(CP_UTF8); tava dando problema!
    setlocale(LC_CTYPE, "portuguese");
    
    bool opcaoin = true;
    char op_cadastro;
    do{
        while (opcaoin == true)
        {
            printf("\n===== MENU ESCOLA =====\n");
            printf("Opção Desejada? >>[L]Login<< || >>[C]Cadastro<<\n");
            op_cadastro = getchar();
            switch (op_cadastro)
            {
            case 'l':
                break;
            case 'c':
                cadastro();
                opcaoin = false;
                Sleep(40);
                break;

            default:
                system("cls");
            }

        }
        printf("----------------Portal Do Aluno----------------\n\n");
        printf("[1] ||Notas||\n");
        printf("[2] ||Ver Cadastro||\n");
        printf("[3] ||Editar Cadastro||\n");
        printf("[4] ||Suporte||\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
                case 1:
                    vernotas();
                    break;

                case 2:
                    system("cls");
                    do{
                        exibirAlunos();
                    }
                    while (opcaoin2 == true);
                    break;

                case 3:
                    editarcadastro();
                    break;

                case 4:
                    suporte();
                    break;
                default:
                    printf("Opção Invalida");
                break;
        }
    }while (opcao != 5);
    return 0;
}
