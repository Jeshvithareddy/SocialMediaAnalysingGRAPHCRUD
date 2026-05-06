#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Create Graph
Graph* createGraph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));

    if (!g) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < MAX; i++)
        g->adjList[i] = NULL;

    return g;
}

// Add User
void addUser(Graph* g, int user) {
    if (user < 0 || user >= MAX) {
        printf("Invalid user\n");
        return;
    }
    // Trick: if already used once, we assume exists
    if (g->adjList[user] != NULL) {
        printf("User already exists\n");
        return;
    }
    g->adjList[user] = NULL; // marks "initialized"
    printf("User %d added\n", user);
}

// Check duplicate follower
int isFollowerExists(Node* head, int follower) {
    while (head) {
        if (head->id == follower)
            return 1;
        head = head->next;
    }
    return 0;
}

// Add Follower
void addFollower(Graph* g, int user, int follower) {
    if (user < 0 || user >= MAX || follower < 0 || follower >= MAX) {
        printf("Invalid input\n");
        return;
    }
    // Allow creation on demand (like real apps)
    if (g->adjList[user] == NULL) {
        printf("User %d does not exist. Creating...\n", user);
        g->adjList[user] = NULL;
    }
    if (isFollowerExists(g->adjList[user], follower)) {
        printf("Follower already exists\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->id = follower;
    newNode->next = g->adjList[user];
    g->adjList[user] = newNode;
    printf("Follower added\n");
}

// Show Followers
void showFollowers(Graph* g, int user) {
    if (user < 0 || user >= MAX) {
        printf("Invalid user\n");
        return;
    }
    printf("Followers of %d: ", user);
    Node* temp = g->adjList[user];
    if (!temp) {
        printf("No followers\n");
        return;
    }
    while (temp) {
        printf("%d ", temp->id);
        temp = temp->next;
    }
    printf("\n");
}

// Update Follower
void updateFollower(Graph* g, int user, int oldF, int newF) {
    if (user < 0 || user >= MAX) {
        printf("Invalid user\n");
        return;
    }
    Node* temp = g->adjList[user];
    while (temp) {
        if (temp->id == oldF) {
            temp->id = newF;
            printf("Follower updated\n");
            return;
        }
        temp = temp->next;
    }
    printf("Follower not found\n");
}

// Remove Follower
void removeFollower(Graph* g, int user, int follower) {
    if (user < 0 || user >= MAX) {
        printf("Invalid user\n");
        return;
    }
    Node* temp = g->adjList[user];
    Node* prev = NULL;
    while (temp) {
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

// Delete User
void deleteUser(Graph* g, int user) {
    if (user < 0 || user >= MAX) {
        printf("Invalid user\n");
        return;
    }
    // Remove from others
    for (int i = 0; i < MAX; i++) {
        Node* temp = g->adjList[i];
        Node* prev = NULL;
        while (temp) {
            if (temp->id == user) {
                if (prev == NULL)
                    g->adjList[i] = temp->next;
                else
                    prev->next = temp->next;
                Node* del = temp;
                temp = temp->next;
                free(del);
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
    // Delete own list
    Node* temp = g->adjList[user];
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    g->adjList[user] = NULL;
    printf("User deleted\n");
}
