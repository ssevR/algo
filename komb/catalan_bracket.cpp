//https://en.wikipedia.org/wiki/Catalan_number
//https://math.stackexchange.com/questions/4587938/number-of-balanced-bracket-sequences-with-given-prefix-and-suffix

mint f(int n, int k, int m) {
    return C(k, (k - n + m) /2) - C(k, (k + n + m)/2 + 1);
}

