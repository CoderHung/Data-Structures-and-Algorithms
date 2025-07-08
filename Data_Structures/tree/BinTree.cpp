#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
private:
    static const int SIZE = 100;
    int tree[SIZE];

public:
    BinaryTree() {
        for (int i = 0; i < SIZE; ++i)
            tree[i] = -1; // -1 means empty
    }

    void insert(int val, int index = 0) {
        if (index >= SIZE) {
            cout << "Index out of bounds\n";
            return;
        }
        if (tree[index] == -1) {
            tree[index] = val;
        } else {
            if (val < tree[index])
                insert(val, 2 * index + 1); // left child
            else
                insert(val, 2 * index + 2); // right child
        }
    }

    void inorder(int index = 0) {
        if (index >= SIZE || tree[index] == -1) return;
        inorder(2 * index + 1);
        cout << tree[index] << " ";
        inorder(2 * index + 2);
    }

    void preorder(int index = 0) {
        if (index >= SIZE || tree[index] == -1) return;
        cout << tree[index] << " ";
        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }

    void postorder(int index = 0) {
        if (index >= SIZE || tree[index] == -1) return;
        postorder(2 * index + 1);
        postorder(2 * index + 2);
        cout << tree[index] << " ";
    }

    int getHeight() {
        int maxIndex = -1;
        for (int i = 0; i < SIZE; ++i)
            if (tree[i] != -1) maxIndex = i;
        return (maxIndex == -1) ? 0 : (int)log2(maxIndex + 1) + 1;
    }

    void printTree() {
        int height = getHeight();
        int maxNodes = pow(2, height);
        int maxWidth = maxNodes * 2;

        for (int level = 0; level < height; ++level) {
            int nodes = pow(2, level);
            int firstIndex = nodes - 1;
            int spacing = maxWidth / nodes;

            // Print spaces before first node
            cout << string(spacing / 2, ' ');

            for (int i = 0; i < nodes; ++i) {
                int idx = firstIndex + i;
                if (idx < SIZE && tree[idx] != -1)
                    cout << setw(2) << tree[idx];
                else
                    cout << "  ";

                // Print space between nodes
                cout << string(spacing - 2, ' ');
            }
            cout << "\n";
        }
    }
};

int main() {
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.printTree();;
    /*
        50
    30      70
  20  40  60  80
    */
    return 0;
}