int climbStairs(int n) {
    int first = 0, next = 1;
    for (int i = 0; i < n; i++)
    {
        int tmp = next;
        next = first + next;
        first = tmp;
    }
    return next;
}