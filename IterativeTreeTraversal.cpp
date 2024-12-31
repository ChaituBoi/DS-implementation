#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int val;
    node *left, *right;
};
void PreOrder(node* root)
{
    if(!root)
        return;
    stack<node*> st;


    cout<<"PreOrder:";
    node *curr = root;
    st.push(root);
    while(!st.empty())
    {
        curr = st.top();
        st.pop();
        cout<<curr->val<<"->";

        if(curr->right)//right first due to LIFO nature of stack
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
            
    }
}

void InOrder(node* root)
{
    if(!root)
        return;
    
    stack<node *> st;
    node *curr = root;
    cout << "InOrder:";
    while(!st.empty() || curr)
    {
        
        while(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        cout << curr->val << "->";
        st.pop();

        curr = curr->right;
    }
}

void PostOrder(node* root)
{
    stack<node *> st1, st2;
    st1.push(root);
    node *curr = root;
    while(!st1.empty())
    {
        curr = st1.top(); st1.pop();
        st2.push(curr); //preorder processed node first, but in post we need to keep it for later. This is what is happeining for second stack.
        
        if(curr->left) //why left 1st like in Preorder? Think about formation of numbers in st2.
            st1.push(curr->left);
        if(curr->right)
            st1.push(curr->right);
        
    }
    cout << "PostOrder:";
    while(!st2.empty())
    {
        cout << st2.top()->val << "->";
        st2.pop();
    }

}
int main()
{

    //              1
    //             / \
    //            2   3
    node *root = new node; root->val = 1;
    root->left = new node; root->left->val = 2; root->left->left = root->left->right = nullptr;
    root->right = new node; root->right->val = 3; root->right->left = root->right->right = nullptr;

    PreOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    InOrder(root);
    return 0;
}
