vll factors(ll n){
    set<ll> ps;
    ll z=2;
    while(z*z <= n){
        if (n%z==0) {
            ps.ins(z);
            n/=z;
        } else ++z;
    }
    if (n>1) ps.ins(n);
    vll v;
    copy(all(ps),bkin(v));
    return v;
}
