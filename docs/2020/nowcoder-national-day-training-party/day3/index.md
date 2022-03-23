# 2020 牛客国庆集训派对 Day3

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://ac.nowcoder.com/acm/contest/7830)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  5/10  |   O   |   O   |   -   |   -   |   -   |   O   |   -   |   -   |   Ø   |   O   |

* O    在比赛中通过
* Ø    赛后通过
* !    尝试了但是失败了
* \-   没有尝试

## Solutions

### Problem A. Leftbest

Solved By Dup4. 00:13(+)

#### 题意

给出 $n$ 个数，对于第 $i$ 个数，要求出在它之前的比它大的，并且最小的数，如果不存在就为 $0$，然后将所有数求和。

#### 思路

维护一个 `set` 即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day3/solutions/a.cpp
    ---8<--
    ```

### Problem B. First Date

Solved By all. 03:15(+)

#### 题意

给出 $n$ 个点，$m$ 条边的无向图，每条边权为 $x_i + a \cdot y_i$，其中 $a \in [0, 1]$ 为一个随机因子，现在求 $S \rightarrow T$ 的最短路的期望。

#### 思路

因为精度要求很低，直接给随机因子每次增量 $0.0001$ 模拟即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day3/solutions/b.cpp
    ---8<--
    ```

### Problem C. Sequence

Upsolved By -.

#### 题意

#### 思路

### Problem D. Capture Stars

Upsolved By -.

#### 题意

#### 思路

### Problem E. Triangulation

Upsolved By -.

#### 题意

#### 思路

### Problem F. Points

Solved By Dup4. 00:06(+)

#### 题意

给出一棵树，求度数为 $1$ 的点的个数。

#### 思路

直接求。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day3/solutions/f.cpp
    ---8<--
    ```

### Problem G. ParallelNetworkAnalysis

Upsolved By -.

#### 题意

#### 思路

### Problem H. Graph

Upsolved By -.

#### 题意

#### 思路

### Problem I. Rooted Tree

Upsolved By Dup4.

#### 题意

给出 $n$ 个点，现在要构造一棵树，不超过三层，并且不同构的方案数。

#### 思路

第一层显然只有一个点，那么剩下 $n - 1$ 个点放在二、三层的方案，其实就是 $n - 1$ 的整数划分方案数。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day3/solutions/i.cpp
    ---8<--
    ```

### Problem J. Flowers

Solved By Dup4 & groggy\_. 01:24(+6)

#### 题意

给出 $n$ 种花，每种花有 $a_i$ 朵，要构成一束花，需要 $m$ 种不同的花，问最多能够构成多少束花？

#### 思路

二分答案 $x$，那么每种花最多使用 $x$ 朵，并且美多都能用上不会违反规则。假设这时所有可用的花朵有 $sum$ 朵，那么只要有 $\displaystyle \lfloor \frac{sum}{m} \rfloor \geq x$ 即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day3/solutions/j.cpp
    ---8<--
    ```
