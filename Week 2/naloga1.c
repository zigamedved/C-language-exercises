#include <stdio.h>

int main(){
    
    
    //situacija, kjer sta dva ++ oz -- je       0
    //situacija, kjer je samo en ali poljubno veliko - oz + je    0
    //situacija, kjer je samo en +||- in cifre je      1
    //situacija, kjer je samo 0 je       1
    //situacija, kjer so samo stevilke je     1
    
    
    char ch;
    ch=getchar();
    int steviloZnakov=0;
    int steviloStevk=0;
    char da = '1';
    char ne = '0';
    int edgeCase=0;
    int steviloNicel=0;
    int flag = 0;
    int skupno=0;
    int flag2=0;
    int nula=0;
    
    while(ch!='\n'){
        
        
        if(ch =='+' || ch == '-'){
            steviloZnakov++;
            if(skupno>0){
                flag2=1;
            }
            
        }else if((ch-'0')<=9 && (ch-'0')>=0){
            if(steviloStevk==0 && skupno==0){
                if(ch=='0'){
                    //edgeCase=1;
                    steviloNicel++;
                    flag=1;
                }
            }
            steviloStevk++;
                skupno++;
        }else if(ch=='.'){
            nula=1;
        }
               
        
        if(ch==' '){
            //resetiraj in izpisi...
            if(nula==1){
                putchar(ne);
            }else if(steviloZnakov>1){
                putchar(ne);
            }else if(flag==1 && steviloNicel==1 && skupno==1 &&flag2 ==0){
                putchar(da);
                
            }else if(flag2==1){
                putchar(ne);
            }else if(flag==1 && steviloNicel==1 && skupno==1){
                putchar(da);
            }else if(flag==1 && steviloStevk>1 ){
                putchar(ne);
            }else if(steviloNicel==1){
                if(steviloZnakov==1){
                    if(flag==1){
                        putchar(ne);
                    }else
                        putchar(da);
                }else if(steviloZnakov>1){
                    putchar(ne);
                }
                else
                    putchar(da);
            }
            else if(edgeCase==1){
                if(steviloStevk>1){
                    putchar(ne);
                }
            }else if(edgeCase==1){
                if(steviloStevk==1){
                    putchar(da);
                }
            }
            else if(steviloStevk>0 && steviloZnakov<=1){
                putchar(da);
            }else if(steviloZnakov==1){
                putchar(ne);
            }else if(edgeCase==1 && steviloZnakov==1){
                putchar(da);
            }
            
            nula=0;
            steviloNicel=0;
            steviloStevk=0;
            steviloZnakov=0;
            edgeCase=0;
            flag=0;
            skupno=0;
            flag2=0;
        }
        
        ch=getchar();
    }
    
    if(nula==1){
        putchar(ne);
        }else if(steviloZnakov>1){
                putchar(ne);
        }else if(flag==1 && steviloNicel==1 && skupno==1 &&flag2 ==0){
            putchar(da);
            
        }else if(flag2==1){
            putchar(ne);
        }
        else if(flag == 1 && steviloZnakov ==1){
            putchar(ne);
        }else if(flag==1 && steviloZnakov==1 && steviloNicel==1){
            putchar(da);
        }else if(flag==1 && steviloStevk>1 ){
                putchar(ne);
        }
        else if(steviloNicel==1){
                
                if(steviloZnakov==1){
                    if(flag == 0){
                        putchar(da);
                    }else
                        putchar(ne);
                    
                }else if(steviloZnakov>1){
                    putchar(ne);
                }
                else
                    putchar(da);
        }else if(edgeCase==1){
                if(steviloStevk>1){
                    putchar(ne);
                }
        }else if(edgeCase==1){
                if(steviloStevk==1){
                    putchar(da);
                }
        }else if(steviloStevk>0 && steviloZnakov<=1){
                putchar(da);
        }else if(steviloZnakov==1){
            putchar(ne);
        }else if(edgeCase==1 && steviloZnakov ==1){
            putchar(da);
        }
 
    
    return 0;
}
