#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct person
{
    char alleles[2];
    struct person *parents[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;
person *create_family(int generations);
void free_family(person *p);
void print_family(person *p, int generation);
char random_allele();


int main(void)
{
    // Seed random number generator
    srand(time(0));
    
    // Create and print family tree
    person *p = create_family(GENERATIONS);
    print_family(p, 0);
    
    // Free memory
    free_family(p);
    return 0;
}

// create a new individual with 'generations'
person *create_family(int generations)
{
    // Allocate memory for new person
    person *new_person = malloc(sizeof(person));
    if (new_person == NULL)
    {
        return NULL;
    }

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // Set parent pointers for current person
        new_person->parents[0] = parent0;
        new_person->parents[1] = parent1;

        // Randomly assign current person's alleles based on the alleles of their parents
        new_person->alleles[0] = parent0->alleles[rand() % 2];
        new_person->alleles[1] = parent1->alleles[rand() % 2];
    }
    else
    {
        // Set parent pointers to NULL
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        // Randomly assign alleles
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    // Return newly created person
    return new_person;
}

void free_family(person *p)
{
    // handle base case
    if (p == NULL)
    {
        return;
    }
    // free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    // free child
    free(p);
}

void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }
    // print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // print current person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    
    // print parents recursively
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}