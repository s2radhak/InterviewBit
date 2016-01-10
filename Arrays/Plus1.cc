#include <deque>
vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int carry = 1;
    deque<int> q;
    for (const auto& e: A)
        q.push_back(e);
    
    for(deque<int>::reverse_iterator i = q.rbegin(); i != q.rend() ; i++){
        if(*i +carry != 10){
            *i += carry;
            carry = 0;
            break;
        }
        
        *i = 0;
        carry = 1;
        
    }
    
    if(carry)
        q.push_front(1);
    
    else {
        for (const auto& e:q){
            if(e == 0)
                q.pop_front();
            else
                break;
        }
        
    }
    
    
    vector<int> solution;
    for (const auto& e: q)
        solution.push_back(e);
    
    return solution;
}

