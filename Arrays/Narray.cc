// Warning : online judge claimed that the solution has overflow issues, but couldn't find any in my testing. 

int term1(const vector<int>&);
int term2(const vector<int>&);

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int term_1 = term1(A), term_2 = term2(A);
    int a = (int) (0.5*(term_2/term_1 + term_1));
    int b = (int) (a - term_1);
    
    vector<int> solution;
    solution.push_back(a);
    solution.push_back(b);
    
    return solution;
}

int term1(const vector<int>& A){
    int sum = 0;
    for(int i = 0; i < A.size(); i++){
        sum += A[i] - (i+1);
    }
    
    return sum;
}

int term2(const vector<int>& A){
    long sum = 0;
    for(int i = 0; i < A.size(); i++){
        sum += pow(A[i],2) - pow((i+1),2);
    }
    return (int)(sum);
}



