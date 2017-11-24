//
// Created by tonggege on 17-10-14.
//

#include <stdlib.h>

#ifndef SEQUENCELIST_SEQUENCELIST_H
#define SEQUENCELIST_SEQUENCELIST_H

#endif //SEQUENCELIST_SEQUENCELIST_H

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef OK
#define OK 1
#endif

#ifndef ERROR
#define ERROR 0
#endif

#ifndef INFEASIBLE
#define INFEASIBLE -1
#endif

#ifndef OVERFLOW
#define OVERFLOW -2
#endif


typedef int Status; //函数的状态码

typedef struct ElemType{
    char c;
    int  d;
    float f;
}ElemType;//基础数据类型

#define LIST_INIT_SIZE 100   //线性表存储空间的初始分配两
#define LISTINCREMENT 10     //线性表存储空间的分配增量

typedef struct{
    ElemType  * elem; //存储空间基地址
    int length;       //当前长度
    int listsize;     //当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

Status InitList(SqList ** L);
/**func: 销毁线性表
 * @初始条件 :线性表L已存在
 * @操作结果 :销毁线性表L
 * @param L 顺序表的地址
 * @return 状态码
 */

Status DestroyList(SqList ** L);

/**func 清空线性表
 * @初始条件 线性表L已存在
 * @param L 线性表
 * @return 状态码
 */
Status ClearList(SqList * L);

/**func 判断线性表是否为空
 * @param L
 * @return
 */

int ListEmpty(SqList * L);


/**func 获取线性表长度
 * @param L
 * @return 状态码
 */

int ListLength(const SqList * L);

/**func 获得第i个元素并存储到e中
 * @初始条件 线性表存在 索引i<= 表长length
 * @param L 线性表L
 * @param i 索引i
 * @param e 获得元素的地址e
 * @return 状态码
 */
Status GetElem(const SqList *  L, int i, ElemType * e);

/**func 返回L中第1个与e满足关系compare的数据源素的位序.若这样的数据元素不存在,则返回值为0
 * @初始条件 线性表L已存在,compare已定义
 * @param L 线性表L
 * @param e 待比较的元素
 * @param compare 比较函数
 * @return 位序
 */
int LocateElem(SqList * L, ElemType e, void *  compare);
/**func 获得cur_e的前驱
 * @初始条件 L存在,cur_e不是首元素,cur_e在L中
 * @param L 线性表
 * @param cur_e 元素
 * @param pre_e 前驱指针
 * @return 状态码
 */
Status PriorElem(const SqList * L, ElemType cur_e, ElemType * pre_e);


/**func 获得cur_e的后继
 * @初始条件 L存在,cur_e不是最后一个元素,cur_e在L中
 * @param L 线性表
 * @param cur_e 元素
 * @param next_e 前驱指针
 * @return 状态码
 */
Status NextElem(const SqList * L, const ElemType cur_e, ElemType * next_e);

/**func:在第i个位置插入e
 * @param L 顺序表
 * @param i 位置
 * @param e 元素
 * @return 状态码
 */
Status ListInsert(SqList * L, int i, ElemType e);

/**func:删除第i个元素
 *
 * @param L 线性表
 * @param i 序号
 * @param e 保存被删除元素的地址
 * @return 状态码
 */
Status  ListDelete(SqList * L,int i,ElemType * e);

/**
 * func 使用visit函数便利每一个元素
 * @param L 线性表
 * @param visit 遍历函数
 * @return 状态码
 */
Status ListTraverse(SqList * L,void * visit);

Status  LoadData(SqList * L);

int compare(ElemType a,ElemType b);

Status SaveData(SqList * L);

Status ChangeSqList(SqList ** Prior,SqList * lists[],int * cur);


























