#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Translate {
    char word[100];
    char tran[100];
};

int comparator(const void * t1, const void * t2) {
    const struct Translate * trans1 = (const struct Translate *)t1;
    const struct Translate * trans2 = (const struct Translate *)t2;
    return strcmp(trans1->word, trans2->word);
}

void wordtolower(char * str) {
    for (size_t i = 0; i < strlen(str); ++i)
        if (isalpha(str[i]))
            str[i] = tolower(str[i]);
}

int main() {
    size_t dictionary_size = 1;
    size_t dictionary_count = 0;
    struct Translate * dictionary = (struct Translate *)malloc(dictionary_size * sizeof(struct Translate));

    while (1) {
        if (dictionary_count == dictionary_size) {
            dictionary_size <<= 1;
            dictionary = (struct Translate *)realloc(dictionary, dictionary_size * sizeof(struct Translate));
        }
        scanf("%s", dictionary[dictionary_count].word);
        wordtolower(dictionary[dictionary_count].word);
        if (strcmp(dictionary[dictionary_count].word, "ugabuga") == 0)
            break;
        scanf("%s", dictionary[dictionary_count].tran);
        ++dictionary_count;
    }

    qsort(dictionary, dictionary_count, sizeof(struct Translate), comparator);

    char key[100];

    char c = ' ';
    while (c = ' '){
        scanf("%s", key);
        wordtolower(key);
        struct Translate *p_key = bsearch(key, dictionary, dictionary_count, sizeof(struct Translate), comparator);
        if (p_key == NULL)
            printf("<unknown> ");
        else
            printf("%s ", p_key->tran);
        c = getchar();
    }

    return 0;
}
