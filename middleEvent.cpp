struct Event {
    int num;
    Event* next;
    Event() : num(0), next(nullptr) {}
    Event(int n) : num(n), next(nullptr) {}
    Event(int n, Event* next) : num(n), next(next) {}
};

// Traverse twice
// Time complexity: O(n)
// Space complexity: O(1)
Event* middleEvent(Event* firstEvent) {
    int len = 0;
    Event* curr = firstEvent;

    // iterate through the whole list to find its length
    while(curr) {
        curr = curr->next;
        ++len;
    }

    // iterate half of the list from the first event
    curr = firstEvent;
    for (int i = 0; i < len/2; ++i) {
        curr = curr->next;
    }
    return curr;
}

// Traverse once
// Time complexity: O(n)
// Space complexity: O(1)
Event* middleEvent(Event* firstEvent) {

	// making two pointers fast and slow and assignning them to first event
    Event* slow = firstEvent;
    Event* fast = firstEvent;

    // increment slow by 1 step and fast by 2 steps 
    // until fast or fast->next reaches null
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow would have travelled half the distance fast travelled
    return slow;
}