#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

void main() {
    int s, r, recb, sntb, x;
    printf("INPUT port number [suggested 10000]:- ");
    scanf("%d", &x);
    struct sockaddr_in server, client;
    int buff[50];  // Updated to store integers instead of characters

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) {
        printf("\nSocket creation error!");
        exit(0);
    }
    printf("\nSocket created!");

    server.sin_family = AF_INET;
    server.sin_port = htons(x);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    r = connect(s, (struct sockaddr*)&server, sizeof(server));
    if (r == -1) {
        printf("\nConnection error!");
        exit(0);
    }
    printf("\nSocket connected!");

    printf("\nType Message (space-separated integers):- ");
    getchar();  // Consume the newline character

    // Read the list of integers and send to the server
    for (int i = 0; i < sizeof(buff) / sizeof(int); i++) {
        scanf("%d", &buff[i]);
    }
    sntb = send(s, buff, sizeof(buff), 0);
    if (sntb == -1) {
        close(s);
        printf("\nMessage Sending Failed!");
        exit(0);
    }

    // Loop to send requests to the server
    while (1) {
        int choice;
        char key;
        printf("Enter choice (1 to search):- ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter key to search for:- ");
            scanf(" %c", &key);  // Note the space before %c to consume the newline character
        }

        // Send the choice and key to the server
        sntb = send(s, &choice, sizeof(choice), 0);
        if (sntb == -1) {
            close(s);
            printf("\nMessage Sending Failed!");
            exit(0);
        }

        sntb = send(s, &key, sizeof(key), 0);
        if (sntb == -1) {
            close(s);
            printf("\nMessage Sending Failed!");
            exit(0);
        }

        char retbuff[50];
        // Receive the result from the server
        recb = recv(s, retbuff, sizeof(retbuff), 0);
        if (recb == -1) {
            printf("\nMessage Receiving Failed!");
            close(s);
            exit(0);
        }

        printf("Message Received: %s\n", retbuff);
    }

    close(s);
}