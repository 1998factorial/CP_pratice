# CP_pratice
# Here I do CP for fun
# With focus on Codeforces

# Solutions to some problems that I have solved

- https://codeforces.com/contest/86/problem/D
solution: Here we use MO's algorithm. (answer for [l , r] -> [l -+ 1, r -+ 1]can be maintained in O(1))

- https://codeforces.com/contest/258/problem/D 
solution: 
we need to process each query in order (order matters in this problem). Each query has 1/2 chance of run or not run. And we need to count the
expected number of inversion pairs after these M queries. There are many ways to calculate the expected number of inversions. eg, sum{e[i]} , where e[i] = expected
number of a[j] > a[i] where j < i. This approach could not work, as if we swap a[l] and a[r] many times, it is hard to maintain each e[i]. 
expected number of inversions could also be counted as : sum { Prob(a[i] > a[j]) * [i < j]}, and we use a new state: f[i][j] = Prob(a[i] > a[j])
for each query, it is not hard to observe the following transition: f[l][i] = f[r][i] = (f[l][i] + f[r][i]) / 2 , f[i][l] = f[i][r] = (f[i][l] + f[i][r]) / 2
f[l][r] = f[r][l] = 1/2. This approach allows us to maintain the information for each pair of (a[i] , a[j]).

- https://codeforces.com/contest/86/problem/C
solution: dp on AC automaton TODO

- https://codeforces.com/contest/83/problem/D
solution: let us think of a navie solution, let f(n , k) = the number of x <= n whose smallest non-one divisor = k. f(n , k) = n / k - sum{f(n / k , j) | 1 < j < k}. since n and k are 2e9 , this might be too slow. However, one can see that if k is not a prime then f(n , k) = 0. eg f(n , 4) = 0 as 4 | x => 2 | x. 
if k * k > n then f(n , k) = 1 (only x is k , no other number works). therefore, the amount of k is at most sqrt(n). also, for each recursive step, 
n shrinks by at least 2, so the height of the recursion tree is at most log(n , 2). The complexity is thus bounded by O(sqrt(n) * log(n , 2)) ~ 1381772

- https://codeforces.com/contest/337/problem/E
solution: there are only n<=8 nodes, we can brute force all these cases. 

- https://codeforces.com/contest/1073/problem/E
solution: f[i][mask][p][q][t] = the sum of all the prefixes of length i and used mask (set) of digits, p => if prefix is bounded by L , q => if prefix is bounded by R , t => if we have leading zeros. dp[i][mask][p][q][t] = number of ways to have prefix of length i ,(mask , p , q , t same meaning as before). and we can use dp table to update f table.

- https://codeforces.com/contest/744/problem/C
solution: A very smart way of dp. To buy a card the cost for red token is max(0 , r[i] - R) , for blue token max(0 , b[i] - B). Consider a simplier version, 
if cost for red = r[i] and cost for blue = b[i], what is the minimal day needed to buy all cards? The answer is max(sum{r[i]} , sum{b[i]}). Also, for those r[i] or b[i] >= N, their cost will always be r[i] - R or b[i] - B. So we mainly focus on those r[i] , b[i] < N. Now, we can dp. let dp[mask][i] be the maximal amount of blue token that we can save when we have bought mask (set) of cards, and saved i red tokens in total. (note that i < N^2)

- https://codeforces.com/contest/840/problem/C
we want to re-arrange the array, so that no adjcent pair a[i] * a[i + 1] is a perfect square. if a * b and b * c is perfect square, then a * c is also a perfect square. eg, 2 * 8 and 8 * 18. why? if a * b is perfect square, then for each p^x | a, and p^y | b, (x + y) % 2 = 0. so x and y have same parity. this relation is transitive, so for each p^x | a , p^y | b , p^z | c , (x + y) = (y + z) = (x + z) % 2. We can therefore group all pairwise perfect square. (Same as give them colour)
Now, our problem is the same as: given K different groups of elements, each have cnt[i] elements, we want to find the number of ways to arrange these elements into a row, such that no adjcent elements are from the same group. Let's try to solve this, group by group. Let dp[i][j] = the number of ways to arrange elements from first i groups, such that we have exactly j bad pairs (bad pair means adjcent pair are from same group) Consider the i+1 th group. First, we need to consider how many consecutive blocks that we are going to divide these cnt[i+1] elements into.
Say we divide them into x blocks, in how many ways can we do this? let f[n][k] = the number of ways to divide n elements into k non-empty groups, group-wise order doesn't matter, but element wise ordering matters. 
```
f[n][k] = f[n - 1][k - 1] + f[n - 1][k] * (n - 1 + k). (think each element as white balls , group can be black balls, put between white balls as barrier , the number of ways to not create another group while inserting nth element is (n - 1 + k) * f[n - 1][k])
```
Now, we are at dp[i][j] and we divide cnt[i+1] elements into x blocks, with f[cnt[i+1]][x] ways, we then consider how many "original bad pairs" we will destroy. Say y of them. we are puting y blocks from x blocks into these y bad pair positions.
And the rest of x - y blocks will be put in good positions. let sum{cnt[k] , k <= i} = prefix. we have 
```
dp[i + 1][j - y + cnt[i + 1] - x] += dp[i][j] * f[cnt[i + 1]][x] * C(x , y) * C(j , y) * C(prefix + 1 - j , x - y) * (x - y)! * y!
```
- note: we destroy y bad pairs, but creates cnt[i + 1] - x new bad pairs.
1. we have C(x , y) ways to select y bad blocks from a total of x blocks.
2. we have C(j , y) ways to select y bad positions from a total of j bad positions.
3. we have C(prefix + 1 - j , x - y) ways to select x - y positions from a total of prefix + 1 - j good positions.
4. we have y! ways to re-arrange y bad blocks (as f[cnt[i]][x] does not consider group-wise ordering).
5. we have (x - y)! ways to re-arrange x - y good blocks.
- our answer is just dp[K][0]
```
complexity is O(#groups * prefix * cnt[i] * cnt[i])
for i = 1 .. |groups|:
    for j = 0 .. cnt[1]+..+cnt[i]:
        for x = 1 .. cnt[i+1]:
            for y = 1 .. min(j,x):
```
note that the third for-loop only runs a total of N times
we can safely say that the solution is O(N^3)

- https://codeforces.com/contest/317/problem/D
solution: Alice and Bob plays a game, each erase x , x^2 , x^3... x^k <= N
the one who can not make any move lose. Determine who can win if both play optimally. N is 1e9 , it is impossible to put every 1...N into a set and simulate the game, also, even if N is very small, simulating all possibilities is impossible. But if the set given looks like {x , x^2 , x^3 , x^4 , x^5}
and if Alice erase x^2 then the set will be {x , x^3 , x^5}. This process can be simulate by bitmask. With this, we try the following construction. 
Iterate x from 2 to sqrt(N), build set {x , x^2 , x^3 , ... , x^k}. Now, we are going to have sqrt(N) sets, where each set's size is at most 29. when Alice / Bob
pick some x, this x will only appear in exactly one set from all these sqrt(N) sets. (let y be the minimal y st y | x , x must be from the set starts with y, and this minimal value must be distinct by our construction)
Now, we have one important observation: we do not care about what values are in each set, we only care about their sizes now.
Our game has been broken into sqrt(N) independent sub-games. (and many other games whose size is 1)
Handeling subgames require SG number. we can precompute the SG number for each sizes from 2 ~ 29, using bitmask. At last, our answer is just the XOR sum of all these SG numbers. (Also need to check the number of subgames whose size = 1)

- https://codeforces.com/contest/1555/problem/F
solution: There are a set of edges to add in, each with weight 0 or 1. We can add edge only when all simple cycles have weight 1 (weight is calculated by xor)
For each edge, if we add it, we say YES and add it into the graph, else, we say NO and don't add it. We can see that, no edge can be used in 2 different cycles. (Draw it and it is obvious) So we can first label edges as "cycle edge" or "tree edge". For each Tree edge, when we process them, we just add them and say YES.
For cycle edge, (u , v) we need to check if edges from u to v are included in any cycle before.(this can be done using Euler tour + fenwick tree) Then we need to have fast query for xor values from u to v, this can be done simply by tree dp.
The hard part is the implementation: https://codeforces.com/contest/1555/submission/124841091

- https://codeforces.com/contest/313/problem/D
solution: dp 

- https://codeforces.com/contest/427/problem/D
solution: dp 

- https://codeforces.com/contest/1129/problem/C
solution: Each time, we will append 0 or 1 to the end of our string. Except "0011", "0101", "1110", and "1111", all other length <= 4 0/1 string can be translated to some distinct alphabet. Our goal is to, after each append operation, we need to calculate the number of different sequences of alphabets that we can translate to. One approach is to consider the number of different sequences we can make, for each string ending with a[i].

- https://codeforces.com/contest/1555/problem/E
solution: Not hard to come up with a sweeping solution, but implementation needs to be careful

- https://codeforces.com/contest/623/problem/B
solution: smart dp 

- https://codeforces.com/contest/587/problem/B
solution: dp + careful case work

- https://codeforces.com/contest/431/problem/D
solution: digit dp

- https://codeforces.com/contest/1546/problem/E
solution: extremely hard constructive problem

- https://codeforces.com/contest/628/problem/D
solution: digit dp

- https://codeforces.com/contest/1188/problem/B
solution: make the formula: (ai - aj)(ai + aj)(ai^2 + aj^2) = k(ai - aj) (mod P), then easy

- https://codeforces.com/contest/1188/problem/D
solution: hard dp , TODO

- https://codeforces.com/contest/1188/problem/C
solution: counting + dp TODO

- https://codeforces.com/contest/888/problem/F
solution: counting + dp TODO

- https://codeforces.com/contest/888/problem/G
solution: TODO

- https://codeforces.com/contest/1495/problem/D
solution: counting , observation TODO

- https://codeforces.com/contest/1550/problem/D
solution: hard counting TODO

- https://codeforces.com/contest/1550/problem/F
solution: Borůvka's algorithm TODO

- https://codeforces.com/contest/1550/problem/E
solution: greedy observation + bit mask dp TODO

- https://codeforces.com/contest/1543/problem/E
solution: hard constructive  TODO

- https://codeforces.com/contest/1546/problem/D
solution: counting TODO


