unsigned long xor128 () {
    unsigned static long xor128_x=123456789, xor128_y=362436069, xor128_z=521288629, xor128_w=88675123;
    unsigned long t=(xor128_x^(xor128_x<<11));
    xor128_x=xor128_y; xor128_y=xor128_z; xor128_z=xor128_w;
    return ( xor128_w=(xor128_w^(xor128_w>>19))^(t^(t>>8)));
}

typedef struct TreapNode{
    int key;
    int sum;
    unsigned long priority;
    TreapNode *left, *right, *parent;
    TreapNode(int key, unsigned long priority){
        this->key = key;
        this->priority = priority;
        left = right = parent = nullptr;
        sum = 0;
    }
}Node;

struct Treap{
    Node *root;
    Treap(){
        root = nullptr;
    }

    bool isleft(Node *t){
        if(t->parent == nullptr) return true;
        if(t->parent->left == t) return true;
        else return false;
    }

    Node *right_rotate(Node* t){
        if(t->left == nullptr) return t;
        Node *s = t->left;
        Node *pp = t->parent;
        Node *sr = s->right;
        if(pp){
            if(isleft(t)) pp->left = s;
            else pp->right = s;
        }
        s->parent = pp;
        s->right = t;
        t->parent = s;
        if(sr) sr->parent = t;
        t->left = sr;
        if(s->parent == nullptr) root = s;
        return s;
    }

    Node *left_rotate(Node *t){
        if(t->right == nullptr) return t;
        Node *s = t->right;
        Node *pp = t->parent;
        Node *sl = s->left;
        if(pp){
            if(isleft(t)) pp->left = s;
            else pp->right = s;
        }
        s->parent = pp;
        s->left = t;
        t->parent = s;
        if(sl) sl->parent = t;
        t->right = sl;
        if(s->parent == nullptr) root = s;
        return s;
    }

    void fix_heap(Node *t){
        if(t->parent == nullptr) return;
        if(t->parent->priority < t->priority){
            left_rotate(t->parent);
            fix_heap(t);
        }
        return;
    }

    void insert(int key){
        Node *t = new Node(key, xor128());
        if(!root){
            root = t;
            return;
        }
        Node *s = root;
        while(true){
            if(t->key <= s->key){
                if(s->left) s = s->left;
                else{
                    s->left = t;
                    t->parent = s;
                    break;
                }
            }else{
                if(s->right) s = s->right;
                else{
                    s->right = t;
                    t->parent = s;
                    break;
                }
            }
        }
        fix_heap(t);
    }

    void remove(int key){
        if(!find(key)) return;
        Node *s = root;
        while(s->key != key){
            if(s->key < key) s = s->right;
            else s = s->left;
        }
        while(true){
            if(s->right) left_rotate(s);
            else if(s->left) right_rotate(s);
            else break;
        }
        s->parent->left = nullptr;
        delete s;
    }

    bool find(int key){
        Node *s = root;
        while(s){
            if(s->key == key) return true;
            else if(s->key < key) s = s->right;
            else s = s->left;
        }
        return false;
    }

    void print_in(Node *s){
        if(s->left) print_in(s->left);
        printf("key:%d, priority:%lu\n", s->key, s->priority);
        if(s->right) print_in(s->right);
    }

    void print_pre(Node *s){
        printf("key:%d, priority:%lu\n", s->key, s->priority);
        if(s->left) print_pre(s->left);
        if(s->right) print_pre(s->right);
    }

};