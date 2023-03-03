/*动态规划即总任务的实现可以由子任务的最优解来实现，并且子任务的最优解是已知的
同时，引入数组将一些重复调用计算的子任务的值加以记录，可以优化总任务的实现效率*/

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
/*背包问题的代码逻辑：
    经典的动态规划问题，同样借助父任务总是由子任务推导而成
    在背包问题的逻辑中，后面物体的存放与前一个物体的是否放入有关系
    如果放入，则空间变小，但是当前价值变大
    如果不放入，则空间不变，价值不变
    所以对于每一个物体来说，如果当前的空间不足以放入该物体，则当前价值与前一个选择一致
    如果空间足够，则面临两个选择，一个是放入，一个是不放入
    由于底层（即开始状态）的价值可以确定
    所以从底层开始，对于每一次选择都通过max函数来确定当前最优解
    既然从底层开始的每一步都是最优解，那么最终的价值则为最优解*/

/*背包问题：有n个重量为w,v的物品，挑选总重不超过W，且总价值最大*/
    int n=3;
    int w[3]={1,2,3};
    int v[3]={1,2,3};
    int W=5; 

/*首先是朴素算法，即利用二叉树的形式，在每一个节点中对当前物体有加入与不加入的两种分支*/
int rec(int i,int j)//i代表当前第i个物品，j代表当前背包所剩空间
{
    int res;
   
    if(i==n)               //如果已经没有剩余物品
        res=0;      
    else if(j<w[i])        //如果对于当前物品，剩余空间不足
        res=rec(i+1,j);
    else                   //正常状态下，分支
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    return res;
}

/*其次是朴素算法的记忆化处理*/

int dp[3][5]; //建立记忆化数组

int rec2(int i,int j)
{
    if(dp[i][j]>0)
        return dp[i][j];

    int res;
    if(i==n)
        res=0;
    else if(j<w[i])
        res=rec2(i+1,j);
    else
        res=max(rec2(i+1,j),rec2(i+1,j-w[i])+v[i]);
    return dp[i][j]=res;
}

/*递归和记忆化数组的处理，本质上是按照一定的递推公式，且最底层在i==n时，数值已经确定
由最底层向上层逐一获取值的过程，那么便可以借助二维数组从底层来实现*/

int dp2[3][5];

int rec3()
{
    int i,j;
    for(i=n-1;i>=0;i--){
        for(j=0;j<=W;j++){
            if(j<w[i])
                dp[i][j]=dp[i+1][j];
            else
                dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    
    return dp2[0][W];
}

int main()
{
    printf("%d\n",rec(0,W));
    printf("%d",rec2(0,W));
    printf("%d\n",dp2[0][W]);
    return 0;
}



