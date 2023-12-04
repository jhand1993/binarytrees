struct Node{
    /* 
    Single binary tree element. Right and left pointers (lp and rp) point to
    respective child nodes.
    */
    int val;
    Node *lp;
    Node *rp;
};


class BinaryTree{
    /* 
    Full binary tree that fills from left to right, then down.
    */
    // Instantiate root node.
    Node *root;
    public:
        // Instantiate empty binary tree. 
        BinaryTree(){
            root = nullptr;
        }
        
        // Check to see if empty.
        bool isempty(){
            return (root == nullptr);
        }
        
        void insert_node(int new_data){
            // Allocate memory for new node.
            Node *new_node = new Node;
            Node *parent;

            // Assign attribute values for node at pointer 'new_data'.
            new_node->val = new_data;
            new_node->lp = nullptr;
            new_node->rp = nullptr;
            parent = nullptr;

            // If the tree is empty, then the new node is the tree.
            if (isempty){
                root = new_node;
            }
            // Else, add node to the existing root.
            else {
                // Instantiate Node pointer.
                Node *p;
                // Assign to the current root pointer.
                p = root;
                // While p is not nullptr, starting with parent node pointer,
                // loop through all linked elements until top of parent is reached.
                while (p != nullptr){
                    parent = p;
                    if (parent->lp != nullptr) {
                        p = parent->rp;
                    }
                    else {
                        p = parent->lp;
                    }
                }
                // 
                if (parent->lp != nullptr) {
                    parent->rp = new_node;
                }
                else {
                    parent->lp = new_node;
                }
            }
        }
};