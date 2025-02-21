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
![image](https://github.com/user-attachments/assets/ef0f2d43-25f9-463c-9b2a-81be98ca5683)  

To receive the data from the microservice, your program must read pipe.txt once it has been written to.  
Each task will be on its own line in the .txt file.  
Example of tasks written to file:  
Line 1 - Task 1
Line 2 - Task 2
Line 3 - Task 3 ...  
  
Here's an example in C++ on how to receive data:   
![image](https://github.com/user-attachments/assets/a70ee527-7519-4dc3-b90e-15dc35cd4d32)  
  
UML Sequence Diagram:  
![image](https://github.com/user-attachments/assets/4ba75057-b833-4ec0-b2e1-b9084b211ed8)
