#include <stdio.h>

typedef union uval{
    long a;
    double b;
    char * c;
} uval;

typedef struct pval{
    uval val;
    int phptype;
} pval;

//enum

void var_dump(pval);

int main(){

    pval pval1 = {{.a = 111}, 1};

    var_dump(pval1);// int 111


    pval1.phptype = 2;
    pval1.val.b = 1.21;

    var_dump(pval1);// float 1.210000

    pval1.phptype = 3;
    pval1.val.c = "abc";

    var_dump(pval1);// string abc

}


/**
 * @param val
 * 根据pval变量类型，决定读取联合体的那个类型
 */
void var_dump(pval val){
    if(val.phptype == 1){
        printf("%s ", "int");
        printf("%ld\n", val.val.a);
    } else if(val.phptype == 2){
        printf("%s ", "float");
        printf("%f\n", val.val.b);
    } else if(val.phptype == 3){
        printf("%s ", "string");
        printf("%s\n", val.val.c);
    }
}
