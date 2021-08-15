# CP_pratice
# Here I do CP for fun
# With focus on Codeforces
# Solutions to some problems that I have solved

- https://codeforces.com/contest/86/problem/D
```
solution: Here we use MO's algorithm. (answer for [l , r] -> [l -+ 1, r -+ 1]can be maintained in O(1))
```
[code](https://codeforces.com/contest/86/submission/125625397)
- https://codeforces.com/contest/258/problem/D 
```
solution: 
we need to process each query in order (order matters in this problem). Each query has 1/2 chance of run or not run. And we need to count the
expected number of inversion pairs after these M queries. There are many ways to calculate the expected number of inversions. eg, sum{e[i]} , where e[i] = expected
number of a[j] > a[i] where j < i. This approach could not work, as if we swap a[l] and a[r] many times, it is hard to maintain each e[i]. 
expected number of inversions could also be counted as : sum { Prob(a[i] > a[j]) * [i < j]}, and we use a new state: f[i][j] = Prob(a[i] > a[j])
for each query, it is not hard to observe the following transition: f[l][i] = f[r][i] = (f[l][i] + f[r][i]) / 2 , f[i][l] = f[i][r] = (f[i][l] + f[i][r]) / 2
f[l][r] = f[r][l] = 1/2. This approach allows us to maintain the information for each pair of (a[i] , a[j]).
```
[code](https://codeforces.com/contest/258/submission/125593954)
- https://codeforces.com/contest/86/problem/C
```
solution: We are given at most 10 patterns, each has length at most 10
We need to find the number of DNA sequence of length N <= 1000, such that, for each
1 <= i <= N, exists 1 <= l <= i <= r <= N , such that s[l..r] = some given pattern.
This means, each character must be included in a matched pattern in the constructed string.
```
```
This implies that while we are building the string, we need keep track of the suffix and prefix at the same time. what is this? This has a smell of KMP (longest proper suffix) However, we have more than one patterns. It might be AC-automaton then! (The idea of AC-automaton is like KMP on trie, we don't have pi function here, we have the "fail" link instead) 
```
```
Now, we can put all patterns into out AC-automaton and count while we traverse on trie. Let dp[i][j] be the number of good strings that we can make, whose length is i and we are currently standing at node j of the AC-automaton
```
```
However, this construction will have problem, that is, while we transit, we want our current suffix of the constructing string to match with at least one pattern, this means we can not move on to other nodes using fail link without specifing "ok, I have done with this particular pattern, now I am moving on". Also, patterns are allowed to overlap.("AC" , "CB" , string "ACB" works.) In another word, dealing with "is this transition valid" is hard with this state.
```
```
The approach that solves this issue is: let dp[i][j][k] be the number of good strings whose length is i , and we are standing at node j , the last k characters in the string that we are constructing is not matched with any pattern yet.
```
```
We just need to store, for each the trie node, the longest pattern that using this node can match to.
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
solution: let us think of a navie solution, let f(n , k) = the number of x <= n whose smallest non-one divisor = k. f(n , k) = n / k - sum{f(n / k , j) | 1 < j < k}. since n and k are 2e9 , this might be too slow. However, one can see that if k is not a prime then f(n , k) = 0. eg f(n , 4) = 0 as 4 | x => 2 | x. 
if k * k > n then f(n , k) = 1 (only x is k , no other number works). therefore, the amount of k is at most sqrt(n). also, for each recursive step, 
n shrinks by at least 2, so the height of the recursion tree is at most log(n , 2). The complexity is thus bounded by O(sqrt(n) * log(n , 2)) ~ 1381772
```
[code](https://codeforces.com/contest/83/problem/D)
- https://codeforces.com/contest/337/problem/E
```
solution: there are only n<=8 nodes, we can brute force all these cases. 
```
[code](https://codeforces.com/contest/337/submission/125267709)
- https://codeforces.com/contest/1073/problem/E
```
solution: f[i][mask][p][q][t] = the sum of all the prefixes of length i and used mask (set) of digits, p => if prefix is bounded by L , q => if prefix is bounded by R , t => if we have leading zeros. dp[i][mask][p][q][t] = number of ways to have prefix of length i ,(mask , p , q , t same meaning as before). and we can use dp table to update f table.
```
[code](https://codeforces.com/contest/1073/submission/125196173)
- https://codeforces.com/contest/744/problem/C
```
solution: A very smart way of dp. To buy a card the cost for red token is max(0 , r[i] - R) , for blue token max(0 , b[i] - B). Consider a simplier version, 
if cost for red = r[i] and cost for blue = b[i], what is the minimal day needed to buy all cards? The answer is max(sum{r[i]} , sum{b[i]}). Also, for those r[i] or b[i] >= N, their cost will always be r[i] - R or b[i] - B. So we mainly focus on those r[i] , b[i] < N. Now, we can dp. let dp[mask][i] be the maximal amount of blue token that we can save when we have bought mask (set) of cards, and saved i red tokens in total. (note that i < N^2)
```
[code](https://codeforces.com/contest/744/submission/125157617)
- https://codeforces.com/contest/840/problem/C
```
we want to re-arrange the array, so that no adjcent pair a[i] * a[i + 1] is a perfect square. if a * b and b * c is perfect square, then a * c is also a perfect square. eg, 2 * 8 and 8 * 18. why? if a * b is perfect square, then for each p^x | a, and p^y | b, (x + y) % 2 = 0. so x and y have same parity. this relation is transitive, so for each p^x | a , p^y | b , p^z | c , (x + y) = (y + z) = (x + z) % 2. We can therefore group all pairwise perfect square. (Same as give them colour)
Now, our problem is the same as: given K different groups of elements, each have cnt[i] elements, we want to find the number of ways to arrange these elements into a row, such that no adjcent elements are from the same group. Let's try to solve this, group by group. Let dp[i][j] = the number of ways to arrange elements from first i groups, such that we have exactly j bad pairs (bad pair means adjcent pair are from same group) Consider the i+1 th group. First, we need to consider how many consecutive blocks that we are going to divide these cnt[i+1] elements into.
Say we divide them into x blocks, in how many ways can we do this? let f[n][k] = the number of ways to divide n elements into k non-empty groups, group-wise order doesn't matter, but element wise ordering matters. 
```
```
f[n][k] = f[n - 1][k - 1] + f[n - 1][k] * (n - 1 + k). (think each element as white balls , group can be black balls, put between white balls as barrier , the number of ways to not create another group while inserting nth element is (n - 1 + k) * f[n - 1][k])
```
```
Now, we are at dp[i][j] and we divide cnt[i+1] elements into x blocks, with f[cnt[i+1]][x] ways, we then consider how many "original bad pairs" we will destroy. Say y of them. we are puting y blocks from x blocks into these y bad pair positions.
And the rest of x - y blocks will be put in good positions. let sum{cnt[k] , k <= i} = prefix. we have 
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
the one who can not make any move lose. Determine who can win if both play optimally. N is 1e9 , it is impossible to put every 1...N into a set and simulate the game, also, even if N is very small, simulating all possibilities is impossible. But if the set given looks like {x , x^2 , x^3 , x^4 , x^5}
and if Alice erase x^2 then the set will be {x , x^3 , x^5}. This process can be simulate by bitmask. With this, we try the following construction. 
Iterate x from 2 to sqrt(N), build set {x , x^2 , x^3 , ... , x^k}. Now, we are going to have sqrt(N) sets, where each set's size is at most 29. when Alice / Bob
pick some x, this x will only appear in exactly one set from all these sqrt(N) sets. (let y be the minimal y st y | x , x must be from the set starts with y, and this minimal value must be distinct by our construction)
Now, we have one important observation: we do not care about what values are in each set, we only care about their sizes now.
Our game has been broken into sqrt(N) independent sub-games. (and many other games whose size is 1)
Handeling subgames require SG number. we can precompute the SG number for each sizes from 2 ~ 29, using bitmask. At last, our answer is just the XOR sum of all these SG numbers. (Also need to check the number of subgames whose size = 1)
```
[code](https://codeforces.com/contest/317/submission/124941147)
- https://codeforces.com/contest/1555/problem/F
```
solution: There are a set of edges to add in, each with weight 0 or 1. We can add edge only when all simple cycles have weight 1 (weight is calculated by xor)
For each edge, if we add it, we say YES and add it into the graph, else, we say NO and don't add it. We can see that, no edge can be used in 2 different cycles. (Draw it and it is obvious) So we can first label edges as "cycle edge" or "tree edge". For each Tree edge, when we process them, we just add them and say YES.
For cycle edge, (u , v) we need to check if edges from u to v are included in any cycle before.(this can be done using Euler tour + fenwick tree) Then we need to have fast query for xor values from u to v, this can be done simply by tree dp.
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
solution: Each time, we will append 0 or 1 to the end of our string. Except "0011", "0101", "1110", and "1111", all other length <= 4 0/1 string can be translated to some distinct alphabet. Our goal is to, after each append operation, we need to calculate the number of different sequences of alphabets that we can translate to. One approach is to consider the number of different sequences we can make, for each string ending with a[i]. 
```
```
Let dp[l][r] be the number of different sequences that a[l..r] can translate to.
this dp can be implemented in a very standard way. Now, after each append, we need to update our total sum. We will see another problem. For example, "10101", we see that the string "101" has appeared before, so we want to avoid counting "101" into our sum again.
```
```
This basically means: if a[l..i] has appeared before then we will stop consider a[l..i] , a[l+1..i] , ... , a[i..i]. So, we need a way to detect the maximal l we can get to for each i. This can be done by another dp. 
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
This inspires us to iterate on {a[1] + 1 , a[1] , a[1] - 1 , a[N] + 1 , a[N] , a[N] - 1} , 6 in total. For the first 3 values, fix to be the value of a[1] and factorize it, for each prime divisor, check the minimal cost to make the whole array divisible by this prime. this can be done with a simple linear dp.
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
solution: very hard dp , (TODO)
```
[code](https://codeforces.com/contest/1188/submission/123750641)
- https://codeforces.com/contest/1188/problem/C
```
value of array <a1..aN> = min{|ai - aj|} , i != j
Interesting dp problem. The idea is to relax the condition

```
[code](https://codeforces.com/contest/1188/submission/123579959)
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


