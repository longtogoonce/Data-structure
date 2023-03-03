#include <stdio.h>
#include <string.h>
/*题目描述:
    n个不同大小的数a，每个有m个，是否能组成数字k*/

/*数据输入*/
int n=3;
int a[3]={3,5,8};
int m[3]={3,2,2};
int k=17;

/*算法分析
    对于每一层来说，都是判断当前元素a
    在dp[j]中，j代表当前背包的容量
    那么如果dp[j-a[i]]可以,只要当前的物品足够，则dp[j]也可
    所以用dp[j]的值代表当前物品的现存个数*/

/*算法代码*/
int dp[17+1];    

int solve(void)
{
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=k;j++)
            if(dp[j]>=0)
                dp[j]=m[i];
            else if(j<a[i]||dp[j-a[i]]<0)
                dp[j]=-1;
            else
                dp[j]=dp[j-a[i]]+1;
    return dp[k];    
}

int main()
{
    printf("%d",solve());
}


