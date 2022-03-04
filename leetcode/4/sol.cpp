#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else
#define debug(x...)
#endif 

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& arr, vector<int>& arr2) {
   int i = 0;
   int tl = arr.size()+arr2.size();
   int j = arr.size();
   int n1 = arr.size();
   int n2 = arr2.size();
   if(j>n2){
    return findMedianSortedArrays(arr2,arr);
   }

   while(i<=j){
     int mid = i + (j-i)/2;
     int secondMid= (tl+1)/2 - mid;
      int max1=(mid==0)?INT_MIN:arr[mid-1];
      int max2=(secondMid==0)?INT_MIN:arr2[secondMid-1];
      int min1=(mid==n1)?INT_MAX:arr[mid];
      int min2=(secondMid==n2)?INT_MAX:arr2[secondMid];
     if(max1>min2){
             j = mid-1;
         }
         else if(max2>min1){
             i = mid+1;
         }
         else {
             if((n1+n2)%2==0){
            return ((double) (max(max1,max2)+ min(min1,min2))/2);
        }else{
            return (double)max(max2,max1);
        }
       }
     }
     return 0.0;
  }
};

int n,m;
vector<int> nums1,nums2;
int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  freopen("error.txt","w",stderr);
#endif
  Solution sol;
  cin >> n >> m;
  nums1.resize(n);
  nums2.resize(m);
  for (int i=0;i<n; ++i) cin >> nums1[i];
  for (int i=0;i<m; ++i) cin >> nums2[i];
  cout << sol.findMedianSortedArrays(nums1,nums2) << '\n';
}
