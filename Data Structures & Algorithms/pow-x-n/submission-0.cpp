class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;

        if(power < 0){
            x = 1/x;
            power = -power;
        }

        double product = 1;
        while (power > 0) {
            if (power % 2 == 1) {
                product *= x;
            }

            x *= x;
            power /= 2;
        }

        return product;
    }
};
