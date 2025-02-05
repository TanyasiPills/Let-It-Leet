int mySqrt(int x) {
    double n = (double)x;
    double y = 1.0;
    double precision = 0.00001;

    while (n-y > precision || y-n > precision)
    {
        n = (n+y)/2;
        y = x/n;
    }
    return (int)n;
}