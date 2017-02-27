#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct noda {
	char name[25],opcode[25];
	int num;
	struct noda *next;
}node;

node *tabl[10000008];
int gch=0;

int hash(char *c) {
	int hs=0,len=strlen(c),val=1,i;
	int mod=10000007;
	for (i=0 ; i<len ; i++) {
		hs=(hs+(c[i]*val)%mod)%mod;
		val=(val*31)%mod;
	}
	return hs;
}

void insert_to_hash(int has , char *na , char *op ,int val) {
	node *trav=tabl[has];
	node *New=(node *)malloc(sizeof(node));
	strcpy(New->name,na);
	strcpy(New->opcode,op);
	New->num=val;
	New->next=NULL;
	if(tabl[has]==NULL) {
		tabl[has]=New;
		return;
	}

	while (trav->next!=NULL) {
		trav=trav->next;
	}
	trav->next=New;
	return;
}

node *get_opcode(int has, char *na) {
	node *trav=tabl[has];
	if(trav==NULL)
		return NULL;
	while(strcmp(trav->name,na)!=0) {
		trav=trav->next;
		if(trav==NULL) {
			return NULL;
		}
	}
	return trav;

}

void add_to_hash(char *ch , char *opc , int val) {
	int ha=hash(ch);
	insert_to_hash(ha,ch,opc,val);
	return;
}

/*void printtab(int idx) {
	node *trav=tabl[idx];
	while (trav!=NULL) {
		printf("Hash value:-> %d\nName:-> %s\nOpcode:-> %s\nNumber of Arguments:->%d\n\n",idx,trav->name,trav->opcode,trav->num);
		trav=trav->next;
	}
}*/

char *to_bin(int num , int le) {
	char *pk;
	pk=(char *)malloc(sizeof(char)*13);
	int idx=le;
	while (num!=0) {
		int kp=num%2;
		char c=kp+'0';
		pk[idx]=c;
		num/=2;
		idx--;
	}
	while (idx!=-1) {
		pk[idx]='0';
		idx--;
	}
	pk[le+1]='\0';
	return pk;
}

char *to_bina(char *si , int le ) {
	int len=strlen(si),i;
	char *chl;
	int num=0,mul=1;
	for(i=len-1 ; i>=0 ; i--) {
		if(si[i]<'0' || si[i]>'9') {
			gch=1;
			return chl;
		}
		num=num+mul*(si[i]-'0');
		mul*=10;
	}
	if(num>=64)
		gch=1;
	return to_bin(num,le);
}
int main() {
	freopen("Task.in","r",stdin);freopen("Task.out","w",stdout);

	char ch[25],opc[25];
	FILE *fp;
	fp=fopen("opcodes","r");
	char in[25],inp[25];
	while (fscanf(fp,"%s",in)!=EOF) {
		fscanf(fp,"%s",inp);
		int lens=strlen(inp);
		if(in[0]=='J' || in[0]=='I' || in[0]=='O' || (in[0]=='S' && in[1]=='T'))
			add_to_hash(in,inp,1);
		else if(lens>8)
			add_to_hash(in,inp,0);
		else
			add_to_hash(in,inp,2);
		// printf("%s %s\n",in,inp);
	}
	fclose(fp);
	fp=fopen("registers","r");
	while (fscanf(fp,"%s",in)!=EOF) {
		fscanf(fp,"%s",inp);
		add_to_hash(in,inp,0);
		// printf("%s %s\n",in,inp);
	}
	fclose(fp);
	char st[25];
	int li=0;
	
	fp=fopen("Task.in","r");

	int cnt=0;
	while (fscanf(fp,"%s",st)!=EOF) {
		// printf("%s %s\n",in,inp);
		cnt++;
		int len=strlen(st);
		st[len]='\0';
		if(st[len-1]==':') {
			st[len-1]='\0';
			strcpy(ch,st);
			char *dst=to_bin(cnt,11);
			strcpy(opc,dst);
			add_to_hash(ch,opc,0);
			continue;
		}
	}
	fclose(fp);

	st[0]='\0';

	for (int i=0 ; i<10000007 ; i++) {
		printtab(i);
	}

	while (scanf("%s",st)!=EOF) {
		li++;
		int len=strlen(st);
		st[len]='\0';
		if(st[len-1]==':') {
			continue;
		}

		int has=hash(st);
		node *trav;
		trav=get_opcode(has,st);
		if(trav==NULL) {
			printf("Warning Wrong INPUT SYSTEM CRASHED!!!");
			return 0;
		}
		int tot=trav->num,chk=0,i;
		printf("%s",trav->opcode);
		for (i=0 ; i<tot ; i++) {
			if(strcmp(st,"OUT")==0) {
				scanf("%s",st);
				printf("%s\n",st);
				continue;
			}
			scanf("%s",st);
			has=hash(st);
			trav=get_opcode(has,st);
			if(trav==NULL) {
				char *pi=to_bina(st,5);
				if(gch==1) {
					printf("Wrong INPUT SYSTEM ud gaya");
					return 0;
				}
				printf("%s",pi);
				continue;
			}
			printf("%s",trav->opcode);
		}
		if(chk==1)
			break;
		printf("\n");
	}
}