//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#pragma warning(disable:4996)
//
//// 회문인지 판단하는 순환 함수
//bool is_palindrome(const char* word, int start, int end) {
//    // 단어의 길이가 0 또는 1이면 회문이다
//    if (start >= end) {
//        return true;
//    }
//
//    // 첫 글자와 마지막 글자가 같은지 확인하고, 다르면 회문이 아니다
//    if (word[start] != word[end]) {
//        return false;
//    }
//
//    // 다음 글자로 이동하여 순환 호출
//    return is_palindrome(word, start + 1, end - 1);
//}
//
//int main() {
//    char word[100];
//
//    // 단어 입력
//    scanf("%s", word);
//
//    // 단어가 회문인지 아닌지 판단하여 결과 출력
//    if (is_palindrome(word, 0, strlen(word) - 1)) {
//        printf("Yes");
//    }
//    else {
//        printf("No");
//    }
//
//    return 0;
//}
