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


```cpp
#include<iostream>
#include<cmath>

using namespace std;

/*
第一行两个整数 n,m，表示方阵大小和魔法施放次数。接下来 m 行，每行 4个整数 x,y,r,z，表示在这次魔法中，Scarlet 会把以第 x行第 y列为中心的 2r+1 阶矩阵按照某种时针方向旋转，其中 
z=0 表示顺时针，z=1 表示逆时针。
*/
int a[501][501],b[501][501];
//-->我们多一格是为了方便统计


int main(){
	int n,m,t=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=t++;
		}
	}
	for(int i=1;i<=m;i++){
		int x,y,r,opt;
		cin>>x>>y>>r>>opt;
		if(opt==0){
			for(int j=x-r;j<=x+r;j++){
				for(int k=y-r;k<=y+r;k++){
					b[x-y+k][x+y-j]=a[j][k];
				}
			}
			for(int j=x-r;j<=x+r;j++){
				for(int k=y-r;k<=y+r;k++){
					a[j][k]=b[j][k];
				}
			}
		}
		else{
			for(int j=x-r;j<=x+r;j++){
				for(int k=y-r;k<=y+r;k++){
					b[x+y-k][y-x+j]=a[j][k];
				}
			}
			for(int j=x-r;j<=x+r;j++){
				for(int k=y-r;k<=y+r;k++){
					a[j][k]=b[j][k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
```
>Summary，Oct22
>模拟旋转的一题，还是挺简单的，但是我在初始化的时候写错了i和j，也就变成了`a[j][i]`，于是找了好久debug…【】，想着逻辑也妹错啊，然后又狠狠鞭尸了一下自己，如代码块所见，`for(int j=x-r;j<=x+r;++j)`，一开始我用的就是前缀自增符号，导致也使得代码块出现错误，这点也应该跟我想贪一点速率有关，所以还是那个问题吧，不要总想着自己有什么就要把什么都展现出来。

>实际上更像我们排队点麻辣烫，麻辣香锅，有的人是酱香口味，有人是微辣口味，有人是麻辣口味…~~（更多的我说不出来）~~，**虽然说你的酱香口味拿的牌子是<u>72</u>**，但是不妨碍**微辣口味的同学在你前面点了**，其**牌子虽然是<u>108</u>**（~~我在玩72地煞36天罡的梗，希望有人理解看水浒传人士的精神状态~~），但是他就是比你先点，理应也先做好，可以理解为，元素"A"**走了**，实际上是==该同学(元素)拿到餐了，甚至说退出了==。


>Summary,Oct23
>今天主要学了Js，并且把静态链表的笔记整理了一下，上面是一些摘录，我对后面关于`栈`的如何写有了一定的眉目，明天满课看看能不能动笔写完关于栈的文章。



这是排序算法的题目：
```cpp
#include<bits/stdc++.h>
#define MAXN 100000

#define int long long
int n,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
void QuickSort(int array[], int low, int high) {
    int i = low; 
    int j = high;
    if(i >= j) {
        return;
    }
 
    int temp = array[low];
    while(i != j) {
        while(array[j] >= temp && i < j) {
            j--;
        }
	while(array[i] <= temp && i < j) {
            i++;
        }
	if(i < j) {
            swap(array[i], array[j]);
        }
    }
 
    //将基准temp放于自己的位置，（第i个位置）
    swap(array[low], array[i]);
    QuickSort(array, low, i - 1);
    QuickSort(array, i + 1, high);

signed main(){//因为有int long long所以用signed
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    QuickSort(0,n);
    for(int i=0;i<n;i++){
        std::cout<<a[i]<<" ";
    }
    return 0;
}
```
用`std`来解决这个问题:
```cpp
#include<bits/stdc++.h>
#define MAXN 100000
#define int long long

signed main(){//因为有int long long所以用signed
    signed n,a[MAXN];
    std::cin>>n;
    for(signed i=0;i<n;i++){
        std::cin>>a[i];
    }
    std::sort(a,a+n);
    for(signed i=0;i<n;i++){
        std::cout<<a[i]<<" ";
    }
    return 0;
}
```

> 注意到有`#define int long long`，我们可以采用`signed`来代替`int`，其次是即便是`sort(a,a+n)`也要有`std::`前缀，经常忘记的还有`std::string`，这是由于string，sort都存放在std命名空间中（想起来还得去写一篇关于命名空间的Blog）
> Today's Summary:
> 说句实话，这两天比较忙只能做到两天一道题~~毕竟从早九上到晚十~~，所以我觉得，周四可以少点任务量，昨天赶完JS的笔记，加上也复习了不少数据库，总体上任务量还是蛮大的。所以我觉得适量削减一些任务，是有存在的必要，今天oj只写一道题的原因是：**_友心疾，陪之_**。
> 明天见。
