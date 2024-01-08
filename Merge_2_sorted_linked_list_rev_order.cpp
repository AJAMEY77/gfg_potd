//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * reverse(Node *n)
    {
        Node *prev = NULL, *curr = n, *nex = n;
        
        while(curr)
        {
            nex = nex->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
        
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        if(node1 == NULL) return reverse(node2);
        if(node2 == NULL) return reverse(node1);
        
        struct Node *temp1 = node1;
        struct Node *temp2 = node2;
        
        struct Node *temp = NULL;
        int ans = 0;
        if(temp1->data < temp2->data)
        {
            temp = temp1;
            temp1 = temp1->next;
            ans = 1;
        }
        else
        {
            temp = temp2;
            temp2 = temp2->next;
            ans = 2;
        }
        
        while(temp1 && temp2)
        {
            if(temp1->data < temp2->data)
            {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }
        
        while(temp1)
        {
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        }
        while(temp2)
        {
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
        if(ans == 1) return reverse(node1);
        if(ans == 2) return reverse(node2);
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends