#include <bits/stdc++.h>

using namespace std;

struct node {
    int maxNutrients[2501];
    int val;
    node * left;
    node * right;
};

node * root = nullptr;

void parseTree(string tree, node * &root) {
    tree = tree.substr(tree.find_first_not_of(' '), tree.find_last_not_of(' ') - tree.find_first_not_of(' ') + 1);
    if (tree[0] == '(') {
        tree = tree.substr(1, tree.size() - 2);
        tree = tree.substr(tree.find_first_not_of(' '), tree.find_last_not_of(' ') - tree.find_first_not_of(' ') + 1);
        int mid = 0;
        if (tree[0] == '(') {
            int count = 0;
            while (count || !mid) {
                if (tree[mid] == '(')
                    count++;
                if (tree[mid] == ')')
                    count--;
                mid++;
            }
        } else {
            mid = (int) tree.find(' ');
        }
        root = (node *) malloc(sizeof(node));
        root->val = 0;
        parseTree(tree.substr(0, mid), root->left);
        parseTree(tree.substr(mid + 1), root->right);
    } else {
        root = (node *) malloc(sizeof(node));
        root->val = stoi(tree);
        root->left = nullptr;
        root->right = nullptr;
    }
}

void optimize(node * current, int growth) {
    if (current->val != 0) {
        memset(current->maxNutrients, 0, sizeof(current->maxNutrients));
        for (int i = 0; i <= growth; i++)
            current->maxNutrients[i] = current->val + i;
    } else {
        optimize(current->left, growth);
        
        int left[2501];
        memset(left, 0, sizeof(left));
        for (int i = 0; i <= growth; i++)
            for (int j = 0; j <= i; j++)
                left[i] = max(left[i], min((1 + j) * (1 + j), current->left->maxNutrients[i - j]));
        
        optimize(current->right, growth);
        
        int right[2501];
        memset(right, 0, sizeof(right));
        for (int i = 0; i <= growth; i++)
            for (int j = 0; j <= i; j++)
                right[i] = max(right[i], min((1 + j) * (1 + j), current->right->maxNutrients[i - j]));
        
        memset(current->maxNutrients, 0, sizeof(current->maxNutrients));
        for (int i = 0; i <= growth; i++)
            for (int j = 0; j <= i; j++)
                current->maxNutrients[i] = max(current->maxNutrients[i], left[j] + right[i - j]);
    }
}

int main() {
    string tree;
    getline(cin, tree);
    parseTree(tree, root);
    
    int growth;
    cin >> growth;
    optimize(root, growth);
    
    cout << root->maxNutrients[growth] << endl;
    
    return 0;
}
