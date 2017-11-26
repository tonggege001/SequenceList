//
// Created by tonggege on 17-10-14.
//

#include "SequenceList.h"
#include <stdlib.h>
#include <stdio.h>
/**һЩ˵����
 * �����Ա���Ŵ�1��ʼ���ײ������0��ʼ
 */

/**func: ��ʼ������
 * @������� ����һ���յ����Ա�L
 * @param L ˳���ĵ�ַ
 * @return ״̬��
 */

Status InitList(SqList ** L){
    if(*L!=NULL) {
        printf("���Ա��Ѵ��ڣ�");
        return ERROR;
    }
    //����һ�����Ա�
    if(!((*L) = (SqList *)malloc(sizeof(SqList)))) return ERROR;
    (*L)->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType)); //����ռ�
    if((*L)->elem == NULL) exit(OVERFLOW);  //�������ʧ�����˳����������ش�����
    (*L)->length = 0;  //��ʼ����Ϊ0
    (*L)->listsize = LIST_INIT_SIZE;  //��ʼ�洢����,��sizeof(ElemType)Ϊ��λ
    return OK;
}

/**func: �������Ա�
 * @��ʼ���� :���Ա�L�Ѵ���
 * @������� :�������Ա�L
 * @param L ˳���ĵ�ַ
 * @return ״̬��
 */

Status DestroyList(SqList ** L){
    if((*L)==NULL) return ERROR;
    if((*L)->elem ==NULL || (*L)->listsize == 0) exit(ERROR); //�ж����Ա�L�Ƿ��Ѿ�����
    free((*L)->elem);    //�ͷſռ�
    (*L)->listsize = 0;    //���ô洢����Ϊ0
    (*L)->length = 0;      //�������Ա���Ϊ0
    free(*L);
    return OK;      //����״̬��
}

/**func ������Ա�
 * @��ʼ���� ���Ա�L�Ѵ���
 * @param L ���Ա�
 * @return ״̬��
 */
Status ClearList(SqList * L){
    if(L==NULL) return ERROR;
    if(L->elem ==NULL || L->listsize == 0) exit(ERROR); //�ж����Ա�L�Ƿ��Ѿ�����
    free(L->elem);      //�ͷſռ�
    L->elem = (ElemType * )malloc(LIST_INIT_SIZE * sizeof(ElemType));   //���·����ʼ��
    L->listsize = LIST_INIT_SIZE;
    L->length = 0;
    return OK;
}

/**func �ж����Ա��Ƿ�Ϊ��
 * @param L
 * @return
 */

int ListEmpty(SqList * L){
    if(L->length == 0 || L->listsize == 0) return TRUE;
    else return FALSE;
}


/**func ��ȡ���Ա���
 * @param L
 * @return ״̬��
 */

int ListLength(const SqList * L){
    if(L->listsize!=0) return L->length;
    else return 0;
}

/**func ��õ�i��Ԫ�ز��洢��e��
 * @��ʼ���� ���Ա���� ����i<= ��length
 * @param L ���Ա�L
 * @param i ����i
 * @param e ���Ԫ�صĵ�ַe
 * @return ״̬��
 */
Status GetElem(const SqList *  L, int i, ElemType * e){
    if(!L) return ERROR;
    if(L->listsize <= 0) return(ERROR); //�ж����Ա��Ƿ����
    if(i> ListLength(L)) return (ERROR); //�ж��Ƿ�Ϊ�ձ�
    ElemType * List = L->elem;  //��ȡ����ַ
    *e = List[i-1]; //���Ա��ȡԪ�ص�ʱ��ĸ��Ӷ��ǳ���O(1)
    return OK;
}

/**func ����L�е�1����e�����ϵcompare������Դ�ص�λ��.������������Ԫ�ز�����,�򷵻�ֵΪ0
 * @��ʼ���� ���Ա�L�Ѵ���,compare�Ѷ���
 * @param L ���Ա�L
 * @param e ���Ƚϵ�Ԫ��
 * @param compare �ȽϺ���
 * @return λ��
 */
int LocateElem(SqList * L, ElemType e, void *  compare){
    if(!L) return ERROR;
    if(L->listsize == 0 || L->length == 0) return 0;
    int ( *cmp)(ElemType a,ElemType b);
    cmp = (int (*)(ElemType ,ElemType))compare;

    ElemType  *List = L->elem; //��ȡ����ַ
    int flag = FALSE;   //�жϵ�ǰ�Ƿ��ҵ�������Ԫ��
    int index = -1; //��Ų��ҵ�������
    for(int i = 0;i<ListLength(L) && flag != TRUE;i++){
        if(cmp(List[i],e) == 0){
            flag = TRUE;   //�ҵ���־
            index = i+1;    //�ײ������±��ʵ��λ���1
        }
        if(flag != 0) break;    //����ҵ�������Ԫ�ؾͲ�����������,����ѭ��
    }
    if(flag) return index;
    else return 0;
}

/**func ���cur_e��ǰ��
 * @��ʼ���� L����,cur_e������Ԫ��,cur_e��L��
 * @param L ���Ա�
 * @param cur_e Ԫ��
 * @param pre_e ǰ��ָ��
 * @return ״̬��
 */
Status PriorElem(const SqList * L, ElemType cur_e, ElemType * pre_e){
    if(L->listsize == 0 || L->length <= 1) return (ERROR); //��������ڻ��߱�С��1,��ô���ش�����
    const ElemType * List = L->elem;
    if(compare(List[0],cur_e)==0) return (ERROR); //�����Ԫ���ǵ�һ��Ԫ��,�򷵻ش�����
    int flag = FALSE;   //�жϵ�ǰ�Ƿ���ҵ�
    for(int i = 0;i<ListLength(L) && flag !=TRUE;i++){
        if(compare(List[i],cur_e)==0){
            flag = TRUE;    //�ҵ���־
            if(pre_e!=NULL) *pre_e = List[i-1];
        }
    }
    return OK;
}


/**func ���cur_e�ĺ��
 * @��ʼ���� L����,cur_e�������һ��Ԫ��,cur_e��L��
 * @param L ���Ա�
 * @param cur_e Ԫ��
 * @param next_e ǰ��ָ��
 * @return ״̬��
 */
Status NextElem(const SqList * L, const ElemType cur_e, ElemType * next_e){
    if(L->listsize == 0 || L->length <=1 ) return(ERROR);     //��������ڻ��߱�С��1,��ô���ش�����
    const ElemType * List = L->elem;
    if(compare(List[L->length-1] , cur_e)==0) return(ERROR); //�����Ԫ�����һ��Ԫ��,�򷵻ش�����

    int flag = FALSE;      //�жϵ�ǰ�Ƿ���ҵ�
    for(int i = 0;i< ListLength(L) && flag != TRUE; i++){   //�˳�ѭ�������Ǳ�β���ҵ�Ԫ��
        if(compare(List[i],cur_e)==0){     //����ҵ�
            flag = TRUE;
            if(next_e!=NULL) *next_e = List[i+1];
        }
    }
    return OK;
}

/**func:�ڵ�i��λ�ò���e
 * @param L ˳���
 * @param i λ��
 * @param e Ԫ��
 * @return ״̬��
 */
Status ListInsert(SqList * L, int i, ElemType e){
    if(!L) return ERROR;
    if(L->listsize == 0) return(ERROR); //�ж����Ա��Ƿ����
    if(i<=0 || i > L->length + 1) return(ERROR);  //�ж�λ���Ƿ��ǺϷ�
    if(L->listsize==L->length){
        L->elem = (ElemType *)realloc(L->elem,L->listsize+LISTINCREMENT);
    }
    ElemType * List = L->elem; //��ȡ �ռ����ַ
    int j = ListLength(L);  //�Ӻ���ǰ�ƶ�
    for(; j >= i; j--){
        List[j] = List[j-1];
    }
    List[j] = e;    //���в���
    L->length++;//���ȼ�һ
    return OK;

}

/**func:ɾ����i��Ԫ��
 *
 * @param L ���Ա�
 * @param i ���
 * @param e ���汻ɾ��Ԫ�صĵ�ַ
 * @return ״̬��
 */
Status  ListDelete(SqList * L,int i,ElemType * e){
    if(L->listsize<=0||L->elem==NULL) return ERROR;
    if(i<=0||i>L->length) return ERROR;
    if(e!=NULL) *e = L->elem[i-1];//��λɾ��λ�õ�
    for(int j = i-1;j<ListLength(L)-1;j++){ //��ɾ��λ�ÿ�ʼ���������ƶ�
        L->elem[j] = L->elem[j+1];
    }
    L->length--;//���±�
    return OK;
}

/**
 * func ʹ��visit��������ÿһ��Ԫ��
 * @param L ���Ա�
 * @param visit ��������
 * @return ״̬��
 */
Status ListTraverse(SqList * L,void * visit){
    if(L==NULL) return ERROR;
    if(L->listsize<=0||L->length<=0) return ERROR;
    void (*vis)(ElemType) = (void (*)(ElemType))(visit);//��������
    for(int i = 0;i<L->length;i++) vis(L->elem[i]);
    return OK;
}

/**
 * func:�����ļ�
 * @param L ���Ա��ַ
 * @return ״̬��
 */
Status LoadData(SqList * L){
    if(L==NULL) return ERROR;
    ElemType e;
    FILE * fp;
    if(!(fp = fopen("file","rb"))) return ERROR; //���ļ�
    int i = 1;
    while(fread(&e,1,sizeof(ElemType),fp)!=0){//��ȡ�ļ�������
        ListInsert(L,i,e);
        i++;
    }
    fclose(fp);//�ر��ļ�
    return OK;
}

/**
 * func ������Ϣ
 * @param L ���Ա��ַ
 * @return ״̬��
 */
Status SaveData(SqList * L){
    if(L==NULL)return ERROR;
    ElemType e;//��ȡԪ���ݴ�ĵ�Ԫ
    FILE * fp;
    fp = fopen("file","wb");//���ļ�
    for(int i = 1;i<=L->length;i++){
        GetElem(L,i,&e);//��ȡԪ��
        fwrite(&e,1,sizeof(ElemType),fp);//д���ļ�
    }
    fclose(fp);//�ر��ļ�
    return OK;
}

/**
 * func:�л����Ա�
 * @param Prior �������Ա��ַ
 * @param lists �б�
 * @param cur ��ǰ�б����
 * @return ״̬��
 */
Status ChangeSqList(SqList ** Prior,SqList ** lists,int *cur){
    int n = 1;
    printf("���л����ڼ���˳���");
    scanf("%d",&n);//��ȡ���Ա���ţ�1��10
    if(n<=0 || n>=11) return ERROR;
    lists[(*cur)-1] = *Prior;//������һ��
    *cur = n;
    (*Prior) = lists[n-1];
    printf("�л��ɹ�!");
    return OK;
}





















