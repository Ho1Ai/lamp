#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#include "../messenger/messenger.h"

#define MAX_USERCFG_LINE_LEN 512
#define MAX_USERS 10

typedef struct {
	char uname[256];
	char passwd[256];
}User;

int signInOption();

char* getUserList(){
	char *homedir=getenv("HOME");
	char defaultPath[512];
	snprintf(defaultPath, 512, "%s/.config/lamp/", homedir);
	mkdir(defaultPath,0700);
	char cfg_file[512];
	snprintf(cfg_file,512,"%s/userList.totmb", defaultPath);
	FILE* userlist_file = fopen(cfg_file,"r");
	
	User* userlist = (User*) malloc(MAX_USERS*sizeof(User));

	char line[MAX_USERCFG_LINE_LEN];

	if(userlist_file){
	for (int i = 0; i < MAX_USERS; i++) {
		//fgets(line, 512, userlist_file);
		if(!fgets(line,512,userlist_file)) break;//running through the file
		strcpy(userlist[i].uname, line);
		userlist[i].uname[strcspn(userlist[i].uname, "\n")] = 0;
		if(!fgets(line,512,userlist_file)) break;
		strcpy(userlist[i].passwd, line);
		userlist[i].passwd[strcspn(userlist[i].passwd, "\n")]=0;
		
	}

	for (int i = 0; i < MAX_USERS; i++) {
		//printf("%s\n", userlist[i].uname);
		if(strcmp(userlist[i].uname, "\0")==0) {
			//printf("qq");
			break;
		}
		printf("[%d] %s\n", i, userlist[i].uname);
	}}


	if(userlist_file){
		printf("\nsuper %d\n", sizeof(userlist_file));
	} else {
		printf("creating file with users data");
		FILE* userlist_file = fopen(cfg_file, "w");
	}

	 //char *getCharOpt;
	int getOption = signInOption();

	if(strcmp(userlist[getOption].uname, "")!=0){
		printf("user existance = True");
	} else {
		printf("user does not exist");
	}

	//getOption = itoa(getCharOpt);

	free(userlist);

	startMessenger();

	return;
}

int signInOption(){
	//printf("NONE");
	int opt;
	scanf("%d", &opt);

	return opt;
}
