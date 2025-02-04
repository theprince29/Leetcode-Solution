class Solution {
         
public:

    void backtrack(int ind,string&curr,vector<string>&res,string&digits,vector<string>&phone)
    {
        if(ind == digits.size())
        {
            res.push_back(curr);
            return;
        }
        string temp = phone[digits[ind] - '0'];
        for(auto x:temp)
        {
            curr.push_back(x);
            backtrack(ind+1,curr,res,digits,phone);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> phone = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string curr;
        vector<string>res;
        backtrack(0,curr,res,digits,phone);
        return res;
    }
};