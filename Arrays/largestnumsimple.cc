bool compare(const int&, const int&);

string Solution::largestNumber(const vector<int> &A){
    ostringstream oss;
    vector<int> B(A);
    bool zeroFlag = true;
    for(auto i: B){
        if(i != 0){
            zeroFlag = false;
            break;
        }
    }
    
    sort(B.begin(), B.end(), compare);
    for(int i = 0; i < B.size(); i++){
        oss << B[i];
    }
    
    if(zeroFlag)
        return "0";
    else
        return oss.str();
}

int numDigits(int n){ 
    int digits = 0;
    while(n != 0){ 
        n/=10;
        digits++;
     
    }   
    return digits;
}

bool compare(const int& first, const int& second){
    int f = first, s = second;
    int firstSecond, secondFirst;
    f *= pow(10,numDigits(second));
    s *= pow(10,numDigits(first));
    firstSecond = f + second;
    secondFirst = s + first;
    
    return firstSecond > secondFirst;
}
