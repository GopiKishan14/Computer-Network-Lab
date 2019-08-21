#include <stdio.h> 
#include <string.h> 
#include <arpa/inet.h> 
#include <unistd.h>  
#include <sys/socket.h> 

#define PORT 8080 
   
int main() 
{ 
    int new_socket = 0, recieved_message; 
    struct sockaddr_in serv_addr; 
    char *message = "This is a message from client"; 
    char buffer[1024] = {0}; 

    // Creating socket file descriptor 
    if ((new_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    // Connect to the sever
    if (connect(new_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    // sending request to server
    send(new_socket , message , strlen(message) , 0 ); 
    printf("Message sent to the server\n"); 
    // recieving response from server
    recieved_message = read( new_socket , buffer, 1024); 
    printf("%s\n",buffer ); 
    return 0; 
}