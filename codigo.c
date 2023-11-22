#include <stdio.h>


// Definindo a estrutura do veículo
typedef struct {
    int id;
    char modelo[50];
    char placa[10];
    int ano;
    float precoDiaria;
    int disponivel;
} Veiculo;

// Função para exibir menu
void exibirMenu() {
    printf("\n=== Locadora de Veiculos ===\n");
    printf("1. Cadastrar Veiculo\n");
    printf("2. Alugar Veiculo\n");
    printf("3. Devolver Veiculo\n");
    printf("4. Mostrar Veiculos Disponiveis\n");
    printf("5. Sair\n");
    printf("============================\n");
    printf("Escolha uma opcao: ");
}

// Função para cadastrar veículo
void cadastrarVeiculo(Veiculo *veiculos, int *totalVeiculos) {
    printf("\nCadastrar Veiculo\n");

    Veiculo novoVeiculo;
    novoVeiculo.id = *totalVeiculos + 1;

    printf("Modelo: ");
    scanf("%s", novoVeiculo.modelo);

    printf("Placa: ");
    scanf("%s", novoVeiculo.placa);

    printf("Ano: ");
    scanf("%d", &novoVeiculo.ano);

    printf("Preco Diaria: ");
    scanf("%f", &novoVeiculo.precoDiaria);

    novoVeiculo.disponivel = 1;

    veiculos[*totalVeiculos] = novoVeiculo;
    (*totalVeiculos)++;

    printf("Veiculo cadastrado com sucesso!\n");
}

// Função para alugar veículo
void alugarVeiculo(Veiculo *veiculos, int totalVeiculos) {
    printf("\nAlugar Veiculo\n");

    int id;
    printf("Digite o ID do veiculo desejado: ");
    scanf("%d", &id);

    if (id >= 1 && id <= totalVeiculos) {
        if (veiculos[id - 1].disponivel) {
            printf("Veiculo alugado com sucesso!\n");
            veiculos[id - 1].disponivel = 0;
        } else {
            printf("Veiculo indisponivel no momento.\n");
        }
    } else {
        printf("ID invalido.\n");
    }
}

// Função para devolver veículo
void devolverVeiculo(Veiculo *veiculos, int totalVeiculos) {
    printf("\nDevolver Veiculo\n");

    int id;
    printf("Digite o ID do veiculo a ser devolvido: ");
    scanf("%d", &id);

    if (id >= 1 && id <= totalVeiculos) {
        if (!veiculos[id - 1].disponivel) {
            printf("Veiculo devolvido com sucesso!\n");
            veiculos[id - 1].disponivel = 1;
        } else {
            printf("Veiculo ja esta disponivel.\n");
        }
    } else {
        printf("ID invalido.\n");
    }
}

// Função para mostrar veículos disponíveis
void mostrarVeiculosDisponiveis(Veiculo *veiculos, int totalVeiculos) {
    printf("\nVeiculos Disponiveis\n");

    for (int i = 0; i < totalVeiculos; i++) {
        if (veiculos[i].disponivel) {
            printf("ID: %d | Modelo: %s | Placa: %s | Ano: %d | Preco Diaria: %.2f\n",
                   veiculos[i].id, veiculos[i].modelo, veiculos[i].placa,
                   veiculos[i].ano, veiculos[i].precoDiaria);
        }
    }
}

int main() {
    const int MAX_VEICULOS = 100;
    Veiculo veiculos[MAX_VEICULOS];
    int totalVeiculos = 0;
    int escolha;

    do {
        exibirMenu();
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cadastrarVeiculo(veiculos, &totalVeiculos);
                break;
            case 2:
                alugarVeiculo(veiculos, totalVeiculos);
                break;
            case 3:
                devolverVeiculo(veiculos, totalVeiculos);
                break;
            case 4:
                mostrarVeiculosDisponiveis(veiculos, totalVeiculos);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 5);

    return 0;
}
