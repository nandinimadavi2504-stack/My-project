class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // store: position, health, direction, original index
        vector<tuple<int,int,char,int>> robots;
        
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // sort by position
        sort(robots.begin(), robots.end());
        
        stack<int> st; // stores indices in robots vector
        
        for(int i = 0; i < n; i++) {
            auto &[pos, health, dir, idx] = robots[i];
            
            if(dir == 'R') {
                st.push(i);
            } else {
                // dir == 'L'
                while(!st.empty() && health > 0) {
                    int j = st.top();
                    auto &[pos2, health2, dir2, idx2] = robots[j];
                    
                    if(health2 < health) {
                        // stack robot dies
                        st.pop();
                        health--;
                        health2 = 0;
                    }
                    else if(health2 == health) {
                        // both die
                        st.pop();
                        health = 0;
                        health2 = 0;
                        break;
                    }
                    else {
                        // current robot dies
                        health2--;
                        health = 0;
                        break;
                    }
                }
            }
        }
        
        // collect survivors
        vector<pair<int,int>> survivors; // {original index, health}
        
        for(auto &r : robots) {
            int pos, health, idx;
            char dir;
            tie(pos, health, dir, idx) = r;
            
            if(health > 0) {
                survivors.push_back({idx, health});
            }
        }
        
        // sort by original index
        sort(survivors.begin(), survivors.end());
        
        vector<int> result;
        for(auto &p : survivors) {
            result.push_back(p.second);
        }
        
        return result;
    }
};