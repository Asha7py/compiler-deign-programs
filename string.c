#include <stdio.h>
int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
char* my_strcat(char *dest, const char *src) {
    int i = 0, j = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';

    return dest;
}
char* my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}
int my_strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}
void my_strrev(char *str) {
    int length = my_strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str1[100];
    char str2[100];
    char str3[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    printf("Length of first string: %d\n", my_strlen(str1));
    my_strcat(str1, str2);
    printf("Concatenation of first and second string: %s\n", str1);
    my_strcpy(str3, str1);
    printf("Copy of concatenated string to third string: %s\n", str3);
    printf("Comparison of concatenated string and third string: %d\n", my_strcmp(str1, str3));
    printf("Comparison of first and second string: %d\n", my_strcmp(str1, str2));
    my_strrev(str3);
    printf("Reversed third string: %s\n", str3);

    return 0;
}

