#ifndef DOG_H
#define DOG_H

/**
* struct dog - dog data structure
* @name: dog name
* @age: dog age
* @owner: dog owner
*
* Description: data structure for dog information
*/
struct dog
{
char *name;
float age;
char *owner;
};

/* function prototype */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

/**
* struct dog - defines a dog
* @name: name of the dog
* @age: age of the dog
* @owner: owner of the dog
*/

typedef struct dog
{
char *name;
float age;
char *owner;
} dog_t;

/* function prototypes */
void free_dog(dog_t *d);
void print_dog(dog_t *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif /* DOG_H */
