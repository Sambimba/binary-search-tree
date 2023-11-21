#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* right;
    struct node* left;
};
struct node* Bibanode(int a) {                           // создаем узел
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = a;
    return temp;
}

int create_node(struct node* node, int value) {           // создание нового узла слева или справа(зависит от value)
    if (value == node->data)
        return 1;
    struct node* nd = malloc(sizeof(struct node));
    nd->data = value;
    nd->left = NULL;
    nd->right = NULL;
    if ((value > node->data) && (node->right == NULL)) {
        node->right = nd;
        return 0;
    }
    if ((value > node->data) && (node->right != NULL))
        create_node(node->right, value);
    if ((value < node->data) && (node->left == NULL)) {
        node->left = nd;
        return 0;
    }
    if ((value < node->data) && (node->left != NULL))
        create_node(node->left, value);
    return 0;
}

struct node* search_node(struct node* node, int searching_value) { // поиск значения
    if (node == NULL)
        return NULL;
    if (searching_value == node->data)
        return node;
    if ((searching_value < node->data))
        search_node(node->left, searching_value);
    else if ((searching_value > node->data))
        search_node(node->right, searching_value);
}                                                         //

int delete_node(struct node* node, int deliting_value) {           // удаление узла
    struct node* nd = malloc(sizeof(struct node));
    struct node* cd = malloc(sizeof(struct node));
    if ((search_node(node, deliting_value)->right==NULL) && (search_node(node, deliting_value)->left == NULL)) {
        free(node);
        return 0;
    }
    else if ((search_node(node, deliting_value)->right != NULL) && (search_node(node, deliting_value)->left == NULL)) {
        node->data = node->right->data;
        free(node->right);
        return 0;
    }
    else if ((search_node(node, deliting_value)->right == NULL) && (search_node(node, deliting_value)->left != NULL)) {
        node->data = node->left->data;
        free(node->right);
        return 0;
    }
    else if ((search_node(node, deliting_value)->right != NULL) && (search_node(node, deliting_value)->left != NULL)) {
        nd = search_node(node, deliting_value);
        cd = nd;
        nd = nd->right;
        while (nd->left != NULL) {
            nd = nd->left;
        }
        cd->data = nd->data;
        free(nd);
        return 0;
    }
}                                                        //

int main(){
    struct node* cuc = malloc(sizeof(struct node));
    struct node* pup = malloc(sizeof(struct node));
    cuc->right = NULL;
    cuc->left = NULL;
    int v, d, s, search_otv;
    v = 4;
    d = v;
    cuc->data = 12;
    create_node(cuc, v);                                  // заполнение дерева
    v = 14;
    create_node(cuc, v);
    v = 13;
    create_node(cuc, v);
    v = 15;
    create_node(cuc, v);                                  //
    s = 14;                                                // поиск элемента
    pup=search_node(cuc, s);
    d = 14;
    delete_node(cuc, d);
    printf("%d\n",cuc->data);
    printf("%d\n", cuc->right->data);
    printf("%d\n", cuc->right->right->data);
    printf("%d\n", cuc->right->left->data);
}