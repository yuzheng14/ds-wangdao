void Initial(int S[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        S[i] = -1;
}

int Find(int S[], int x)
{
    while (S[x] > -1)
        x = S[x];
    return x;
}