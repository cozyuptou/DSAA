#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vt vector <int>
#define vtl vector <ll>
#define vts vector <string>
#define matrix vector <vector <int>>
#define matrixl vector <vector <ll>>
const ll MOD = 1e9 + 7;

int n, e, s;
vector <pair <int, int>> vp;
matrix M;

void dfs() {
    vt mark(n + 1, 1);
    stack <int> st;
    st.push(s);
    mark[s] = 0;
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        for (auto i : M[x]) {
            if (mark[i]) {
                mark[i] = 0;
                vp.push_back({ x,i });
                st.push(x), st.push(i);
                break;
            }
        }
    }
    if (vp.size() == n - 1) {
        for (auto i : vp) cout << i.first << " " << i.second << endl;
    }
    else cout << "-1" << endl;
}

void solution() {
    vp.clear();
    cin >> n >> e >> s;
    M = matrix(n + 1);
    for (int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    dfs();
}

int main() {
    faster();
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}