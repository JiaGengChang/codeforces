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
