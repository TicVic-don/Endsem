#include <iostream>
#include <string>

using namespace std;

bool palidrom(const string &str) {
    int left =0 ;
    int right = str.length()-1;
    while(left <right){
        if(str[left]!=str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true ;

}
int main(){
    string input ;
    cout<<"enter your string";
    cin>>input;
    if(palidrom(input)){
        cout<<input<<"is paildrom";
    }else{
        cout<<input<<"not paildrom";
    }
}