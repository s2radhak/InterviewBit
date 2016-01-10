vector<int> Solution::flip(string A) {
    int low = 0, hi = 0, ct = 0, max = 0, j = 0, templow = 0;
    
    for(int i = 0; i < A.size(); i++) {
        
        if(ct < 0){
            templow = i;
            ct = 0;
        }
        
        A[i] == '0' ? ct++ : ct--;
    
        if(ct > max){
            max = ct;
            hi = i;
            low = templow;
        }
        
        
    }
 
   // cout << "max = " << max <<", high = " << hi << ", low = " << low << " ";
    
    if(max == 0){
        vector<int> solution;
        return solution;
    }
    else {
        vector<int> solution = {low+1, hi+1};
        return solution;
    }
}

