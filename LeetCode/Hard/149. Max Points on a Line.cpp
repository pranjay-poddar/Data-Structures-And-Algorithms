class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        vector <pair<int,int>> v;
        int n = points.size();
        for(int i=0;i<n;i++){
            v.push_back({points[i][0],points[i][1]});
        }
        sort(v.begin(),v.end());
        map <pair<int,int>,int> mp[n];
        int ans = 0;
        for(int i=0;i<n;i++){
            mp[i][{0,0}] = 1;
            ans = max(ans,1);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int xd = v[i].first - v[j].first;
                int yd = v[i].second - v[j].second;
                int g = __gcd(xd,yd);
                xd/=g;yd/=g;
                if(mp[j][{xd,yd}]==0) mp[i][{xd,yd}] = max(2,mp[i][{xd,yd}]);
                else mp[i][{xd,yd}] = max(mp[i][{xd,yd}],mp[j][{xd,yd}] +1);
                ans = max(ans,mp[i][{xd,yd}]);
                
            }
        }
     
        return ans;
        
    }
};
