#include <stdio.h>
#include "graph.h"

int main() {
    Graph* g = createGraph();
    if (g == NULL) return 1;
    int choice;
    int user, follower, oldF, newF;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Add User\n");
        printf("2. Add Follower\n");
        printf("3. Show Followers\n");
        printf("4. Update Follower\n");
        printf("5. Remove Follower\n");
        printf("6. Delete User\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            return 1;
        }
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
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
