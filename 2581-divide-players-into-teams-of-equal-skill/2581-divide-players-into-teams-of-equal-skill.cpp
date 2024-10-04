class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
    
    sort(skill.begin(), skill.end());
    
    
    int total_skill = skill[0] + skill[skill.size() - 1];
    
    long long chemistry_sum = 0;
    int n = skill.size();
    
    
    for (int i = 0; i < n / 2; ++i) {
        
        if (skill[i] + skill[n - 1 - i] != total_skill) {
            return -1;
        }
        
        chemistry_sum += (long long)skill[i] * skill[n - 1 - i];
    }
    
    return chemistry_sum; 
    }
};