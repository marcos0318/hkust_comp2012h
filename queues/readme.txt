/**********************************************************************
 *  Randomized Queues and Deques
 **********************************************************************/

Name: BAI Jiaxin
ID:20327648
Login: jbai
Hours to complete assignment (optional):


/**********************************************************************
 *  Explain briefly how you implemented the randomized queue and deque.
 *  Which data structure did you choose (array, linked list, etc.)
 *  and why?
 **********************************************************************/
PUT YOUR ANSWER HERE

linked list for deque
array for randomized queue

Because we need deque to be like that each iteration operation (including construction) in constant worst-case time, and use a constant amount of extra space per iterator.
 
Because we need rand queue to have properties that each randomized queue operation (besides creating an iterator) in constant amortized time and use space proportional to number of items currently in the queue.


/**********************************************************************
 *  Briefly describe why any sequence of N randomized queue operations,
 *  starting from an empty randomized queue, takes O(N) time.
 **********************************************************************/
PUT YOUR ANSWER HERE
because we need to resize the capacity twice when it is full. we can culculate that it is O(N)



/**********************************************************************
 *  Briefly describe why each Deque operation takes O(1) time.
 **********************************************************************/
PUT YOUR ANSWER HERE

Because not matter where it is, when remove or add we just to manipulate the list;


/**********************************************************************
 *  How much memory (in bytes) does your data type use to store N items.
 *  Use tilde notation to simplify your answer. Use the memory requirements
 *  for a "typical machine" given in Lecture. In your analysis, don't include
 *  the memory for the items themselves (as this memory is allocated by
 *  the client and depends on the item type.
 *  For a typical machine, refer to page 11 of 
 *  http://www.cs.princeton.edu/courses/archive/spring10/cos226/lectures/02-14Analysis-2x2.pdf 
 **********************************************************************/

RandomizedQueue:

Dequeue:




/**********************************************************************
 *  Known bugs / limitations.
 **********************************************************************/

some warning when conpiling

/**********************************************************************
 *  List whatever help (if any) that you received and from whom,
 *  including help from staff members or lab TAs.
 **********************************************************************/
with the help of some website.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
The implementation of the rand queue is very hard to think of a way.



/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
