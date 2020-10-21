class ParkingSystem {
public:
    int bigC, smallC, mediumC;
    int countb, countm, counts;
    ParkingSystem(int big, int medium, int small) {
        bigC = big;
        mediumC = medium;
        smallC = small;
        countb = 0;
        countm = 0;
        counts = 0;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
           if(countb < bigC){
                countb++;
                return true;
            }
            else
                return false;
        }
        else if(carType == 2){
           if(countm < mediumC){
                countm++;
                return true;
            }
            else
                return false;
        }
        else if(carType == 3){
           if(counts < smallC){
                counts++;
                return true;
            }
            else
                return false;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */