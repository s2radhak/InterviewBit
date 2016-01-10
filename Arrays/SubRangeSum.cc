int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        int sumSoFar = 0, i = 0, maxSum =INT_MIN; 
    
    for (; i < A.size(); i++){
        sumSoFar += A[i];
        
        
        if (sumSoFar > maxSum)
            maxSum = sumSoFar;
        
        if(sumSoFar < 0){
            sumSoFar = 0;
            
        }
        
        
    }
    return maxSum;
}

