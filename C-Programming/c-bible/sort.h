#include <stdio.h>
#include <string.h>

void qsort(char v[], int left, int right){

        int i, last;
        void swap(char v[], int left, int right);      /* function prototype */

        if(left >= right)
                return;
        swap(v, left, (left+right)/2);
        last=left;

        for(i=left+1;i<right;i++){
                if((strcmp(v[i],v[left]) < 0))  /* returns value < 0 if elem1 is lexicographical smaller than elem2 */
                        swap(v,++last,i);
                swap(v,left,last);
                qsort(v,left,last-1);
                qsort(v,last+1,right);
        }
}

void swap(char v[], int i, int j){

        char *temp[j];

        temp=v[i];
        v[i]=v[j];
        v[j]=temp;

}
