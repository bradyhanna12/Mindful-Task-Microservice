/*
* Author: Brady Hanna
* Description: A program to generate random mindful tasks. These are printed to a .txt file
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>
#include <cmath>
#include <chrono>
#include <thread>
#include <exception>

using namespace std;

void resetTasks(vector<string>& activeTasks, vector<string>& passiveTasks, vector<string>& shortTasks, vector<string>& longTasks){
    // Set the tasks
    activeTasks = {
        "Walk", "Run", "Go for a Hike", "Dance", "Do Yoga", 
        "Swim", "Play a Sport", "Bike", "Climb", "Rollerblade"
    };
    
    passiveTasks = {
        "Meditate", "Read a Book", "Listen to Music", "Watch the Sunset", 
        "Daydream", "Do Deep Breathing", "Journal", "Stargaze", 
        "Take a Nap", "Relax in a Hammock"
    };
    
    shortTasks = {
        "Take a Mindful Minute", "Scroll on your phone", "Stretch", "Drink Water", 
        "Write a Journal Entry", "Doodle", "Make a To-Do List", "Close Your Eyes for 30 Seconds", 
        "Deep Breathing", "Stand Up and Walk Around"
    };
    
    longTasks = {
        "Watch a Movie", "Go on a drive", "Cook a New Recipe", "Visit a Museum", 
        "Binge a TV Show", "Work on a Hobby", "Take a Day Trip", "Read a Novel", 
        "Learn a New Skill", "Explore a New Place"
    };
}

bool readFile(ifstream& infile, string& num, int& numerical){
    // Read pipe.txt
    infile.open("pipe.txt");

    getline(infile, num);

    try{
        numerical = stoi(num);
        infile.close();
        return true;
    } catch (const invalid_argument& e){
        infile.close();
        return false;
    }
}

void writeTasks(ifstream& infile, int& numerical, string& category, vector<string>& activeTasks, vector<string>& passiveTasks, vector<string>& shortTasks, vector<string>& longTasks){
    infile.open("pipe.txt");
    string garbage;
    getline(infile, garbage);
    if(numerical > 0 && getline(infile, category) && numerical <= 10){
        infile.close();
        ofstream outfile("pipe.txt");
        outfile.close();

        // Write the mindful task to the file
        outfile.open("pipe.txt", ios::app);
        for (int i = 0; i < numerical; i++){
            // Choose a random task from the selected category
            string selectedTask;
            int index = rand() % (10 - i);
            if (category == "active") {
                selectedTask = activeTasks[index];
                activeTasks.erase(activeTasks.begin() + index);
            } else if (category == "passive") {
                selectedTask = passiveTasks[index];
                passiveTasks.erase(passiveTasks.begin() + index);
            } else if (category == "short") {
                selectedTask = shortTasks[index];
                shortTasks.erase(shortTasks.begin() + index);
            } else if (category == "long"){
                selectedTask = longTasks[index];
                longTasks.erase(longTasks.begin() + index);
            } else {
                selectedTask = "Improper category";
            }

            outfile << selectedTask << endl;
        }
            outfile.close();
    } else if (numerical > 0 && numerical <= 10){
        infile.close();
        ofstream outfile("pipe.txt");
        outfile.close();

        // Write the mindful task to the file
        outfile.open("pipe.txt", ios::app);
        for (int i = 0; i < numerical; i++){
            // Generate random number
            int categoryNum = rand() % 4;

            // Choose a random task from the selected category
            string selectedTask;
            int index = rand() % (10 - i);
            if (categoryNum == 0) {
                selectedTask = activeTasks[index];
                activeTasks.erase(activeTasks.begin() + index);
            } else if (categoryNum == 1) {
                selectedTask = passiveTasks[index];
                passiveTasks.erase(passiveTasks.begin() + index);
            } else if (categoryNum == 2) {
                selectedTask = shortTasks[index];
                shortTasks.erase(shortTasks.begin() + index);
            } else {
                selectedTask = longTasks[index];
                longTasks.erase(longTasks.begin() + index);
            }

            outfile << selectedTask << endl;
        }
        outfile.close();
    } else {
        infile.close();
    }
}

int main(){
while(true){
    // Set the tasks
    vector<string> activeTasks;
    vector<string> passiveTasks;
    vector<string> shortTasks;
    vector<string> longTasks;
    resetTasks(activeTasks, passiveTasks, shortTasks, longTasks);

    // Set random number seed
    srand(time(nullptr));

    // Read pipe.txt
    ifstream infile("pipe.txt");

    string num;
    string category;
    int numerical;

    infile.close();

    if (!readFile(infile, num, numerical)){
        continue;
    }
  
    writeTasks(infile, numerical, category, activeTasks, passiveTasks, shortTasks, longTasks);
}
}