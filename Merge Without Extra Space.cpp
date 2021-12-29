// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        29 Dec 2021
//  @Detail  :        Merge Without Extra Space (GeeksforGeeks)
//  ============================
//  -->

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i = 0, j = 0;
            while(i + j < n && j < m)
                if(arr1[i] <= arr2[j])
                    i++;
                else
                    j++;
            j--;
            i = n - 1;
            while(j >= 0)
                swap(arr1[i--], arr2[j--]);
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        } 
};
