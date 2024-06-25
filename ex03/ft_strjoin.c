//#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// دالة لحساب طول السلسلة النصية
int str_len(char* str) 
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

// دالة لإنشاء سلسلة نصية بطول مناسب
char* create_str(int size, char** strs, char* sep) 
{
    char* str;
    int len = 0;
    int i = 0;

    while (i < size) 
    {
        len += str_len(strs[i]);
        i++;
    }
    len += str_len(sep) * (size - 1);
    if (size <= 0)
        len = 1;
    str = (char*)malloc(sizeof(char) * (len + 1)); //    تأكد من تخصيص ذاكرة كافية بما في ذلك '\0'
    if (!str)
        return 0;
    return str;
}

// دالة لدمج السلاسل النصية
char* ft_strjoin(int size, char** strs, char* sep) 
{
    int i;
    int j;
    int k;
    char* str;

    str = create_str(size, strs, sep);
    if (!str)
        return NULL;

    i = 0;
    k = 0;
    while (i < size) 
    {
        j = 0;
        while (strs[i][j]) {
            str[k++] = strs[i][j];
            j++;
        }
        j = 0;
        while (sep[j] && i < size - 1)
        {
            str[k++] = sep[j];
            j++;
        }
        i++;
    }
    str[k] = '\0';
    return str;
}

// دالة رئيسية للاختبار
int main() 
{
    char* strs[] = { "Hello", "world", "from", "C" };
    char* sep = ", ";
    int size = 4;

    char* result = ft_strjoin(size, strs, sep);
    if (result != NULL) 
    {
        printf("%s\n", result);
        free(result); // تحرير الذاكرة بعد الاستخدام
    }
    else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
