vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > solution;
    
    if(A == 0)
        return solution;
        
    vector<int> row1(1,1);
    vector<int> row2(2,1);
    switch (A){
        case 1: solution.push_back(row1);
                break;
        case 2: solution.push_back(row1);
                solution.push_back(row2);
                break;
        default: solution.push_back(row1);
                 solution.push_back(row2);
                 
                 for(int i = 2; i < A; i++){
                    vector<int> row(1,1);
                    for(int j = 1; j < solution[i-1].size(); j++){
                        row.push_back(solution[i-1][j]+solution[i-1][j-1]);
                    }
                    row.push_back(1);
                    solution.push_back(row);
                }
                
                break;
        
    }
    
    return solution;
    
}

