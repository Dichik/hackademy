nclude <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    void *data;
    struct node *left;
    struct node *right;
} node_t;

node_t *allocnode() {
    node_t * root = NULL;
    root = (node_t * ) malloc(sizeof(node_t));

    return root;
}

node_t  *insert(node_t *root, char *key, void *data) {
    if(root == NULL) {
        node_t * rs = NULL;
        rs = (node_t * ) malloc(sizeof(node_t));

        rs->key = key;
        rs->data = data;
        root = rs;

        return rs;
    } else {
        if( strcmp(key, root->key) < 0 ) {
            if(root->left != NULL)
                insert(root->left, key, data);
            else {
                node_t * rs = NULL;
                rs = (node_t * ) malloc(sizeof(node_t));

                rs->key = key;
                rs->data = data;

                root->left = rs;
                return rs;
            }
        } else {
            if(root->right != NULL)
                insert(root->right, key, data);
            else {
                node_t * rs = NULL;
                rs = (node_t * ) malloc(sizeof(node_t));

                rs->key = key;
                rs->data = data;

                root->right = rs;

                return rs;
            }
        }
    }
}

void    print_node(node_t *node) {
    printf("%s", node->key);
}
void    visit_tree(node_t *node, void (*fp)(node_t *root)) {

}

void    destroy_tree(node_t *node, void (*fdestroy)(node_t *root)) {

}
