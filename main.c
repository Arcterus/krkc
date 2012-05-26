#include <stdio.h>
#include <stdlib.h>
#include "krcc.h"

int main(const int argc, const char *argv[]) {
  if(argc < 2) {
    fputs("Error: Too few arguments", stderr);
    return 1;
  }
  char files[1024][1024];
  int filenum = 0;
  Krcc parser = {"a.out", O2, true, false};
  int i;
  for(i = 0; i < argc; i++) {
    if(strcmp(argv[i], "-o") == 0) {
      if(++i < argc) {
	parser.output = argv[i];
      } else {
	fputs("Error: Missing output file name", stderr);
	return 1;
      }
    } else if(strcmp(argv[i], "-c") == 0) {
      parser.compile = false;
    } else if(strcmp(argv[i], "-O3") == 0) {
      parser.optimize = O3;
    } else if(strcmp(argv[i], "-Os") == 0) {
      parser.optimize = Os;
    } else if(strcmp(argv[i], "-Oz") == 0) {
      parser.optimize = Oz;
    } else if(strcmp(argv[i], "-O1") == 0) {
      parser.optimize = O1;
    } else if(strcmp(argv[i], "-O0") == 0) {
      parser.optimize = O0;
    } else if(strcmp(argv[i], "-O2") == 0) {
      parser.optimize = O2;
    } else if(strcmp(argv[i], "--preprocess-only") == 0) {
      parser.preprocess = true;
    } else {
      if(filenum <= 1024) {
	if(sizeof(argv[i]) <= 1024) {
	  strcpy(files[filenum++], argv[i]);
	} else {
	  fprintf(stderr, "Error: File name too long (%s greater than 1024)\n", argv[i]);
	  return 1;
	}
      } else {
	fputs("Error: Too many input files (over 1024)", stderr);
	return 1;
      }
    }
  }
  return 0;
}
