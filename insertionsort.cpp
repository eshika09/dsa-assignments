#include<iostream>
using namespace std;
#include<vector>
void insertionSort(vector<int>&v){
    int n=v.size();
    for(int i=1; i<n; i++){
        int current=v[i];
        int j=i-1;
        while(j>=0&&v[j]>current){
            v[j+1]=v[j];
            j--;
        }v[j+1]=current;
    }return;
}
int main(){
    int n=5;
    vector<int>vec(5);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    insertionSort(vec);
    for(int i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }return 0;
}