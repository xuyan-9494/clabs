{
    printf("请输入一个五位数及五位数以下的非负整数：");
    
    // 初始化num变量，用于存储即将输入的数
    int num = 0;
    
    // 当getchar没有结束时，将输入的数字字符转成对应的数字
    char c = getchar();
    while(c != '\n' && c != EOF) {
        num = num * 10 + (c - '0');
        c = getchar();
    }
    
    // 对输入做简单的校验
    if (num < 0 || num > 99999) {
        printf("输入的数据不合法！\n");
        return 0;
    }

    // 初始化计数器
    int count = 0;
    // 当num不为0时，执行 num 和 num - 1 的按位与操作，当num为0时，计数器的值就是num中1的个数
//    因为需要按比特位输出，所以就不用这种方法
//    while(num) {
//        count++;
//        num = num & (num - 1);
//    }
    // 设置掩码
    int mask = 1;//特定的数1
    int res[17];
    int i = 0;
    while(num) {
        // 与掩码按位与
        int temp = mask & num;
        // 将每一位存储到数组中
        res[i] = temp;
        i++;
        if (temp) count++;
        // 将num右移一位
        num = num >> 1;
    }
    int len = i;
    printf("此数的二进制表示是：");
    // 如果长度是0，直接输出
    if (len == 0) printf("%d", 0);
    else
        // 倒序输出数组
        for (i = len - 1; i >= 0; i--) {
            printf("%d", res[i]);
        }
    printf("\n1出现的次数是: %d\n", count);
    return 0;
}
