#include <stdio.h>
#include <string.h>

int solution(const char *text, const char *patt) {
    size_t text_len = strlen(text);
    size_t patt_len = strlen(patt);
    size_t i;
    size_t j;
    for (i = 0; i < text_len - patt_len + 1; ++i) {
        // Предполагаемая величина сдвига для данного символа строки.
        int shift = (patt[0] - text[i] + 26) % 26;
        for (j = 0; j < patt_len; ++j)
            if ((text[i + j] + shift - 'a') % 26  != patt[j] - 'a')
                break;
        if (j == patt_len)
            return shift;
    }
    return -1;
}

int main() {
    char text[100];
    char patt[100];
    scanf("%s %s", text, patt);
    printf("%d", solution(text, patt));
    return 0;
}
