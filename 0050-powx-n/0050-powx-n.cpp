class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long nn = n;
        
        // edge case
        if(n < 0) {
            nn *= -1;
        }
        
        // binary exponentiation
        while(nn > 0) {
            // if n is odd
            if(nn % 2 == 1) {
                ans = ans * x;
                nn = nn - 1;
                
            } 
            // if n is even
            else {
                x = x * x;
                nn = nn / 2;  
                if(nn == 0) break;
                
            }
        } 
        
        if(n < 0) {
            ans = 1 / ans;
        }
        
        return ans;
    }
};