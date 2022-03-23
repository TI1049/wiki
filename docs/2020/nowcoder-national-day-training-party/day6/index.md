# 2020 牛客国庆集训派对 Day6

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://ac.nowcoder.com/acm/contest/7854)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  6/11  |   O   |   O   |   -   |   -   |   O   |   O   |   -   |   -   |   O   |   Ø   |   -   |

* O    在比赛中通过
* Ø    赛后通过
* !    尝试了但是失败了
* \-   没有尝试

## Solutions

### Problem A. Fractions

Solved By Dup4 & lts. 01:38(+)

#### 题意

给出 $n$，要求找出 $k(1 \leq k \leq 10^5)$ 对分数 $\displaystyle \frac{a_i}{b_i}$，满足：

* $b_i \;|\; n$, 并且有 $1 \lt b_i \lt n$。
* $1 \leq a_i \lt b_i$。
* $\displaystyle \sum\limits_{i = 1}^k \frac{a_i}{b_i} = 1 - \frac{1}{n}$。

#### 思路

* 大力猜测两个分数就够了。
* 然后枚举出两个分母，做 `exgcd` 即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day6/solutions/a.cpp
    ---8<--
    ```

### Problem B. Guest Student

Solved By Dup4. 00:31(+1)

#### 题意

给出一周七天，哪些天有课，然后给出 $n$，问上 $n$ 天课需要的周期是多长。

#### 思路

枚举第一周和最后一周的开始位置和结束位置。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day6/solutions/b.cpp
    ---8<--
    ```

### Problem C. Harder Satisfiability

Upsolved By -.

#### 题意

#### 思路

### Problem D. Interval-Free Permutations

Upsolved By -.

#### 题意

#### 思路

### Problem E. King Kog's Reception

Solved By Dup4. 03:20(+)

#### 题意

给出 $q$ 个事件，事件类型有如下三种：

* `+ t d`, 表示在第 $t$ 时刻有个骑士需要参见国王，参见所需事件为 $d$。
* `- i`，表示取消第 $i$ 个事件。
* `? t`，表示询问公主如果在第 $t$ 时刻来见国王，需要等多久。如果同一时刻，也有骑士在等，那么骑士优先。

#### 思路

我们用 $f_i$ 表示前 $i$ 个时刻所有参见事件全都结束需要的时间，那么有：

$$
\begin{eqnarray*}
f_i = \max(f_{i - 1}, i) + d_i
\end{eqnarray*}
$$

然后发现这个东西可以用线段树维护。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day6/solutions/e.cpp
    ---8<--
    ```

### Problem F. Lazyland

Solved By Dup4. 00:38(+)

#### 题意

给出 $n$ 个人以及 $m$ 个任务，并且第 $i$ 个人想要做第 $a_i$ 个任务，要想劝说第 $i$ 个人改变他的意志需要花费 $b_i$ 的代价，现在要求每个任务至少有一个人需要做，最少需要花费多少代价。

#### 思路

将每个任务不用劝说的人中，除了代价最高的那个人，其他人全都丢进最小堆中，然后贪心取出来去做其他任务。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day6/solutions/f.cpp
    ---8<--
    ```

### Problem G. Minegraphed

Upsolved By -.

#### 题意

#### 思路

### Problem H. Archery Tournament

Upsolved By -.

#### 题意

#### 思路

### Problem I. Box

Solved By groggy\_. 01:09(+1)

#### 题意

对于给出宽为 $w$，高为 $h$ 的纸，需要剪出 $a \cdot b \cdot c$ 的长方体，问能否裁出

#### 思路

长方体的构成方式可以看作两种，用不同边长尝试出各种宽与高的可能性，判断即可

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day6/solutions/i.cpp
    ---8<--
    ```

### Problem J. Connections

Upsolved By Dup4.

#### 题意

给出 $n$ 个点 $m \gt 2 \cdot n$ 条边的有向强连通图，现在要求只保留 $2n$ 条边，使得图仍然是强连通的。

#### 思路

随便找个点作为根，跑出一个 `dfs` 树，然后在反图上，还是以这个点为根，跑出一个 `dfs` 树即可。

显然，这两棵树所用的边不会超过 $2(n - 1)$。

??? info "Code"
    ```cpp
    ---8<--
    2020/nowcoder-national-day-training-party/day6/solutions/j.cpp
    ---8<--
    ```

### Problem K. The Final Level

Upsolved By -.

#### 题意

#### 思路
