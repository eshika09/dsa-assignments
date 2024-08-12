#include<iostream>
using namespace std;
#include<vector>
void selectionSort(vector<int>&v){
    int n=v.size();
    for(int i=0; i<n-1; i++){
        int min_idx=i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[min_idx]){
                min_idx=j;
            }
        }if(i!=min_idx){
            swap(v[i], v[min_idx]);
        }
    }
}
int main(){int n=5;
vector<int>vec(5);
for(int i=0; i<5; i++){
    cin>>vec[i];
}
selectionSort(vec);
for(int i=0; i<5; i++){
    cout<<vec[i]<<" ";
}

    return 0;
}