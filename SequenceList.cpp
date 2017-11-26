//
// Created by tonggege on 17-10-14.
//

#include "SequenceList.h"
#include <stdlib.h>
#include <stdio.h>
/**一些说明：
 * ①线性表序号从1开始，底层数组从0开始
 */

/**func: 初始化链表
 * @操作结果 构造一个空的线性表L
 * @param L 顺序表的地址
 * @return 状态码
 */

Status InitList(SqList ** L){
    if(*L!=NULL) {
        printf("线性表已存在！");
        return ERROR;
    }
    //构造一个线性表
    if(!((*L) = (SqList *)malloc(sizeof(SqList)))) return ERROR;
    (*L)->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType)); //分配空间
    if((*L)->elem == NULL) exit(OVERFLOW);  //如果分配失败则退出函数并返回错误码
    (*L)->length = 0;  //初始长度为0
    (*L)->listsize = LIST_INIT_SIZE;  //初始存储容量,以sizeof(ElemType)为单位
    return OK;
}

/**func: 销毁线性表
 * @初始条件 :线性表L已存在
 * @操作结果 :销毁线性表L
 * @param L 顺序表的地址
 * @return 状态码
 */

Status DestroyList(SqList ** L){
    if((*L)==NULL) return ERROR;
    if((*L)->elem ==NULL || (*L)->listsize == 0) exit(ERROR); //判断线性表L是否已经存在
    free((*L)->elem);    //释放空间
    (*L)->listsize = 0;    //设置存储容量为0
    (*L)->length = 0;      //设置线性表长度为0
    free(*L);
    return OK;      //返回状态码
}

/**func 清空线性表
 * @初始条件 线性表L已存在
 * @param L 线性表
 * @return 状态码
 */
Status ClearList(SqList * L){
    if(L==NULL) return ERROR;
    if(L->elem ==NULL || L->listsize == 0) exit(ERROR); //判断线性表L是否已经存在
    free(L->elem);      //释放空间
    L->elem = (ElemType * )malloc(LIST_INIT_SIZE * sizeof(ElemType));   //重新分配初始量
    L->listsize = LIST_INIT_SIZE;
    L->length = 0;
    return OK;
}

/**func 判断线性表是否为空
 * @param L
 * @return
 */

int ListEmpty(SqList * L){
    if(L->length == 0 || L->listsize == 0) return TRUE;
    else return FALSE;
}


/**func 获取线性表长度
 * @param L
 * @return 状态码
 */

int ListLength(const SqList * L){
    if(L->listsize!=0) return L->length;
    else return 0;
}

/**func 获得第i个元素并存储到e中
 * @初始条件 线性表存在 索引i<= 表长length
 * @param L 线性表L
 * @param i 索引i
 * @param e 获得元素的地址e
 * @return 状态码
 */
Status GetElem(const SqList *  L, int i, ElemType * e){
    if(!L) return ERROR;
    if(L->listsize <= 0) return(ERROR); //判断线性表是否存在
    if(i> ListLength(L)) return (ERROR); //判断是否为空表
    ElemType * List = L->elem;  //获取基地址
    *e = List[i-1]; //线性表获取元素的时间的复杂度是常数O(1)
    return OK;
}

/**func 返回L中第1个与e满足关系compare的数据源素的位序.若这样的数据元素不存在,则返回值为0
 * @初始条件 线性表L已存在,compare已定义
 * @param L 线性表L
 * @param e 待比较的元素
 * @param compare 比较函数
 * @return 位序
 */
int LocateElem(SqList * L, ElemType e, void *  compare){
    if(!L) return ERROR;
    if(L->listsize == 0 || L->length == 0) return 0;
    int ( *cmp)(ElemType a,ElemType b);
    cmp = (int (*)(ElemType ,ElemType))compare;

    ElemType  *List = L->elem; //获取基地址
    int flag = FALSE;   //判断当前是否找到这样的元素
    int index = -1; //存放查找到的索引
    for(int i = 0;i<ListLength(L) && flag != TRUE;i++){
        if(cmp(List[i],e) == 0){
            flag = TRUE;   //找到标志
            index = i+1;    //底层数组下标和实际位序差1
        }
        if(flag != 0) break;    //如果找到这样的元素就不继续查找了,跳出循环
    }
    if(flag) return index;
    else return 0;
}

/**func 获得cur_e的前驱
 * @初始条件 L存在,cur_e不是首元素,cur_e在L中
 * @param L 线性表
 * @param cur_e 元素
 * @param pre_e 前驱指针
 * @return 状态码
 */
Status PriorElem(const SqList * L, ElemType cur_e, ElemType * pre_e){
    if(L->listsize == 0 || L->length <= 1) return (ERROR); //如果表不存在或者表长小于1,那么返回错误码
    const ElemType * List = L->elem;
    if(compare(List[0],cur_e)==0) return (ERROR); //如果该元素是第一个元素,则返回错误码
    int flag = FALSE;   //判断当前是否查找到
    for(int i = 0;i<ListLength(L) && flag !=TRUE;i++){
        if(compare(List[i],cur_e)==0){
            flag = TRUE;    //找到标志
            if(pre_e!=NULL) *pre_e = List[i-1];
        }
    }
    return OK;
}


/**func 获得cur_e的后继
 * @初始条件 L存在,cur_e不是最后一个元素,cur_e在L中
 * @param L 线性表
 * @param cur_e 元素
 * @param next_e 前驱指针
 * @return 状态码
 */
Status NextElem(const SqList * L, const ElemType cur_e, ElemType * next_e){
    if(L->listsize == 0 || L->length <=1 ) return(ERROR);     //如果表不存在或者表长小于1,那么返回错误码
    const ElemType * List = L->elem;
    if(compare(List[L->length-1] , cur_e)==0) return(ERROR); //如果该元素最后一个元素,则返回错误码

    int flag = FALSE;      //判断当前是否查找到
    for(int i = 0;i< ListLength(L) && flag != TRUE; i++){   //退出循环条件是表尾或找到元素
        if(compare(List[i],cur_e)==0){     //如果找到
            flag = TRUE;
            if(next_e!=NULL) *next_e = List[i+1];
        }
    }
    return OK;
}

/**func:在第i个位置插入e
 * @param L 顺序表
 * @param i 位置
 * @param e 元素
 * @return 状态码
 */
Status ListInsert(SqList * L, int i, ElemType e){
    if(!L) return ERROR;
    if(L->listsize == 0) return(ERROR); //判断线性表是否存在
    if(i<=0 || i > L->length + 1) return(ERROR);  //判断位序是否是合法
    if(L->listsize==L->length){
        L->elem = (ElemType *)realloc(L->elem,L->listsize+LISTINCREMENT);
    }
    ElemType * List = L->elem; //获取 空间基地址
    int j = ListLength(L);  //从后往前移动
    for(; j >= i; j--){
        List[j] = List[j-1];
    }
    List[j] = e;    //进行插入
    L->length++;//长度加一
    return OK;

}

/**func:删除第i个元素
 *
 * @param L 线性表
 * @param i 序号
 * @param e 保存被删除元素的地址
 * @return 状态码
 */
Status  ListDelete(SqList * L,int i,ElemType * e){
    if(L->listsize<=0||L->elem==NULL) return ERROR;
    if(i<=0||i>L->length) return ERROR;
    if(e!=NULL) *e = L->elem[i-1];//定位删除位置点
    for(int j = i-1;j<ListLength(L)-1;j++){ //从删除位置开始依次向右移动
        L->elem[j] = L->elem[j+1];
    }
    L->length--;//更新表长
    return OK;
}

/**
 * func 使用visit函数便利每一个元素
 * @param L 线性表
 * @param visit 遍历函数
 * @return 状态码
 */
Status ListTraverse(SqList * L,void * visit){
    if(L==NULL) return ERROR;
    if(L->listsize<=0||L->length<=0) return ERROR;
    void (*vis)(ElemType) = (void (*)(ElemType))(visit);//遍历函数
    for(int i = 0;i<L->length;i++) vis(L->elem[i]);
    return OK;
}

/**
 * func:加载文件
 * @param L 线性表地址
 * @return 状态码
 */
Status LoadData(SqList * L){
    if(L==NULL) return ERROR;
    ElemType e;
    FILE * fp;
    if(!(fp = fopen("file","rb"))) return ERROR; //打开文件
    int i = 1;
    while(fread(&e,1,sizeof(ElemType),fp)!=0){//读取文件并插入
        ListInsert(L,i,e);
        i++;
    }
    fclose(fp);//关闭文件
    return OK;
}

/**
 * func 保存信息
 * @param L 线性表地址
 * @return 状态码
 */
Status SaveData(SqList * L){
    if(L==NULL)return ERROR;
    ElemType e;//获取元素暂存的单元
    FILE * fp;
    fp = fopen("file","wb");//打开文件
    for(int i = 1;i<=L->length;i++){
        GetElem(L,i,&e);//获取元素
        fwrite(&e,1,sizeof(ElemType),fp);//写入文件
    }
    fclose(fp);//关闭文件
    return OK;
}

/**
 * func:切换线性表
 * @param Prior ：本线性表地址
 * @param lists 列表
 * @param cur 当前列表序号
 * @return 状态码
 */
Status ChangeSqList(SqList ** Prior,SqList ** lists,int *cur){
    int n = 1;
    printf("您切换到第几个顺序表？");
    scanf("%d",&n);//获取线性表序号，1—10
    if(n<=0 || n>=11) return ERROR;
    lists[(*cur)-1] = *Prior;//更新上一个
    *cur = n;
    (*Prior) = lists[n-1];
    printf("切换成功!");
    return OK;
}





















