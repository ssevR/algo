mint stirling[M][M];
void calc_s2(){
    stirling[0][0] = 1;
    for (int i = 1; i < M; ++i) {
        stirling[i][0] = stirling[0][i] = 0;
        for (int j = 1; j <= i; ++j) {
            stirling[i][j] = j * stirling[i - 1][j] + stirling[i - 1][j - 1];
        }
    }
}
