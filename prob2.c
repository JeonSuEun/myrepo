//#include <stdio.h>
//#pragma warning(disable:4996)
//// 두 문자열의 사전식 순서를 비교하는 순환 함수
//int compare(const char* str1, const char* str2) {
//    if (*str1 == '\0' && *str2 == '\0') {
//        return 0; // 두 문자열이 같다
//    }
//    else if (*str1 == '\0') {
//        return -1; // str1이 더 짧다
//    }
//    else if (*str2 == '\0') {
//        return 1; // str2가 더 짧다
//    }
//
//    if (*str1 < *str2) {
//        return -1; // str1이 더 빠르다
//    }
//    else if (*str1 > *str2) {
//        return 1; // str2가 더 빠르다
//    }
//
//    return compare(str1 + 1, str2 + 1); // 다음 위치로 이동하여 순환 호출
//}
//
//int main() {
//    char word1[100], word2[100];
//
//    // 두 단어 입력
//    scanf("%s", word1);
//    scanf("%s", word2);
//
//    // 두 단어의 사전식 순서를 비교하여 결과 출력
//    int result = compare(word1, word2);
//    if (result < 0) {
//        printf("%s, %s\n", word1, word2);
//    }
//    else if (result > 0) {
//        printf("%s, %s\n", word2, word1);
//    }
//    else {
//        printf("두 단어는 사전식으로 동일합니다.\n");
//    }
//
//    return 0;
//}
