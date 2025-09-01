/**
 * 总的来说，这个想法是基于分治法的思想。
 * 我们常常用a^n = a*a*a...*a (n个a相乘)来表示a的n次方。
 * 我们也知道a^(b+c)=a^b*a^c。
  

 * 我们把3^13拆成3^(8+4+1)，
 * 也就是3^8 * 3^4 * 3^1。
 * 注意到8,4,1都是2的幂次方。
 * 所以我们只要把 幂 对应二进制位为1的那些2的幂次方的结果相乘就行了。
 */

#include <iostream>
typedef long long LL

using namespace std;

LL quickPow(LL a, LL b) {
    if (b == 0) {
        return 1;
    }

    if (b == 1) {
        return a;
    }

    // 递归调用：先计算 a^(b/2)
    LL half = quickPow(a, b / 2);

    // 根据 b 的奇偶性进行判断
    // 如果 b 是偶数，那么 a^b = (a^(b/2))^2
    if (b % 2 == 0) {
        return half * half;
    } else { // 如果 b 是奇数，那么 a^b = a * (a^(b/2))^2
        return a * half * half;
    }
}

LL quickPowIter(LL a, LL b){
    LL result = 1 ;

    while(b>0){
        
        if(b % 2 == 1){
            result *= a;
        }

        a <<= 1;
        b >>= 1;
    }

    return result;
}

LL fastPow(LL a, LL b,LL m){
    LL result = 1;

    a% = m;

    while(b){
        if(b & 1){
            result = (result * a) % m;
        }

        a = (a * a) % m;
        b >>= 1;
    }

    return result;
}