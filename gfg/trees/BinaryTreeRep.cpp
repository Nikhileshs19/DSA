//User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        root0->data = vec[0];
        queue<struct node*> q;
        q.push(root0);
    
        int i = 1;
        while (!q.empty() && i < vec.size()) {
            struct node* current = q.front();
            q.pop();
    
            if (i < vec.size()) {
                current->left = newNode(vec[i]);
                q.push(current->left);
                i++;
            }
            if (i < vec.size()) {
                current->right = newNode(vec[i]);
                q.push(current->right);
                i++;
            }
        }
    }

};