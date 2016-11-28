#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

FILE *fp;

int main(int argc, char *argv[]) {

    // Open file in read mode
    fp = fopen(argv[1], "r");

    int newlines = 0;
    int words = 0;
    int bytes = 0;

    char c;
    bool in_word = false;
    while((c = fgetc(fp)) != EOF) {
        bytes++;
        if(c == '\n') {
            newlines++;
        }
        // When leaving a word, increment the words counter
        if(in_word && isspace(c)) {
            words++;
            in_word = false;
        } else {
            if(!isspace(c)) {
                in_word = true;
            }
        }
    }

    // If we were in a word when we reached EOF, count that too
    if(in_word) {
        words++;
    }

    printf(" %d %d %d %s\n", newlines, words, bytes, argv[1]);

    return 0;
}