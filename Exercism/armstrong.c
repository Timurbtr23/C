#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>


bool is_armstrong_number(int candidate)
{
    // lenOfNum doen not work for 0
    if (candidate == 0) return 1;

    int candidate_copy = candidate;

    // nice way to find length of an integer
    int lenOfNum = floor(log10(abs(candidate))) + 1;
    int sum = 0;

    // nice way to take a numbers from an integer
    while(candidate_copy){
        sum += pow(candidate_copy % 10, lenOfNum);
        candidate_copy /= 10;
    }

    if (sum == candidate) return 1;
    else return 0;
}

int main(){
    is_armstrong_number(5);
    return 0;
}
