// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Nov 2021
//  @Detail  :        Gridland Metro (HackerRank)
//  ============================
//  -->

bool myComp(vector<int> &a, vector<int> &b)
{
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

long long gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    if(!k)
        return n * m;
    sort(track.begin(), track.end(), myComp);
    vector<vector<int>> result{track[0]};
    for(int i = 1; i < track.size(); i++)
    {
        if(track[i][0] != result.back()[0])
            result.push_back(track[i]);
        while(i < track.size() && track[i][0] == result.back()[0])
        {
            if(result.back()[2] < track[i][1])
                result.push_back(track[i]);
            else if(result.back()[2] < track[i][2])
                result.back()[2] = track[i][2];
            i++;
        }
        i--;
    }
    long long cnt = 1ll * n * m;
    for(auto &z : result)
        cnt -= (z[2] - z[1] + 1);
    return cnt;
}
