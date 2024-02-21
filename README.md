# Problem of the Day  21/02/2024
### My [Solution](https://github.com/theprince29/leetcodeSolution/blob/main/0201-bitwise-and-of-numbers-range/0201-bitwise-and-of-numbers-range.cpp)

<h2><a href="https://leetcode.com/problems/bitwise-and-of-numbers-range/">201. Bitwise AND of Numbers Range</a></h2><h3>Medium</h3><hr><div><p>Given two integers <code>left</code> and <code>right</code> that represent the range <code>[left, right]</code>, return <em>the bitwise AND of all numbers in this range, inclusive</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> left = 5, right = 7
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> left = 0, right = 0
<strong>Output:</strong> 0
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> left = 1, right = 2147483647
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= left &lt;= right &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>


```
class Solution {
public:
    
    int rangeBitwiseAnd(int left, int right) {
        int shift =0;
        
        while(left<right)
        {
            left >>= 1;
            right >>=1;
            shift++;
        }
        
        return left <<shift;
    }
};
```
