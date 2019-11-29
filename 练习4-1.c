#include <stdio.h>

// 限制用户输入为1000个字符，因为scanf会填充'\0'到数组中，所以设置为1001
#define MAX 1001

int strrindex(char* s, char* t);

int main() {
    // 测试结束后可以把while循环删除
    while(1)
    {
        // 清空缓冲区
        fflush(stdin);
        // 创建一个字符数组，用于存储scanf的输入，限制为1000个字符
        char s[MAX];
        char t[MAX];
        printf("请输入待匹配的字符串s 和匹配字符串t，字符串长度限制为1000以内，以空格分隔: \n");
//        // scanf的输入版本,可用，但无法判断输入的字符是否超长
//        fflush(stdin);
//        scanf("%s",s);
//        scanf(" %s",t);
        
        // getchar版本
        // 记录s的长度
        int sLen = 0;
        // 记录t的长度
        int tLen = 0;
        // 是否在空格之后的标记
        int flag = 0;
        // 退出标记
        int exitFlag = 0;
        char c = getchar();
        // 循环取输入
        while(c != '\n' && c != EOF)
        {
            // 如果遇到空格，则将flag置为1，后面的字符都属于t
            if (c == ' ')
            {
                flag = 1;
                c = getchar();
                continue;
            }
            // 如果未遇到空格，则字符都属于s
            if (!flag)
            {
                // 如果超长，则退出循环
                if (MAX <= sLen + 1)
                {
                    printf("输入的s字符串超长！\n");
                    exitFlag = 1;
                    break;
                }
                s[sLen] = c;
                sLen++;
            }
            // 如果遇到了空格，则字符都属于t
            else
            {
                // 如果超长，则退出循环
                if (MAX <= tLen + 1)
                {
                    printf("输入的t字符串超长！\n");
                    exitFlag = 1;
                    break;
                }
                t[tLen] = c;
                tLen++;
            }
            c = getchar();
        }
        // 手动补结束符
        s[sLen] = '\0';
        t[tLen] = '\0';
        if (exitFlag)
        {
            continue;
        }
        
        int index = strrindex(s, t);
        
        printf("字符串t在s中匹配到的索引是 %d \n", index);
    }
    return 0;
}

int strrindex(char s[], char t[])
{
    int index = -1;
    // 循环s
    for (int i = 0; s[i] != '\0'; i++)
    {
        // 设置t是否在s中存在的标志
        int flag = 1;
        // 从s的当前位置开始和t一起循环，直到t结束
        for (int j = 0, k = i; t[j] != '\0'; j++, k++)
        {
            // 如果t当前位置的字符是小写
            if (t[j] >= 'a' && t[j] <= 'z')
            {
                // 判断t当前位置的字符和s是否相同，不区分大小写
                if (!(t[j] - 'a' == s[k] - 'a' || t[j] - 'a' == s[k] - 'A'))
                {
                    flag = 0;
                }
            }
            // 如果t当前位置的字符是小写
            else if (t[j] >= 'A' && t[j] <= 'Z')
            {
                // 判断t当前位置的字符和s是否相同，不区分大小写
                if (!(t[j] - 'A' == s[k] - 'a' || t[j] - 'A' == s[k] - 'A'))
                {
                    flag = 0;
                }
            }
            // 其它字符直接判断
            else if (t[j] != s[k])
            {
                flag = 0;
            }
            // 如果已经不同，则直接退出当前循环
            if (!flag){
                break;
            }
        }
        // 如果t包含于s中，则将当前s的起始位置赋值给index
        if (flag) {
            index = i;
        }
    }
    return index;
}
