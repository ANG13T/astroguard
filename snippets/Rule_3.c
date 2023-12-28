/*
 NASA JPL Rule #3:
 Avoid heap memory allocation. There shall be no use of dynamic memory allocation after task initialization.
 Specifically, this rule disallows the use of malloc(), sbrk(), alloca(), and similar routines, after task initialization.
 Heap memory allocation occurs when you have.

 The reason for this rule is to remove the use of memory allocators and garbage collectors, as they have unpredictable behavior which can hinder performance.
 Moreover, lots of programming errors stem from mishandled memory allocation and free routines.
 - Forgetting to use memory
 - Attempting to allocate more memory after it is freed
 - Using stray pointers

 To eliminate these issues, one can make a memory environment that is fixed and pre-allocated

 Conceptual Overview:
 A heap is where dynamic memory allocation takes place.
 Memory in a heap is assigned / deallocated in an undefined and random order
 .
 Static vs Dynamic:
 - static memory allocation is when the program is being executed, memory cannot be changed. This memory is assigned when the program is compiled.
 - dynamic memory allocation is when a program is being executed, memory CAN be changed. This memory is assigned during the program run time.

 When a program is being executed, a set of memory is assigned depending on the requirements of the program.

 When the program is complete, the memory is released and is usable again for another operation.

*/


// SNIPPETS of Code Demonstrating Instances of Dynamic Memory Allocation in C
// Dynamic Memory allocation occurs when a size of a data structure (ie. array) is modified during runtime

// malloc (Memory Allocation) - allocates a single block of memory for a purpose
// this creates one large chunk block of memory
void malloc_example(int value) {
  int* ptr; // pointer for the base address of the block initiated
  ptr = (int*) malloc(value * sizeof(int)); // sizeof(int) = 4 bytes to carry each integer
  if (ptr == NULL) {
    printf("Memory not allocated.\n");
  } else {
    printf("Memory allocated.\n");
  }
}

// calloc (Contiguous Allocation) - dynamically allocate the specified number of blocks of memory of the specified type. It places a default value of 0 for each block of memory
// this creates segmented chunks of memory with preconfigured values
void calloc_example(int value) {
  int* ptr; // pointer for the base address of the block initiated
  ptr = (int*) calloc(value * sizeof(int));
  if (ptr == NULL) {
    printf("Memory not allocated.\n");
  } else {
    printf("Memory allocated.\n");
  }
}

// free (frees / deallocates memory)
void free_example(int value) {
  int *ptr, *ptr1;
  ptr = (int*) malloc(value * sizeof(int));
  ptr1 = (int*) calloc(value * sizeof(int));

  if (ptr == NULL or ptr1 == NULL) {
    printf("Memory not assigned");
    exit(1);
  } else {
    printf("Memory assigned!");
  }
  free(ptr);
  printf("Freed first chunk of memory");
  free(ptr1);
  printf("Freed second chunk of memory");
}

// realloc (Reallocates memory)
// when memory is reallocated, the previous stored memory is maintained and new blocks contain the default garbage value
void realloc_example(int value, int new_value) {
  int* ptr;
  ptr = (int*)calloc(value, sizeof(int));
  if (ptr == NULL) {
    printf("Memory not allocated.\n");
    exit(1);
  } else {
    printf("Memory allocated.\n");
  }
  ptr = (int*)realloc(ptr, new_value * sizeof(int));
  if (ptr == NULL) {
    printf("Memory not reallocated.\n");
    exit(1);
  } else {
    printf("Memory reallocated.\n");
  }

}

// alloca (allocates a specified number of bytes of memory from the stack frame)
// allocated memory is automatically deallocated when the function exits
void alloca_example(int value) {
  int* dynamicArray = (int*)alloca(5 * sizeof(int));
  printf("Memory allocated!");
  // Memory is automatically deallocated when the function exits
}

// sbrk (Aadjusts the program's data space (heap) by incrementing it by a specified number of bytes)
// this is typically used for low level memory management
void sbrk(int value) {
  // Increment the program's data space (heap) by 100 bytes
  void* newHeapSpace = sbrk(100);
  printf("Incremented program's data space by 100 bytes!");
}

// SNIPPETS Demonstrating Memory Leaks in C


int main() {
}
