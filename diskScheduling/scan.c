#include <stdio.h>
#include <stdlib.h>
#define MAX 200
void SCAN(int arr[], int head, int size, int direction) {
    int seek_sequence[MAX];
    int distance = 0;
    int cur_track;
 int left ,right;
    // Sort the array of disk locations
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }  } }
    for(int i=0;i<size;i++){
        if(arr[i]>head){
            right=i;
            left=i-1;
            break;
        }
    }
    int total_distance = 0;
    int seek_count = 0;
    int index = 0;
      // Move the head in the requested direction
    if (direction == 0) {
        // Move left
        for (int i = left; i >= 0; i--) {
            cur_track = arr[i];
            seek_sequence[index++] = cur_track;
           
        }
       
        for (int i = right; i < size; i++) {
            cur_track = arr[i];
            seek_sequence[index++] = cur_track;
            
        }
        total_distance=head+arr[size-1];
    } else {
        // Move right
        for (int i = right; i < size; i++) {
            cur_track = arr[i];
            seek_sequence[index++] = cur_track;
            
        }
        for (int i = left; i >= 0; i--) {
            cur_track = arr[i];
            seek_sequence[index++] = cur_track;
           
        }
        total_distance=MAX-1-head +(MAX-1-arr[0]);
    }

    printf("Seek Sequence: ");
    for (int i = 0; i < index; i++) {
        printf("%d", seek_sequence[i]);
        if (i != seek_count - 1) {
            printf(" -> ");
        }
    }
    printf("\nTotal Seek Distance: %d\n", total_distance);
}

void main() {
    int size, head, direction;

    printf("Enter the number of requests: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the requests: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
     printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    SCAN(arr, head, size, direction);
}