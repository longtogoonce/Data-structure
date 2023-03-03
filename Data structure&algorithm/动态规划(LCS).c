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

/*最长公共子序列的代码逻辑：
    经典的动态规划问题，同样父任务的完成也是由子任务完成
    而这里的子任务便是比父字符串短一点的字符串
    从空串出发进而推导出所有公共子串
    所有有两种状态：
    第一种：如果当前两串的最后一个字符相同，则dp[i][j]=dp[i-1][j-1]+1
    第二种：如果当前串最后字符不相同，则dp[i][j]=max(dp[i-1][j],dp[i][j-1])*/

int dp[4+1][4+1];

int main()
{
    int n=4,m=4,i,j;
    char S[]="abcd";
    char T[]="becd";

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(S[i]==T[j])
                dp[i+1][j+1]=1+dp[i][j];
            else
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}
