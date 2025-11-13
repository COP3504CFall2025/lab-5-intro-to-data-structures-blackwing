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


    ABS<int> q;
    q.push(3);
    q.push(2);
    q.push(1);
    q.pop();
    std::cout << q.peek() << std::endl;
    // ABQ<int> q;
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // std::cout << q.peek() << std::endl;



    return 0;
}


#endif