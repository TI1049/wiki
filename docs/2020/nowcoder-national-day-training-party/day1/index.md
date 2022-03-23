# 2020 牛客国庆集训派对 Day1

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://ac.nowcoder.com/acm/contest/7817)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  6/10  |   O   |   O   |   O   |   O   |   O   |   -   |   -   |   O   |   -   |   -   |

* O    在比赛中通过
* Ø    赛后通过
* !    尝试了但是失败了
* \-   没有尝试

## Solutions

### Problem A. ABB

Solved By Dup4. 00:08(+)

#### 题意

给出一个字符串 $S$，问在该字符串末尾最少添加多少个字符使得该字符串能够变成一个回文串？

#### 思路

找一个最长的回文后缀，然后在末尾补齐前缀所对应的回文的那部分即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day1/solutions/a.cpp
    ---8<--
    ```

### Problem B. Be Geeks!

Solved By Dup4. 01:19(+2)

#### 题意

给出一个长度为 $n$ 的序列 $a_i$, 定义：

* $G(i, j) = \gcd(a_i, a_{i + 1}, \cdots, a_j)$
* $M(i, j) = \max(a_i, a_{i + 1}, \cdots, a_j)$
* $P(i, j) = G(i, j) \cdot M(i, j)$
* $F(A) = \sum P(i, j)$

然后就是要求 $F(A)$。

#### 思路

简单来说，就是求这个序列当中任意一个连续子序列的最大值乘上子序列的最大公约数的总和。

* 首先我们通过笛卡尔树，求出每个值它所控制的那段范围。
* 然后枚举每个值作为最大值，并且假设它控制的那段字段为 $[l_i, r_i]$, 然后枚举短的那边，用二分去弄另一边。能这么做的原因是因为，一段序列中，控制了起点，对于不同终点来说，只有 $\mathcal{O}(\log n)$ 个不同的最大公约数。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day1/solutions/b.cpp
    ---8<--
    ```

### Problem C. Bob in Wonderland

Solved By Dup4. 01:50(+1)

#### 题意

给出一棵树，每次可以断掉一条边变成两个连通块，然后可以加入一条边，将两个连通块连通。

问最少多少次操作可以将这棵树变成一个链。

#### 思路

如果是一棵有根树，那么贪心策略是固定的，就是对于一个点，假设它的孩子有 $x$ 个，那么对于这个点，要断掉 $x - 1$ 条边。

现在的问题是，这是一棵无根树，那么换根 DP 一下即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day1/solutions/c.cpp
    ---8<--
    ```

### Problem D. Deep800080

Solved By Dup4 & lts. 04:50(+7)

#### 题意

给出 $n$ 个点，然后可以在通过 $(0, 0)$ 到 $(A, B)$ 的这条直线上找一个点画一个圆，半径为 $R$，使得这个圆能够覆盖到尽可能多的点。

问最多能覆盖到多少个点？

#### 思路

以每个点为圆心，半径为 $R$ 画圆，然后它会跟那条直线最多相交两个点，只要我们选的点落在这两个点确定的线段之内，这个点就可以被覆盖。

那么问题变成了，有若干条线段，问被线段覆盖次数最多的点被覆盖了多少次？

至于精度问题的话，扩大一下转化成整数会好做一点。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day1/solutions/d.cpp
    ---8<--
    ```

### Problem E. Zeldain Garden

Solved By Dup4. 01:28(+)

#### 题意

求 $[l, r]$ 中每个数的因数个数之和。

#### 思路

$[1, n]$ 中的因子数之和的答案是 $ \displaystyle \sum\limits_{i = 1}^n \lfloor \frac{n}{i} \rfloor  $。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day1/solutions/e.cpp
    ---8<--
    ```

### Problem F. Light Emitting Hindenburg

Upsolved By -.

#### 题意

#### 思路

### Problem G. K==S

Upsolved By -.

#### 题意

#### 思路

### Problem H. Ponk Warshall

Solved By Dup4 & lts. 02:26(+)

#### 题意

给出连个个字符串 $S$ 和 $T$，并且只有四种字符 `A`,`C`,`G`,`T`，只有一种操作，就是交换 $S$ 中任意两个位置的字符，问最少需要多少次操作能够将 $S$ 变成 $T$。

#### 思路

对于一个环，那么需要 $\mbox{环的长度} - 1$ 次操作能够将这个环上的每一对都复原。

比如说 `AC` 和 `CA`，只需要一次交换。

并且环的长度越小越好，即环的个数越多越好。

我们虽然不知道怎么证，但是我们能猜出来贪心先去找二元环，再去找三元环，再去找四元环即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day1/solutions/h.cpp
    ---8<--
    ```

### Problem I. Saba1000kg

Upsolved By -.

#### 题意

#### 思路

### Problem J. The Bugs

Upsolved By -.

#### 题意

#### 思路
