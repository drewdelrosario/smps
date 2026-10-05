
#include <stdio.h>
#include <stdbool.h>

// Task 1: create a function that displays a greetings and the title of the project (SMPS)

void greet() {
  printf("=================\n");
  printf("    ESEMPIES     \n");
  printf("=================\n");
}

// Task 2: create a function that prompts the user to enter a command 

void options() {
  printf("\n1. View grade\n");
  printf("2. Add grade\n");
  printf("3. Remove grade\n");
  printf("4. Exit\n");
}

int prompt() {
  int res;
  printf(">> ");
  scanf("%d", &res);
  while (getchar() != '\n');
  return res;
}

// Task 3: create a loop to loop the process except the greet function because it should only display once


/* Task 4: create handler functions for specific commands
    commands:
      - show: show all availble commands
      - get average
      - get grades
      - set grade [subject] [score]
      - summarize

*/ 

// Task 5: catch unidentified commands entered by the user

int main() {
  // execution

  greet();

  bool ongoing = true;

  while (ongoing) {
    options();

    int res = prompt();

    switch (res)
      {
        case 1:
          printf("\nSample\n");
          break;

        case 2:
          printf("\nAdd\n");
          break;

        case 3:
          printf("\nRemove\n");
          break;

        case 4:
          ongoing = false;
          printf("\nByee!\n");
          break;

        default:
          printf("\nInvalid argument\n");
          break;
      }
  }

}