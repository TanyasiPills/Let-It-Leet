int sumOfTheDigitsOfHarshadNumber(int x) {
    int sum = 0;
    int count = x;
    while (count != 0) {
        sum += count % 10;
        count /= 10;
    }
    return (x % sum == 0) ? sum : -1;
}