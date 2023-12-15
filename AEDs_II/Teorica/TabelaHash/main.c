/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: flavio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Gera a posicao a ser gravada na hash usando o metodo da divisao.
 * @param chave
 * @param TABLE_SIZE
 * @return indice do vetor onde a informação será gravada.
 */
int chave_divisao(int chave, int TABLE_SIZE)
{
	if (chave < 0)
		chave *= -1;
	return chave % TABLE_SIZE;
}

/**
 * Gera a posicao a ser gravada na hash usando o metodo da multiplicacao.
 * @param chave
 * @param TABLE_SIZE
 * @return indice do vetor onde a informação será gravada.
 */
int chave_multiplicacao(int chave, int TABLE_SIZE)
{
	if (chave < 0)
		chave *= -1;
	double A = 0.7834729723;
	double val = chave * A;
	val = val - (int)val;
	return (int)(val * TABLE_SIZE);
}

/**
 * Gera a posicao a ser gravada na hash usando o metodo da dobra.
 * @param chave
 * @param TABLE_SIZE
 * @return indice do vetor onde a informação será gravada.
 */
int chave_dobra(int chave, int TABLE_SIZE)
{
	if (chave < 0)
		chave *= -1;
	if (chave < TABLE_SIZE)
		return chave;

	int numeros[10];
	int inicio = 0;
	int fim = 0;
	int div = chave;
	do
	{
		int resto = div % 10;
		numeros[inicio] = resto;
		if (numeros[inicio])
			fim = inicio;
		inicio++;
		div = div / 10;
	} while (inicio < 10);
	inicio = 0;

	while (chave > TABLE_SIZE)
	{
		while (fim > inicio)
		{
			numeros[inicio] = (numeros[inicio] + numeros[fim]) % 10;
			numeros[fim] = 0;
			inicio++;
			fim--;
		}
		inicio = 0;
		chave = 0;
		int fator = 1;
		while (inicio <= fim)
		{
			chave += numeros[inicio] * fator;
			fator *= 10;
			inicio++;
		}
		inicio = 0;
	}

	return chave;
}

/**
 * Gera a partir da string um valor inteiro, de modo a poder
 * ser usada em alguma das outras funcoes de hashing.
 * @param str string que se deseja obter a chave.
 * @return valor inteiro obtido à partir da string passada.
 */
int valor_string(char *str)
{
	int i, valor = 7;
	int tam = strlen(str);
	for (i = 0; i < tam; i++)
	{
		valor = 31 * valor + (int)str[i];
	}
	return valor;
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

typedef struct estudante_
{
	int matricula; // chave
	char nome[30]; // valor
} estudante;

typedef struct hash_
{
	int qtd, TABLE_SIZE; // qtd = quantidade de elementos inseridos,
	// TABLE_SIZE = tamanho da tabela.
	estudante **estudantes; // vetor de estudantes.
} hash;

estudante *cria_estudante(char *nome, int matricula)
{
	estudante *e = malloc(sizeof(estudante));
	e->matricula = matricula;
	strncpy(e->nome, nome, strlen(nome));
	return e;
}

hash *cria_hash(int TABLE_SIZE)
{
	hash *ha = malloc(sizeof(hash));

	if (ha != NULL)
	{
		int i;
		ha->estudantes = malloc(TABLE_SIZE * sizeof(estudante *));
		if (ha->estudantes == NULL)
		{
			free(ha);
			return NULL;
		}
		ha->TABLE_SIZE = TABLE_SIZE;
		ha->qtd = 0;
		for (i = 0; i < TABLE_SIZE; i++)
		{
			ha->estudantes[i] = NULL;
		}
	}
	return ha;
}

void libera_hash(hash *ha)
{
	if (ha != NULL)
	{
		int i;

		for (i = 0; i < ha->TABLE_SIZE; i++)
		{
			if (ha->estudantes[i] != NULL)
				free(ha->estudantes[i]);
		}
		free(ha->estudantes);
		free(ha);
	}
}

int insere_hash_s_colisao(hash *ha, estudante *e)
{
	if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
	{
		return 0;
	}
	int pos = chave_divisao(e->matricula, ha->TABLE_SIZE);

	ha->estudantes[pos] = e;
	ha->qtd++;
	return 1;
}

char *busca_hash_s_colisao(hash *ha, int matricula)
{
	int pos = chave_divisao(matricula, ha->TABLE_SIZE);
	return &(ha->estudantes[pos]->nome[0]);
}

/**
 * Tratamento de colisoes desse ponto para baixo.
 */

/**
 * Realiza a sondagem linear na tabela.
 * @param pos posicao atual que se deseja inserir na Hash.
 * @param i deslocamento para se fazer a sondagem em relacao à posição atual.
 * @param TABLE_SIZE tamanho da tabela.
 * @return nova posição calculada.
 */
int sondagem_linear(int pos, int i, int TABLE_SIZE)
{
	return ((pos + i) % TABLE_SIZE);
}

/**
 * Realiza a sondagem quadratica na tabela.
 * @param pos posicao atual que se deseja inserir na Hash.
 * @param i deslocamento para se fazer a sondagem em relacao à posição atual.
 * @param TABLE_SIZE tamanho da tabela.
 * @return nova posição calculada.
 */
int sondagem_quadratica(int pos, int i, int TABLE_SIZE)
{
	pos = pos + 2 * i + 5 * i * i;
	return (pos % TABLE_SIZE);
}

/**
 * Realiza o duplo hash.
 * @param H1 Valor obtido da primeira funcao de hashing.
 * @param chave chave, que sera usada para se obter o novo índice.
 * @param i tentativa, observe que na primeira vez, somente o valor de H1 é considerado.
 * @param TABLE_SIZE tamanho da tabela.
 * @return nova posição calculada.
 */
int duplo_hash(int H1, int chave, int i, int TABLE_SIZE)
{
	// garantindo que a funcao chave_divisao nao retorne 0
	int H2 = chave_divisao(chave, TABLE_SIZE - 1) + 1;
	return ((H1 + i * H2) % TABLE_SIZE);
}

/**
 * Metodo de inserção e busca desse ponto para baixo.
 * Considerando o tratamento de colisões por endereçamento aberto.
 */

/**
 * Insere na hash, considerando a tecnica de endereçamento
 * aberto na hora de resolver colisões.
 * @param ha hash.
 * @param e estudante, a ser inserido.
 * @return 1 caso consiga inserir, e 0 caso contrário.
 */
int insere_hash_end_aberto(hash *ha, estudante *e)
{
	if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
	{
		return 0;
	}
	int pos, i;
	// pos = chave_divisao(e->matricula, ha->TABLE_SIZE);
	// pos = chave_multiplicacao(e->matricula, ha->TABLE_SIZE);
	pos = chave_dobra(e->matricula, ha->TABLE_SIZE);

	for (i = 0; i < ha->TABLE_SIZE; i++)
	{
		// pos = sondagem_linear(pos, i, ha->TABLE_SIZE);
		// pos = sondagem_quadratica(pos, i, ha->TABLE_SIZE);
		pos = duplo_hash(pos, e->matricula, i, ha->TABLE_SIZE);
		if (ha->estudantes[pos] == NULL)
		{
			ha->estudantes[pos] = e;
			ha->qtd++;
			return 1;
		}
	}
	return 0;
}

/**
 * Busca na hash, considerando que na inserção foi usada
 * a técnica de endereçamento aberto na hora de resolver colisões.
 * @param ha hash.
 * @param matricula matrícula do estudante, que se deseja buscar.
 * @return ponteiro para o nome do estudante, caso ele esteja na hash,
 * ou NULL caso contrário.
 */
char *busca_hash_end_aberto(hash *ha, int matricula)
{
	int i, pos;
	// pos = chave_divisao(matricula, ha->TABLE_SIZE);
	// pos = chave_multiplicacao(e->matricula, ha->TABLE_SIZE);
	pos = chave_dobra(matricula, ha->TABLE_SIZE);

	for (i = 0; i < ha->TABLE_SIZE; i++)
	{
		// pos = sondagem_linear(pos, i, ha->TABLE_SIZE);
		// pos = sondagem_quadratica(pos, i, ha->TABLE_SIZE);
		pos = duplo_hash(pos, matricula, i, ha->TABLE_SIZE);
		if (ha->estudantes[pos] == NULL)
		{
			return NULL;
		}
		else if (ha->estudantes[pos]->matricula == matricula)
		{
			return &(ha->estudantes[pos]->nome[0]);
		}
	}
	return NULL;
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

typedef struct estudanteSep_
{
	int matricula; // chave
	char nome[30]; // valor
	struct estudanteSep_ *prox;
} estudanteSeparado;

typedef struct hashSep_
{
	int qtd, TABLE_SIZE; // qtd = quantidade de elementos inseridos,
	// TABLE_SIZE = tamanho da tabela.
	estudanteSeparado **estudantes; // vetor de estudantes.
} hashSeparado;

hashSeparado *cria_hashSep(int TABLE_SIZE)
{
	hashSeparado *ha = malloc(sizeof(hashSeparado));

	if (ha != NULL)
	{
		int i;
		ha->estudantes = malloc(TABLE_SIZE * sizeof(estudanteSeparado *));
		if (ha->estudantes == NULL)
		{
			free(ha);
			return NULL;
		}
		ha->TABLE_SIZE = TABLE_SIZE;
		ha->qtd = 0;
		for (i = 0; i < TABLE_SIZE; i++)
		{
			ha->estudantes[i] = malloc(sizeof(estudanteSeparado));
			ha->estudantes[i]->prox = NULL;
		}
	}
	return ha;
}

estudanteSeparado *cria_estudanteSep(char *nome, int matricula)
{
	estudanteSeparado *e = malloc(sizeof(estudanteSeparado));
	e->matricula = matricula;
	strncpy(e->nome, nome, strlen(nome));
	e->prox = NULL;
	return e;
}

void buscar(estudanteSeparado *ptlista, int x, estudanteSeparado **ant, estudanteSeparado **pont)
{
	*pont = NULL;
	*ant = ptlista;
	estudanteSeparado *ptr = ptlista->prox;

	while (ptr != NULL)
	{
		if (ptr->matricula < x)
		{
			*ant = ptr;
			ptr = ptr->prox;
		}
		else
		{
			if (ptr->matricula == x)
			{
				*pont = ptr;
			}
			ptr = NULL; // break;
		}
	}
}

estudanteSeparado *inserir(estudanteSeparado *ptlista, estudanteSeparado *novo_no)
{
	estudanteSeparado *ant, *pont;
	buscar(ptlista, novo_no->matricula, &ant, &pont);
	if (pont == NULL)
	{
		novo_no->prox = ant->prox;
		ant->prox = novo_no;
		return NULL;
	}
	return pont;
}

estudanteSeparado *remover(estudanteSeparado *ptlista, int x)
{
	estudanteSeparado *ant, *pont;
	buscar(ptlista, x, &ant, &pont);
	if (pont != NULL)
	{
		ant->prox = pont->prox;
		return pont;
	}
	else
	{
		return NULL;
	}
}

int insere_hash_end_separado(hash *ha, estudante *e)
{
	if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
	{
		return 0;
	}
	int pos;
	pos = chave_divisao(e->matricula, ha->TABLE_SIZE);
	// pos = chave_multiplicacao(e->matricula, ha->TABLE_SIZE);
	// pos = chave_dobra(e->matricula, ha->TABLE_SIZE);

	if (inserir(ha->estudantes[pos], e) == NULL)
	{
		ha->qtd++;
		return 1;
	}
	printf("Já existe um aluno com essa matrícula.\n");
	return 0;

	return 0;
}

char *busca_hash_end_separado(hash *ha, int matricula)
{
	int i, pos;
	pos = chave_divisao(matricula, ha->TABLE_SIZE);
	// pos = chave_multiplicacao(e->matricula, ha->TABLE_SIZE);
	// pos = chave_dobra(matricula, ha->TABLE_SIZE);
	estudanteSeparado *pont, *ant;
	buscar(ha->estudantes[pos], matricula, &ant, &pont);
	if (pont != NULL)
	{
		return pont->nome;
	}
	return NULL;
}

int remove_hash_end_separado(hash *ha, int id)
{
	if (ha == NULL)
	{
		return 0;
	}
	int pos;
	pos = chave_divisao(id, ha->TABLE_SIZE);
	// pos = chave_multiplicacao(id, ha->TABLE_SIZE);
	// pos = chave_dobra(id, ha->TABLE_SIZE);

	estudanteSeparado *temp = remover(ha->estudantes[pos], id);
	if (temp != NULL)
	{
		printf("Aluno removido: %s\n", temp->nome);
		printf("Posição: %d\n", pos);
		ha->qtd--;
		return 1;
	}
	printf("Aluno não encontrado.\n");
	return 0;

	// if (ha->estudantes[pos] == NULL)
	// {
	// 	return 0;
	// }
	// else
	// {
	// 	estudanteSeparado *aux = ha->estudantes[pos], *ant = NULL;
	// 	while (aux->matricula != id)
	// 	{
	// 		ant = aux;
	// 		aux = aux->prox;
	// 		if (aux == NULL)
	// 		{
	// 			return 0;
	// 		}
	// 	}
	// 	ant->prox = aux->prox;
	// 	free(aux);
	// 	ha->qtd--;
	// 	return 1;
	// }
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void ler_menu(int *resposta)
{
	printf("\n-----------------------\n");
	printf("escolha uma das opcoes:\n");
	printf("0 - sair\n");
	printf("1 - inserir estudante\n");
	printf("2 - remover\n");
	printf("3 - buscar estudante\n");
	scanf("%d", resposta);
	printf("-----------------------\n\n");
}

/*
 *
 */
int main()
{
	hashSeparado *ha = cria_hashSep(1000);
	int resposta = 1;

	// estudante * e = cria_estudante("Flavio Barbieri\0", 125);
	// insere_hash_end_aberto(ha, e);

	// e = cria_estudante("Joao das Couves\0", 1125);
	// insere_hash_end_aberto(ha, e);

	// char * a = busca_hash_end_aberto(ha, 125);
	// if (a != NULL)
	// 	printf("%s\n", a);
	// else
	// 	printf("Aluno nao encontrado.\n");

	// a = busca_hash_end_aberto(ha, 1125);
	// if (a != NULL)
	// 	printf("%s\n", a);
	// else
	// 	printf("Aluno nao encontrado.");

	// libera_hash(ha);

	while (resposta)
	{
		ler_menu(&resposta);

		if (resposta == 0)
		{
			libera_hash(ha);
			return (EXIT_SUCCESS);
		}
		else if (resposta == 1)
		{
			char nome[30];
			int id;
			printf("Digite seu nome: ");
			scanf("%s", nome);
			printf("Digite sua matricula: ");
			scanf("%d", &id);
			estudanteSeparado *e = cria_estudanteSep(nome, id);
			insere_hash_end_separado(ha, e);
		}
		else if (resposta == 2)
		{
			// remover
			int id;
			printf("Digite sua matricula: ");
			scanf("%d", &id);
			remove_hash_end_separado(ha, id);
		}
		else if (resposta == 3)
		{
			int id;
			printf("Digite sua matricula: ");
			scanf("%d", &id);
			char *a = busca_hash_end_separado(ha, id);
			if (a != NULL)
			{
				printf("Aluno: %s\n", a);
			}
			else
			{
				printf("Aluno nao encontrado.\n");
			}
		}
	}

	return (EXIT_SUCCESS);
}
