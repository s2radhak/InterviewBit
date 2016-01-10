void printvec(vector<vector<int> > &A){
    for(int i = 0; i < A.size(); i++){
        cout << "[ ";
        for(int j = 0; j < A[i].size(); j++){
            cout << A[i][j];
        }
        cout << "], ";
    }
}

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    vector<vector<int> > finalSolution;
    int colStart, rowStart, row, col;    
    //cout << A.size(); 
    // go over first row, left to right
    for(colStart = 0; colStart < A.size(); colStart++){
        rowStart = 0;
        row = rowStart; col = colStart;
        vector<int> solution;
        while(row < A.size() && col >= 0){
            solution.push_back(A[row][col]);
            row++;
            col--;
        }
        finalSolution.push_back(solution);
       /// printvec(finalSolution);
    }
    
    // go over last col, top to bottom
    for(rowStart = 1; rowStart < A.size(); rowStart++ ){
        colStart = A.size() - 1;
        row = rowStart; col = colStart;
        vector<int> solution;
        while(col >=0 && row < A.size()){
            solution.push_back(A[row][col]);
            row++;
            col--;
        }
        finalSolution.push_back(solution);
       // printvec(finalSolution);
    }
    
    return finalSolution;   
}

