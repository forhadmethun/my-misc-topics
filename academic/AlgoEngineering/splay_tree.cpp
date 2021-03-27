#include<bits/stdc++.h>
#include <ctime>

using namespace std;

//splay tree node..
class node {
public:
    int key;
    node *l, *r;

    node() {
        key = 0;
        l = r = NULL;
    }

    node(int value) {
        key = value;
        l = NULL;
        r = NULL;
    }
};

class SplayTree {
public:
    node *newNode(int value) {
        node *temp = new node(value);
        return temp;
    }

    node *rightRotate(node *p) {
        node *q = p->l;
        p->l = q->r;
        q->r = p;
        return q;
    }

    node *leftRotate(node *p) {
        node *q = p->r;
        p->r = q->l;
        q->l = p;
        return q;
    }

    node *splay(node *root, int key) {
        if (root == NULL || root->key == key) return root;
        if (key > root->key) {
            //if Key is not found in tree(no right children of the tree)
            if (root->r == NULL) return root;

            // Zag Zag (Right Right)
            /*
             *                        G
             *                       / \
             *                          p
             *                         / \
             *                            X
             *
             */
            if (root->r->key < key) {
                // Bring the key as root of right-right and do first rotation
                root->r->r = splay(root->r->r, key);
                root = leftRotate(root);
            }
                // Zig-Zag (Right Left)
                /*
                 *                        G
                 *                       / \
                 *                          p
                 *                         / \
                 *                        X
                 *
                 */

            else if (root->r->key > key) {
                root->r->l = splay(root->r->l, key);
                if (root->r->l != NULL)
                    root->r = rightRotate(root->r);
            }


            if (root->r == NULL) {
                return root;
            } else return leftRotate(root);
        } else {
            // Key is not in tree, we are done
            if (root->l == NULL) return root;

            // Zig Zig (Left Left)
            /*
             *                        G
             *                       / \
             *                      P
             *                     /
             *                    X
             *
             */
            if (root->l->key > key) {
                root->l->l = splay(root->l->l, key);
                root = rightRotate(root);
            }
                // Zig-Zag (Left Right)
                /*
                 *                        G
                 *                       / \
                 *                      P
                 *                      \
                 *                       X
                 */
            else if (root->l->key < key) {
                root->l->r = splay(root->l->r, key);
                if (root->l->r != NULL)
                    root->l = leftRotate(root->l);
            }

            if (root->l == NULL)return root;
            else return rightRotate(root);
        }


    }

    node *insert(node *root, int key) {
        node *temp = newNode(key);
        //if the tree is empty
        if (root == NULL) {
            root = temp;
            temp = NULL;
            return root;
        }
        //splay the tree with the key
        root = splay(root, key);

        if (key < root->key) {
            temp->l = root->l;
            temp->r = root;
            root->l = NULL;
            root = temp;
        } else if (key > root->key) {
            temp->r = root->r;
            temp->l = root;
            root->r = NULL;
            root = temp;
        } else
            return root;
        temp = NULL;
        return root;


    }

    node *del(node *root, int key) {
        node *temp;
        if (root == NULL)return NULL;
        root = splay(root, key);
        if (key != root->key)return root;
        else {
            if (root->l == NULL) {
                temp = root;
                root = root->r;
            } else {
                temp = root;
                root = splay(root->l, key);
                root->r = temp->r;
            }
            free(temp);
            return root;
        }
    }

    node *search(node *root, int key) {
        return splay(root, key);
    }

    //in order
    void print(struct node *root) {
        if (root == NULL)return;
        printf("%d ", root->key);
        print(root->l);
        print(root->r);

    }


};

void N104() {

    clock_t start, start_insert, start_search, start_delete;
    double duration, duration_insert = 0, duration_search = 0, duration_delete = 0;

    start = clock();

    /* Your algorithm here */


    SplayTree sp;
    node *root = NULL;
    for (int i = 0; i < 104 / 2 + 2; i++) {

        start_insert = clock();
        root = sp.insert(root, rand() % 500);
        duration_insert += (clock() - start_insert) / (double) CLOCKS_PER_SEC;

//        sp.print(root);
//        printf("\n");
    }
    for (int i = 0; i < 104 - 104 / 2 - 2; i++) {
        int r = rand() % 2;
        int randVal = rand() % 500;


        if (r == 0) {
            start_delete = clock();
            root = sp.del(root, randVal);
            cout << endl << "deleting: " << randVal << endl;
            duration_delete += (clock() - start_delete) / (double) CLOCKS_PER_SEC;

        } else {
            start_search = clock();
            root = sp.search(root, randVal);
            if (root->key == randVal) {
                printf("found %d\n",randVal) ;
            }
            duration_search += (clock() - start_search) / (double) CLOCKS_PER_SEC;
        }
    }

    duration = (clock() - start) / (double) CLOCKS_PER_SEC;

    //cout<<"printf: "<< duration <<'\n';
    printf("%0.16lf\t%0.16lf\t%0.16lf\t%0.16lf\n", duration, duration_insert, duration_delete, duration_search);
}

void N1004() {

    clock_t start, start_insert, start_search, start_delete;
    double duration, duration_insert = 0, duration_search = 0, duration_delete = 0;

    start = clock();

    /* Your algorithm here */


    SplayTree sp;
    node *root = NULL;
    for (int i = 0; i < 1004 / 2 + 2; i++) {

        start_insert = clock();
        root = sp.insert(root, rand() % 5000);
        duration_insert += (clock() - start_insert) / (double) CLOCKS_PER_SEC;

//        sp.print(root);
//        printf("\n");
    }
    for (int i = 0; i < 1004 - 1004 / 2 - 2; i++) {
        int r = rand() % 2;
        int randVal = rand() % 5000;


        if (r == 0) {
            start_delete = clock();
            root = sp.del(root, randVal);
//            cout << endl << "deleting: " << randVal << endl;
            duration_delete += (clock() - start_delete) / (double) CLOCKS_PER_SEC;

        } else {
            start_search = clock();
            root = sp.search(root, randVal);
            if (root->key == randVal) {
//                printf("found %d\n",randVal) ;
            }
            duration_search += (clock() - start_search) / (double) CLOCKS_PER_SEC;

        }
    }

    duration = (clock() - start) / (double) CLOCKS_PER_SEC;

    //cout<<"printf: "<< duration <<'\n';
    printf("%0.16lf\t%0.16lf\t%0.16lf\t%0.16lf\n", duration, duration_insert, duration_delete, duration_search);
}

void N10004() {

    clock_t start, start_insert, start_search, start_delete;
    double duration, duration_insert = 0, duration_search = 0, duration_delete = 0;

    start = clock();

    /* Your algorithm here */


    SplayTree sp;
    node *root = NULL;
    for (int i = 0; i < 10004 / 2 + 2; i++) {

        start_insert = clock();
        root = sp.insert(root, rand() % 5000);
        duration_insert += (clock() - start_insert) / (double) CLOCKS_PER_SEC;

//        sp.print(root);
//        printf("\n");
    }
    for (int i = 0; i < 1004 - 1004 / 2 - 2; i++) {
        int r = rand() % 2;
        int randVal = rand() % 5000;


        if (r == 0) {
            start_delete = clock();
            root = sp.del(root, randVal);
//            cout << endl << "deleting: " << randVal << endl;
            duration_delete += (clock() - start_delete) / (double) CLOCKS_PER_SEC;

        } else {
            start_search = clock();
            root = sp.search(root, randVal);
            if (root->key == randVal) {
//                printf("found %d\n",randVal) ;
            }
            duration_search = (clock() - start_search) / (double) CLOCKS_PER_SEC;
        }
    }

    duration = (clock() - start) / (double) CLOCKS_PER_SEC;

    //cout<<"printf: "<< duration <<'\n';
    printf("%0.16lf\t%0.16lf\t%0.16lf\t%0.16lf\n", duration, duration_insert, duration_delete, duration_search);
}

void sampleInput1() {
    SplayTree sp;
    node *root = NULL;

    //inserting
    root = sp.insert(root, 1);
    //printing
    sp.print(root);
    printf("\n");
    root = sp.insert(root, 2);
    sp.print(root);
    printf("\n");
    root = sp.insert(root, 2);
    sp.print(root);
    printf("\n");
    root = sp.insert(root, 3);
    sp.print(root);
    printf("\n");

    root = sp.insert(root, 7);
    sp.print(root);
    printf("\n");

    root = sp.insert(root, 5);
    sp.print(root);
    printf("\n");
    root = sp.insert(root, 7);
    sp.print(root);
    printf("\n");

    root = sp.del(root, 3);

    printf("\nTree after deleting 3\n");

    sp.print(root);
    //print
    //searching

    root = sp.search(root, 1);
    cout << "seariching 1" << endl;
    if (root->key == 1) {
        printf("found\n");
    } else {
        printf("not found\n");
    }
    cout << endl;
    sp.print(root);



}

void sampleInput2() {
    SplayTree sp;
    node *root = NULL;

    //inserting
    root = sp.insert(root, 25);
    //printing
    sp.print(root);
    printf("\n");
    root = sp.insert(root, 30);
    sp.print(root);
    printf("\n");
    root = sp.insert(root, 35);
    sp.print(root);
    printf("\n");


    //searching
    root = sp.search(root, 30);
    if (root->key == 30) {
        printf("found\n");
    } else {
        printf("not found\n");
    }

    sp.print(root);
    printf("\n");


    root = sp.insert(root, 32);
    sp.print(root);
    printf("\n");



    //searching
    root = sp.search(root, 7);
    if (root->key == 7) {
        printf("found\n");
    } else {
        printf("not found\n");
    }

    //deleting

    root = sp.del(root, 7);

    //print
    sp.print(root);
    printf("\n");



}


int main() {
//    printf("Tests Splay Tree");
    srand(time(NULL));
    printf("Total\t\t\tInsert\t\t\tDelete\t\t\tSearch\n");
    N104();
    N1004();
    N10004();
    sampleInput1();
    printf("\n\n");
    sampleInput2();
    return 0;
}






