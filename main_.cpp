//
// Created by tonggege on 17-11-14.
//
/**
#include <stdio.h>
#include "SequenceList.h"

void visit(ElemType e){
    printf(" * %d *",e);
}

int compare(ElemType a,ElemType b){
    if(a==b) return 0;
    else return -1;
}
int main(void){
    SqList * L = NULL;  int op=1;
    int index;
    ElemType e;

    while(op){
        //  system("cls");
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. IntiaList       7. LocateElem\n");
        printf("    	  2. DestroyList     8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty     10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem       12. ListTrabverse\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~12]:");
        scanf("%d",&op);
        switch(op){
            case 1:
                //printf("\n----IntiaList功能待实现！\n");
                if(InitList(&L)==OK) printf("线性表创建成功！\n");
                else printf("线性表创建失败！\n");
                break;
            case 2:
                if(DestroyList(&L)==OK){
                    L = NULL;
                    printf("线性表销毁成功！\n");
                }
                getchar();getchar();
                break;
            case 3:
                if(ClearList(L)==OK)printf("\n线性表清除成功！\n");
                getchar();getchar();
                break;
            case 4:
                ListEmpty(L)==TRUE?printf("\n线性表为空\n"):printf("\n线性表不为空\n");
                getchar();getchar();
                break;
            case 5:
                printf("\n线性表的长度为%d\n",ListLength(L));
                getchar();getchar();
                break;
            case 6:
                printf("\n请输入元素位序\n");scanf("%d",&index);
                getchar();
                if(!GetElem(L,index,&e)){
                    printf("元素为%d\n",e);
                }
                else printf("错误！");

                break;
            case 7:
                printf("请输入元素:");
                scanf("%d",&e);
                printf("\n元素序号是：%d\n",LocateElem(L,e,(void *)(&compare)));
                getchar();getchar();
                break;
            case 8:
                printf("请输入节点值：\n");scanf("%d",&e);
                if(PriorElem(L,e,&e)!= ERROR){
                    printf("该元素的前驱元素为：%d",e);
                }
                else printf("\n错误\n");
                getchar();getchar();
                break;
            case 9:
                printf("请输入节点值：\n");scanf("%d",&e);
                if(NextElem(L,e,&e)!= ERROR){
                    printf("该元素的后继元素为：%d",e);
                }
                else printf("\n输入错误\n");
                getchar();getchar();
                break;
            case 10:
                printf("请输入插入位序：\n");
                scanf("%d",&index);
                printf("请输入元素值：\n");
                scanf("%d",&e);
                if(ListInsert(L,index,e)!=ERROR) printf("\n插入成功！\n");
                else printf("插入失败！");
                getchar();getchar();
                break;
            case 11:
                printf("请输入删除位序：\n");
                scanf("%d",&index);
                ListDelete(L,index,&e);
                printf("\n元素%d已被删除！\n",e);
                getchar();
                break;
            case 12:
                if(!ListTraverse(L,(void *)(&visit))) printf("线性表是空表！\n");
                getchar();
                break;
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}//end of main()
 **/