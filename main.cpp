#ifdef MAIN

#include "ABDQ.hpp"
#include "ABQ.hpp"
#include "ABS.hpp"
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include "LLDQ.hpp"
#include "LLQ.hpp"
#include "LLS.hpp"
#include <iostream>

/*
    - LEAVE THE IFDEF GUARDS TO KEEP YOUR MAIN WITHOUT CONFLICTING WITH GRADESCOPE!
    - Test your code in this main and run locally with the RunMain configuration in CLion, or
    through your own command line compilation. Make sure to add flag "-DMAIN" to your compilation so this
    main function can compile.

*/

int main() {


    ABQ<int> q;
    q.enqueue(1);
    //std::cout << q.dequeue() << std::endl;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
     for (int i = 0; i < 9; i++) {
         std::cout << q.dequeue() << std::endl;
     }
    //std::cout << q.peek() << std::endl;
    // ABQ<int> q;
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // std::cout << q.peek() << std::endl;



    return 0;
}


#endif