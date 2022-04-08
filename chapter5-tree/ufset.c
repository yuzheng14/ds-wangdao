void Initial(int S[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        S[i] = -1;
}

int Find(int S[], int x)
{
    int root = x;
    // 找到根
    while (S[root] > -1)
        root = S[root];
    // 循环将 x 上的双亲连接到根，降低树的高度
    while (x != root)
    {
        int t = S[x];
        S[x] = root;
        x = t;
    }
    return x;
}

void Union(int S[], int root1, int root2)
{
    // 根节点存树高度的负数
    if (root1 == root2)
        return;
    if (S[root2] > S[root1])
    {
        S[root1] += S[root2];
        S[root2] = root1;
    }
    else
    {
        S[root2] += S[root1];
        S[root1] = root2;
    }
}