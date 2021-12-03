
public class Solution {
	public int firstMissingPositive(int[] A) {
        int n = A.length;
        int i = 0;
        while(i<n){
            if(A[i]<=0 || A[i]>n || A[i]==(i+1)  ){
                i++;
                continue;
            }else if(A[A[i]-1]==A[i]){
                i++;
                continue;
                
            }else{
                int temp = A[A[i]-1];
                A[A[i]-1]=A[i];
                A[i]=temp;
            }
        }
        int res=0;
        for(int j =0;j<n;j++){
            if((A[j]-1)==j){
                res=j+2;
                continue;
            }else if(A[j]!=(j+1)){
                res =j+1;
                break;
            }
        }
        return res;
    }

}
