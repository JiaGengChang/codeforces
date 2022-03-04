#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

int n,m;
vector<int> nums;
int main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  freopen("error.txt","w",stderr);
#endif
  cin >> n >> m;
  nums.resize(m+n);
  for (int i=0;i<n+m; ++i) cin >> nums[i];
  sort(nums.begin(),nums.end());
  debug(nums);
  int s = m+n;
  if (s%2==1){
    cout << nums[s/2];
  } else {
    cout << (nums[(s/2)-1] + nums[s/2])/(double)2;
  }
  return 0;
}

