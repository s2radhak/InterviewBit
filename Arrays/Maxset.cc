vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<long int> maxSum(A.size(), 0);
    vector<int> low(A.size(),0), hi(A.size(), 0);
    long int sumSoFar = 0;
    int i = 0, j = 0;
    bool isNegative = true, reset = false;
    
    //obtain vectors of max subrange sum with ranges
    
    for(;i < A.size(); i++){
        
        if(isNegative)
            isNegative = A[i] < 0 ? true : false;
        
        if(sumSoFar == 0 && reset){
            low[j] = i;
            reset = false;
            
        }
        
        sumSoFar += A[i];
        if(sumSoFar < maxSum[j]){
            sumSoFar = 0;
            reset = true;
            j++;
        }
        else{
            maxSum[j] = sumSoFar;
            hi[j] = i;
        }
    }
    
    // deal with ties 
    int maxIndex = 0;
    
    for(i = 1; i < maxSum.size(); i++){
       
        if(maxSum[maxIndex] != maxSum[i])
            maxIndex = (maxSum[maxIndex]>maxSum[i])?maxIndex:i ;
        else {
            if((hi[maxIndex]-low[maxIndex]) != (hi[i]-low[i])){
                maxIndex = (hi[maxIndex]-low[maxIndex])>(hi[i]-low[i])? maxIndex:i;
            }
            else {
                maxIndex = low[maxIndex]<low[i]? maxIndex:i;
            }
        }
        
    }
    
    if (! isNegative) {
        vector<int> solution(A.begin() + low[maxIndex], A.begin() + hi[maxIndex]+1);
        return solution;
    }
        
    else{
        vector<int> solution;
        return solution;
    }
}
    
    
    
    
