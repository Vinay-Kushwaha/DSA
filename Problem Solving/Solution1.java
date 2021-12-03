
public class Solution {
	public int[] solve(int[] A, int[] B) {
        int n = A.length;
        int m = B.length;
        Arrays.sort(A);
        Arrays.sort(B);
        int i =0;
        int j =0;
        ArrayList<Integer> r = new ArrayList<>();
        while(i<n && j<m){
            if(A[i]>B[j] ){
                j++;
            }else if(B[j]>A[i] ){
                i++;
            }else{
                r.add(A[i]);
                i++;
                j++;
            }
        }
        int [] res = new int[r.size() ];
        for(int k=0;k<res.length;k++){
            res[k]=r.get(k);
        }
        return res;
    }

}
