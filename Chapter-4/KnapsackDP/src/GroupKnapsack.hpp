#ifndef TWO_DIMENSION_KNAPSACK
#define TWO_DIMENSION_KNAPSACK

#ifndef MAX
#define MAX 1024
#endif
// #include <iostream>
#include <algorithm>
using namespace std;


// f[k][j] ǰ k ������������ j ������ֵ
int f[MAX][MAX];

/**
 * ��Ʒ��Ϊ n ��
 * �� i ������ group_n[i] ����Ʒ ��ΧΪ [ 1, group_n[i] ]
 * group[i][j] Ϊ�� i ���еĵ� j ����Ʒ
 * ����Ʒ item �ļ�ֵΪ item.value_ ����Ϊ item.weight_
 * ������װ�ص��������Ϊ total_weight
*/

struct Item {
    int value_;
    int weight_;
};

bool ItemCompare(const Item & a, const Item & b)
{
    double rate_a = (double)a.value_ / (double)a.weight_;
    double rate_b = (double)b.value_ / (double)b.weight_;
    if (rate_a != rate_b)
        return rate_a > rate_b;
    else
        return a.weight_ < b.weight_;
}

int GroupKnapsack(Item group[MAX][MAX], int group_n[MAX], int n, int total_weight)
{
    // ��ʼ��
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            f[i][j] = 0;

    // �����з����������
    for (int i = 1; i <= n; i++) {
        sort( (Item*)group[i] + 1, (Item*)group[i] + 1 + group_n[i], ItemCompare );
    }

    // �� k ����Ʒ
    for (int k = 1; k <= n; k++) {
        // һ���еĵ� i ����Ʒ
        for (int i = 1; i <= group_n[k]; i++) {
            // ���������� j
            for (int j = 0; j <= total_weight; j++) {
                // ��ͬһ�� k �еĲ�ͬ��Ʒ i ֮���ǻ����
                // ����ֻ��ѡ��һ��
                // ѡ����Ʒ i ��ǰһ����Ʒ i-1 ֮�м�ֵ����
                int tmp;
                if (j >= group[k][i].weight_) {
                    tmp = max( f[k-1][j], f[k-1][ j - group[k][i].weight_ ] + group[k][i].value_ );
                } else {
                    tmp = f[k-1][j];
                }
                f[k][j] = max( f[k][j], tmp );
            }
        }
    }

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total_weight; j++) {
            cout << "f[" << i << "][" << j <<"]: " << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    */

    return f[n][total_weight];
}


#endif
