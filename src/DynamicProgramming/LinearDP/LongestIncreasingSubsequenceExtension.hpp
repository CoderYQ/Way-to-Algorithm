#ifndef LONGEST_INCREASING_SUBSEQUENCE_EXTENSION
#define LONGEST_INCREASING_SUBSEQUENCE_EXTENSION

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
using namespace std;


// TODO: ���㷨����bug

int f[MAX], g[MAX];

void LongestIncreasingSubsequenceExtension(const int s[MAX], int n, int &list, int &count)
{
    // ����s�ķ�Χ��[1,n]
    // ��ʼ��
    f[0] = 0;
    g[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        g[i] = 1;
    }

    // ��������������еĳ���
    for (int i = 1; i <= n; i++) {
        int max_length = 0;
        for (int k = 1; k < i; k++) {
            if (s[i] > s[k])
                max_length = max(max_length, f[k]);
        }
        f[i] = max_length+1;
    }
    int lis = 1;
    for (int i = 1; i <= n; i++) {
        lis = max(lis, f[i]);
    }

    // ������ͬ���ȵ�����������е�����
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k < i; k++) {
            if (s[i] > s[k]) {
                if (f[i] < f[k]+1) {
                    g[i] = g[k];
                } else if (f[i] == f[k]+1) {
                    g[i] += g[k];
                }
            }
        }
    }
    count = 0;
    for (int i = 1; i <= n; i++) {
        count = max(count, g[i]);
    }

    return lis;
}


#endif
