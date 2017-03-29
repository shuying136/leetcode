offer 编程习题，并查集应用

#include <iostream>
#include <cstdio>
using namespace std;

bool a[1005][1005];
int n, x, y;
int par[1000005];
int ran[1000005];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        ran[i] = 0;
        par[i] = i;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}


void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (ran[x] < ran[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if (ran[x] == ran[y])
            ran[x]++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int trans(int x, int y)
{
    return x * 1000 + y;
}

int main()
{
    init(1000005);
    cin >> n;
    int now = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        now++;
        c += 4;
        cin >> x >> y;
        a[x][y] = true;
        int tmp = trans(x, y);
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && nx < 1000 && ny >= 0 && ny < 1000 && a[nx][ny])
            {
                int t = trans(nx, ny);
                if (!same(tmp, t))
                {
                    unite(tmp, t);
                    now--;
                }
                c -= 2;
            }
        }
        cout << now << " " << i + 1 << " " << c << endl;
    }
    return 0;
}
