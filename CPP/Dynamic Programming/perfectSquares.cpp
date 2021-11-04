// Problems: https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int A) {
    int mnr[A+1];
    mnr[0]=0;
    for(int i=1;i<=A;i++){
        mnr[i]=i; 
        for(int k=1;k*k<=i;k++){
            mnr[i] = std::min(mnr[i],mnr[i-(k*k)]+1);
        }
    }
    
//     for(int i=0;i<A+2;i++){
//         cout<<mnr[i]<<" ";
//     }
    return mnr[A];
        
    }
    
};