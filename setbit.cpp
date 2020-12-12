#include <bits/stdc++.h>

using namespace std;

#define L long
#define LL long

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

L setBitNumber(L n) { 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
    n = n + 1; 
    return (n >> 1); 
}

L highestPowerof2(L n){
    L res = 0;
    while(n!=0) {
        res++;
        n=n>>1;
    }
    return 1<<(res-1);
}

int main(){
    L num;
    cin>>num;

    cout<<highestPowerof2(num);
}