class Solution {
public:
    void solve(double x, int n, double& res){
        if(n <= 0){
            return;
        }
        if(n & 1){
            res = (res*x);
        }
        n = n >> 1;
        solve(x*x,n,res);
    }
    double myPow(double x, int n) {
        double res = 1;
        
        if(n < 0){
            n = abs(n);
            solve(x,n,res);
            return 1/res;
        }
        solve(x,n,res);
        return res;
    }
};