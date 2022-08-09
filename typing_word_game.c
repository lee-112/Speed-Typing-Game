//  The purpose of the game is to test the users typing speed.
//  The program will track the amount of time it takes the user
//  to correctly type each of the nine words. The program will
//  display each word one at a time in a random order.


#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


// Search through the index array for a match
int getRandom(int index[], int size, int match);

// Set a random number for each array index
int setRandom(int * index, int size, int set);

// Set each array index to -1
void setIndex(int * index, int size);




int main()
{
    // Create a 2D array of 'strings' for the word bank
    char words[9][9] = { "The", "quick", "brown","fox","jumps","over","the","lazy","dog"};


    // Create an array of index values and set it to -1
    int index[9];
    setIndex(index, 9);
    struct timeval start, stop, results;


    printf("This is a game that tests typing speed");
    printf("\nType the following words:\n");


    // Create a new seed for rand() and get the starting time
    srand(time(NULL));
    gettimeofday(&start,NULL);


    // loop through the array of words
    for(int i = 0; i < 9; i++)
    {
        int indexPos = 0;       // Track the current index position
        char userInput[9];      // Get the users word input


        // Get a random index number for the word array
        shuffle_index:
            indexPos = rand() % 9;


        // Shuffle index numbers, or Set a random index number
        if(getRandom(index, 9, indexPos))
            goto shuffle_index;
        else
            setRandom(index, 9, indexPos);


        // Display the word and collect user input
        retype_word:
            printf("word #%d is %s: ", i+1, words[indexPos]);
            if(scanf("%s", userInput) == 1);


        // Compare user input
        if(strcmp(userInput, words[indexPos]) != 0)
            goto retype_word;
    }

    // Get the stoping time
    gettimeofday(&stop, NULL);


    // Get and display the users time results
    timersub(&stop, &start, &results);
    printf("----------------------------------------------\n");
    printf("You took %ld seconds and %ld microseconds\n", results.tv_sec, results.tv_usec);

    return 0;
}




// Search through the index array for a match
int getRandom(int index[], int size, int match)
{
    for(int i = 0; i < size; i++)
    {
        if(index[i] == match)
            return 1;
    }
    return 0;
}


// Set a random number for each array index
int setRandom(int * index, int size, int set)
{
    for(int i = 0; i < size; i++)
        if(index[i] == -1)
        {
            index[i] = set;
            return 1;
        }
    return 0;
}


// Set each array index to -1
void setIndex(int * index, int size)
{
    for(int i = 0; i < size; i++)
        index[i] = -1;
}
