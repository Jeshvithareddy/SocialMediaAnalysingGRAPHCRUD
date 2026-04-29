#include <stdio.h>
#include "graph.h"

int main() {

    Graph* g = createGraph();

    int choice;
    int user, follower, oldF, newF;

    while (1) {

        printf("\n1 Add User");
        printf("\n2 Add Follower");
        printf("\n3 Show Followers");
        printf("\n4 Update Follower");
        printf("\n5 Remove Follower");
        printf("\n6 Delete User");
        printf("\n7 Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter user id: ");
            scanf("%d", &user);
            addUser(g, user);
            break;

        case 2:
            printf("Enter user id: ");
            scanf("%d", &user);
            printf("Enter follower id: ");
            scanf("%d", &follower);
            addFollower(g, user, follower);
            break;

        case 3:
            printf("Enter user id: ");
            scanf("%d", &user);
            showFollowers(g, user);
            break;

        case 4:
            printf("Enter user id: ");
            scanf("%d", &user);
            printf("Old follower: ");
            scanf("%d", &oldF);
            printf("New follower: ");
            scanf("%d", &newF);
            updateFollower(g, user, oldF, newF);
            break;

        case 5:
            printf("Enter user id: ");
            scanf("%d", &user);
            printf("Follower to remove: ");
            scanf("%d", &follower);
            removeFollower(g, user, follower);
            break;

        case 6:
            printf("Enter user id: ");
            scanf("%d", &user);
            deleteUser(g, user);
            break;

        case 7:
            return 0;

        default:
            printf("Invalid choice");
        }
    }
}