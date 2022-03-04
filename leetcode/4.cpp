#include <bits/stdc++.h>

using namespace std

class Solution {
public:
    //median of m[l] to m[r-1]
    double median(vector<int> m, int l, int r){
        int s = r-l;
        return s%2 ? (double)m[l+(s/2)] : (m[l+(s/2)-1]+m[l+(s/2)])/(double)2;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()==1)
            nums1.push_back(nums1[0]);
        if (nums2.size()==1)
            nums2.push_back(nums2[0]);
        int l1=0,r1=nums1.size();
        int l2=0,r2=nums2.size();
        while (r1-l1!=2 && r2-l2!=2){
            double m1 = median(nums1,l1,r1);
            double m2 = median(nums2,l2,r2);
            if (m1 < m2){
                //first half of m1, second half of m2
                r1 = (l1+r1)/2+1;//also take m1
                l2 = (l2+r2)/2;
            } else {
                //second half of m1, first half of m2
                l1 = (l1+r1)/2;
                r2 = (l1+r2)/2+1;
            }
        }
        return ((max(nums1[0],nums2[0])+min(nums1[1],nums2[1]))/(double)2);
    }
};
int n,m;
vector<int> nums1,nums2;
int main(){
  Solution sol();
  cin >> n >> m;
  for (int i=0;i<n; ++i) cin >> nums1[i];
  for (int i=0;i<m; ++i) cin >> nums2[i];
  double ans = sol.findMedianSortedArrays(nums1,nums2);
  cout << ans;
}
