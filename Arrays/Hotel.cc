enum Paren{
    LEFT,
    RIGHT
};

typedef struct node{
    int key;
    Paren paren;    
} Node;

bool compareByArrival(const Node& firstEle, const Node& secondEle){
    return firstEle.key < secondEle.key;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int guestCount = 0, maxAllowed = K;
    vector<Node> solution;
    for(int i = 0; i < arrive.size(); i++){
        Node entry;
        if(arrive[i] == depart[i])
            continue;
        entry.key = arrive[i];
        entry.paren = Paren::LEFT;
        solution.push_back(entry);
    
        entry.key = depart[i];
        entry.paren = Paren::RIGHT;
        solution.push_back(entry);
    }

    sort(solution.begin(), solution.end(), compareByArrival);
    for(int i = 0; i < solution.size(); i++){
        //cout << solution[i].key << ", " << solution[i].paren << "\t";
        solution[i].paren == Paren::LEFT? guestCount++ : guestCount--;
    if(guestCount > maxAllowed) return false;
        
    }
    
    return true;
}

