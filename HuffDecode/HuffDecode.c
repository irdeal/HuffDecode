//
//  main.c
//  HuffDecode
//
//  Created by Yong Hwan Ho on 2016. 7. 31..
//  Copyright © 2016년 Yong Hwan Ho. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int findfbranch(int , char *, int, int);
int StrNCpy (char *, char *, int, int);


int main(int argc, const char * argv[]) {
    // insert code here...
    char encode[200];
    char decode[200];
    char alltree[20][200];

    int testCount=0, maxnum=0, arity=0;
    int length=0;
    int i=0, j=0;
    int maxdepth = 0;
    int firstbranch = 0;
    
//    printf("Enter Test Count: ");
//    scanf("%d", &testCount);
    
    printf("Enter Max Number: ");
    scanf("%d", &maxnum);
    printf("Enter arity: ");
    scanf("%d", &arity);
    printf("Enter Decode string: ");
    scanf("%s", encode);
    
    length = (int)strlen(encode);
    
    maxdepth = (maxnum-1)/(arity-1);
    if ((maxnum-1)%(arity-1))
        maxdepth++;

    firstbranch = findfbranch(1, encode, length, arity);


    
    while (i<maxnum) {
        
        StrNCpy(encode, decode, i, 1);
        printf("%d -> %s\n", i,decode );
        i++;
    }

    printf("Test Count: %d\nMax Number : %d\nArity = %d\nEncode string = %s\nstring length=%d\nmaxdepth=%d\nfirstbranch=%d\n", testCount, maxnum, arity,encode, length, maxdepth, firstbranch);
    
    return 0;
}

int findfbranch(int depth, char * org, int length, int arity)
{
    int i=0;
    char decode[200];
    int count[200]={0,};
    int branch=0;
    int branchnum=0;
    
    while (i < length) {
        StrNCpy(org, decode, i, depth );
        count[atoi(decode)]++;
        i++;
    }
    
    i = 0;
   
    while (i<arity) {
        if ( branch < count[i])
        {
            branch = count[i];
            branchnum = i;
        }
        i++;
    }

    return branchnum;
        
}

int StrNCpy(char *org, char *dst, int start, int num)
{
    int i=0;
    while (i < num)
    {
        *(dst+i) = *(org+start+i);
        i++;
    }
    *(dst+i) = '\0';
    return 0;
}
