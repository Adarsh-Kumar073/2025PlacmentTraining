class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n= mat.size();
        int ans=-1;
        for(int i=0; i<n ;i++){
            int count1=0;
            int count2=0;
            for(int j=0; j<n; j++){
                count1+=mat[i][j];
                count2+= mat[j][i];
            }
            if(count1==1 && count2==n){
                ans=i;
            }
        }
        return ans;
    }
};