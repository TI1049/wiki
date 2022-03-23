# 第十七届中国计量大学程序设计竞赛

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link](https://ac.nowcoder.com/acm/contest/7591)

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |   M   |   N   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 12/14  |   O   |   O   |   O   |   O   |   O   |   O   |   Ø   |   O   |   O   |   O   |   O   |   O   |   -   |   -   |

* O  在比赛中通过
* Ø  赛后通过
* !  尝试了但是失败了
* \- 没有尝试

## Solutions

### Problem A

Solved By Dup4. 01:49(+)

#### 题意

抽象一下，就是树上的 `DFS序` 上区间更新，单点查询。

#### 思路

随便搞个数据结构维护一下。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/a.cpp
    ---8<--
    ```

### Problem B

Solved By Dup4. 01:16(+)

#### 题意

给出两个 `01` 串 $A$ 和 $B$，每次可以执行的操作有：

* 将所有位都变成 $0$。
* 翻转一个后缀的状态。

问将 $A$ 变成 $B$ 最少的操作步骤。

#### 思路

如果需要执行第一种操作，显然肯定是第一次执行。

根据这个讨论两种情况，发现只用第二种操作，最少步数是固定的，肯定是从前往后去翻转，因为一次翻转只会影响后缀，前面的位是不会变的。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/b.cpp
    ---8<--
    ```

### Problem C

Solved By Dup4. 01:03(+)

#### 题意

要烤牛排，有 $n$ 个步骤，需要在每个步骤烤制一分钟。

第 $i$ 个步骤有温度要求 $[l_i, r_i]$，当烤肉机的温度在这个范围内才能烤制一分钟并且到下一个步骤。

每分钟可以将烤肉机的温度升高或者降低 $1$ 度。

刚开始的温度是 $0$。

#### 思路

刚开始的温度固定，显然就有贪心策略：对于每个步骤，如果温度符合，就不变，否则根据小于或者大于，刚好变化到当前步骤的边界即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/c.cpp
    ---8<--
    ```

### Problem D

Solved By ltslts. 02:55(+)

#### 题意

取石子，每次只能选择一堆，选取不少于上次拿的数。然后最后如果有剩余的石子，最后一个人必须取完。取完的人输，问先手第一次取多少个才能必赢，如果不能输出 $-1$.

#### 思路

- 如果最大数量的堆有奇数个，那么先手取最大的数量即必胜策略，以此类推，降序的石堆中如果有某个数量是奇数，那么先手的即取该数量的石子。
- 特殊的，如果所有数量的石堆都是偶数个，那么先手必胜，如果先手取的是最小数量的石堆，并且最小数量的石堆个数为奇数，那么先手必败。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/d.cpp
    ---8<--
    ```

### Problem E

Solved By groggy\_. 03:53(+)

#### 题意

一条链，每个节点数字表示节点附属的子节点，末尾节点一定包含一个子节点。
两个人轮流从末尾节点的子节点取若干个，当末尾节点无子节点时，末尾节点的父亲节点成为新的末尾节点。
最后拿完的人输，求先手者能否胜利。

#### 思路

根据子节点是否唯一可以判断是否改变先后手，递推即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/e.cpp
    ---8<--
    ```

### Problem F

Solved By Dup4. 00:13(+)

#### 题意

签到。

#### 思路

??? info "Code"
    ```py
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/f.py
    ---8<--
    ```

### Problem G

Upsolved By Dup4.

#### 题意

给出一张 $n$ 个点 $m$ 条边的无向图，每个点有一种颜色 $a_i$，有 $q$ 次操作：

* `1 u x`, 将点 $u$ 的颜色染成 $x$。
* `2 u`，询问如果将点 $u$ 重新染色，并且不和点 $u$ 相邻的任意一点的颜色一样，那么可染色的颜色中，编号最小的是多少？

#### 思路

* 根据度数分成大点和小点。
* 显然小点的答案很好算，复杂度 $\mathcal{O}(\sqrt{n})$。
* 对于大点，只有 $\sqrt{n}$ 个大点，对于每个大点都维护一个 `BitSet`，然后对于每次更新颜色都修改一下大点的 `BitSet` 中的对应位置。
  * 我不知道 `C++` 中的 `BitSet` 怎么实现的，也不知道修改单点信息的复杂度是多少，但是如果自己写一个 `BitSet`，修改单点信息是能够做到 $\mathcal{O}(1)$ 的。
  * 对于大点答案的查询，复杂度是 $\mathcal{O}(\frac{n}{w})$。
* 所以最优情况下，能够做到 $\displaystyle \mathcal{O} (\frac{n^2}{w} + n \cdot \sqrt{n})$。
* 其实也可以用树状数组来维护，查询的时候二分即可，这样复杂度是 $\mathcal{\log^2 n}$，如果用线段树的话，查询复杂度能够做到 $\mathcal{o}(\log n)$。但是更新的时候线段树常数大，树状数组常数小。感觉没什么差别。这样的话，复杂度能够做到 $\mathcal{O}(n \cdot \sqrt{n} \cdot \log n + n \cdot \log^2 n)$。
* 我感觉题意有点问题：
  > * Type 1:`1 u x`($0 \leq x \leq 10^9$)–Change the colour of area $u$ to $x$.
  > * Type 2:`2 u`–At this time, the little beauty wants to draw area u, YHH will pass a brush according to the above rules, which number is what you should print.
  * 说实话，从这两句话我看不出第 $2$ 种操作后也需要将 $u$ 的颜色更改为询问的答案，但是实际上是要这么做的，但是这好像给「强制在线」提供了一种比较好的思路。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/g.cpp
    ---8<--
    ```

### Problem H

Solved By Dup4. 01:27(+)

#### 题意

#### 思路

线段树区间更新，全局查询。

可能有更简短的做法。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/h.cpp
    ---8<--
    ```

### Problem I

Solved By all. 01:56(+6)

#### 题意

给出 $n$ 个点，问你是否有一种方案，使得这 $n$ 个点不重叠，并且任意两点的中垂线之间都至少有一个点。

#### 思路

$  n \geq 3 $ 时答案为 `Yes`。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/i.cpp
    ---8<--
    ```

### Problem J

Solved By Dup4. 03:22(+1)

#### 题意

给出 $n$ 个人，要求组成不超过两支队伍，并且每个人都要在一支队伍中。现在给出 $m$ 条关系 $(a_i, b_i, t_i)$，表示 $a_i$ 和 $b_i$ 要想在一支队伍的话，至少需要 $t_i$ 的时间去磨合。

如果对于一对 $a_j, b_j$ 没有在 $m$ 条关系中给出，可以理解为这两个人不需要时间磨合。

一支队伍的磨合时间为队伍中任意两人所需磨合时间的最大值。

现在问所有人都有队伍并且磨合完毕的最少时间是多少。

#### 思路

二分答案 $x$，然后考虑补图，即保留所有边权大于 $x$ 的边，在补图中连边等价于这两个人不能在一个队伍里，那么二分图染色判断是否是二分图就可以了。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/j.cpp
    ---8<--
    ```

### Problem K

Solved By ltslts and Dup4. 01:33(+2)

#### 题意

给出若干个身份证号，判断有多少个子串是合法的回文日期。

#### 思路

暴力。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/k.cpp
    ---8<--
    ```

### Problem L

Solved By Dup4. 04:29(+1)

#### 题意

给出若干个身份证号，判断有多少个子序列是合法的回文日期。

#### 思路

在题意限定日期范围内，合法回文日期只有 $12$ 个，那么直接转化成给出两个字符串 $S$ 和 $T$，问 $S$ 中有多少个子序列是 $T$，直接 `DP` 即可，时间复杂度 $\mathcal{O}(|S||T|)$。

??? info "Code"
    ```cpp
    ---8<--
    2020/random-trainings/17th-cjlu-cpc/solutions/l.cpp
    ---8<--
    ```

### Problem M

Solved By . 0:00(+)

#### 题意

#### 思路

### Problem N

Solved By . 0:00(+)

#### 题意

#### 思路
