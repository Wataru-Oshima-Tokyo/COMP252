//
//  main.cpp
//  binarySearch_second
//
//  Created by Wataru Oshima on 2020/04/18.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include <stdlib.h>
#include <ctime>
#include <iostream>

using namespace std;

#define ARRAY_SIZE 1000

int main()

{

int arra[ARRAY_SIZE]; //array of thousand values

srand(time(0)); //initializing srand function with time

//filling array with thousand random values

for(int i=0;i<ARRAY_SIZE;i++)

    arra[i]=rand()%ARRAY_SIZE+1;

cout<<"\nList elements before sorting: "<<endl;

for(int i=0;i<ARRAY_SIZE;i++)

    cout<<arra[i]<<" ";

//sorting the array elements

for(int i=0;i<ARRAY_SIZE-1;i++)

for(int j=i+1;j<ARRAY_SIZE;j++)

{

if(arra[i]>arra[j])

{

int tmp=arra[i];

arra[i]=arra[j];

arra[j]=tmp;

}

}

cout<<"\n\nList elements after sorting: "<<endl;

for(int i=0;i<ARRAY_SIZE;i++)

cout<<arra[i]<<" ";

//Binary Search

cout<<"\n\nBinary Serach: "<<endl;

int searchElement;

cout<<"Enter Searching Element: ";

cin>>searchElement;

int min=0;

int max=ARRAY_SIZE-1;

int mid=(min+max)/2;

int flag=false;

int numOfComparisions=0;

int position;

while(min<=max)

{

if(arra[mid]==searchElement)

{

flag=true;

position=mid+1;

break;

}

else if(arra[mid]<searchElement)

min=mid+1;

else

max=mid-1;

numOfComparisions++;

mid=(min+max)/2;

}

if(flag)

cout<<endl<<searchElement<<" is found at "<<position<< " position"<<endl;

else

cout<<searchElement<<" is not found in the list"<<endl;

cout<<"Number of comparisions: "<<numOfComparisions<<endl;

//Sequential Search for sorted list

cout<<"\nSequential Search: "<<endl;

cout<<"Enter Searching Element: ";

cin>>searchElement;

numOfComparisions=0;

flag=false;

for(int i=0;i<ARRAY_SIZE;i++)

{

if(arra[i]==searchElement)

{

flag=true;

position=i+1;

break;

}

numOfComparisions++;

}

if(flag)

cout<<endl<<searchElement<<" is found at "<<position<< " position"<<endl;

else

cout<<searchElement<<" is not found in the list"<<endl;

cout<<"Number of comparisions: "<<numOfComparisions<<endl;

system("pause");

return 0;

}
