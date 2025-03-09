# STL

## STL简介

STL是C++标准库的一部分，它提供了一系列容器、算法和迭代器，使得程序员可以更加方便地进行软件开发。STL中的容器包括vector、list、deque、set、map等，算法包括排序、查找、替换等，迭代器则用于遍历容器中的元素。

[TOC]

## String

更加详细的可以访问[STL——String](/字符串/STL——String.md)

1. `length()`

   返回字符串的长度

2. `size()`

   返回字符串的长度

> ​    string类的重载运算符>>以及<<分别用于**输入和输出**，执行输入读取操作的时候，string对象会忽略开头的空格、换行符、制表符等空白，从第一个真正的字符开始读入，以空白字符为结束标志，一次只能读单个词。
>
> ​    **getline函数可以读取一行**，**只以换行符为一行输入的结束标志**，且不会忽略开头的空白符号。

3. `push_back()`

   在字符串的尾部添加一个字符

4. `append()`

   在字符串的尾部添加一个字符串

5. `find(first,pos)`

   从前往后查找子串或字符的位置。

   ```cpp
   string s1 = "Hello";
   
   int pos  s1. find("l”); //从前往后查找l出现的位置为2
   ```

6. `substr(int pos,int n);`

   `substr`成员函数用于求string对象的子串，函数返回字符串从pos开始的连续n个字符组成的字符串

> `insert`成员函数用于在string对象中插入另一个字符串，返回值为插人后的对象自身的引用。

7. `insert(index,count,ch)`

   在`index`后插入`count`次`ch`

   ```cpp
   std::string s = "Hello";
   // bug修复：将字符串字面量 "a" 替换为字符 'a'
   s.insert(2, 3, 'a');  // 在索引2的位置插入3个字符 'a'
   std::cout << s << std::endl;  // 输出：Heaaallo
   ```

8. `insert(index,str)`

   在 `index` 位置插入字符串 `str`。

   ```cpp
   std::string s = "Hello";
   std::string toInsert = "World";
   // 在索引 5 的位置插入字符串 "World"
   s.insert(5, toInsert);
   std::cout << s << std::endl;  // 输出：HelloWorld

9. `erase()`

    `erase`成员函数用于删除string对象中的子串，返回值为删除子重后对象自身的引用。

    ```cpp
    string s1="Hello!";
    s1.insert(5," lw");			//在s1第5位置插入字符串lw
    
    s1.earse(4,6);				//删除s1串第4位置后连续1个字符
    std::cout<<s1<<std::endl;	//输出ABC lw
    
    s1.erase(3);				//删除s1串第3位置后所有字符
    std::cout<<s1<<std::endl;
    ```

10. `replace(pos,count,str)`

    该函数用于从字符串的 `pos` 位置开始，替换掉连续的 `count` 个字符，用字符串 `str` 来替换。

    ```cpp
    std::string s = "HelloWorld";
    // 从索引 5 开始，替换掉 5 个字符，用 "C++" 替换
    s.replace(5, 5, "C++");
    std::cout << s << std::endl;  // 输出：HelloC++
    ```

11. `replace(first,last,str)`

    该函数用于替换字符串中从迭代器 `first` 到 `last` 所指向的字符范围，用字符串 `str` 来替换。

    ```cpp
    std::string s = "HelloWorld";
    // 替换从第 5 个字符到第 10 个字符的范围，用 "C++" 替换
    s.replace(s.begin() + 5, s.begin() + 10, "C++");
    std::cout << s << std::endl;  // 输出：HelloC++
    ```

12. `empty()`

    测试字符串是否为空，为空返回1，否则返回0。 

13. `to_string()`

    转换整数或浮点数为 `string`

14. `stoi` , `stol` ,`stoll`

    转换字符串为有符号整数

15. `stoul`  ,`stoull`

    转换字符串为无符号整数

### String的使用



## Stack库

Stack（栈）是一种后进先出（LIFO）的数据结构，它只允许在栈顶进行插入和删除操作。STL中的Stack容器适配器提供了一种简单的方式来实现栈的功能。

1. `empty()`
   测试栈是否为空，为空返回true，否则返回false。 

2. `size() `
   返回栈的大小。 

3. `top()`
   获取栈顶元素。 

4. `pop() `
   移除栈顶元素。 

5. `push() `
   将指定的元素压入栈顶。 

   ```cpp
   void push(const value_type& value); 
   ```

### Stack的使用方法

```cpp
#include <stack>
using namespace std;

int main() {
    stack<int> s; // 创建一个空栈
    s.push(1); // 向栈中插入元素
    s.push(2);
    s.push(3);
    cout << s.top() << endl; // 输出栈顶元素
    s.pop(); // 删除栈顶元素
    cout << s.top() << endl;
    return 0;
}
```

## Vector

`std::vector` 是C++标准库中的一个动态数组容器，它能够自动管理内存，提供了高效的随机访问能力。以下是 `std::vector` 的一些常见操作及其用例：

1. 定义和初始化

    ```cpp
    #include <iostream>
    #include <vector>
    
    int main() {
        // 定义一个空的vector
        std::vector<int> vec1;
    
        // 定义一个包含5个元素，每个元素初始值为0的vector
        std::vector<int> vec2(5);
    
        // 定义一个包含3个元素，每个元素初始值为10的vector
        std::vector<int> vec3(3, 10);
    
        // 使用初始化列表初始化vector
        std::vector<int> vec4 = {1, 2, 3, 4, 5};
    
        return 0;
    }
    ```
2. 访问元素
    ```cpp
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 使用下标访问元素
    std::cout << "第一个元素: " << vec[0] << std::endl;
    
    // 使用at()方法访问元素，会进行边界检查
    std::cout << "第三个元素: " << vec.at(2) << std::endl;
    
    // 使用front()和back()方法访问第一个和最后一个元素
    std::cout << "第一个元素: " << vec.front() << std::endl;
    std::cout << "最后一个元素: " << vec.back() << std::endl;
    ```

3. 修改元素
    ```cpp
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 修改指定位置的元素
    vec[2] = 10;
    
    // 在末尾添加元素
    vec.push_back(6);
    
    // 在指定位置插入元素
    vec.insert(vec.begin() + 1, 20);
    
    // 删除指定位置的元素
    vec.erase(vec.begin() + 3);
    
    ```

4. 遍历元素
    ```cpp
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 使用for循环遍历
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    // 使用范围for循环遍历
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // 使用迭代器遍历
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    ```

5. 其他操作
    ```cpp
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 检查vector是否为空
    bool isEmpty = vec.empty();
    
    // 获取vector的大小
    size_t size = vec.size();
    
    // 清空vector
    vec.clear()
    ```
6. `push_back`

    `push_back` 用于在 `vector` 的尾部添加一个元素。

    ```cpp
        std::vector<int> vec = {1, 2, 3};
        // 在尾部添加元素 4
        vec.push_back(4);
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2 3 4
    ```

7. `pop_back`

   `pop_back` 用于移除 `vector` 的最后一个元素。

    ```cpp
        std::vector<int> vec = {1, 2, 3};
        // 移除最后一个元素
        vec.pop_back();
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2
    ```

8. `resize`

    `resize` 用于改变 `vector` 的大小。如果新的大小比原来大，新元素会用默认值填充；如果新的大小比原来小，`vector` 会截断。

    ```cpp
        std::vector<int> vec = {1, 2, 3};
        // 增大vector大小，新元素默认初始化为 0
        vec.resize(5);
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2 3 0 0

        // 缩小vector大小
        vec.resize(2);
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2
    ```

9. `reserve`

`reserve` 用于为 `vector` 预留一定的空间，避免多次重新分配内存。

    ```cpp
        std::vector<int> vec;
        // 预留空间
        vec.reserve(10);
        for (int i = 0; i < 10; ++i) {
            vec.push_back(i);
        }
        std::cout << "Vector的容量: " << vec.capacity() << std::endl; // 输出: 10
    ```

10. `shrink_to_fit`

    `shrink_to_fit` 用于将 `vector` 的容量调整为和它的大小一致，释放多余的内存。

    ```cpp
        std::vector<int> vec;
        vec.reserve(100);
        for (int i = 0; i < 5; ++i) {
            vec.push_back(i);
        }
        std::cout << "调整前的容量: " << vec.capacity() << std::endl; // 输出: 100
        vec.shrink_to_fit();
        std::cout << "调整后的容量: " << vec.capacity() << std::endl; // 输出: 5
    ```

11. `swap`

    `swap` 用于交换两个 `vector` 的内容。

    ```cpp
        std::vector<int> vec1 = {1, 2, 3};
        std::vector<int> vec2 = {4, 5, 6};
        // 交换两个vector的内容
        vec1.swap(vec2);
        for (int num : vec1) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 4 5 6
        for (int num : vec2) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2 3
    ```

## 常见算法函数

1. `find(a.begin(),a.end,value)`
    `std::find` 用于在指定范围内查找某个元素，如果找到则返回该元素的迭代器，否则返回范围的末尾迭代器。
2. `reverse(a.begin(),a.end())`
3. `sort(a.begin(),a.end(),cmp)`
    `std::sort` 用于对指定范围内的元素进行排序，默认是升序排序。
4. `unique(first,last)`
    `std::unique` 用于移除**指定范围内的相邻重复元素，返回一个指向去重后范围末尾的迭代器**。注意，它并没有真正删除重复元素，只是将不重复的元素移到前面，需要结合 `erase` 函数来删除多余的元素
    
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    
    int main() {
        std::vector<int> a = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
        auto last = std::unique(a.begin(), a.end());
        a.erase(last, a.end());
        for (int num : a) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return 0;
    }
    ```
5. `nth_element(a.begin(),a.begin()+mid,a.end,cmp)`
    `std::nth_element` 用于将第 n 小的元素放到它应该在的位置，同时保证该位置左边的元素都小于等于它，右边的元素都大于等于它。
    ```cpp
    std::vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int mid = a.size() / 2;
    std::nth_element(a.begin(), a.begin() + mid, a.end(), cmp);
    std::cout << "第 " << mid + 1 << " 小的元素是: " << a[mid] << std::endl;
    ```
6. `binary_search(a.begin(),a.end(),value)`
    `std::binary_search` 用于在已排序的范围内查找某个元素是否存在，返回一个布尔值。
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    
    int main() {
        std::vector<int> a = {1, 2, 3, 4, 5};
        bool found = std::binary_search(a.begin(), a.end(), 3);
        if (found) {
            std::cout << "Found" << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
        return 0;
    }
    ```
7. `lower_bound(a.begin(),a.end(),x)`
    `std::lower_bound` 用于在已排序的范围内查找第一个不小于给定值的元素的迭代器。
8. `upper_bound(a.begin(),a.end(),x)`
    `std::upper_bound` 用于在已排序的范围内查找第一个大于给定值的元素的迭代器。
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    
    int main() {
        std::vector<int> a = {1, 2, 3, 4, 5};
        auto it = std::upper_bound(a.begin(), a.end(), 3);
        if (it != a.end()) {
            std::cout << "第一个大于 3 的元素是: " << *it << std::endl;
        } else {
            std::cout << "未找到" << std::endl;
        }
        return 0;
    }
    ```
9. `next_permutation(a.begin(),a.end())`
    `std::next_permutation` 用于生成给定范围内的下一个排列，返回一个布尔值，表示是否成功生成了下一个排列。
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm>
    
    int main() {
        std::vector<int> a = {1, 2, 3};
        do {
            for (int num : a) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        } while (std::next_permutation(a.begin(), a.end()));
        return 0;
    }
    ```
10. `prev_permutation()`
    `std::prev_permutation` 用于生成给定范围内的上一个排列，返回一个布尔值，表示是否成功生成了上一个排列。
    ```cpp
    std::vector<int> a = {3, 2, 1};
    do {
        for (int num : a) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } while (std::prev_permutation(a.begin(), a.end()));
    ```
11. `max()`,`min()`
    `std::max` 用于返回两个值中的最大值，`std::min` 用于返回两个值中的最小值
12. `swap()`
    `swap()`
13. `std::accumulate`
    `std::accumulate` 用于计算指定范围内元素的总和。
    ```cpp
    #include <numeric>
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    ```

## 链表
`STL list` 是一个双向链表容器，它提供了高效的插入和删除操作。以下是 `STL list` 的一些常见操作及其用例：

1. 定义和初始化
    ```cpp
    #include <iostream>
    #include <list>
    
    int main() {
     
        // 定义一个空的list
        std::list<int> lst1;
    
        // 定义一个包含5个元素，每个元素初始值为0的list
        std::list<int> lst2(5);
    
        // 定义一个包含3个元素，每个元素初始值为10的list
        std::list<int> lst3(3, 10);
    
        // 使用初始化列表初始化list
        std::list<int> lst4 = {1, 2, 3, 4, 5};
    
        return 0;
    }
    
    ```
    
2. 访问元素
    ```cpp
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // 使用下标访问元素（不支持）
    // std::cout << lst[0] << std::endl;
    
    // 使用at()方法访问元素，会进行边界检查
    std::cout << lst.at(2) << std::endl;
    // 使用front()和back()方法访问第一个和最后一个元素
    std::cout << lst.front() << std::endl;
    std::cout << lst.back() << std::endl;
    ```

3. 修改元素
    ```cpp
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // 修改指定位置的元素
    auto it = lst.begin();
    std::advance(it, 2); // 移动迭代器到第3个元素
    *it = 10;
    
    // 在末尾添加元素
    lst.push_back(6);
    
    // 在指定位置插入元素
    auto insertIt = lst.begin();
    std::advance(insertIt, 1); // 移动迭代器到第2个元素
    lst.insert(insertIt, 20);
    
    // 删除指定位置的元素
    auto eraseIt = lst.begin();
    std::advance(eraseIt, 3); // 移动迭代器到第4个元素
    lst.erase(eraseIt);
    ```

4. 遍历元素
    ```cpp
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // 使用for循环遍历
    for (int num : lst) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // 使用范围for循环遍历
    for (int num : lst) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // 使用迭代器遍历
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    ```

5. 其他操作
    ```cpp
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // 检查list是否为空
    bool isEmpty = lst.empty();
    
    // 获取list的大小
    size_t size = lst.size();
    
    // 清空list
    lst.clear();
    ```

6. `push_back`

    `push_back` 用于在 `list` 的尾部添加一个元素。

    ```cpp
        std::list<int> lst = {1, 2, 3};
        // 在尾部添加元素 4
        lst.push_back(4);
        for (int num : lst) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2 3 4
    ```

7. `pop_back`

   `pop_back` 用于移除 `list` 的最后一个元素。

    ```cpp
        std::list<int> lst = {1, 2, 3};
        // 移除最后一个元素
        lst.pop_back();
        for (int num : lst) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2
    ```

8. `resize`

    `resize` 用于改变 `list` 的大小。如果新的大小比原来大，新元素会用默认值填充；如果新的大小比原来小，`list` 会截断。

    ```cpp
        std::list<int> lst = {1, 2, 3};
        // 增大list大小，新元素默认初始化为 0
        lst.resize(5);
        for (int num : lst) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2 3 0 0

        // 缩小list大小
        lst.resize(2);
        for (int num : lst) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2
    ```

9. `reserve`

    `reserve` 用于为 `list` 预留一定的空间，避免多次重新分配内存。

    ```cpp
        std::list<int> lst;
        // 预留空间
        lst.reserve(10);
        for (int i = 0; i < 10; ++i) {
            lst.push_back(i); 
        }
        std::cout << "List的容量: " << lst.size() << std::endl; // 输出: 10
    ```

10. `shrink_to_fit`

    `shrink_to_fit` 用于将 `list` 的容量调整为和它的大小一致，释放多余的内存。

    ```cpp
        std::list<int> lst;
        lst.reserve(100);
        for (int i = 0; i < 5; ++i) {
            lst.push_back(i);
        }
        std::cout << "调整前的容量: " << lst.size() << std::endl; // 输出: 100
        lst.shrink_to_fit();
        std::cout << "调整后的容量: " << lst.size() << std::endl; // 输出: 5
    ```

11. `swap`

    `swap` 用于交换两个 `list` 的内容。

    ```cpp
        std::list<int> lst1 = {1, 2, 3};
        std::list<int> lst2 = {4, 5, 6};
        // 交换两个list的内容
        lst1.swap(lst2);
        for (int num : lst1) {
            std::cout << num << " "; 
        }
        std::cout << std::endl; // 输出: 4 5 6
        for (int num : lst2) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2 3
    ```

12. `merge`

    `merge` 用于将一个 `list` 的内容合并到另一个 `list` 中，并且保持两个 `list` 都是有序的。

    ```cpp
        std::list<int> lst1 = {1, 3, 5};
        std::list<int> lst2 = {2, 4, 6};
        // 将lst2的内容合并到lst1中
        lst1.merge(lst2);
        for (int num : lst1) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2 3 4 5 6
    ```

13. `splice`

    `splice` 用于将一个 `list` 中的元素移动到另一个 `list` 的指定位置。

    ```cpp
        std::list<int> lst1 = {1, 2, 3};
        std::list<int> lst2 = {4, 5, 6};
        // 将lst2的第一个元素移动到lst1的末尾
        lst1.splice(lst1.end(), lst2, lst2.begin());
        for (int num : lst1) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2 3 4
        for (int num : lst2) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 5 6
    ```

14. `remove`

    `remove` 用于移除 `list` 中所有等于给定值的元素。

    ```cpp
        std::list<int> lst = {1, 2, 3, 2, 4, 2};
        // 移除所有等于2的元素
        lst.remove(2);
        for (int num : lst) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 3 4
    ```

15. `unique`

    `unique` 用于移除 `list` 中相邻的重复元素，只保留一个。

    ```cpp
        std::list<int> lst = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
        // 移除相邻的重复元素
        lst.unique();
        for (int num : lst) {
            std::cout << num << " ";
        }
        std::cout << std::endl; // 输出: 1 2 3 4 5
    ```

16. `sort`

     `sort` 用于对 `list` 中的元素进行排序。

     ```cpp
         std::list<int> lst = {5, 2, 8, 1, 9};
         // 对list进行排序
         lst.sort();
         for (int num : lst) {
             std::cout << num << " ";
         }
         std::cout << std::endl; // 输出: 1 2 5 8 9
     ```

## 优先队列

## 树

