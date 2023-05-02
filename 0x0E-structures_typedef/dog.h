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

#endif /* DOG_H */
