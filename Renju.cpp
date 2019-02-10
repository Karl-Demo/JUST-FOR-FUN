#include<stdio.h>

#include<string.h>

#define MAXN 25

#define BACK "老铁给个面子"

//\n在windows文件里被当成两个字节！！！！！！ 
int main() {
    //显示最近棋盘局势
    enum WANJIA{A,B}; 
    enum WANJIA num;
    printf("亲爱的玩家，请问你是执哪个子(A  or  B)：_");
    scanf("%c",&num);
    printf("亲爱的%c玩家，以下游戏规则是此简易五子棋盘\
下棋须知，*代表未下区域，若思考完请输入您所下的子的行列,\
请在屏幕上输入，r表示行，c表示列\n",num);
    FILE *fp;
    int hqcnt = 0;
    if((fp = fopen("D://forchess", "r")) == NULL) {
        printf("FAILED TO OPEN THE FILE,PLEASE TRY AGAIN");
        return 1;
    }
    printf("以下是棋盘局势，请仔细思考，因为您的对手可能在看春晚：\n");
    /*这里用时有点久，主要是显示与文本中间隔改变，为了改善用户体验*/
    int ch;
    int cnt = 0;
    for(int i = 0; i < MAXN; i++) {
        cnt = 0;
        while((ch = fgetc(fp)) != '\n') {
            ++cnt;
            
            if(cnt%2 != 1)putchar(ch);
        }
        putchar(10);
    }
    rewind(fp);
    //复制备份悔棋文件
    FILE* fphq;
    if((fphq = fopen("D://forchesshq", "w")) == NULL) {
        printf("FAIL TO MAKE OUT THE BACK-UP");
        return 1;
    }
    while((ch = fgetc(fp)) != EOF) {
        fputc(ch, fphq);
    }
    fclose(fp);
    fclose(fphq);
    //接下来终于是写文件了啊啊啊啊啊啊，要哭了
    printf("如果您已经思考好了，那么请输入以下两个参数\
   （空格已帮您排除），只需要数*或者AB的几行几列即可\
   行列标准范围为1到MAXN（=%d）,GOOD LUCK！\n", MAXN);
    if((fp = fopen("D://forchess", "r+")) == NULL) {
        printf("THE FILE CANNOT BE WRITTEN,PLEASE TRY AGAIN\n");
        return 1;
    }
    int c, r;
    nidaye:
    printf("PLEASE INPUT THE ROW_:");
    scanf("%d", &r);
    printf("AND THE COLUMN:_");
    scanf("%d", &c);
    putchar(10);
    if(c > MAXN || r > MAXN || c < 1 || r < 1) {
        printf("THE FIGURE YOU INPUT IS OUT OF THE STD SCOPE,PLEASE INPUT AGAIN");
        goto nidaye;
    }
    else fseek(fp, (4*MAXN+2)*(r-1)+4*c-1, 0);
//    printf("%ld",ftell(fp));
//    puts("我要位置"); 
    fputc(num,fp);
    fclose(fp);
    //查看
    char view[20];
    printf("请问您是否需要查看如今棋盘情况(需要请输入yes；不需要则输入no):_");
    scanf("%s", view);
    if(strcmp(view, "yes") == 0) {
        if((fp = fopen("D://forchess", "r")) == NULL) {
            printf("FAILED TO OPEN THE FILE,PLEASE TRY AGAIN");
            return 1;
        }
        printf("以下是您落子后的棋盘局势:_请确认\n");
        /*这里用时有点久，主要是显示与文本中间隔改变，为了改善用户体验*/
        cnt = 0;
        for(int i = 0; i < MAXN; i++) {
            cnt = 0;
            while((ch = fgetc(fp)) != '\n') {
                ++cnt;
                if(cnt%2 != 1)putchar(ch);
            }
            putchar(10);
        }
        fclose(fp);
    }
    //插入悔棋步骤，我又回来了~
    hq:
    if(hqcnt == 1) {
        if((fphq = fopen("D://forchesshq", "r")) == NULL) {
            printf("FAIL TO OPEN THE FILE!");
            return 1;
        }
        printf("以下是棋盘局势，请仔细思考:\n");
        cnt = 0;
        //再次显示棋局
        for(int i = 0; i < MAXN; i++) {
            cnt = 0;
            while((ch = fgetc(fphq)) != '\n') {
                ++cnt;
                if(cnt%2 != 1)putchar(ch);
            }
            putchar(10);
        }
        fclose(fphq);
        //重新落子
        printf("如果您已经思考好了，那么请输入以下两个参数（空格已帮\
您排除）,行列标准范围为1到MAXN（=%d）\n", MAXN);
        if((fp = fopen("D://forchesshq", "r+")) == NULL) {
            printf("THE FILE CANNOT BE WRITTEN,PLEASE TRY AGAIN\n");
            return 1;
        }
        nimei:
        printf("PLEASE INPUT THE ROW_:");
        scanf("%d", &r);
        printf("AND THE COLUMN:_");
        scanf("%d", &c);
        putchar(10);
        if(c > MAXN || r > MAXN || c < 1 || r < 1) {
            printf("THE FIGURE YOU INPUT IS OUT OF THE STD SCOPE,PLEASE INPUT AGAIN");
            goto nimei;
        }
        else fseek(fphq, (4*MAXN+2)*(r-1)+4*c-1, 0);
        fputc(num, fphq);
        fclose(fphq);
        //查看
        char view[20];
        printf("请问您是否需要查看如今棋盘情况(需要请输入yes；不需要则输入no):_");
        scanf("%s", view);
        if(strcmp(view, "yes") == 0) {
            if((fp = fopen("D://forchesshq", "r")) == NULL) {
                printf("FAILED TO OPEN THE FILE,PLEASE TRY AGAIN");
                return 1;
            }
            printf("以下是您落子后的棋盘局势:_请确认\n");
            /*这里用时有点久，主要是显示与文本中间隔改变，为了改善用户体验*/
            cnt = 0;
            for(int i = 0; i < MAXN; i++) {
                cnt = 0;
                while((ch = fgetc(fp)) != '\n') {
                    ++cnt;
                    if(cnt%2 != 1)putchar(ch);
                }
                putchar(10);
            }
            fclose(fp);
        }
    }
    //悔棋
    if(hqcnt == 1) {
        printf("你本回合悔棋次数已经用尽\n");
    }
    else {
        printf("如果您觉得落子位置有误或者您想悔棋，请输入：老铁给个面子\n");
        char back[81];
        scanf("%s",back);
        if(strcmp(back, BACK) == 0) {
            hqcnt++;
            goto hq;
        }
    }
    printf("您的回合结束");
    return 0;
    //   getchar(); //for pause
}
