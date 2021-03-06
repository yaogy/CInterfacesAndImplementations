#pragma once

#include <stdio.h>

#include "Except\Except.h"

//exceptions 51
const Except_T Mem_Failed;

//funcions 51
void * Mem_alloc(long nbytes, const char *file, int line);
void * Mem_calloc(long count, long nbytes, const char *file, int line);
void Mem_free(void *ptr, const char *file, int line);
void * Mem_resize(void *ptr, long nbytes, const char *file, int line);
// excercise 5.4
FILE *log_file;
void Mem_log(FILE *log);
// excercise 5.5
void Mem_leak(void apply(const void *ptr, long size, const char *file, int line, void *cl), void *cl);

//macros 51
#define ALLOC(nbytes) Mem_alloc((nbytes), __FILE__, __LINE__)
#define CALLOC(count, nbytes) Mem_calloc((count), (nbytes), __FILE__, __LINE__)
#define NEW(p) ((p) = ALLOC((long)sizeof(*(p))))
#define NEW0(p) ((p) = CALLOC(1, (long)sizeof(*(p))))
#define FREE(ptr) ((void) (Mem_free((ptr), __FILE__, __LINE__), (ptr) = 0))
#define RESIZE(ptr, nbytes) ((ptr) = Mem_resize((ptr), (nbytes), __FILE__, __LINE__))