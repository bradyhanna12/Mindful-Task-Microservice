# Mindful-Task-Microservice

A. To Request data from this microservice, you must write the following information to a file called "pipe.txt". The information must be in the following form: 
Line 1 - The number of tasks to generate (up to 10). 
Line 2 - The category of task to generate ("active", "passive", "short", or "long). 

Line 2 may be left empty. This will generate tasks from any of the categories. Line 1 CANNOT be empty.

Example write:
8
passive

This example will generate 8 passive mindful tasks and write them back to pipe.txt.

Here's an example in C++ on how to request data:
int main() {
    // Step 1: Write "8\npassive" to pipe.txt
    ofstream outfile("pipe.txt"); // Open file for writing (overwrites existing content);
    if (outfile.is_open()) {
        outfile << "8\npassive" << endl; // Write "8", newline, then "passive"
        outfile.close();
        cout << "Successfully wrote '8 passive' to pipe.txt" << endl;
    } else {
        cerr << "Error opening file!" << endl;
        return 1;
    }

To receive the data from the microservice, your program must read pipe.txt once it has been written to.

Here's an example in C++ on how to receive data:
    // Step 2: Wait until any text appears in pipe.txt
    while (true) {
        ifstream infile("pipe.txt");
        if (infile.peek() != ifstream::traits_type::eof()) { // Check if file is not empty
            break;
        }
        infile.close();
        this_thread::sleep_for(chrono::milliseconds(500)); // Sleep before checking again
    }
    this_thread::sleep_for(chrono::seconds(1)); // Sleep to wait for the data
    // Step 3: Read first 8 lines of pipe.txt and store them in a vector
    ifstream infile("pipe.txt");
    vector<string> tasks;
    string task;
    int count = 0;
    // Read the 8 lines of data in the "pipe.txt" file
    while (count < 8 && getline(infile, task)) {
        tasks.push_back(task);
        count++;
    }
    infile.close();

UML Sequence Diagram:
