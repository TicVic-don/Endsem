#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> &arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <=right)
    {
        cout<<"finding"<<endl;
        int mid = left + (right - left) / 2;
        cout<<"mid :"<<mid;
        cout<<"left:"<<left;
        cout<<"right:"<<right;
        if(arr[mid]>target){
            right = mid -1;
        }
        else if (arr[mid]<target){
            left = mid +1;
        }
        else{
            return mid;
        }
        /* code */
    }
    
    return -1;
}
int binary_recussion(vector<int> & v, int target, int left, int right){
   if(right>=left){
     int mid = left +(right- left)/2;
     if(v[mid]==target){
       return mid;
     }
     else if (v[mid]>target){
        return binary_recussion(v, target, left, mid-1);

     }
     else{
        return binary_recussion(v, target, mid+1, right);
     }
   }
   return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 11;
    int index = binary_search(arr, target);
    int index2 = binary_recussion(arr, target, 0, arr.size()-1);
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    if (index2 != -1) {
        cout << "Element found at index: " << index2 << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}

// binary srarch using recussion
