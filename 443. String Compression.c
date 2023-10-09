#define MAX_STR_LEN (5)

int compress(char* chars, int charsSize){
    int i = 0, j = 0, k = 0, l;
    char str[MAX_STR_LEN + 1]; 

    str[MAX_STR_LEN] = 0;

    while (i < charsSize) {
        chars[j++] = chars[i];
        k = i + 1;

        while (k < charsSize && chars[k] == chars[i]) {
            k++;
        }

        if (k - i > 1) {
            int len = snprintf(str, MAX_STR_LEN, "%d", k - i);

            for (l = 0; l < len; l++) {
                chars[j++] = str[l];
            }
        }

        i = k;
    }

    return j;
}