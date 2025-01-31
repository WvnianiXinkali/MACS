#include<bits/stdc++.h>
using namespace std;
 vector<int> m;
 int t;
    int mzegadamyoli = 0;
    int mtlianibitebi = 0;
    int ertianebi = 0;

    unordered_map<int, int> keeper;


void changer(int n, int count ){
    string s = "";
    int b = ertianebi;
    int q = count;
    int j = 0;
    int k = 0;

    while(n){
        count --;
        if(n % 2 == 1){
            s += '1';
            if(count >= 0) k++;
        } else {
            s += '0';
        }
        n = n / 2;
    }
    int z = 0;
    int p = s.size();
    for(int i =  p - 1; i > p - q - 1; i--){
        if(s[i] == '1'){
            z++;
        }
    }
    keeper[m[mzegadamyoli]] = b - k + z;
}

void ertianebisDatvla(int n){
    int count = 0;
    int p = n;
    while (n){
        count ++;
        ertianebi += n & 1;
        mtlianibitebi++;
        if(mtlianibitebi == m[mzegadamyoli]){
            changer(p, count);
            mzegadamyoli++;
            if(mzegadamyoli >= t) break;
        }
        n >>= 1;
    }
}
// am funqciis didi nawili gadmovige https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html?fbclid=IwAR3b9aCZiCoe-jrjxVfXxK3Vt3PsJ6kCHzXjsT6Ph2_nfnP2qeZdYeMxb0U#segmented-sieve am saitidan;
// radgan eratostenes saceris gaumjobesebuli versiaa da gaviazre shemdgom shevcvale kidec, magram umetesad rogorc abstraqcia ise gamoviyene.
void count_primes(int n) {
    const int S = 1000000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i]) {
                ertianebisDatvla(start + i);
                if(mzegadamyoli >= t) return;
            }
        }
    }
}

int main(){

    scanf("%d", &t);
    int test;
    vector<int> q;
    for(int i = 0 ; i < t; i ++){
        scanf("%d",&test);
        m.push_back(test);
        q.push_back(test);
    }
    sort(m.begin(), m.end());
    if(m[0] == 0){
        mzegadamyoli++;
        keeper[0] = 0;
    }
    count_primes(101865020);
    for(int i = 0; i < q.size(); i++){
        printf("%d\n", keeper[q[i]]);
    }
    return 0;
}
