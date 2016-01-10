vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> newRow(A,0);
    vector<vector<int> > solution(A, newRow);
    
    // loop over. each iteration reduces MXM matrix to (M-2)X(M-2)
    int rowStart = 0, colStart = 0, row, col, val = 0;
    for(; A >= 0; A-=2){
             
        // add left to right
        row = rowStart;
        for(col = colStart; col < colStart+A; col++){
            solution[row][col] = ++val;
        }
        val--; // overwrite edges, makes loops look cleaner.
        
        // add top to bottom
        col = colStart+A-1;
        for(row = rowStart; row < colStart+A; row++){
            solution[row][col] = ++val;
        }
        val--;
        
        // add right to left
        row = rowStart+A-1;
        for(col = colStart+A-1; col >=colStart; col--){
            solution[row][col] = ++val;
        }
        val--;
        
        // add bottom to top
        col = colStart;
        for(row = rowStart+A-1; row >rowStart; row--){
            solution[row][col] = ++val;
        }
        // val--; not needed since we don't overwrite the left corner value
        
        // update starting point for next iteration
        rowStart++;
        colStart++;
    }
    
    return solution;
    
    
}

