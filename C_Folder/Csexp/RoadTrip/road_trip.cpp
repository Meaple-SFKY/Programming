#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int n_max = 1e4 + 5;
const int m_max = 5e4 + 5;
const int inf = 0x3f3f3f3f;
int n, m, head[n_max], tot;
int hero[n_max], a[n_max], dis[n_max];
bool vis[n_max];

struct edge{
    int to, wp, wq, ww, next;
} ed[m_max*2];

inline void add( int u, int v, int p, int q ){
    ed[tot].to = v;
    ed[tot].wp = p;
    ed[tot].wq = q;
    ed[tot].ww = 0;
    ed[tot].next = head[u];
    head[u] = tot ++;
}

inline void dij1(int s){
    memset( vis, 0, sizeof(vis) );
    memset( hero, inf, sizeof(hero) );
    priority_queue< pair<int, int> > q;
    vis[s] = 1;
    hero[s] = 0;
    q.push( make_pair( 0, s ) );
    while( !q.empty() ){
        int u = q.top().second;
        q.pop();
        for(int i = head[u]; i != -1; i = ed[i].next){
            int v = ed[i].to;
            if(hero[v] > hero[u] + ed[i].wp){
                hero[v] = hero[u] + ed[i].wp;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(make_pair(-hero[v], v));
                }
            }
        }
    }
}

inline void dij2(int s){
    memset(vis, 0, sizeof(vis));
    memset(a, inf, sizeof(a));
    priority_queue<pair<int, int> > q;
    a[s] = 0;
    q.push(make_pair(0, s));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if( vis[u] ) continue;
        vis[u] = 1;
        for(int i = head[u]; i != -1; i = ed[i].next) {
            int v = ed[i].to;
            if(a[v] > a[u]+ed[i].wq) {
                a[v] = a[u]+ed[i].wq;
                q.push(make_pair(-a[v], v));
            }
        }
    }
}

inline void dij3(int s) {
    memset(vis, 0, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    priority_queue< pair<int, int> > q;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u])
            continue;
        vis[u] = 1;
        for(int i = head[u]; i != -1; i = ed[i].next) {
            int v = ed[i].to;
            if(dis[v] > dis[u] + ed[i].ww) {
                dis[v] = dis[u] + ed[i].ww;
                q.push(make_pair(-dis[v], v));
            }
        }
    }
}

inline void bfs(int s){
    queue<int> q;
    memset( vis, 0, sizeof(vis) );
    vis[s] = 1;
    q.push(s);
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        for( int i=head[u]; i!=-1; i=ed[i].next ){
            int v = ed[i].to;
            if( !vis[v] ){
                vis[v] = 1;
                if( hero[v]+ed[i].wp>hero[u] ) ed[i].ww ++;
                if( a[v]+ed[i].wq>a[u] ) ed[i].ww ++;
            }
        }
    }
}

int main(void) {
    // freopen("in.txt", "r", stdin);
    tot = 0;
    memset( head, -1, sizeof(head) );
    cin >> n >> m;
    for( int i=0; i<m; i++ ){
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        add( u, v, p, q );
        add( v, u, p, q );
    }
    dij1(n);
    dij2(n);
    bfs(1);
    dij3(1);
    cout << dis[n] << endl;

    return 0;
}