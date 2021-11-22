// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Nov 2021
//  @Detail  :        Top K Frequent Elements (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    void quickSelect(int start, int end, int idx, vector<int> &arr, unordered_map<int, int> &cache)
    {
        while(start <= end)
        {
            int left = start + 1, right = end;
            int pivot = start + rand() % (end - start + 1);
            swap(arr[start], arr[pivot]);
            pivot = start;
            while(left <= right)
            {
                if(cache[arr[left]] > cache[arr[pivot]] && cache[arr[right]] < cache[arr[pivot]])
                    swap(arr[left], arr[right]);
                if(cache[arr[left]] <= cache[arr[pivot]])
                    left++;
                if(cache[arr[right]] >= cache[arr[pivot]])
                    right--;
            }
            swap(arr[pivot], arr[right]);
            if(right == idx)
                return;
            if(right < idx)
                start = right + 1;
            else
                end = right - 1;
        }
    }
    
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int, int> cache;
        for(int &x : arr)
            cache[x]++;
        
        vector<int> unique;
        for(auto &x : cache)
            unique.push_back(x.first);
        quickSelect(0, unique.size() - 1, unique.size() - k, unique, cache);
        vector<int> result;
        for(int i = unique.size() - k; i < unique.size(); i++)
            result.push_back(unique[i]);
        return result;
    }
};
