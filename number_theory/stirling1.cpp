mint stirling1[M][M];
void calc_s1() {
    stirling1[0][0] = 1;
    for (int i = 1; i < M; ++i) {
        stirling[i][0] = stirling[0][i] = 0;
        for (int j = 1; j <= i; ++j) {
            stirling[i][j] = (i - 1) * stirling[i - 1][j] + stirling[i - 1][j - 1];
        }
    }
}
