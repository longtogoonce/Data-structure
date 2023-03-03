#include <stdio.h>
#include <string.h>
/*KMP匹配算法指在一个长串中寻找一个子串
常规的做法是对于这两个串我们进行依次的匹配，所以匹配的次数与长串的大小与子串的大小都有关系
而KMP的做法是第一让主串的值没有回溯
第二对于这个子串进行分析，从而获得这个next数组，这个数组记录的是如果当前位置没有进行匹配，直接跳转到最优的地方*/

/*值得注意的是i与j这两个变量，j代表的是当前T字符串的下标，该值不会回溯，i代表的是在j下标所对应元素所相关联的值
也即最优的跳转地方
所以有了i=next[i]这个表达式
例如对于字符串“ababaaaba”
i=next[i]可能有两种情况
第一种是前面没有相匹配的值，如“ab”,此时i=next[0]=-1,也即从新计数
第二种情况在于有匹配的值，如在“ababa”字符串之后的‘a’与‘b’，由于j值不变，所以向前依次回溯
如同“aaaab”这种一样*/

void getnext(char *,int *);
void getnextval(char *,int *);
int KMP(char *,char *,int *);

int main()
{
    int kmp;
    char S[]="abababababaaabaccaa";
    char T[]="ababaaaba";
    int next[1024];
    getnextval(T,next);//getnaxt(str,next);
    kmp=KMP(S,T,next);
    printf("该子串位于第%d个位置",kmp);
    return 0;
}

void getnext(char *T,int *next)
{
    int i,j;
    i=-1;
    j=0;
    next[0]=-1;
    while(j<strlen(T)){
        if(i==-1||T[i]==T[j]){
            i++;
            j++;
            next[j]=i;
        }
        else
            i=next[i];  /*向前依次检索可能会匹配的值*/
    }
}

/*为了解决如同“aaaab”这种形式的重复问题，问题出在i变量在不相匹配的回溯值
而i的回溯值是由于i=next[i]这个表达式所引起的，而next数组的值又是由于next[j]=i所确定的
故我们在这里加入判断*/

void getnextval (char *T,int *nextval)
{
    int i=-1,j=0;
    nextval[0]=-1;
    while(j<strlen(T)){
        if(i==-1||T[i]==T[j]){
            i++,j++;
            if(T[i]!=T[j])
                nextval[j]=i;
            else
                nextval[j]=nextval[i];
        }
        else
            i=nextval[i];
    }
}

int KMP(char *S,char *T,int *next)
{
    int s=0,t=0;
    while(s<=strlen(S)&&t<=strlen(T)){
        if(S[s]==T[t]||t==-1)
        {
            s++;
            t++;
        }
        else
            t=next[t];
    }
    if(s<=(strlen(S)+1))
        return s-strlen(T);
    else
        return 0;
}