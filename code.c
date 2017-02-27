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
	return to_bin(num,le);
}
int main() {
	freopen("Task.in","r",stdin);freopen("Task.out","w",stdout);

	char ch[25],opc[25];
	strcpy(ch,"MOV");
	strcpy(opc,"0000");
	add_to_hash(ch,opc,2);

	strcpy(ch,"ADD");
	strcpy(opc,"0001");
	add_to_hash(ch,opc,2);

	strcpy(ch,"SUB");
	strcpy(opc,"1101");
	add_to_hash(ch,opc,2);

	strcpy(ch,"CMP");
	strcpy(opc,"0010");
	add_to_hash(ch,opc,2);

	strcpy(ch,"STB");
	strcpy(opc,"0011");
	add_to_hash(ch,opc,2);

	strcpy(ch,"LDB");
	strcpy(opc,"0100");
	add_to_hash(ch,opc,2);

	strcpy(ch,"STATUS");
	strcpy(opc,"0101");;
	add_to_hash(ch,opc,1);
	
	strcpy(ch,"IN");
	strcpy(opc,"0000000110");
	add_to_hash(ch,opc,1);

	strcpy(ch,"OUT");
	strcpy(opc,"0111");
	add_to_hash(ch,opc,1);

	strcpy(ch,"JMP");
	strcpy(opc,"1000");
	add_to_hash(ch,opc,1);

	strcpy(ch,"JGT");
	strcpy(opc,"1001");
	add_to_hash(ch,opc,1);

	strcpy(ch,"JLT");
	strcpy(opc,"1010");
	add_to_hash(ch,opc,1);

	strcpy(ch,"JEQ");
	strcpy(opc,"1011");
	add_to_hash(ch,opc,1);

	strcpy(ch,"JNE");
	strcpy(opc,"1100");
	add_to_hash(ch,opc,1);

	strcpy(ch,"CHARGE");
	strcpy(opc,"000000001111");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R1");
	strcpy(opc,"000001");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R2");
	strcpy(opc,"000010");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R3");
	strcpy(opc,"000011");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R4");
	strcpy(opc,"000100");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R5");
	strcpy(opc,"000101");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R6");
	strcpy(opc,"000110");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R7");
	strcpy(opc,"000111");;
	add_to_hash(ch,opc,0);
	
	strcpy(ch,"R8");
	strcpy(opc,"001000");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R9");
	strcpy(opc,"001001");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R10");
	strcpy(opc,"001010");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R11");
	strcpy(opc,"001011");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R12");
	strcpy(opc,"001100");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R13");
	strcpy(opc,"001101");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R14");
	strcpy(opc,"001110");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R15");
	strcpy(opc,"001111");
	add_to_hash(ch,opc,0);

	strcpy(ch,"R16");
	strcpy(opc,"010000");
	add_to_hash(ch,opc,0);

	strcpy(ch,"PC");
	strcpy(opc,"010001");
	add_to_hash(ch,opc,0);

	strcpy(ch,"FLAG");
	strcpy(opc,"010010");
	add_to_hash(ch,opc,0);

	strcpy(ch,"SP");
	strcpy(opc,"010011");
	add_to_hash(ch,opc,0);

	strcpy(ch,"START");
	strcpy(opc,"000000000000");
	add_to_hash(ch,opc,0);

	strcpy(ch,"HLT");
	strcpy(opc,"0000000000000001");
	add_to_hash(ch,opc,0);

	strcpy(ch,"FWD");
	strcpy(opc,"000000000010");
	add_to_hash(ch,opc,0);

	strcpy(ch,"BKD");
	strcpy(opc,"000000000011");
	add_to_hash(ch,opc,0);

	strcpy(ch,"ROTC");
	strcpy(opc,"000000000100");
	add_to_hash(ch,opc,0);

	strcpy(ch,"ROTAC");
	strcpy(opc,"000000000101");
	add_to_hash(ch,opc,0);

	strcpy(ch,"HUP");
	strcpy(opc,"000000000110");
	add_to_hash(ch,opc,0);

	strcpy(ch,"HDN");
	strcpy(opc,"000000000111");
	add_to_hash(ch,opc,0);

	strcpy(ch,"STOP");
	strcpy(opc,"000000001000");
	add_to_hash(ch,opc,0);

	strcpy(ch,"BACKIN");
	strcpy(opc,"000000001001");
	add_to_hash(ch,opc,0);

	strcpy(ch,"BACKDEC");
	strcpy(opc,"000000001010");
	add_to_hash(ch,opc,0);

	char st[25];
	int li=0;
	
	while (scanf("%s",st)!=EOF) {
		li++;
		int len=strlen(st);
		st[len]='\0';
		if(st[len-1]==':') {
			st[len-1]='\0';
			strcpy(ch,st);
			char *dst=to_bin(li,11);
			strcpy(opc,dst);
			add_to_hash(ch,opc,0);
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