//
// Created by tonggege on 17-11-14.
//
#include <stdio.h>
#include "SequenceList.h"

void visit(ElemType e){
    printf(" * %c %d %f *",e.c,e.d,e.f);
}

int compare(ElemType a,ElemType b){
    if(a.d==b.d && (a.f-b.f) < 0.001 && a.c==b.c) return 0;
    else return 1;
}
int Input(ElemType *e){
    getchar();
    printf("请输入c:\n");scanf("%c",&e->c);
    printf("请输入d:\n");scanf("%d",&e->d);
    printf("请输入f:\n");scanf("%f",&e->f);
}
int Output(ElemType e){
    printf("C的值为%c,",e.c);
    printf("D的值为%d,",e.d);
    printf("F的值为%f",e.f);
}

SqList * Lists[10];
int current;
int main(void){
    SqList * L = NULL;  int op=1;
    int index;current = 1;
    ElemType e;
    ElemType e2;
    while(op){
      //  system("cls");
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. IntiaList       8. PriorElem\n");
        printf("    	  2. DestroyList     9. NextElem\n");
        printf("    	  3. ClearList       10. ListInsert\n");
        printf("    	  4. ListEmpty       11. ListDelete\n");
        printf("    	  5. ListLength      12. ListTrabverse\n");
        printf("    	  6. GetElem         13. LoadData\n");
        printf("    	  7.LoacteElem       14.SaveData\n");
        printf("    	  15. ChangeSqList   0. Exit   \n");
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
                if(GetElem(L,index,&e)){
                    Output(e);
                }
                else printf("错误！");

                break;
            case 7:
                printf("请输入元素:");
                Input(&e);
                printf("\n元素序号是：%d\n",LocateElem(L,e,(void *)(&compare)));
                getchar();getchar();
                break;
            case 8:
                printf("请输入节点值：\n");Input(&e);
                if(PriorElem(L,e,&e2)!= ERROR){
                    Output(e2);
                }
                else printf("\n错误\n");
                getchar();getchar();
                break;
            case 9:
                printf("请输入节点值：\n");Input(&e);
                if(NextElem(L,e,&e2)!= ERROR){
                    Output(e2);
                }
                else printf("\n输入错误\n");
                getchar();getchar();
                break;
            case 10:
                printf("请输入插入位序：\n");
                scanf("%d",&index);
                printf("请输入元素值：\n");
                Input(&e);
                if(ListInsert(L,index,e)!=ERROR) printf("\n插入成功！\n");
                else printf("插入失败！");
                getchar();getchar();
                break;
            case 11:
                printf("请输入删除位序：\n");
                scanf("%d",&index);
                ListDelete(L,index,&e);
                printf("\n元素%c,%d,%f已被删除！\n",e.c,e.d,e.f);
                getchar();
                break;
            case 12:
                if(!ListTraverse(L,(void *)(&visit))) printf("线性表是空表！\n");
                getchar();
                break;
            case 13:
                if(LoadData(L)==ERROR)  printf("错误！");
                else printf("加载成功！");
                break;
            case 14:
                if(SaveData(L)==ERROR) printf("出错！");
                else printf("存盘成功");
                break;
            case 15:
                if(ChangeSqList(&L,Lists,&current)==ERROR) printf("出错！");
                break;
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("欢迎下次再使用本系统！\n");
}//end of main()