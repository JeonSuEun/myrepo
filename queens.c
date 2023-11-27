#include <stdio.h>
#include <stdbool.h>




int count_two_sum(int data[], int s, int t, int k)
{
	if (s >= t)
		return 0;
	if (data[s] + data[t] < k)
		return count_two_sum(data, s + 1, t, k);
	else if (data[s] + data[t] > k)
		return count_two_sum(data, s, t - 1, k);
	else
		return 1 + count_two_sum(data, s + 1, t - 1, k);
}

int floor(int data[], int begin, int end, int target)
{
	if (begin > end)
		return -1;

	int mid = (begin + end) / 2;
	if (data[mid] == target)
		return data[mid];
	else if (data[mid] < target)
		return floor(data, mid, end, target);
	else
		return floor(data, begin, mid - 1, target);
}
int N;
int cols[N+1];



// �������� : level���� ���� �̹� �����ִ�.
// �����ִ� ���� ��ġ�� �������� cols[0..level-1]�� ��ϵǾ� �ִ�.
// �ϴ� �� : ������ ��鿡 ���� ���Ƽ� ������ ���� ������ ī��Ʈ�ؼ� ������ �����Ѵ�.

int cols[N + 1];
bool queens(int level)
{
	if (!promising(level))
		return 0;
	else if (level == N)
		return 1;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;
		count += queens(level + 1);
	}
	return count;
}

int findMazePath(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N || maze[x][y] != PATHWAY_COLOUR)
		return 0;
	else if (x == N - 1 && y == N - 1) {
		//maze[x][y] = PATH_COLOUR;
		return 1;
	}

	maze[x][y] = PATH_COLOUR;
	int count = 0;
	count += findMazePath(x - 1, y);
	count += findMazePath(x, y + 1);
	count += findMazePath(x + 1, y);
	count += findMazePath(x, y - 1);
	maze[x][y] = PATHWAY_COLOUR;
	return count;
	
}