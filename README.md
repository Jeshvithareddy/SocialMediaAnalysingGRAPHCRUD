# SocialMediaAnalysingGRAPHCRUD
Social Media Analytics - Follower/Influencer Graph CRUD

## Project Description

This project implements a Social Media Analytics system using a Graph data structure in C.  
Each user is represented as a vertex (node), and followers are represented as edges (connections).  
The system allows users to perform CRUD operations (Create, Read, Update, Delete) on followers and users.

This project demonstrates the use of:

- Graph Data Structure
- Linked List
- Dynamic Memory Allocation
- CRUD Operations
- Menu-driven Program
- GitHub Collaboration


## Features

The system supports the following operations:

1. Add User
2. Add Follower
3. Show Followers
4. Update Follower
5. Remove Follower
6. Delete User
7. Exit Program


## Technologies Used

- Programming Language: C
- Data Structure: Graph (Adjacency List)
- Memory Management: Dynamic Allocation (malloc, free)
- Version Control: Git
- Collaboration Platform: GitHub


## Project Structure
social-media-graph-crud/

main.c     - Contains the main function and menu-driven program  
graph.c    - Contains all graph operations (CRUD functions)  
graph.h    - Header file with structure definitions and function declarations  
README.md  - Project documentation and instructions


## How to Compile and Run

### Step 1: Open Terminal
Navigate to the project folder.

### Step 2: Compile the Program
gcc main.c graph.c -o social


### Step 3: Run the Program
Linux / Mac:
./social

Windows:
social.exe


## Sample Output
///PRINTS
1 Add User
2 Add Follower
3 Show Followers
4 Update Follower
5 Remove Follower
6 Delete User
7 Exit

Enter choice: 1
Enter user id: 1
User 1 added //OUTPUT


## Future Improvements

Possible enhancements include:
- Graph visualization
- File storage
- User interface (GUI)
- Database integration
- Influencer ranking system


## Conclusion

This project demonstrates the practical implementation of graph-based social media analytics using C programming and GitHub collaboration. It provides a foundational understanding of data structures, memory management, and teamwork in software development.



