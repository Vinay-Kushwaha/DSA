
public class Solution {

	public int solve(int[] A) {
        int n = A.length;
        if(n==1){
            return 0;
        }
        int mod =1000000007;
        long ma=0l;
        long mi=0l;
        Arrays.sort(A);
        
        for(int i =0;i<n;i++){
            ma+=(A[i]*pow(2,i,mod))%mod;
            ma%=mod;
            mi+=(A[i]*pow(2,n-1-i,mod))%mod;
            mi%=mod;
            //System.out.println(ma+" "+mi);
        }
        //System.out.println(ma+" "+mi);
        return (int)(ma-mi+mod)%mod;
    }
    public long pow(long x,int y,int k){
        long result =1l;
        while(y>0){
            if(y%2==1){
                result = (result*x)%k;
                y--;
            }
            y>>=1;
            x=(x*x)%k;
        }
        return result;
    }
}
