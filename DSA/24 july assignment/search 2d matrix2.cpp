class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n= matrix[0].size();

        int i=0, j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j]== target){
                return true;
            }
            if(matrix[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }

        // for(int i=0; i<m; i++){
        //     int low=0; int high= n-1;
        //     while(low<= high){
        //         int mid= low+ (high-low)/2;
        //         if(matrix[i][mid]==target){
        //             return true;
        //         }
        //         else if(matrix[i][mid]>target){
        //             high=mid-1;
        //         }
        //         else{
        //             low=mid+1; 
        //         }
        //     }
        // }
        return false;
    }
};