#include <stdio.h>

int isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

/* Returns day of week: 0 = Sunday ... 6 = Saturday */
int dayOfWeek(int y, int m, int d) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 2, 6, 1, 4, 6, 4};
    if (m < 3)
        y--;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int main() {
    int year, m, d, start, i;
    char *names[] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Enter year: ");
    scanf("%d", &year);

    if (isLeap(year))
        days[1] = 29;

    start = dayOfWeek(year, 1, 1);   /* weekday of 1 January */

    for (m = 0; m < 12; m++) {
        printf("\n    %s %d\n", names[m], year);
        printf("Su Mo Tu We Th Fr Sa\n");

        for (i = 0; i < start; i++)
            printf("   ");

        for (d = 1; d <= days[m]; d++) {
            printf("%2d ", d);
            if ((d + start) % 7 == 0)
                printf("\n");
        }
        printf("\n");

        start = (start + days[m]) % 7;   /* first day of next month */
    }
    return 0;
}
