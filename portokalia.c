#include <stdio.h>
#include <stdlib.h>

void gemisma(double varos_diam_paxos[][3],int portokalia);
void gemisma_me_pointers(double *varos_diam_paxos,int portokalia);
void display_me_pointers(double *varos_diam_paxos,int portokalia);
void under_over_100gr_me_pointers(double *varos_diam_paxos,int portokalia,int *over,int *under);
void max_diam_me_pointers(double *varos_diam_paxos,int portokalia,double *maxi,int *pos);
void diam_mik_apo_10_kai_varos_meg_apo_100(double *varos_diam_paxos,int portokalia,int *count);
void sorting_asc_paxos(double *varos_diam_paxos,int portokalia);

int main() {
	
	int over=0,under=0;
	int portokalia;
	double maxi;
	int pos;
	int count=0;
	
	printf("Posa portokalia exeis;\n");
	scanf("%i",&portokalia);
	double varos_diam_paxos[portokalia][3];
	
	gemisma_me_pointers(&varos_diam_paxos[0][0],portokalia);
	display_me_pointers(&varos_diam_paxos[0][0],portokalia);
	under_over_100gr_me_pointers(&varos_diam_paxos[0][0],portokalia,&over,&under);
	printf("Over 100: %i, Under 100: %i\n",over,under);
	max_diam_me_pointers(&varos_diam_paxos[0][0],portokalia,&maxi,&pos);
	printf("H megisti diametros einai %.1f kai tin exei to %io\n",maxi,pos+1);
	diam_mik_apo_10_kai_varos_meg_apo_100(&varos_diam_paxos[0][0],portokalia,&count);
	printf("Auta me diametro mikroteri apo 10 kai varos megalitero apo 100 einai %i\n",count);
	sorting_asc_paxos(&varos_diam_paxos[0][0],portokalia);
	display_me_pointers(&varos_diam_paxos[0][0],portokalia);
	
	return 0;
}

void gemisma(double varos_diam_paxos[][3],int portokalia){
	int i;
	for (i=0; i<portokalia; i++){
		printf("Dwse to varos tou %iou\n",i+1);
		//scanf("%lf",&varos);
		scanf("%lf",&varos_diam_paxos[i][0]);
		
		printf("Dwse tin diametro tou %iou\n",i+1);
		scanf("%lf",&varos_diam_paxos[i][1]);
		
		printf("Dwse to paxos tis floudas tou %iou\n",i+1);
		scanf("%lf",&varos_diam_paxos[i][2]);
	}
}

void gemisma_me_pointers(double *varos_diam_paxos,int portokalia){
	int i;
	double varos,diametros,paxos;
	for (i=0; i<portokalia; i++){
		printf("Dwse to varos tou %iou\n",i+1);
		scanf("%lf",&varos);
		*(varos_diam_paxos+i*3+0)=varos;
		//scanf("%lf",&varos_diam_paxos[i][0]);
		printf("Dwse tin diametro tou %iou\n",i+1);
		scanf("%lf",&diametros);
		*(varos_diam_paxos+i*3+1)=diametros;
		printf("Dwse to paxos tis floudas tou %iou\n",i+1);
		scanf("%lf",&paxos);
		*(varos_diam_paxos+i*3+2)=paxos;
	}
}
//1. 20 gr, 1.3 cm, 0.11 cm
void display_me_pointers(double *varos_diam_paxos,int portokalia){
	int i;
	printf("\n");
	for (i=0; i<portokalia; i++){
		printf("%i. %.2f gr, %.2f cm, %.2f cm\n",i+1,*(varos_diam_paxos+i*3+0),*(varos_diam_paxos+i*3+1),*(varos_diam_paxos+i*3+2));
	}
	printf("\n");
}

void under_over_100gr_me_pointers(double *varos_diam_paxos,int portokalia,int *over,int *under){
	int i;
	for (i=0; i<portokalia; i++){
		if (*(varos_diam_paxos+i*3+0)>100){
			*over=*over+1;
		}
		else{
			*under=*under+1;
		}
	}
}

void max_diam_me_pointers(double *varos_diam_paxos,int portokalia,double *maxi,int *pos){
	int i;
	*pos=0;
	*maxi=*(varos_diam_paxos+0*3+1);
	for (i=0; i<portokalia; i++){
		if (*(varos_diam_paxos+i*3+1)>(*maxi)){
			*pos=i;
			*maxi=*(varos_diam_paxos+i*3+1);
		}
	}
}

void diam_mik_apo_10_kai_varos_meg_apo_100(double *varos_diam_paxos,int portokalia,int *count){
	int i;
	for (i=0; i<portokalia; i++){
		if (*(varos_diam_paxos+i*3+1)<10 && *(varos_diam_paxos+i*3+0)>100){
			*count=*count+1;
		}
	}
}

void sorting_asc_paxos(double *varos_diam_paxos,int portokalia){
	int i,j;
	double temp,temp1,temp2;
	for (i=0; i<portokalia-1; i++){
		for (j=0; j<portokalia-i-1; j++){
			if (*(varos_diam_paxos+j*3+2)>*(varos_diam_paxos+(j+1)*3+2)){
				//swap
				temp=*(varos_diam_paxos+j*3+2);
				*(varos_diam_paxos+j*3+2)=*(varos_diam_paxos+(j+1)*3+2);
				*(varos_diam_paxos+(j+1)*3+2)=temp;
				
				temp1=*(varos_diam_paxos+j*3+0);
				*(varos_diam_paxos+j*3+0)=*(varos_diam_paxos+(j+1)*3+0);
				*(varos_diam_paxos+(j+1)*3+0)=temp1;
				
				temp2=*(varos_diam_paxos+j*3+1);
				*(varos_diam_paxos+j*3+1)=*(varos_diam_paxos+(j+1)*3+1);
				*(varos_diam_paxos+(j+1)*3+1)=temp2;
			}
		}
	}
}
