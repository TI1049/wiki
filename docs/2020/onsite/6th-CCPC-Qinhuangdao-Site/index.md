# 第六届 CCPC 秦皇岛

???+ info "Contents"
    [TOC]

## Contest Info

[Practice Link]()

| Solved |   A   |   B   |   C   |   D   |   E   |   F   |   G   |   H   |   I   |   J   |   K   |   L   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|  5/12  |   O   |   -   |   O   |   -   |   O   |   O   |   O   |   -   |   -   |   -   |   -   |   -   |

* O 在比赛中通过
* Ø 赛后通过
* ! 尝试了但是失败了
* \- 没有尝试

## Solutions

### Problem A. A Greeting from Qinhuangdao

Solved By Dup4. 9(+)

#### 题意

给出 $r$ 和红球，$b$ 个蓝球，问取两个球，都是红球的概率是多少？

#### 思路

$\displaystyle \frac{r}{r + b} \cdot \frac{r - 1}{r + b - 1}$

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/6th-CCPC-Qinhuangdao-Site/solutions/a.cpp
    ---8<--
    ```

### Problem B. Bounding Wall

Upsolved By -.

#### 题意

#### 思路

### Problem C. Cameraman

Solved By Dup4 & groggy\_. -

#### 题意

* 给出一个矩形，左下角是 $(0, 0)$, 右上角是 $(w, h)$, 并且给出一个点 $(x, y)(1 \leq x \leq w - 1, 1 \leq y \leq h - 1)$。
* 在矩形内部有 $n$ 个点，现在要找个点射出去两条线，使得射线以及矩形围成的闭合区域只有 $(x, y)$ 这个点。
* 现在要求两条射线与矩形围成的闭合区域中，矩形那部分的变长和最长。

#### 思路

* 大力猜测要找的那个点就可以是 $(x, y)$。
* 然后从 $(x, y)$ 向其它点连射线，交矩形一个点。
* 对求出的点做直角排序。
  * 我们直接直角排序发现过不了。
  * 后来考虑每个点肯定在矩形的四条边上，那么我们对这四条边的上的点分别排序，最后找个方向合并起来。
* 然后计算相邻两点之间围成的变长和。
  * 这里其实情况有很多种，但是如果加入矩形的四个角作为虚点。
  * 那么相邻亮点肯定在矩形的一条边上，这个时候求距离很简单。
  * 那么就转化成了两个实点之间相邻两点的边长和。

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/6th-CCPC-Qinhuangdao-Site/solutions/c.cpp
    ---8<--
    ```

### Problem D. Defend City

Upsolved By -.

#### 题意

#### 思路

### Problem E. Exam Results

Solved By Dup4 & ltslts. 76(+1)

#### 题意

* 给出 $n$ 个人和一个概率参数 $p$。
* 对于每个人，在一场考试中，如果他发挥的好，他会得到 $a_i$ 的分数，否则得到 $b_i$ 的分数。
* 在一场考试中，假定最高分数为 $x$，那么只要一个人得到的分数大于等于 $x \cdot p\%$，那么他就能通过这场考试。
* 问所有 $2^n$ 的情况中，最多能有多少人通过考试。

#### 思路

* 将所有分数排序。
* 然后从大到小枚举 $x$，然后维护两个指针。
  * 一个是要所有大于 $x$ 的分数都不能要。
  * 一个是所有小于 $x \cdot p\%$ 的分数都不能加入。
    * 但是考虑 $x$ 是递减的，所以下界是逐渐减小，所以是慢慢加入很多可以的点。
  * 所以每个分数只会被加入一次，剔除一次。
* 要注意的是，如果一个人两个分数都因为大于 $x$ 而被剔除掉，是不合法的情况。

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/6th-CCPC-Qinhuangdao-Site/solutions/e.cpp
    ---8<--
    ```

### Problem F. Friendly Group

Solved By Dup4 & ltslts. 44(+)

#### 题意

* 给出 $n$ 个点和 $m$ 条边。
* 现在要给出一个子图，定义价值为：
  $$
  V = \mbox{连接这个子图中两点的边的数量} - \mbox{点数} - \mbox{其中一个点在子图中，另一个点在子图外的边的数量}
  $$
* 问如何选子图，使得价值最大？

#### 思路

* 贪心，选择正收益的每一个连通块。

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/6th-CCPC-Qinhuangdao-Site/solutions/f.cpp
    ---8<--
    ```

### Problem G. Good Number

Solved By Dup4. 34(+)

#### 题意

* 给出 $n$ 和 $k$。
* 统计 $[1, n]$ 中有多少个 $x$ 满足 $\displaystyle \lfloor \sqrt[k]{x} \rfloor \;\;|\;\; x$。

#### 思路

* $k = 1$ 的时候特判。
* 考虑 $\lfloor \sqrt[k]{x} \rfloor$ 的种类只有 $\lfloor \sqrt[k]{n} \rfloor$ 种。
* 那么对于 $i$，它掌管的范围是 $[i^k, (i + 1)^k)$, 直接统计这个范围内有多少个 $i$ 的倍数即可。

??? info "Code"
    ```cpp
    ---8<--
    2020/onsite/6th-CCPC-Qinhuangdao-Site/solutions/g.cpp
    ---8<--
    ```

### Problem H. Holy Sequence

Upsolved By -.

#### 题意

#### 思路

### Problem I. Interstellar Hunter

Upsolved By -.

#### 题意

#### 思路

### Problem J. Jewel Splitting

Upsolved By -.

#### 题意

#### 思路

### Problem K. Kingdom’s Power

Upsolved By -.

#### 题意

* 给出 $n$ 个点的有根树，根为 $1$。
* 在根结点，有无限个士兵。
* 每次可以调配一个士兵，向它相邻的点走一步。
* 问所有点都至少被一个士兵访问过的最小次数。

#### 思路

### Problem L.  Lost Temple

Upsolved By -.

#### 题意

#### 思路
