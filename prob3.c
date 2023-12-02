#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 1000

int data[MAX];
int N, K;

// 2-SUM 문제를 순환 함수로 푸는 함수
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
    // N의 값과 정렬된 정수 배열 입력 받기
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &data[i]);
    }

    // K의 값 입력 받기
    scanf("%d", &K);

    // 2-SUM 문제 해결 및 결과 출력
    int result = countPairs(0, N - 1);
    printf("%d\n", result);

    return 0;
}
