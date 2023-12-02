#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 1000

int data[MAX];
int N, K;

// 2-SUM ������ ��ȯ �Լ��� Ǫ�� �Լ�
int countPairs(int start, int end) {
    if (start >= end) {
        return 0;
    }

    int sum = data[start] + data[end];
    int count = 0;

    if (sum > K) {
        return countPairs(start, end - 1);
    }
    else if (sum < K) {
        return countPairs(start + 1, end);
    }
    else {
        count++;
        count += countPairs(start + 1, end - 1);
    }

    return count;
}

int main() {
    // N�� ���� ���ĵ� ���� �迭 �Է� �ޱ�
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &data[i]);
    }

    // K�� �� �Է� �ޱ�
    scanf("%d", &K);

    // 2-SUM ���� �ذ� �� ��� ���
    int result = countPairs(0, N - 1);
    printf("%d\n", result);

    return 0;
}
