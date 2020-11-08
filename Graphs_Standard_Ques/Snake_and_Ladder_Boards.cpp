#include <bits/stdc++.h>
using namespace std;
struct queueEntry
{
    int v;   
    int dist;
};
int getMinDiceThrows(int move[], int N)
{
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
    queue<queueEntry> q;
    visited[0] = true;
    queueEntry s = {0, 0}; 
    q.push(s); 

    queueEntry qe; 
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v; 
        if (v == N-1)
            break;
        q.pop();
        for (int j=v+1; j<=(v+6) && j<N; ++j)
        {
            if (!visited[j])
            {
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;
                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
    return qe.dist;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int moves[n];
        for(int j=0;j<n;j++)
        {
            moves[j]=-1;
        }
        for(int j=0;j<m;j++)
        {
            int k1,k2;
            cin>>k1>>k2;
            moves[k1-1]=k2;
        }
        for(int j=0;j<k;j++)
        {
            int k1,k2;
            cin>>k1>>k2;
            moves[k1-1]=k2;
        }
        cout << getMinDiceThrows(moves, n)<<endl;
    }
}
