#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void levelOrder(Node* root) {
    if (root == NULL) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        cout << curr->data << " ";
        
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    
    map<int, Node*> m;
    Node* root = NULL;
    
    for (int i = 0; i < n; i++) {
        int u, v;
        char x;
        cin >> u >> v >> x;
        
        if (m.find(u) == m.end()) {
            m[u] = new Node(u);
            if (root == NULL) {
                root = m[u];
            }
        }
        
        if (m.find(v) == m.end()) {
            m[v] = new Node(v);
        }
        
        if (x == 'L') {
            m[u]->left = m[v];
        } else if (x == 'R') {
            m[u]->right = m[v];
        }
    }
    
    levelOrder(root);
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}