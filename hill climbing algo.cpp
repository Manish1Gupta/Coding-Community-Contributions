class Solution {
public:
#define f first
#define s second

vector<int> v{0, 0};
double ans = 0;

double dist(int x1, int y1, int x2, int y2){
    return(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2)));
}

vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    queue<pair<int, int>> q;
    
    for(int i=0;i<towers.size();i++){
        q.push({towers[i][0], towers[i][1]});
    }
    
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        
        double temp = 0;
        
        for(int i=0;i<towers.size();i++){
		
			//skip the tower if it is not reachable from the point
            if(dist(towers[i][0], towers[i][1], p.f, p.s) > radius)
                continue;
            
            temp += floor(towers[i][2]/(1 + dist(towers[i][0], towers[i][1], p.f, p.s)));
        }
        
        if(temp > ans){
            ans = temp;
            v = {p.f, p.s};
            
			//explore the neighbourhood
            q.push({p.f - 1, p.s - 1});
            q.push({p.f+1, p.f +1});
            q.push({p.f - 1, p.s + 1});
            q.push({p.f+1, p.f -1});
            q.push({p.f, p.s - 1});
            q.push({p.f, p.f +1});
            q.push({p.f - 1, p.s});
            q.push({p.f+1, p.f});
        }
        else if(temp == ans){
            if(v[0] > p.f || (v[0] == p.f and v[1] > p.s))
                v = {p.f, p.s};
        }
        else
            continue;
    }
    
    return v;
}
};
