int main() {
    int N, M;
    int k;
    // user input matrix size
    printf("input the matrix size:\n");
    scanf("%d %d", &N, &M);

    // create matrix array 
    int matrix[N][M];

    // user input matrix elements
    printf("input Matrix elements:\n");
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int X = 0, Row_Val, Col_Val;

    // while Row_Val or Col_Val is not equal to 1
    for(k = 0; k <(N*M); k++) {
        for (i = 0; i < N; i++) {
            Row_Val = 1;
            for (j = 0; j < M; j++) {
                // if any element in row is less than X, Row_Val=0 then break
                if (X > matrix[i][j]) {
                    Row_Val = 0;
                    break;
                }
            }
            if(j==M)
                break;
        }

        for (i = 0; i < M; i++) {
            Col_Val = 1;
            for (j = 0; j < N; j++) {
                // if any element in the column is less than X, Col_Val=0 then break
                if (X > matrix[j][i]) {
                    Col_Val = 0;
                    break;
                }

            }
            if(j==N)
                break;
        }

        // if Row_Val and Col_Val= 1, increment X 
        if (Col_Val == 1 && Row_Val == 1) 
            X++;
        // if not break
        else
            break;
    }
    int result = X - 1;
    printf("X value : %d\n", result);

    return 0;
}



