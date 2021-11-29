// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Nov 2021
//  @Detail  :        Queue Reconstruction by Height (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    static bool customComp(vector<int> &x, vector<int> &y)
    {
        if(x[0] == y[0])
            return x[1] < y[1];
        return x[0] > y[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(), people.end(), customComp);
        for(vector<int> &x : people)
            result.insert(result.begin() + x[1], x);
        return result;
    }
};
