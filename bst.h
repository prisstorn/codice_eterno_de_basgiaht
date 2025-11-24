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
