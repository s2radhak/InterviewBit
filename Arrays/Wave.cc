#include <algorithm>

vector<int> Solution::wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end());
    
    vector<int> solution(A.size(), 0);
    for(int i = 1; i < A.size(); i+=2) {
        solution[i-1] = A[i];
        solution[i] = A[i-1];
        
    }
    
    // last element if odd sized
    if (A.size() % 2 != 0)
        solution[A.size()-1] = A[A.size()-1];
        
    return solution;
}

