#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int mins[n + 5];
    mins[0] = 0;
    int k;
    for(int i = 1; i <= n; i ++){
        cin >> k;
        mins[i] = k;
    }
    if(n > 3){
        int answ = 0;
        int counter;
        for(int i = n; i > 3; i--){
            if(mins[i] + mins[1] + mins[i - 1] + mins[1] < mins[i] + mins[1] + mins[2] + mins[2]){
                answ += mins[i] + mins[1];
            } else {
                answ +=  mins[i] + mins[1] + mins[2] + mins[2];
                i--;
            }
            counter = i;
        }
        if(counter == 4){
            answ += mins[1] + mins[2] + mins[3];
        } else {
            answ += mins[2];
        }
        cout << answ;
    } else if(n == 2){
        cout << mins[2];
    } else if(n <= 1){
        cout << mins[n];
    } else if(n == 3){
        cout << mins[1] + mins[2] + mins[3];
    }

    return 0;
}
