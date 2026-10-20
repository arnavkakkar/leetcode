class Solution {
private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);

        // Fast pointer moves two steps while slow pointer moves one step
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        // If fast reaches 1, it's a happy number; if slow == fast, there's a cycle
        return fast == 1;
    }
};