#ifndef TWO_DIMENSION_KNAPSACK
#define TWO_DIMENSION_KNAPSACK

#ifndef MAX
#define MAX 128
#endif
// #include <iostream>
#include <algorithm>
using namespace std;


int f[MAX][MAX][MAX];

int TwoDimensionKnapsack(int value[MAX], int weight1[MAX], int weight2[MAX], int n, int w1, int w2)
{
    // ��ʼ��
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                f[i][j][k] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w1; j++) {
            for (int k = 0; k <= w2; k++) {
                if (j >= weight1[i] && k >= weight2[i]) {
                    f[i][j][k] = max( f[i-1][j][k], f[i-1][ j - weight1[i] ][ k - weight2[i] ] + value[i] );
                } else {
                    f[i][j][k] = f[i-1][j][k];
                }
            }
        }
    }

    /*
    cout << "debug info" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w1; j++) {
            for (int k = 0; k <= w2; k++) {
                cout << "f[" << i << "][" << j << "][" << k << "]: " << f[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    */

    return f[n][w1][w2];
}


#endif
