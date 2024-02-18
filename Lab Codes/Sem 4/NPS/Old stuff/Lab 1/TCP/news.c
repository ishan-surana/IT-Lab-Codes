#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

void main() {
    int s, r, recb, sntb, x, ns, a = 0;
    printf("INPUT port number:- ");
    scanf("%d", &x);
    socklen_t len;
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
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    r = bind(s, (struct sockaddr*)&server, sizeof(server));
    if (r == -1) {
        printf("\nBinding error!");
        exit(0);
    }
    printf("\nSocket binded!");

    r = listen(s, 1);
    if (r == -1) {
        close(s);
        exit(0);
    }
    printf("\nSocket listening...");

    len = sizeof(client);
    ns = accept(s, (struct sockaddr*)&client, &len);
    if (ns == -1) {
        close(s);
        exit(0);
    }
    printf("\nSocket accepting...\n");

    // Receive the list of integers from the client
    recb = recv(ns, buff, sizeof(buff), 0);
    if (recb == -1) {
        printf("\nMessage Receiving Failed!");
        close(s);
        close(ns);
        exit(0);
    }

    printf("Buffer is: ");
    for (int i = 0; i < recb / sizeof(int); i++) {
        printf("%d ", buff[i]);
    }
    printf("\n");

    // Loop to handle client requests
    while (1) {
        int choice;
        char key;

        // Receive the choice and key from the client
        recb = recv(ns, &choice, sizeof(choice), 0);
        if (recb == -1) {
            printf("\nMessage Receiving Failed!");
            close(s);
            close(ns);
            exit(0);
        }

        recb = recv(ns, &key, sizeof(key), 0);
        if (recb == -1) {
            printf("\nMessage Receiving Failed!");
            close(s);
            close(ns);
            exit(0);
        }

        char retbuff[50];
        switch (choice) {
            case 1:
                int i, flag = 0;
                for (i = 0; i < recb / sizeof(int); i++) {
                    if (key == buff[i]) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    strcpy(retbuff, "NOT FOUND!");
                } else {
                    strcpy(retbuff, "FOUND!");
                }
                break;
            default:
                break;
        }

        // Send the result back to the client
        sntb = send(ns, retbuff, sizeof(retbuff), 0);
        if (sntb == -1) {
            printf("\nMessage Sending Failed!");
            close(s);
            close(ns);
            exit(0);
        }
    }

    close(ns);
    close(s);
}