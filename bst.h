#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

// Estrutura para guardar as informações do livro (Códice)
typedef struct {
    char titulo[100];
    char autor[100];
    int id_registro; // A chave principal
} Codice;

// Estrutura do Nó da Árvore
typedef struct Node {
    Codice *data; // Ponteiro para o livro
    struct Node *left;
    struct Node *right;
} Node;

// Estrutura para o sistema inteiro (as duas árvores)
typedef struct {
    Node *root_id;    // Árvore indexada por ID
    Node *root_title; // Árvore indexada por Título
} CodiceEternal;

// Funções básicas de gerenciamento de memória
Codice* createCodice(const char *titulo, const char *autor, int id);
Node* createNode(Codice *codice);
void destroyTree(Node *root, int free_codice_data); // free_codice_data diz se é para liberar o Codice junto
void freeCodice(Codice *codice);
// Funções de Inserção
Node* insertNode_ID(Node *root, Codice *codice);
Node* insertNode_Title(Node *root, Codice *codice);

// Funções de Busca
Node* searchNode_ID(Node *root, int id, int *comparisons);
Node* searchNode_Title(Node *root, const char *title, int *comparisons);

// Funções de Remoção
Node* findMin(Node *node); // Acha o menor nó da subárvore
Node* deleteNode_ID(Node *root, int id);
Node* deleteNode_Title(Node *root, const char *title);

// Travessia (para listar em ordem)
void traverseInOrder(Node *root);

// Métricas
int calculateHeight(Node *root); // Calcula a altura da árvore

// I/O (Simulação de Banco de Dados)
CodiceEternal* loadCatalogFromFile(const char *filename);
void saveCatalogToFile(Node *root, const char *filename);

#endif // BST_H
