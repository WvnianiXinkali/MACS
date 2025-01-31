#include<bits/stdc++.h>
using namespace std;

int LIS_size(vector<int>& arr){
    vector<int> subsq;
    for(int i = 0; i < arr.size(); i++){
        int newplacement = lower_bound(subsq.begin(), subsq.end(), arr[i]) - subsq.begin();
        if(newplacement >= subsq.size()){
            subsq.push_back(arr[i]);
        } else {
            subsq[newplacement] = arr[i];
        }
    }
    return subsq.size();
}

int logbase2(int n){
    int answ = 0;
    while(n){
        n = n>>1;
        answ++;
    }
    return answ;
}


void bst(int answ[], int strti, int endi, int val){
    if(strti<=endi){
        if(strti == endi) {
            answ[strti - 1] = val;
            return;
        }
        int head = 0;
        int N = endi - strti + 1;
        int logN = logbase2(N);
        int nthrowNum = (1 << (logN - 1));
        int elems = (1 << logN) - 1;
        int udevs = elems - N;
        if(nthrowNum - udevs > nthrowNum / 2){
            head = endi - ((nthrowNum - 1) / 2) - ((nthrowNum / 2) - udevs);
        } else {
            head = endi - (nthrowNum - 1) / 2;
        }
        answ[head - 1] = val;
        val = head;
        bst(answ, head + 1, endi, val);
        bst(answ, strti, head - 1, val);
    }
}


int main(){
    int tests;
    scanf("%d", &tests);
    for (int i = 0; i < tests; i++){
        int N;
        scanf("%d", &N);
        vector<int> arr;
        int m;
        for(int j = 0; j < N; j++){
            scanf("%d", &m);
            arr.push_back(m);
        }
        printf("Case %d:\n", i + 1);
        int minMove = N - LIS_size(arr);
        printf("Minimum Move: %d\n", minMove);
        int answ[N];
        int strti = 1,endi = N, val = -1;
        bst(answ, strti, endi, val);
        for(int j = 0; j < N; j++){
            printf("%d", answ[j]);
            if(j != N - 1) printf(" ");
        }
        printf("\n");
    }
}








