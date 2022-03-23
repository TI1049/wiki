# 2020 牛客国庆集训派对 Day7

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://ac.nowcoder.com/acm/contest/7858)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  5/11  |   O   |   O   |   O   |   O   |   -   |   -   |   -   |   -   |   -   |   O   |   -   |

* O    在比赛中通过
* Ø    赛后通过
* !    尝试了但是失败了
* \-   没有尝试

## Solutions

### Problem A. Laminar Family

Solved By Dup4. 04:28(+1)

#### 题意

给出一棵 $n$ 个点的树，以及 $m$ 条简单路径 $(a_i, b_i)$，问这 $m$ 条简单路径是否两两不相交或者处于包含关系。

#### 思路

* 按路径长度从大到小排序。
* 对于第 $i$ 段简单路径，我们在线段树上将这这段路径上的点的权值赋成 $i$。
* 然后对于当前路径 $(a_i, b_i)$，我们在线段树上查询这段路径的点权和，假设为 $y$，该路径上的点数为 $x$，那么我们知道如果这段简单路径属于之前的某段路径，而不是拼凑成的，那么肯定属于第 $\displaystyle \frac{y}{x}$ 条路径。
  * 可以额外判断第 $\displaystyle \frac{y}{x}$ 条路径是否包含 第 $i$ 条路径。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day7/solutions/a.cpp
    ---8<--
    ```

### Problem B. Abbreviation

Solved By Dup4. 00:49(+)

#### 题意

给出一个字符串，给连续的只被一个空格间隔的并且首字母大写的单词连成的短语加上缩写。

#### 思路

模拟就完了。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day7/solutions/b.cpp
    ---8<--
    ```

### Problem C. Expect to Wait

Solved By Dup4. 02:03(+1)

#### 题意

给出 $n$ 种操作：

* `+ t k`, 表示在第 $t$ 时刻加入 $k$ 辆车。
* `- t k`, 表示在第 $t$ 时刻有 $K$ 个用车需求。

有 $q$ 次询问，每次询问表示假如加入操作 `+ 0 a`, 那么对于每个用车需求总共的等待时间是多少？

#### 思路

* 将时间拆成 $n$ 段，第 $i$ 段为 $t_i - t_{i - 1}$。
* 那么考虑在第 $i$ 个操作种加入一辆车，其实就是在第 $[i + 1, n]$ 的时间段里减一。
* 在第 $i$ 个操作中有一个用车需求，就是在第 $[i + 1, n]$ 的时间段里加一。
* 对于 $q$ 次询问，将询问按 $a_i$ 排序，每次剔除时间段内权值小于等于 $0$ 的那些段即可，剩下的没被剔除的总和就是答案。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day7/solutions/c.cpp
    ---8<--
    ```

### Problem D. Foreign Postcards

Solved By Dup4. 03:31(+)

#### 题意

给出 $n$ 张扑克牌，`C` 表示第 $i$ 张扑克牌正面朝上，`W` 表示反面朝上。现在将 $n$ 张牌入栈，并执行以下流程：

* 令当前栈的大小为 $n$，首先在 $[1, n]$ 中随机一个数 $k$。
* 然后从栈中取出 $k$ 张牌，如果取出的第一张牌是 `W`，那么将取出的所有牌都翻一个面。
* 循环上述流程，直到栈空。

问流程结束后，反面朝上的牌的个数的期望是多少？

#### 思路

* 令 $f_i$ 表示栈底往上 $i$ 张牌的期望是多少。
* 然后对于当前 $i$，我们都要从 $f_j(j \leq i)$ 转移过来。并且根据当前第 $i$ 张牌的状态决定加上的贡献是区间内 `W` 的牌还是 `C` 的牌。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day7/solutions/d.cpp
    ---8<--
    ```

### Problem E. Game on Graph

Upsolved By -.

#### 题意

#### 思路

### Problem F. Jenga Boom

Upsolved By -.

#### 题意

#### 思路

### Problem G. List of Primes

Upsolved By -.

#### 题意

#### 思路

### Problem H. Mole Tunnels

Upsolved By -.

#### 题意

#### 思路

### Problem I. Bowlstack

Upsolved By -.

#### 题意

#### 思路

### Problem J. Adjustment Office

Solved By Dup4. 00:11(+)

#### 题意

给出一个 $n \cdot n$ 的矩阵，其中 $a_{i, j} = i + j$，有两种操作：

* `R r`，表示输出矩阵中第 $r$ 行的数的和，并且将这行数都变成 $0$。
* `C c`, 表示输出矩阵中第 $c$ 列的数的和，并且将这列数都变成 $0$。

#### 思路

* 以行为例，对于当前行我们只需要知道这一行有多少列没被清 $0$，以及没被清 $0$ 的行的数的和即可。
* 用数据结构维护行信息以及列信息。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day7/solutions/j.cpp
    ---8<--
    ```

### Problem K. Binary vs Decimal

Upsolved By -.

#### 题意

#### 思路
