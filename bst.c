#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h> // Para medir o tempo com precisão

// =================================================================
// 1. FUNÇÕES DE CRIAÇÃO E DESTRUIÇÃO
// =================================================================

// Cria um novo Códice na memória
Codice* createCodice(const char *titulo, const char *autor, int id) {
    Codice *newCodice = (Codice *)malloc(sizeof(Codice));
    if (newCodice == NULL) {
        perror("Erro ao alocar Codice");
        exit(EXIT_FAILURE);
    }
    strncpy(newCodice->titulo, titulo, 99);
    strncpy(newCodice->autor, autor, 99);
    newCodice->id_registro = id;
    return newCodice;
}

// Cria um novo Nó da BST
Node* createNode(Codice *codice) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erro ao alocar Node");
        exit(EXIT_FAILURE);
    }
    newNode->data = codice;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Libera a memória do Códice
void freeCodice(Codice *codice) {
    if (codice != NULL) {
        free(codice);
    }
}

// Libera a árvore inteira. O parâmetro free_codice_data garante que o Codice
// seja liberado apenas uma vez (pela BST de ID, por exemplo).
void destroyTree(Node *root, int free_codice_data) {
    if (root != NULL) {
        destroyTree(root->left, free_codice_data);
        destroyTree(root->right, free_codice_data);
        if (free_codice_data) {
            freeCodice(root->data);
        }
        free(root);
    }
}

// =================================================================
// 2. FUNÇÕES DE INSERÇÃO
// =================================================================

// Insere um nó na BST de ID (comparação numérica)
Node* insertNode_ID(Node *root, Codice *codice) {
    if (root == NULL) {
        return createNode(codice);
    }

    if (codice->id_registro < root->data->id_registro) {
        root->left = insertNode_ID(root->left, codice);
    } else if (codice->id_registro > root->data->id_registro) {
        root->right = insertNode_ID(root->right, codice);
    }
    // Se for duplicado, apenas retorna a raiz (não insere)
    return root;
}

// Insere um nó na BST de Título (comparação alfabética com strcmp)
Node* insertNode_Title(Node *root, Codice *codice) {
    if (root == NULL) {
        return createNode(codice);
    }

    int cmp = strcmp(codice->titulo, root->data->titulo);

    if (cmp < 0) {
        root->left = insertNode_Title(root->left, codice);
    } else if (cmp > 0) {
        root->right = insertNode_Title(root->right, codice);
    }
    // Se for duplicado, apenas retorna a raiz
    return root;
}
