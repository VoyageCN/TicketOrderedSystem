//
//  main.c
//  TicketOrderedSystem
//
//  Created by ma c on 16/3/23.
//  Copyright (c) 2016年 尚学堂. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <unistd.h>
//#define FlightMess_PATH "/Users/mac/Desktop/史傲楠/TicketOrderedSystem/TicketOrderedSystem/airline.dat"
//#define CustomMess_PATH "/Users/mac/Desktop/customer.dat"

typedef struct airline{
    char flightNum[6];
    int planeNum;
    char destination[20];
    int ordered;
    int remain;
}air;

typedef struct customMessage{
    char name[10];
    char flightNum[6];
    int seatNum;
}customer; // 客户

// 结构体声明

void Airline(customer bj[],customer sh[],customer gz[])
{
    air air1={"CX6122",1001,"beijing",1,99};
    air air2={"CA418",1002,"shanghai",1,99};
    air air3={"KA1428",1003,"guangzhou",1,99};
    printf("目前我司有三条航线：\n");
    printf("航班号   飞机号   目的地   订票数   余票数\n");
    printf("%s   %d\t%s\t%d\t   %d\n",air1.flightNum,air1.planeNum,air1.destination,Count(bj),100-Count(bj));
    printf("%s    %d\t%s\t%d\t   %d\n",air2.flightNum,air2.planeNum,air2.destination,Count(sh),100-Count(sh));
    printf("%s   %d\t%s\t%d\t   %d\n",air3.flightNum,air3.planeNum,air3.destination,Count(gz),100-Count(gz));
}  // 航线信息

void OrderTicket(customer bj[],customer sh[],customer gz[])
{
    //    FILE *fp=NULL;
    //    fp=fopen(CustomMess_PATH, "r+");
    int x=0;
    printf("请输入您要到达的城市\n");
    printf("1.北京 2.上海 3.广州\n");
    scanf("%d",&x);
    if (x==1) {
        for(int i=1;i<100;i++){
            if(bj[i].seatNum!=i+1){
                printf("请输入您的姓名:\n");
                scanf("%s",bj[i].name);
                strcpy(bj[i].flightNum, "CX6122");
                printf("您要订的航班号为:%s\n",bj[i].flightNum);
                printf("系统正在为您分配座位号:\n请稍后.......\n");
                sleep(2);
                bj[i].seatNum=i+1;
                printf("您的座位号为%d\n",bj[i].seatNum);
                break;
            }
        }
        
    }
    else if(x==2){
        for(int i=0;i<100;i++){
            if(sh[i].seatNum!=i+1){
                printf("请输入您的姓名:\n");
                scanf("%s",sh[i].name);
                strcpy(sh[i].flightNum, "CA418");
                printf("您要订的航班号为:%s\n",sh[i].flightNum);
                printf("系统正在为您分配座位号:\n请稍后.......\n");
                sleep(2);
                sh[i].seatNum=i+1;
                printf("您的座位号为%d\n",sh[i].seatNum);
                break;
                
            }
        }
    }
    else if(x==3){
        for(int i=0;i<100;i++){
            if(gz[i].seatNum!=i+1){
                printf("请输入您的姓名:\n");
                scanf("%s",gz[i].name);
                strcpy(gz[i].flightNum, "KA1428");
                printf("您要订的航班号为:%s\n",gz[i].flightNum);
                printf("系统正在为您分配座位号:\n请稍后.......\n");
                sleep(2);
                gz[i].seatNum=i+1;
                printf("您的座位号为%d\n",gz[i].seatNum);
                break;
            }
        }
    }
    else{
        printf("输入错误，请重新选择\n");
        sleep(1);
        OrderTicket(bj, sh, gz);
    }
    
} // 订票


int Count(customer arr[])
{
    int count=0;
    for (int i=0;i<100 ; i++) {
        if (arr[i].seatNum==i+1) {
            count = arr[i].seatNum;
        }
    }
    return count;
} // 计算订票数量

void CustomInfo(customer bj[],customer sh[],customer gz[])
{
    printf("姓名    航班号    座位号\n");
    for (int i=0; i<100; i++) {
        if(bj[i].seatNum!=0){
            printf("%s    %s     %d\n",bj[i].name,bj[i].flightNum,bj[i].seatNum);
        }
    }
    for (int i=0; i<100; i++) {
        if(sh[i].seatNum!=0){
            printf("%s    %s      %d\n",sh[i].name,sh[i].flightNum,sh[i].seatNum);
        }
    }
    for (int i=0; i<100; i++) {
        if(gz[i].seatNum!=0){
            printf("%s    %s     %d\n",gz[i].name,gz[i].flightNum,gz[i].seatNum);
        }
    }
} // 打印客户信息

void PrtMenu()
{
    printf("*************************\n");
    printf("**    1.查询航线信息     **\n");
    printf("**    2.查询客户信息     **\n");
    printf("**    3.订票业务办理     **\n");
    printf("**    4.退票业务办理     **\n");
    printf("**    0.退出航空系统     **\n");
    printf("*************************\n");
} // 打印菜单

void Refund(customer bj[],customer sh[],customer gz[])
{
    char ch[10]={'\0'};
    printf("请输入您的姓名：\n");
    scanf("%s",ch);
    for (int i=0; i<100; i++) {
        if (strcmp(ch, bj[i].name)==0) {
            bj[i].seatNum=0;
        }
    }
    for (int i=0; i<100; i++) {
        if (strcmp(ch, sh[i].name)==0) {
            sh[i].seatNum=0;
        }
    }
    for (int i=0; i<100; i++) {
        if (strcmp(ch, gz[i].name)==0) {
            gz[i].seatNum=0;
        }
    }
    
} // 退票

//void Press()
//{
//    printf("输入任意键继续\n");
//    char ch;
//    scanf("%c",&ch);
//}

void Execute(customer bj[],customer sh[],customer gz[])
{
    int n=0;
    scanf("%d",&n);
    while (n) {
        switch (n                                                                                                                                                                      ) {
            case 1:
                Airline(bj,sh,gz);
                //                Press();
                PrtMenu();
                Execute(bj,sh,gz);
                
            case 2:
                CustomInfo(bj,sh,gz);
                PrtMenu();
                Execute(bj,sh,gz);
                
            case 3:
                OrderTicket(bj,sh,gz);
                PrtMenu();
                Execute(bj,sh,gz);
            case 4:
                Refund(bj, sh, gz);
                //                Press();
                PrtMenu();
                Execute(bj,sh,gz);
            default:
                Execute(bj,sh,gz);
        }
    }
        printf("您已退出航空订票系统，欢迎下次再来！\n");
    
} // 执行结构



int main(int argc, const char * argv[]) {
    PrtMenu();
    customer bjCus[100]={{"张三","CX6122",1}},shCus[100]={{"李四","CA418",1}},gzCus[100]={{"王五","KA1428",1}};
    customer *p1=bjCus;
    customer *p2=shCus;
    customer *p3=gzCus;
    
    Execute(p1,p2,p3);
    
    return 0;
}
//void AirLine()
//{
//    char c;
//    FILE *fp=NULL;
//    fp=fopen(FlightMess_PATH, "r");
//    while (fscanf(fp, "%c",&c)!=EOF) {
//        printf("%c",c);
//    }
//    printf("\n");
//    fclose(fp);
//    fp=NULL;
//}
//void CustomerMes()
//{
//    char c;
//    FILE *fp=NULL;
//    fp=fopen(CustomMess_PATH, "r");
//    while (fscanf(fp, "%c",&c)!=EOF) {
//        printf("%c",c);
//    }
//    printf("\n");
//    fclose(fp);
//    fp=NULL;
//}
