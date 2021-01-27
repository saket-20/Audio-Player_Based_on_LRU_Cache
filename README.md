# Audio-Player_Based_on_LRU_Cache
Queue based audio Player which creates and plays a playlist based on the LRU cache principle
LRU cache is implemented using a queue and hashmap. A doubly linked list is used to implement the queue.Doubly linked list allows fast insertion and deletion of queue nodes.
The hash has page number as a key and the address of the corresponding queue node as the value.
The queue is updated based on the principle of LRU cache.
Hash is used for O(1) complexity (while retrieving and inserting values at a particular key).
A playlist is generated based on the final contents of the cache and audio is played.
Only Audio stored in the computer's memory is supported to be played.
The file location must be provided at the appropriate location in the program(in lines 233-271)
