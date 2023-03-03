#include <stdio.h>
int max(int num1, int num2) 
{
   int result;
 
   if (num1 > num2) 
      result = num1;
    else 
      result = num2;
   return result; 
}
/*数据输入*/
int n=3;
int w[4]={0,3,4,2};
int v[4]={0,4,5,3};
int W=7;

/*朴素算法*/

int dp[3+1]; //压缩状态的dp数组

int solve(int i,int j,int k) //i代表当前的物品
{
    for(i=1;i<=n;i++)
        for(j=W;j>=1;j--)
            for(k=0;k<=j/w[i];k++)
                dp[j]=max(dp[j],dp[j-k*w[i]]+k*v[i]);
    return dp[W];
}

/*算法改进思想*/
//压缩状态的dp数组中j代表当空间为j时，可以放入的最优价值
/*对max函数的理解：
    dp[j]代表没有加入当前物品，但已经加入之前物品且空间为j的最优价值
    dp[j-k*w[i]]+k*v[i]代表加入k个当前物品的最优价值*/
/*改进思路：
    你也发现了，在k从0到j/w[i]的过程中，肯定是当k取最大值时，最大
    所以只需要比较k为最大值时，与不加入当前物品的值就行*/
/*01问题与完全背包的区别：
    在dp压缩状态中，因为d[j]值的更新都是dp[j]=max(dp[j],dp[j-w[i]]+v[i])
    在01中，因为dp值的更新来自于比当前空间容量更小的且是上一层的dp值，所以更新值时，应该倒叙
    在完全背包中，因为dp值的更新来自于空间容量更小，但是当前层的dp值，所以更新值时，应该顺序*/

int dp2[3+1];

int solve2(int i,int j)
{
    for(i=1;i<=n;i++)
        for(j=w[i];j<=W;j++)    //直接从w[i]开始，因为在这之前，j<w[i],dp值保持不变
           dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    return dp[W];
}
int main()
{
    int k=0;
    printf("%d\n",solve(n,W,k));
    printf("%d",solve2(n,W));
}
