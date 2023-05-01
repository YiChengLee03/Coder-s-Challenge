#include <iostream>
#include <unordered_set>

struct Plant {
    char* species = new char[50];
    Plant* ancestor;
    Plant() : species("0"), ancestor(nullptr) {}
    Plant(char* species) : species(species), ancestor(nullptr) {}
    Plant(char* species, Plant* ancestor) : species(species), ancestor(ancestor) {}
    ~Plant() { delete[] species; }
};

// Set solution 
// Time complexity: O(n)
// Space complexity: O(n) 
Plant* findCommonAncestor(Plant* plantA, Plant* plantB) {
    std::unordered_set<Plant*> ancestors;
    Plant* currA = plantA;
    Plant* currB = plantB;
    while (currA || currB) {
        if (currA) {
            if (ancestors.find(currA) != ancestors.end())
                return currA;
            else 
                ancestors.insert(currA);
            currA = currA->ancestor;
        }

        if (currB) {
            if (ancestors.find(currB) != ancestors.end()) 
                return currB;
            else 
                ancestors.insert(currB);
            currB = currB->ancestor;
        }
    }
    return nullptr;
}

// Length difference solution
// Time complexity: O(n)
// Space complexity: O(1)
Plant* findCommonAncestor(Plant* plantA, Plant* plantB) {
    Plant* currA = plantA;
    Plant* currB = plantB;
    int lengthA = 0, lengthB = 0;
    
    while(currA) {
        currA = currA->ancestor;
        ++lengthA;
    }
    
    while(currB) {
        currB = currB->ancestor;
        ++lengthB;
    }

    currA = plantA;
    currB = plantB;
    if(lengthA > lengthB) {
        for(int i = 0; i < lengthA-lengthB; ++i)
            currA = currA->ancestor;
    } else if (lengthB > lengthA) {
        for(int i = 0; i < lengthB-lengthA; ++i)
            currB = currB->ancestor;
    }
    while(currA) {
        if(currA == currB) return currA;
        currA = currA->ancestor;
        currB = currB->ancestor;
    }
    return nullptr;
}

// Two pointer solution 
// Time complexity: O(n) 
// Space complexity: O(1)
Plant* findCommonAncestor(Plant* plantA, Plant* plantB) {
    Plant* currA = plantA;
    Plant* currB = plantB;
    while(currA != currB) {
        currA = currA->ancestor ? currA->ancestor : plantA;
        currA = currB->ancestor ? currB->ancestor : plantB;
    }
    return currA;
}