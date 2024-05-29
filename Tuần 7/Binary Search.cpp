#include<bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int l,int r,int target){
	if (r>=l) {
		int mid=(r-l)/2;
		if(a[mid]==target) return mid;
		if (mid>target) {
			return binarysearch(a,l,mid-1,target);
		}
		else return binarysearch(a,mid+1,r,target);
	}
	return -1;
}
int main(){
	int n;int a[n];int target;cin>>n>>target;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int l=a[0];
	int r=a[n-1];
	cout<<binarysearch(a,l,r,target);
}
