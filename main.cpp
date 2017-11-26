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
    printf("������c:\n");scanf("%c",&e->c);
    printf("������d:\n");scanf("%d",&e->d);
    printf("������f:\n");scanf("%f",&e->f);
}
int Output(ElemType e){
    printf("C��ֵΪ%c,",e.c);
    printf("D��ֵΪ%d,",e.d);
    printf("F��ֵΪ%f",e.f);
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
        printf("    ��ѡ����Ĳ���[0~12]:");
        scanf("%d",&op);
        switch(op){
            case 1:
                //printf("\n----IntiaList���ܴ�ʵ�֣�\n");
                if(InitList(&L)==OK) printf("���Ա����ɹ���\n");
                else printf("���Ա���ʧ�ܣ�\n");
                break;
            case 2:
                if(DestroyList(&L)==OK){
                    L = NULL;
                    printf("���Ա����ٳɹ���\n");
                }
                getchar();getchar();
                break;
            case 3:
                if(ClearList(L)==OK)printf("\n���Ա�����ɹ���\n");
                getchar();getchar();
                break;
            case 4:
                ListEmpty(L)==TRUE?printf("\n���Ա�Ϊ��\n"):printf("\n���Ա�Ϊ��\n");
                getchar();getchar();
                break;
            case 5:
                printf("\n���Ա�ĳ���Ϊ%d\n",ListLength(L));
                getchar();getchar();
                break;
            case 6:
                printf("\n������Ԫ��λ��\n");scanf("%d",&index);
                getchar();
                if(GetElem(L,index,&e)){
                    Output(e);
                }
                else printf("����");

                break;
            case 7:
                printf("������Ԫ��:");
                Input(&e);
                printf("\nԪ������ǣ�%d\n",LocateElem(L,e,(void *)(&compare)));
                getchar();getchar();
                break;
            case 8:
                printf("������ڵ�ֵ��\n");Input(&e);
                if(PriorElem(L,e,&e2)!= ERROR){
                    Output(e2);
                }
                else printf("\n����\n");
                getchar();getchar();
                break;
            case 9:
                printf("������ڵ�ֵ��\n");Input(&e);
                if(NextElem(L,e,&e2)!= ERROR){
                    Output(e2);
                }
                else printf("\n�������\n");
                getchar();getchar();
                break;
            case 10:
                printf("���������λ��\n");
                scanf("%d",&index);
                printf("������Ԫ��ֵ��\n");
                Input(&e);
                if(ListInsert(L,index,e)!=ERROR) printf("\n����ɹ���\n");
                else printf("����ʧ�ܣ�");
                getchar();getchar();
                break;
            case 11:
                printf("������ɾ��λ��\n");
                scanf("%d",&index);
                ListDelete(L,index,&e);
                printf("\nԪ��%c,%d,%f�ѱ�ɾ����\n",e.c,e.d,e.f);
                getchar();
                break;
            case 12:
                if(!ListTraverse(L,(void *)(&visit))) printf("���Ա��ǿձ�\n");
                getchar();
                break;
            case 13:
                if(LoadData(L)==ERROR)  printf("����");
                else printf("���سɹ���");
                break;
            case 14:
                if(SaveData(L)==ERROR) printf("����");
                else printf("���̳ɹ�");
                break;
            case 15:
                if(ChangeSqList(&L,Lists,&current)==ERROR) printf("����");
                break;
            case 0:
                break;
        }//end of switch
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()