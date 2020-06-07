# CPP-Memory-Leaks

# Walkthrough video
https://www.youtube.com/watch?v=j4dFhyNQe-8&t=523s

## Memory Leaks
    - No deallocation of allocated memmory in heap using new or delete
    - Using wrong delete where delete[] has to be used
    - Allocation a new memory to a pointer without free the memory it owns
    - Assigning a new address to a pointer who is the only pointer holding address to an allocated memory
    - Not having virtual destructor for base class
    - Not having implemented copy constructor and assignment operator (also refer rule of three)

## How to prevent memory leaks
    - Use delete and free sparingly by making use of smart pointer unique_ptr , shared_ptr and weak_ptr
    - If you have to do your own dynamic memory allocation, write new and delete always pairwise
    - You can prevent dynamic allocation by using classes like stl containers which take care of RAII. eg: use std::vector<char> buff(size,'') instead of char* buff = new char[size]
    - If a variable is only used as a local variable inside a function and the value of the local variable is not returned or passed to outside the function, then it would be better to simply use stack memory
    - Always be aware of ownership of object: who owns, who refers, who is responsible to free the memmory
    - Define the destructor of base class as virtual. So all derived classes referred by pointer to the base class get deleted
    - Define copy and assignment operator when you need deep copy to happen
    
## References :
https://ptolemy.berkeley.edu/ptolemyclassic/almagest/docs/prog/html/ptlang.doc7.html#:~:text=Memory%20leaks%20occur%20when%20new,or%20the%20delete%20%5B%5D%20operator.
http://www.yolinux.com/TUTORIALS/C++MemoryCorruptionAndMemoryLeaks.html
https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)#:~:text=The%20rule%20of%20three%20(also,copy%20assignment%20operator

