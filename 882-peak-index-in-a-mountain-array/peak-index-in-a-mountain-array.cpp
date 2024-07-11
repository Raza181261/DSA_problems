class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int index;
        // int max=0;

        // for(int i = 0; i<arr.size()-1; i++){
        //     if(arr[i] > max){
        //         max = arr[i];
        //         index = i;
        //         }
        //         }
           
        // return index;

        int left=0;
        int right=arr.size()-1;

        while(left<right){
            int mid = (left+right)/2;

            if(arr[mid] < arr[mid+1]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};

