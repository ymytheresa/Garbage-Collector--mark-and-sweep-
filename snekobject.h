#include <stdbool.h>
#include <stddef.h>

typedef struct SnekObject snek_object_t; //means we will implement later

int snek_length(snek_object_t *obj);
snek_object_t *snek_add(snek_object_t *a, snek_object_t *b);

typedef struct {
  size_t size;
  snek_object_t **elements;
} snek_array_t;

typedef struct { //anonymous just to keep the codoe slightly more concise, no use case difference with named one
  snek_object_t *x; //true that we hvnt implemented the structure yet but the size of address always same so its fine
  snek_object_t *y;
  snek_object_t *z;
} snek_vector_t;

typedef enum SnekObjectKind {
  INTEGER,
  FLOAT,
  STRING,
  VECTOR3,
  ARRAY,
} snek_object_kind_t;

typedef union SnekObjectData {
  int v_int;
  float v_float;
  char *v_string;
  snek_vector_t v_vector3;
  snek_array_t v_array;
} snek_object_data_t;

typedef struct SnekObject {
  snek_object_kind_t kind;
  snek_object_data_t data;
} snek_object_t;

snek_object_t *new_snek_integer(int value);
snek_object_t *new_snek_float(float value);
snek_object_t *new_snek_string(char *value);
snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z
);

snek_object_t *new_snek_array(size_t size);

bool snek_array_set(snek_object_t *array, size_t index, snek_object_t *value);

snek_object_t *snek_array_get(snek_object_t *array, size_t index);
