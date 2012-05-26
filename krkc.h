#ifndef _KRCC_H
#define _KRCC_H

typedef enum {
  O0 = 0, // no optimization
  O1, // little optimization (speed and size)
  O2, // average optimization (speed and size)
  O3, // lots of optimization (speed)
  Os, // lots of optimization (size)
  Oz // huge amount of optimization (size)
} OpLevel;

#ifndef _cplusplus
typedef enum {
  false = 0,
  true = !0
} Bool;

/*#define false 0
  #define true !0*/
#else
typedef bool Bool;
#endif // _cplusplus

typedef struct {
  char *output; // compiler output file
  OpLevel optimize; // compiler optimization level
  Bool link; // link object files together (true), or leave them as .o files (false)
  Bool preprocess; // only preprocess (true), or preprocess and compiler (false)
  Bool (*compile)(const char *code);
  Bool (*compileFile)(const char *filename);
  char *(*parse)(const char *code);
  char *(*parseFile)(const char *filename);
} Krcc;

#endif
