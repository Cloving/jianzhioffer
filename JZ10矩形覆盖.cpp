class Solution {
public:
    int rectCover(int number) {
        if (number == 1 || number == 2 || number == 0) {
            return number;
        }
        int a = 1, b = 2;
        for (int i = 3; i <= number; ++i) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};