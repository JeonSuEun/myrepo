//#include <stdio.h>
//#pragma warning(disable:4996)
//// �� ���ڿ��� ������ ������ ���ϴ� ��ȯ �Լ�
//int compare(const char* str1, const char* str2) {
//    if (*str1 == '\0' && *str2 == '\0') {
//        return 0; // �� ���ڿ��� ����
//    }
//    else if (*str1 == '\0') {
//        return -1; // str1�� �� ª��
//    }
//    else if (*str2 == '\0') {
//        return 1; // str2�� �� ª��
//    }
//
//    if (*str1 < *str2) {
//        return -1; // str1�� �� ������
//    }
//    else if (*str1 > *str2) {
//        return 1; // str2�� �� ������
//    }
//
//    return compare(str1 + 1, str2 + 1); // ���� ��ġ�� �̵��Ͽ� ��ȯ ȣ��
//}
//
//int main() {
//    char word1[100], word2[100];
//
//    // �� �ܾ� �Է�
//    scanf("%s", word1);
//    scanf("%s", word2);
//
//    // �� �ܾ��� ������ ������ ���Ͽ� ��� ���
//    int result = compare(word1, word2);
//    if (result < 0) {
//        printf("%s, %s\n", word1, word2);
//    }
//    else if (result > 0) {
//        printf("%s, %s\n", word2, word1);
//    }
//    else {
//        printf("�� �ܾ�� ���������� �����մϴ�.\n");
//    }
//
//    return 0;
//}
