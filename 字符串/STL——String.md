# STL——String

## 字符串

> scanf遇上空格结束，用gets();
> while(gets(str));
> char *str="abcdef";-->是常量
> char str[]="abcdef";-->是初始化

### 字符

字符类型是基本数据类型，用char表示，字符的大小由其ASCII码的大小决定。

### 字符数组

存放自负的数组称之为字符数组。用字符串常量赋值时，系统会在字符串末尾自动添加结束标识符\0，而对单个字符赋值时，则不会自动添加结束标识符\0，有可能除了赋值元素外，其他元素也由预期外的初始值。

### 字符串处理函数

| 函数                                                      | 描述                                                         |
| :-------------------------------------------------------- | :----------------------------------------------------------- |
| void *memchr(const void *str, int c, size_t n)            | 在参数 *str* 所指向的字符串的前 n 个字节中搜索第一次出现字符 c（一个无符号字符）的位置。 |
| int memcmp(const void *str1, const void *str2, size_t n)  | 把 *str1* 和 *str2* 的前 n 个字节进行比较。                  |
| void *memcpy(void *dest, const void *src, size_t n)       | 从 src 复制 n 个字符到 *dest*。                              |
| void *memmove(void *dest, const void *src, size_t n)      | 另一个用于从 *src* 复制 n 个字符到 *dest* 的函数。           |
| void *memset(void *str, int c, size_t n)                  | 将指定的值 c 复制到 str 所指向的内存区域的前 n 个字节中。    |
| char *strcat(char *dest, const char *src)                 | 把 *src* 所指向的字符串追加到 *dest* 所指向的字符串的结尾。  |
| char *strncat(char *dest, const char *src, size_t n)      | 把 *src* 所指向的字符串追加到 *dest* 所指向的字符串的结尾，直到 n 字符长度为止。 |
| char *strchr(const char *str, int c)                      | 在参数 *str* 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置。 |
| int strcmp(const char *str1, const char *str2)            | 把 *str1* 所指向的字符串和 *str2* 所指向的字符串进行比较。   |
| int strncmp(const char *str1, const char *str2, size_t n) | 把 *str1* 和 *str2* 进行比较，最多比较前 n 个字节。          |
| int strcoll(const char *str1, const char *str2)           | 把 *str1* 和 *str2* 进行比较，结果取决于 LC_COLLATE 的位置设置。 |
| char *strcpy(char *dest, const char *src)                 | 把 *src* 所指向的字符串复制到 *dest*。                       |
| char *strncpy(char *dest, const char *src, size_t n)      | 把 *src* 所指向的字符串复制到 *dest*，最多复制 n 个字符。    |
| size_t strcspn(const char *str1, const char *str2)        | 检索字符串 str1 开头连续有几个字符都不含字符串 str2 中的字符。 |
| char *strerror(int errnum)                                | 从内部数组中搜索错误号 errnum，并返回一个指向错误消息字符串的指针。 |
| size_t strlen(const char *str)                            | 计算字符串 str 的长度，直到空结束字符，但不包括空结束字符。  |
| char *strpbrk(const char *str1, const char *str2)         | 检索字符串 *str1* 中第一个匹配字符串 *str2* 中字符的字符，不包含空结束字符。也就是说，依次检验字符串 str1 中的字符，当被检验字符在字符串 str2 中也包含时，则停止检验，并返回该字符位置。 |
| char *strrchr(const char *str, int c)                     | 在参数 *str* 所指向的字符串中搜索最后一次出现字符 c（一个无符号字符）的位置。 |
| size_t strspn(const char *str1, const char *str2)         | 检索字符串 *str1* 中第一个不在字符串 *str2* 中出现的字符下标。 |
| char *strstr(const char *haystack, const char *needle)    | 在字符串 *haystack* 中查找第一次出现字符串 *needle*（不包含空结束字符）的位置。 |
| char *strtok(char *str, const char *delim)                | 分解字符串 *str* 为一组字符串，*delim* 为分隔符。            |
| size_t strxfrm(char *dest, const char *src, size_t n)     | 根据程序当前的区域选项中的 LC_COLLATE 来转换字符串 **src** 的前 **n** 个字符，并把它们放置在字符串 **dest** 中。 |

### string类

1. #### 构造函数

   ```cpp
   string s1();
   string s2("hello lw");
   string s3(4,'o');
   string s4("012345",2,3)//用012345字符串中的第二个元素(也就是下标的数字)开始的三个元素给s4赋初值，s4="234"
   ```

2. #### 赋值
   
   可以使用`char*`类型给string对象赋值，string类重载了运算符=，可以直接用等号=进行赋值，或者用成员函数assign()对string对象赋值，assign成员函数返回对象自身的引用。
   
   ```cpp
   string str,s1;
   str="hello";
   s='0';
   string s2,s3,s4,s5,s6;
   s2.assign("hello lw");
   s3.assign(str);				//s3=str
   s4.assign(str,2,4);			//s4=str[2~2+4]-->"llol"
   s5.assign(4,'o');			//s5="oooo"
   s6.assign("012345",2,4);	//012345的子串给s6赋值,从第二个元素开始，连续4个元素,s6="2345"
   ```
   
3. #### string类的输入/输出
   
       string类的重载运算符>>以及<<分别用于输入和输出，执行输入读取操作的时候，string对象会忽略开头的空格、换行符、制表符等空白，从第一个真正的字符开始读入，以空白字符为结束标志，一次只能读单个词。
       getline函数可以读取一行，只以换行符为一行输入的结束标志，且不会忽略开头的空白符号。
   
   ```cpp
   getline(cin,string对象);
   ```
   
   ```cpp
   #include<iostream>
   #include<string>	//包含该头文件后可以使用string str、str.compare()以及比较运算符
   int main(){
       string s1,s2;
       
       std::getline(cin,s1);
       std::cout<<s1<<std::endl;
       
       std::cin>>s2;
       std::cout<<s2<<std::endl;
       
       return 0;
   }
   ```
   
4. #### string对象常用特性

   |        成员函数名         |                             说明                             |
   | :-----------------------: | :----------------------------------------------------------: |
   |      int capacity()       | 返回string对象当前容量，在不增加内存的情况下可以存放的元素个数 |
   |      int max_size()       |           返回string对象中可以存放的最大字符串长度           |
   |        int size()         |         返回当前字符串的大小，使用方法和length()相同         |
   |       int length()        |          返回当前字符串的长度，使用方法和size()相同          |
   |        bool empty         |       判断当前字符串是否为空，是返回true，反之为false        |
   | void resize(int len,char) |      把字符串当前大小重置为len，并用字符c填充不足的部分      |

5. #### string的比较
   
   string类提供了compare()函数,用于比较两个字符串的大小，函数返回值为负值则表示当前字符小，返回值为0则表示两个字符串相等，返回值为正值则表示当前字符串大。同时重载比较运算符==、！=、<、<=、>、>=用于两个字符串的比较，举例说明如下：
   
     ```cpp
     #include<cstdio>
     #include<string>
     int main(){
       string s1="abcdefg",s2="abcdef";
       if(s1==s2)std::cout<<"相等";
       else if(s1>s2)std::cout<<"s1>s2"<<std::endl;
       else if(s1<s2)std::cout<<"s1<s2"<<std::endl;
       
       int cmp=s1.compare(s2);
       if(cmp==0)std::cout<<"相等";
       else if(cmp>0)std::cout<<"s1>s2"<<std::endl;
       else if(cmp<0)std::cout<<"s1<s2"<<std::endl;
       
       cmp=s1.compare(1,2,s2,0,3);//比较s1从1开始的2个字符组成的字符串与s2从0开始的字符组成的字符串的大小
       cmp=s1.compare(0,6,s2);//比较s1从0开始的6个字符组成的字符串与s2的大小
       cmp=s1.compare("abcdefg");//比较s1与字符串abcdefg的大小
       
       return 0;
     }
     ```
   
6. #### string的链接
   
   string类提供了append函数，用于在当前字符串后面链接字符串，返回值为连接后对象自身的引用。同时重载了运算符+、+=用于两个字符串的链接
   
   ```cpp
   #include<iostream>
   #include<string>
   int main(){
       string s1="hello";
       s1+=" lw!";
       std::cout<<s1<<std::endl;
       
       string s2="ABCD";
       s1.append(s2);				//在s1的末尾链接s2字符串
       std::cout<<s1<<std::endl;	//输出hello lw！ ABCD
       
       s1.append(s2,0,3);			//在s1的末尾链接s2中从0开始的连续3个字符的字符串
       std::cout<<s1<<std::endl;	//输出hello lw! ABCDABC
       
       s1.append(3,'K');			//在s1的末尾链接3个字符，内容均为K
       std::cout<<s1<<std::endl;	//输出hello lw! ABCDABCKKK
       
       return 0;
   }
   ```
   
7. #### 交换string对象的内容

   ```cpp
   string s1="abc",s2="0123456";
   s1.swap(s2);
   std::cout<<s1<<""<<s2<<std::endl;
   ```

8. #### string对象的子串

   ```cpp
   string substr(int pos,int n);
   ```

   `substr`成员函数用于求string对象的子串，函数返回字符串从pos开始的连续n个字符组成的字符串

   ```cpp
   #include<iostream>
   #include<string>
   int main(){
       string s1="0123456";
       string s2=s1.substr(1,3);//123
       std::cout<<s2<<std::endl;
       
       s2=s1.strsub(3);	//3456(从第三个元素开始直到s1字符结束的子串)
   	std::cout<<s2<<std::endl;
       
       return 0;
   }
   ```

   

9. #### string类的查找函数

   string 类可以查找字符串中的子串和字符，返回值是子串或字符在字符串中的位置，如果不存在，则返回`-1`，成员函数如下。
   • find：从前往后查找子串或字符的位置。
   • rfind：从后往前查找子串或者字符的位置
   • find_first_of：从前往后查找另一个字符串中任意字符在当前字符串中出现的负置
   •find_last_of：从后往前查找另一个字符串中任意字符在当前字符串中出现的位置
   •find_first_not_of：从前往后查找另一个字符串中没有包含的字符在当前字符串中的位置
   •find_last_not_of：从后往前查找另一个字符串中没有包含的字符在当前字符串中的位置

   ```CPP
   #include<iostream>
   #include<string>
   
   int main(){
       string s1 = "Hello";
       
       int pos  s1. find("l”); //从前往后查找l出现的位置为2
                         
       if(pos!=-1)
       	std::cout << pos <<" "<< sl.subst.r(poa)<<std::endl;
       //输出从字符串pos位置开始的子串
       //输出结果：2 llo
       pos = s1.find("l"); //从后往营查找l出现的位置为3
                         
       if(pos!= - 1)
       	std::cout << pos << " "<< sl.subatr(pos)<<std::endl;//输出结果；3 1o
   
   	pos=s1.find("ell"，2); //从第2个元索开始寻找ell子串
       std::cout << pos << std::endl; //不存在该子串，输出-1
   
       pos =s1.find_first_of("world"); //从前往后查找第一次出"w","o","r","l"或者"d"的位置
       if(pos!=-1)
       	std::cout << pos << " " << sl.substr(pos) <<std::endl;//输出结果：2 llo
       
   	pos = s1.find_last_of("world"); //从后往前查找第一次出"w","o","r","l"或者"d"的位置
   
   	if(pos(=-1)
       std::cout << pos << " " << s1.substr(pos) <<std::endl; //输出结果：4 o
          
       pos = s1.find_first_not_of("world"); //从前往后查找第一次出现的不是“w”“o"“r”“1”或者“d”字符的位置
          
       if(pos= -1)
       std::cout << pos << " " << sl.substr(pos) << std::endl;//输出结果：0 Hello
       
   	pos = al.find_last_ not_of("worid"); //从后往的查找第一次出现的不是“w“o"“r"“1”或者“d”字符的位置
       if(poat= -1)
       	std::cout << pos <<" "<<s1.substr(pos)<<std::endl; //输出结果：1 ello
       return 0；
   }
   ```

10. #### string类替换、插入、删除成员函数
    
    `replace`成员函数用于对`string`对象子串进行替换，返回值为替换子串后对象的引用。insert成员函数用于在string对象中插入另一个字符串，返回值为插人后的对象自身的引用。erase成员函数用于删除string对象中的子串，返回值为删除子重后对象自身的引用。举例说明如下，
    
    ```cpp
    #include<iostream>
    #include<string>
    
    int main(){
        string s1="Hello!";
       	s1.insert(5," lw");			//在s1第5位置插入字符串lw
        std::cout<<s1<<std::endl;
        
        strnig s2="ABC ";
        s1.insert(0,s2);			//在s1第0位置插入字符串s2
        std::cout<<s1<<std::endl;	//输出ABC Hello lw
        
        s1.earse(4,6);				//删除s1串第4位置后连续1个字符
        std::cout<<s1<<std::endl;	//输出ABC lw
        
        s1.erase(3);				//删除s1串第3位置后所有字符
        std::cout<<s1<<std::endl;
        
        s1.replace(0,3,"Hello lw",0,8);//将s1中从0开始的1个字符替换为"Hello lw"中从0开始的8个字符
        
        std::cout<<s1<<std::endl;
        
        s1.replace(5,2,3,'A');		//将s1中从5开始的2个字符替换为A
        std::cout<<s1<<std::endl;
        
        return 0;
    }
    ```
    
    

##### 【错位纠正】

```cpp
#include<stdio.h>
char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
     int i, c;
     while((c = getchar()) != EOF) {
        for (i=1; s[i] && s[i]!=c; i++); //找错位之后的字符在常量表中的位置
        if (s[i]) putchar(s[i-1]); //如果找到，则输出它的前一个字符
 	else putchar(c);
     }
     return 0;
}
```

【忽略大小写字符串比较】

> 【题目描述】
>
> 	用strcmp函数可以比较两个字符串的大小,比较方法为：对两个字符串从前往后逐个字符串相比较,直到出现不同的字符或遇到'\0'为止。如果全部字符都相同，则认为相同；如果某个字符串先遇到\0，而另一个字符串还未遇到\0，则前者小于后者。

```cpp
#include<bits/stdc++.h>

const int N=105;
char s1[N],s2[N];
int main(){
    gets(s1);gets(s2);
    strlwr(s1),strlwr(s2);
    int cmp=strcmp(s1,s2);
    if(cmp<0)std::cout<<"<"<<std::endl;
    if(cmp==0)std::cout<<"="<<std::endl;
    if(cmp>0)std::cout<<">"<<std::endl;
    
    return 0;
}
```

##### 【NOIP 2008 ISBN号码】

```cpp
#include<stdio.h>
int main(){
	char str[14],mod[12]="0123456789X";
	gets(str);
	int i,j=1,t=0;
	for(i=0;i<12;i++){
		if(str[i]=='-')continue;
		t+=(str[i]-'0')*j++;
	}
	if(mod[t%11]==str[12])printf("Right");
	else {
		str[12]=mod[t%11];
		puts(str);
	}
	return 0;
}
```

```cpp
#include<iostream>
#include<cstring>

char s[20];
int main(){
    std::cin>>s;
    int n=strlen(s);
    int sum=0,mul=1;
    for(int i=0;i<n-1;i++){
        if(s[i]>='0'&&s[i]<='9')sum+=(s[i]-'0')*(mul++);
        sum%=11;
    }
    if(sum==10){//最后一个数字-->判定
        if(s[n-1]=='X'){
		std::cout<<"Right"<<std::endl;return 0;
		}
        else{
            s[n-1]='X';
            std::cout<<s<<std::endl;
            return 0;
        }
    }
    if(s[n-1]-'0'==sum)std::cout<<"Right"<<std::endl;
    else{
        s[n-1]='0'+sum;
        std::cout<<s<<std::endl;
    }
    return 0;
}
```