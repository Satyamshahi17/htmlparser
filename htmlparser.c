#include <stdio.h>
#include <string.h>
void parser(char *string)
{
    int a;
    int index = 0;
    for (int i = 0; i < strlen(string); i++) // To remove tags
    {
        if (string[i] == '<')
        {
            a = 0; continue;
        }
        else if (string[i] == '>')
        {
            a = 1;
            continue;
        }
        if (a == 1)
        {
            string[index] = string[i];
            index++;
        }
    }
    string[index] = '\0';

    while (string[0] == ' ') // To remove trailing space from beginning
    {
        for (int i = 0; i < strlen(string); i++) // To shift the string to left
        {
            string[i] = string[i + 1];
        }
    }
    while (string[strlen(string) - 1] == ' ') // To remove trailing spaces from the end
    {

        string[strlen(string) - 1] = '\0'; // since last char index=strlen(str)-1
    }
}
int main()
{
    char str[] = "<h1>      This is a heading. </h1>";
    parser(str);
    printf("~~%s~~", str);

    return 0;
}