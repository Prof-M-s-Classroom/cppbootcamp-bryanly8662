#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the Robot class
class Robot {
private:
    string name;
    string model;
    int batteryLife;

public:
    // Constructor
    Robot(string n, string m, int b):name(n),model(m),batteryLife(b) {}

    // Getter Methods
    string getName() { return name; }
    string getModel() { return model; }
    int getBatteryLife() { return batteryLife; }

    // Setter Methods
    void setName(string n) { name = n; }
    void setModel(string m) { model = m; }
    void setBatteryLife(int b) { batteryLife = b; }

    // Display function
    void displayRobot() {
        cout << "Robot: " << name << " | Model: " << model << " | Battery Life: " << batteryLife << "%\n";
    }
};

// Step 2: Function to modify robot (pass by value)
// subtracts 50 battery life from robot
void modifyRobotbyValue(Robot robot) {
    robot.setBatteryLife(robot.getBatteryLife() - 50);
    robot.displayRobot();

}

// Step 3: Function to modify robot (pass by reference)
// subtracts 50 battery life from robot passed by reference
void modifyRobotbyReference(Robot &robot) {
    robot.setBatteryLife(robot.getBatteryLife() - 50);
    robot.displayRobot();

}


// Step 4: Template class for a Fleet that stores multiple robots
template <typename T>
class Fleet {
private:
    T* robots;
    int capacity;
    int count;

public:
    // Constructor: Allocates space for 'capacity' robots
    Fleet(int cap) {
        capacity = cap;
        count = 0;
        robots = new T[capacity];
    }

    // Add robot to fleet
    void addRobot(T robot) {
        if (count < capacity) {
            robots[count] = robot;
            count++;
        } else {
            cout << "Fleet is full!\n";
        }
    }

    // Display all robots
    void showFleet() {
        cout << "Fleet contains:\n";
        for (int i = 0; i < count; i++) {
            cout << "- " << robots[i] << "\n";
        }
    }

    // Destructor: Free allocated memory
    ~Fleet() {
        delete[] robots;
    }
};

int main() {
    // Step 5: Create a Robot object
    // creating a new robot ojbect
    Robot robotOne("robotOne", "ModelOne", 100);
    robotOne.displayRobot();

    // Step 6: Use pointers to access Robot object
    Robot* robotptr = &robotOne;
   // cout << "Updated Battery Life (using pointer): " << robotPtr->getBatteryLife() << "%\n";
    cout<<"Updated Battery Life (using pointer): "<<robotptr->getBatteryLife()<<"%\n";
    // Step 7: Pass by value (no change outside function)
    // nothing really happens to robotOne here in main function
    modifyRobotbyValue(robotOne);
   // cout << "After modifyRobotByValue, Battery Life: " << myRobot.getBatteryLife() << "%\n";
    cout<<"After modifyRobotbyValue, Battery Life: "<<robotOne.getBatteryLife()<<"%\n";
    // Step 8: Pass by reference (changes persist)
    modifyRobotbyReference(robotOne);
   // cout << "After modifyRobotByReference, Battery Life: " << myRobot.getBatteryLife() << "%\n";
    cout<<"After modifyRobotbyReference, Battery Life: "<<robotOne.getBatteryLife()<<"%\n";
    // Step 9: Use the Fleet template class
    Fleet<string> myFleet(3);
    myFleet.addRobot("Autobot-X");
    myFleet.addRobot("Cybertron-7");
    myFleet.addRobot("NanoDroid-3");

    myFleet.showFleet();

    return 0;
}

//ran in online complier because I was getting an error
//CMake Error: The current CMakeCache.txt directory /Users/bryanly/CLionProjects/CppBootcamp/cmake-build-debug/CMakeCache.txt is different than the directory /Users/manjumuralidharan/CLionProjects/CppBootcamp/cmake-build-debug where CMakeCache.txt was created. This may result in binaries being created in the wrong place. If you are not sure, reedit the CMakeCache.txt
//no such file or directory CMake Error: Generator: execution of make failed. Make command was: /Applications/CLion.app/Contents/bin/ninja/mac/ninja-j 6 CppBootcamp
