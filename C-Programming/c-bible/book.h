/* getline: read a line into s, return length */
int mygetline(char s[], int lim)
{
int c, i;
 
for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != 10; ++i)
    s[i] = c;
if (c == 10) {
    s[i] = c;
    ++i;}
 
s[i] = '\0';
return i;
}
