/*****************************************************************************
* Program:  RANDOM.CPP
* Purpose:  generates random values so random squares can be selected and
*           a random face on that random square.
*****************************************************************************/
#include "random.hpp"


/*****************************************************************************
* Function: perm
* Parms:    none
* Purpose:  generates an array representing a random order of squares
* Returns:  nothing
*****************************************************************************/
void Random::perm()
{
   /******************************************************
   ** This function will populate the cube_array with
   ** 16 random integers which represent a random cube
   ** order for the game.
   ******************************************************/
   time_t t;
   int rand_cube, temp_val, i = 0;

   /******************************************************
   ** Initialize the array from 1-16.
   ******************************************************/
   for (i = 0; i < 16; i++)
      cube_array[i] = i + 1;

   srand( (unsigned) time(&t) );             // grab current time
   for (int perm = 16; perm > 0; perm--)
   {
      rand_cube = (rand() % perm);           // generate random number

      temp_val = cube_array[perm-1];         // save the value of last
                                             //  element.
      /******************************************************
      ** This will swap the last index in the array with
      ** the randomly selected index.
      ******************************************************/
      cube_array[perm-1] = cube_array[rand_cube];
      cube_array[rand_cube] = temp_val;
   }
}

/*****************************************************************************
* Function: getValue
* Parms:    k - the array element you wish to query
* Purpose:  returns the value from the cube array
* Returns:  the array element you wish to query
*****************************************************************************/
int  Random::getValue(int k)
{
   return(cube_array[k] - 1);
}

