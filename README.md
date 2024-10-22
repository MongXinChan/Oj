# Oj

## 24
### Oct
```cpp
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 501
int la,lb,m;//m是最大值的意思 
short x[MAX]={},y[MAX]={};
string a,b;

int Traversing(short* p,short *q,string a,string b){
	for(int i=1;i<=a.length();++i){
		p[i]=a[a.length()-i]-'0';
	}
	for(int i=1;i<=b.length();++i){
		q[i]=b[b.length()-i]-'0';
	}
}

int main(){
	cin>>a>>b;
	la=a.length();
	lb=b.length();
	m=max(la,lb);
	if(la>lb){
		Traversing(x,y,a,b);
	}
	else{
		Traversing(y,x,b,a);
	}
	for(int i=1;i<m;++i){
		if(x[i]>=10){
			x[i]-=10;
			++x[i+1];
		}
	}
	if(x[m+1]>0){
		++m;
	}
	for(int i=m;i>1;--i){
		cout<<x[i];
	}
	return 0;
}
```


```cpp
#include<iostream>
#include<algorithm>
#include<string>
using namespace std; 
string a,b;
int n,p[5000],q[5000],t[5000],m;

int main(){
	cin>>a>>b;
	int la=a.length(),lb=b.length();
	//store
	for(int i=1;i<=la;++i){
		p[i]=a[la-i]-'0';
	}
	for(int i=1;i<=lb;++i){
		q[i]=b[lb-i]-'0';
	}
	//multiple
	for(int i=1;i<=la;++i){
		for(int j=1;j<=lb;++j){
			t[i+j-1]+=p[i]*q[j];//remember to'+=' isnt '='
		}
	}
	m=la+lb;
	//plus
	for(int i=1;i<m;++i){
		if(t[i]>9){
			t[i+1]+=t[i]/10;
			t[i]%=10;
		}
	}
	while(t[m]==0&&m>1){
		m--;
	}
	for(int i=m;i>=1;--i){
		cout<<t[i];
	}
	return 0;
}
```

> today's summary，Oct20：
> I consider that I never finish a question during lnog-time,including oj,some databates
> I need to pay some time to fill my mind about some computer question.
> 好了我的毕生英语也就这样了，发现最近自己挺忙的，也挺懒的，刷了一边数据结构和一些简单算法就浅尝辄止，想看的代码书也没看多少，不过值得高兴的是把《C++编程思想二卷》啃了第一卷，暂时来讲第二卷还不需要用太多，慢慢看，加上看《代码大全2》来简化我的编程习惯，说句实话，我有点==lazy==，这点直言不讳，也算是把Cpp的应用提上日程，现在准备每天1~3道oj（如果不忙手里的项目的话，尽可能保持2道），并且带着一些问题去找答案。预计在11月前完成对图论的复习以及构建一些==QT==小项目的需求。
> 即目前->每天Oj+一些学习，在11月份做好QT的小项目，大概是在中旬。期间找几天去看看华南植物园 ~ ，那里目前的秋意特别浓厚，喜欢秋
> 勉强来说这应该记录一下今天刷题的心得————太久没写cpp有点手生，可能由于我现在学的代码及算法比较低端，我倒没有见到用到"构造函数"，"子类继承"之类的东西，反倒是迭代器用得多？
> 大数规律——说句实话脑子居然一抽写成了类似于BubbleSort的写法来遍历`p[i]*q[j]`,这点我感觉很混乱，脑子太少用在数理上了，我觉得在半个月是可以恢复到原本的水准。
> 以及一件很蠢的事情，在写第二个代码的时候，我居然想要做continue这件事，这跳过了某些位数，但是这些位数又确确实实存在会影响到数值，假设我们有两个数字 a = "105" 和 b = "201"。如果我们跳过 p[2]（即数字 0）的乘法操作，我们将错过 p[1]*q[2]（即 5*1=5）的进位，这将导致最终结果的错误。
> 再讲一个逻辑错误，里面涉及了`+=`，我这里也做得不太好，因为我一开始是用`t[i]=p[i]*q[j]`来写，本质上来说就是太久没写加减乘除了~~对不起我有罪~~，就这样吧


```cpp
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
```


>today's summary,Oct21:
>关于`重载`和`输入输出流`的重载认识更深了一些，不过这个代码还是==WA * 4==了，就很悲剧，所以我在想这些东西出了什么错？
>关于重载：一开始想的是`operator<<`,`operator>>`要写在类里，然后就错付了，实际上istream和ostream本身就是一个类，所以在类外重载就是要`&类名`，对类的理解加深了，原本在想obj1.l+obj2.l这样子加起来等于l，但是发现本身就可以存在一个类，那自然把另一个类引进就行了（Thinking in C++受害者，这书太厚太催眠了）
>关于明天的安排：由于明天的空余时间比较多，我准备花点时间在重新回眸这一题，分析这一题为什么会 WA * 4 ,加油吧，明天还要继续啃Js
>哦对了，cstring和string头文件不是同一个东西——这个知识点每次瞥一眼后写代码总是会忘记。
>以及用重载来写高精度的人真他妈是天才。

>debug 日志
>原本以为是`operator+`或者是`operator*`的锅，最后没想到是构造函数引起的锅…
>```cpp
>    mp():l(1),x{0}{}
>	mp(){
>		l=1;
>		x[0]=0;
>	}
>```


