typedef char ElemType;
#define MAX_TREE_SIZE 100

// 双亲表示法
typedef struct
{
    ElemType data;
    // 父结点指针
    int parent;
} PTNode;
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    // 结点数量
    int n;
} PTree;

// 孩子表示法
typedef struct CTNode
{
    // 孩子结点位置
    int child;
    // 下一个孩子结点位置指针
    struct CTNode *next;
} CTNode;
typedef struct
{
    ElemType data;
    // 第一个孩子结点指针
    CTNode *firstChild;
} CTBox;
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    // 结点数和根的位置；
    int n, r;
} CTree;

// 孩子兄弟表示法
typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

// 以下算法均使用孩子兄弟表示法表示的森林
// 树和森林的前序（先跟）遍历和二叉树的前序遍历一样
// 树和森林的后续（后根）遍历和二叉树的中序遍历一样
void PreOrder(CSTree T, void (*visit)(CSNode *));
void PostOrder(CSTree T, void (*visit)(CSNode *));
void LevelOrder(CSTree T, void (*visit)(CSNode *));

void PreOrderForest(CSTree T, void (*visit)(CSNode *));