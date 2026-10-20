class ParkingSystem {
public:
    int big, med, small;
    ParkingSystem(int b, int medium, int s) {
        big = b, med = medium, small = s;
    }

    bool addCar(int carType) {
        if (carType == 1 && big > 0) {
            big--;
            return true;

        } else if (carType == 2 && med > 0) {
            med--;
            return true;

        } else if (carType == 3 && small > 0) {
            small--;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */