/*
Link: https://leetcode.com/problems/design-parking-system/
Problem: 1603. Design Parking System
*/

typedef struct {
    int big, medium, small;
    
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *obj = calloc(1, sizeof(ParkingSystem));
    obj->big = big;
    obj->medium = medium;
    obj->small = small;
    
    return obj;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    switch(carType){
        case 1: // Big
            if (obj->big <= 0){
                return false;
            }

            obj->big--;
            break;
        case 2: // Medium
            if (obj->medium <= 0){
                return false;
            }

            obj->medium--;

            break;
        case 3: // Small
            if (obj->small <= 0){
                return false;
            }

            obj->small--;

            break;
        default:
            assert(0);
    }
    
    return true;
  
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/