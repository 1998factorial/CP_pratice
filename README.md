# CP_pratice
## Solutions on codeforces

- https://codeforces.com/contest/567/problem/F
```
2 requirement about permutation

1. first go up then go down. (or simply just go up or just go down)
2. follow the inequalities
```
```
Ignoring the second constraint, how do we arrange?
```
```
...N,N...
then we consider N-1
we can have ..N-1,N,N,N-1..
or
..N-1,N-1,N,N,...
or
..N,N,N-1,N-1
```
```
so let dp[l][r] = the number of ways to arrange the last (r - l + 1) / 2 numbers 
dp[l][r] = dp[l + 1][r - 1] + dp[l + 2][r] + dp[l][r - 2]
```
```
now, we consider the second constraint.
we can simply do another iteration for checking
```
```
overrall, O(N^3)
```
[code](https://codeforces.com/contest/567/submission/127784130)
- https://codeforces.com/contest/115/problem/E
```
not hard to come up with a dp solution first
```
```
dp[i] = maximal profit we can get if we consider only the first i roads & races 
are completely covered in the first i roads
dp[i] = max{dp[i - 1] , max{dp[j - 1] + good(j , i) - cost(j , i)}}
```
```
can we make this faster?
```
```
we can sweep while maintain a range tree that keeps each dp[j] + good(j + 1 , i) - cost(j + 1 , i)
```
```
when we consider i + 1th road, what happen?
```
```
all dp[j] + good(j + 1 , i) - cost(j + 1 , i) get -cost[i + 1], for j <= i
this need range addition
```
```
for each race that ends with i + 1th road, start with l, all dp[j] get profit of this race
, j < l
this also need range addition
```
```
after updates, we query the maximal in our tree
```
```
overrall, we need a lazy tree that supports max query, and range addition
```
[code](https://codeforces.com/contest/115/submission/127709002)
- https://codeforces.com/contest/1561/problem/E
```
For this question, think about what case we will not be able to have a solution
```
```
if odd on even / even on odd position => no solution
```
```
since this is about reverse, lets try to fix N and N - 1 first, we can make N - 1 and N to the end
by 5 steps
```
```
initially , suppose ...N..
step 1 : N....N-1.... 
step 2 : .....N,N-1..
step 3 : N-1,N,......
step 4 : N,N-1,......
step 5 : .......N-1,N
we need a total of (5N) / 2 operations
```
[code](https://codeforces.com/contest/1561/submission/127373382)
- https://codeforces.com/contest/1557/problem/E
```
A hard but interesting interactive problem
```
```
we need to force the king to move to one of the conners to win
```
```
How do we do it?
```
```
if we sweep from column 1 to column 8, what happen to king?
```
```
How many times can king go up if we sweep left to right starting from row 1?
```
```
It is not hard to find the answer after these hints.
```
[code](https://codeforces.com/contest/1557/submission/127256860)
- https://codeforces.com/contest/1549/problem/E
```
It is obvious that the answer is just 
sum{C(3 * i , x) | 0 <= i <= N}
The goal is to calculate it more efficiently 
```
```
There are 2 ways to solve this problem
```
```
solution 1: consider generating function:
f(x) = (1 + x)^3 + (1 + x)^6 + ... + (1 + x)^3N
the answer is just the xth cofficient of f(x)
```
```
solution 2:
let dp[x][0] = sum{C(3i , x) , i <= N - 1}
let dp[x][1] = sum{C(3i + 1 , x) , i <= N - 1}
let dp[x][2] = sum{C(3i + 2 , x) , i <= N - 1}
answer for x is dp[x][0] + C(3N , x) 
since sum{C(i , j) , i <= n} = C(n + 1 , j + 1)
dp[x][0] + dp[x][1] + dp[x][2] = C(3N , x + 1)
since C(n , k) = C(n - 1 , k) + C(n - 1 , k - 1)
dp[x][1] = dp[x][0] + dp[x - 1][0]
dp[x][2] = dp[x][1] + dp[x - 1][1]
dp[x][0] = (C(3N , x + 1) - 2 * dp[x - 1][0] - dp[x - 1][1]) / 3
```

[code](https://codeforces.com/contest/1549/submission/126835025)

- https://codeforces.com/contest/1557/problem/D
```
solution: minimse the number of rows to be removed is the same as
maximise the number of rows kept.
```
```
we can treat each interval as event, and sweep on them
when we process an interval, link it with the smallest interval 
whose id is strictly greater. Link the largest interval whose 
id is strictly less to us. 
```
```
we will have a acyclic graph. we can then dp
```
[code](https://codeforces.com/contest/1557/submission/127313817)

- https://codeforces.com/contest/86/problem/D
```
solution: Here we use MO's algorithm. (answer for [l , r] -> [l -+ 1, r -+ 1]can be maintained in O(1))
```
[code](https://codeforces.com/contest/86/submission/125625397)
- https://codeforces.com/contest/258/problem/D 
```
solution: 
we need to process each query in order (order matters in this problem). Each query has 1/2 chance of run or not run. 
And we need to count the
expected number of inversion pairs after these M queries. 
There are many ways to calculate the expected number of inversions. 
eg, sum{e[i]} , where e[i] = expected
number of a[j] > a[i] where j < i. 
This approach could not work, as if we swap a[l] and a[r] many times, it is hard to maintain each e[i]. 
expected number of inversions could also be counted as : sum { Prob(a[i] > a[j]) * [i < j]}, 
and we use a new state: f[i][j] = Prob(a[i] > a[j])
for each query, 
it is not hard to observe the following transition: f[l][i] = f[r][i] = (f[l][i] + f[r][i]) / 2 , f[i][l] = f[i][r] = (f[i][l] + f[i][r]) / 2
f[l][r] = f[r][l] = 1/2. 
This approach allows us to maintain the information for each pair of (a[i] , a[j]).
```
[code](https://codeforces.com/contest/258/submission/125593954)
- https://codeforces.com/contest/86/problem/C
```
solution: We are given at most 10 patterns, 
each has length at most 10
We need to find the number of DNA sequence of length N <= 1000, such that, for each
1 <= i <= N, exists 1 <= l <= i <= r <= N , 
such that s[l..r] = some given pattern.
This means, each character must be included in a matched pattern in the constructed string.
```
```
This implies that while we are building the string, we need keep track of the suffix and prefix at the same time. 
what is this? This has a smell of KMP (longest proper suffix) 
However, we have more than one patterns. 
It might be AC-automaton then! 
(The idea of AC-automaton is like KMP on trie, we don't have pi function here, we have the "fail" link instead) 
```
```
Now, we can put all patterns into out AC-automaton and count while we traverse on trie. 
Let dp[i][j] be the number of good strings that we can make, 
whose length is i and we are currently standing at node j of the AC-automaton
```
```
However, this construction will have problem, 
that is, while we transit, 
we want our current suffix of the constructing string to match with at least one pattern, 
this means we can not move on to other nodes using fail link without specifing "ok, I have done with this particular pattern, now I am moving on". 
Also, patterns are allowed to overlap.
("AC" , "CB" , string "ACB" works.) 
In another word, dealing with "is this transition valid" is hard with this state.
```
```
The approach that solves this issue is: let dp[i][j][k] be the number of good strings whose length is i , 
and we are standing at node j , 
the last k characters in the string that we are constructing is not matched with any pattern yet.
```
```
We just need to store, for each the trie node, 
the longest pattern that using this node can match to.
```
```
while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i < 4; ++i){
        if(tr[u][i]){
            fail[tr[u][i]] = tr[fail[u]][i];
            q.push(tr[u][i]);
            val[tr[u][i]] = max(val[tr[u][i]] , val[fail[tr[u][i]]]); // <--- here updates the longest we can reach
        }
        else{
            tr[u][i] = tr[fail[u]][i];
        }
    }
}
```
```
After this, the transition is easy
```
```
    for(int i = 0; i < N; ++i){
        for(int j = 0; j <= tot; ++j){
            for(int k = 0; k < 10; ++k){
                if(dp[i][j][k] == 0)continue;
                for(int x = 0; x < 4; ++x){
                    int nj = tr[j][x];
                    if(val[nj] >= 1 + k){
                        dp[i + 1][nj][0] = add(dp[i + 1][nj][0] , dp[i][j][k]); // we can mark finish the matching for the last part
                    }
                    else{
                        dp[i + 1][nj][k + 1] = add(dp[i + 1][nj][k + 1] , dp[i][j][k]);
                        // we can not finish it now, we seek to find for next
                    }
                }
            }
        }
    }
```
[code](https://codeforces.com/contest/86/submission/125450299)
- https://codeforces.com/contest/83/problem/D
```
solution: let us think of a navie solution, 
let f(n , k) = the number of x <= n whose smallest non-one divisor = k. f(n , k) = n / k - sum{f(n / k , j) | 1 < j < k}. 
since n and k are 2e9 , this might be too slow. 
However, one can see that if k is not a prime then f(n , k) = 0. eg f(n , 4) = 0 as 4 | x => 2 | x. 
if k * k > n then f(n , k) = 1 (only x is k , no other number works). 
therefore, the amount of k is at most sqrt(n). 
also, for each recursive step, 
n shrinks by at least 2, 
so the height of the recursion tree is at most log(n , 2). The complexity is thus bounded by O(sqrt(n) * log(n , 2)) ~ 1381772
```
[code](https://codeforces.com/contest/83/problem/D)
- https://codeforces.com/contest/337/problem/E
```
solution: there are only n<=8 nodes, we can brute force all these cases. 
```
[code](https://codeforces.com/contest/337/submission/125267709)
- https://codeforces.com/contest/1073/problem/E
```
solution: f[i][mask][p][q][t] = the sum of all the prefixes of length i and used mask (set) of digits, p => if prefix is bounded by L , q => if prefix is bounded by R , t => if we have leading zeros. 
dp[i][mask][p][q][t] = number of ways to have prefix of length i ,(mask , p , q , t same meaning as before). 
and we can use dp table to update f table.
```
[code](https://codeforces.com/contest/1073/submission/125196173)
- https://codeforces.com/contest/744/problem/C
```
solution: A very smart way of dp. 
To buy a card the cost for red token is max(0 , r[i] - R) , for blue token max(0 , b[i] - B). 
Consider a simplier version, 
if cost for red = r[i] and cost for blue = b[i], what is the minimal day needed to buy all cards? The answer is max(sum{r[i]} , sum{b[i]}). 
Also, for those r[i] or b[i] >= N, their cost will always be r[i] - R or b[i] - B. So we mainly focus on those r[i] , b[i] < N. 
Now, we can dp. let dp[mask][i] be the maximal amount of blue token that we can save when we have bought mask (set) of cards,
and saved i red tokens in total. (note that i < N^2)
```
[code](https://codeforces.com/contest/744/submission/125157617)
- https://codeforces.com/contest/840/problem/C
```
we want to re-arrange the array, so that no adjcent pair a[i] * a[i + 1] is a perfect square. 
if a * b and b * c is perfect square, then a * c is also a perfect square. eg, 2 * 8 and 8 * 18. 
why? if a * b is perfect square, then for each p^x | a, and p^y | b, (x + y) % 2 = 0. so x and y have same parity. 
this relation is transitive, so for each p^x | a , p^y | b , p^z | c , (x + y) = (y + z) = (x + z) % 2. We can therefore group all pairwise perfect square. 
(Same as give them colour)
Now, our problem is the same as: given K different groups of elements, 
each have cnt[i] elements, we want to find the number of ways to arrange these elements into a row, 
such that no adjcent elements are from the same group. 
Let's try to solve this, group by group. 
Let dp[i][j] = the number of ways to arrange elements from first i groups, such that we have exactly j bad pairs (bad pair means adjcent pair are from same group) Consider the i+1 th group. 
First, we need to consider how many consecutive blocks that we are going to divide these cnt[i+1] elements into.
Say we divide them into x blocks, in how many ways can we do this? 
let f[n][k] = the number of ways to divide n elements into k non-empty groups, 
group-wise order doesn't matter, but element wise ordering matters. 
```
```
f[n][k] = f[n - 1][k - 1] + f[n - 1][k] * (n - 1 + k). 
(think each element as white balls , group can be black balls, put between white balls as barrier , 
the number of ways to not create another group while inserting nth element is (n - 1 + k) * f[n - 1][k])
```
```
Now, we are at dp[i][j] and we divide cnt[i+1] elements into x blocks, with f[cnt[i+1]][x] ways, 
we then consider how many "original bad pairs" we will destroy. 
Say y of them. we are puting y blocks from x blocks into these y bad pair positions.
And the rest of x - y blocks will be put in good positions. 
let sum{cnt[k] , k <= i} = prefix. we have 
```
```
dp[i + 1][j - y + cnt[i + 1] - x] += dp[i][j] * f[cnt[i + 1]][x] * C(x , y) * C(j , y) * C(prefix + 1 - j , x - y) * (x - y)! * y!
```
```
- note: we destroy y bad pairs, but creates cnt[i + 1] - x new bad pairs.
1. we have C(x , y) ways to select y bad blocks from a total of x blocks.
2. we have C(j , y) ways to select y bad positions from a total of j bad positions.
3. we have C(prefix + 1 - j , x - y) ways to select x - y positions from a total of prefix + 1 - j good positions.
4. we have y! ways to re-arrange y bad blocks (as f[cnt[i]][x] does not consider group-wise ordering).
5. we have (x - y)! ways to re-arrange x - y good blocks.
- our answer is just dp[K][0]
```
```
complexity is O(#groups * prefix * cnt[i] * cnt[i])
for i = 1 .. |groups|:
    for j = 0 .. cnt[1]+..+cnt[i]:
        for x = 1 .. cnt[i+1]:
            for y = 1 .. min(j,x):
```
```
note that the third for-loop only runs a total of N times
we can safely say that the solution is O(N^3)
```
[code](https://codeforces.com/contest/840/submission/125066900)
- https://codeforces.com/contest/317/problem/D
```
solution: Alice and Bob plays a game, each erase x , x^2 , x^3... x^k <= N
the one who can not make any move lose. 
Determine who can win if both play optimally. 
N is 1e9 , it is impossible to put every 1...N into a set and simulate the game, also, even if N is very small, 
simulating all possibilities is impossible. But if the set given looks like {x , x^2 , x^3 , x^4 , x^5}
and if Alice erase x^2 then the set will be {x , x^3 , x^5}. 
This process can be simulate by bitmask. With this, we try the following construction. 
Iterate x from 2 to sqrt(N), build set {x , x^2 , x^3 , ... , x^k}. 
Now, we are going to have sqrt(N) sets, where each set's size is at most 29. when Alice / Bob
pick some x, this x will only appear in exactly one set from all these sqrt(N) sets. 
(let y be the minimal y st y | x , x must be from the set starts with y, and this minimal value must be distinct by our construction)
Now, we have one important observation: 
we do not care about what values are in each set, we only care about their sizes now.
Our game has been broken into sqrt(N) independent sub-games. (and many other games whose size is 1)
Handeling subgames require SG number. 
we can precompute the SG number for each sizes from 2 ~ 29, using bitmask. At last, our answer is just the XOR sum of all these SG numbers. 
(Also need to check the number of subgames whose size = 1)
```
[code](https://codeforces.com/contest/317/submission/124941147)
- https://codeforces.com/contest/1555/problem/F
```
solution: There are a set of edges to add in, each with weight 0 or 1. 
We can add edge only when all simple cycles have weight 1 (weight is calculated by xor)
For each edge, if we add it, we say YES and add it into the graph, else, we say NO and don't add it. We can see that, 
no edge can be used in 2 different cycles. (Draw it and it is obvious) So we can first label edges as "cycle edge" or "tree edge". 
For each Tree edge, when we process them, we just add them and say YES.
For cycle edge, 
(u , v) we need to check if edges from u to v are included in any cycle before.(this can be done using Euler tour + fenwick tree) 
Then we need to have fast query for xor values from u to v, this can be done simply by tree dp.
```
The hard part is the implementation: [code](https://codeforces.com/contest/1555/submission/124841091)
- https://codeforces.com/contest/313/problem/D
```
solution: dp 
```
[code](https://codeforces.com/contest/313/problem/D)
- https://codeforces.com/contest/427/problem/D
```
solution: dp 
```
[code](https://codeforces.com/contest/427/submission/124731420)
- https://codeforces.com/contest/1129/problem/C
```
solution: Each time, we will append 0 or 1 to the end of our string. 
Except "0011", "0101", "1110", and "1111", all other length <= 4 0/1 string can be translated to some distinct alphabet. 
Our goal is to, after each append operation, we need to calculate the number of different sequences of alphabets that we can translate to. 
One approach is to consider the number of different sequences we can make, 
for each string ending with a[i]. 
```
```
Let dp[l][r] be the number of different sequences that a[l..r] can translate to.
this dp can be implemented in a very standard way. 
Now, after each append, we need to update our total sum. 
We will see another problem. For example, "10101", we see that the string "101" has appeared before, 
so we want to avoid counting "101" into our sum again.
```
```
This basically means: if a[l..i] has appeared before then we will stop consider a[l..i] , a[l+1..i] , ... , a[i..i]. 
So, we need a way to detect the maximal l we can get to for each i. This can be done by another dp. 
```
```
Let LCS[i][j] = the longest common suffix for a[1..i] and a[1..j]
LCS[i][j] = LCS[i - 1][j - 1] + 1 if a[i] == a[j]. 
```
[code](https://codeforces.com/contest/1129/submission/124406253)
- https://codeforces.com/contest/1555/problem/E
```
solution: Not hard to come up with a sweeping solution, but implementation needs to be careful
```
[code](https://codeforces.com/contest/1555/submission/124386624)
- https://codeforces.com/contest/623/problem/B
```
solution: we can erase at most one consecutive segment (has to be shorter than the whole array) and pay A for each unit.
We can +1 or -1 for each a[i], and need to pay B for each.
We need to find the min cost to make the whole array's gcd > 1 
```
```
Here we can make an observation: at least one of a[1] and a[N] will not be erased
This inspires us to iterate on {a[1] + 1 , a[1] , a[1] - 1 , a[N] + 1 , a[N] , a[N] - 1} , 6 in total. 
For the first 3 values, fix to be the value of a[1] and factorize it, for each prime divisor, check the minimal cost to make the whole array divisible by this prime. 
this can be done with a simple linear dp.
And similarly, for the last 3 values.
```
[code](https://codeforces.com/contest/623/submission/124211872)
- https://codeforces.com/contest/587/problem/B
solution: dp + careful case work
```
Nothing really special about this problem, just standard dp
```
[code](https://codeforces.com/contest/587/submission/124050121)
- https://codeforces.com/contest/431/problem/D
```
solution: standard digit dp
```
[code](https://codeforces.com/contest/431/submission/123989803)
- https://codeforces.com/contest/1546/problem/E
```
solution: extremely hard constructive problem
The goal is to find the number of ways to make NxN latin square
(TODO)
```
[code](https://codeforces.com/contest/1546/submission/123890305)
- https://codeforces.com/contest/628/problem/D
```
solution: digit dp
```
[code](https://codeforces.com/contest/628/submission/123791463)
- https://codeforces.com/contest/1188/problem/B
```
solution: make the formula: (ai - aj)(ai + aj)(ai^2 + aj^2) = k(ai - aj) (mod P), then easy
```
[code](https://codeforces.com/contest/1188/submission/123757746)
- https://codeforces.com/contest/1188/problem/D
```
Problem:
We are given a sequence of numbers, each time we can choose to add
some non-negative power of 2 to some number. The goal is to use the 
minimal number of operations to make all numbers equal.
```
```
First observation, since we can add only, if at the end, a[1]=...=a[N]=x
then x >= max{a[i]}. If we fix this x, the answer is just sum{Bit[x - a[i]]}
where Bit[x] is the number of 1s in the binary form of x.
Since the possible values of x can be large, we can not just iterate x. 
```
```
We can not binary search on x, as if x works, x + 1 might not make the answer smaller. (At least my intuition)
Instead, we can try to enumerate the possible values of x on each bit.
However, the minus is annoying to deal with, we try to turn it into a plus.
```
```
Assuming a[1]<=..<=a[N]
Notice Let t = (x - a[N]) , then x - a[i] = t + a[N] - a[i]
Let b[i] = a[N] - a[i]
we have x - a[i] = t + b[i] , the goal is to min{sum{t + b[i]}}
Now, we can enumerate bis on t
```
```
Consider the ith bit of t, assuming we have the answer for the first i-1 bits.
Let dp[i][0/1] = min{sum{t[i..0] + b[j][i..0] | j <= N}}, such that 
t[i] = 0/1. Consider the cases when we move from dp[i] to dp[i + 1]
dp[i + 1][0] = min{
    dp[i][0] + sum((b[j][i + 1] + carry[j][i][0]) % 2) , 
    dp[i][1] + sum((b[j][i + 1] + carry[j][i][1]) % 2)
} 
where carry[j][i][0] = the carry of b[j] on ith bit, if we reach dp[i][0]. 
carry[j][i][1] = the carry of b[j] on ith bit, if we reach dp[i][1]. 
the possible of states of carries can reach 2^N, which is 2^(1e5).
```
```
Optimization:
Carry is important, there is no way to get rid of it. 
Carry on each b[j] can vary and there is no way to get rid of it.
So the only way is to shrink the 2^N states into something managable.
We notice that, if (b[j][i..0] + t[i..0]) >= (b[k][i..0] + t[i..0]) 
and the carry on b[k] is 1, then b[j]'s carry must also be 1.
As the condition to have carry is (b[k][i..0] + t[i..0]) >= 2^(i+1)
so if sort b[j][i..0] (same as sort by b[j] mod (2^(i + 1)))
into ascending order then we can just enumerate on the number of carries 
we have from previous bits, and this is linear.
```
```
So we can define our dp state:
dp[i][j] = the minimal number of operations to make for the first
i bits, such that we have j carries.
We can transit this with some case works + prefix sums.
```
[code](https://codeforces.com/contest/1188/submission/123750641)
- https://codeforces.com/contest/1188/problem/C
```
value of array <a1..aN> = min{|ai - aj|} , i != j. 
We need to calculate the value of all subsequences of array a with length = K
Interesting dp problem. The idea is to relax the condition
the answer = 1 * #(value = 1) + 2 * #(value = 2) + ...
but to find the number of subsequences whose value = k is not easy
We can rewrite answer = #(value >= 1) + #(value >= 2) + ...
In a relax manner.
Then the problem can be solved by dp.
sort a into ascending order
Let dp[i][j] = the number of sequences ending at a[i] , length = j and value >= x.
dp[i][j] = sum{dp[k][j - 1] | a[i] - a[k] >= x}
This can be optimized to O(N * K) by using prefix-sum + 2-pointer
We also notice that the upperbound of the value is max{a[i]} / (K - 1)
total complexity is O(max{a[i]} / (K - 1) * N * K) = O(10^5 * N) ~ 1e8
```
[code](https://codeforces.com/contest/1188/submission/123579959)
- https://codeforces.com/contest/888/problem/F
```
solution: there are N points on a circular table, 
the goal is to find the number of different ways to
make them all connected. Constraints are: direct links do
not intersect, you can connect i and j only if a[i][j] = 1.
```
```
Consider what happen with pt[1]. Say we link 1 with some pt[i]
[1...i , i+1...N] Let f[l][r] be the total number of ways to connect
all pts from l to r. Let g[l][r] be the total number of ways to connect all
pts from l to r if l and r are linked directly.
we get the following recurences:
f[l][r] = sum{g[l][m] * f[m][r] | l < m <= r , a[l][m] == 1}
g[l][r] = sum{f[l][m] * f[m + 1][r] | l <= m < r}
answer is f[1][N]
base case: f[i][i] = 1 , g[i][i] = 1
```
[code](https://codeforces.com/contest/888/submission/123409300)
- https://codeforces.com/contest/888/problem/G
```
You are given an undirected graph with n vertices, each vertice has a value a[i],
weight of edge (i , j) is a[i] xor a[j]. We need to find the MST.
n <= 2e5 , a[i] < 2^30
```
```
One way to solve this is to use Boruvka algorithm
Kruskal algorithm's complexity is O(ElogE) = O(N^2 * log(N^2)) too slow
Boruvka algorithm's complexity is O(ElogV), for each logV iteration,
we can speed up the process. Instead iterating all edges, for each vertex u in 
a component, we find the vertex v in other components, such that a[u] xor a[v] is minimised. This can be done with a trie, thus making the process at most 30 for each vertex. Time complexity is O(30*V*logV) However the constant is large, so my implementation failed to pass the tests.
```
[code](https://codeforces.com/contest/888/submission/123232074)
```
Another way is to use divide and conquer. We start from the the highest bit and we group vertices by weather they have this bit in their values.
And then we recursively solve for these 2 groups.
At the end, we use link these 2 groups by the cheapest edge.
The whole process can be done with trie.
```
[code](https://codeforces.com/contest/888/submission/123235034)
- https://codeforces.com/contest/1495/problem/D
```

```
- https://codeforces.com/contest/1550/problem/D
```
solution: hard counting TODO
```
- https://codeforces.com/contest/1550/problem/F
```
solution: Bor??vka's algorithm TODO
```
- https://codeforces.com/contest/1550/problem/E
```
solution: greedy observation + bit mask dp TODO
```
- https://codeforces.com/contest/1543/problem/E
```
solution: hard constructive  TODO
```
- https://codeforces.com/contest/1546/problem/D
```
solution: counting TODO
```

