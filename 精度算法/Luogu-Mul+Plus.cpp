#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#define MAX 4233
using namespace std;

class mp{
public:
    int l,x[MAX];
    mp():l(1),x{0}{}
//	mp(){
//		l=1;
//		x[0]=0;
//	}
    mp& operator=(const char*num){
        l=strlen(num);
        for(int i=0;i<l;++i)
            x[i]=num[l-i-1]-'0';
        x[l] = 0; // ???????????????0	
        return *this;
    }
    mp& operator=(const int num){
        char a[MAX];
        sprintf(a,"%d",num);
        *this=a;
        return *this;
    }
    mp (const int num){
        *this=num;
    }
    mp (const char* num){
        *this=num;
    }
    mp operator+(const mp& a) {
        mp c;
        c.l = max(l, a.l);
        for (int i = 0, t = 0; i < c.l; ++i) {
            c.x[i] = x[i] + a.x[i] + t;
            t = c.x[i] / 10;
            c.x[i] %= 10;
        }
        if (c.x[c.l - 1] == 0) --c.l;
        return c;
    }

    mp operator*(const mp& obj) {
        mp c;
        c.l = l + obj.l;
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < obj.l; ++j) {
                c.x[i + j] += x[i] * obj.x[j];
                c.x[i + j + 1] += c.x[i + j] / 10;
                c.x[i + j] %= 10;
            }
       	if (c.x[c.l - 1] == 0) --c.l;
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

/*other solution1:*/

#include<stdio.h>
int main()
{
    int i,A[1005]={0},B[1005]={0},n,j;      //初始值0
    scanf("%d", &n);
    A[0]=B[0]=1;
    for (i=2;i<=n;i++){
        for (j=0;j<100;j++)
            B[j]*=i;                        //各自存入i的阶乘
        for (j=0;j<100;j++)
            if (B[j]>9){                    //逢十进一
                B[j+1] += B[j]/10;
                B[j]%=10;
            }
        for (j=0;j<100;j++){                //由于n小于50，把B的值加到A中
            A[j]+=B[j];
            if (A[j]>9) {
                A[j+1] += A[j]/10;
                A[j]%=10;
            }
        }
    }
    for (i=100;i>=0&&A[i]==0;i--);          //从最高位开始找，找到第一个不为0的数
    for (j=i;j>=0;j--) printf("%d", A[j]);
    return 0;
}

/*other solution2:*/

#include<iostream>
#include<cstring>
using namespace std;
int n,a[90],b[90],c[90],f[90],d=0,len_a,len_b=1,len_c=1,len_ans,m=1;
string s;
int main(){
    cin>>n;
    b[0]=1; //初始化
    for(int i=1;i<=n;i++){ //计算i的阶乘，已经算好了i-1的阶乘
        len_a=0; //i的长度
        int p=i;
        while(p>0){ //把i存进a数组
            a[len_a++]=p%10;
            p/=10;
        }
        for(int j=0;j<len_a;j++) //计算a*b（i*（i-1）的阶乘），即i的阶乘，看不懂的网上查，我也不知道为什么
            for(int k=0;k<=len_b;k++)
                c[j+k]+=a[j]*b[k];
        for(int j=0;j<len_c;j++) //需要进位的就进位
            if(c[j]>9) c[j+1]+=c[j]/10,c[j]%=10;
        if(c[len_c]) len_c++; //看最高位要不要进位
        len_ans=len_b,len_b=len_c,m=max(m,len_c); //把len_b赋值给len_ans，修改len_b的值，m为i阶乘的长度，看有没有进位
        for(int k=len_c-1;k>=0;k--) b[k]=c[k]; //把c存进b数组，即存进i的阶乘，下次循环b为i-1的阶乘
        len_c=len_a+len_ans;
        memset(c,0,sizeof(c)); //清零c数组，准备计算下个阶乘
        for(int j=0;j<m;j++){ //高精加，直接套模板
            f[j]+=b[j];
            if(f[j]>9) f[j+1]+=f[j]/10,f[j]%=10; //进位，注意不要写成f[j+1]++，f[j]-=10;就因为这里wa了一个点
        }
    }
    while(!f[m]&&m>0) m--; //去掉首导零
    for(int i=m;i>=0;i--) cout<<f[i]; //倒序输出
    return 0; //圆满结束
}


//#include<iostream>
//#include<string>
//#include<cstring>
//#include<cmath>
//#define MAX 4233
//using namespace std;
//
//class mp {
//public:
//    int l, x[MAX];
//    mp() : l(1), x{0} {}
//
//    mp& operator=(const char* num) {
//        l = strlen(num);
//        for (int i = 0; i < l; ++i)
//            x[i] = num[l - i - 1] - '0';
//        x[l] = 0; // ȷ����������ಿ��Ϊ0
//        return *this;
//    }
//
//    mp& operator=(const int num) {
//        char a[MAX];
//        sprintf(a, "%d", num);
//        *this = a;
//        return *this;
//    }
//
//    mp(const int num) {
//        *this = num;
//    }
//
//    mp(const char* num) {
//        *this = num;
//    }
//
//    mp operator+(const mp& a) {
//        mp c;
//        c.l = max(l, a.l);
//        for (int i = 0, t = 0; i < c.l; ++i) {
//            c.x[i] = x[i] + a.x[i] + t;
//            t = c.x[i] / 10;
//            c.x[i] %= 10;
//        }
//        if (c.x[c.l - 1] == 0) --c.l;
//        return c;
//    }
//
//    mp operator*(const mp& obj) {
//        mp c;
//        c.l = l + obj.l;
//        for (int i = 0; i < l; ++i)
//            for (int j = 0; j < obj.l; ++j) {
//                c.x[i + j] += x[i] * obj.x[j];
//                c.x[i + j + 1] += c.x[i + j] / 10;
//                c.x[i + j] %= 10;
//            }
//        if (c.x[c.l - 1] == 0) --c.l;
//        return c;
//    }
//};
//
//ostream& operator<<(ostream& out, const mp& obj) {
//    for (int i = obj.l - 1; i >= 0; --i) {
//        out << obj.x[i];
//    }
//    return out;
//}
//
//istream& operator>>(istream& in, mp& obj) {
//    char num[MAX];
//    in >> num;
//    obj = num;
//    return in;
//}
//
//int main() {
//    int n;
//    mp ans = 0, num = 1;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        num = num * i;
//        ans = ans + num;
//    }
//    cout << ans << endl;
//    return 0;
//}






