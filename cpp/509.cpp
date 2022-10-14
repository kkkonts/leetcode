class Solution {
public:
    int fib(int n) {
        int f0 = 0, f1 = 1, cur;
        if (n == 0)
            return f0;
        else if (n == 1)
            return f1;
        else {
            for (int i = 2; i <= n; i++){
                cur = f0 + f1;
                f0 = f1;
                f1 = cur;
            }
            return cur;
        }
    }
};