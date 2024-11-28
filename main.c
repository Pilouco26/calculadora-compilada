#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "funcions.h"

int main(int argc, char *argv[]) {
  int error;
  FILE *file_ca3;

  // Call open_file_ca3 at the start and store the FILE pointer
  file_ca3 = open_file_ca3();

  if (argc == 3) {
    error = init_analisi_lexica(argv[1]);

    if (error == EXIT_SUCCESS) {
      error = init_analisi_sintactica(argv[2]);

      if (error == EXIT_SUCCESS) {
        error = analisi_semantica();

        if (error == EXIT_SUCCESS) {
          printf("The compilation has been successful\n");
        } else {
          printf("ERROR\n");
        }

        error = end_analisi_sintactica();
        if (error == EXIT_FAILURE) {
          printf("The output file cannot be closed\n");
        }

        error = end_analisi_lexica();
        if (error == EXIT_FAILURE) {
          printf("The input file cannot be closed\n");
        }
      } else {
        printf("The output file %s cannot be created\n", argv[2]);
      }
    } else {
      printf("The input file %s cannot be opened\n", argv[1]);
    }
  } else {
    printf("\nUsage: %s INPUT_FILE OUTPUT_FILE\n", argv[0]);
  }

  // Call close_file_ca3 at the end, passing the FILE pointer
  close_file_ca3(file_ca3);

  return EXIT_SUCCESS;
}
