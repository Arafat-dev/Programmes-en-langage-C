	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<conio.h>
	
	struct ADRESSE{
    	char Ville[20];
    	char Quartier[20];
    	char Rue[20];
    	int Numero;    	
	};
		
	struct Etudiant{
		int Id;
		char Nom[45];
		char Prenom[45];
		char Sexe;
		struct ADRESSE Adresse;     // le champs Adresse est de type structure ADRESSE ci-dessus ;
		char Filiere[25];
		int Niveau_etude;
		float Note_S1;
		float Note_S2;
		float Moy_generale;		
	};

    
    void saisir(struct Etudiant etud[100] , int N ){
    	
    	int i;
    	
    	for(i=0;i<N;i++){
    		 
			etud[i].Id=i+1;
    		
    		printf("\n Entrer les informations de l'etudiant %d \n",i+1);
    		printf("  Nom : ");         fflush(stdin);
    		  gets(etud[i].Nom);        
    		printf("  Prenom : ");
    		  gets(etud[i].Prenom);	
    		                     	 /*  pour lire un caractére après une chaine de carctére ou après 
									        un caractere il faut appeler la fonction "fflush(stdin)" :        */			                      	     
				fflush(stdin);  	 /*  pour effacer ou vider  le tampon de sortie du flux  ===>   c'est une 
			                       	       fonction prédéfinit de la bibliotheque  stdio.h   			                                 
				                    */				                
    		do{
				 printf("  sexe (M/F): ");
	    	 	 scanf("%c",&etud[i].Sexe);
	    	 	 fflush(stdin);
			}while(etud[i].Sexe!='F' && etud[i].Sexe!='M' && etud[i].Sexe!='f' && etud[i].Sexe!='m');
    		
    		printf("  Adresse \n");
    		printf("      Ville : ");
    		scanf("%s",etud[i].Adresse.Ville);     fflush(stdin);
    		printf("      Quartier : ");   		
    		gets(etud[i].Adresse.Quartier);        fflush(stdin);
    		printf("      Rue : ");
    		gets(etud[i].Adresse.Rue);
    		printf("      Numero Rue : ");
    		fflush(stdin);
    		scanf("%d",&etud[i].Adresse.Numero);
    	     
	    	    do{
	    	     	printf("  Filiere (Ingenierie / Management) : ");
	    	        scanf("%s",etud[i].Filiere);
				 }while(strcmp(etud[i].Filiere,"ingenierie")!=0 && strcmp(etud[i].Filiere,"Ingenierie")!=0 && 
				          strcmp(etud[i].Filiere,"INGENIERIE")!=0 && strcmp(etud[i].Filiere,"management")!=0 && 
						  strcmp(etud[i].Filiere,"Management")!=0 && strcmp(etud[i].Filiere,"MANAGEMENT")!=0);
    	    
	    	    do{
	    	    	printf("  Niveau (1/2) : ");
	    	    	scanf("%d",&etud[i].Niveau_etude);
				}while(etud[i].Niveau_etude!=1 && etud[i].Niveau_etude!=2);
    	        
    	        do{
    	        	printf("  Note du Semestre 1 : ");
    	            scanf("%f",&etud[i].Note_S1);
				}while(etud[i].Note_S1<0 || etud[i].Note_S1>20);
    	        do{
    	        	printf("  Note du Semestre 2 : ");
    	   			scanf("%f",&etud[i].Note_S2);
				}while(etud[i].Note_S2<0 || etud[i].Note_S2>20);
    	    
    	    etud[i].Moy_generale = (etud[i].Note_S1+etud[i].Note_S2)/2;
    	    
    	  system("cls");		
		}
	}
   
   
   
    void afficher_Etudiant_par_filiere(struct Etudiant etud[100] , int N){     // fonction qui affiche la liste des etudiant par filiere ;
   	    int i;
   	    
   	        printf("\n        Filiere Ingenierie : \n");
   	        
	   	    for(i=0;i<N;i++){
     	   	      if(strcmp(etud[i].Filiere,"ingenierie")==0 || strcmp(etud[i].Filiere,"Ingenierie")==0            
						  
						  || strcmp(etud[i].Filiere,"INGENIERIE")==0){                  /* Recherche et affichage des étudiants de la filiére d'ingenierie */
	   	   	     	 
					   printf(" \t  %s  \t  %s  \n",etud[i].Nom,etud[i].Prenom);
				  }	 
			}
			  
		      printf("\n        Filiere Management : \n");
		      
	   	   for(i=0;i<N;i++){                                                 /* Recherche et affichage des étudiants de la filiére management */
	   	   	   
			     if(strcmp(etud[i].Filiere,"management")==0 || strcmp(etud[i].Filiere,"Management")==0 
					               || strcmp(etud[i].Filiere,"MANAGEMENT")==0 ){
		   	   	     
						printf(" \t  %s  \t  %s  \n",etud[i].Nom,etud[i].Prenom);
				  }	 
			  }
   }
   
                            /* La fonction qui affiche la liste des etudiants par ordre  alphabétique
							                                                  croissant de nom de famille */
   
   void afficher_croissant_nom(struct Etudiant IE1[100],struct Etudiant IE2[100],
                                   struct Etudiant MT1[100],struct Etudiant MT2[100],
								                                   int j,int d,int h,int l){
								                               
	    int i;														       	 
   	         printf("\n   Niveau 1\n\n     Filiere Ingenierie : \n");
		     
				 for(i=0;i<j;i++){
			     	 printf(" \t  %s  \t  %s \n",IE1[i].Nom,IE1[i].Prenom);
				 } 
			 printf("\n\n     Filiere Management :\n");
				 for(i=0;i<d;i++){
			     	 printf(" \t  %s  \t  %s \n",MT1[i].Nom,MT1[i].Prenom);
				 }  
		     printf("\n\n   Niveau 2\n\n     Filiere Ingenierie : \n");		  
				 for(i=0;i<h;i++){
			     	 printf(" \t   %s  \t  %s   \n",IE2[i].Nom,IE2[i].Prenom);
				 } 
			 printf("\n\n     Filiere Management :\n");
				 for(i=0;i<l;i++){
			     	 printf(" \t  %s  \t  %s \n",MT2[i].Nom,MT2[i].Prenom);
				 }
   }
                                        
										 // fonction qui affiche par ordre decroissante de moyenne genrale;
   
   void afficher_decroissant_moy(struct Etudiant IE1[100],struct Etudiant IE2[100],
                                   struct Etudiant MT1[100],struct Etudiant MT2[100],
								                                   int j,int d,int h,int l){
								                                   	
        int i;								                                   	
             printf("\n   Niveau 1\n     Filiere Ingenierie : \n");
				 for(i=0;i<j;i++){
			     	 printf("  \t  %s  \t  %s  \t  Moyenne Generale = %0.2f\n",IE1[i].Nom,IE1[i].Prenom,IE1[i].Moy_generale);
				 }      
			 printf("\n    Filiere Management :\n");
				 for(i=0;i<d;i++){
			     	 printf("  \t  %s  \t  %s  \t  Moyenne Generale = %0.2f\n",MT1[i].Nom,MT1[i].Prenom,MT1[i].Moy_generale);
				 } 
			 
		     printf("\n\n   Niveau 2\n     Filiere Ingenierie : \n");		 
				 for(i=0;i<h;i++){
			     	 printf("  \t  %s  \t  %s  \t  Moyenne Generale = %0.2f\n",IE2[i].Nom,IE2[i].Prenom,IE2[i].Moy_generale);
				 } 
		     
			 printf("\n    Filiere Management : \n");
				 for(i=0;i<l;i++){
			     	 printf("  \t  %s  \t   %s  \t  Moyenne Generale = %0.2f\n",MT2[i].Nom,MT2[i].Prenom,MT2[i].Moy_generale);
				 }								                                   	
								                                   	
   }
   
                         // la fonction qui trie la liste par ordre  alphabétique croissant de nom de famille;   
   
   void trie_Nom(struct Etudiant tab[100],int N){
   	  int i,j;
      struct Etudiant aide;     
		   j=N-1;
		   while(j>0){
		   	   for(i=0;i<N-1;i++){
		   	   	    if(strcmp(tab[i].Nom,tab[i+1].Nom)==1){  	   	    	 
							 aide=tab[i];
			   	   	    	 tab[i]=tab[i+1];
			   	   	    	 tab[i+1]=aide;
					}
			   }
			  j--; 
		   }
   }   
   
                               /* La fonction qui trie la liste par ordre decroissant de moyenne generale */
                               
   void trie_moyenne(struct Etudiant tab[100],int N){
   	    int i,j;
        struct Etudiant aide;     
		   j=N-1;
		   while(j>0){
		   	   for(i=0;i<N-1;i++){
		   	   	    if(tab[i].Moy_generale<tab[i+1].Moy_generale){
			   	   	    	 
							 aide=tab[i];
			   	   	    	 tab[i]=tab[i+1];
			   	   	    	 tab[i+1]=aide;
					}
			   }
			  j--; 
		   }
   	  
   }                                   /* la fonction suivante : 
									        A. affiche la liste des etudiant par niveau et  par filiere :
			                                        1 : selon l'ordre croissant de nom de famille
													2 : selon l'ordre decroissant de moyenne generale;
									        B. affiche le nombre des etudiants qui ont valider
									  */
     void afficher_Et_f_o(struct Etudiant etud[100] , int N ,int ch){     
        
		int i,j,h,d,l,valE1,valE2,valM1,valM2;
		struct Etudiant IE1[100],IE2[100],MT1[100],MT2[100];
			    
   	           j=0; h=0; d=0; l=0; valE1=0; valE2=0; valM1=0; valM2=0;
	   	    for(i=0;i<N;i++){
	     	   	    if(strcmp(etud[i].Filiere,"ingenierie")==0 || strcmp(etud[i].Filiere,"Ingenierie")==0      
                          || strcmp(etud[i].Filiere,"INGENIERIE")==0){
								        
								if(etud[i].Niveau_etude==1){
			     		   				IE1[j]=etud[i];
										j++;
									 if(etud[i].Moy_generale>=10){ 
										   valE1++;  
									 }		  
								} 
								
								if(etud[i].Niveau_etude==2){
		     	   	       	             IE2[h]=etud[i];
		     	   	       	             h++;		     	   	       	          
		     	   	       	           if(etud[i].Moy_generale>=10){
										     valE2++; 
									   }		     
						        }				 
					     }	 
	
			     	if(strcmp(etud[i].Filiere,"management")==0 || strcmp(etud[i].Filiere,"Management")==0 
					     || strcmp(etud[i].Filiere,"MANAGEMENT")==0 ){		   	   	                
						        
								if(etud[i].Niveau_etude==1){
					                   MT1[d]=etud[i];
					                   d++;
					                if(etud[i].Moy_generale>=10){
										  valM1++;  
									 }
								}	
							    if(etud[i].Niveau_etude==2){
					                   MT2[l]=etud[i];
					                   l++;					                 
					                 if(etud[i].Moy_generale>=10){
										  valM2++;  	
									 }	
							    }	 
				        }
		
			  }
			 
		  trie_Nom(IE1,j);               // appel de la fonction trie_Nom() avec different parametre ;
		  trie_Nom(IE2,h);
		  trie_Nom(MT1,d);
		  trie_Nom(MT2,l);
		  
		  trie_moyenne(IE1,j);          // appel de la fonction trie_moyenne() avec different parametre ;
		  trie_moyenne(IE2,h);
		  trie_moyenne(MT1,d);
		  trie_moyenne(MT2,l);
		  
		  if(ch==2){
		  	     afficher_croissant_nom(IE1,IE2,MT1,MT2,j,d,h,l);
		  }
		  if(ch==3){
		  	     afficher_decroissant_moy(IE1,IE2,MT1,MT2,j,d,h,l);
		  }
		  if(ch==4){
		         printf("\n\n   Filiere Ingenierie : %d presonnes ont valider l annee\n",valE1+valE2);
		         printf("\n   Filiere Management : %d presonnes ont valider l annee\n",valM1+valM2);
		  } 
	   	  	  			  
   }
    
                                                             // fonction qui calcule et returne le pourcentage ;
     float pourcentage(struct Etudiant etud[100] , int N ){
     	   int i,pourcentfv,totalF2;
     	   float p;
     	   pourcentfv=0;  totalF2=0;
     	    for(i=0;i<N;i++){	  	
			          if(etud[i].Niveau_etude==2){		                   
		                   if(etud[i].Sexe=='f' || etud[i].Sexe=='F'){
							 	 totalF2++;
							   if(etud[i].Moy_generale>=10){										  			    
									   pourcentfv++;
							   }	 
   						   }   							
					  }				    	 				       		
			}
		
		    if(totalF2!=0){
			       p=(pourcentfv*100)/totalF2;        // calcule de pourcentage;
			}             
		  
		  return(p);	     	
	 }
	   
	                                                     // calculer et afficher le majorant ingenierie niveau 1 ;
     struct Etudiant majorant_ING1(struct Etudiant etud[100] , int N ){
             
			 struct Etudiant majortING;
			 int i;			 
			 
			     majortING=etud[0];
			 for(i=1;i<N;i++){			 	
			      if(strcmp(etud[i].Filiere,"ingenierie")==0 || strcmp(etud[i].Filiere,"Ingenierie")==0      
                        || strcmp(etud[i].Filiere,"INGENIERIE")==0){								        
							
							if(etud[i].Niveau_etude==1){
			     		   	    
								if(etud[i].Moy_generale>majortING.Moy_generale){
							 	      majortING=etud[i];
			   				    }		  
	   					    } 
			           }
			
			 }
			 			 			 			 
			 return(majortING);			 	     	
	 }
                                                    
                                                      // calculer et afficher le majorant ingenierie niveau 2 ;                                      
     struct Etudiant majorant_ING2(struct Etudiant etud[100] , int N){
     	   struct Etudiant majort_ING2;
			 int i;			 
			 
			     majort_ING2=etud[0];
			 for(i=1;i<N;i++){			 	
			      if(strcmp(etud[i].Filiere,"ingenierie")==0 || strcmp(etud[i].Filiere,"Ingenierie")==0      
                        || strcmp(etud[i].Filiere,"INGENIERIE")==0){								        
							
							if(etud[i].Niveau_etude==2){
			     		   	    
								if(etud[i].Moy_generale>majort_ING2.Moy_generale){
							 	      majort_ING2=etud[i];
			   				    }		  
	   					    } 
			           }
			
			 }
			 
			 return(majort_ING2);	
     	
	 }  
	 
	    void afficher(struct Etudiant tab[100] , int i){
	    	
	    	  printf("\n\n   L'etudiant  : \n");
	    	  printf("    ID : %d\n",tab[i-1].Id);
	    	  printf("    nom : %s \n",tab[i-1].Nom);
	    	  printf("    Prenom : %s\n",tab[i-1].Prenom);
	    	  printf("    Sexe : %c\n",tab[i-1].Sexe);
	    	  printf("    Adresse : %d %s %s %s\n",tab[i-1].Adresse.Numero,tab[i-1].Adresse.Rue,tab[i-1].Adresse.Quartier,tab[i-1].Adresse.Ville);
	    	  printf("    Filiere : %s\n",tab[i-1].Filiere);
	    	  printf("    Niveau : %d\n",tab[i-1].Niveau_etude);
	    	  printf("    Note semestre 1 : %0.2f\n",tab[i-1].Note_S1);
	    	  printf("    Note semestre 2 : %0.2f\n",tab[i-1].Note_S2);
	    	  printf("    Moyeene generale : %0.2f\n",tab[i-1].Moy_generale);
		}
	  
	                                       
												        // fonction principal ;
    
   int main(){
   	  
   	  int choix,N,id;
   	  struct Etudiant liste_Etudiant[100],mjr1,mjr2;
	  
	  do{	 
	  	printf("\n  Entrer Le nombre d etudiants a enregistrer dans la liste (Au moins 2 etudiants): ");
	  	scanf("%d",&N);
	  }while(N<=1);             /*  pour exiger l'utilisateur de saisir 
		                               un nombre strictement supérieur à 1 */
	  
	        	   
   	   saisir(liste_Etudiant,N);     
   	   
		  system("cls");
   	   
   	   while(1){
   	   	   
   	   	     printf("\n\n   Quel traitement Voulez vous effectuer  : \n");
   	   	     
   	   	     printf("\n        1 : Afficher tout les informations d'un etudiant grace a son identifiant unique\n\n"
				      "        2 : Afficher la liste de tous les etudiants saisis par filiere \n\n"
				      "        3 : Afficher la liste de tous les etudiants saisis par niveau  et par filiere \n"
					  "             Selon l ordre alphabetique croissant des noms de famille \n\n"
					  "        4 : Afficher la liste de tous les etudiants saisis par niveau  et par filiere \n"
					  "             Selon  l ordre  decroissant de la moyenne generale \n\n"
					  "        5 : Afficher le nombre des etudiants ayant valide l annee (qui ont eu une\n" 
					  "	     note de Moyenne generale supérieure a 10) pour chaque filiere \n\n"
					  "        6 : Afficher le pourcentage des etudiants de sexe feminin qui ont valide \n   \t     la 2eme annee \n\n"
					  "        7 : Afficher le majorant de la promotion Ingenierie par niveau \n\n"
					  "        8 : Quitter Le programme \n");
   	   	     
   	   	     printf("\n\n     Entrer votre choix : ");
   	   	     scanf("%d",&choix);
   	   	     system("cls");
   	   	         
   	   	         if(choix==1){
   	   	         	            printf("\n\n   Entre l'identifiant de l'etudiant a afficher : ");
								scanf("%d",&id);	    
   	   	         	            afficher(liste_Etudiant,id);
   	   	         	            getch();
					   }
   	   	         if(choix==2){   	   	         	     
   	   	         	      afficher_Etudiant_par_filiere(liste_Etudiant,N);   	   	         	      
   	   	         	      getch();
				  }
				  if(choix==3){				  	      
   	   	         	     afficher_Et_f_o(liste_Etudiant,N,2);   	   	         	     
						 getch();
				  }
				  if(choix==4){   	   	         	      
   	   	         	      afficher_Et_f_o(liste_Etudiant,N,3); 
   	   	         	      getch();
				  }
				  if(choix==5){  	   	         	      
   	   	         	      afficher_Et_f_o(liste_Etudiant,N,4); 
   	   	         	      getch();
				  }
				  if(choix==6){ 
				          printf("\n\n   le pourcentage des etudiants de sexe feminine qui\n \t ont valider la" 
						          " 2 eme annee (niveau 2) est : %0.2f %% \n",pourcentage(liste_Etudiant,N));   	      
   	   	         	      getch();
				  }
				  if(choix==7){
				  	                  mjr1=majorant_ING1(liste_Etudiant,N);
				  	                  mjr2=majorant_ING2(liste_Etudiant,N);
				  	                  
   	   	         	      printf("\n\n  Le majorant de la promotion ingenierie de nievau 1 est : %s %s Avec %0.2f \n ",mjr1.Nom,mjr1.Prenom,mjr1.Moy_generale);
						  printf("\n\n  Le majorant de la promotion ingenierie de nievau 2 est : %s %s Avec %0.2f \n ",mjr2.Nom,mjr2.Prenom,mjr2.Moy_generale); 
   	   	         	      getch();
				  }
				  if(choix==8){
				  	  exit(0);
				  }
			  
			  system("cls");	 
		  }
   	
   	  system("pause");
   	  return 0;
   }
