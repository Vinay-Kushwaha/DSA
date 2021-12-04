
public class intersectionOfSortedArrays {

	public int[] intersect(final int[] A, final int[] B) {
        int n = A.length;
        int m = B.length;
        ArrayList<Integer> r = new ArrayList<>();
        int i =0;
        int j =0;
        while(i<n && j<m){
            if(A[i]<B[j] ){
                i++;
            }else if(A[i]==B[j]){
                r.add(A[i]);
                i++;
                j++;
            }else{
                j++;
            }
        }
        int [] res = new int[r.size()];
        for(int k =0;k<r.size();k++ ){
            res[k]=r.get(k);
        }
        return res;
    }

}
