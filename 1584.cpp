//Problem: 1584
//Platform: Leetcode(https://leetcode.com/problems/min-cost-to-connect-all-points/description/)
//Topic: MST
//Description:Tried the dense graph version of Prims from https://cp-algorithms.com/graph/mst_prim.html

#include<bits/stdc++.h>
using namespace std;


const int INF = 100000000;
struct edge{
    int w=INF,to=-1;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<edge>min_e(n);
        vector<int>selected(n,0);
        int min_cost=0;
        min_e[0].w=0;
        min_e[0].to=-1;
        for(int i=0;i<n;i++){
            int v=-1;
            for(int j=0;j<n;j++){
                if(!selected[j] && (v==-1 || min_e[j].w<min_e[v].w)){
                    v=j;
                }
            }
            if(v==-1)break;
            selected[v]=1;
            min_cost+= min_e[v].w;

            for(int to=0;to<n;to++){
                if(!selected[to] && min_e[to].w>(abs(points[to][0]-points[v][0])+abs(points[to][1]-points[v][1]))){
                    min_e[to].w = abs(points[to][0]-points[v][0])+abs(points[to][1]-points[v][1]);
                    min_e[to].to= v;
                }
            }
        }
        return min_cost;
    }
};

int main(){
    vector<vector<int>> points={{0,0},{2,2},{3,10},{5,2},{7,0}};
    Solution obj;
    cout<<obj.minCostConnectPoints(points)<<endl;

}