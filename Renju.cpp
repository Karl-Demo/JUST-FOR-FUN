#include<stdio.h>

#include<string.h>

#define MAXN 25

#define BACK "������������"

//\n��windows�ļ��ﱻ���������ֽڣ����������� 
int main() {
    //��ʾ������̾���
    enum WANJIA{A,B}; 
    enum WANJIA num;
    printf("�װ�����ң���������ִ�ĸ���(A  or  B)��_");
    scanf("%c",&num);
    printf("�װ���%c��ң�������Ϸ�����Ǵ˼�����������\
������֪��*����δ��������˼���������������µ��ӵ�����,\
������Ļ�����룬r��ʾ�У�c��ʾ��\n",num);
    FILE *fp;
    int hqcnt = 0;
    if((fp = fopen("D://forchess", "r")) == NULL) {
        printf("FAILED TO OPEN THE FILE,PLEASE TRY AGAIN");
        return 1;
    }
    printf("���������̾��ƣ�����ϸ˼������Ϊ���Ķ��ֿ����ڿ�����\n");
    /*������ʱ�е�ã���Ҫ����ʾ���ı��м���ı䣬Ϊ�˸����û�����*/
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
    //���Ʊ��ݻ����ļ�
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
    //������������д�ļ��˰�������������Ҫ����
    printf("������Ѿ�˼�����ˣ���ô������������������\
   ���ո��Ѱ����ų�����ֻ��Ҫ��*����AB�ļ��м��м���\
   ���б�׼��ΧΪ1��MAXN��=%d��,GOOD LUCK��\n", MAXN);
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
//    puts("��Ҫλ��"); 
    fputc(num,fp);
    fclose(fp);
    //�鿴
    char view[20];
    printf("�������Ƿ���Ҫ�鿴����������(��Ҫ������yes������Ҫ������no):_");
    scanf("%s", view);
    if(strcmp(view, "yes") == 0) {
        if((fp = fopen("D://forchess", "r")) == NULL) {
            printf("FAILED TO OPEN THE FILE,PLEASE TRY AGAIN");
            return 1;
        }
        printf("�����������Ӻ�����̾���:_��ȷ��\n");
        /*������ʱ�е�ã���Ҫ����ʾ���ı��м���ı䣬Ϊ�˸����û�����*/
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
    //������岽�裬���ֻ�����~
    hq:
    if(hqcnt == 1) {
        if((fphq = fopen("D://forchesshq", "r")) == NULL) {
            printf("FAIL TO OPEN THE FILE!");
            return 1;
        }
        printf("���������̾��ƣ�����ϸ˼��:\n");
        cnt = 0;
        //�ٴ���ʾ���
        for(int i = 0; i < MAXN; i++) {
            cnt = 0;
            while((ch = fgetc(fphq)) != '\n') {
                ++cnt;
                if(cnt%2 != 1)putchar(ch);
            }
            putchar(10);
        }
        fclose(fphq);
        //��������
        printf("������Ѿ�˼�����ˣ���ô���������������������ո��Ѱ�\
���ų���,���б�׼��ΧΪ1��MAXN��=%d��\n", MAXN);
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
        //�鿴
        char view[20];
        printf("�������Ƿ���Ҫ�鿴����������(��Ҫ������yes������Ҫ������no):_");
        scanf("%s", view);
        if(strcmp(view, "yes") == 0) {
            if((fp = fopen("D://forchesshq", "r")) == NULL) {
                printf("FAILED TO OPEN THE FILE,PLEASE TRY AGAIN");
                return 1;
            }
            printf("�����������Ӻ�����̾���:_��ȷ��\n");
            /*������ʱ�е�ã���Ҫ����ʾ���ı��м���ı䣬Ϊ�˸����û�����*/
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
    //����
    if(hqcnt == 1) {
        printf("�㱾�غϻ�������Ѿ��þ�\n");
    }
    else {
        printf("�������������λ���������������壬�����룺������������\n");
        char back[81];
        scanf("%s",back);
        if(strcmp(back, BACK) == 0) {
            hqcnt++;
            goto hq;
        }
    }
    printf("���ĻغϽ���");
    return 0;
    //   getchar(); //for pause
}
