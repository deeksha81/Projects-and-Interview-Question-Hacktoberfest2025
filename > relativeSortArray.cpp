class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a1, vector<int>& a2) {
        int m = a1.size(), n = a2.size();
        unordered_map<int,int>freq;
        
        
        for(int i =0; i<m ;i++){
            
            freq[a1[i]]++;
        }
        
        int index = 0;
        
        for(int i =0 ; i<n ; i++){
            while(freq[a2[i]]--){
                a1[index++] = a2[i];
                
            }
            
            freq.erase(a2[i]);
        }
        
        vector<int>remaining;
        for(auto &pair: freq){
            while(pair.second--){
                remaining.push_back(pair.first);
            }
            
        }
        
        sort(remaining.begin(), remaining.end());
        for(int i : remaining){
            a1[index++] = i;
            
        }
        return a1;
        
    }
};


        
    
