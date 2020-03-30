//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int a[120];
int main(){
    int t;
    int i,j;
    int n,k;
    int countt = 0;
    cin >> t;
    for(i = 1;i<=t;i++){
        countt = 0;
        cin >> n;
        for(j = 1;j<n;j++){
            cin >> a[j];
        }
        for(j = 1;j<=n;j++){
            if(j!=a[j]){
             for(k = j+1;k<=n;k++){
                 if(a[k] == j){
                     swap(a[k],a[j]);
                     countt++;
                     break;
                 }
             }
            }
        }
        cout << "Case " << i << ": " << countt << endl;
    }
    return 0;
}