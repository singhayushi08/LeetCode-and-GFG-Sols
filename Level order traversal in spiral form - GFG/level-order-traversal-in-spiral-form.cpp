//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    // exactly the opposite of zigzag order
    // on 0th level we want R->L and the next level we want L->R and so on..
    
    // Approach1: using two stacks, TC: O(N), SC: O(N)
    // vector<int> ans;
    // if(root == NULL) return ans;
    // stack<Node*> left_to_right; //coz first we want right to left, so take opposite. It stores nodes in order left to right
    // stack<Node*> right_to_left; //next we want left to right, so take opposite. It stores nodes in order right to left
    // left_to_right.push(root);
    
    // while(left_to_right.size() != 0 || right_to_left.size() != 0) {
        
    //     // first R->L
    //     while(left_to_right.size() != 0) { 
    //         Node* temp = left_to_right.top();
    //         left_to_right.pop();
    //         ans.push_back(temp->data);
            
    //         if(temp->right != NULL) {
    //             right_to_left.push(temp->right);
    //         }
    //         if(temp->left != NULL) {
    //             right_to_left.push(temp->left);
    //         }
    //     }
        
    //     // then L->R
    //     while(right_to_left.size() != 0) {
    //         Node* temp = right_to_left.top();
    //         right_to_left.pop();
    //         ans.push_back(temp->data);
            
    //         if(temp->left != NULL) {
    //             left_to_right.push(temp->left);
    //         }
    //         if(temp->right != NULL) {
    //             left_to_right.push(temp->right);
    //         }
    //     }
    // }    
    
    // return ans;
    
    // Approach 2 => using queue, TC: O(N), SC: O(N)
    // traverse level order wise and just maintain a flag to change order
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    bool right_to_left = true;
    
    while(!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for(int i=0; i<size; i++) {
            Node* front = q.front();
            q.pop();
            int index = (right_to_left == true) ? size-i-1 : i;
            level[index] = front->data;
            
            if(front->left != NULL) {
                q.push(front->left);
            }
            if(front->right != NULL) {
                q.push(front->right);
            }
        }
        //curr level is over, so change the bool
        right_to_left = !right_to_left;
        for(auto i: level) { 
            ans.push_back(i);
        }
    }
    
    return ans;
    
}

