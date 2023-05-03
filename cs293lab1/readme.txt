                                                                                       *** CS 293 LAB1 ***
  LINEAR QUEUE:
  Elements jointer later in the queue have higher index than those joined earlier.
  so a simple array would do the job.
  But the problem arrises while using grow() function.
  the condition must be that all memory the array must be used 
  i.e, grow only when (head==0 && tail==N-1).keep rearranging the elements till tha space is used up.
  P.S. for IsFull() I considered only tail==N-1 but not head==0 because that makes code easier to make.
  Insert unless its full just copy the element in tail and increment the tail.
  although if its full grow (which contains both array growth and rearrangement)then do the similar.
  deletion is just setting the element to NULL and increment the head.
  CIRCULAR QUEUE:
  Elements in this array are placed in circular fashion.
  cleverly used simple array would solve this problem too.
  grow function is done by creating new array and copy elements in such a way that we have space between head and tail.
  now the inserted element goes after the tail and becomes the newtail.
  as its circular for increment its recommened to use "%N" instead of using multiple if conditions.
  IsFull() is when head==tail+1(although it fails when head==0 and tail==N-1)but that would be just a linear array.
  
