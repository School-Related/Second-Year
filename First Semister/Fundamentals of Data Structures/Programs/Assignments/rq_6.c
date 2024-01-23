#include <stdio.h>
int pre_sum[11][301][301];
int n;

void bin(int num)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre_sum[num][i][j] += pre_sum[num][i - 1][j] + pre_sum[num][i][j - 1] - pre_sum[num][i - 1][j - 1];
        }
    }
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            scanf("%d", &x);
            pre_sum[x][i][j] = 1;
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        bin(i);
    }
    int query;
    scanf("%d", &query);
    int x1, x2, y1, y2;
    for (int i = 1; i <= query; i++)
    {
        scanf("%d", &x1);
        scanf("%d", &y1);
        scanf("%d", &x2);
        scanf("%d", &y2);
        int ans = 0;
        for (int j = 1; j <= 10; j++)
        {
            if (pre_sum[j][x2][y2] - pre_sum[j][x1 - 1][y2] - pre_sum[j][x2][y1 - 1] + pre_sum[j][x1 - 1][y1 - 1])
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}