// 파일처리 과제 3
// 이진트리 - 전위순회방식
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int menu;
int flag = 0;
int select_menu() {
    printf("\n0: 종료\n");
    printf("1: 검색\n");
    printf("2: 삽입\n");
    printf("3: 삭제\n");
    printf("4: 출력\n");
    printf("메뉴를 선택하세요: ");
    scanf("%d", &menu);
    return menu;
}

template <typename T>
struct Node {
private:
    T data;
    Node* left;
    Node* right;
public:
    Node(T _data, Node* _left, Node* _right) {
        data = _data;
        left = _left;
        right = _right;
    }
    ~Node() {}

    // getter/setter
    T getData() {
        return data;
    }
    void setData(T _data) {
        data = _data;
    }
    Node* getLeft() {
        return left;
    }
    void setLeft(Node* _left) {
        left = _left;
    }
    Node* getRight() {
        return right;
    }
    void setRight(Node* _right) {
        right = _right;
    }

    bool isLeaf() {
        return left == nullptr && right == nullptr;
    }

    // Node 멤버함수로 순환탐색 구현
    Node* search(T key) {
        if (key == data)                         // key == 노드의 data
            return this;
        else if (key < data && left != NULL)     // key < 노드의 data
            return left->search(key);
        else if (key > data && right != NULL)    // key > 노드의 data
            return left->search(key);
        else                                    // 탐색이 실패한 경우
            return NULL;
    }
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;
public:
    BinaryTree() {
        root = nullptr;
    }
    ~BinaryTree() {}

    // set root node
    void setRoot(Node<T>* _root) {
        root = _root;
    }
    // get root node
    Node<T>* getRoot() {
        return root;
    }

    // 전위 순회
    void preorder() {
        preorder(root);
    }
    void preorder(Node<T>* node) {
        if (node != NULL) {
            cout << node->getData() << " ";
            preorder(node->getLeft());
            preorder(node->getRight());
        }
    }

    bool isEmpty() {
        return root == nullptr;
    }

};

// 이진탐색트리 (이진트리 상속)
template <typename T>
class BinarySearchTree : public BinaryTree<T> {
private:
    // 탐색 (반복)
    Node<T>* searchIter(Node<T>* node, T key) {
        while (node != NULL) {
            if (key == node->getData()) return node;     // key == root 노드의 data
            else if (key < node->getData()) node = node->getLeft();   // key < root 노드의 data
            else if (key > node->getData()) node = node->getRight();  // key > root 노드의 data
        }
        return NULL;    // 탐색이 실패한 경우 NULL 반환
    }

    // 삽입 (순환)
    void insertRecur(Node<T>* node, T key) {
        Node<T>* newNode = new Node<T>(key, nullptr, nullptr);  // 새로운 key를 가지는 node 생성

        if (key == node->getData()) {         // 트리에 이미 key값을 가지는 node가 있는 경우
            return;
        }
        else if (key < node->getData()) {    // key < root 노드의 data
            if (node->getLeft() == NULL) {
                node->setLeft(newNode);
            }
            else {
                insertRecur(node->getLeft(), key);
            }
        }
        else if (key > node->getData()) {    // key > root 노드의 data
            if (node->getRight() == NULL) {
                node->setRight(newNode);
            }
            else {
                insertRecur(node->getRight(), key);
            }
        }
    }

    // 삭제
    void remove(Node<T>* parentNode, Node<T>* deleteNode) {
        // Case1. 삭제하려는 node가 leaf 노드인 경우
        if (deleteNode->isLeaf()) {
            if (deleteNode == this->getRoot()) {     // 삭제하려는 node가 root인 경우
                this->setRoot(nullptr);
            }
            else {
                if (parentNode->getLeft() == deleteNode) {        // parent의 왼쪽 자식노드 삭제
                    parentNode->setLeft(nullptr);
                }
                else if (parentNode->getRight() == deleteNode) { // parent의 오른쪽 자식노드 삭제
                    parentNode->setRight(nullptr);
                }
            }
        }
        // Case2. 삭제하려는 node가 하나의 자식노드만 갖는 경우
        else if (deleteNode->getLeft() == NULL || deleteNode->getRight() == NULL) {
            Node<T>* childNode = (deleteNode->getLeft() != NULL) ? deleteNode->getLeft() : deleteNode->getRight();  // 삭제할 node의 유일한 자식노드

            if (deleteNode == this->getRoot()) {    // 삭제하려는 node가 root인 경우
                this->setRoot(childNode);
            }
            else {
                if (parentNode->getLeft() == deleteNode) {        // parent의 왼쪽 자식노드에 childNode link
                    parentNode->setLeft(childNode);
                }
                else if (parentNode->getRight() == deleteNode) { // parent의 오른쪽 자식노드 childNode link
                    parentNode->setRight(childNode);
                }
            }
        }
        // Case3. 삭제하려는 node가 2개의 자식노드를 모두 갖는 경우
        else {
            // 삭제하려는 노드의 오른쪽 서브트리에서 가장 작은 노드를 탐색하는 과정
            Node<T>* succp = deleteNode;
            Node<T>* succ = deleteNode->getLeft();
            while (succ->getRight() != NULL) {
                succp = succ;
                succ = succ->getRight();
            }

            // 3-1. 후계자 노드의 부모와 후계자 노드의 자식 연결
            if (succp->getRight() == succ) {
                succp->setRight(succ->getLeft());
            }
            else {  // 후계자 노드가 삭제할 노드의 바로 오른쪽 자식인 경우
                succp->setLeft(succ->getLeft());
            }

            // 3-2. 삭제할 노드의 data를 후계자노드의 data로 대체
            deleteNode->setData(succ->getData());

            // 3-3. 삭제할 노드를 후계자노드로 변경 (후계자노드를 delete 하기 위해)
            deleteNode = succ;
        }

        delete deleteNode;  // memory 반납
    }

public:
    BinarySearchTree() {}
    ~BinarySearchTree() {}

    // 탐색
    Node<T>* search(T key) {
        //return searchRecur(this->getRoot(), key);
        return searchIter(this->getRoot(), key);
    }

    // 삽입
    void insert(T key) {
        if (this->isEmpty()) {
            Node<T>* newNode = new Node<T>(key, nullptr, nullptr);  // 새로운 key를 가지는 node 생성
            this->setRoot(newNode);
        }
        else {
            insertRecur(this->getRoot(), key);
        }
    }

    // 삭제
    void remove(T key) {
        if (flag == 0) {
            if (this->isEmpty()) printf("삭제할 키 값 [%d]는 트리에 없습니다.\n", key);
            else printf("삭제할 키 값 [%d]는 트리에 있습니다.\n", key);
            return;
        }
        else {

            // parentNode와 deleteNode를 찾는 과정
            Node<T>* parentNode = nullptr;          // 삭제하려는 node의 부모 node (최초 root의 부모노드는 없음)
            Node<T>* deleteNode = this->getRoot();    // 삭제하려는 node
            while (deleteNode != NULL && deleteNode->getData() != key) {
                parentNode = deleteNode;
                deleteNode = (key < parentNode->getData()) ? parentNode->getLeft() : parentNode->getRight();
            }

            if (deleteNode == NULL) {
                printf("삭제할 키 값 [%d]은 트리에 없습니다.\n", key);
                return;
            }
            else {
                remove(parentNode, deleteNode);
            }
        }

    }

};

int main() {
    BinarySearchTree<int> tree;

    while (select_menu()) {
        // 검색이라면
        if (menu == 1) {
            int key;
            printf("검색할 키 값을 입력하세요: ");
            scanf("%d", &key);
            if (tree.search(key)) printf("찾는 키 값 [%d]는 트리에 있습니다.\n", key);
            else printf("찾는 키 값 [%d]는 트리에 없습니다.\n", key);
        }
        // 삽입이라면
        else if (menu == 2) {
            printf("삽입할 키 값을 입력하세요: ");
            int key;
            scanf("%d", &key);
            tree.insert(key);
        }
        // 삭제라면
        else if (menu == 3) {
            flag = 1;
            printf("삭제할 키 값을 입력하세요: ");
            int key;
            scanf("%d", &key);
            tree.remove(key);
        }
        // 출력이라면
        else if (menu == 4) {
            printf("출력 결과>> ");
            tree.preorder();
            printf("\n");
        }
    }
    return 0;
}
