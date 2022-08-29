void findpar(int s, int T){
    for(int x:adj[s]){
        if(x!=T){
            par[x] = s;
            h[x] = h[s]+1;
            findpar(x,s);
        }
    }
}

void build(){
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; 1 << j <= n; j++)
        P[i][j] = -1;

    for (i = 1; i <= n; i++){
        P[i][0] = par[i];
        //cout << P[i][0] << endl;
    }

    for (j = 1; 1 << j <= n; j++)
        for (i = 1; i <= n; i++)
            if (P[i][j - 1] != -1)
                {
                    P[i][j] = P[P[i][j - 1]][j - 1];
                    //cout << P[i][j] << endl;
                }
}

int lca(int u,int v){
    if(h[u] != h[v]){
        if(h[u] < h[v])swap(u,v);

        int k = h[u] - h[v];

        for(int i = 0;(1 << i) <= k;i++){
            if(k >> i & 1)u = P[u][i];
        }
    }

    if(u == v)return u;
    int k = log2(h[u]);

    for(int i = k;i>=0;i--){
        if(P[v][i] != P[u][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}
