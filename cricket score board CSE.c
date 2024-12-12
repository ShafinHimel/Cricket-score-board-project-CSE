#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int toss() {
    return rand() % 2;  // Returns 0 or 1
}

int main() {
    char team1[50], team2[50];
    int tossResult, score1 = 0, score2 = 0, runs, ball, isOut;

    // Get team names
    printf("Enter the name of Team 1: ");
    scanf("%s", team1);
    printf("Enter the name of Team 2: ");
    scanf("%s", team2);

    srand(time(0));  // Initialize random seed for toss
    printf("\nTossing the coin...\n");
    tossResult = toss();

    char *battingFirst = tossResult == 0 ? team1 : team2;
    char *battingSecond = tossResult == 0 ? team2 : team1;

    printf("%s won the toss and will bat first.\n\n", battingFirst);

    // First innings
    printf("--- First Innings: %s Batting ---\n", battingFirst);
    for (ball = 1; ball <= 6; ball++) {
        printf("Ball %d: Enter runs scored (0-6): ", ball);
        scanf("%d", &runs);

        while (runs < 0 || runs > 6) {
            printf("Invalid input. Enter runs scored (0-6): ");
            scanf("%d", &runs);
        }

        printf("Is the batsman out? (1 for Yes, 0 for No): ");
        scanf("%d", &isOut);

        if (isOut) {
            printf("Batsman is out!\n");
            break;
        }

        score1 += runs;
    }
    printf("\n%s scored %d runs.\n\n", battingFirst, score1);

    // Second innings
    printf("--- Second Innings: %s Batting ---\n", battingSecond);
    for (ball = 1; ball <= 6; ball++) {
        printf("Ball %d: Enter runs scored (0-6): ", ball);
        scanf("%d", &runs);

        while (runs < 0 || runs > 6) {
            printf("Invalid input. Enter runs scored (0-6): ");
            scanf("%d", &runs);
        }

        printf("Is the batsman out? (1 for Yes, 0 for No): ");
        scanf("%d", &isOut);

        if (isOut) {
            printf("Batsman is out!\n");
            break;
        }

        score2 += runs;

        // Check if the chasing team has already won
        if (score2 > score1) {
            break;
        }
    }
    printf("\n%s scored %d runs.\n\n", battingSecond, score2);

    // Announce the winner
    printf("--- Match Result ---\n");
    if (score1 > score2) {
        printf("%s wins by %d runs!\n", battingFirst, score1 - score2);
    } else if (score2 > score1) {
        printf("%s wins by %d balls remaining!\n", battingSecond, 6 - ball + 1);
    } else {
        printf("The match is a tie!\n");
    }

    return 0;
}