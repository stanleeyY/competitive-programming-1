#include <cstdio>
#include <cstring>
#define maxn 100 + 5
#define maxm 100 + 5

char field[maxn][maxm];
int n, m;

void dfs(int x, int y)
{
  field[x][y] = '.';
  //printf("changed\n");
  for (int dx = -1; dx <= 1; dx++)
  {
    for (int dy = -1; dy <= 1; dy++)
    {
      int nx = x + dx, ny = y + dy;
      if (field[nx][ny] == 'W' && 0 <= nx && nx < n && 0 <= ny && ny < m)
      {
        dfs(nx, ny);
      }
    }
  }
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  while(~scanf("%d%d\n", &n, &m))
  {
    int res = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        scanf("%c", &field[i][j]);
      }
      getchar();
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (field[i][j] == 'W')
        {
          dfs(i, j);
          res++;
        }
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
