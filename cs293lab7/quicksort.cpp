#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

#ifndef STD_HEADERS
#include "std_headers.h"
#endif

#ifndef PLANNER_H
#include "planner.h"
#endif

#ifndef DICTIONARY_H
#include "dictionary.h"
#endif

#ifndef CODES_H
#include "codes.h"
#endif

// If you are using the updated planner.cpp, then you simply need to
// sort the list of TrainInfoPerStation objects in stnInfoList.  The
// function that calls Quicksort in planner.cpp (i.e. printStationInfo)
// will then automatically pretty-print the sorted list.
//
// USING THE UPDATED planner.cpp FILE IS STRONGLY RECOMMENDED
//
// Notice that there is a variable K in Quicksort that is to be used as
// described in the problem statement in problems_statement.pdf
// Specifically, if the first call to Quicksort has an argument list of
// n TrainInfoPerStation objects, you can't use additional storage space
// for more than n/K TrainInfoPerStation objects overall (across all
// recursive calls), you must implement random choice for pivot (i.e.
// each element in the list being sorted should be equally likely to
// be chosen as pivot), and each call to finding a random pivot
// within the list being sorted must take time within O(K), regardless
// of how long the list to be sorted is.
//
// In the function signature of Quicksort, stnInfoList is a list of
// TrainInfoPerStation objects that is to be sorted. In the updated
// planner.cpp file, this list (unsorted) is already prepared for you,
// and you need to simply ensure that the list is sorted (see note
// below about sorting order) when Quicksort returns.
//
// A note about the sorting order:
//
// The final list should be sorted with respect to day of week (first)
// and departure time within the day (next).  Thus Sun 900 < Sun 1100
// < Mon 800 < Thu 700 < Fri 1200
//
//
// Based on how we saw some of you were trying to approach the problem
// in the lab of Sep 23, we are providing another function QuicksortSimple
// with a slightly extended signature. In addition to the list stnInfoList,
// which is passed as the first argument to QuicksortSimple, there are two
// integer parameters "start" and "end", just like in the usual Quicksort
// of an array (as in Prof. Naveen Garg's lectures, for example).
// How do we interpret these "start" and "end" variables in this case,
// when we are trying to sort a list?
// Well, here is one way of thinking about this: If we start
// counting elements of the list starting from stnInfoList and
// chasing "next" pointers until nullptr is reached, the corresponding
// elements can be thought of as elements of a (virtual) array indexed
// from 0 onwards.
// Then, the call to Quicksort must sort the part of the list
// consisting of elements at indices start, start+1, ... until end
// of the above virtual array.
// The whole point of this assignment is to have you do this without
// converting the whole list to an array.
//
// Remember it is indeed possible to solve this problem using the
// function Quicksort with only stnInfoList as its argument.  However,
// if you are finding it difficult to implement Quicksort, you can
// implement QuicksortSimple instead.  Those who implement both
// Quicksort and QuicksortSimple potentially stand to gain some bonus
// points.
bool isLessthan(TrainInfoPerStation* a,TrainInfoPerStation* b){
  for(int i=0;i<7;i++){
    if(a->daysOfWeek[i]||b->daysOfWeek[i]){
      if(!(a->daysOfWeek[i]&&b->daysOfWeek[i])){
        if(a->daysOfWeek[i]){return true;}
        else return false;
      }
      else{
        if(a->arrTime<=b->arrTime){return true;}
        else return false;
      }
    }
  }
}
int Length(listOfObjects<TrainInfoPerStation *> *stnInfoList){
  int N=0;
  listOfObjects<TrainInfoPerStation *> *currNode = stnInfoList;
  while(currNode!=nullptr){
    currNode=currNode->next;
    N++;
  }
  return N;
}
listOfObjects<TrainInfoPerStation*>* get(listOfObjects<TrainInfoPerStation *> *stnInfoList,int l){
 listOfObjects<TrainInfoPerStation *> *currNode = stnInfoList;
 while(l!=0){
    currNode=currNode->next;
    l--;
  }
  return currNode;
}
listOfObjects<TrainInfoPerStation*>**  Preprocess(listOfObjects<TrainInfoPerStation *> *stnInfoList){
  listOfObjects<TrainInfoPerStation*>** arr;
  int K=4;
  int N=Length(stnInfoList);
  int i=0;
  int j=0;
  listOfObjects<TrainInfoPerStation *> *currNode = stnInfoList;
  arr = new listOfObjects<TrainInfoPerStation*>* [(N-1/K)+1];
  while(currNode!=nullptr){
    if(j%K==0){*(arr+i)=(currNode);i++;}
    j++;
    currNode=currNode->next;
  }
  return arr;
}

void Planner::Quicksort(listOfObjects<TrainInfoPerStation *> *stnInfoList)
{
  // A few static variable declarations
  static int K = 4; // Parameter to be experimented with
  static int recursionLevel = -1; // This can be used to find out at which
                                  // level of the recursion you are in

  // Increment recursion level on entering the function
  recursionLevel++;
  
  // If you need to set up additional storage (upto n/K TrainInfoPerStation
  // elements), it's ok to do it *once* using static variables/array.
  // Using the static recursionLevel, you can ensure that the storage
  // allocation is done only the first time Quicksort is called, and not
  // in every recursive call.
  //
  // Note that if you allocate space for upto n/K TrainInfoPerStation in
  // each recursive call, you will end up using much more than n/K space
  // overall.  So you MUST NOT allocate space in each recursive call.
  //
  // A variable/array defined using static is not created afresh in
  // each recursive call.  Instead, a single copy of it is maintained
  // across all recursions.
  
  if (recursionLevel == 0) {
    // Find length of the list stnInfoList, if needed.
    // Allocate additional space for upto n/K TrainInfoPerStation objects
    // if needed.
    // Do other things that you may want to do only at the beginning
    // as a pre-processing step.
    
  }
  
  // Put your code for the core of Quicksort here

  // Decrement recursion level before leaving the function
  recursionLevel--;
  return;
}
listOfObjects<TrainInfoPerStation*>* choosePivot( int start, int end,listOfObjects<TrainInfoPerStation*>** arr){
    int N = start + rand()%(end-start+1);
    listOfObjects<TrainInfoPerStation*>* curr;
    int K=4;
    int rem = N%K;
    int q = N/K;
    curr = arr[q];
    while(rem != 0){
      curr = curr->next;
      rem--;
    }
    return curr;

}
int Partition(listOfObjects<TrainInfoPerStation *> *stnInfoList,int start, int end,listOfObjects<TrainInfoPerStation*>** arr)
{
    // Call appropriate pivot function based on choice
    listOfObjects<TrainInfoPerStation*> *pivot;
    listOfObjects<TrainInfoPerStation*> *temp;
    pivot = choosePivot(start,end,arr);
    temp = new listOfObjects<TrainInfoPerStation*> (pivot->object);
    int i=start;
    int j=end;
    listOfObjects<TrainInfoPerStation*>* tail = get(stnInfoList,end);
    listOfObjects<TrainInfoPerStation *> *head = get(stnInfoList,start);

    while(true){
    // compare and swap the elements
        while(!(isLessthan(temp->object,head->object))){head=head->next;i++;}
         while(!(isLessthan(tail->object,temp->object))){tail=tail->prev;j--;}
        if(i<j) {
            TrainInfoPerStation* t;
            t=head->object;
            head->object=tail->object;
            tail->object=t;
        }
        else return j;}
    // Split into 2 parts based on pivot choice
    // Recursively keep sorting
}
void Planner::QuicksortSimple(listOfObjects<TrainInfoPerStation *> *stnInfoList, int start, int end)
{
  // A few static variable declarations
  static int K = 4; // Parameter to be experimented with
  static int recursionLevel = -1; // This can be used to find out at which
                                  // level of the recursion you are in

  // Increment recursion level on entering the function
  recursionLevel++;
  
  // If you need to set up additional storage (upto n/K TrainInfoPerStation
  // elements), it's ok to do it *once* using static variables/array.
  // Using the static recursionLevel, you can ensure that the storage
  // allocation is done only the first time Quicksort is called, and not
  // in every recursive call.
  //
  // Note that if you allocate space for upto n/K TrainInfoPerStation in
  // each recursive call, you will end up using much more than n/K space
  // overall.  So you MUST NOT allocate space in each recursive call.
  //
  // A variable/array defined using static is not created afresh in
  // each recursive call.  Instead, a single copy of it is maintained
  // across all recursions.

  
  static listOfObjects<TrainInfoPerStation*>** arr;
  if (recursionLevel == 0) {
    // Allocate additional space for upto n/K TrainInfoPerStation objects
    // if needed.
    // Do other things that you may want to do only at the beginning
    // as a pre-processing step.
    arr = Preprocess(stnInfoList);
  }

  
  // Put your code for the core of QuicksortSimple here

  // Decrement recursion level before leaving the function

  if (start<end){
    int q;
    q=Partition(stnInfoList,start,end,arr);
if(q<end){
    QuicksortSimple(stnInfoList,start,q);
    QuicksortSimple(stnInfoList,q+1,end);}
else{
    QuicksortSimple(stnInfoList,start,q-1);
    QuicksortSimple(stnInfoList,q,end);
}
}
  recursionLevel--;
  return;
}

#endif
