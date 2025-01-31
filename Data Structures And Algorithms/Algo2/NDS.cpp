#include<bits/stdc++.h>
using namespace std;

int nds(vector<int>& arr, int& L){
    vector<int> subsq;
    for(int i = 0; i < arr.size(); i++){
        int newplacement = lower_bound(subsq.begin(), subsq.end(), arr[i]) - subsq.begin();
        if(newplacement >= subsq.size()){
            subsq.push_back(arr[i]);
        } else {
            subsq[newplacement] = arr[i];
        }
    }
    if(subsq.size() >= L) return subsq[L - 1];
    return -1;
}

int main(){
    int tests;
    scanf("%d", &tests);
    for (int i = 0; i < tests; i++){
        int N;
        scanf("%d", &N);
        vector<int> arr;
        int m;
        int L;
        for(int j = 0; j < N; j++){
            scanf("%d", &m);
            arr.push_back(m);
        }
        scanf("%d", &L);
        if(N == 0 || L == 0 || L > N) {
          printf("%d\n", -1);
          continue;
        }
        int answ = nds(arr, L);
        printf("%d\n", answ);
    }
    return 0;
}
