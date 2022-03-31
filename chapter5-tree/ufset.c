void Initial(int S[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        S[i] = -1;
}

int Find(int S[], int x)
{
    int root = x;
    while (S[root] > -1)
        root = S[root];
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