#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
	char responses[20][30] = {
							 "It is certain",
							 "It is decidedly so",
							 "Without a doubt",
							 "Yes definitely",
							 "You may rely on it",
							 "As I see it, yes",
							 "Most likely",
							 "Outlook good",
							 "Yes",
							 "Signs point to yes",
							 "Reply hazy, try again",
							 "Ask again later",
							 "Better not tell you now",
							 "Cannot predict now",
							 "Concentrate and ask again",
							 "Don't count on it",
							 "My reply is no",
							 "My sources say no",
							 "Outlook not so good",
							 "Very doubtful"
				 		   };

	struct timeval te; 
    gettimeofday(&te, NULL);

    srandom(te.tv_sec*1000LL + te.tv_usec/1000);

	printf("8Ball says: %s\n", responses[random() % 20]);

	return 0;
}