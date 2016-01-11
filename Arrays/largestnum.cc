bool lexicalSort(const int& first, const int& second);

bool printvec(vector<int> v){
    for(auto i:v)
        cout << i << ", ";
    cout << "\t";
}

string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map<int, vector<int> > numMap;
    ostringstream oss;
    // create buckets
    for(int i = 0; i < A.size(); i++){
        // find most significant digit
        int val = A[i];
        vector<int> entry;
        while(true){
            if(val/10 == 0) {
               // cout << "key:"<<val%10 << ", val: ";
                auto it = numMap.find(val%10);
                if(it == numMap.end()){
                    entry.push_back(A[i]);
                    numMap.insert( {val%10, entry});
                  //  printvec(entry);
                }
                else {
                    it->second.push_back(A[i]);
                  //  printvec(it->second);
                }
                
                break;
            }
            val/=10;
        }
    }
    
    // sort each bucket and build string 
    for(int key = 9; key >=0; key--){
        sort(numMap[key].begin(), numMap[key].end(), lexicalSort);
        //printvec(numMap[key]);
        for(int i = 0; i < numMap[key].size(); i++){
            oss << numMap[key][i];
        }
    }
    return oss.str();
    //string s("gello");
    //return s;
    
}

// get number of digits in a number; worse case complexity O(k),
// where k is the number of digits in n. 
int numDigits(int n){
    int digits = 0;
    while(n != 0){
        n/=10;
        digits++;
        
    }
    return digits;
}

// sort within buckets
bool lexicalSort(const int& first, const int& second){
    //cout << "comparing" << first << "and" << second;
    int _first = first, _second = second;
    int diff = numDigits(first) - numDigits(second);
    int deltaShift = _first/(pow(10,numDigits(first)-1));
    
    if(diff < 0){
        diff *= -1;
        _first *= 10*diff;
        while(diff>0){
            diff--;
            _first += (pow(10,diff)*deltaShift);
        }
        //cout << "first" << _first;
        return _first > second;
        
    }
    
    else if(diff > 0){
        
        _second *= 10*diff;
        while(diff>0){
            diff--;
            _second += (pow(10,diff)*deltaShift);
        }
        //cout << ", second "<< _second;
    }
    
    return _first > _second ;
    
}


