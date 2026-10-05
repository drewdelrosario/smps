
#include <stdio.h>
#include <stdbool.h>
#include <string.h> // for strcpy to work
#include <stdlib.h> // for system("cls") to work

char subjects[10][30];
float scores[10];
int count = 0;


void greet() {
  printf(" ____   __  __  ____   ____  \n");
  printf("/ ___| |  \\/  ||  _ \\ / ___| \n");
  printf("\\___ \\ | |\\/| || |_) |\\___ \\ \n");
  printf(" ___) || |  | ||  __/  ___) |\n");
  printf("|____/ |_|  |_||_|    |____/ \n\n");
}

void options() {
  printf("1. View grades\n");
  printf("2. Add grade\n");
  printf("3. Remove grade\n");
  printf("4. Exit\n");
}

int prompt() {
  int res;
  printf("\nsmps> ");
  scanf("%d", &res);
  while (getchar() != '\n');
  return res;
}

void clear() {
  system("cls");
}

void view_grades() {
  if (count == 0) {
    printf("\nThe list is still empty.\n\n");
    return;
  }

  double total = 0;

  printf("\n%-25s %s\n", "Subject", "Grade");
  printf("%-25s %s\n", "-------", "-----");

  for (int i = 0; i < count; i++) {
    printf("%d. %-22s %.2f\n", i + 1, subjects[i], scores[i]);
    total += scores[i];
  }

  printf("\nAverage: %.2f\n\n", total / count);
}

void add_grades() {

   if (count == 10) {
    printf("\nThe list is already full.\n");
    return;
  }

  char subjectName[30];

  printf("Subject name: ");
  fgets(subjectName, sizeof(subjectName), stdin);
  subjectName[strcspn(subjectName, "\n")] = '\0';

  float grade;

  printf("Subject score: ");
  scanf("%f", &grade);

  strcpy(subjects[count], subjectName);
  scores[count] = grade;

  count++;

  printf("\nAdded successfully!\n");

  view_grades();

}

void remove_grade() {
  int n;
  view_grades();
  if (count == 0) return;

  printf("Enter number to remove: ");
  scanf("%d", &n);
  while (getchar() != '\n');

  if (n < 1 || n > count) {
    printf("Invalid number.\n");
    return;
  }

  // shift everything after it up by one
  for (int i = n - 1; i < count - 1; i++) {
    for (int j = 0; j < 30; j++) subjects[i][j] = subjects[i + 1][j];
    scores[i] = scores[i + 1];
  }
  count--;

  printf("\nRemoved successfully!\n");

  view_grades();
}

int main() {

  greet();

  bool ongoing = true;

  while (ongoing) {
    options();

    int res = prompt();

    switch (res)
      {
        case 1:
          clear();
          view_grades();
          break;

        case 2:
          clear();
          add_grades();
          break;

        case 3:
          clear();
          remove_grade();
          break;

        case 4:
          ongoing = false;
          printf("\nByee!\n\n");
          break;

        default:
          clear();
          printf("\nInvalid input\n");
          break;
      }
  }
}