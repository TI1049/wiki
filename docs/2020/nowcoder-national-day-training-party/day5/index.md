# 2020 牛客国庆集训派对 Day5

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://ac.nowcoder.com/acm/contest/7852)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  6/11  |   -   |   O   |   O   |   O   |   Ø   |   -   |   -   |   O   |   -   |   -   |   O   |

* O    在比赛中通过
* Ø    赛后通过
* !    尝试了但是失败了
* \-   没有尝试

## Solutions

### Problem A. Kingdom Reunion

Upsolved By -.

#### 题意

#### 思路

### Problem B. Hyperdrome

Solved By Dup4. 01:51(+1)

#### 题意

给出一个字符串，找出有多少个子串满足重新排列后是一个回文串。

#### 思路

题意的要求就是找有多少个子串，使得最多只有一种字符出现的次数为奇数。

我们考虑维护一个前缀字符出现信息 $f_i$，$0$ 表示出现偶数次，$1$ 表示出现奇数次，那么任意一个子串 $[l_i, r_i]$，只要满足 $f_r \oplus f_{l - 1}$ 中最多只有一位为 $1$ 就可以了。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day5/solutions/b.cpp
    ---8<--
    ```

### Problem C. Great Deceiver

Solved By Dup4. 02:21(+)

#### 题意

给出一个 $n$ 和 $k$，要求十进制中小于等于 $n$ 的数中，在 $+k$ 进制和 $-k$ 进制下相等的数有多少个。

#### 思路

在 $+k$ 进制下 和 $-k$ 进制下相等，即表明奇数次幂上的值全都为 $0$ 即可。
那么我们去掉奇数次幂，贪心出最大值，即为最多的数。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day5/solutions/c.cpp
    ---8<--
    ```

### Problem D. Exact Measurement

Solved By Dup4 & groggy\_. 04:35(+1)

#### 题意

给出 $n$ 个箱子，每个箱子有 $10^{k_i}$ 的砝码有 $q_i$ 个，现在要取最少的箱子，使得有一种方案取出这些箱子中的砝码使得重量和等于 $x$。
即箱子中的砝码可以不全取出来。

#### 思路

低位的砝码不能满足更低位的需求，但是能够满足高位的需求。
那么我们从地位到高位贪心，每次遍历到一位，都会解锁若干箱子，然后丢进最大堆，每次取盒子砝码总重量大的即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day5/solutions/d.cpp
    ---8<--
    ```

### Problem E. Caravan Robbers

Upsolved By Dup4.

#### 题意

给出 $n$ 个线段 $[a_i, b_i]$，满足 $i \leq j$, 有 $a_i \leq a_j, b_i \leq b_j$, 现在要找出最长的长度 $len$，满足每条线段都能取出那么长的子段，并且 $n$ 条线段不相交。

#### 思路

* 如果有两个重叠的线段，那么可以取平均值。但是要跟各自的本身的线段长度取 `Min`。
* 那么对于 $x$ 个重叠的线段，答案应该是任意连续个线段的平均值的最小值。
* 但是这么做复杂度是 $\mathcal{O}(n^2)$。
* 那么我们考虑二分，然后贪心判断。
* 但是答案要分数，我们考虑小数如何化分数。
    * 考虑分数 $\displaystyle \frac{p}{q} = d$, 有 $\displaystyle p = qd$。
    * 所以我们枚举分母 $q$，此处根据前面的分析，显然当所有线段挤在一起的时候，分数最大为 $n$。
    * 通过控制误差去得到更精确的值。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day5/solutions/e.cpp
    ---8<--
    ```

### Problem F. Kabaleo Lite

Upsolved By -.

#### 题意

#### 思路

### Problem G. Hack Protection

Upsolved By -.

#### 题意

#### 思路

### Problem H. Fraud Busters

Solved By groggy\_. 00:34(+)

#### 题意

配出字符串，求有多少个匹配

#### 思路

暴力匹配

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day5/solutions/h.cpp
    ---8<--
    ```

### Problem I. Cactus Automorphisms

Upsolved By -.

#### 题意

#### 思路

### Problem J. Bonus Cards

Upsolved By -.

#### 题意

#### 思路

### Problem K. Knockout Racing

Solved By groggy\_. 00:25(+1)

#### 题意

每辆车在 $a$ 和 $b$ 之间来回移动。
求 $t$ 时刻，$x$ 和 $y$ 区间内有多少辆车。

#### 思路

计算查询时刻的每个车位置

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day5/solutions/k.cpp
    ---8<--
    ```
