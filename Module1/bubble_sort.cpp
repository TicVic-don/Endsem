#include <iostream>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

void bubble(vector<int> &v , int n){

    int i , j;
    for(i =0;i<n;i++){
        bool swapped = false;
        for(j =0;j<n-i;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped = true;
            }
        }
        if(swapped==false){
            break;
        }
    }

}
void bubble2(vector<int> &v, int n){
    int count = 1;
    while(count<n){
        for(int j =0; j<n-count;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
        count++;
    }
}

void insertion_sort(vector<int>&v, int n){
    int i , key , j;
    for(i=1;i<n;i++){
        key = v[i];
        j=i-1;
        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j=j-1;
        }
        v[j+1]=key;
    }
}
int partation(vector<int> &v ,int l , int r){
    int pivit = v[r];

    int i = l-1;
    int j = l;
    for(j ;j<r;j++){
        if(v[j]<pivit)
       {
       i++;
        swap(v[i],v[j]);
       } 

    }
    swap(v[i+1],v[r]);

return i+1;
}


void quick_sort(vector<int> &v , int l , int r){

    if(l<r){
        int pivit = partation(v,l,r);
        quick_sort(v,l,pivit-1);
        quick_sort(v,pivit+1,r);
    }
}


int main(){

    vector<int> v ={3, 1, 2, 3, 2 ,1};

    int n = v.size();

    quick_sort(v,0,5);

    // for(int i =0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }
    int i =0;
    while( i <n){
        cout<<v[i]<<" ";
        i++;
    }

}
