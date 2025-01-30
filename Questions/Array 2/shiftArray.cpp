// **********************************
#include<iostream>
using namespace std;
void rotateByTwoPlaces(int arr[],int size,int shiftNo){
     int temp[1000];
     int index=0;
     //copy elements of array from last that much element we have to shift
     for(int i=size-shiftNo ; i<size; i++){
          temp[index]=arr[i];
          index++;
     }//shifting by 2 places
     //shift array elements by n places//let say arr[10]={10,20,30,40,50,60,70,80,90,100}
     for(int i=size-1;i>=0;i--){//i=size-1==>9
          if(i-shiftNo>=0){//i-shiftNo==>7
               arr[i]=arr[i-shiftNo];//copy values
          }
     }
       //step-3: copy temp elements into original array' starting
       for( int i=0; i<shiftNo;i++){
        arr[i]=temp[i];
    }
}

int main(){
int arr[]={10,20,30,40,50,60};
    int size=6;
    //cyclically rotate array by 2 places
    int n = 2;
    //print original array
    cout<<"Array before rotating: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    rotateByTwoPlaces(arr,size,n);
    //print array after rotation
    cout<<"Array after rotating : "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*Approach 1: Using Extra Array (O(n) Space)
// Copy the last k elements to a new array.
// Move the rest of the elements k positions to the right.
// Insert the copied elements at the beginning.
*/