#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* createGraph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));

    for (int i = 0; i < MAX; i++)
        g->adjList[i] = NULL;

    return g;
}

void addUser(Graph* g, int user) {
    if (g->adjList[user] == NULL) {
        g->adjList[user] = NULL;
        printf("User %d added\n", user);
    }
    else {
        printf("User already exists\n");
    }
}

void addFollower(Graph* g, int user, int follower) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = follower;
    newNode->next = g->adjList[user];

    g->adjList[user] = newNode;

    printf("Follower added\n");
}

void showFollowers(Graph* g, int user) {
    Node* temp = g->adjList[user];

    printf("Followers of %d: ", user);

    while (temp != NULL) {
        printf("%d ", temp->id);
        temp = temp->next;
    }

    printf("\n");
}

void updateFollower(Graph* g, int user, int oldF, int newF) {
    Node* temp = g->adjList[user];

    while (temp != NULL) {
        if (temp->id == oldF) {
            temp->id = newF;
            printf("Follower updated\n");
            return;
        }
        temp = temp->next;
    }

    printf("Follower not found\n");
}

void removeFollower(Graph* g, int user, int follower) {
    Node* temp = g->adjList[user];
    Node* prev = NULL;

    while (temp != NULL) {

        if (temp->id == follower) {

            if (prev == NULL)
                g->adjList[user] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Follower removed\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Follower not found\n");
}

void deleteUser(Graph* g, int user) {
    Node* temp = g->adjList[user];

    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    g->adjList[user] = NULL;

    printf("User deleted\n");
}