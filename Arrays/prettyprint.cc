vector<vector<int> > Solution::prettyPrint(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // outer loop to track size
    int size = A*2-1;
    vector<int> entry(size,0);
    vector<vector<int> > x(size, entry);
    
    int colStart = 0, rowStart = 0, row, col;
    for(;size > 0; size-=2){
        
        // print left-right
        row = rowStart;
        for(col = colStart; col < colStart + size; col++){
            x[row][col] = A;
        }
        
        // print top-bottom
        col = colStart + size - 1;
        for(row = rowStart; row < rowStart + size; row++){
            x[row][col] = A;
        }
        
        // print right-left
        row = rowStart + size - 1;
        for(col = colStart; col < colStart + size; col++){
            x[row][col] = A;
        }
        
        // print bottom-up
        col = colStart;
        for(row = rowStart; row < rowStart + size; row++){
            x[row][col] = A;
        }
        
        //update rowstart, colstart
        rowStart++;
        colStart++;
        A--;
    }
    
    return x;
}

