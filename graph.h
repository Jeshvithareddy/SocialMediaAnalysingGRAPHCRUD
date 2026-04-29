#ifndef GRAPH_H
#define GRAPH_H

#define MAX 100

typedef struct Node {
    int id;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX];
} Graph;

Graph* createGraph();
void addUser(Graph* g, int user);
void addFollower(Graph* g, int user, int follower);
void showFollowers(Graph* g, int user);
void updateFollower(Graph* g, int user, int oldF, int newF);
void removeFollower(Graph* g, int user, int follower);
void deleteUser(Graph* g, int user);

#endif