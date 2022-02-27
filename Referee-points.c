/*
Program that calculates the highest- lowest and average score among a given
amount of judgescores
By: Johanna Lindoff id19jlf
Date: 2019-10-14
*/

#include <stdio.h>

void printInfo (void);
int readJudges (void);
void readPoints (int judges, double scores[]);
void loadedScores (int judges, double scores[]);
void result (int judges, double scores[], double *highestScore,
            double *lowestScore, double *averageScore);
void finalScores (int judges, double scores[], double highestScore,
            double lowestScore, double averageScore);

int main(void) {

  double highestScore;
  double lowestScore;
  double averageScore;
  int judges;

  printInfo();

  judges = readJudges ();

  /* The number of elements in the array is as many as the judges */

  double scores[judges];

  readPoints (judges, scores);

  loadedScores (judges, scores);

  result (judges, scores, &highestScore, &lowestScore, &averageScore);

  finalScores (judges, scores, highestScore, lowestScore, averageScore);

  return 0;
}

/* Prints the program menu. */

void printInfo (void) {

  printf("Program information\n"
  "The program reads in the number of judges and the score from each judge.\n"
  "Then it calculates the average score without regard to the lowest and \n"
  "highest judge score. Finally it prints the results (the highest, the \n"
  "lowest and the final average score).\n\n");
}

/* Reads a given amount of judges that the user has choosen. */

int readJudges (void) {

  int judges;

  do {
    printf("Number of judges (min 3 and max 10 judges)? ");
    scanf("%d", &judges);
  } while (judges < 3 || judges > 10);

  printf("\n");

  return judges;
}

/* The user decides what score which judge gives and the data stores in the
array "scores[judges]"".
Input: Amount of judges and the array that consists of as many reserved
memoryplaces.
*/

void readPoints (int judges, double scores[]) {

  for (int i = 0 ; i < judges ; i++) {
    printf("Score from judge %d? ", i+1);
    scanf("%lf", &scores[i]);
  }
  printf("\n");
}

/* The function prints the loaded scores.
Input: Amount of judges and the array that consists of the judges
given scores. */

void loadedScores (int judges, double scores[]) {

  printf("Loaded scores:\n");
  for (int i = 0 ; i < judges ; i++) {
    printf("Judge %d: %.1lf \n", i+1, scores[i]);
  }
  printf("\n");
}

/* The resultfunction calculates the highest, lowest and the average scores
among the judges.
Input: Amount of judges, the array, and the adress to the variables
highestScore, lowestScore and averageScore.*/

void result (int judges, double scores[], double *highestScore,
            double *lowestScore, double *averageScore) {

  double sum = 0;
  *highestScore = scores[0];
  *lowestScore = scores[0];

  for (int i = 0; i < judges; i++) {
    if (scores[i] > *highestScore) {
      *highestScore = scores[i];
    }
    if (scores[i] < *lowestScore) {
      *lowestScore = scores[i];
    }
    sum = sum + scores[i];
  }
  *averageScore = (sum - *lowestScore - *highestScore) / (judges - 2);
}

/* Function which prints the min, max and average score. */

void finalScores (int judges, double scores[], double highestScore,
                  double lowestScore, double averageScore) {

  printf("Final result:\n");
  printf("Highest judge score: %.1lf\n", highestScore);
  printf("Lowest judge score: %.1lf\n", lowestScore);
  printf("Final average score: %.1lf\n", averageScore);
}
