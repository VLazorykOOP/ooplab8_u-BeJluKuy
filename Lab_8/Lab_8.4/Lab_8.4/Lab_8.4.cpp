#include <iostream>
#include <stack>

// Клас, що представляє вузол бінарного дерева
class TreeNode {
public:
    int value; // Значення вузла
    TreeNode* left; // Покажчик на лівого нащадка
    TreeNode* right; // Покажчик на правого нащадка

    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

// Клас бінарного дерева стандартної форми
class BinaryTree {
private:
    TreeNode* root; // Корінь дерева

public:
    BinaryTree() : root(nullptr) {}

    // Додавання вузла в бінарне дерево
    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        }
        else {
            insertRecursive(root, value);
        }
    }

    // Рекурсивна функція для додавання вузла
    void insertRecursive(TreeNode* currentNode, int value) {
        if (value < currentNode->value) {
            if (currentNode->left == nullptr) {
                currentNode->left = new TreeNode(value);
            }
            else {
                insertRecursive(currentNode->left, value);
            }
        }
        else {
            if (currentNode->right == nullptr) {
                currentNode->right = new TreeNode(value);
            }
            else {
                insertRecursive(currentNode->right, value);
            }
        }
    }

    // Клас ітератора для обходу дерева
    class Iterator {
    private:
        TreeNode* current; // Поточний вузол
        std::stack<TreeNode*> stack; // Стек для збереження вузлів під час обходу

    public:
        Iterator(TreeNode* root) : current(root) {}

        // Перевірка, чи є ще елементи для обходу
        bool hasNext() const {
            return !stack.empty() || current != nullptr;
        }

        // Перехід до наступного елемента
        int next() {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            TreeNode* node = stack.top();
            stack.pop();
            int value = node->value;
            current = node->right;

            return value;
        }
    };

    // Повертає ітератор, починаючи з кореня дерева
    Iterator getIterator() const {
        return Iterator(root);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);

    BinaryTree::Iterator iterator = tree.getIterator();
    while (iterator.hasNext()) {
        std::cout << iterator.next() << " ";
    }
    std::cout << std::endl;

    return 0;
}
