class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int Size_1 = nums1.size(), Size_2 = nums2.size();
        int half = (Size_1 + Size_2 + 1)/2;
        if(Size_1 > Size_2){
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0, high = Size_1;
        int i,j;
        while(low <= high){
            i = (low + high)/2;
            j = half - i;
            if(i > 0 && nums1[i-1] > nums2[j]){
                high = i - 1;
            }
            else if(i < Size_1 && nums1[i] < nums2[j-1]){
                low = i + 1;
            }
            else{
                break;
            }
        }
        int LeftMax,RightMin;
        if(i==0){
            LeftMax = nums2[j-1];
        }
        else if(j==0){
            LeftMax = nums1[i-1];
        }
        else{
            LeftMax = max(nums1[i-1],nums2[j-1]);
        }
        
        if((Size_1+Size_2)%2==1){
            return LeftMax;
        }
        
        if(i==Size_1){
            RightMin = nums2[j];
        }
        else if(j==Size_2){
            RightMin = nums1[i];
        }
        else{
            RightMin = min(nums1[i],nums2[j]);
        }
        return (LeftMax + RightMin)/2.0;
            
        }    
};