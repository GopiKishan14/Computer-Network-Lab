#include<stdio.h> 
#include<string.h> 

char getClass(char str[]) 
{ 
	char arr[4]; 
	int i = 0; 
	while (str[i] != '.') 
	{ 
		arr[i] = str[i]; 
		i++; 
	} 
	i--; 

	int ip = 0, j = 1; 
	while (i >= 0) 
	{ 
		ip = ip + (str[i] - '0') * j; 
		j = j * 10; 
		i--; 
	} 

	if (ip >=1 && ip <= 126) 
		return 'A'; 

	else if (ip >= 128 && ip <= 191) 
		return 'B'; 

	else if (ip >= 192 && ip <= 223) 
		return 'C'; 

	else if (ip >= 224 && ip <= 239) 
		return 'D'; 

	else
		return 'E'; 
} 

void generate_Network_Host_ID(char str[], char ipClass) 
{ 
	char network[12], host[12]; 
	for (int k = 0; k < 12; k++) 
		network[k] = host[k] = '\0'; 

    if(ipClass=='D' || ipClass=='E')
    {
        printf("In this Class, IP address is not"
           " divided into Network and Host ID\n"); 
        return;
    }
        

    int i = 0, j = 0, dotCount = 0; 

    while (dotCount < ipClass - 'A' + 1) 
    { 
        network[i++] = str[j++]; 
        if (str[j] == '.') 
            dotCount++; 
    } 
    i = 0; 
    j++; 

    while (str[j] != '\0') 
        host[i++] = str[j++]; 

    printf("Network ID is %s\n", network); 
    printf("Host ID is %s\n", host); 

    return;
} 

int main() 
{ 
    char str[16];
    scanf("%s", str);
	char ipClass = getClass(str); 
	printf("Given IP address belongs to Class %c\n", 
										ipClass); 
	generate_Network_Host_ID(str, ipClass); 
	return 0; 
} 
