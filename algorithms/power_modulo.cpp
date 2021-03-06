ll mod_pow(ll b, ll e) {
    ll x=1;
    while(e>0){
        if(e&1){
            x = (x*b)%mod; --e;
        } else {
            b = (b*b)%mod; e/=2;
        }
    }
    return x;
}
