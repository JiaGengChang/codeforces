//linear sieve
{
    const int N = 10000000;
    vi lp(N+1);
    vi pr;
    void sieve() {
        F(i,2,N+1){
            if(lp[i]==0) {
                lp[i]=i;
                pr.push_back(i);
            }
            for(int j=0;j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j){
                lp[i * pr[j]] = pr[j];
            }
        }
    }
}

//sieve of erasthothenes
{
    const int b = 100000;
    vector<bool> is_prime(b,true);
    vi prime;
    void sieve() {
        F(i,2,b+1){
            if(is_prime[i]){
                primes.pb(i);
                for(ll j=i*i; j<=b; j+=i){
                    is_prime[j]=false;
                }
            }
        }
    }
}
