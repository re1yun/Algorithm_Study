/**
 * @file 타겟 넘버.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief return number of possible combination of numbers that sum is equal to target
 * @version 0.1
 * @date 2023-04-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <queue>

using namespace std;

// define node
struct Node{
    int value;
    Node* left;
    Node* right;

    Node(int val, int sig){
        value = val * sig;
        left = NULL;
        right = NULL;
    }
};

void addLeaves(Node* node, int num){
    if(node == nullptr)
        return;
    if(node->left == nullptr && node->right == nullptr){
        Node* left = new Node(num, 1);
        Node* right = new Node(num, -1);
        node->left = left;
        node->right = right;
        return;
    }
    addLeaves(node->left, num);
    addLeaves(node->right, num);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    // construct tree
    Node* root = new Node(0, 1);
    for(int number : numbers){
        addLeaves(root, number);
    }
    // traverse tree and modify values
    queue<Node*> que;
    que.push(root);
    while(!que.empty()){
        Node* current = que.front();
        que.pop();
        if(current->left == nullptr && current->right == nullptr && current->value == target){
            answer++;
        }
        if(current->left != nullptr && current->right != nullptr){
            current->left->value += current->value;
            current->right->value += current->value;
            que.push(current->left);
            que.push(current->right);
        }
    }
    return answer;
}