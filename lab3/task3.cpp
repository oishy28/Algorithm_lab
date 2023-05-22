class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                for (Node* child : curr->children) {
                    q.push(child);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};
