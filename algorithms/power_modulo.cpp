
//fast power with square-and-multiply method
//as a modification, take modulo at each step
ll mod_pow(ll b, ll e, ll mod) {
    ll x=1;//running product
    while(e>0){
        if(e%2==1){
            x = (x*b)%mod;
            --e;
        } else {
            b = (b*b)%mod;//factor we multiply running product with
            e /= 2;
        }
    }
    return x;
}

