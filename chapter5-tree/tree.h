
// 双亲表示法
#define MAX_TREE_SIZE 100

typedef char ElemType;

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