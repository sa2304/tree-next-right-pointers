#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        m_treeLevels.clear();
        visitNode(root, 0);
        connectNodes();

        return root;
    }

private:
    void visitNode(Node* node, int depth) {
        if (node) {
            m_treeLevels[depth].push_back(node);
            visitNode(node->left, depth+1);
            visitNode(node->right, depth+1);
        }
    }

    void connectNodes() {
        for (const auto & [depth, level] : m_treeLevels) {
            for (auto iter = level.begin() + 1; iter != level.end(); ++iter) {
                (*std::prev(iter))->next = *iter;
            }
        }
    }

    std::map<int, std::vector<Node*>> m_treeLevels;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
