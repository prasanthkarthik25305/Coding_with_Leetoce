class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int maxy=arr[n-1];
        for(int i=n-1;i>=0;i--){
            if(maxy<arr[i]){
                maxy=arr[i];
            }
            else{
                arr[i]=maxy;
            }
        }
     for(int i=0;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        arr[n-1]=-1;
        return arr;
    }
};