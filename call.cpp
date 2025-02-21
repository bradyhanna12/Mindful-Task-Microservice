#include <iostream>
#include <fstream>
#include <vector>
#include <thread> 
#include <chrono>  

using namespace std;

int main() {
    // Step 1: Write "8\npassive" to pipe.txt
    ofstream outfile("pipe.txt"); // Open file for writing (overwrites existing content)
    
    if (outfile.is_open()) {
        outfile << "8\npassive" << endl; // Write "8", newline, then "passive"
        outfile.close();
        cout << "Successfully wrote '8 passive' to pipe.txt" << endl;
    } else {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Step 2: Wait until any text appears in pipe.txt
    while (true) {
        ifstream infile("pipe.txt");
        if (infile.peek() != ifstream::traits_type::eof()) { // Check if file is not empty
            break;
        }
        infile.close();
        this_thread::sleep_for(chrono::milliseconds(500)); // Sleep before checking again
    }

    this_thread::sleep_for(chrono::seconds(1));
    // Step 3: Read first 8 lines of pipe.txt and store them in a vector
    ifstream infile("pipe.txt");
    vector<string> tasks;
    string task;

    int count = 0;
    while (count < 8 && getline(infile, task)) {
        tasks.push_back(task);
        count++;
    }
    infile.close();

    // Step 4: Print stored lines
    cout << "First 8 lines of pipe.txt:" << endl;
    for (const auto& task : tasks) {
        cout << task << endl;
    }

    return 0;
}