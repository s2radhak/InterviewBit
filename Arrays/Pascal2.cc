vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> solution(1,1);
    
    switch(A){
        case 0: break;
        case 1: solution.push_back(1);
                break;
        default: int prev = 1, curr;
                solution.push_back(1);
                for(int k = 2; k<=A; k++) {
                    for(int i = 1; i < solution.size(); i++){
                        //1 3 3 1; 1 4 3 1;  1 4 6 1 ; 1 4 6 7;
                        curr = solution[i];
                        solution[i] = curr + prev;        
                        prev  = curr;            
                        
                    } 
                    solution.push_back(1); // 1 4 6 7 1 
                }
                break;
        
    }
    return solution;
}

