#include <stdio.h>
#include <ctype.h>
#include <string.h>

void exo1Calculatrice(){
    int number1, number2 , result ;
    int addition = 1 , soustraction = 2 , multiplication = 3 , division = 4;
    int operationType = 0 ; 
    
    printf("Enter first number: ");
    scanf("%d", &number1);
    printf("Enter secound number: ");
    scanf("%d", &number2);

    printf("Select your oeperation : \n Enter 1 for (+) \n Enter 2 for (-) \n Enter 3 for (x) \n Enter 4 for (/) \n : ");
    scanf("%d",&operationType);

    if(operationType == addition){
        result = number1 + number2 ; 
    }else if(operationType == soustraction){
        result = number1 - number2 ; 
    }else if(operationType == multiplication){
        result = number1 * number2 ; 
    }else if(operationType == division){
        result = number1 / number2 ;
    }
    printf("Result : %d",result);
}

void exo2Echange(){
    int number1 , number2 , cache ;

    printf("Enter first number : ");
    scanf("%d", &number1);
    printf("Enter secound number : ");
    scanf("%d", &number2);

    printf("Before -------------\n Number 1 : %d , Number 2 : %d \n", number1 , number2);
    cache = number1 ; 
    number1 = number2 ; 
    number2 = cache ;
    printf("After -------------\n Number 1 : %d , Number 2 : %d \n", number1 , number2);
}

void exo3RechercherLaPlusGrandValeurDansUnTableau(){
    int table[] = {1,2,3,7,30,3,8,9,12,2};
    int largeNumber = table[0]; 

    for(int i = 0 ; i<9 ; i++){
        if(table[i] > largeNumber){
            largeNumber = table[i];
        }
    }

    printf("\n Large Number in our list : %d" , largeNumber);
}

void exo4AfficheChaine(char* chaine){
    for(int i = 0 ; i< 30 ; i++){
        printf("%c ",chaine[i]);
    }
}

int exo5Voyelle(char* chaine){
    char voyelleChar[3] = "AOE";
    int voyelleCharNumber = 0 ;

    for(int charMessageIndex = 0 ; charMessageIndex < 30 ;charMessageIndex++){
        for(int voyelleCharIndex = 0 ; voyelleCharIndex < 3 ; voyelleCharIndex++){
            if(chaine[charMessageIndex] == voyelleChar[voyelleCharIndex]){
                voyelleCharNumber ++ ; 
            }
        }
    }
    printf("Number Of Voyelles : %d ",voyelleCharNumber);
    return voyelleCharNumber ; 
}

void exo6VerificationDeLoginEtModeDePasse(char* login , char* password){
   int PasswordhasUpperChar = 0 ; 
   int allLoginIsAlphaNumerique = 1 ; 
   int sizeOfPasswordSupThen10Char = 1 ; 
   int isLoginLikePassword = 0 ; 
   int loginStartByAlpha = 1 ; 
   int loginSize =  strlen(login) ;
   int passwordSize =  strlen(password) ;
   
    if(!isalpha(login[0])){
      loginStartByAlpha = 0;
    }
    
    for(int i = 0 ; i < loginSize ; i++ ){

        if(!isalpha(login[i])){
            if(!isdigit(login[i])){
               allLoginIsAlphaNumerique = 0 ; 
            }
        }
    }
    
    for(int i = 0 ; i < passwordSize ; i++ ){
        if(isupper(password[i])){
          PasswordhasUpperChar = 1 ; 
        }
    }

    if(passwordSize < 10){
        sizeOfPasswordSupThen10Char = 0 ;
    }

    if(strcmp(login , password) == 0){
        isLoginLikePassword = 1 ;
    }

    if(!loginStartByAlpha){
      printf("ERROR : le login \" %c \" n'est pas valide car ce login commence par un chiffre",login );
    }
    if(!allLoginIsAlphaNumerique){
        printf("ERROR : login \" %s \" n'est pas valide car celui-ci ne contient un caractere Bizar \n", login  );
        
    }
    if(!PasswordhasUpperChar) {
        printf("ERROR : password \" %s \" n'est pas valide car celui-ci ne contient pas un caractere majuscule \n", password );
       
    }
    if(!sizeOfPasswordSupThen10Char){
        printf("ERROR : password \" %s \" small then 10 character \n", password );
       
    }
    if(isLoginLikePassword){
         printf("ERROR : Password must not be like login \n" );
       
    }
    int loginAndPasswordRight = loginStartByAlpha && allLoginIsAlphaNumerique && PasswordhasUpperChar && sizeOfPasswordSupThen10Char && !isLoginLikePassword ;

    if(loginAndPasswordRight){
        printf("SUCESS \n LOGIN : %s \n PASSWORD : %s \n",login , password );
    }

   // 

}

int main(void){
    char message[30] = "Zerrouk/Hacene";
    char voyelleChar[20] = "OUT OF DORE ";

    char login[20] = "hacD12313";
    char password[20] = "hacD123134";

    // exo1Calculatrice();
    // exo2Echange();
    // exo3RechercherLaPlusGrandValeurDansUnTableau();
    // exo4AfficheChaine(message);
    // exo5Voyelle(voyelleChar); 

    exo6VerificationDeLoginEtModeDePasse(login , password);
    return 0;
}