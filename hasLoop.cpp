#include <unordered_set>

struct Tunnel {
    int num;
    Tunnel* next;
    Tunnel() : num(0), next(nullptr) {}
    Tunnel(int n) : num(n), next(nullptr) {}
    Tunnel(int n, Tunnel* next) : num(n), next(next) {}
};

// Time complexity: O(n)
// Space complexity: O(n)
bool hasLoop(Tunnel* entrance) {
    std::unordered_set<Tunnel*> tunnels;
    Tunnel* curr = entrance;
    while(curr) {
        // A loop is found if there is a repeating tunnel node
        if(tunnels.find(curr) != tunnels.end())
            return true;
        tunnels.insert(curr);
        curr = curr->next;
    } 
    return false;
}

// Time complexity: O(n)
// Space complexity: O(1)
bool hasLoop(Tunnel* entrance) {
	// making two pointers fast and slow and assignning them to entrace
    Tunnel* slow = entrance;
    Tunnel* fast = entrance;

    // we will increment fast by 2 steps and slow by 1 step 
    // as long as they do not reach null
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // if both are at the same address, there would've been a cycle 
        if(slow == fast) {
            return true;
        }
    }
    return false;
}
