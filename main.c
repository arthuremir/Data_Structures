#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//#include "avltree.h"
//#include "stack.h"
//#include "middlestack.h"
//#include "linkedlist.h"


void delK(char *s,int K){
    if(K<strlen(s))
    {
        char *m = &s[K+1];
        s[K] = '\0';
        sprintf(s,"%sD%s",s,m);
    }
}

void replace(char a[],char *b,char *c){
    char *t = strstr(a,b);
    while(t!=NULL){
        char *h = t+strlen(b);
        *t = '\0';
        sprintf(a,"%s%s%s",a,c,h);
        t = strstr(a,b);
    }
}


char *canonical(char *path){
    char *t = strstr(path,"/..");
    char *res = malloc(1000);
    while(t!=NULL){
        char *h = t+3;
        char *r = t-1;
        while(*r!='/'){
            r--;
        }
        *r = '\0';
        sprintf(path,"%s%s",path,h);
        t = strstr(path,"/..");
    }
    strcpy(res,path);
    res = realloc(res,strlen(res)+1);
    return res;
}


char *bigbang(char *s){
    char *t = strstr(s,"k");
    int c = 0;
    int q = 0;
    while(t) {
        c = (int)(t-s)-q;
        q+=c;
        *t = '\0';
        char *h = malloc(1000);
        strcpy(h,t+1);
        for(int i = 0;i<=c;i++){
            strcat(s,"k");
        }
        strcat(s,h);
        t = strstr(t+c+1,"k");
        free(h);
    }
    return s;
}

char *collapse(char *s){
    char *t = s+1;
    while(*t!='\0'){
        if(*t==*(t-1)){
            *(t-1) = '\0';
            strcat(s,t);
        } else {
            t++;
        }
    }
    //s = realloc(s,strlen(s)+1);
    return s;
}


char *unroll(char *s){
    int c = s[strlen(s)-1] - '0';
    s[strlen(s)-1] = '\0';
    char *r = malloc(c*(strlen(s)-1)+1);
    //strcpy(r,s);
    for(int i = 0;i<c;i++){
        strcat(r,s);
    }
    return r;
}


char **split(char *s){
    char **a = malloc(1000*sizeof(char*));
    char *q = malloc(sizeof(char)*(strlen(s)+1));
    int i = 0;
    strcpy(q,s);
    char *t = strstr(q,";");
    while(t){
        char *h = t+1;
        *t = '\0';
        a[i] = malloc(sizeof(char)*(strlen(q)+1));
        strcpy(a[i++],q);
        q = h;
        t = strstr(q,";");
    }
    a[i] = malloc(sizeof(char)*(strlen(q)+1));
    strcpy(a[i],q);
    return a;
}



char *longest(char **list){
    int len = 0;
    char *c = malloc(len*sizeof(char));
    for(int i = 0;i<strlen(*list);i++){
        for(char **s = list;*s!=NULL;s++){
            if(*(*s+i)!=*(*list+i)){
                c[i] = '\0';
                return c;
            }
        }
        c = realloc(c,(++len)*sizeof(char));
        c[i] = *(*list+i);
    }
    c[len] = '\0';
    return c;
}



int main(void) {
    char **a = malloc(1000*sizeof(char*));
    *(a+0) = "dbc";
    *(a+1) = "def";
    *(a+2) = "dbb";
    *(a+3) = NULL;
    //longest(a);
    char *t = longest(a);
    printf("%s %d",t,strlen(t));


}






























