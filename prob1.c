//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#pragma warning(disable:4996)
//
//// ȸ������ �Ǵ��ϴ� ��ȯ �Լ�
//bool is_palindrome(const char* word, int start, int end) {
//    // �ܾ��� ���̰� 0 �Ǵ� 1�̸� ȸ���̴�
//    if (start >= end) {
//        return true;
//    }
//
//    // ù ���ڿ� ������ ���ڰ� ������ Ȯ���ϰ�, �ٸ��� ȸ���� �ƴϴ�
//    if (word[start] != word[end]) {
//        return false;
//    }
//
//    // ���� ���ڷ� �̵��Ͽ� ��ȯ ȣ��
//    return is_palindrome(word, start + 1, end - 1);
//}
//
//int main() {
//    char word[100];
//
//    // �ܾ� �Է�
//    scanf("%s", word);
//
//    // �ܾ ȸ������ �ƴ��� �Ǵ��Ͽ� ��� ���
//    if (is_palindrome(word, 0, strlen(word) - 1)) {
//        printf("Yes");
//    }
//    else {
//        printf("No");
//    }
//
//    return 0;
//}
