#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <dirent.h>
#include <ctype.h>



struct proces_names
{
	int fd;
	int task;
	char ime[1001];
	int ppid;
	char stanje[1001];
	int id;
};


void processName(char* path,char* state, char* ppid);
int check(struct proces_names proces,char* path,int search);
int countfd(char* path);
int counttasks(char* path);


int main(int argc, char** argv) {

	
	char defPath[] = "/proc";
	

	//AKCIJA SYS
	if(strcmp("sys",argv[1])==0){
		char* path = (char*)malloc(42*sizeof(char));

		if(argc>2){
			strcpy(path,argv[2]);
			
		}else{
			strcpy(path,defPath);
		}
		//printf("%s\n",path);

		FILE* vhod = fopen(strcat(path,"/version"),"r");

		int trenuten;

		char* vrstica = (char*)malloc(1001*sizeof(char));
		int indeks=0;

		int flag=0;
		int rez=0;

		while((trenuten=fgetc(vhod))!=EOF){
			if(trenuten==' '){
				indeks=0;

				if(flag){
					if(rez==0){
						printf("Linux: %s \n",vrstica);
						rez++;
					}else{
						printf("gcc: %s \n",vrstica);
					}
					flag=0;
				}

				if(strcmp("version",vrstica)==0){
					flag=1;
				}
				vrstica = (char*)malloc(1001*sizeof(char));
			}else{
				vrstica[indeks]=trenuten;	
				indeks++;
			}
		}


		free(path);
		fclose(vhod);

	//AKCIJA SYSEXT
	}else if(strcmp("sysext",argv[1])==0){
		char* path = (char*)malloc(42*sizeof(char));
		char* path2 = (char*)malloc(42*sizeof(char));
		char* path3 = (char*)malloc(42*sizeof(char));

		if(argc>2){
			strcpy(path,argv[2]);
			strcpy(path2,argv[2]);
			strcpy(path3,argv[2]);
			
			
		}else{
			strcpy(path,defPath);
			strcpy(path2,defPath);
			strcpy(path3,defPath);
				
		}
		//printf("%s\n",path);

		FILE* vhod = fopen(strcat(path,"/version"),"r");

		int trenuten;

		char* vrstica = (char*)malloc(1001*sizeof(char));
		int indeks=0;

		int flag=0;
		int rez=0;

		while((trenuten=fgetc(vhod))!=EOF){
			if(trenuten==' '){
				indeks=0;

				if(flag){
					if(rez==0){
						printf("Linux: %s \n",vrstica);
						rez++;
					}else{
						printf("gcc: %s \n",vrstica);
					}
					flag=0;
				}

				if(strcmp("version",vrstica)==0){
					flag=1;
				}
				vrstica = (char*)malloc(1001*sizeof(char));
			}else{
				vrstica[indeks]=trenuten;	
				indeks++;
			}
		}

		trenuten=0;
		free(path);
		free(vrstica);
		fclose(vhod);


		FILE* vhod2 = fopen(strcat(path2,"/modules"),"r");
		FILE* vhod3 = fopen(strcat(path3,"/swaps"),"r");

		int prva=0;
		vrstica = (char*)malloc(1001*sizeof(char));
		indeks=0;
		
		while((trenuten=fgetc(vhod3))!=EOF){
			if(prva && trenuten==' '){
				vrstica[indeks]='\0';
				printf("Swap: %s",vrstica);
				break;
			}
			if(prva){
				vrstica[indeks]=trenuten;
				indeks++;
			}

			if(trenuten=='\n'){
				prva=1;
			}
		}

		int steviloVrstic=0;
		trenuten=0;

		while((trenuten=fgetc(vhod2))!=EOF){
			if(trenuten=='\n'){
				steviloVrstic++;
			}
		}
		printf("\nModules: %d\n",steviloVrstic);
		free(path2);
		free(path3);
		fclose(vhod2);
		fclose(vhod3);
		free(vrstica);
		//printf("42");
		return steviloVrstic;

	}else if(strcmp("me",argv[1])==0){

		int uid=getuid();
		int euid=geteuid();
		int gid=getgid();
		int egid=getegid();
		char cwd[1001];
		getcwd(cwd,sizeof(cwd));

		printf("Uid: %d\n",uid);
		printf("EUid: %d\n",euid);
		printf("Gid: %d\n",gid);
		printf("EGid: %d\n",egid);
		printf("Cwd: %s\n",cwd);
		printf("Priority: %d\n",getpriority(PRIO_PROCESS,getpid()));

		//procc path unu 2x 
		
		int pid=getpid();
		printf("Process proc path: /proc/%d/\n",pid);

		char id[1001];

		sprintf(id,"%d",pid);
		strcat(id,"/");

		char pot[] = "/proc/";
		strcat(pot,id);

		int dostop=access(pot,R_OK);

		if(dostop==0){
			printf("Process proc access: yes\n");
		}else{
			printf("Process proc access: no\n");
		}


		struct utsname A;
		uname(&A);
		printf("OS name: %s\n", A.sysname);
		printf("OS release: %s\n",A.release);
		printf("OS version: %s\n",A.version);
		printf("Machine: %s\n",A.machine);
		printf("Node name: %s\n",A.nodename);		

		struct timeval B;
		struct timezone pas;
		gettimeofday(&B,&pas);
		printf("Timezone: %d\n",pas.tz_dsttime);
		
		
		struct rlimit D;
		getrlimit(RLIMIT_CPU,&D);
		printf("CPU limit: %ld",D.rlim_max);
		


	}else if(strcmp("pids",argv[1])==0){
		
		
		//char* path = (char*)malloc(42*sizeof(char));

		int tabela[1001];



		/*if(argc>2){
			strcpy(path,argv[2]);
		}else{
			strcpy(path,defPath);
		}*/

		int mape=0;

		//printf("POTTTTTT %s\n",path);

		char ime[1001];
		DIR* directory = opendir(argv[2]);
		if(directory==NULL){printf("Prislo je do napake\n");}
		
		struct dirent* mapca;

		while((mapca=readdir(directory))!=NULL){
			strcpy(ime,mapca->d_name);
			
			if(strcmp(ime,".")==0 || strcmp(ime,"..")==0){
				continue;
			}
			if(atoi(ime)>0){
				tabela[mape]=atoi(ime);
				mape++;
			}
		}

		int tabela2[mape];

		for(int i = 0; i<mape; i++){
			tabela2[i]=tabela[i];
			//printf("%d\n",tabela2[i]);
		}


		
		//bubble sort
		for(int i = 0; i<mape-1; i++){
			for(int j = 0; j<mape-1-i;j++){
				if(tabela2[j]>tabela2[j+1]){
					int temp=tabela2[j];
					tabela2[j]=tabela2[j+1];
					tabela2[j+1]=temp;
				}
			}
		}
		//end bubble sort

		for(int i = 0; i<mape; i++){
			printf("%d\n",tabela2[i]);
		}

		//free(path);
		closedir(directory);


	}else if(strcmp("names",argv[1])==0){

	
		struct proces_names tabela[1001];
		int mape=0;

		char ime[1001];
		DIR* directory = opendir(argv[2]);

		if(directory==NULL){printf("Prislo je do napake\n");}
		
		struct dirent* mapca;

		while((mapca=readdir(directory))!=NULL){
			strcpy(ime,mapca->d_name);


			if(strcmp(ime,".")==0 || strcmp(ime,"..")==0){
				continue;
			}
			
				
			if(atoi(ime)>0){

				//najdem ime procesa
				char potka[1001]="";
				char state[1001]="";
				char ppid[1001]="";
				strcat(potka,argv[2]);
				strcat(potka,"/");
				strcat(potka,ime);

				processName(potka,state,ppid);

				struct proces_names trenutni_proces;

				//printf("lmao %s\n",potka);

				//napolnem struct
				strcpy(trenutni_proces.ime,potka);
				trenutni_proces.id=atoi(ime);
				

				tabela[mape]=trenutni_proces;
				mape++;
			}
		}

		
		//bubble sort
		for(int i = 0; i<mape-1; i++){
			for(int j = 0; j<mape-1-i;j++){

				if(strcasecmp(tabela[j].ime,tabela[j+1].ime)<0){

					struct proces_names temp=tabela[j];
					tabela[j]=tabela[j+1];
					tabela[j+1]=temp;

				}else if(strcasecmp(tabela[j].ime,tabela[j+1].ime)==0){
					//printf("SAME %s %s\n",sef[j].ime,sef[j+1].ime);
					if(tabela[j].id<tabela[j+1].id){

						struct proces_names temp=tabela[j];
						tabela[j]=tabela[j+1];
						tabela[j+1]=temp;
					}
				}
			}
		}
		//end bubble sort

		//printf("Stevilo procesov je %d\n",mape);

		for(int i = mape-1; i>=0; i--){


			//if(check(tabela[i])){
			//	printf("%d %s\n",tabela[i].id,tabela[i].ime);
			//}

			printf("%d %s\n",tabela[i].id,tabela[i].ime);
		}

		
		closedir(directory);

	}else if(strcmp("ps",argv[1])==0){

		
		//izpisat moram PID, PPID STANJE IME


		struct proces_names tabela[1001];
		int mape=0;

		char ime[1001];
		DIR* directory = opendir(argv[2]);

		if(directory==NULL){printf("Prislo je do napake\n");}
		
		struct dirent* mapca;

		while((mapca=readdir(directory))!=NULL){
			strcpy(ime,mapca->d_name);


			if(strcmp(ime,".")==0 || strcmp(ime,"..")==0){
				continue;
			}
			
				
			if(atoi(ime)>0){

				//najdem ime procesa
				char potka[1001]="";
				char state[1001]="";
				char ppid[1001]="";
				strcat(potka,argv[2]);
				strcat(potka,"/");
				strcat(potka,ime);

				processName(potka,state,ppid);

				//printf("%s %s\n",state,ppid);

				struct proces_names trenutni_proces;

				//napolnem struct
				strcpy(trenutni_proces.ime,potka);
				strcpy(trenutni_proces.stanje,state);
				trenutni_proces.ppid=atoi(ppid);
				trenutni_proces.id=atoi(ime);
				

				tabela[mape]=trenutni_proces;
				mape++;
			}
		}

		//bubble sort
		for(int i = 0; i<mape-1; i++){
			for(int j = 0; j<mape-1-i;j++){

				if(tabela[j].id<tabela[j+1].id){

					struct proces_names temp=tabela[j];
					tabela[j]=tabela[j+1];
					tabela[j+1]=temp;
				}
			}
		}
		//end bubble sort

		//printf("Stevilo procesov je %d\n",mape);
		//printf("st argsov %d\n",argc);

		printf("%5s %5s %6s %s\n", "PID", "PPID", "STANJE", "IME");
		for(int i = mape-1; i>=0; i--){
			//printf("%d %s\n",tabela[i].id,tabela[i].ime);

			if(argc>3){
				if(check(tabela[i],argv[2],atoi(argv[3]))){
					printf("%5d %5d %6s %s\n",tabela[i].id,tabela[i].ppid,tabela[i].stanje,tabela[i].ime);
				}
			}else{
				printf("%5d %5d %6s %s\n",tabela[i].id,tabela[i].ppid,tabela[i].stanje,tabela[i].ime);

			}

		}

		
		closedir(directory);


	}else if(strcmp("psext",argv[1])==0){

		//izpisat moram PID, PPID STANJE #NITI #DAT IME


		struct proces_names tabela[1001];
		int mape=0;

		char ime[1001];
		DIR* directory = opendir(argv[2]);

		if(directory==NULL){printf("Prislo je do napake\n");}
		
		struct dirent* mapca;

		while((mapca=readdir(directory))!=NULL){
			strcpy(ime,mapca->d_name);


			if(strcmp(ime,".")==0 || strcmp(ime,"..")==0){
				continue;
			}
			
				
			if(atoi(ime)>0){

				//najdem ime procesa
				char potka[1001]="";
				char state[1001]="";
				char ppid[1001]="";
				strcat(potka,argv[2]);
				strcat(potka,"/");
				strcat(potka,ime);

				struct proces_names trenutni_proces;

				//printf("I GUESS %s\n",potka);

				int fds=countfd(potka);
				int tasks=counttasks(potka);

				trenutni_proces.fd=fds;
				trenutni_proces.task=tasks;

				processName(potka,state,ppid);

				//printf("%s %s\n",state,ppid);
				//napolnem struct
				strcpy(trenutni_proces.ime,potka);
				strcpy(trenutni_proces.stanje,state);
				trenutni_proces.ppid=atoi(ppid);
				trenutni_proces.id=atoi(ime);
				
				//dodam se fd pa task
				tabela[mape]=trenutni_proces;
				mape++;
			}
		}

		//bubble sort
		for(int i = 0; i<mape-1; i++){
			for(int j = 0; j<mape-1-i;j++){

				if(tabela[j].id<tabela[j+1].id){

					struct proces_names temp=tabela[j];
					tabela[j]=tabela[j+1];
					tabela[j+1]=temp;
				}
			}
		}
		//end bubble sort

		//printf("Stevilo procesov je %d\n",mape);
		//printf("st argsov %d\n",argc);

		//printf("%5s %5s %6s %s\n", "PID", "PPID", "STANJE", "IME");
		printf("%5s %5s %6s %6s %6s %s\n", "PID", "PPID", "STANJE", "#NITI", "#DAT.", "IME");

		for(int i = mape-1; i>=0; i--){
			//printf("%d %s\n",tabela[i].id,tabela[i].ime);

			if(argc>3){
				if(check(tabela[i],argv[2],atoi(argv[3]))){
					printf("%5d %5d %6s %6d %6d %s\n",tabela[i].id,tabela[i].ppid,tabela[i].stanje,tabela[i].task,tabela[i].fd,tabela[i].ime);
				}
			}else{
				printf("%5d %5d %6s %6d %6d %s\n",tabela[i].id,tabela[i].ppid,tabela[i].stanje,tabela[i].task,tabela[i].fd,tabela[i].ime);
			}

		}

		
		closedir(directory);


	}

    return 0;
}


void processName(char* path,char* state, char* ppid){
	
	strcat(path,"/status");
	FILE* vhod = fopen(path,"r");
	
	if(vhod==NULL){
		printf("Prislo je do napake pri odpiranju\n");
	}

	//NAME 2 beseda
	//STATE 4 beseda
	//PPID 13

	char name[1001];

	fscanf(vhod,"%99s",name);
	fscanf(vhod,"%99s",name);

	strcpy(path,name);

	for(int i = 2; i<4; i++){
		fscanf(vhod,"%99s",name);
	}
	
	strcpy(state,name);
	
	for(int i = 4; i<13; i++){
		fscanf(vhod,"%99s",name);
	}


	strcpy(ppid,name);
	
	//strcpy(path,kaj);
	
	//free(kaj);
	fclose(vhod);


}


int check(struct proces_names proces,char* path,int search){

	//printf("%s\n",path);
	//printf("iscem %d\n",search);

	int pid=proces.id;
	int ppid=proces.ppid;

	//robni pogoj ce ppid=0

	if(search==pid || search==ppid){
		return 1;
	}

	if(ppid==0){
		return 0;
	}

	//ce ni pogledam od tega procesa prednike
	
	/*
		PID PPID

	1 0, ker ppid =  0, returnam 0, ne izpisem
	10 1, preverim ce je pid oz ppid == search, ker je ga izpisem
	11 10, ker ppid == search, ga izpisem
	12 10, enako

	14 1, pid in ppid nista search, nov struct oblike 1 fotr in poslem v check
	fotra najdem tako, da grem z proc-demo/pid v process name in vrnem fotra

	*/

	//proc-demo + / + ppid 
	//zdaj od tega 



	char str[1001];
	sprintf(str, "%d", ppid);


	char potka[1001]="";
	char state[1001]="";
	char fotr[1001]="";
	strcat(potka,path);
	strcat(potka,"/");
	
	strcat(potka,str);

	processName(potka,state,fotr);

	//nafilam struct in ga f***** v search

	struct proces_names alfa;

	alfa.id=ppid;
	alfa.ppid=atoi(fotr);



	return check(alfa,path,search);

	return 0;
}

int countfd(char* path){
	char nova[1001];
	char ime[1001];

	strcpy(nova,path);
	strcat(nova,"/fd");

	DIR* directory = opendir(nova);

	if(directory==NULL){printf("Prislo je do napake\n");}
	
	struct dirent* mapca;

	int stevec=0;

	while((mapca=readdir(directory))!=NULL){
		strcpy(ime,mapca->d_name);
		if(strcmp(ime,".")==0 || strcmp(ime,"..")==0){
			continue;
		}else{
			stevec++;
		}
	}

	closedir(directory);

	return stevec;
}
int counttasks(char* path){

	char nova[1001];
	char ime[1001];
	
	strcpy(nova,path);
	strcat(nova,"/task");

	DIR* directory = opendir(nova);

	if(directory==NULL){printf("Prislo je do napake\n");}
	
	struct dirent* mapca;

	int stevec=0;

	while((mapca=readdir(directory))!=NULL){
		strcpy(ime,mapca->d_name);
		if(strcmp(ime,".")==0 || strcmp(ime,"..")==0){
			continue;
		}else{
			stevec++;
		}
	}

	closedir(directory);


	return stevec;
}




