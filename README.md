# CP_pratice
# Here I do CP for fun
# With focus on Codeforces

# Solutions to some problems that I have solved

https://codeforces.com/contest/86/problem/D
solution: Here we use MO's algorithm. (answer for [l , r] -> [l -+ 1, r -+ 1]can be maintained in O(1))

https://codeforces.com/contest/258/problem/D
solution: we need to process each query in order (order matters in this problem). Each query has 1/2 chance of run or not run. And we need to count the
expected number of inversion pairs after these M queries. There are many ways to calculate the expected number of inversions. eg, sum{e[i]} , where e[i] = expected
number of a[j] > a[i] where j < i. This approach could not work, as if we swap a[l] and a[r] many times, it is hard to maintain each e[i]. 
expected number of inversions could also be counted as : sum { Prob(a[i] > a[j]) * [i < j]}, and we use a new state: f[i][j] = Prob(a[i] > a[j])
for each query, it is not hard to observe the following transition: f[l][i] = f[r][i] = (f[l][i] + f[r][i]) / 2 , f[i][l] = f[i][r] = (f[i][l] + f[i][r]) / 2
f[l][r] = f[r][l] = 1/2. This approach allows us to maintain the information for each pair of (a[i] , a[j]).

https://codeforces.com/contest/86/problem/C
solution: dp on AC automaton TODO

https://codeforces.com/contest/83/problem/D
solution: let us think of a navie solution, let f(n , k) = the number of x <= n whose smallest non-one divisor = k. f(n , k) = n / k - sum{f(n / k , j) | 1 < j < k}. since n and k are 2e9 , this might be too slow. However, one can see that if k is not a prime then f(n , k) = 0. eg f(n , 4) = 0 as 4 | x => 2 | x. 
if k * k > n then f(n , k) = 1 (only x is k , no other number works). therefore, the amount of k is at most sqrt(n). also, for each recursive step, 
n shrinks by at least 2, so the height of the recursion tree is at most log(n , 2). The complexity is thus bounded by O(sqrt(n) * log(n , 2)) ~ 1381772

https://codeforces.com/contest/337/problem/E
solution: there are only n<=8 nodes, we can brute force all these cases. 

https://codeforces.com/contest/1073/problem/E
solution: f[i][mask][p][q][t] = the sum of all the prefixes of length i and used mask (set) of digits, p => if prefix is bounded by L , q => if prefix is bounded by R , t => if we have leading zeros. dp[i][mask][p][q][t] = number of ways to have prefix of length i ,(mask , p , q , t same meaning as before). and we can use dp table to update f table.

https://codeforces.com/contest/744/problem/C
solution: A very smart way of dp. To buy a card the cost for red token is max(0 , r[i] - R) , for blue token max(0 , b[i] - B). Consider a simplier version, 
if cost for red = r[i] and cost for blue = b[i], what is the minimal day needed to buy all cards? The answer is max(sum{r[i]} , sum{b[i]}). Also, for those r[i] or b[i] >= N, their cost will always be r[i] - R or b[i] - B. So we mainly focus on those r[i] , b[i] < N. Now, we can dp. let dp[mask][i] be the maximal amount of blue token that we can save when we have bought mask (set) of cards, and saved i red tokens in total. (note that i < N^2)

https://codeforces.com/contest/840/problem/C
solution: combinatoric dp

https://codeforces.com/contest/317/problem/D
solution: game , SG number , precomputation

https://codeforces.com/contest/1555/problem/F
solution: XOR , inference  TODO

https://codeforces.com/contest/313/problem/D
solution: dp

https://codeforces.com/contest/427/problem/D
solution: dp

https://codeforces.com/contest/1129/problem/C
solution: dp , suffix structure TODO

https://codeforces.com/contest/1555/problem/E
solution: Not hard to come up with a sweeping solution, but implementation needs to be careful

https://codeforces.com/contest/623/problem/B
solution: smart dp 

https://codeforces.com/contest/587/problem/B
solution: dp + careful case work

https://codeforces.com/contest/431/problem/D
solution: digit dp

https://codeforces.com/contest/1546/problem/E
solution: extremely hard constructive problem

https://codeforces.com/contest/628/problem/D
solution: digit dp

https://codeforces.com/contest/1188/problem/B
solution: make the formula: (ai - aj)(ai + aj)(ai^2 + aj^2) = k(ai - aj) (mod P), then easy

https://codeforces.com/contest/1188/problem/D
solution: hard dp , TODO

https://codeforces.com/contest/1188/problem/C
solution: counting + dp TODO

https://codeforces.com/contest/888/problem/F
solution: counting + dp TODO

https://codeforces.com/contest/888/problem/G
solution: TODO

https://codeforces.com/contest/1495/problem/D
solution: counting , observation TODO

https://codeforces.com/contest/1550/problem/D
solution: hard counting TODO

https://codeforces.com/contest/1550/problem/F
solution: Borůvka's algorithm TODO

https://codeforces.com/contest/1550/problem/E
solution: greedy observation + bit mask dp TODO

https://codeforces.com/contest/1543/problem/E
solution: hard constructive  TODO

https://codeforces.com/contest/1546/problem/D
solution: counting TODO


