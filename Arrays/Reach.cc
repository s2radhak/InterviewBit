#include <cstdlib>// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int maxVal(int, int);

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int steps = 0;
    for (int i=0; i< X.size() - 1; i++){
        steps += maxVal(abs(X[i+1]-X[i]), abs(Y[i+1]- Y[i]));
    }
    return steps;
}

int maxVal(int a, int b){
    return a>b?a:b;
}
