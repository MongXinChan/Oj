#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#define MAX 4233
using namespace std;

class mp{
    public :
        int l,x[MAX];
        mp():l(1){
            x[0]=0;
        }
        mp operator=(const char*num){//用const是为了防止传数值过程中的变化
            l=strlen(num);
            for(int i=0;i<l;++i)
                x[i]=num[l-i-1]-'0';
            return *this;//也就是返回当前一整个对象的数值
        }
        mp operator=(const int num){
            char a[MAX];
            sprintf(a,"%d",num);
            *this=a;
            return *this;
        }
        mp (const int num){
            *this=num;
        }
        mp(const char* num){
            *this=num;
        }
        mp operator+(const mp& obj){
            mp c;
            c.l=max(l,obj.l)+1; 
            memset(c.x,0,sizeof(c.x)); //sizeof()和sizeof等价 
            for(int i=0,t=0;i<c.l;++i){
                c.x[i]=x[i]+obj.x[i]+t;
                t=c.x[i]/10;
                c.x[i]=c[x]%10;
            }
            if(c.x[c.l-1]==0)
                --c.l;      //减的原因是因为在模拟竖式的时候，最高位可能会进位，所以要减一位
        	return c;
		}
		mp operator * (const mp &obj){
		    mp c;
		    c.l = l + obj.l;
		    for(int i = 0; i < l; ++i)
		        for(int j = 0; j < obj.l; ++j){
		            c.x[i + j] += x[i] * obj.x[j];
		            c.x[i + j + 1] += c.x[i + j] / 10;
		            c.x[i + j] %= 10;
		        }
		    if(c.x[c.l - 1] == 0){
		        --c.l;
		    }
		    return c;
		}
};
ostream& operator<<(ostream &out, const mp &obj){//这里要使用引用,传入的数值用const
    for(int i=obj.l-1;i>=0;--i){
        out<<obj.x[i];
    }
    return out;
}
istream& operator>>(istream &in, mp &obj){//这里要使用引用
    char num[MAX];
    in>>num;
    obj = num;
    return in;
}
int main(){
    int n;
    mp ans=0,num=1;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
         num=num*i;
         ans=ans+num;
    }
    cout<<ans<<endl;
    return 0;
}
//input error*4









// #include<iostream>
// #include<cstring>
// #include<cstdio>
// #include<cmath>
// using namespace std;
// struct fantastic     //嗯，开始重载了
// {
//     int len,s[9999];
//     fantastic()
//     {
//         memset(s,0,sizeof(s));
//         len=1;
//     }
//     fantastic operator=(const char*num)
//     {
//         len=strlen(num);
//         for(int i=0;i<len;++i)
//             s[i]=num[len-i-1]-'0';
//         return *this;
//     }
    // fantastic operator=(const int num)
    // {
    //     char a[9999];
    //     sprintf(a,"%d",num);
    //     *this=a;
    //     return *this;
    // }
//     fantastic (const int num)
//     {
//         *this=num;
//     }
//     fantastic (const char * num)
//     {
//         *this=num;
//     }
//     fantastic operator+(const fantastic &a)   //这里在重载 “+” 的运算
//     {
//         fantastic c;
//         c.len=max(len,a.len)+1;                //这里就是我们熟悉的竖式模拟了
//         for(int i=0,x=0;i<c.len;++i)
//         {
//             c.s[i]=s[i]+a.s[i]+x;
//             x=c.s[i]/10;
//             c.s[i]=c.s[i]%10;
//         }
//         if(c.s[c.len-1]==0)
//             --c.len;
//         return c;
//     }
//     fantastic operator * (const fantastic &x)           //然后再来波 “*” 的运算
//     {
//         fantastic c;
//         c.len=len+x.len;                 //又是我们熟悉的竖式模拟
//         for(int i=0;i<len;++i)
//             for(int j=0;j<x.len;++j)
//             {
//                 c.s[i+j]+=s[i]*x.s[j];
//                 c.s[i+j+1]+=c.s[i+j]/10;
//                 c.s[i+j]%=10;
//             }
//         if(c.s[c.len-1]==0)
//             --c.len;
//         return c;
//     }
// };
// ostream& operator<<(ostream &out,const fantastic& x)   //重载一下输出
// {
//     for(int i=x.len-1;i>=0;--i)
//         cout<<x.s[i];
//     return out;
// }
// istream& operator>>(istream &in,fantastic &x)       //重载一下输入
// {
//     char num[9999];
//     in>>num;
//     x=num;
//     return in;
// }
// int main()         //然后就可以愉快的开始主程序啦
// {
//     int n;
//     fantastic ans=0,num=1;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         num=num*i;
//         ans=ans+num;
//     }
//     cout<<ans<<endl;
// }                                         //非常的简单明了